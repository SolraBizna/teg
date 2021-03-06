#ifndef XGLHH
#define XGLHH

#include "teg.hh"

#ifdef WE_ARE_XGL
#define EXTERN 
#else
#define EXTERN extern
#endif

namespace xgl {
  void Initialize();
#if XGL_ENABLE_VBO
  /* ARB_vertex_buffer_object */
  EXTERN bool have_ARB_vertex_buffer_object;
  EXTERN void(*BindBuffer)(GLenum target, GLuint buffer);
  EXTERN void(*DeleteBuffers)(GLsizei n, const GLuint* buffers);
  EXTERN void(*GenBuffers)(GLsizei n, GLuint* buffers);
  EXTERN GLboolean(*IsBuffer)(GLuint buffer);
  EXTERN void(*BufferData)(GLenum target, GLsizeiptr size,
                           const void* data, GLenum usage);
  EXTERN void(*BufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size,
                              const void* data);
  EXTERN void(*GetBufferSubData)(GLenum target, GLintptr offset,
                                 GLsizeiptr size, void* data);
  EXTERN void*(*MapBuffer)(GLenum target, GLenum access);
  EXTERN GLboolean(*UnmapBuffer)(GLenum target);
  EXTERN void(*GetBufferParameteriv)(GLenum target, GLenum pname, GLint* v);
  EXTERN void(*GetBufferPointerv)(GLenum target, GLenum pname, void** v);
#endif
#if XGL_ENABLE_SYNC
  /* ARB_sync */
  EXTERN bool have_ARB_sync;
  EXTERN GLsync (*FenceSync)(GLenum condition, GLbitfield flags);
  EXTERN GLboolean (*IsSync)(GLsync sync);
  EXTERN void (*DeleteSync)(GLsync sync);
  EXTERN GLenum (*ClientWaitSync)(GLsync sync, GLbitfield flags,
                                  GLuint64 timeout);
  EXTERN void (*WaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
  EXTERN void (*GetInteger64v)(GLenum pname, GLint64 *params);
  EXTERN void (*GetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize,
                    GLsizei* length, GLint* values);
#endif
#if XGL_ENABLE_PBO
  /* ARB_pixel_buffer_object */
  EXTERN bool have_ARB_pixel_buffer_object;
#endif
#if XGL_ENABLE_RECTANGLE_TEXTURES
  /* ARB_texture_rectangle */
  EXTERN bool have_ARB_texture_rectangle;
  EXTERN bool have_quirk_ARB_texture_rectangle_no_filtering;
#endif
#if XGL_ENABLE_FLOAT_TEXTURES
  /* ARB_texture_float */
  EXTERN bool have_ARB_texture_float;
  EXTERN bool have_quirk_ARB_texture_float_half_no_filtering;
  EXTERN bool have_quirk_ARB_texture_float_single_no_filtering;
#endif
#if XGL_CHECK_RGB16_QUIRK
  EXTERN bool have_quirk_texture_rgb16_no_filtering;
#endif
#if XGL_ENABLE_SRGB
  /* EXT_texture_sRGB */
  EXTERN bool have_EXT_texture_sRGB;
  /* EXT_framebuffer_sRGB */
  EXTERN bool have_EXT_framebuffer_sRGB;
#endif
#if XGL_ENABLE_SHADERS
  /* ARB_shader_objects */
  EXTERN bool have_ARB_shader_objects;
  EXTERN void (*DeleteObject)(GLhandleARB obj);
  EXTERN GLhandleARB (*GetHandle)(GLenum pname);
  EXTERN void (*DetachObject)(GLhandleARB containerObj,
                              GLhandleARB attachedObj);
  EXTERN GLhandleARB (*CreateShaderObject)(GLenum shaderType);
  EXTERN void (*ShaderSource)(GLhandleARB shaderObj, GLsizei count,
                              const GLcharARB **string, const GLint *length);
  EXTERN void (*CompileShader)(GLhandleARB shaderObj);
  EXTERN GLhandleARB (*CreateProgramObject)(void);
  EXTERN void (*AttachObject)(GLhandleARB containerObj, GLhandleARB obj);
  EXTERN void (*LinkProgram)(GLhandleARB programObj);
  EXTERN void (*UseProgramObject)(GLhandleARB programObj);
  EXTERN void (*ValidateProgram)(GLhandleARB programObj);
  EXTERN void (*Uniform1f)(GLint location, GLfloat v0);
  EXTERN void (*Uniform2f)(GLint location, GLfloat v0, GLfloat v1);
  EXTERN void (*Uniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
  EXTERN void (*Uniform4f)(GLint location,
                           GLfloat v0, GLfloat v1,
                           GLfloat v2, GLfloat v3);
  EXTERN void (*Uniform1i)(GLint location, GLint v0);
  EXTERN void (*Uniform2i)(GLint location, GLint v0, GLint v1);
  EXTERN void (*Uniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
  EXTERN void (*Uniform4i)(GLint location,
                           GLint v0, GLint v1, GLint v2, GLint v3);
  EXTERN void (*Uniform1fv)(GLint location,
                            GLsizei count, const GLfloat *value);
  EXTERN void (*Uniform2fv)(GLint location,
                            GLsizei count, const GLfloat *value);
  EXTERN void (*Uniform3fv)(GLint location,
                            GLsizei count, const GLfloat *value);
  EXTERN void (*Uniform4fv)(GLint location,
                            GLsizei count, const GLfloat *value);
  EXTERN void (*Uniform1iv)(GLint location, GLsizei count, const GLint *value);
  EXTERN void (*Uniform2iv)(GLint location, GLsizei count, const GLint *value);
  EXTERN void (*Uniform3iv)(GLint location, GLsizei count, const GLint *value);
  EXTERN void (*Uniform4iv)(GLint location, GLsizei count, const GLint *value);
  EXTERN void (*UniformMatrix2fv)(GLint location, GLsizei count,
                                  GLboolean transpose, const GLfloat *value);
  EXTERN void (*UniformMatrix3fv)(GLint location, GLsizei count,
                                  GLboolean transpose, const GLfloat *value);
  EXTERN void (*UniformMatrix4fv)(GLint location, GLsizei count,
                                  GLboolean transpose, const GLfloat *value);
  EXTERN void (*GetObjectParameterfv)(GLhandleARB obj, GLenum pname,
                                      GLfloat *params);
  EXTERN void (*GetObjectParameteriv)(GLhandleARB obj, GLenum pname,
                                      GLint *params);
  EXTERN void (*GetInfoLog)(GLhandleARB obj, GLsizei maxLength,
                            GLsizei *length, GLcharARB *infoLog);
  EXTERN void (*GetAttachedObjects)(GLhandleARB containerObj, GLsizei maxCount,
                                    GLsizei *count, GLhandleARB *obj);
  EXTERN GLint (*GetUniformLocation)(GLhandleARB programObj,
                                     const GLcharARB *name);
  EXTERN void (*GetActiveUniform)(GLhandleARB programObj, GLuint index,
                                  GLsizei maxLength, GLsizei *length,
                                  GLint *size, GLenum *type, GLcharARB *name);
  EXTERN void (*GetUniformfv)(GLhandleARB programObj, GLint location,
                              GLfloat *params);
  EXTERN void (*GetUniformiv)(GLhandleARB programObj, GLint location,
                              GLint *params);
  EXTERN void (*GetShaderSource)(GLhandleARB obj, GLsizei maxLength,
                                 GLsizei *length, GLcharARB *source);
  /* ARB_fragment_shader */
  EXTERN bool have_ARB_fragment_shader;
  /* ARB_vertex_shader */
  EXTERN bool have_ARB_vertex_shader;
  EXTERN void (*VertexAttrib1f)(GLuint index, GLfloat v0);
  EXTERN void (*VertexAttrib1s)(GLuint index, GLshort v0);
  EXTERN void (*VertexAttrib1d)(GLuint index, GLdouble v0);
  EXTERN void (*VertexAttrib2f)(GLuint index, GLfloat v0, GLfloat v1);
  EXTERN void (*VertexAttrib2s)(GLuint index, GLshort v0, GLshort v1);
  EXTERN void (*VertexAttrib2d)(GLuint index, GLdouble v0, GLdouble v1);
  EXTERN void (*VertexAttrib3f)(GLuint index,
                                GLfloat v0, GLfloat v1, GLfloat v2);
  EXTERN void (*VertexAttrib3s)(GLuint index,
                                GLshort v0, GLshort v1, GLshort v2);
  EXTERN void (*VertexAttrib3d)(GLuint index,
                                GLdouble v0, GLdouble v1, GLdouble v2);
  EXTERN void (*VertexAttrib4f)(GLuint index,
                                GLfloat v0, GLfloat v1,
                                GLfloat v2, GLfloat v3);
  EXTERN void (*VertexAttrib4s)(GLuint index,
                                GLshort v0, GLshort v1,
                                GLshort v2, GLshort v3);
  EXTERN void (*VertexAttrib4d)(GLuint index,
                                GLdouble v0, GLdouble v1,
                                GLdouble v2, GLdouble v3);
  EXTERN void (*VertexAttrib4Nub)(GLuint index,
                                  GLubyte x, GLubyte y, GLubyte z, GLubyte w);
  EXTERN void (*VertexAttrib1fv)(GLuint index, const GLfloat *v);
  EXTERN void (*VertexAttrib1sv)(GLuint index, const GLshort *v);
  EXTERN void (*VertexAttrib1dv)(GLuint index, const GLdouble *v);
  EXTERN void (*VertexAttrib2fv)(GLuint index, const GLfloat *v);
  EXTERN void (*VertexAttrib2sv)(GLuint index, const GLshort *v);
  EXTERN void (*VertexAttrib2dv)(GLuint index, const GLdouble *v);
  EXTERN void (*VertexAttrib3fv)(GLuint index, const GLfloat *v);
  EXTERN void (*VertexAttrib3sv)(GLuint index, const GLshort *v);
  EXTERN void (*VertexAttrib3dv)(GLuint index, const GLdouble *v);
  EXTERN void (*VertexAttrib4fv)(GLuint index, const GLfloat *v);
  EXTERN void (*VertexAttrib4sv)(GLuint index, const GLshort *v);
  EXTERN void (*VertexAttrib4dv)(GLuint index, const GLdouble *v);
  EXTERN void (*VertexAttrib4iv)(GLuint index, const GLint *v);
  EXTERN void (*VertexAttrib4bv)(GLuint index, const GLbyte *v);
  EXTERN void (*VertexAttrib4ubv)(GLuint index, const GLubyte *v);
  EXTERN void (*VertexAttrib4usv)(GLuint index, const GLushort *v);
  EXTERN void (*VertexAttrib4uiv)(GLuint index, const GLuint *v);
  EXTERN void (*VertexAttrib4Nbv)(GLuint index, const GLbyte *v);
  EXTERN void (*VertexAttrib4Nsv)(GLuint index, const GLshort *v);
  EXTERN void (*VertexAttrib4Niv)(GLuint index, const GLint *v);
  EXTERN void (*VertexAttrib4Nubv)(GLuint index, const GLubyte *v);
  EXTERN void (*VertexAttrib4Nusv)(GLuint index, const GLushort *v);
  EXTERN void (*VertexAttrib4Nuiv)(GLuint index, const GLuint *v);
  EXTERN void (*VertexAttribPointer)(GLuint index, GLint size, GLenum type,
                                     GLboolean normalized, GLsizei stride,
                                     const void *pointer);
  EXTERN void (*EnableVertexAttribArray)(GLuint index);
  EXTERN void (*DisableVertexAttribArray)(GLuint index);
  EXTERN void (*BindAttribLocation)(GLhandleARB programObj,
                                    GLuint index, const GLcharARB *name);
  EXTERN void (*GetActiveAttrib)(GLhandleARB programObj, GLuint index,
                                 GLsizei maxLength, GLsizei *length,
                                 GLint *size, GLenum *type, GLcharARB *name);
  EXTERN GLint (*GetAttribLocation)(GLhandleARB programObj,
                                    const GLcharARB *name);
  EXTERN void (*GetVertexAttribdv)(GLuint index,
                                   GLenum pname, GLdouble *params);
  EXTERN void (*GetVertexAttribfv)(GLuint index,
                                   GLenum pname, GLfloat *params);
  EXTERN void (*GetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
  EXTERN void (*GetVertexAttribPointerv)(GLuint index,
                                         GLenum pname, void **pointer);
#endif
#if XGL_ENABLE_FBO
  /* ARB_draw_buffers */
  EXTERN bool have_ARB_draw_buffers;
  EXTERN void (*DrawBuffers)(GLsizei n, const GLenum* bufs);
  /* ARB_framebuffer_object (and its parents) */
  EXTERN bool have_EXT_framebuffer_object, have_EXT_framebuffer_blit,
    have_EXT_framebuffer_multisample, have_ARB_framebuffer_object;
  EXTERN GLboolean (*IsRenderbuffer)(GLuint renderbuffer);
  EXTERN void (*BindRenderbuffer)(GLenum target, GLuint renderbuffer);
  EXTERN void (*DeleteRenderbuffers)(GLsizei n, const GLuint* renderbuffers);
  EXTERN void (*GenRenderbuffers)(GLsizei n, GLuint* renderbuffers);
  EXTERN void (*RenderbufferStorage)(GLenum target, GLenum internalformat,
                                     GLsizei width, GLsizei height);
  EXTERN void (*GetRenderbufferParameteriv)(GLenum target, GLenum pname,
                                            GLint* params);
  EXTERN GLboolean (*IsFramebuffer)(GLuint framebuffer);
  EXTERN void (*BindFramebuffer)(GLenum target, GLuint framebuffer);
  EXTERN void (*DeleteFramebuffers)(GLsizei n, const GLuint* framebuffers);
  EXTERN void (*GenFramebuffers)(GLsizei n, GLuint* framebuffers);
  EXTERN GLenum (*CheckFramebufferStatus)(GLenum target);
  EXTERN void (*FramebufferTexture1D)(GLenum target, GLenum attachment,
                                      GLenum textarget, GLuint texture,
                                      GLint level);
  EXTERN void (*FramebufferTexture2D)(GLenum target, GLenum attachment,
                                      GLenum textarget, GLuint texture,
                                      GLint level);
  EXTERN void (*FramebufferTexture3D)(GLenum target, GLenum attachment,
                                      GLenum textarget, GLuint texture,
                                      GLint level, GLint layer);
  EXTERN void (*FramebufferRenderbuffer)(GLenum target, GLenum attachment,
                                         GLenum renderbuffertarget,
                                         GLuint renderbuffer);
  EXTERN void (*GetFramebufferAttachmentParameteriv)(GLenum target,
                                                     GLenum attachment,
                                                     GLenum pname,
                                                     GLint* params);
  EXTERN void (*GenerateMipmap)(GLenum target);
  /* ARB_framebuffer_object only */
  EXTERN void (*FramebufferTextureLayer)(GLenum target, GLenum attachment,
                                         GLuint texture, GLint level,
                                         GLint layer);
  /* ARB_framebuffer_object or EXT_framebuffer_multisample, check latter */
  EXTERN void (*RenderbufferStorageMultisample)(GLenum target, GLsizei samples,
                                                GLenum internalformat,
                                                GLsizei width, GLsizei height);
  /* ARB_framebuffer_object or EXT_framebuffer_blit, check latter */
  EXTERN void (*BlitFramebuffer)(GLint srcX0, GLint srcY0,
                                 GLint srcX1, GLint srcY1,
                                 GLint dstX0, GLint dstY0,
                                 GLint dstX1, GLint dstY1,
                                 GLbitfield mask, GLenum filter);
#endif
};

#define REQUIRE_EXTENSION(ext) if(!xgl::have_##ext) die("Your video hardware does not support %s, and is therefore not supported.", #ext)

#undef EXTERN

#endif
