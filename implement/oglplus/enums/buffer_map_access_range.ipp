//  File implement/oglplus/enums/buffer_map_access_range.ipp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/buffer_map_access.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
namespace enums {
OGLPLUS_LIB_FUNC aux::CastIterRange<
	const GLbitfield*,
	BufferMapAccess
> ValueRange_(BufferMapAccess*)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVR_BUFFERMAPACCESS)
#define OGLPLUS_IMPL_EVR_BUFFERMAPACCESS
{
static const GLbitfield _values[] = {
#if defined GL_MAP_READ_BIT
GL_MAP_READ_BIT,
#endif
#if defined GL_MAP_WRITE_BIT
GL_MAP_WRITE_BIT,
#endif
#if defined GL_MAP_PERSISTENT_BIT
GL_MAP_PERSISTENT_BIT,
#endif
#if defined GL_MAP_COHERENT_BIT
GL_MAP_COHERENT_BIT,
#endif
#if defined GL_MAP_INVALIDATE_RANGE_BIT
GL_MAP_INVALIDATE_RANGE_BIT,
#endif
#if defined GL_MAP_INVALIDATE_BUFFER_BIT
GL_MAP_INVALIDATE_BUFFER_BIT,
#endif
#if defined GL_MAP_FLUSH_EXPLICIT_BIT
GL_MAP_FLUSH_EXPLICIT_BIT,
#endif
#if defined GL_MAP_UNSYNCHRONIZED_BIT
GL_MAP_UNSYNCHRONIZED_BIT,
#endif
0
};
return aux::CastIterRange<
	const GLbitfield*,
	BufferMapAccess
>(_values, _values+sizeof(_values)/sizeof(_values[0])-1);
}
#else
;
#endif
} // namespace enums

