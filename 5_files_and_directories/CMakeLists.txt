set(app
        file_read
        file_write
        file_info
        dirs)

foreach(a ${apps})
    app_coreonly(${a})
endforeach()