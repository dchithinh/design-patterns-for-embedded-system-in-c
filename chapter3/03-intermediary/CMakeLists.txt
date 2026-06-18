cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter3_03_intermediary C)
  include(CTest)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_executable(chapter3_03_intermediary
  Action.c
  GraspingManipulator.c
  RobotArmManager.c
  RotatingArmJoint.c
  SlidingArmJoint.c
  main.c
)

target_include_directories(chapter3_03_intermediary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTING)
  add_test(NAME chapter3_03_intermediary COMMAND chapter3_03_intermediary)
endif()
