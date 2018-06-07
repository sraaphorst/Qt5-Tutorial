add_executable(simplemenu simplemenu.cpp)
target_link_libraries(simplemenu LINK_PUBLIC Qt5::Widgets)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/resources)
configure_file(resources/new.png  resources/new.png COPYONLY)
configure_file(resources/open.png resources/open.png COPYONLY)
configure_file(resources/quit.png resources/quit.png COPYONLY)
add_executable(anothermenu anothermenu.cpp)
target_link_libraries(anothermenu LINK_PUBLIC Qt5::Widgets)

add_executable(checkablemenu checkablemenu.cpp)
target_link_libraries(checkablemenu LINK_PUBLIC Qt5::Widgets)

add_executable(toolbar toolbar.cpp)
target_link_libraries(toolbar LINK_PUBLIC Qt5::Widgets)

add_executable(myskeleton myskeleton.cpp)
target_link_libraries(myskeleton LINK_PUBLIC Qt5::Widgets)
