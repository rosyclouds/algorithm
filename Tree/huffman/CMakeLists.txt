cmake_minimum_required(VERSION 3.6)
project(huffman_c)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -std=c99")


set(SOURCE_FILES huffmanCode.c MinHeap.c)
add_executable(huffman_c ${SOURCE_FILES})