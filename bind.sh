#!/bin/bash

 c++ -O3 -Wall -shared -std=c++14 -fPIC \
	$(python3 -m pybind11 --includes)  -I .\
	./pybind11.cpp  \
	-o ./capy$(python3-config --extension-suffix)
	
 if [ $? -eq 0 ]
 then
   echo "no error , install on /usr/local/lib/python3.5/dist-packages/capy.cpython-35m-x86_64-linux-gnu.so"
   sudo cp capy.cpython-35m-x86_64-linux-gnu.so /usr/local/lib/python3.5/dist-packages/capy.cpython-35m-x86_64-linux-gnu.so
   [ $? -ne 0 ] && echo 'error on install !!'
 fi
