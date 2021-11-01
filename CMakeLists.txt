cmake_minimum_required(VERSION 3.0)
project(Pong)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(pong_SRC
  src/main.cpp
  src/pong.cpp
  src/gamewindow.cpp
  src/assets/ball.cpp
  src/assets/pad.cpp
)

# Tell CMake to create the executable
add_executable(pong ${pong_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(pong Qt5::Widgets)

# Install the executable
install(TARGETS pong DESTINATION bin)
