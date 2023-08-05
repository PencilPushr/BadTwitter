# CMakeList.txt : CMake project for BadTwitter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("BadTwitter")

#compile 3rdParty               _______________________

#set variables
set(GLFW_INCLUDES  3rdParty/glfw/glfw/include)
set(GLAD_INCLUDES  3rdParty/glad/include)
set(IMGUI_INCLUDES 3rdParty/imgui/ 3rdParty/imgui/backends)

#glfw
#disable unit tests
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#addsub dir

add_subdirectory("3rdParty/glfw/glfw")

#linker glfw
#target_link_libraries(BadTwitter glfw)
#find opengl
find_package(OpenGL REQUIRED)
#linker opengl
#target_link_libraries(Badtwitter OpenGL::GL glfw)

#glad
set(GLAD_DIR "3rdParty/glad")
file(GLOB glad_files 
        ${GlAD_DIR}/include/glad/glad.h
        ${GlAD_DIR}/include/KHR/khrplatform.h
        ${GlAD_DIR}/src/glad.c
)

#linker shit that I dont understand but rahul told me about
include_directories(${GLFW_INCLUDES})
include_directories(${GLAD_INCLUDES})
include_directories(${IMGUI_INCLUDES})

#note: we only need to include the imgui cmakelist unlike the glfw
add_subdirectory(${IMGUI_INCLUDES})

#end compile 3rdParty           _______________________

#compile my files
file(GLOB source_files CONFIGURE_DEPENDS
        "*.h"
        "*.cpp"
        "src/*.cpp"
        "src/*.h"
        "src/Interface/*.h"
        "src/Interface/*.cpp"
        "util/*.cpp"
        "util/*.h"
        )

set(DUMB_DIR src/mainfiles)

file (GLOB_RECURSE retarded_dir_files CMAKE_CONFIGURE_DEPENDS
        ${DUMB_DIR}/*.h
        ${DUMB_DIR}/*.cpp
)


# Add source to this project's executable.
# add_executable ( BadTwitter "BadTwitter.cpp" "BadTwitter.h" "src/Manager.cpp" "src/Manager.h" )
add_executable (BadTwitter ${source_files})

target_link_libraries(BadTwitter ${OPENGL_LIBRARIES} OpenGL::GL glfw imgui)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET BadTwitter PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.