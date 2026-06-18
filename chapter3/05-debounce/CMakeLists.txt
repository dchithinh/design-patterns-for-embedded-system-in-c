cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter3_05_debounce C)
  include(CTest)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_executable(chapter3_05_debounce
  Button.c
  ButtonDriver.c
  MicrowaveEmitter.c
  Timer.c
  main.c
)

target_include_directories(chapter3_05_debounce PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTING)
  add_test(NAME chapter3_05_debounce COMMAND chapter3_05_debounce)
endif()
