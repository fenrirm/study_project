cmake_minimum_required(VERSION 3.5)

project(studyProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        user.cpp
        user.h
        src.qrc
        secondwindow.cpp
        secondwindow.h
        secondwindow.ui
        teacherwindow.cpp
        teacherwindow.h
        teacherwindow.ui
        classroom.cpp
        classroom.h
        student.cpp
        student.h
        userfile.cpp
        userfile.h
        teacher.cpp
        teacher.h
        classroomfile.cpp
        classroomfile.h
        fileclass.h
        task.h
        task.cpp
        question.h
        question.cpp
        test.h
        test.cpp
        answer.h
        answer.cpp
        createtaskwindow.h
        createtaskwindow.cpp
        createtaskwindow.ui
        questionfactory.h
        questionfactory.cpp
        testfactory.h
        testfactory.cpp
        ansfactory.h
        ansfactory.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(studyProject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET studyProject APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(studyProject SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(studyProject
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(studyProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(studyProject PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(studyProject)
endif()
