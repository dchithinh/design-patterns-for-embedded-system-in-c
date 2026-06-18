cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter6_02_crc C)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_library(chapter6_02_crc STATIC
  CRCCalculator.c
  PatientData.c
)

target_include_directories(chapter6_02_crc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
