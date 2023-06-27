cmake_minimum_required(VERSION 3.22)
project("MakeSquare")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c11")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fprofile-arcs -fno-omit-frame-pointer -fsanitize=address")


file(GLOB LIB_SOURCES src/MakeSquare.c)
file(GLOB LIB_HEADERS lib/MakeSquare.h)

add_library(MakeSquareLib ${LIB_SOURCES} ${LIB_HEADERS})

#Create executable
add_executable(squareCompute main.c)
target_link_libraries(squareCompute MakeSquareLib)


file(COPY build/libMakeSquareLib.a DESTINATION test/.)
