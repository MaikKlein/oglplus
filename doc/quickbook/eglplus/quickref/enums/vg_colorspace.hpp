//  File doc/quickbook/eglplus/quickref/enums/vg_colorspace.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/eglplus/vg_colorspace.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_vg_colorspace
namespace eglplus {

enum class VGColorspace : EGLenum
{
	sRGB   = EGL_VG_COLORSPACE_sRGB,
	Linear = EGL_VG_COLORSPACE_LINEAR
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<VGColorspace> __EnumValueName<VGColorspace>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(VGColorspace);
#endif

} // namespace eglplus
//]
