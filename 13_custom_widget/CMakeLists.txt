add_executable(burning burning_widget.cpp burning_scale.cpp main.cpp)
target_link_libraries(burning LINK_PUBLIC Qt5::Widgets)