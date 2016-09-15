/*
 * GLExtension.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "GLExtensions.h"


namespace LLGL
{

    
#ifndef __APPLE__

/* --- Platform specific GL extensions --- */

#if defined(_WIN32)

// WGL_EXT_swap_control
PFNWGLSWAPINTERVALEXTPROC                               wglSwapIntervalEXT                              = nullptr;
PFNWGLCHOOSEPIXELFORMATARBPROC                          wglChoosePixelFormatARB                         = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC                       wglCreateContextAttribsARB                      = nullptr;
PFNWGLGETEXTENSIONSSTRINGARBPROC                        wglGetExtensionsStringARB                       = nullptr;

#elif defined(__linux__)

// GLX_SGI_swap_control
PFNGLXSWAPINTERVALSGIPROC                               glXSwapIntervalSGI                              = nullptr;

#endif

#if defined(GL_VERSION_3_0) && !defined(GL_GLEXT_PROTOTYPES)

/* --- GL 3.0 extensions (for Core Profile) --- */

PFNGLGETSTRINGIPROC                                     glGetStringi                                    = nullptr;

#endif

/* --- Blending (GL_ARB_draw_buffers_blend) --- */

PFNGLBLENDFUNCSEPARATEPROC                              glBlendFuncSeparate                             = nullptr;
PFNGLBLENDFUNCSEPARATEIPROC                             glBlendFuncSeparatei                            = nullptr;

/* --- Indexed (GL_EXT_draw_buffers2) --- */

PFNGLCOLORMASKIPROC                                     glColorMaski                                    = nullptr;
PFNGLGETBOOLEANI_VPROC                                  glGetBooleani_v                                 = nullptr;
PFNGLGETINTEGERI_VPROC                                  glGetIntegeri_v                                 = nullptr;
PFNGLENABLEIPROC                                        glEnablei                                       = nullptr;
PFNGLDISABLEIPROC                                       glDisablei                                      = nullptr;
PFNGLISENABLEDIPROC                                     glIsEnabledi                                    = nullptr;

/* --- Multi texture (GL_ARB_multitexture) --- */

PFNGLACTIVETEXTUREPROC                                  glActiveTexture                                 = nullptr;

/* --- 3D texture (GL_EXT_texture3D) --- */

PFNGLTEXIMAGE3DPROC                                     glTexImage3D                                    = nullptr;
PFNGLTEXSUBIMAGE3DPROC                                  glTexSubImage3D                                 = nullptr;

/* --- Clear texture (GL_ARB_clear_texture) --- */

PFNGLCLEARTEXIMAGEPROC                                  glClearTexImage                                 = nullptr;
PFNGLCLEARTEXSUBIMAGEPROC                               glClearTexSubImage                              = nullptr;

/* --- Texture compression (GL_ARB_texture_compression) --- */

PFNGLCOMPRESSEDTEXIMAGE1DPROC                           glCompressedTexImage1D                          = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC                           glCompressedTexImage2D                          = nullptr;
PFNGLCOMPRESSEDTEXIMAGE3DPROC                           glCompressedTexImage3D                          = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                        glCompressedTexSubImage1D                       = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                        glCompressedTexSubImage2D                       = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                        glCompressedTexSubImage3D                       = nullptr;
PFNGLGETCOMPRESSEDTEXIMAGEPROC                          glGetCompressedTexImage                         = nullptr;

/* --- Sampler objects (GL_ARB_sampler_objects) --- */

PFNGLGENSAMPLERSPROC                                    glGenSamplers                                   = nullptr;
PFNGLDELETESAMPLERSPROC                                 glDeleteSamplers                                = nullptr;
PFNGLBINDSAMPLERPROC                                    glBindSampler                                   = nullptr;
PFNGLSAMPLERPARAMETERIPROC                              glSamplerParameteri                             = nullptr;
PFNGLSAMPLERPARAMETERFPROC                              glSamplerParameterf                             = nullptr;
PFNGLSAMPLERPARAMETERIVPROC                             glSamplerParameteriv                            = nullptr;
PFNGLSAMPLERPARAMETERFVPROC                             glSamplerParameterfv                            = nullptr;

/* --- Multi bind (GL_ARB_multi_bind) --- */

PFNGLBINDBUFFERSBASEPROC                                glBindBuffersBase                               = nullptr;
PFNGLBINDBUFFERSRANGEPROC                               glBindBuffersRange                              = nullptr;
PFNGLBINDTEXTURESPROC                                   glBindTextures                                  = nullptr;
PFNGLBINDSAMPLERSPROC                                   glBindSamplers                                  = nullptr;
PFNGLBINDIMAGETEXTURESPROC                              glBindImageTextures                             = nullptr;
PFNGLBINDVERTEXBUFFERSPROC                              glBindVertexBuffers                             = nullptr;

/* --- Vertex buffer object (GL_ARB_vertex_buffer_object) --- */

PFNGLGENBUFFERSPROC                                     glGenBuffers                                    = nullptr;
PFNGLDELETEBUFFERSPROC                                  glDeleteBuffers                                 = nullptr;
PFNGLBINDBUFFERPROC                                     glBindBuffer                                    = nullptr;
PFNGLBUFFERDATAPROC                                     glBufferData                                    = nullptr;
PFNGLBUFFERSUBDATAPROC                                  glBufferSubData                                 = nullptr;
PFNGLMAPBUFFERPROC                                      glMapBuffer                                     = nullptr;
PFNGLUNMAPBUFFERPROC                                    glUnmapBuffer                                   = nullptr;

/* --- Vertex attributes (GL_ARB_vertex_buffer_object???) --- */

PFNGLENABLEVERTEXATTRIBARRAYPROC                        glEnableVertexAttribArray                       = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC                       glDisableVertexAttribArray                      = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC                            glVertexAttribPointer                           = nullptr;
PFNGLVERTEXATTRIBIPOINTERPROC                           glVertexAttribIPointer                          = nullptr;
PFNGLBINDATTRIBLOCATIONPROC                             glBindAttribLocation                            = nullptr;

/* --- Draw buffers (GL_ARB_draw_buffers) --- */

PFNGLDRAWBUFFERSPROC                                    glDrawBuffers                                   = nullptr;

/* --- Vertex array objects (GL_ARB_vertex_array_object) --- */

PFNGLGENVERTEXARRAYSPROC                                glGenVertexArrays                               = nullptr;
PFNGLDELETEVERTEXARRAYSPROC                             glDeleteVertexArrays                            = nullptr;
PFNGLBINDVERTEXARRAYPROC                                glBindVertexArray                               = nullptr;

/* --- Frame buffer objects (GL_ARB_framebuffer_object) --- */

PFNGLGENRENDERBUFFERSPROC                               glGenRenderbuffers                              = nullptr;
PFNGLDELETERENDERBUFFERSPROC                            glDeleteRenderbuffers                           = nullptr;
PFNGLBINDRENDERBUFFERPROC                               glBindRenderbuffer                              = nullptr;
PFNGLRENDERBUFFERSTORAGEPROC                            glRenderbufferStorage                           = nullptr;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC                 glRenderbufferStorageMultisample                = nullptr;

PFNGLGENFRAMEBUFFERSPROC                                glGenFramebuffers                               = nullptr;
PFNGLDELETEFRAMEBUFFERSPROC                             glDeleteFramebuffers                            = nullptr;
PFNGLBINDFRAMEBUFFERPROC                                glBindFramebuffer                               = nullptr;
PFNGLCHECKFRAMEBUFFERSTATUSPROC                         glCheckFramebufferStatus                        = nullptr;

PFNGLFRAMEBUFFERTEXTUREPROC                             glFramebufferTexture                            = nullptr;
PFNGLFRAMEBUFFERTEXTURE1DPROC                           glFramebufferTexture1D                          = nullptr;
PFNGLFRAMEBUFFERTEXTURE2DPROC                           glFramebufferTexture2D                          = nullptr;
PFNGLFRAMEBUFFERTEXTURE3DPROC                           glFramebufferTexture3D                          = nullptr;
PFNGLFRAMEBUFFERTEXTURELAYERPROC                        glFramebufferTextureLayer                       = nullptr;
PFNGLFRAMEBUFFERRENDERBUFFERPROC                        glFramebufferRenderbuffer                       = nullptr;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC            glGetFramebufferAttachmentParameteriv           = nullptr;
PFNGLBLITFRAMEBUFFERPROC                                glBlitFramebuffer                               = nullptr;

PFNGLGENERATEMIPMAPPROC                                 glGenerateMipmap                                = nullptr;

/* --- Instanced drawing (GL_ARB_draw_instanced) --- */

PFNGLDRAWARRAYSINSTANCEDPROC                            glDrawArraysInstanced                           = nullptr;
PFNGLDRAWELEMENTSINSTANCEDPROC                          glDrawElementsInstanced                         = nullptr;

/* --- Base vertex drawing (GL_ARB_draw_elements_base_vertex) --- */

PFNGLDRAWELEMENTSBASEVERTEXPROC                         glDrawElementsBaseVertex                        = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC                glDrawElementsInstancedBaseVertex               = nullptr;

/* --- Instanced offset drawing (GL_ARB_base_instance) --- */

PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC                glDrawArraysInstancedBaseInstance               = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC              glDrawElementsInstancedBaseInstance             = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC    glDrawElementsInstancedBaseVertexBaseInstance   = nullptr;

/* --- OpenGL shader extension (GL_ARB_shader_objects) --- */

PFNGLCREATESHADERPROC                                   glCreateShader                                  = nullptr;
PFNGLSHADERSOURCEPROC                                   glShaderSource                                  = nullptr;
PFNGLCOMPILESHADERPROC                                  glCompileShader                                 = nullptr;
PFNGLGETSHADERIVPROC                                    glGetShaderiv                                   = nullptr;
PFNGLGETSHADERINFOLOGPROC                               glGetShaderInfoLog                              = nullptr;
PFNGLDELETESHADERPROC                                   glDeleteShader                                  = nullptr;

PFNGLCREATEPROGRAMPROC                                  glCreateProgram                                 = nullptr;
PFNGLDELETEPROGRAMPROC                                  glDeleteProgram                                 = nullptr;
PFNGLATTACHSHADERPROC                                   glAttachShader                                  = nullptr;
PFNGLDETACHSHADERPROC                                   glDetachShader                                  = nullptr;
PFNGLLINKPROGRAMPROC                                    glLinkProgram                                   = nullptr;
PFNGLVALIDATEPROGRAMPROC                                glValidateProgram                               = nullptr;
PFNGLGETPROGRAMIVPROC                                   glGetProgramiv                                  = nullptr;
PFNGLGETPROGRAMINFOLOGPROC                              glGetProgramInfoLog                             = nullptr;
PFNGLUSEPROGRAMPROC                                     glUseProgram                                    = nullptr;

PFNGLGETACTIVEATTRIBPROC                                glGetActiveAttrib                               = nullptr;
PFNGLGETATTRIBLOCATIONPROC                              glGetAttribLocation                             = nullptr;

PFNGLGETACTIVEUNIFORMARBPROC                            glGetActiveUniform                              = nullptr;
PFNGLGETUNIFORMLOCATIONPROC                             glGetUniformLocation                            = nullptr;
PFNGLUNIFORM1FVPROC                                     glUniform1fv                                    = nullptr;
PFNGLUNIFORM2FVPROC                                     glUniform2fv                                    = nullptr;
PFNGLUNIFORM3FVPROC                                     glUniform3fv                                    = nullptr;
PFNGLUNIFORM4FVPROC                                     glUniform4fv                                    = nullptr;
PFNGLUNIFORM1IVPROC                                     glUniform1iv                                    = nullptr;
PFNGLUNIFORM2IVPROC                                     glUniform2iv                                    = nullptr;
PFNGLUNIFORM3IVPROC                                     glUniform3iv                                    = nullptr;
PFNGLUNIFORM4IVPROC                                     glUniform4iv                                    = nullptr;
PFNGLUNIFORMMATRIX2FVPROC                               glUniformMatrix2fv                              = nullptr;
PFNGLUNIFORMMATRIX3FVPROC                               glUniformMatrix3fv                              = nullptr;
PFNGLUNIFORMMATRIX4FVPROC                               glUniformMatrix4fv                              = nullptr;

/* --- Tessellation shader (GL_ARB_tessellation_shader) --- */

PFNGLPATCHPARAMETERIPROC                                glPatchParameteri                               = nullptr;
PFNGLPATCHPARAMETERFVPROC                               glPatchParameterfv                              = nullptr;

/* --- Compute shader (GL_ARB_compute_shader) --- */

PFNGLDISPATCHCOMPUTEPROC                                glDispatchCompute                               = nullptr;
PFNGLDISPATCHCOMPUTEINDIRECTPROC                        glDispatchComputeIndirect                       = nullptr;

/* --- Binary program (GL_ARB_get_program_binary) --- */

PFNGLGETPROGRAMBINARYPROC                               glGetProgramBinary                              = nullptr;
PFNGLPROGRAMBINARYPROC                                  glProgramBinary                                 = nullptr;
PFNGLPROGRAMPARAMETERIPROC                              glProgramParameteri                             = nullptr;

/* --- Program interface query (GL_ARB_program_interface_query) --- */

PFNGLGETPROGRAMINTERFACEIVPROC                          glGetProgramInterfaceiv                         = nullptr;
PFNGLGETPROGRAMRESOURCEINDEXPROC                        glGetProgramResourceIndex                       = nullptr;
PFNGLGETPROGRAMRESOURCENAMEPROC                         glGetProgramResourceName                        = nullptr;
PFNGLGETPROGRAMRESOURCEIVPROC                           glGetProgramResourceiv                          = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONPROC                     glGetProgramResourceLocation                    = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC                glGetProgramResourceLocationIndex               = nullptr;

/* --- Uniform buffer objects (GL_ARB_uniform_buffer_objects) --- */

PFNGLGETUNIFORMBLOCKINDEXPROC                           glGetUniformBlockIndex                          = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC                        glGetActiveUniformBlockiv                       = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                      glGetActiveUniformBlockName                     = nullptr;
PFNGLUNIFORMBLOCKBINDINGPROC                            glUniformBlockBinding                           = nullptr;
PFNGLBINDBUFFERBASEPROC                                 glBindBufferBase                                = nullptr;

/* --- Shader storage buffer objects (GL_ARB_shader_storage_buffer_object) --- */

PFNGLSHADERSTORAGEBLOCKBINDINGPROC                      glShaderStorageBlockBinding                     = nullptr;

/* --- Query objects (GL_ARB_occlusion_query) --- */

PFNGLGENQUERIESPROC                                     glGenQueries                                    = nullptr;
PFNGLDELETEQUERIESPROC                                  glDeleteQueries                                 = nullptr;
PFNGLBEGINQUERYPROC                                     glBeginQuery                                    = nullptr;
PFNGLENDQUERYPROC                                       glEndQuery                                      = nullptr;
PFNGLGETQUERYOBJECTIVPROC                               glGetQueryObjectiv                              = nullptr;
PFNGLGETQUERYOBJECTUIVPROC                              glGetQueryObjectuiv                             = nullptr;

/* --- Timer query objects (GL_ARB_timer_query) --- */

PFNGLQUERYCOUNTERPROC                                   glQueryCounter                                  = nullptr;
PFNGLGETQUERYOBJECTI64VPROC                             glGetQueryObjecti64v                            = nullptr;
PFNGLGETQUERYOBJECTUI64VPROC                            glGetQueryObjectui64v                           = nullptr;

/* --- Viewport array (GL_ARB_viewport_array) --- */

PFNGLVIEWPORTARRAYVPROC                                 glViewportArrayv                                = nullptr;
PFNGLSCISSORARRAYVPROC                                  glScissorArrayv                                 = nullptr;
PFNGLDEPTHRANGEARRAYVPROC                               glDepthRangeArrayv                              = nullptr;

/* --- ??? --- */

PFNGLSTENCILFUNCSEPARATEPROC                            glStencilFuncSeparate                           = nullptr;
PFNGLSTENCILMASKSEPARATEPROC                            glStencilMaskSeparate                           = nullptr;
PFNGLSTENCILOPSEPARATEPROC                              glStencilOpSeparate                             = nullptr;

/* --- Debug context (GL_KHR_debug) --- */

PFNGLDEBUGMESSAGECALLBACKPROC                           glDebugMessageCallback                          = nullptr;

/* --- Clipping control (GL_ARB_clip_control) --- */

PFNGLCLIPCONTROLPROC                                    glClipControl                                   = nullptr;
    
#endif // /ifndef(__APPLE__)


} // /namespace LLGL



// ================================================================================
