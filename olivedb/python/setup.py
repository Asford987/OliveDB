from setuptools import setup, Extension
import pybind11

# Locate pybind11 include directories
pybind11_include = pybind11.get_include()

# Define the extension module
ext_modules = [
    Extension(
        'example',
        ['example.cpp'],
        include_dirs=[pybind11_include],
        language='c++'
    ),
]

# Setup script
setup(
    name='example',
    version='0.1',
    ext_modules=ext_modules,
    zip_safe=False,
)
