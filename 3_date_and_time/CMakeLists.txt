set(apps
        init_datetime
        leapyear
        datetimeformats
        datetime_properties
        date_validity
        daystofrom
        )

foreach(a ${apps})
    app_coreonly(${a})
endforeach()