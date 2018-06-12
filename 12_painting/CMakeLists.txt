set(apps
        lines
        colours
        patterns
        )

foreach(a ${apps})
    app(${a})
endforeach()