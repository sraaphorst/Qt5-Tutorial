set(apps
        layouts
        absolute
        verticalbox
        buttons
        nesting
        form
        calculator
        review
        reviewform
        )

foreach(a ${apps})
    app(${a})
endforeach()