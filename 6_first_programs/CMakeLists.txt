set(apps
        simple_qt
        cursors
        pushbutton
        plusminus
        )

configure_file(Alex.png Alex.png COPYONLY)

foreach(a ${apps})
    app(${a})
endforeach()