cmake_minimum_required(VERSION 4.2)
project(Proiect_CPP_MC_TP)

set(CMAKE_CXX_STANDARD 14)

include_directories(../src_clase)

add_executable(Proiect_CPP_MC_TP
        manager.cpp
        ../src_clase/Aplicatie.cpp
        ../src_clase/Aplicatie.h
        ../src_clase/Candidat.cpp
        ../src_clase/Candidat.h
        ../src_clase/Job.cpp
        ../src_clase/Job.h)
