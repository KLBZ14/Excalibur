#include "Window.h"





void Window::setupWindow(int width, int height, const char* name)
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // glfw window creation
    // ------------------
    // get monitor and resolution parameters
    window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (window == NULL)
    {
        EX_CORE_ERROR("Failed to create GLFW window");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        EX_CORE_ERROR("Failed to initialize GLAD");
    }


    //enable depth testing
    glEnable(GL_DEPTH_TEST);
}


void Window::clearColor(float r, float g, float b, float w)
{
    glClearColor(r, g, b, w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers(GLFWwindow *window)
{
    glfwSwapBuffers(window);

    glfwPollEvents();
}

GLFWwindow *Window::getWindow()
{
    return window;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
