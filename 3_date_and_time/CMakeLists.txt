add_executable(init_datetime init_datetime.cpp)
target_link_libraries(init_datetime LINK_PUBLIC Qt5::Core)

add_executable(leapyear leapyear.cpp)
target_link_libraries(leapyear LINK_PUBLIC Qt5::Core)

add_executable(datetimeformats datetimeformats.cpp)
target_link_libraries(datetimeformats LINK_PUBLIC Qt5::Core)

add_executable(datetime_properties datetime_properties.cpp)
target_link_libraries(datetime_properties LINK_PUBLIC Qt5::Core)

add_executable(date_validity date_validity.cpp)
target_link_libraries(date_validity LINK_PUBLIC Qt5::Core)

add_executable(daystofrom daystofrom.cpp)
target_link_libraries(daystofrom LINK_PUBLIC Qt5::Core)