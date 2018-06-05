add_executable(SimpleMenu SimpleMenu.cpp)
target_link_libraries(SimpleMenu LINK_PUBLIC Qt5::Widgets)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/resources)
configure_file(resources/new.png  resources/new.png COPYONLY)
configure_file(resources/open.png resources/open.png COPYONLY)
configure_file(resources/quit.png resources/quit.png COPYONLY)
add_executable(AnotherMenu AnotherMenu.cpp)
target_link_libraries(AnotherMenu LINK_PUBLIC Qt5::Widgets)

add_executable(CheckableMenu CheckableMenu.cpp)
target_link_libraries(CheckableMenu LINK_PUBLIC Qt5::Widgets)

add_executable(Toolbar Toolbar.cpp)
target_link_libraries(Toolbar LINK_PUBLIC Qt5::Widgets)

add_executable(MySkeleton MySkeleton.cpp)
target_link_libraries(MySkeleton LINK_PUBLIC Qt5::Widgets)
