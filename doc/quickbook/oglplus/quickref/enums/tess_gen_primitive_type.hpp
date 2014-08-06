//  File doc/quickbook/oglplus/quickref/enums/tess_gen_primitive_type.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/tess_gen_primitive_type.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_tess_gen_primitive_type
namespace oglplus {

enum class TessGenPrimitiveType : GLenum
{
	Quads     = GL_QUADS,
	Triangles = GL_TRIANGLES,
	Isolines  = GL_ISOLINES
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<TessGenPrimitiveType> __EnumValueName<TessGenPrimitiveType>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(TessGenPrimitiveType);
#endif

} // namespace oglplus
//]
