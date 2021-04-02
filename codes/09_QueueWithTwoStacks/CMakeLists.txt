cmake_minimum_required(VERSION 3.5)

project(queue)

set(SOURCES
    ./QueueWithTwoStacks.cpp
    ./Queue.h
)

add_executable(queue ${SOURCES})