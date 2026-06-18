cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter4_05_queue C)
endif()

add_custom_target(chapter4_05_queue)
message(STATUS "chapter4/05-queue: placeholder target only. Example depends on missing OS semaphore/thread support headers.")
