# Find pkg-config first
find_package(PkgConfig REQUIRED)

# Use pkg-config to find glib-2.0 and gio-2.0
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GIO REQUIRED gio-2.0)

# List all source files here
set(SOURCE_FILES
        adapter.c
        advertisement.c
        agent.c
        application.c
        characteristic.c
        descriptor.c
        device.c
        logger.c
        parser.c
        service.c
        utility.c
        )

# Create a static library `binc`
add_library(binc STATIC ${SOURCE_FILES})

# Include directories for binc and for GLib/GIO
target_include_directories(binc PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${GLIB_INCLUDE_DIRS}
        ${GIO_INCLUDE_DIRS}
        )

# Link binc with GLib and GIO
target_link_libraries(binc
        ${GLIB_LIBRARIES}
        ${GIO_LIBRARIES}
        )

# Since pkg_check_modules defines variables with -I and -L flags,
# ensure the compiler knows where to find the GLib/GIO headers and libraries
link_directories(
        ${GLIB_LIBRARY_DIRS}
        ${GIO_LIBRARY_DIRS}
)

# Add GLib and GIO compile flags to the binc target
# This can include preprocessor definitions, optimizations, etc.
if(GLIB_CFLAGS_OTHER)
    set_target_properties(binc PROPERTIES COMPILE_OPTIONS "${GLIB_CFLAGS_OTHER}")
endif()

if(GIO_CFLAGS_OTHER)
    target_compile_options(binc PRIVATE ${GIO_CFLAGS_OTHER})
endif()
