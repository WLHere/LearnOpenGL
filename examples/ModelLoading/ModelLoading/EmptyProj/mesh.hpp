//
//  mesh.hpp
//  EmptyProj
//
//  Created by wenlong bai on 2021/3/3.
//

#ifndef mesh_hpp
#define mesh_hpp

#include <vector>

#include <glm/glm.hpp>
#include "shader_s_v2.h"

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh {
    public:
        vector<Vertex> vertices;
        vector<unsigned int> indices;
        vector<Texture> textures;
        
        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
        void Draw(Shader &shader);
    
    private:
        unsigned int VAO, VBO, EBO;
        
        void setupMesh();
};


#endif /* mesh_hpp */
