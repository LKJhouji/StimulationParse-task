cmake_minimum_required(VERSION 3.0)
project(MAT_FILE_READER_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -g")
include_directories(. ../../Value)
file(GLOB_RECURSE SOURCE_FILES
    "../../Value/*.cpp"
)
list(APPEND SOURCE_FILES
    "./MATFileReader.cpp"
    "./MATFileReaderTest.cpp"
)
add_executable(MATFileReaderTest ${SOURCE_FILES})
target_link_libraries(MATFileReaderTest PUBLIC matio)