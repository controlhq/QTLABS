cmake_minimum_required(VERSION 3.19)
project(lab1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()
set(CMAKE_AUTORCC ON)

qt_add_executable(lab1
    WIN32 MACOSX_BUNDLE
    main.cpp


    flag_icons.qrc
    lab1layout.ui
    widget.cpp
    widget.h

)

target_link_libraries(lab1
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS lab1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET lab1
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
