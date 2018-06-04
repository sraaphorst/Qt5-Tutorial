add_executable(file_read file_read.cpp)
target_link_libraries(file_read LINK_PUBLIC Qt5::Core)

add_executable(file_write file_write.cpp)
target_link_libraries(file_write LINK_PUBLIC Qt5::Core)

add_executable(file_info file_info.cpp)
target_link_libraries(file_info LINK_PUBLIC Qt5::Core)

add_executable(dirs dirs.cpp)
target_link_libraries(dirs LINK_PUBLIC Qt5::Core)