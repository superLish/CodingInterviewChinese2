cmake_minimum_required(VERSION 3.5)

project(copylist)

set(SOURCES
    ./ComplexList.h
    ./ComplexList.cpp
    ./CopyComplexList.cpp
)

add_executable(copylist ${SOURCES})