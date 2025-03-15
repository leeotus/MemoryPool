cmake_minimum_required(VERSION 3.12...3.30)

set(MEMORYPOOL_NAME "mempool")
project(
  "${MEMORYPOOL_NAME}"
  VERSION 1.0.0
  LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(TAGRET_LIB_NAME "memp")

include_directories(include)
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

add_library("${TAGRET_LIB_NAME}" ${SRC_FILES})
target_include_directories("${TAGRET_LIB_NAME}" PUBLIC include)

# example:
add_executable(main "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
target_link_libraries(main PRIVATE "${CMAKE_BINARY_DIR}/libmemp.a")
