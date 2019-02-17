#ifndef MESH_MY_DUDES
#define MESH_MY_DUDES

#include <vector>
#include <string>
#include "MatrixUtils.hpp"
#include "Shader.hpp"

using namespace std;

struct Vertex {
    vec3 Position;
    vec3 Normal;
    vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
};  

class Mesh {
    public:
        /*  Mesh Data  */
        vector<Vertex> vertices;
        vector<unsigned int> indices;
        vector<Texture> textures;
        /*  Functions  */
        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
        void Draw(Shader shader);
    private:
        /*  Functions    */
        void setupMesh();
        /*  Render data  */
        unsigned int VAO, VBO, EBO;
};  

#endif
