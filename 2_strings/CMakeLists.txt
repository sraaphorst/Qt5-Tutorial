set(apps
        basic
        init_qstring
        access
        length
        building
        substrings
        looping
        comparing
        convert
        letters
        modify
        right_align
        html_escape)

configure_file(cprog.c cprog.c COPYONLY)

foreach(a ${apps})
    app_coreonly(${a})
endforeach()