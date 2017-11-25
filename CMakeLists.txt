cmake_minimum_required(VERSION 3.8)
project(HuffmanCoding)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c codificare.h definitii.h)
add_executable(HuffmanCoding ${SOURCE_FILES})