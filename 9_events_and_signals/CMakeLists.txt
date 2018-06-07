add_executable(click click.cpp)
target_link_libraries(click Qt5::Widgets)

add_executable(keypress keypress.cpp)
target_link_libraries(keypress Qt5::Widgets Qt5::Core)

add_executable(move move.cpp)
target_link_libraries(move Qt5::Widgets)

add_executable(disconnect disconnect.cpp)
target_link_libraries(disconnect Qt5::Widgets)

add_executable(timer timer.cpp)
target_link_libraries(timer Qt5::Widgets)