cmake_minimum_required(VERSION 3.24)
project(binc)

set(CMAKE_C_STANDARD 11)

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

# Include directories for the library
target_include_directories(binc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
