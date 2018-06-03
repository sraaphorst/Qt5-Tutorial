# Extras: me playing around with Qt5 as I go.

add_executable(logging logging.cpp)
target_link_libraries(logging LINK_PUBLIC Qt5::Core)

add_executable(string_funcs string_funcs.cpp)
target_link_libraries(string_funcs LINK_PUBLIC Qt5::Core)