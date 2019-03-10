project(StereoView)

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(Qt5Widgets)  
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(OpenCV REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
qt5_wrap_ui(WRAP_FILES ${UI_FILES})

add_executable(StereoView
	main.cpp
	StereoView.cpp
	StereoView.h
	StereoView.ui
	)

target_link_libraries(StereoView Qt5::Widgets Qt5::Core Qt5::Gui)
target_link_libraries(StereoView ${OpenCV_LIBS})