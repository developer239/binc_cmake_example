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
add_library(binc ${SOURCE_FILES})

# For binc CMakeLists.txt
# Use INTERFACE or PUBLIC if the PUBLIC directories should be available to the targets that link against binc
target_include_directories(binc PUBLIC
        ${GLIB_INCLUDE_DIRS}
        ${GIO_INCLUDE_DIRS}
        )

# Same for compile options, use INTERFACE or PUBLIC as needed
if(GLIB_CFLAGS_OTHER)
    target_compile_options(binc PUBLIC ${GLIB_CFLAGS_OTHER})
endif()

if(GIO_CFLAGS_OTHER)
    target_compile_options(binc PUBLIC ${GIO_CFLAGS_OTHER})
endif()
