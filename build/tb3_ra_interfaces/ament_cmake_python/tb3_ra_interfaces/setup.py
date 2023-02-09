from setuptools import find_packages
from setuptools import setup

setup(
    name='tb3_ra_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('tb3_ra_interfaces', 'tb3_ra_interfaces.*')),
)
