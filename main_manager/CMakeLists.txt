cmake_minimum_required(VERSION 4.1)
project(main_manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(main_manager
    manager.cpp
    ../src_clase/Job.cpp
    ../src_clase/Candidat.cpp
    ../src_clase/Aplicatie.cpp
)

target_include_directories(main_manager PRIVATE ../src_clase)