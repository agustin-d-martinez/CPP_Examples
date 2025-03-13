cmake_minimum_required(VERSION 3.10.0)
project(CPP_Examples VERSION 0.1.0 LANGUAGES C CXX)

# Busca recursivamente todos los archivos .cpp en la carpeta lib
file(GLOB_RECURSE LIB_SOURCES "${CMAKE_SOURCE_DIR}/lib/*.cpp")
add_executable(CPP_Examples main.cpp ${LIB_SOURCES})

include(CTest)
enable_testing()

