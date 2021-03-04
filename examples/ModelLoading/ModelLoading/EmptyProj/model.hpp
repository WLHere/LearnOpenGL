//
//  model.hpp
//  EmptyProj
//
//  Created by wenlong bai on 2021/3/3.
//

#ifndef model_hpp
#define model_hpp

#include <vector>
#include "shader_s_v2.h"
#include "mesh.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace std;

class Model {
    public:
        Model(char *path) {
            loadModel(path);
        }
        void Draw(Shader &shader);
    private:
        vector<Mesh> meshes;
        string directory;
        vector<Texture> textures_loaded;
        
        void loadModel(string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
        unsigned loadTextureFromFile(string path);
};

#endif /* model_hpp */
