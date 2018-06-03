add_executable(basic basic.cpp)
target_link_libraries(basic LINK_PUBLIC Qt5::Core)

add_executable(init_qstring init_qstring.cpp)
target_link_libraries(init_qstring LINK_PUBLIC Qt5::Core)

add_executable(access access.cpp)
target_link_libraries(access LINK_PUBLIC Qt5::Core)

add_executable(length length.cpp)
target_link_libraries(length LINK_PUBLIC Qt5::Core)

add_executable(building building.cpp)
target_link_libraries(building LINK_PUBLIC Qt5::Core)

add_executable(substrings substrings.cpp)
target_link_libraries(substrings LINK_PUBLIC Qt5::Core)

add_executable(looping looping.cpp)
target_link_libraries(looping LINK_PUBLIC Qt5::Core)

add_executable(comparing comparing.cpp)
target_link_libraries(comparing LINK_PUBLIC Qt5::Core)

add_executable(convert convert.cpp)
target_link_libraries(convert LINK_PUBLIC Qt5::Core)

add_executable(letters letters.cpp)
target_link_libraries(letters LINK_PUBLIC Qt5::Core)

add_executable(modify modify.cpp)
target_link_libraries(modify LINK_PUBLIC Qt5::Core)

add_executable(right_align right_align.cpp)
target_link_libraries(right_align LINK_PUBLIC Qt5::Core)

configure_file(cprog.c cprog.c COPYONLY)
add_executable(html_escape html_escape.cpp)
target_link_libraries(html_escape LINK_PUBLIC Qt5::Core)