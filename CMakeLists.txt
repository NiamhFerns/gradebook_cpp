cmake_minimum_required(VERSION 3.16.4)
project(gradebook)

set (
    HEADER_FILES
    src/headers/init.hpp
    src/headers/menu.hpp
    src/headers/course.hpp
    src/headers/assessment.hpp
)

set(
    SRC_FILES
    src/main.cpp
    src/init.cpp
    src/menu.cpp
    src/course.cpp
    src/assessment.cpp
)

add_executable(GradeBook ${HEADER_FILES} ${SRC_FILES})

target_link_libraries(GradeBook)