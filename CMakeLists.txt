cmake_minimum_required(VERSION 3.16.4)
project(gradebook)

set (
    HEADER_FILES

)

set(
    SRC_FILES
    src/main.cpp
)

add_executable(GradeBook ${SRC_FILES})

target_link_libraries(GradeBook)