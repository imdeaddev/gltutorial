set(
    GL_TUTORIALS_LIST
    01_hello_window
)

foreach(TUTORIAL ${GL_TUTORIALS_LIST})
    file(GLOB_RECURSE TUTORIAL_SRC "${CMAKE_CURRENT_SOURCE_DIR}/${TUTORIAL}/*.cpp")
    add_executable(${TUTORIAL} ${TUTORIAL_SRC})
    target_link_libraries(${TUTORIAL} PRIVATE glad glfw glm::glm)
endforeach(TUTORIAL ${GL_TUTORIALS_LIST})


