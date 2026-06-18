cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter2_01_client_server C)
  include(CTest)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_executable(chapter2_01_client_server
  ArrhythmiaDetector.c
  ECG_Module.c
  HistogramDisplay.c
  QRSDetector.c
  TMDQueue.c
  TestBuilder.c
  TimeMarkedData.c
  WaveformDisplay.c
  main.c
)

target_include_directories(chapter2_01_client_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTING)
  add_test(NAME chapter2_01_client_server COMMAND chapter2_01_client_server)
endif()
