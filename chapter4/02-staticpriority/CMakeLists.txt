cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter4_02_staticpriority C)
endif()

add_custom_target(chapter4_02_staticpriority)
message(STATUS "chapter4/02-staticpriority: placeholder target only. Example depends on RTOS APIs and missing constants/types.")
