cmake_minimum_required ( VERSION 3.22 FATAL_ERROR )

#General settings

set ( PROJECT_NAME "AM" )
set ( PROJECT_VERSION 0.0.1 )
set ( PROJECT_DESCRIPTION "ZemGa admin panel.")

set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON)
set ( CMAKE_POSITION_INDEPENDENT_CODE ON )
set ( CMAKE_INCLUDE_CURRENT_DIR ON)

#Project

project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES CXX )

#QT

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

#Build settings

if ( WIN32 ) 
    set ( PLATFORM_DIR "win32" )
    add_definitions( -DWINDOWS=1 )
    set(CMAKE_WIN32_EXECUTABLE ON)
elseif ( WIN64 )
    set ( PLATFORM_DIR "win64" )
    add_definitions( -DWINDOWS=1 )
    set(CMAKE_WIN32_EXECUTABLE ON)
endif ( WIN32 )

set ( BUILD_TYPE_DIR "release" )
set ( BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${PLATFORM_DIR}/${BUILD_TYPE_DIR}" )

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

#Source settings

set ( AM_COMMON_FOLDER "src/common" )
set ( AM_EXE_FOLDER "src/exe" )

#Conan settings

set ( CONAN_FOLDER "${CMAKE_SOURCE_DIR}/conan" )

#Finding sources

file ( GLOB_RECURSE AM_PUBLIC_HEADERS
    "${AM_COMMON_FOLDER}/public/*.hxx"
    "${AM_COMMON_FOLDER}/public/*.h"
    "${AM_COMMON_FOLDER}/public/*.hpp")

file( GLOB_RECURSE AM_HEADERS
    "${AM_COMMON_FOLDER}/*.hxx"
    "${AM_COMMON_FOLDER}/*.h"
    "${AM_COMMON_FOLDER}/*.hpp")

file( GLOB_RECURSE AM_SOURCES
    "${AM_COMMON_FOLDER}/*.cxx"
    "${AM_COMMON_FOLDER}/*.cpp")

file ( GLOB_RECURSE TEST_AM_HEADERS
    "${AM_EXE_FOLDER}/*.hxx"
    "${AM_EXE_FOLDER}/*.h" )

file ( GLOB_RECURSE TEST_AM_SOURCES
    "${AM_EXE_FOLDER}/*.cxx" 
    "${AM_EXE_FOLDER}/*.cpp")


#Conan

include(${CONAN_FOLDER}/temp/conanbuildinfo.cmake)
conan_basic_setup()

#Library

add_library ( AM_COMMON SHARED ${AM_SOURCES} )

set_target_properties ( AM_COMMON PROPERTIES
    PUBLIC_HEADER AM_PUBLIC_HEADERS
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
    VERSION ${PROJECT_VERSION} )
    
target_link_libraries ( AM_COMMON PRIVATE Qt6::Widgets)
target_link_libraries ( AM_COMMON ${CONAN_LIBS} )

#Testing exe

add_executable ( AM_EXE ${TEST_AM_HEADERS} ${TEST_AM_SOURCES} )

set_target_properties ( AM_EXE PROPERTIES
	OUTPUT_NAME "Test"
	RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}" )

target_include_directories( AM_EXE PRIVATE "${AM_COMMON_FOLDER}/public" )

set_target_properties(AM_EXE PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

target_link_libraries ( AM_EXE PRIVATE AM_COMMON ${CONAN_LIBS} Qt6::Widgets )