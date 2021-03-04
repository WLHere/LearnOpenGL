//
//  main.cpp
//  EmptyProj
//
//  Created by wenlong bai on 2021/2/5.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "shader_s_v2.h"

#include "model.hpp"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 4.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// lighting
glm::vec3 lightPos(0.3f, 0.3f, 1.0f);

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
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
    
    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    // configure global opengl state
    glEnable(GL_DEPTH_TEST);
    
    // builder and compile shader program
    const char *obj_vs = "#version 330 core\n"
    "layout(location = 0) in vec3 aPos;\n"
    "layout(location = 1) in vec3 aNormal;\n"
    "layout(location = 2) in vec2 aTexCoord;\n"
    "uniform mat4 projection;\n"
    "uniform mat4 view;\n"
    "uniform mat4 model;\n"
    "out vec3 Normal;\n"
    "out vec3 FragPos;\n"
    "out vec2 TexCoord;\n"
    "void main() {\n"
    "    gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "    FragPos = vec3(model * vec4(aPos, 1.0f));\n"
    "    Normal = aNormal;\n"
    "    TexCoord = aTexCoord;\n"
    "}\n";
    const char *obj_fs = "#version 330 core\n"
    "struct Material {\n"
    "    sampler2D texture_diffuse;\n"
    "    sampler2D texture_specular;\n"
    "};\n"
    "struct Light {\n"
    "    vec3 position;\n"
    "    vec3 ambient;\n"
    "    vec3 diffuse;\n"
    "    vec3 specular;\n"
    "};\n"
    "in vec3 Normal;\n"
    "in vec3 FragPos;\n"
    "in vec2 TexCoord;\n"
    "uniform vec3 viewPos;\n"
    "uniform Material material;\n"
    "uniform Light light;\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "    vec3 texColor = vec3(texture(material.texture_diffuse, TexCoord));\n"
    "    vec3 ambient = light.ambient * texColor;\n"
    "    vec3 norm = normalize(Normal);\n"
    "    vec3 lightDir = normalize(light.position - FragPos);\n"
    "    float diff = max(dot(norm, lightDir), 0.0f);\n"
    "    vec3 diffuse = light.diffuse * diff * texColor;\n"
    "    vec3 viewDir = normalize(viewPos - FragPos);\n"
    "    vec3 reflectDir = reflect(-lightDir, norm);\n"
    "    float spec = max(dot(viewDir, reflectDir), 0);\n"
    "    vec3 specular = light.specular * (spec * vec3(texture(material.texture_specular, TexCoord)));\n"
    "    vec3 result = ambient + diffuse + specular;\n"
    "    FragColor = vec4(result, 1.0f);\n"
    "}\n";
    
    Shader objShader(obj_vs, obj_fs);
    Model model = Model("/Users/wenlongbai/dev/github/LearnOpenGL/image/model_backpack.zip");
    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        objShader.use();
        
        glm::mat4 pos_projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 pos_view = camera.GetViewMatrix();
        glm::mat4 pos_model = glm::mat4(1.0f);
        
        objShader.setMat4("projection", &pos_projection);
        objShader.setMat4("view", &pos_view);
        objShader.setMat4("model", &pos_model);
        
        objShader.setVec3("light.position", lightPos.x, lightPos.y, lightPos.z);
        objShader.setVec3("light.ambient", 0.1f, 0.1f, 0.1f);
        objShader.setVec3("light.diffuse", 1.0f, 1.0f, 1.0f);
        objShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
        
        objShader.setVec3("viewPos", &camera.Position);
        
        model.Draw(objShader);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

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

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    
    lastX = xpos;
    lastY = ypos;
    
    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset);
}
