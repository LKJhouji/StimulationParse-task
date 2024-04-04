cmake_minimum_required(VERSION 3.0)
project(SIGNAL_GENERATOR_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g")
include_directories(. ../SignalDescription ../TinyXml ../ParseXml ../Value)
file(GLOB_RECURSE SOURCE_FILES
    "../SignalDescription/*.cpp"
    "../TinyXml/*.cpp"
    "../Value/*.cpp"
)
list(APPEND SOURCE_FILES
    "../ParseXml/ParseXml.cpp"
    "./SignalGenerator.cpp"
    "./SignalGeneratorTest.cpp"
)
add_executable(SignalGeneratorTest ${SOURCE_FILES})