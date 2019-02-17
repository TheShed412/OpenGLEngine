#include "../headers/Shader.hpp"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch(std::ifstream::failure e) {
        std::cout << "SHIT BROKE" << std::endl;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertexFilePtr, fragmentFilePtr;
    int success;

    vertexFilePtr = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexFilePtr, 1, &vShaderCode, NULL);
    glCompileShader(vertexFilePtr);
    glGetShaderiv(vertexFilePtr, GL_COMPILE_STATUS, &success);
    if(!success) {
        std::cout << "VERTEX SHADER BROKE" << std::endl;
    }

    fragmentFilePtr = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentFilePtr, 1, &fShaderCode, NULL);
    glCompileShader(fragmentFilePtr);
    glGetShaderiv(fragmentFilePtr, GL_COMPILE_STATUS, &success);
    if(!success) {
        std::cout << "FRAGMENT SHADER BROKE" << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, fragmentFilePtr);
    glAttachShader(ID, vertexFilePtr);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success) {
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << std::endl;
    }

    glDeleteShader(vertexFilePtr);
    glDeleteShader(fragmentFilePtr);
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
} 