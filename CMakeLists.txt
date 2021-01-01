cmake_minimum_required(VERSION 3.14)

project(SIRouters LANGUAGES CXX)


set(PROJECT_NAME SIRouters)

find_package(Qt5 REQUIRED COMPONENTS
  Core
  Gui
  Qml
  Quick
  QuickControls2
  Svg
  Xml
  QuickCompiler
)


add_library(SIUtils STATIC ${SOURCES})

list(APPEND QML_IMPORT_PATH {CMAKE_CURRENT_SOURCE_DIR}/qml)

list(REMOVE_DUPLICATES QML_IMPORT_PATH)

set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
    CACHE STRING "Qt Creator 4.1 extra qml import paths"
    FORCE
)

target_compile_definitions(${PROJECT_NAME} PUBLIC)

target_link_libraries(${PROJECT_NAME} PUBLIC
  Qt::Core
  Qt::Gui
  Qt::Svg
  Qt::Xml
  Qt::Qml
  Qt::Quick
  Qt::QuickControls2
)

