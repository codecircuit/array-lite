cmake_minimum_required(VERSION 3.14)

find_package(CMakeshift 3.4 REQUIRED)

# targets
add_library(array-lite INTERFACE)

# library properties
target_include_directories(array-lite
    INTERFACE
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
target_compile_features(array-lite
    INTERFACE
        cxx_std_14)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
    DESTINATION "include")
install(
    TARGETS array-lite
    EXPORT array-liteTargets
    INCLUDES DESTINATION "include")
