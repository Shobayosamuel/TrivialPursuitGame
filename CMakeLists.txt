cmake_minimum_required(VERSION 3.10)
project(TrivialPursuitGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)

include_directories(src)

# Main application
add_executable(TrivialPursuitGame
    src/main.cpp
    src/core/GameSetup.cpp
    src/core/GameFunctions.cpp
    src/core/HighScoreManager.cpp
    src/file_handling/FileReader.cpp
    src/file_handling/FileWriter.cpp
    src/file_handling/Delete.cpp
    src/gui/MainDialog.cpp
    src/gui/AdminDialog.cpp
    src/gui/GameDialog.cpp
)

target_link_libraries(TrivialPursuitGame PRIVATE Qt5::Widgets)

# Test executable
add_executable(TrivialPursuitGameTests
    test/test_main.cpp
    test/core_tests/GameFunctionsTests.cpp
    test/file_handling_tests/FileReaderTests.cpp
    test/file_handling_tests/FileWriterTests.cpp
    test/file_handling_tests/DeleteTests.cpp
    src/core/GameFunctions.cpp
    src/file_handling/FileReader.cpp
    src/file_handling/FileWriter.cpp
    src/file_handling/Delete.cpp
)

target_link_libraries(TrivialPursuitGameTests PRIVATE GTest::GTest GTest::Main)