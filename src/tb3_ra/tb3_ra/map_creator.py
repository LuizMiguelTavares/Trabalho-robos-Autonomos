import rclpy
from rclpy.node import Node

from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from tb3_ra_interfaces.msg import GridMap
from scipy.cluster.hierarchy import linkage,  cut_tree
from tf_transformations import euler_from_quaternion
import math
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import time

class MapCreator(Node):

    def __init__(self):
        super().__init__("map_creator")

        self.grid_map_publisher_ = self.create_publisher(GridMap, "grid_map", 10)
        self.degrees       = None
        self.frames_sec    = 30    # Frames
        self.laser_const   = 1
        self.x_points      = []
        self.y_points      = []
        self.points        = []
        self.ranges        = None
        self.aux_mapping   = True
        self.position      = None

        # grid mapping
        self.width         = 60
        self.heigth        = 60
        self.resolution    = 0.04

        self.grid_msg = GridMap()
        self.grid_msg.width  = float(self.width) 
        self.grid_msg.heigth  = float(self.heigth) 
        self.grid_msg.resolution = float(self.resolution)
        self.aux_grid = 0
        self.timer = 1.5 # segundos
        self.loops = 7 

        # making grid
        self.grid = np.zeros(int(self.heigth/self.resolution) * int(self.width/self.resolution) * 4).reshape(int(self.width/self.resolution)*2, int(self.heigth/self.resolution)*2)
        #self.get_logger().info(str(len(self.grid[0])))

        # x_grid
        aux_x_rigth = []
        aux_x_left  = []
        aux = 0
        for i in range(int(self.width/self.resolution)*2):
            if i%2 == 0 and aux == 0:
                aux_x_left.append(i * self.resolution)
            
            if i%2 == 1 and aux == 0:
                aux_x_rigth.append(i * self.resolution)
                aux = 1
            
            if (i%2 == 0) & (aux != 0):
                aux_x_left.append((i-aux +1) * self.resolution)
            
            if (i%2 == 1) & (aux != 0):
                aux_x_rigth.append((i-aux +2) * self.resolution)
                aux = aux + 1
        
        if len(aux_x_left) != len(aux_x_rigth):
            if len(aux_x_left) > len(aux_x_rigth):
                aux_x_left.pop(-1)
            else:
                aux_x_rigth.pop(-1)

        self.x_grid = pd.arrays.IntervalArray.from_arrays(aux_x_left, aux_x_rigth, closed='left')

        # y_grid
        aux_y_rigth = []
        aux_y_left  = []
        aux = 0
        for i in range(int(self.heigth/self.resolution)*2):
            if i%2 == 0 and aux == 0:
                aux_y_left.append(i * self.resolution)
            
            if i%2 == 1 and aux == 0:
                aux_y_rigth.append(i * self.resolution)
                aux = 1
            
            if (i%2 == 0) & (aux != 0):
                aux_y_left.append((i-aux +1) * self.resolution)
            
            if (i%2 == 1) & (aux != 0):
                aux_y_rigth.append((i-aux +2) * self.resolution)
                aux = aux + 1
        
        if len(aux_y_left) != len(aux_y_rigth):
            if len(aux_y_left) > len(aux_y_rigth):
                aux_y_left.pop(-1)
            else:
                aux_y_rigth.pop(-1)

        self.y_grid = pd.arrays.IntervalArray.from_arrays(aux_y_left, aux_y_rigth, closed='left')

        #self.get_logger().info(str(len(self.x_grid)))
        #self.get_logger().info(str(len(self.y_grid)))

        del aux_x_rigth
        del aux_x_left
        del aux_y_left
        del aux_y_rigth
        del aux

        self.pose_subscriber = self.create_subscription(Odometry, "odom", self.Turtlebot3_pose, 10)

        self.laser_subscriber = self.create_subscription(LaserScan, "scan", self.laser_reading, 10)

        self.grid_publisher = self.create_publisher(GridMap, "grid_map", 10)

        self.timer_ = self.create_timer(1/self.frames_sec, self.grid_map)

        self.get_logger().info("Map creator Node has been started!!")

    def Turtlebot3_pose(self, msg): # OK
        self.pose = msg
        self.grid_msg = GridMap()
        self.orientation = msg.pose.pose.orientation
        self.position = msg.pose.pose.position
        self.orientation = [self.orientation.x, self.orientation.y, self.orientation.z, self.orientation.w]
        (self.roll, self.pitch, self.yaw) = euler_from_quaternion(self.orientation)

    def laser_reading(self, msg): # OK
        # Sentido anti-horário
        self.ranges = msg.ranges

    def polar_to_cartesian_global(self):
        x = []
        y = []
        weight = []
        degree = []
        ranges = []
        x_aux = 0
        y_aux = 0

        if self.ranges == None:
            return None, None, None, None, None
        
        for i in range(len(self.ranges)):
            yaw = self.yaw
            
            if self.ranges[i] == float("inf"):
                    self.ranges[i] = 4

            for j in range(int(self.ranges[i]/self.resolution)):
                degree.append(i/self.laser_const)
                ranges.append(self.ranges[i])
                const = round((j+1)/int(self.ranges[i]/self.resolution), 2)
                    
                if self.ranges[i] < 4:

                    x_aux = const * self.ranges[i] * math.cos(math.radians(i/self.laser_const))
                    y_aux = const * self.ranges[i] * math.sin(math.radians(i/self.laser_const))
                    
                    x.append((x_aux * math.cos(yaw)) - (y_aux * math.sin(yaw)) + self.position.x + 20)
                    y.append((x_aux * math.sin(yaw)) + (y_aux * math.cos(yaw)) + self.position.y + 15)

                    if const == 1.0:
                        weight.append(int(0))
                    else:
                        weight.append(int(100))
                else:
                    x_aux = const * 3.5 * math.cos(math.radians(i/self.laser_const))
                    y_aux = const * 3.5 * math.sin(math.radians(i/self.laser_const))
            
                    x.append((x_aux * math.cos(yaw)) - (y_aux * math.sin(yaw)) + self.position.x + 20)
                    y.append((x_aux * math.sin(yaw)) + (y_aux * math.cos(yaw)) + self.position.y + 15)

                    weight.append(int(100))

        return x, y, weight, degree, ranges
    
    def calc_hierarchy(self, data,n_cluster_max,n_min_pontos):
        # Generate sample data
        X = data.to_numpy()

        # Perform linkage
        Z = linkage(X, method='single')

        # Cut the dendrogram to obtain clusters
        clusters = cut_tree(Z, n_clusters=np.linspace(1,n_cluster_max,n_cluster_max))

        for i in range(clusters.shape[1]):
            _, counts = np.unique(clusters[:,i], return_counts=True)
            if np.min(counts)<n_min_pontos:
                cluster = clusters[:,i-1]
                break

        return cluster
    
    def calc_centroid(self, data):
        label, counts = np.unique(data['weight'], return_counts=True)
        centroids = []

        for classe in label:
            aux = data[data['weight']==classe]
            x_mean = sum(aux.iloc[:,0].to_numpy())/len(aux)
            y_mean = sum(aux.iloc[:,1].to_numpy())/len(aux)
            centroids.append((x_mean,y_mean))

        return centroids   
    
    def grid_map(self):
        if self.position == None:
            return

        x_grid_aux = pd.DataFrame()
        y_grid_aux = pd.DataFrame()
        for i in range(self.loops):
            X, Y, weight, degree, ranges = self.polar_to_cartesian_global()

            if X == None:
                return

            x_grid_aux[i] = X
            y_grid_aux[i] = Y
            #time.sleep(self.timer/self.loops)
        
        X = x_grid_aux.mean(axis=1)
        Y = y_grid_aux.mean(axis=1)

        x_gridd = [int(np.where(self.x_grid.contains(x))[0][0]) for x in X]
        y_gridd = [int(np.where(self.y_grid.contains(y))[0][0]) for y in Y]

        x_position = int(np.where(self.x_grid.contains(self.position.x+20))[0][0]) 
        y_position = int(np.where(self.y_grid.contains(self.position.y+15))[0][0])

        d = {'x grid': x_gridd, 'y grid': y_gridd, 'weight': weight, 'degrees':degree, 'ranges': ranges}
        if self.aux_grid == 0:
            self.df = pd.DataFrame(data=d)
            self.aux_grid = 1
            return
        
        df1 = pd.DataFrame(data=d)
        df1.drop_duplicates(inplace=True,ignore_index=True)
        self.df = self.df.append(df1, ignore_index=True)
        
        df1.to_csv('map_movimentação.csv', index=False)

        x_grid_unique = np.unique(self.df["x grid"])
        y_grid_unique = np.unique(self.df["y grid"])

        map = self.df.copy()

        for i, x in enumerate(x_grid_unique):
            map["x grid"][map.iloc[:, 0]==x ] = i
        for j, y in enumerate(y_grid_unique):
            map["y grid"][map.iloc[:, 1]==y] = j

        grid = np.zeros(len(x_grid_unique)*len(y_grid_unique)).reshape(len(x_grid_unique), len(y_grid_unique))
        grid = grid + 0.5

        for i, v in enumerate(map.values):
            if v[2] == 100:
                grid[int(v[0]), int(v[1])] = grid[int(v[0]), int(v[1])] * 0.9
            elif v[2] == 0:
                if grid[int(v[0]), int(v[1])]<500000:
                    grid[int(v[0]), int(v[1])] = grid[int(v[0]), int(v[1])] * 1.8
        
        x, y = grid.shape
        d_map = {'x grid': np.zeros(x*y), 'y grid': np.zeros(x*y), 'weight': np.zeros(x*y)}
        df_map = pd.DataFrame(data=d_map)

        aux = 0
        for i in range(x):
            for j in range(y):
                df_map.iloc[aux]['x grid'] = int(i)
                df_map.iloc[aux]['y grid'] = int(j)
                df_map.iloc[aux]['weight'] = grid[i, j]
                aux = aux + 1
        
        df_map['weight'][df_map['weight']==0.5] = 500000
        df_map['weight'][(df_map['weight']<0.5)] = 1000000
        df_map['weight'][(df_map['weight']>0.5) & (df_map['weight']<500000)] = 0

        data_occ = df_map[df_map['weight']==0] 

        data_occ['weight'] = self.calc_hierarchy(data_occ.iloc[:,0:2],12,10)
        #self.get_logger().info(teste)
        
        centroids = pd.DataFrame(self.calc_centroid(data_occ))
        centroids.to_csv('centroid.csv')

        """
        Movimentação
        """

        movimentacao = df1[['degrees', 'ranges']]
        movimentacao = movimentacao.drop_duplicates(ignore_index=True)
        movimentacao['ranges'][movimentacao['ranges']==4] = 3.5

        # Cone de 30 graus
        df_90 = movimentacao[movimentacao['degrees']<=89]
        df_270 = movimentacao[movimentacao['degrees']>=269]

        new = pd.DataFrame({'degrees': np.zeros(len(df_90)+len(df_270)-1), 'new_degrees': np.zeros(len(df_90)+len(df_270)-1), 'ranges': np.zeros(len(df_90)+len(df_270)-1)})
        for i, v in enumerate(df_270.values):
            new.iloc[i, 0] = v[0]
            new.iloc[i, 1] = i
            new.iloc[i, 2] = v[1]
        for i, v in enumerate(df_90.values):
            new.iloc[(i+len(df_90)), 0] = v[0]
            new.iloc[(i+len(df_90)), 1] = (i+len(df_90))
            new.iloc[(i+len(df_90)), 2] = v[1]
        
        new_2 = new.copy()
        for i in range(len(new)):
            new_2['ranges'].iloc[i] = new['ranges'].iloc[len(new)-i-1]

        # Pega pontos com valores especificos (>1.5)
        new_max_range = new_2[new_2.ranges > 2]

        aux = []
        clusters = []
        for idx, i in enumerate(new_max_range['new_degrees']):
            if i != (new_max_range['new_degrees'].iloc[-1]):
                if (new_max_range['new_degrees'].iloc[int(idx)+1]-new_max_range['new_degrees'].iloc[int(idx)])==1.0:
                    aux.append(new_max_range['new_degrees'].iloc[idx])
                else:
                    aux.append(new_max_range['new_degrees'].iloc[idx])
                    clusters.append(aux)
                    aux = [] 
        else:
            aux.append(new_max_range['new_degrees'].iloc[idx])
            clusters.append(aux)
        
        # Pega maior cluster
        aux = 0
        index = None
        for idx, v in enumerate(clusters):
            if len(v)>aux:
                aux=len(v)
                index = idx

        # Tratando self yaw
        if self.yaw<0:
            grau = math.degrees(self.yaw)+360
        else:
            grau = math.degrees(self.yaw)

        d = -(int(np.mean(clusters[index])) - int(np.mean(new_2.new_degrees)))
        if d+grau<0:
            d = d+grau+360
        else:
            d = grau+d
        

        dist = 1 # metros
        if d>=270:
            d_n = 360-d
            xn  = round(math.cos(math.radians(d_n))*dist, 5)
            yn  = round(-math.sin(math.radians(d_n))*dist, 5)
        elif d>=0 and d<90:
            d_n = d
            xn  = round(math.cos(math.radians(d_n))*dist, 5)
            yn  = round(math.sin(math.radians(d_n))*dist, 5)
        elif d>=90 and d<180:
            d_n = 180-d
            xn  = round(-math.cos(math.radians(d_n))*dist, 5)
            yn  = round(math.sin(math.radians(d_n))*dist, 5)
        else:
            d_n = d-180
            xn  = round(-math.cos(math.radians(d_n))*dist, 5)
            yn  = round(-math.sin(math.radians(d_n))*dist, 5)
        
        p_x = self.position.x
        p_y = self.position.y
        pn_x = p_x+xn
        pn_y = p_y+yn 
        self.grid_msg.x_to_go = pn_x
        self.grid_msg.y_to_go = pn_y

        self.grid_publisher.publish(self.grid_msg)

        self.get_logger().info('Ponto em x: ' + str(pn_x))
        self.get_logger().info('Ponto em y: ' + str(pn_y))

        """
        Plot
        """
        fig, axs = plt.subplots(2, 2)
        axs[0, 0].scatter(df1["x grid"], df1["y grid"], s=1, c = df1["weight"])
        axs[0, 0].scatter(x_position , y_position, color='green', s=30)
        axs[0, 0].scatter(x_position+(xn/self.resolution) , y_position+(yn/self.resolution), color='red', s=30)
        axs[0, 0].set_title('Mapa de movimentação')

        axs[0, 1].scatter(data_occ["x grid"], data_occ["y grid"], s=1, c = data_occ["weight"])
        axs[0, 1].scatter(centroids.iloc[1:,0], centroids.iloc[1:,1], color='red', s=5)
        axs[0, 1].set_title('Contagem de objetos')
        
        axs[1, 0].scatter(df_map["x grid"], df_map["y grid"], s=1, c = df_map["weight"])
        axs[1, 0].set_title('Mapeamento')

        # # plt.subplot(2221)
        # plt.scatter(df1["x grid"], df1["y grid"], s=1, c = df1["weight"])
        # plt.scatter(x_position , y_position, color='green', s=30)
        # plt.scatter(x_position+(xn/self.resolution) , y_position+(yn/self.resolution), color='red', s=30)
        # plt.title("A subplot with 2 lines")
        
        # plt.subplot(2212)
        # plt.scatter(data_occ["x grid"], data_occ["y grid"], s=1, c = data_occ["weight"])
        # plt.scatter(centroids.iloc[1:,0], centroids.iloc[1:,1], color='red', s=5)

        # Show the graph

        plt.show(block=False)
        plt.pause(10)
        plt.close()

def main(args=None):
    rclpy.init(args=args)
    node = MapCreator()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()