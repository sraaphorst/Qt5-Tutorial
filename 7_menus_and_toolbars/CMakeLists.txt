set(apps
        simplemenu
        anothermenu
        checkablemenu
        toolbar
        myskeleton)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/resources)
configure_file(resources/new.png  resources/new.png COPYONLY)
configure_file(resources/open.png resources/open.png COPYONLY)
configure_file(resources/quit.png resources/quit.png COPYONLY)

foreach(a ${apps})
    app(${a})
endforeach()