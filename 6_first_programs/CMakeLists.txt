configure_file(Alex.png Alex.png COPYONLY)
add_executable(simple_qt simple_qt.cpp)
target_link_libraries(simple_qt LINK_PUBLIC Qt5::Widgets)

add_executable(cursors cursors.cpp)
target_link_libraries(cursors LINK_PUBLIC Qt5::Widgets)

add_executable(pushbutton pushbutton.cpp)
target_link_libraries(pushbutton LINK_PUBLIC Qt5::Widgets)

add_executable(plus_minus PlusMinus.h PlusMinus.cpp)
target_link_libraries(plus_minus LINK_PUBLIC Qt5::Widgets)