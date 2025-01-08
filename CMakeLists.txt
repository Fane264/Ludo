cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Options.cmake)

###############################################################################

# Include SFML
# Actualizează această cale pentru a indica locația exactă unde se află fișierul SFMLConfig.cmake
set(SFML_DIR "C:/SFML/lib/cmake/SFML") # Schimbă C:SFML-3.0.0/lib/cmake/SFML în C:/SFML/lib/cmake/SFML

# Asigură-te că prefixul este setat corect pentru căutare suplimentară
list(APPEND CMAKE_PREFIX_PATH "C:/SFML")

# Găsește pachetul SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing name here
add_executable(${PROJECT_NAME}
        main.cpp
        generated/src/Helper.cpp
        Include/Piece.h
        src/Piece.cpp
        Include/Player.h
        src/Player.cpp
        Include/Board.h
        src/Board.cpp
        Include/GameEntity.h
        Include/GameException.h
        Include/Exceptions.h
)

include(cmake/CompilerFlags.cmake)

###############################################################################

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)

# Include directories for SFML
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${SFML_INCLUDE_DIR})

###############################################################################

# use SYSTEM so cppcheck and clang-tidy do not report warnings from these directories
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE generated/include)

###############################################################################

# copy binaries to "bin" folder; these are uploaded as artifacts on each release
# DESTINATION_DIR is set as "bin" in cmake/Options.cmake:6
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

include(cmake/CopyHelper.cmake)
copy_files(FILES tastatura.txt)
# copy_files(FILES tastatura.txt config.json DIRECTORY images sounds)
# copy_files(DIRECTORY images sounds)
