cmake_minimum_required(VERSION 3.16)

project(jadwal LANGUAGES CXX)

# Set standar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable otomatis generate moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Temukan Qt5 dan komponen yang diperlukan
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Sql)

# Kumpulkan semua source file .cpp
file(GLOB_RECURSE CPP_SOURCES
    ${CMAKE_SOURCE_DIR}/application/*.cpp
    ${CMAKE_SOURCE_DIR}/algorithm/*.cpp
    ${CMAKE_SOURCE_DIR}/algorithms/backtracking/*.cpp
    ${CMAKE_SOURCE_DIR}/algorithms/constraint/*.cpp
    ${CMAKE_SOURCE_DIR}/algorithms/genetic/*.cpp
    ${CMAKE_SOURCE_DIR}/algorithms/greedy/*.cpp
    ${CMAKE_SOURCE_DIR}/data/entities/*.cpp
    ${CMAKE_SOURCE_DIR}/data/dtos/*.cpp
    ${CMAKE_SOURCE_DIR}/data/repositories/*.cpp
    ${CMAKE_SOURCE_DIR}/io/importer/*.cpp
    ${CMAKE_SOURCE_DIR}/io/exporter/*.cpp
    ${CMAKE_SOURCE_DIR}/ui/*.cpp
    ${CMAKE_SOURCE_DIR}/ui/schedule/*.cpp
    ${CMAKE_SOURCE_DIR}/ui/subject/*.cpp
    ${CMAKE_SOURCE_DIR}/ui/teacher/*.cpp
    ${CMAKE_SOURCE_DIR}/ui/timeslot/*.cpp
    ${CMAKE_SOURCE_DIR}/utils/*.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp
)

list(FILTER CPP_SOURCES EXCLUDE REGEX ".*/\\.bak/.*")

# Kumpulkan semua file UI .ui
file(GLOB_RECURSE UI_FILES
    ${CMAKE_SOURCE_DIR}/ui/*.ui
    ${CMAKE_SOURCE_DIR}/ui/schedule/*.ui
    ${CMAKE_SOURCE_DIR}/ui/subject/*.ui
    ${CMAKE_SOURCE_DIR}/ui/teacher/*.ui
    ${CMAKE_SOURCE_DIR}/ui/timeslot/*.ui
)

# Buat executable dan gabungkan .cpp dan .ui
add_executable(${PROJECT_NAME} ${CPP_SOURCES} ${UI_FILES})

# Include directories (header files)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/application
    ${CMAKE_SOURCE_DIR}/algorithm
    ${CMAKE_SOURCE_DIR}/algorithms/backtracking
    ${CMAKE_SOURCE_DIR}/algorithms/constraint
    ${CMAKE_SOURCE_DIR}/algorithms/genetic
    ${CMAKE_SOURCE_DIR}/algorithms/greedy
    ${CMAKE_SOURCE_DIR}/data/entities
    ${CMAKE_SOURCE_DIR}/data/dtos
    ${CMAKE_SOURCE_DIR}/data/repositories
    ${CMAKE_SOURCE_DIR}/io/importer
    ${CMAKE_SOURCE_DIR}/io/exporter
    ${CMAKE_SOURCE_DIR}/ui
    ${CMAKE_SOURCE_DIR}/ui/schedule
    ${CMAKE_SOURCE_DIR}/ui/subject
    ${CMAKE_SOURCE_DIR}/ui/teacher
    ${CMAKE_SOURCE_DIR}/ui/timeslot
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_BINARY_DIR}  # untuk akses generated files seperti ui_*.h
)

# Link ke library Qt5 yang diperlukan
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Sql
)

# Tentukan direktori output hasil build (executable)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)

# Copy file config.ini setelah build ke direktori executable
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/config.ini
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/config.ini
)

# Jika ingin copy folder translations, uncomment dan aktifkan ini
# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#         ${CMAKE_SOURCE_DIR}/translations
#         $<TARGET_FILE_DIR:${PROJECT_NAME}>/translations
# )
