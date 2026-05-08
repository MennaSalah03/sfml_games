cmake_minimum_required(VERSION 3.10)

# Project name and version
project(WanderingStar VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find SFML 2.5
# This looks for the SFMLConfig.cmake file which should be in /usr/local/lib/cmake/SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# 2. Add the executable
add_executable(test_app src/main.cpp src/Game.cpp)

# 3. Finding header files
target_include_directories(test_app PRIVATE include)

# 4. Link the SFML libraries to your executable
target_link_libraries(test_app sfml-graphics sfml-window sfml-system)