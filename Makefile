#!/bin/bash

hello :
	swig -python oct1.i
	python setup.py build_ext --inplace	
.PHONY : clean
clean :
	-rm edit oct1.py oct1_wrap.o oct1_wrap.c _oct1.cpython-36m-darwin.so
	-rm -R edit build __pycache__
