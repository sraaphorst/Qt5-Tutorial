add_executable(layouts layouts.cpp)
target_link_libraries(layouts Qt5::Widgets)

add_executable(absolute absolute.cpp)
target_link_libraries(absolute Qt5::Widgets)

add_executable(verticalbox verticalbox.cpp)
target_link_libraries(verticalbox Qt5::Widgets Qt5::Core)

add_executable(buttons buttons.cpp)
target_link_libraries(buttons Qt5::Widgets)

add_executable(nesting nesting.cpp)
target_link_libraries(nesting Qt5::Widgets Qt5::Core)

add_executable(form form.cpp)
target_link_libraries(form Qt5::Widgets)

add_executable(calculator calculator.cpp)
target_link_libraries(calculator Qt5::Widgets Qt5::Core)

add_executable(review review.cpp)
target_link_libraries(review Qt5::Widgets)

add_executable(reviewform reviewform.cpp)
target_link_libraries(reviewform Qt5::Widgets)