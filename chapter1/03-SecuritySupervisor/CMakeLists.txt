cmake_minimum_required(VERSION 3.16)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(chapter1_03_security_supervisor C)
  include(CTest)
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)
endif()

add_executable(chapter1_03_security_supervisor
  SecuritySupervisor.c
  SecuritySupervisorTest.c
)

target_include_directories(chapter1_03_security_supervisor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_TESTING)
  add_test(NAME chapter1_03_security_supervisor COMMAND chapter1_03_security_supervisor)
endif()
