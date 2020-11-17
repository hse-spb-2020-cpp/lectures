cmake_minimum_required(VERSION 3.10)

# set the project name
project(01-basic-functions)

add_compile_options(-std=c++17)

if (MSVC)
    add_compile_options(/W4 /WX)
    # Do not specify /O2 because there are Debug/Release modes.
else()
    add_compile_options(-Wall -Wextra -Werror -O2)
    if (UNIX)
      add_compile_options(-fsanitize=address)
      add_link_options(-fsanitize=address)
    endif (UNIX)
endif (MSVC)

# add the executable
add_executable(main-a       main.cpp print_hello_1.cpp)
add_executable(main-a-debug main.cpp print_hello_1.cpp)
add_executable(main-b       main.cpp print_hello_2.cpp)

target_compile_options(main-a-debug PUBLIC -DDEBUG)
