# set minimum version of CMake.
cmake_minimum_required(VERSION 3.13)

# set project name and version
project(klib-x86 VERSION 0.0.1)

# change all floating point constants to single precision
add_compile_options("-fsingle-precision-constant")

# set the sources
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/math.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/queue.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/ringbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/string.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/units.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/vector2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/vector3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/crypt/base32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/io/rtc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/klib/dynamic_array.cpp
)

# add our executable
add_executable(klib-x86
    ${SOURCES}
)

# enable C++20 support
target_compile_features(klib-x86 PUBLIC cxx_std_20)
target_compile_options(klib-x86 PUBLIC -O1)

# include klib 
target_include_directories(klib-x86 PUBLIC ../klib/)

# Libraries to link for all targets
target_link_libraries(klib-x86 PUBLIC m)