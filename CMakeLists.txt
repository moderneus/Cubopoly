cmake_minimum_required(VERSION 4.1.1)
project(Cubopoly LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)

add_executable(Cubopoly 
        
    src/Cubopoly.cpp
    src/CommandMap.cpp
    src/Options.cpp
    src/Game.cpp
    src/Player.cpp
    src/Utils.cpp
    
)

target_include_directories(Cubopoly PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_link_libraries(Cubopoly PRIVATE fmt::fmt)
target_compile_options(Cubopoly PRIVATE -g)
