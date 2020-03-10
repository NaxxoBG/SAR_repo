project(client_server)
cmake_minimum_required(VERSION 3.10)


# The project relies on several external libraries.
# These are managed by the Conan package manager (https://conan.io/)
# This can be install using "pip install conan"

# Conan provides a way to launch conan directly from cmake: (https://docs.conan.io/en/latest/howtos/cmake_launch.html)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES 

                fmt/6.1.1
                boost/1.71.0
                BASIC_SETUP 
                BUILD missing)


# end of external packages

# create two executables which depends on the external libraries defined above
# first executeable is the client
add_executable(client
    src/client.cpp
)
target_link_libraries(client PRIVATE ${CONAN_LIBS})


# second executable is the server
add_executable(server

    src/server.cpp
)
target_link_libraries(server PRIVATE ${CONAN_LIBS})


