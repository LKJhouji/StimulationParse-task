cmake_minimum_required(VERSION 3.0)
project(MF4_READER_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g -Wno-narrowing")
include_directories(. ../../SignalDescription ../../Value ../../mdf4lib_linux/Common ../../mdf4lib_linux/MDF4_SimpleReader)
file(GLOB_RECURSE SOURCE_FILES
    "../../SignalDescription/*.cpp"
    "../../Value/*.cpp"
    "../../mdf4lib_linux/Common/*.cpp"
    "../../mdf4lib_linux/MDF4_SimpleReader/*.cpp"
)
list(APPEND SOURCE_FILES
    "./MF4FileReader.cpp"
    "./MF4FileReaderTest.cpp"
)
add_executable(MF4ReaderTest ${SOURCE_FILES})