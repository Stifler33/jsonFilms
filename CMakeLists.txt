cmake_minimum_required(VERSION 3.21)
project(32)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(json
        URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
        )

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(32 main.cpp)
target_link_libraries(32 PRIVATE nlohmann_json::nlohmann_json)