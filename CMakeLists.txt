cmake_minimum_required(VERSION 3.16)

project(expr VERSION 1.0.0 LANGUAGES CXX)

add_library(expr INTERFACE)
add_library(expr::expr ALIAS expr)

target_compile_features(expr INTERFACE cxx_std_11)

target_include_directories(expr INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(expr_basic examples/basic.cpp)
    target_link_libraries(expr_basic PRIVATE expr::expr)
endif()
