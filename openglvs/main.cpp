#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // window and its context, window width and height
    window = glfwCreateWindow(1000, 1000, "2D Triangle", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current 
    glfwMakeContextCurrent(window);

    // Array of vertices
    float vertices[] =
    {
        0, 0.5, 0.0,     // top corner
        -0.5, -0.5, 0.0, // bottom left corner
        0.5, -0.5, 0.0   // bottom right corner
    };

    //Array of three colors
    GLfloat colour[] = {
        255, 0, 0, //red
        0, 255, 0, //green
        0, 255, 0   //green
    };
    /* Looping occurs until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0,1.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Rendering  OpenGL is done here

        glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices); // point to the vertices to be used
        glColorPointer(3, GL_FLOAT, 0, colour);// point to the c
        glDrawArrays(GL_TRIANGLES, 0, 3); // draw the vertixes
        glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
        glDisableClientState(GL_COLOR_ARRAY);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
