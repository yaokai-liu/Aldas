cmake_minimum_required(VERSION 4.3)
project(muso VERSION 0.0.1 LANGUAGES C)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules/ProjectBasicConfig.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules/CompilerOptions.cmake)

find_package(extstd REQUIRED)
include_directories(${extstd_INCLUDE_DIRS})

file(GLOB_RECURSE ${PROJECT_NAME}_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c src/*.h)
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRC})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PRIVATE "_SHARED_LIB_" $<$<BOOL:${ENABLE_TEST_COV}>:_TEST_LOCAL_API_>)
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(muso PRIVATE extstd::extstd)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules/InstallCLibrary.cmake)
setup_c_library_install(${PROJECT_NAME} DEPENDENCIES extstd)
