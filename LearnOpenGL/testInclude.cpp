#include "common.h"

//void processInput(GLFWwindow *window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main0() 
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "This is the first OpenGL Window since xd was borned.", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed create OpenGL window!" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // �����˺���ָ�루������ǿ������ת����
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Initial GLAD Failed!" << std::endl;
    return -1;
  }


  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }


  glfwTerminate();
  return 0;
}