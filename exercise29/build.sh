#!/bin/bash

# Build Exercise29
cc -c libex29.c -o build/libex29.o
cc -shared -o build/libex29.so build/libex29.o
cc -Wall -g -DNDEBUG ex29.c -ldl -o build/ex29