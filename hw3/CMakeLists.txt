cmake_minimum_required(VERSION 3.9)
project(hw3 C)

set(CMAKE_C_STANDARD 99)
add_executable(hw3 main.c mtmflix.c user.h user.c series.h series.c mtmflix.h
      map.h set.h mtm_ex3.h list.h libmtm.a libmtm_ex3.a)
target_link_libraries(hw3 ${CMAKE_SOURCE_DIR}/libmtm.a ${CMAKE_SOURCE_DIR}/libmtm_ex3.a)
set(CMAKE_C_FLAGS "-std=c99 -Wall -Werror -pedantic-errors -DNDEBUG")
set(CMAKE_LEGACY_CYGWIN_WIN32 0)