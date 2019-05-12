#ifndef OBJ_LOAD
#define OBJ_LOAD

#include <vector>

#include "MatrixUtils.hpp"
#include "Mesh.hpp"

using namespace std;

class ObjectLoader {

    public:
        ObjectLoader();
        Mesh *LoadObject(const char* path, 
            vector<vec3>& out_verts, 
            vector<vec2>& out_uvs, 
            vector<vec3>& out_norms);
    
};

#endif