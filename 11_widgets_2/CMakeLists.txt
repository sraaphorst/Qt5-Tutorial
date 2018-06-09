set(apps
        checkbox
        listwidget
        progressbar
        pixmap
        splitter
        table
        )

configure_file(alex_workout.jpg alex_workout.jpg COPYONLY)

foreach(a ${apps})
    app(${a})
endforeach()