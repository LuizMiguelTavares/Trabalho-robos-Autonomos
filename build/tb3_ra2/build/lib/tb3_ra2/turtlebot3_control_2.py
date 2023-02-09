import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan
from tf_transformations import euler_from_quaternion
from PIL import Image as Img
import math
import numpy as np
import random

class TurtlebotControl(Node):

    def __init__(self):
        super().__init__("turtlebot3_control")

        self.pose             = None            # Guarda a posição e velocidade do robô
        self.graus            = None            # Possui a orientação do robô
        self.msg              = Twist()         # movimenta o robô
        self.yaw              = None

        '''posição em y'''
        self.direita   = 1.575
        self.centro    = 2.175
        self.esquerda  = 2.775

        '''Posição inicial do robô em x'''
        self.x_inicial = -11

        self.flag_centro       = None
        self.pergunta          = False
        self.aux_laser         = None
        self.terminei_de_virar = True
        self.flag_lado         = True
        self.lado              = None

        self.erro_angular_anterior = 0

        self.aux               = True    
        self.aux_loop          = True    

        self.laser_const = 1
        
        self.rotation_p_gain = 5.0
        self.rotation_d_gain = 1.0
        self.forward_gain  = 0.7
        self.safe_margin   = 0.01

        self.rotation_flag = None

        self.dist_270 = None

        # Publishing frame rate
        self.frames_sec = 30

        # Creating motion control publisher
        self.motion_publisher_ = self.create_publisher(Twist, "cmd_vel", 10) # Publishes in the cmd_vel topic from turtlebot3

        self.pose_subscription = self.create_subscription(Odometry, "odom", self.Turtlebot3_pose, 10)

        self.laser_subscriber_ = self.create_subscription(LaserScan, "scan", self.laser_reading, 10)

        self.grid_map_subscriber = self.create_subscription(Image, "/camera/image_raw", self.camera_viewer, 10)
        
        self.timer_ = self.create_timer(1/self.frames_sec, self.control_loop) # Run control_loop 30 times per sec
        
        self.get_logger().info("Turtlebot3 Node has been started!!")
    
    def Turtlebot3_pose(self, msg):
        '''Retorna a Pose do Turtlebot3'''
        self.pose = msg
        self.position = msg.pose.pose.position
        self.orientation = msg.pose.pose.orientation
        self.orientation = [self.orientation.x, self.orientation.y, self.orientation.z, self.orientation.w]
        self.aux = False
        (self.roll, self.pitch, self.yaw) = euler_from_quaternion(self.orientation)

    def laser_reading(self, msg):
        '''Visualiza a posição do bloco'''
        self.aux_laser = True

        '''Esquerda'''
        range_23 = msg.ranges[13]
        range_27 = msg.ranges[15]
        range_31 = msg.ranges[18]
        esquerda = [range_23, range_27, range_31]

        '''Central'''
        range_m4 = msg.ranges[-4]
        range_0 = msg.ranges[0]
        range_4 = msg.ranges[4]
        centro = [range_m4, range_0, range_4]

        '''Direita'''
        range_m23 = msg.ranges[-13]
        range_m27 = msg.ranges[-15]
        range_m31 = msg.ranges[-18]
        direita = [range_m23, range_m27, range_m31]

        self.laser = np.around([esquerda, centro, direita], decimals=2)

    def camera_viewer(self, msg):
        '''Visualiza a cor do bloco'''
        if (self.terminei_de_virar==True):

            imagem = np.array(Img.fromarray(np.array(msg.data, dtype=np.uint8).reshape([1080, 1920,3])).resize((48, 27))).reshape([1296, 3])
            
            cont_verde    = 0
            cont_vermelho = 0
            cont_amarelo  = 0
            cont_azul     = 0

            for i in imagem:
                '''Verde'''
                if (int(i[1])-int(i[0])>130)&(int(i[1])-int(i[2])>130):
                    cont_verde+=1

                '''Vermelho'''
                if (int(i[0])-int(i[1])>130)&(int(i[0])-int(i[2])>130):
                    cont_vermelho+=1
                
                '''Azul'''
                if (int(i[2])-int(i[1])>130)&(int(i[2])-int(i[0])>130):
                    cont_azul+=1

                '''Amarelo'''
                if (int(i[0])>200)&(int(i[1])>200):
                    cont_amarelo+=1

            cont = [cont_amarelo, cont_azul, cont_verde, cont_vermelho]
            max_cont = np.max(cont)

            if max_cont == 0:
                max_cont = -1

            if max_cont==cont_verde:
                self.cor = 'Verde'
            elif max_cont==cont_vermelho:
                self.cor = 'Vermelho'
            elif max_cont==cont_azul:
                self.cor = 'Azul'
            elif max_cont==cont_amarelo:
                self.cor = 'Amarelo'
            else:
                self.cor = 'Nenhum'
    
    def go_to(self, x_target, y_target):
        if self.aux:
            return
        
        aux = 0
        x_position = self.position.x
        y_position = self.position.y

        x = x_target - x_position
        y = y_target - y_position

        if y >=0 and x>=0:
            obj = math.atan(y/x)
        elif y>=0 and x<0:
            obj = np.pi + math.atan(y/x)
        elif y<0 and x>=0:
            obj = math.atan(y/x)
        else:
            obj = -np.pi + math.atan(y/x)

        if self.yaw is None:
            return

        if obj>=0:
            f_obj = True
        else:
            f_obj = False

        if self.yaw>=0:
            f_yaw = True
        else:
            f_yaw = False

        ########################

        if f_obj==f_yaw:
            erro = obj - self.yaw 
        else:
            if f_obj:
                aux = -np.pi+obj
            else:
                aux = np.pi+obj
            
            if f_yaw:
                if self.yaw>=aux:
                    erro = self.yaw - obj 
                else:
                    erro = obj - self.yaw 
            else:
                if self.yaw>=aux:
                    erro = obj - self.yaw 
                else:
                    erro = self.yaw - obj 
        
        position_error = np.sqrt((x_position-x_target)**2 + (y_position-y_target)**2)
        if abs(erro)>0.05:
            self.msg.angular.z = erro # Positivo = anti-horário
        else:
            self.msg.angular.z = 0.0
        
        if self.msg.angular.z > 5.0:
            self.msg.angular.z = 5.0

        if position_error>0.3:
            self.msg.linear.x = self.forward_gain
            self.motion_publisher_.publish(self.msg)
            return False
        else:
            self.msg.linear.x = 0.0
            self.msg.angular.z = 0.0
            self.motion_publisher_.publish(self.msg)
            return True

    def angle_ajust(self):

        if self.yaw == None:
            return

        diff_angle = self.yaw
        if self.erro_angular_anterior == 0:
            self.erro_angular_anterior = diff_angle
        
        self.erro_d = self.erro_angular_anterior - diff_angle
        self.erro_angular_anterior = diff_angle
        
        if abs(diff_angle) > 0.05: 
            self.msg.angular.z = -self.rotation_p_gain * diff_angle + self.rotation_d_gain * self.erro_d
            print(self.msg.angular.z)
            self.msg.linear.x = 0.0

        else:
            self.terminei_de_virar = True
            self.pergunta = False
            self.aux_loop = True
            self.flag_lado = True
            self.msg.angular.z = 0.0
            self.msg.linear.x = 0.0
            self.erro_angular_anterior = 0

        
        self.motion_publisher_.publish(self.msg)

    def control_loop(self):
        
        if self.aux_laser == None:
            return

        if (self.pergunta==False)&(self.terminei_de_virar == True):
            min = np.min(self.laser)

            '''Print da cor e localização do bloco'''
            if np.where(self.laser[0]==min)[0].size > 0:
                self.get_logger().info('Bloco ' + self.cor + ' à esquerda.')
            
            if np.where(self.laser[1]==min)[0].size > 0:
                self.get_logger().info('Bloco ' + self.cor + ' no centro.')
            
            if np.where(self.laser[2]==min)[0].size > 0:
                self.get_logger().info('Bloco ' + self.cor + ' à direita.')
            
            '''Lógica de movimentação'''
            if self.cor == 'Nenhum':
                self.get_logger().info('Não foi possível detectar a cor do bloco')

            if self.cor == 'Vermelho':
                    self.flag_empurrar = True
            else:
                    self.flag_empurrar = False
                
            if np.where(self.laser[1]==min)[0].size > 0:
                self.flag_centro = True
            else:
                self.flag_centro = False

            if (np.where(self.laser[0]==min)[0].size > 0) & (self.cor == 'Vermelho'):
                self.flag_esquerda = True
            else:
                self.flag_esquerda = False
            
            if (np.where(self.laser[2]==min)[0].size > 0) & (self.cor == 'Vermelho'):
                self.flag_direita = True
            else:
                self.flag_direita = False
            self.terminei_de_virar=False
            
        self.pergunta = True
        if (self.pergunta):
            if self.flag_empurrar:
                
                if self.flag_centro:
                    if self.aux_loop:
                        a = self.go_to(self.x_inicial+2, self.centro)
                        if a:
                            self.aux_loop = False
                            self.x_inicial = self.x_inicial + 4
                    else:
                        a = self.go_to(self.x_inicial, 2.175)
                        if a:
                            self.angle_ajust()

                if self.flag_direita:
                    if self.aux_loop:
                        a = self.go_to(self.x_inicial+2, self.direita)
                        if a:
                            self.aux_loop = False
                            self.x_inicial = self.x_inicial + 4
                    else:
                        a = self.go_to(self.x_inicial, 2.175)
                        if a:
                            self.angle_ajust() 
                
                if self.flag_esquerda:

                    if self.aux_loop:
                        a = self.go_to(self.x_inicial+2, self.esquerda)
                        if a:
                            self.aux_loop = False
                            self.x_inicial = self.x_inicial + 4
                    else:
                        a = self.go_to(self.x_inicial, 2.175)
                        if a:
                            self.angle_ajust()
                            
            else:
                if self.flag_centro:
                    if (self.cor == 'Azul'):
                        if self.aux_loop:
                            a = self.go_to(self.x_inicial+2, self.direita)
                            if a:
                                self.aux_loop = False
                                self.x_inicial = self.x_inicial + 4
                        else:
                            a = self.go_to(self.x_inicial, 2.175)
                            if a:
                                self.angle_ajust()
                        
                    elif self.cor == 'Amarelo':
                        if self.aux_loop:
                            if self.flag_lado:
                                random_n = random.randint(0, 1)
                                if random_n == 1:
                                    self.lado = self.direita
                                    self.flag_lado = False
                                else:
                                    self.lado = self.esquerda
                                    self.flag_lado = False
                            
                            a = self.go_to(self.x_inicial+2, self.lado)
                            if a:
                                self.aux_loop = False
                                self.x_inicial = self.x_inicial + 4
                        else:
                            a = self.go_to(self.x_inicial, 2.175)
                            if a:
                                self.angle_ajust()
                    else:
                        if self.aux_loop:
                            a = self.go_to(self.x_inicial+2, self.esquerda)
                            if a:
                                self.aux_loop = False
                                self.x_inicial = self.x_inicial + 4
                        else:
                            a = self.go_to(self.x_inicial, 2.175)
                            if a:
                                self.angle_ajust()

                else:
                        if self.aux_loop:
                            a = self.go_to(self.x_inicial+2, self.centro)
                            if a:
                                self.aux_loop = False
                                self.x_inicial += 4
                        else:
                            a = self.go_to(self.x_inicial, 2.175)
                            if a:
                                self.angle_ajust()

def main(args=None):
    rclpy.init(args=args)
    node = TurtlebotControl()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()