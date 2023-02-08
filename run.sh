#!/bin/bash

set -e

g++ -g test.cpp -std=c++11 -o testc
./testc