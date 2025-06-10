cmake_minimum_required(VERSION 3.16)
project(jadwal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Aktifkan autogen Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Beri tahu AUTOUIC di mana file .ui berada
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_SOURCE_DIR}/resources/ui
)

# Cari semua source file
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/include/*.cpp
)

# Cari semua header file
file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/include/*.h
)

# File UI
file(GLOB UI_FILES
    ${CMAKE_SOURCE_DIR}/resources/ui/*.ui
)

# Temukan Qt5 dan pastikan modul yg dibutuhkan tersedia
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Sql)

# Masukkan makro tambahan Qt agar qt5_add_resources dikenali
include(${Qt5Core_DIR}/Qt5CoreMacros.cmake)

# Resource translasi (.qrc)
qt5_add_resources(TRANSLATIONS_RC translations/i18n.qrc)

# Target utama
add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${TRANSLATIONS_RC}
)

# Include direktori supaya compiler bisa temukan header (.h)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_BINARY_DIR}        # Untuk header hasil autouic (ui_*.h)
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ui
    ${CMAKE_SOURCE_DIR}/include/core
    ${CMAKE_SOURCE_DIR}/include/algorithms
    ${CMAKE_SOURCE_DIR}/include/utils
)

# Output binary di folder build
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)

# Link ke Qt5 libraries
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Sql
)

# Salin config.ini setelah build
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/config.ini
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/config.ini
)
