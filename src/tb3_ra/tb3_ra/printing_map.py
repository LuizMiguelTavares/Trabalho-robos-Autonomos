import rclpy
from rclpy.node import Node
from tb3_ra_interfaces.msg import GridMap
from scipy.cluster.hierarchy import linkage,  cut_tree
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


class MapPrinter(Node):

    def __init__(self):
        super().__init__("map_printer")
        self.msg_x_y = GridMap()
        self.grid_aux = True
        self.grid_map_subscriber = self.create_subscription(GridMap, "grid_map", self.printing_map, 10)
        self.grid_map_publisher_ = self.create_publisher(GridMap, "grid_map", 10)
        self.get_logger().info("printing_map Node has been started!!")

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

    def printing_map(self, msg):
        x_grid = msg.x_grid
        y_grid = msg.y_grid
        weight = msg.weight
        degree = msg.degree

        d = {'x grid': x_grid, 'y grid': y_grid, 'weight': weight, 'degrees':degree}
        if self.grid_aux:
            self.df = pd.DataFrame(data=d)
            self.df.drop_duplicates(inplace=True,ignore_index=True)
            self.grid_aux = False
        else:
            df1 = pd.DataFrame(data=d)
            df1.drop_duplicates(inplace=True,ignore_index=True)
            self.df = self.df.append(df1, ignore_index=True)

        x_grid_unique = np.unique(self.df["x grid"])
        y_grid_unique = np.unique(self.df["y grid"])

        map = self.df.copy()

        for i, x in enumerate(x_grid_unique):
            map["x grid"][map.loc[:, 0]==x ] = i
        for j, y in enumerate(y_grid_unique):
            map["y grid"][map.loc[:, 1]==y] = j

        grid = np.zeros(len(x_grid_unique)*len(y_grid_unique)).reshape(len(x_grid_unique), len(y_grid_unique))
        grid = grid + 0.5

        for i, v in enumerate(map.values):
            if v[2] == 100:
                grid[int(v[0]), int(v[1])] = grid[int(v[0]), int(v[1])] * 0.5
            elif v[2] == 0:
                grid[int(v[0]), int(v[1])] = grid[int(v[0]), int(v[1])] * 1.5
        
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
        
        df_map['weight'][(df_map['weight']<0.5) & (df_map['weight']!=0.5)] = 100
        df_map['weight'][df_map['weight']==0.5] = 50
        df_map['weight'][(df_map['weight']>0.5) & (df_map['weight']<50)] = 0

        # plt.scatter(df_map["x grid"], df_map["y grid"], s=1, c = df_map["weight"])
        # #plt.savefig('mapa_9_07_17_menor05',dpi = 1200)
        # plt.show()

        data_occ = df_map[df_map['weight']==0] 

        print(len(data_occ))

        data_occ['weight'] = self.calc_hierarchy(data_occ.iloc[:,0:2],12,10)

        centroids = pd.DataFrame(self.calc_centroid(data_occ))
        centroids.to_csv('centroid.csv')
        plt.scatter(data_occ["x grid"], data_occ["y grid"], s=1, c = data_occ["weight"])
        plt.scatter(centroids.iloc[1:,0], centroids.iloc[1:,1], color='red', s=30)
        plt.show()
        
def main(args=None):
    rclpy.init(args=args)
    node = MapPrinter()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()