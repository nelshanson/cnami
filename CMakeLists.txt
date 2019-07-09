cmake_minimum_required (VERSION 2.6)
project (Cnami)

# Version information
set (Cnami_VERSION_MAJOR 0)
set (Cnami_VERSION_MINOR 1)

# Configuration settings
configure_file (
    "./src/CnamiConfig.h.in"
    "./bin/CnamiConfig.h"
)

# Add bin tree to the search path
include_directories("./bin")

# Add the executable
add_executable(Cnami ./src/cnami.c)
add_library(utils ./src/utils.c)

# Link libraries
target_link_libraries(Cnami m)
target_link_libraries(Cnami utils)