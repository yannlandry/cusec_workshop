from setuptools import Extension
from setuptools import setup


"""
    E. Define the extension, dependencies, etc.
"""
yelp_arithmetic = Extension(
    name="yelp_arithmetic",
    sources=["yelp_arithmetic.c"],
)


"""
    F. Initialize package with extension
"""
setup(
    name="yelp_arithmetic",
    ext_modules=[yelp_arithmetic],
)


"""
    G. After testing, add exception support
       Add additional methods if time permits
"""