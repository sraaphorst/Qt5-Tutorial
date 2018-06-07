set(apps
        click
        keypress
        move
        disconnect
        timer
        )

foreach(a ${apps})
    app(${a})
endforeach()