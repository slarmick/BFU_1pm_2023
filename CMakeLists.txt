cmake_minimum_required(VERSION 3.10)

project("cmake&git")

add_library(functions "func.cpp")
add_executable(main "main.cpp")

target_link_libraries(main functions)