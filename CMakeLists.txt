cmake_minimum_required(VERSION 3.16)
project(CodeSouls LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where SFML is installed
set(SFML_DIR "C:/Users/warad/OneDrive/Documents/SFML-3.0.2-windows-vc17-64-bit/SFML-3.0.2/lib/cmake/SFML")

# SFML 3 REQUIRES components
find_package(SFML REQUIRED COMPONENTS Graphics Window System)

add_executable(CodeSouls
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
)

target_link_libraries(CodeSouls PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

# Copy SFML DLLs next to the executable on Windows
if (WIN32)
    add_custom_command(TARGET CodeSouls POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:CodeSouls>
        $<TARGET_FILE_DIR:CodeSouls>
        COMMAND_EXPAND_LISTS
    )
endif()