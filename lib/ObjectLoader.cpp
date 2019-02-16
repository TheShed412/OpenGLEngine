#include "../headers/ObjectLoader.hpp"
#include <string>


ObjectLoader::ObjectLoader() {}

bool ObjectLoader::LoadObject(const char* path, vector<vec3>& out_verts, vector<vec2>& out_uvs, vector<vec3>& out_norms) {
    vector<unsigned int> vector_indecies, uv_indices, noramal_indecies;
    vector<vec3> temp_verts;
    vector<vec2> temp_uvs;
    vector<vec3> temp_norms;

    FILE* model = fopen(path, "r");
    if (model == NULL) {
        fprintf(stderr, "shit wont open\n");
        return false;
    }
    
    while(true) {
        char line_header[128];
        int flag = fscanf(model, "%s", line_header);
        if (flag == EOF)
            break;
        
        
        string line_str (line_header);
        if( line_str.compare("v") ) {

        }
    }

    return false;
}