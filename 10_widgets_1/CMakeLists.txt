set(apps
        label
        slider
        combobox
        combobox2
        spinbox
        lineedit
        statusbar
        )

foreach(a ${apps})
    app(${a})
endforeach()