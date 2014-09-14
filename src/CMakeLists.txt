cmake_minimum_required(VERSION 2.6)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

set(sources
  demo.c
)

set(libraries
)

add_library(${PROJECT_NAME} ${sources})
target_link_libraries (${PROJECT_NAME} ${libraries})


