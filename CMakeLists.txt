cmake_minimum_required(VERSION 3.7)
project(fantasia_remake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES src/main.cpp src/resource_manager.cpp src/resource_manager.h src/enum/stage_name.h src/window_manager.cpp src/window_manager.h src/gui/rounded_rectangle_shape.cpp src/gui/rounded_rectangle_shape.h src/gui/progress_bar.cpp src/gui/progress_bar.h src/clickable.h src/entity/player.cpp src/entity/player.h src/entity/stage.cpp src/entity/stage.h src/gameplay/game.cpp src/gameplay/game.h src/entity/enemy.cpp src/entity/enemy.h)
FILE(COPY res DESTINATION "${CMAKE_BINARY_DIR}")

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(sfml ${SOURCE_FILES})
target_link_libraries(sfml sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
