#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenAl/al.h>
#include <OpenCL/cl.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description){
    fprintf(stderr, "GLFW Error (%d): %s\n", error, description);
}
int main(){

    glfwSetErrorCallback(error_callback);
    
    if(!glfwInit()){
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window_frame = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if(!window_frame){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window_frame);
    glfwSwapInterval(1);

    while(!glfwWindowShouldClose(window_frame)){
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window_frame);
        glfwPollEvents();
    }

    glfwDestroyWindow(window_frame);
    glfwTerminate();

    return 0;
}