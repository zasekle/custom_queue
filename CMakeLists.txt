cmake_minimum_required(VERSION 3.25)
project(custom_queue)

set(CMAKE_CXX_STANDARD 23)

add_executable(custom_queue main.cpp custom_queue.h queue_tests.cpp queue_tests.h)
