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

    pWindow = glfwCreateWindow( g_nWindowWidth, g_nWindowHeight, g_szWindowTitle, nullptr, nullptr );
    if ( !pWindow )
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    while ( !glfwWindowShouldClose( pWindow ) )
    {
        glfwPollEvents();
    }

    glfwDestroyWindow( pWindow );
    glfwTerminate();
    return 0;
}
