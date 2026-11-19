cmake_minimum_required(3.20)

add_library(tkstdc++ INTERFACE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


target_include_directories(tkstdc++ PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)