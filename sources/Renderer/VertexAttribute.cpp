/*
 * VertexAttribute.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2018 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include <LLGL/VertexAttribute.h>
#include "../Core/HelperMacros.h"


namespace LLGL
{


VertexAttribute::VertexAttribute(
    const std::string& name, const VectorType vectorType, std::uint32_t instanceDivisor) :
        VertexAttribute { name, 0, vectorType, instanceDivisor }
{
}

VertexAttribute::VertexAttribute(
    const std::string& semanticName, std::uint32_t semanticIndex, const VectorType vectorType, std::uint32_t instanceDivisor) :
        name            { semanticName    },
        vectorType      { vectorType      },
        instanceDivisor { instanceDivisor },
        semanticIndex   { semanticIndex   }
{
}

std::uint32_t VertexAttribute::GetSize() const
{
    return VectorTypeSize(vectorType);
}


LLGL_EXPORT bool operator == (const VertexAttribute& lhs, const VertexAttribute& rhs)
{
    return
    (
        LLGL_COMPARE_MEMBER_EQ( name            ) &&
        LLGL_COMPARE_MEMBER_EQ( vectorType      ) &&
        LLGL_COMPARE_MEMBER_EQ( instanceDivisor ) &&
        LLGL_COMPARE_MEMBER_EQ( conversion      ) &&
        LLGL_COMPARE_MEMBER_EQ( offset          ) &&
        LLGL_COMPARE_MEMBER_EQ( semanticIndex   )
    );
}

LLGL_EXPORT bool operator != (const VertexAttribute& lhs, const VertexAttribute& rhs)
{
    return !(lhs == rhs);
}


} // /namespace LLGL



// ================================================================================
