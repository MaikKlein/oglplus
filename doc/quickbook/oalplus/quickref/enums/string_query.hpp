//  File doc/quickbook/oalplus/quickref/enums/string_query.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oalplus/string_query.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_string_query
namespace oalplus {

enum class StringQuery : ALenum
{
	Version    = AL_VERSION,
	Renderer   = AL_RENDERER,
	Vendor     = AL_VENDOR,
	Extensions = AL_EXTENSIONS
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<StringQuery> __EnumValueName<StringQuery>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(StringQuery);
#endif

} // namespace oalplus
//]
