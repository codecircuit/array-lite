cmake_minimum_required(VERSION 3.14)

project(array-lite
    VERSION 1.0.0
    LANGUAGES CXX CUDA)

option(BUILD_EXAMPLES "Build examples" OFF)

add_subdirectory(src)

if (BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

find_package(CMakeshift 3.4 REQUIRED)
include(CMakeshift/InstallSimpleLibraryPackage)
cmakeshift_install_simple_library_package(
    INTERFACE
    EXPORT array-liteTargets
    VERSION_COMPATIBILITY SameMajorVersion
    CONFIG_TEMPLATE "cmake/array-liteConfig.cmake.in")
