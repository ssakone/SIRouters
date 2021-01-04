cmake_minimum_required(VERSION 3.14)

project(SIRouters LANGUAGES CXX)

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

set(HEADERS
    include/routers/routers.h
)

set(SOURCES
  src/routers.cpp
  qml/SIRouters.qrc
)


list(APPEND QML_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/qml/SIRouters/)

list(REMOVE_DUPLICATES QML_IMPORT_PATH)

set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
    CACHE STRING "Qt Creator 4.1 extra qml import paths"
    FORCE
)

list(APPEND QML2_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/qml/SIRouters/)

list(REMOVE_DUPLICATES QML2_IMPORT_PATH)

set(QML_IMPORT_PATH ${QML2_IMPORT_PATH}
    CACHE STRING "Qt Creator 4.1 extra qml import paths"
    FORCE
)


qtquick_compiler_add_resources(ROUTERS_QML_RES qml/SIRouters.qrc)

add_library(SIRouters STATIC ${HEADERS} ${SOURCES} ${ROUTERS_QML_RES})


target_compile_definitions(SIRouters PUBLIC)
target_include_directories(SIRouters PUBLIC include)

target_link_libraries(SIRouters PUBLIC
  Qt::Core
  Qt::Gui
  Qt::Svg
  Qt::Xml
  Qt::Qml
  Qt::Quick
  Qt::QuickControls2
)

