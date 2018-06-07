set(apps
        version
        simple)

foreach(a ${apps})
    app_coreonly(${a})
endforeach()