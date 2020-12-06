cmake_minimum_required(VERSION 3.10)

# Modifier ces variables si vous avez des fichiers à ajouter.
set(ZZ_SRC
    src/item.cpp
    #src/arme.cpp
    #src/enchantement.cpp
    #src/inventaire.cpp
)
set(ZZ_HEADER
    src/item.hpp
    src/arme.hpp
    #src/enchantement.hpp
    #src/inventaire.hpp
)

# Ne pas toucher le reste.

set(TEST_SRC test/catch.cpp test/test_examen.cpp)
set(TEST_HEADER test/catch.hpp)


project(examen_blanc CXX)
project(inventaire CXX)

add_library(inventaire ${ZZ_SRC} ${ZZ_HEADER})
add_executable(panda ${TEST_SRC} ${TEST_HEADER})

target_include_directories(panda PRIVATE src)
target_link_libraries(panda inventaire)

target_compile_options(inventaire PUBLIC -g -Wall -Wextra -pedantic)
target_compile_features(inventaire PUBLIC cxx_std_14)
