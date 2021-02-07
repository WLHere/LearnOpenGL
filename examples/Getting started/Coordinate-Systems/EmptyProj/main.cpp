//
//  main.cpp
//  EmptyProj
//
//  Created by wenlong bai on 2021/2/5.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "std_image.h"

#include "glm.hpp"
#include "matrix_transform.hpp"
#include "type_ptr.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    // 指定使用opengl3.3版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // 指定使用core_profile模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    // macos必须添加
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    const char *vetexShaderSource = "#version 330 core\n"
    "layout(location = 0) in vec3 aPos;\n"
    "layout(location = 1) in vec2 aTextureCoord;\n"

    "out vec2 TextureCoord;\n"

    "uniform mat4 modelMat;\n"
    "uniform mat4 viewMat;\n"
    "uniform mat4 projectionMat;\n"

    "void main() {\n"
    "    gl_Position = projectionMat * viewMat * modelMat * vec4(aPos, 1.0);\n"
    "    TextureCoord = vec2(aTextureCoord.x, aTextureCoord.y);\n"
    "}";
    
    const char *fragmentSharderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 TextureCoord;\n"

    "uniform sampler2D texture1;\n"
    "uniform sampler2D texture2;\n"

    "void main() {\n"
    "FragColor = mix(texture(texture1, TextureCoord), texture(texture2, TextureCoord), 0.2f);\n"
    "}";
    
    unsigned int vetextShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(vetextShader, 1, &vetexShaderSource, NULL);
    glShaderSource(fragmentShader, 1, &fragmentSharderSource, NULL);
    
    glCompileShader(vetextShader);
    glCompileShader(fragmentShader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(vetextShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vetextShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VETEXT::COMPLICATION_FAILED\n" << infoLog << std::endl;
        glfwTerminate();
        return 0;
    }
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPLICATION_FAILED\n" << infoLog << std::endl;
        glfwTerminate();
        return 0;
    }
    
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vetextShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vetextShader);
    glDeleteShader(fragmentShader);
    
    
    float verticles[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    
    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// default wrap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);// default filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int width, height, nrChannels;
    std::cout << "App path " << system("pwd") << std::endl;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("/Users/wenlongbai/dev/github/LearnOpenGL/image/wooden_container.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
        glfwTerminate();
        return 0;
    }
    stbi_image_free(data);
    
    unsigned int texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);// default wrap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);// default filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    unsigned char *data1 = stbi_load("/Users/wenlongbai/dev/github/LearnOpenGL/image/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data1) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data1);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture1" << std::endl;
        glfwTerminate();
        return 0;
    }
    stbi_image_free(data1);
    
//    glm::mat4 modelMat = glm::rotate(glm::mat4(1.0f), glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projectMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    
    glEnable(GL_DEPTH_TEST);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture1);
        
        glUseProgram(shaderProgram);
        glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0);
        glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1);
        
        glBindVertexArray(vao);
        
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projectionMat"), 1, GL_FALSE, glm::value_ptr(projectMat));
        for (int i = 0; i < 10; i++) {
            glm::mat4 modelMat = glm::mat4(1.0f);
            modelMat = glm::translate(modelMat, cubePositions[i]);
            modelMat = glm::rotate(modelMat, (float) glfwGetTime() * glm::radians(50.0f) + glm::radians(20.0f * i), glm::vec3(1.0f, 0.3f, 0.5f));
            
            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &texture1);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

