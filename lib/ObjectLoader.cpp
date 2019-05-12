#include "../headers/ObjectLoader.hpp"
#include "../headers/Mesh.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

bool hasUvIndexes(string face) {
    string dividerStr = "//"; 

    size_t found = face.find(dividerStr);
    if(found != string::npos) {
        return false;
    }

    return true;
}

ObjectLoader::ObjectLoader() {}

// TODO reimplement this with my meshes object
bool ObjectLoader::LoadObject(const char* path, vector<vec3>& out_verts, vector<vec2>& out_uvs, vector<vec3>& out_norms) {
    vector<int> vector_indecies, uv_indices, noramal_indecies;
    vector<vec3> temp_verts;
    vector<vec2> temp_uvs;
    vector<vec3> temp_norms;

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
            // Each one of these are going to be a vertex in a mesh
            // /int/int:
            string face1;
            string face2;
            string face3;
            modelLineStream >> face1 >> face2 >> face3;

            // I need to check for the case that the texture vertex doesn't exist. poo
            if (hasUvIndexes(face1)) {
                int vertIndex[3], uvIndex[3], normalIndex[3];
                sscanf(face1.c_str(), "%d/%d/%d", &vertIndex[0], &uvIndex[0], &normalIndex[0]);
                sscanf(face2.c_str(), "%d/%d/%d", &vertIndex[1], &uvIndex[1], &normalIndex[1]);
                sscanf(face3.c_str(), "%d/%d/%d", &vertIndex[2], &uvIndex[2], &normalIndex[2]);
                for(int i = 0; i < 3; i++) {
                    vector_indecies.push_back(vertIndex[i]);
                    noramal_indecies.push_back(normalIndex[i]);
                    uv_indices.push_back(uvIndex[i]);
                }
            } else {
                int vertIndex[3], normalIndex[3];
                sscanf(face1.c_str(), "%d//%d", &vertIndex[0], &normalIndex[0]);
                sscanf(face2.c_str(), "%d//%d", &vertIndex[1], &normalIndex[1]);
                sscanf(face3.c_str(), "%d//%d", &vertIndex[2], &normalIndex[2]);
                for(int i = 0; i < 3; i++) {
                    vector_indecies.push_back(vertIndex[i]);
                    noramal_indecies.push_back(normalIndex[i]);
                }
            }
        }
    }

    /*
        Processing step. Take the f part and use it to construct our outputs
    */

   
   for(int i = 0; i < vector_indecies.size(); i++) {
       int vector_index = vector_indecies[i];
       vec3 vector = temp_verts[vector_index-1];
       out_verts.push_back(vector);
   }

   for(int i = 0; i < uv_indices.size(); i++) {
       int uv_index = uv_indices[i];
       vec2 uv = temp_uvs[uv_index-1];
       out_uvs.push_back(uv);
   }

   for(int i = 0; i < noramal_indecies.size(); i++) {
       int norm_index = noramal_indecies[i];
       vec3 norm = temp_norms[norm_index-1];
       out_norms.push_back(norm);
   }

    return true;
}