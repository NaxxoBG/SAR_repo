cmake_minimum_required(VERSION 3.10)
project(zeromq_quickstart)


# The project relies on several external libraries.
# These are managed by the Conan package manager (https://conan.io/)
# Conan provides a way to launch conan directly from cmake: (https://docs.conan.io/en/latest/howtos/cmake_launch.html)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES 
                
   zeromq/4.3.2
   fmt/6.1.1
   
   BASIC_SETUP 
   BUILD missing)


add_executable(tests
   src/main.cpp
)

target_link_libraries(tests
   PUBLIC
   ${CONAN_LIBS})
