cmake_minimum_required(VERSION 3.19)
project(play_04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH /Users/username/Qt5.12.11/5.12.11/clang_64/lib/cmake)


add_executable(play_04
        BackGround.qrc
        add_information.cpp
        add_information.h
        delete_information.cpp
        delete_information.h
        find_information.cpp
        find_information.h
        linklist.cpp
        linklist.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        rankinglist.cpp
        rankinglist.h
        register.cpp
        register.h
        student_login.cpp
        student_login.h
        studentinformation.cpp
        studentinformation.h
        studentlist.cpp
        studentlist.h
        update_information.cpp
        update_information.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

target_link_libraries(play_04 Qt5::Core)
target_link_libraries(play_04 Qt5::Widgets)