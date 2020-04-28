cmake_minimum_required(VERSION 3.10)
project(assignment_12_code_reuse)

add_executable(tests
    src/main.cpp
    src/units/soldier.cpp
    src/units/unit_selection.cpp
	src/monitor/battle_monitor.cpp
	src/weapons/Revolver.cpp
    
)
target_include_directories(tests
    PUBLIC
    include
)

