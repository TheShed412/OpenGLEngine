#ifndef MODEL_THING_SHIT
#define MODEL_THING_SHIT

#include <string>
#include <vector>

#include "Mesh.hpp"
#include "Shader.hpp"

using namespace std;

class Model 
{
    public:
        /*  Functions   */
        Model(char *path)
        {
            loadModel(path);
        }
        void Draw(Shader shader);	
    private:
        /*  Model Data  */
        vector<Mesh> meshes;
        string directory;
        /*  Functions   */
        void loadModel(string path);
        // void processNode(aiNode *node, const aiScene *scene);
        // Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        // vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, 
        //                                      string typeName);
};

#endif