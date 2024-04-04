cmake_minimum_required(VERSION 3.0)
project(PARSE_XML_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g")
include_directories(. ../SignalDescription ../TinyXml ../ParseXml ../Value)
file(GLOB_RECURSE SOURCE_FILES
    "../SignalDescription/*.cpp"
    "../TinyXml/*.cpp"
    "../Value/*.cpp"
)
list(APPEND SOURCE_FILES
    "./ParseXml.cpp"
    "./ParseXmlTest.cpp"
)
add_executable(ParseXmlTest ${SOURCE_FILES})