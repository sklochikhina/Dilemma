cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 17)

project(dilemma)

set(exe_name ${PROJECT_NAME})

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(corelib OBJECT Dilemma/complex_strategies.cpp
                            Dilemma/simple_strategies.cpp
                            Dilemma/console_interface.cpp
                            Dilemma/factory.cpp
                            Dilemma/game.cpp
                            Dilemma/game_runner.cpp
                            Dilemma/matrix.cpp)

add_executable(${exe_name} Dilemma/main.cpp)
target_link_libraries(${exe_name} corelib)