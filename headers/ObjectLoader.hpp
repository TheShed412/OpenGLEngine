#ifndef OBJ_LOAD
#define OBJ_LOAD

#include <vector>

#include "MatrixUtils.hpp"

using namespace std;

class ObjectLoader {

    public:
        ObjectLoader();
        ~ObjectLoader();
        bool LoadObject(const char* path, 
            vector<vec3>& out_verts, 
            vector<vec2>& out_uvs, 
            vector<vec3>& out_norms);
    
};

#endif