add_executable(version version.cpp)
target_link_libraries(version LINK_PUBLIC Qt5::Core)

add_executable(simple simple.cpp)
target_link_libraries(simple LINK_PUBLIC Qt5::Widgets)