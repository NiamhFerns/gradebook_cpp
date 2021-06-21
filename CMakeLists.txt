cmake_minimum_required(VERSION 3.16.4)
project(gradebook)

set (
    HEADER_FILES
    # src/headers/course.hpp
    # src/headers/assessment.hpp
    src/headers/misc.hpp
)

set(
    SRC_FILES
    src/main.cpp
    # src/assessments.cpp
    # src/course.cpp
    src/misc.cpp
)

add_executable(GradeBook ${HEADER_FILES} ${SRC_FILES})

target_link_libraries(GradeBook)