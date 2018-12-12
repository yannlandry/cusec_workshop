from setuptools import Extension
from setuptools import setup


yelp_arithmetic = Extension(
    name="yelp_arithmetic",
    sources=["yelp_arithmetic.c"],
)


setup(
    name="yelp_arithmetic",
    ext_modules=[yelp_arithmetic],
)