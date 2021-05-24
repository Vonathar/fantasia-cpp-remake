cmake_minimum_required(VERSION 3.7)
project(fantasia_remake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES "src/main.cpp" "src/stage_name.h" "src/rounded_rect.cpp" "src/rounded_rect.h" "src/progress_bar.cpp" "src/progress_bar.h" "src/player.h" "src/stage.cpp" "src/stage.h" "src/game.cpp" "src/game.h" "src/enemy.h" "src/entity.h" "src/player_gui.h" "src/enemy_gui.h" "src/static_gui.h" src/static_gui.cpp src/resources.cpp src/resources.h src/player.cpp src/enemy_name.h src/enemy.cpp src/enemy_gui.cpp src/player_gui.cpp src/animator.cpp src/animator.h src/resource_name.h src/player_rank.h src/enemy_generator.cpp src/enemy_generator.h src/damage_bubble.cpp src/damage_bubble.h)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(sfml ${SOURCE_FILES})
target_link_libraries(sfml sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
