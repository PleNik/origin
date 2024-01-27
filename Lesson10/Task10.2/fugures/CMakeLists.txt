cmake_minimum_required(VERSION 3.22.2)
project(figures)
set(source_files figures.cpp figure.cpp treangle.cpp rightTriangle.cpp isoscelesTriangle.cpp equilateralTriangle.cpp quadrilateral.cpp 
rectangle.cpp square.cpp parallelogram.cpp rhombus.cpp)
add_executable(figures ${source_files})