cmake_minimum_required(VERSION 3.0.0)
project(PruebaBandas VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PruebaBandas main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
find_package(fmt 7.1 REQUIRED)
find_package(range-v3 0.11.0 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
   fmt::fmt
   range-v3
)