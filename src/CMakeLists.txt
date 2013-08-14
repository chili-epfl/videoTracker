cmake_minimum_required (VERSION 2.8)
project (videoTracker)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif (NOT CMAKE_BUILD_TYPE)

set(BASE_DIR ${PROJECT_BINARY_DIR}/..)
set(CMAKE_LIBRARY_PATH ${BASE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_BINARY_DIR ${BASE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${BASE_DIR}/bin)

set(CMAKE_DEBUG_POSTFIX "_d")

option(BUILD_SHARED_LIBS "Set to OFF to build static libraries" ON)
option(ENABLE_PROFILING "Set to ON to enable profiling" OFF)

if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__GXX_EXPERIMENTAL_CXX0X__")
  if (ENABLE_PROFILING STREQUAL ON)
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -p")
  endif()
  if (CMAKE_BUILD_TYPE STREQUAL Debug)
    message("Build type: DEBUG")
  endif()
  if (CMAKE_BUILD_TYPE STREQUAL Release)
    message("Build type: RELEASE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  endif()
endif(CMAKE_COMPILER_IS_GNUCXX)

add_definitions(-D__GXX_EXPERIMENTAL_CXX0X__)

include_directories("/usr/include" "/usr/local/include")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SOURCES 
  main.cpp
  VideoTracker.cpp
  ChiliTracker.cpp
  ChiliProcessor.cpp
  VideoReader.cpp
  Logger.cpp
)

link_directories(/usr/local/lib/)
set (EXTRA_LIBS ${EXTRA_LIBS}
  chilitags
  GL ftgl
  opencv_core opencv_highgui opencv_imgproc
  boost_filesystem boost_system boost_regex
  config++
)

# add the executable
add_executable(videoTracker 
  ${SOURCES}
)
target_link_libraries(videoTracker ${EXTRA_LIBS})

