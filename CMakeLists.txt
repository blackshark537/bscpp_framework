cmake_minimum_required(VERSION 3.10)

# set the project name
project(app VERSION 1.0)

# for filesystem functionality from C++17  - this is a variable
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

# condicional if
if (WIN32)
    # these are a variables
    set(WHERE-IS-SDL "c:/programs/sdl/lib/x64")
    set(WHERE-IS-SDL-HEADERS "c:/programs/sdl/include")
    set(WHERE-IS-GLAD "c:/programs/glad/src/glad.c")
    set(WHERE-IS-GLAD-HEADERS "c:/programs/glad/include")
endif()

# condicional if
if (UNIX)
    # these are a variables
    set(WHERE-IS-GLAD "./include/glad/glad.c")
    set(WHERE-IS-GLAD-HEADERS "./include")

    if (APPLE)
        # these are a variables
        set(WHERE-IS-SDL "${CMAKE_SOURCE_DIR}/lib")
        set(WHERE-IS-SDL-HEADERS "${CMAKE_SOURCE_DIR}/include/sdl")

        set(WHERE-IS-IMGUI-HEADERS "${CMAKE_SOURCE_DIR}/imgui")
    endif()

    if(NOT APPLE)
        find_package(SDL2 REQUIRED)
        include_directories(${SDL2_INCLUDE_DIRS})
    endif()
endif()

#message(${WHERE-IS-SDL})
#message(${WHERE-IS-SDL-HEADERS})
#message(${WHERE-IS-GLAD})
#message(${WHERE-IS-GLAD-HEADERS})

if (WIN32 OR APPLE)
    find_library(SDL SDL2 PATHS ${WHERE-IS-SDL})
    if (WIN32)
        find_library(SDLmain SDL2main PATHS ${WHERE-IS-SDL})
    endif()

    include_directories(
        "${WHERE-IS-SDL-HEADERS}"
    )
endif()

add_library("glad" ${WHERE-IS-GLAD})
include_directories(
        "${WHERE-IS-GLAD-HEADERS}"
    )

# your sources variable
set(sources
    include/bsc/bscpp.h
    include/bsc/main.cpp
    include/bsc/IconsFontAwesome5.h
    
    src/app.cpp
    
    imgui/imconfig.h
    imgui/imgui.cpp
    imgui/imgui.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_internal.h
    imgui/imgui_widgets.cpp
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
    imgui/imgui_impl_opengl3.cpp
    imgui/imgui_impl_opengl3.h
    imgui/imgui_impl_sdl.cpp
    imgui/imgui_impl_sdl.h

)

if (WIN32)
    # add the executable
    add_executable(${CMAKE_PROJECT_NAME} WIN32 ${sources})
    target_link_libraries(${CMAKE_PROJECT_NAME}
        "glad"
        ${SDL}
        ${SDLmain}
        ${OPENGL_gl_LIBRARY}
        )
else()
    # add the executable
    add_executable(${CMAKE_PROJECT_NAME} ${sources})
    target_link_libraries(${CMAKE_PROJECT_NAME}
            "glad"
            ${OPENGL_gl_LIBRARY}
            )
    if (APPLE)
        target_link_libraries(${CMAKE_PROJECT_NAME}
            ${SDL}
            )
    endif()
    if (UNIX AND NOT APPLE)
        target_link_libraries(${CMAKE_PROJECT_NAME}
            ${SDL2_LIBRARIES}
            ${CMAKE_DL_LIBS}
            )
    endif()
endif()

# copy icon file to the build directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/icons/*.ttf
            ${CMAKE_CURRENT_BINARY_DIR}/icons/*.ttf
            )

# copy font file to the build directory
add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/fonts/*.ttf
                ${CMAKE_CURRENT_BINARY_DIR}/fonts/*.ttf
                )
