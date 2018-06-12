set(apps
        lines
        colours
        patterns
        transparent_rectangles
        donut
        shapes
        linear_gradients
        radial_gradient
        puff
        )

foreach(a ${apps})
    app(${a})
endforeach()