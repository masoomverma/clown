cmake_minimum_required(VERSION 3.20)
project(clown)

add_executable(clown
    src/main.cpp

    src/core/editor.cpp
    src/core/editor_loop.cpp

    src/buffer/buffer.cpp
    src/buffer/gap_buffer.cpp

    src/render/renderer.cpp
    src/render/screen.cpp

    src/input/keyboard.cpp
    src/input/commands.cpp

    src/io/fileio.cpp
    src/io/config.cpp
)

target_compile_features(clown PRIVATE cxx_std_20)

target_include_directories(clown PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/pdcurses
)

target_link_libraries(clown PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/pdcurses.lib
)