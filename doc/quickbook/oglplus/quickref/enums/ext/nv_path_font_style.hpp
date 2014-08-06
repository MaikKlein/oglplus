//  File doc/quickbook/oglplus/quickref/enums/ext/nv_path_font_style.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/ext/nv_path_font_style.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_ext_nv_path_font_style
namespace oglplus {

enum class PathNVFontStyle : GLenum
{
	Bold   = GL_BOLD_BIT_NV,
	Italic = GL_ITALIC_BIT_NV
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<PathNVFontStyle> __EnumValueName<PathNVFontStyle>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(PathNVFontStyle);
#endif

} // namespace oglplus
//]
