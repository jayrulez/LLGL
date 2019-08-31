/*
 * DbgShader.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2019 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_DBG_SHADER_H
#define LLGL_DBG_SHADER_H


#include <LLGL/Shader.h>
#include <LLGL/RenderingDebugger.h>
#include <string>


namespace LLGL
{


class DbgShader final : public Shader
{

    public:

        void SetName(const char* name) override;

        bool HasErrors() const override;

        std::string Disassemble(int flags = 0) override;
        std::string GetReport() override;

    public:

        DbgShader(Shader& instance, const ShaderType type, RenderingDebugger* debugger);

        inline bool IsCompiled() const
        {
            return !instance.HasErrors();
        }

    public:

        Shader&     instance;
        std::string label;

    private:

        RenderingDebugger* debugger_ = nullptr;

};


} // /namespace LLGL


#endif



// ================================================================================
