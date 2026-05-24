cmake_minimum_required(VERSION 3.16)

# Project name and language
project(Client VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable from main.cpp
add_executable(Client client.cpp
        ../src_clase/Aplicatie.cpp
        ../src_clase/Candidat.cpp
        ../src_clase/Job.cpp)