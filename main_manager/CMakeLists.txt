cmake_minimum_required(VERSION 4.2)
project(manager)

include_directories(../src_clase)

add_executable(manager
        manager.cpp
        ../src_clase/Aplicatie.cpp

        ../src_clase/Candidat.cpp

        ../src_clase/Job.cpp

        ../src_clase/Manager_interface.cpp
)
