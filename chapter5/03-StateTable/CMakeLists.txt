cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter5_03_state_table C)
endif()

add_custom_target(chapter5_03_state_table)
message(STATUS "chapter5/03-StateTable: placeholder target only. Example depends on missing Mutex/runtime headers.")
