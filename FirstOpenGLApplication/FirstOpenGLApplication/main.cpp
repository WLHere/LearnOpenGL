//
//  main.cpp
//  FirstOpenGLApplication
//
//  Created by 58 on 2020/7/30.
//  Copyright © 2020 58. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    
    glViewport(0, 0, 800, 600);
    return 0;
}
