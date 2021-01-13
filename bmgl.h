#ifndef _BMGL_H_
#define _BMGL_H_

/*===============================================*/
/*            _                     _            */
/*           | |__  _ __ ___   __ _| |           */
/*           | '_ \| '_ ` _ \ / _` | |           */
/*           | |_) | | | | | | (_| | |           */
/*           |_.__/|_| |_| |_|\__, |_|           */
/*                            |___/              */
/*                                               */
/*=============  Made by Amaziner01 =============*/
/*====================  2021 ====================*/

// This header file is free. You can do whatever you
// want with it. 
#include <stddef.h>
#include <GL/gl.h>

#ifdef _WIN64 || _WIN32
    #include <windows.h>
#endif


/* Types */
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
typedef char GLchar;

/* Constants */
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893

#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA

#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD

#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA

#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31

#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83

#define GL_CLAMP_TO_EDGE                  0x812F

#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF

#define GL_CLAMP_TO_BORDER                0x812D

#define GL_BGR                            0x80E0

/* Function loader macro */
#define GLF(type, name, ...) type _stdcall (*gl##name)(__VA_ARGS__);

/* Load All functions */

#define GL_FUNCS \
    GLF(void, GenBuffers, GLsizei n, GLuint *buffers);\
    GLF(void, BindBuffer, GLenum target, GLuint buffer);\
    GLF(void, BufferData, GLenum target, GLsizeiptr size, const void *data, GLenum usage);\
    GLF(void, VertexAttribPointer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);\
    GLF(void, EnableVertexAttribArray, GLuint index);\
    GLF(GLuint, CreateShader, GLenum shaderType);\
    GLF(void, ShaderSource, GLuint shader, GLsizei count, const GLchar **string, const GLint *length);\
    GLF(void, CompileShader, GLuint shader);\
    GLF(void, AttachShader, GLuint program, GLuint shader);\
    GLF(void, GetShaderiv, GLuint shader, GLenum pname, GLint *params);\
    GLF(void, GetShaderInfoLog, GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog);\
    GLF(GLuint, CreateProgram, void);\
    GLF(void, LinkProgram, GLuint program);\
    GLF(void, UseProgram, GLuint program);\
    GLF(GLint, GetUniformLocation, GLuint program, const GLchar *name);\
    GLF(void, Uniform1i, GLint location, GLint i);\
    GLF(void, Uniform2f, GLint location, GLfloat v0, GLfloat v1);\
    GLF(void, Uniform2fv, GLint location, GLsizei count, const GLfloat *value);\
    GLF(void, UniformMatrix2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);\
    GLF(void, ActiveTexture, GLenum texture);

/* Define each funtions */
GL_FUNCS

/* Re-define function macro */
#undef GLF
#define GLF(type, name, ...) gl##name = (void*)wglGetProcAddress("gl"#name); if (!gl##name) return false;

/* Initialize modern opengl functions */
bool bmgl_init(void){
    GL_FUNCS
    return true;
};

#endif