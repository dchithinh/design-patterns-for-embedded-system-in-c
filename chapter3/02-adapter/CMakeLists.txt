cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter3_02_adapter C)
  include(CTest)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_executable(chapter3_02_adapter
  AcmeO2Adapter.c
  AcmeO2SensorProxy.c
  GasDisplay.c
  GasMixer.c
  O2SensorFactory.c
  UltimateO2Adapter.c
  UltimateO2SensorProxy.c
  iO2Sensor.c
  main.c
)

target_include_directories(chapter3_02_adapter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTING)
  add_test(NAME chapter3_02_adapter COMMAND chapter3_02_adapter)
endif()
