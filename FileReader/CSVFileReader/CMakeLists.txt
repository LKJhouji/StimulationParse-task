cmake_minimum_required(VERSION 3.0)
project(CSV_READER_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g")
include_directories(. ../../SignalDescription ../../Value)
file(GLOB_RECURSE SOURCE_FILES
    "../../SignalDescription/*.cpp"
    "../../Value/*.cpp"
)
list(APPEND SOURCE_FILES
    "./CSVFileReader.cpp"
    "./CSVFileReaderTest.cpp"
)
add_executable(CSVFileReaderTest ${SOURCE_FILES})