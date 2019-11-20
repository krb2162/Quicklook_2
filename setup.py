try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension
import numpy
name = "oct1"
version = "1.0"

ext_modules=[Extension("_oct1",
        sources=["oct1_wrap.c", "oct1.c"],swig_opts=['-modern', '-I../include'],library_dirs=['/usr/local/Cellar/cfitsio/3.450_1/include'],libraries=['cfitsio'])]


setup(name="oct1", version="1.0", include_dirs=['Practice_Research_Class',numpy.get_include()],py_modules = ["oct1"],ext_modules=ext_modules)
