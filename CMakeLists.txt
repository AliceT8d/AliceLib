cmake_minimum_required(VERSION 4.1)
project(AliceLib)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE ALI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ali/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ali/*.cpp
)

add_executable(AliceLib main.cpp 
    ${ALI_FILES}      
)