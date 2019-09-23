cmake_minimum_required(VERSION 3.14)

add_executable(simple "simple.cu")

target_link_libraries(simple
	array-lite)
