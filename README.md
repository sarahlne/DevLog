# DevLog
+ `setup.py` contains all the code needed to create the extension module using distutils library.
+ `install.sh` contains the command lines that should be executed to build the extension module .so:
+ `script.py` a simple python script that calls the extension (simple example)
+ `my_wrapper_c.cpython-36m-darwin.so` compiled extension
  + `MyWrapper.cpp`: C++/C - Python Wrapper. This file includes the <Python.h> header, that defines functions to parse and create python objects (e.g., lists ...). The basic idea is that when a C/C++ object is created, its pointer is stored in a Capsule and returned as a python object.
