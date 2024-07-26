cmake_minimum_required(VERSION 3.16)

project(Tesla VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Gui Qml Sql)

qt_standard_project_setup(REQUIRES 6.5)

set(PROJECT_SOURCES
    main.cpp

    resources.qrc

)

qt_add_executable(appTesla
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

qt_add_qml_module(appTesla
    URI Tesla
    VERSION 1.0
    QML_FILES
        Main.qml
        ui/BottomBar/BottomBar.qml
        ui/LeftBar/LeftBar.qml
        SOURCES TitleModel.h TitleModel.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTesla PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTesla
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTesla
    PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Sql
)

# Copy the database file to the build directory
add_custom_command(TARGET appTesla POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/resources/database/teslaDB.db
    $<TARGET_FILE_DIR:appTesla>
)

include(GNUInstallDirs)
install(TARGETS appTesla
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(appTesla)
