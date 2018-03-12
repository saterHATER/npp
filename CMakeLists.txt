cmake_minimum_required(VERSION 3.8)
project(npp)
set(CMAKE_CXX_STANDARD 11)

find_package(Curses REQUIRED)


file(GLOB NPP_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/srcs/*)
file(GLOB NPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes/*)

add_library(npp STATIC ${NPP_SOURCE_FILES})
target_link_libraries(npp ${NPPSOURCE_FILES} ${CURSES_LIBRARIES})
target_include_directories(npp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes ${CURSES_INCLUDE_DIR})