cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter4_03_critical C)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_library(chapter4_03_critical STATIC
  CRRobotArmManager.c
)

target_include_directories(chapter4_03_critical PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
