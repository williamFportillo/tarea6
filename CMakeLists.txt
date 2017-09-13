cmake_minimum_required(VERSION 3.8)
project(tarea6progra)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Evaluador.cpp Evaluador.h Pais.cpp Pais.h NodoNario.cpp NodoNario.h)
add_executable(tarea6progra ${SOURCE_FILES})