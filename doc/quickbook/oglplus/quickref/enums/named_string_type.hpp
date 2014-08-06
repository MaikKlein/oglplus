//  File doc/quickbook/oglplus/quickref/enums/named_string_type.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/named_string_type.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_named_string_type
namespace oglplus {

enum class NamedStringType : GLenum
{
	ShaderInclude = GL_SHADER_INCLUDE_ARB
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<NamedStringType> __EnumValueName<NamedStringType>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(NamedStringType);
#endif

} // namespace oglplus
//]
