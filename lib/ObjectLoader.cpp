#include "../headers/ObjectLoader.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

ObjectLoader::ObjectLoader() {}

bool ObjectLoader::LoadObject(const char* path, vector<vec3>& out_verts, vector<vec2>& out_uvs, vector<vec3>& out_norms) {
    vector<unsigned int> vector_indecies, uv_indices, noramal_indecies;
    vector<vec3> temp_verts;
    vector<vec2> temp_uvs;
    vector<vec3> temp_norms;

    // FILE* model = fopen(path, "r");
    // if (model == NULL) {
    //     fprintf(stderr, "shit wont open\n");
    //     return false;
    // }
    
    // while(true) {
    //     char line_header[128];
    //     int flag = fscanf(model, "%s", line_header);
    //     if (flag == EOF)
    //         break;
        
        
    //     string line_str (line_header);
    //     if( line_str.compare("v") ) {

    //     }
    // }

    ifstream model(path, ios::in);
    if (!model) {
        cout << "Won't open" << endl;
        return false;
    }

    string modelLine;
    while(getline(model, modelLine)) {
        //check if the first character is a vertex
        istringstream modelLineStream(modelLine);

        string typeStr;
        modelLineStream >> typeStr;
        if(typeStr == "v") {
            vec3 vertex;
            modelLineStream >> vertex.x >> vertex.y >> vertex.z;
            temp_verts.push_back(vertex);
        } else if(typeStr == "vn") {
            vec3 normal;
            modelLineStream >> normal.x >> normal.y >> normal.z;
            temp_norms.push_back(normal);
        } else if(typeStr == "vt") {
            vec2 uv;
            modelLineStream >> uv.x >> uv.y;
            temp_uvs.push_back(uv);
        } else if(typeStr == "f") {
            string face1;
            string face2;
            string face3;
            modelLineStream >> face1 >> face2 >> face3;

            unsigned int vertIndex[3], uvIndex[3], normalIndex[3];
            sscanf(face1.c_str(), "%d/%d/%d", &vertIndex[0], &vertIndex[1], &vertIndex[2]);
            sscanf(face2.c_str(), "%d/%d/%d", &uvIndex[0], &uvIndex[1], &uvIndex[2]);
            sscanf(face3.c_str(), "%d/%d/%d", &normalIndex[0], &normalIndex[1], &normalIndex[2]);
            for(int i = 0; i < 3; i++) {
                vector_indecies.push_back(vertIndex[i]);
                uv_indices.push_back(uvIndex[i]);
                noramal_indecies.push_back(normalIndex[i]);
            }
        }
    }


    return false;
}