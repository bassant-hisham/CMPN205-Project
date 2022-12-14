#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace our {

    class ShaderProgram {

    private:
        //Shader Program Handle
        GLuint program;

    public:
        void create();
        void destroy();

        ShaderProgram(){ program = 0; }
        ~ShaderProgram(){ destroy(); }

        bool attach(const std::string &filename, GLenum type) const;

        bool link() const;

        void use() { 
            //TODO: call opengl to use the program identified by this->program
            //Done:Ahmed Hussien
            glUseProgram(this->program);
        }

        GLuint getUniformLocation(const std::string &name) {
            //TODO: call opengl to get the uniform location for the uniform defined by name from this->program
            //Done: Ahmed Hussien
            return glGetUniformLocation(this->program,name.c_str());
        }

        void set(const std::string &uniform, GLfloat value) {
            //TODO: call opengl to set the value to the uniform defined by name
            //Done:Ahmed Hussien
            glUniform1f(getUniformLocation(uniform),value);
        }

        void set(const std::string &uniform, glm::vec2 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            //Done:Ahmed Hussien
            glUniform2f(getUniformLocation(uniform),value.x,value.y);
        }

        void set(const std::string &uniform, glm::vec3 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            //Done:Ahmed Hussien
            glUniform3f(getUniformLocation(uniform),value.x,value.y,value.z);
        }

        void set(const std::string &uniform, glm::vec4 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            //Done:Ahmed Hussien
            glUniform4f(getUniformLocation(uniform),value.x,value.y,value.z,value.w);
        }


        //TODO: Delete the copy constructor and assignment operator
        //Done:Ahmed Hussien
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram& operator= ( ShaderProgram& ) = delete;
        //Question: Why do we do this? Hint: Look at the deconstructor
        
    };

}

#endif