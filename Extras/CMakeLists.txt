# Extras: me playing around with Qt5 as I go.
set(apps
        logging
        string_funcs
        Styles
        )

foreach(a ${apps})
    app(${a})
endforeach()