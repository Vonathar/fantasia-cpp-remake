cmake_minimum_required(VERSION 3.7)
project(fantasia_remake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)

############################
##     Required files     ##
############################

set(SOURCE_FILES
        src/stage_name.h src/rounded_rect.cpp src/rounded_rect.h
        src/progress_bar.cpp src/progress_bar.h src/player.h
        src/stage.cpp src/stage.h src/game.cpp src/game.h src/enemy.h
        src/entity.h src/player_gui.h src/enemy_gui.h src/static_gui.h
        src/static_gui.cpp src/resources.cpp src/resources.h src/player.cpp
        src/enemy_name.h src/enemy.cpp src/enemy_gui.cpp src/player_gui.cpp
        src/animator.cpp src/animator.h src/resource_name.h src/player_rank.h
        src/enemy_generator.cpp src/enemy_generator.h src/damage_bubble.cpp
        src/damage_bubble.h src/number_formatter.cpp src/number_formatter.h
        src/money.cpp src/money.h src/inventory.cpp src/inventory.h
        src/inventory_gui.cpp src/inventory_gui.h src/stage_gui.cpp src/stage_gui.h)

set(TEST_FILES
        tests/init.cpp
        tests/number_formatter_test.cpp tests/resources_test.cpp
        tests/player_test.cpp tests/money_test.cpp tests/enemy_test.cpp
        tests/enemy_generator_test.cpp tests/animator_test.cpp
        tests/damage_bubble_test.cpp tests/inventory_test.cpp)

set(SFML_FILES
        sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

##########################
##     Fetch Catch2     ##
##########################

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.1)
FetchContent_MakeAvailable(Catch2)

#######################
##     Load SFML     ##
#######################

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

#########################
##     Load Spdlog     ##
#########################

if (NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif ()

#########################
##     Executables     ##
#########################

add_executable(sfml "src/main.cpp" ${SOURCE_FILES})
target_link_libraries(sfml ${SFML_FILES}, spdlog::spdlog)
add_executable(tests ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2 ${SFML_FILES})
