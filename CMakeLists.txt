cmake_minimum_required(VERSION 3.24)
project(SDIZOproject)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDIZOproject main.cpp Table/Table.cpp Table/Table.h Menu.cpp Menu.h DoubleLinkedList/DoubleLinkedList.cpp DoubleLinkedList/DoubleLinkedList.h DoubleLinkedList/Node.cpp DoubleLinkedList/Node.h Heap/Heap.cpp Heap/Heap.h)
