include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${OpenCL_INCLUDE_DIRS})
include_directories(${EASYLOGGINGPP_INCLUDE_DIR})
include_directories(SYSTEM ${CLPP_INCLUDE_DIR})
include_directories(${CPPFORMAT_INCLUDE_DIR})
include_directories(${NOD_INCLUDE_DIR})
include_directories(${RAPIDJSON_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${SOIL_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)

add_subdirectory(event)
add_subdirectory(game)
add_subdirectory(process)
add_subdirectory(system)
add_subdirectory(util)

link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
add_definitions(-DELPP_DISABLE_LOGS)

add_executable(blue ${SOURCE_FILES})
target_link_libraries(blue ${OPENGL_LIBRARIES} libglew_shared ${GLFW_STATIC_LIBRARIES} clpp cppformat SOIL)

add_subdirectory(kernels)
add_subdirectory(shaders)

if(WIN32)
endif()


