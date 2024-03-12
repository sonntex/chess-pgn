cmake_minimum_required(VERSION 3.27)

project(chess)

add_compile_options(-Wall -Winline)

enable_testing()
add_subdirectory(src)
