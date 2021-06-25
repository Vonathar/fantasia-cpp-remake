cmake_minimum_required(VERSION 3.7)
project(fantasia_remake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)

############################
##     Required files     ##
############################

set(SOURCE_FILES
        src/enums/stage_name.h src/gui/drawables/reusable/rounded_rect.cpp src/gui/drawables/reusable/rounded_rect.h
        src/gui/drawables/reusable/progress_bar.cpp src/gui/drawables/reusable/progress_bar.h src/entities/player.h
        src/entities/stage.cpp src/entities/stage.h src/game.cpp src/game.h src/entities/enemy.h
        src/gui/drawables/player_gui.h src/gui/drawables/enemy_gui.h src/gui/drawables/static_gui.h
        src/gui/drawables/static_gui.cpp src/gui/resources.cpp src/gui/resources.h src/entities/player.cpp
        src/enums/enemy_name.h src/entities/enemy.cpp src/gui/drawables/enemy_gui.cpp src/gui/drawables/player_gui.cpp
        src/gui/animator.cpp src/gui/animator.h src/enums/resource_name.h src/enums/player_rank.h
        src/enemy_generator.cpp src/enemy_generator.h src/gui/drawables/damage_bubble.cpp
        src/gui/drawables/damage_bubble.h src/number_formatter.cpp src/number_formatter.h
        src/gui/drawables/money.cpp src/gui/drawables/money.h src/entities/inventory.cpp src/entities/inventory.h
        src/gui/drawables/inventory_gui.cpp src/gui/drawables/inventory_gui.h src/gui/drawables/stage/stage_gui.cpp
        src/gui/drawables/stage/stage_gui.h src/gui/drawables/stage/stage_level.h src/gui/drawables/stage/stage_level.cpp
        src/gui/drawables/stage/stage_enemy_counter.cpp src/gui/drawables/stage/stage_enemy_counter.h
        src/gui/drawables/stage/stage_boss_button.cpp src/gui/drawables/stage/stage_boss_button.h
        src/interfaces/clickable.h)

set(TEST_FILES
        tests/init.cpp
        tests/number_formatter_test.cpp tests/resources_test.cpp tests/player_test.cpp
        tests/enemy_test.cpp tests/enemy_generator_test.cpp tests/animator_test.cpp tests/damage_bubble_test.cpp
        tests/inventory_test.cpp tests/stage_test.cpp tests/stage_gui_test.cpp tests/money_test.cpp
        tests/game_test.cpp
        )

set(SFML_FILES
        sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

###########################
##     Load packages     ##
###########################

find_package(Catch2 REQUIRED)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

if (NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif ()

#########################
##     Executables     ##
#########################

add_executable(sfml "src/main.cpp" ${SOURCE_FILES})
target_link_libraries(sfml ${SFML_FILES} "spdlog::spdlog")
add_executable(tests ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(tests PRIVATE ${SFML_FILES} Catch2::Catch2WithMain)