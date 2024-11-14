#include <GLFW/glfw3.h>
#include <cassert>

constexpr int         g_nWindowWidth  = 640;
constexpr int         g_nWindowHeight = 480;
constexpr const char *g_szWindowTitle = "OpenGL tutorial";

int main( int argc, const char *argv[] )
{
    GLFWwindow *pWindow = nullptr;
    assert( glfwInit() );

    pWindow = glfwCreateWindow( g_nWindowWidth, g_nWindowHeight, g_szWindowTitle, nullptr, nullptr );
    assert( pWindow );

    while ( !glfwWindowShouldClose( pWindow ) )
    {
        glfwPollEvents();
    }

    glfwDestroyWindow( pWindow );
    glfwTerminate();
    return 0;
}
