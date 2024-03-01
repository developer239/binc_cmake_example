cmake_minimum_required(VERSION 3.10) # Ensure compatibility with the features used
project(binc)

# Find pkg-config first
find_package(PkgConfig REQUIRED)

# Use pkg-config to find glib-2.0 and gio-2.0 and import them as targets
pkg_check_modules(GLIB REQUIRED IMPORTED_TARGET glib-2.0)
pkg_check_modules(GIO REQUIRED IMPORTED_TARGET gio-2.0)

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

# Use INTERFACE or PUBLIC to make the include directories and compile options
# available to targets that link against `binc`
target_include_directories(binc PUBLIC
        ${GLIB_INCLUDE_DIRS}
        ${GIO_INCLUDE_DIRS}
        # If binc has its own headers, you should also include its directory here
        )

# Link `binc` with GLib and GIO using imported targets. Use PUBLIC to ensure that
# anything linking to `binc` also links to these libraries.
target_link_libraries(binc PUBLIC
        PkgConfig::GLIB
        PkgConfig::GIO
        )

# Optionally, apply compile options from GLib and GIO. This might be necessary if
# there are specific flags required for compilation, but often it can be omitted
# if flags are standard or handled by the pkg-config imported targets.
if(GLIB_CFLAGS_OTHER)
    target_compile_options(binc PUBLIC ${GLIB_CFLAGS_OTHER})
endif()

if(GIO_CFLAGS_OTHER)
    target_compile_options(binc PUBLIC ${GIO_CFLAGS_OTHER})
endif()
