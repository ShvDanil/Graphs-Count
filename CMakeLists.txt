cmake_minimum_required(VERSION 3.21)
project(peergradeGraphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        peergradeGraphs main.cpp
        adjacency_list.h
        adjacency_matrix.h
        console_input.h console_input.cpp
        defines.h
        edges_list.h
        file_input.h file_input.cpp
        graph.h
        graph_info_helper.h graph_info_helper.cpp
        incidence_matrix.h
        inner_helper.h inner_helper.cpp
        instructions.h instructions.cpp
        validator.cpp validator.h)
