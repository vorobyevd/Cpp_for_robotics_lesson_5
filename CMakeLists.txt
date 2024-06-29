cmake_minimum_required(VERSION 3.30)        # Minimum cmake version

# Project description
project(
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Car class"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)                  # Set required C++ standart
set(CMAKE_CXX_STANDARD_REQUIRED ON)         # Check standart

set(CMAKE_BUILD_TYPE Debug)                 # Set type of build

add_executable(car_class)                     


set(sources 
                             # Add source code files
         main.cpp
    )
target_sources(car_class PRIVATE ${sources})  # Sefine sources for compilation

target_include_directories(car_class
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"

)
