from setuptools import setup,Extension

setup(
    name='Fibonacci',
    ext_modules=[
        Extension('Fibonacci',['Fibonacci.c'])
    ]
)

