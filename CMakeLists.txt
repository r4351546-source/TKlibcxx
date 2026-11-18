cmake_minimum_required(3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
    tk_stdlib
    VERSION 0.0
    LANGUAGES CXX
)

target_include_directories(tk_stdlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)