#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

constexpr int         g_nWindowWidth  = 640;
constexpr int         g_nWindowHeight = 480;
constexpr const char *g_szWindowTitle = "OpenGL tutorial";

int main( int argc, const char *argv[] )
{
    GLFWwindow *pWindow = nullptr;
    if ( !glfwInit() )
    {
        std::cerr << "Failed to init GLFW" << std::endl;
        return -1;
    }

    // Use OpenGL 4.5 core profile
    glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_API );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 5 );

    pWindow = glfwCreateWindow( g_nWindowWidth, g_nWindowHeight, g_szWindowTitle, nullptr, nullptr );
    if ( !pWindow )
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( pWindow );

    int nLoadedOpenGLVersion = gladLoadGL( glfwGetProcAddress );
    if ( ( GLAD_VERSION_MAJOR( nLoadedOpenGLVersion ) < 4 ) || GLAD_VERSION_MINOR( nLoadedOpenGLVersion ) < 5 )
    {
        std::cerr << "Failed to load OpenGL 4.5 functions" << std::endl;
        glfwDestroyWindow( pWindow );
        glfwTerminate();
        return -1;
    }

    glClearColor( 0.1, 0.2, 0.7, 1.0 );

    while ( !glfwWindowShouldClose( pWindow ) )
    {
        glfwPollEvents();
        glClear( GL_COLOR_BUFFER_BIT );
        glfwSwapBuffers( pWindow );
    }

    glfwDestroyWindow( pWindow );
    glfwTerminate();
    return 0;
}
