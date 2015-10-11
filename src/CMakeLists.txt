cmake_minimum_required (VERSION 2.6)
project(orx_template)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()

set ( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package ( ORX COMPONENTS Scroll REQUIRED)

IF(CMAKE_COMPILER_IS_GNUCXX)
  SET (CMAKE_CXX_COMPILER_ARG1 -std=c++11)
ELSE()
  SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE .)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG .)
  file(COPY ${ORX_DLLS} DESTINATION .)
ENDIF (CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_CXX_FLAGS_RELEASE -DNDEBUG)
set(CMAKE_CXX_FLAGS_DEBUG -D__orxDEBUG__)

include_directories(.
    ${ORX_SCROLL_INCLUDE_DIR} 
    ${ORX_INCLUDE_DIR} 
)

file (GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

configure_file(execute_in_sibling_folder.ini ${CMAKE_PROJECT_NAME}.ini COPYONLY)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

target_link_libraries (${CMAKE_PROJECT_NAME} ${ORX_LIBRARY})
