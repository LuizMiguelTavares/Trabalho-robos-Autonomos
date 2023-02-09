from setuptools import setup

package_name = 'tb3_ra2'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='miguel',
    maintainer_email='miguel@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "turtlebot3_control_2 = tb3_ra2.turtlebot3_control_2:main", 
            "turtlebot3_control_2_marcal = tb3_ra2.turtlebot3_control_2_marcal:main"
        ],
    },
)
