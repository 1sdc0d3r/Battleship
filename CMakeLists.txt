cmake_minimum_required(VERSION 3.5)
project(battleship)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

# set( APP_EXECUTABLE main )
set( APP_EXECUTABLE main )


add_executable(${APP_EXECUTABLE}
src/Game.cpp
inc/Board.h
src/Board.cpp
inc/Player.h
src/Player.cpp
inc/Ship.h
src/Ship.cpp
)


#! this works... however gets stuck in a while loop because of user input -- use a num rand generator for input
find_program(VALGRIND "valgrind")
if(VALGRIND)
add_definitions(-D TESTING=true)
add_custom_target(valgrind
		COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()

# message("MY_VARIABLE=${MY_VARIABLE}")
# if( MY_VARIABLE )
    # message("MY_VARIABLE evaluates to True")
	# -DMY_VARIABLE=True
# endif()
