//  File implement/oglplus/enums/context_release_behavior_range.ipp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/context_release_behavior.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
namespace enums {
OGLPLUS_LIB_FUNC aux::CastIterRange<
	const GLenum*,
	ContextReleaseBehavior
> ValueRange_(ContextReleaseBehavior*)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVR_CONTEXTRELEASEBEHAVIOR)
#define OGLPLUS_IMPL_EVR_CONTEXTRELEASEBEHAVIOR
{
static const GLenum _values[] = {
#if defined GL_NONE
GL_NONE,
#endif
#if defined GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH
GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH,
#endif
0
};
return aux::CastIterRange<
	const GLenum*,
	ContextReleaseBehavior
>(_values, _values+sizeof(_values)/sizeof(_values[0])-1);
}
#else
;
#endif
} // namespace enums

