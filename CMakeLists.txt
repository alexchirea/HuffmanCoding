cmake_minimum_required(VERSION 3.8)
project(HuffmanCoding)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")


set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c codificare.h definitii.h sortare.h grafica.h)
add_executable(HuffmanCoding ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(HuffmanCoding ${GTK3_LIBRARIES})