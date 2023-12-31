# set minimum version of CMake.
cmake_minimum_required(VERSION 3.13)

# set project name and version
project(klib-x86 VERSION 0.0.1)

# change all floating point constants to single precision
add_compile_options("-fsingle-precision-constant")

# set the sources
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# add our executable
add_executable(klib-x86
    ${SOURCES}
)

# Libraries to link for all targets
target_link_libraries(klib-x86 PUBLIC m)