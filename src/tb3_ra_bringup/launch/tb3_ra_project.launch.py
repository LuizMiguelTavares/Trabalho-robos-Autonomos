from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    turtlebot3_control_node = Node(
        package="tb3_ra",
        executable="turtlebot3_control"
    )

    ld.add_action(turtlebot3_control_node)

    map_creator_node = Node(
        package="tb3_ra",
        executable="map_creator"
    )

    ld.add_action(map_creator_node)

    return ld
