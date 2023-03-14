# CMakeLists File for the simulation in this filesystem
# Go figure

# Minium requirement for CMAKE
cmake_minimum_required(VERSION 3.16)

# Give Project Name
project(LIGHT-1_BG)

# Load Geant4
find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

# Set the directories
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cc")
file(GLOB headers "${PROJECT_SOURCE_DIR}/include/*.hh")

# Set up executable
add_executable(LIGHT-1_BG LIGHT-1_BG.cc ${sources} ${headers})
target_link_libraries(LIGHT-1_BG ${Geant4_LIBRARIES})

# Install file
install(TARGETS LIGHT-1_BG DESTINATION bin)