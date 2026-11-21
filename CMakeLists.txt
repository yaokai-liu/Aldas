cmake_minimum_required(VERSION 4.3)
project(meman C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_compile_options("-flto")
add_compile_options("-O3" "-Os")
add_compile_options("-Wall" "-Wextra" "-Werror")

add_subdirectory(extstd)

file(GLOB_RECURSE MEMAN_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c src/*.h)
add_library(meman STATIC ${MEMAN_SRC})
target_include_directories(meman PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/extstd/include)
target_link_libraries(meman PUBLIC extstd)
target_compile_definitions(meman PRIVATE "_BUILDING_SHARED_")

