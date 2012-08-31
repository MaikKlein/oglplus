/**
 *  @file oglplus/stencil_op.hpp
 *  @brief OpenGL stencil operation enumeration
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2011 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef OGLPLUS_STENCIL_FUNC_1107121519_HPP
#define OGLPLUS_STENCIL_FUNC_1107121519_HPP

namespace oglplus {

/// Stencil operation type enumeration
/**
 *  @ingroup enumerations
 *
 *  @glsymbols
 *  @glfunref{StencilOp}
 */
OGLPLUS_ENUM_CLASS_BEGIN(StencilOperation, GLenum)
#include <oglplus/enums/stencil_operation.ipp>
OGLPLUS_ENUM_CLASS_END

OGLPLUS_LIB_FUNC StrLit EnumValueName(
	StencilOperation*,
	EnumBaseType<StencilOperation>::Type value
) OGLPLUS_NOEXCEPT(true)
#if OGLPLUS_LINK_LIBRARY
;
#else
{
#if !OGLPLUS_NO_ENUM_VALUE_NAMES
#include <oglplus/names/stencil_operation.ipp>
#endif
	OGLPLUS_FAKE_USE(value);
	return StrLit();
}
#endif

/// Alternate name for the StencilOperation enumeration
typedef StencilOperation StencilOp;

} // namespace oglplus

#endif // include guard
