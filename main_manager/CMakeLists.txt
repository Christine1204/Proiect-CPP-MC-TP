cmake_minimum_required(VERSION 4.2)
project(manager)

include_directories(../shared/classes)

add_executable(manager
        manager.cpp
        ../shared/classes/Aplicatie.cpp

        ../shared/classes/Candidat.cpp

        ../shared/classes/Job.cpp

        ../shared/classes/Manager_interface.cpp
) 
