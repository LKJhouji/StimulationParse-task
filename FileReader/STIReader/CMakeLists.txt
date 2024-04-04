cmake_minimum_required(VERSION 3.0)
project(STI_READER_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g")
include_directories(. ../../SignalDescription ../../TinyXml ../../ParseXml ../../Value)
file(GLOB_RECURSE SOURCE_FILES
    "../../SignalDescription/*.cpp"
    "../../TinyXml/*.cpp"
    "../../Value/*.cpp"
    "../../ParseXml.cpp"
)
list(APPEND SOURCE_FILES
    "./STIReader.cpp"
    "./STIReaderTest.cpp"
)
add_executable(STIReaderTest ${SOURCE_FILES})