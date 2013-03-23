/*
 *  .file oglplus/enums/transform_feedback_target_range.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/oglplus/transform_feedback_target.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

OGLPLUS_LIB_FUNC aux::CastIterRange<
	const GLenum*,
	TransformFeedbackTarget
> EnumValueRange(TransformFeedbackTarget*)
OGLPLUS_NOEXCEPT(true)
#if (!OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)) && \
	!defined(OGLPLUS_IMPL_EVR_TRANSFORMFEEDBACKTARGET)
#define OGLPLUS_IMPL_EVR_TRANSFORMFEEDBACKTARGET
{
static const GLenum _values[] = {
#if defined GL_TRANSFORM_FEEDBACK
GL_TRANSFORM_FEEDBACK,
#endif
0
};
return aux::CastIterRange<
	const GLenum*,
	TransformFeedbackTarget
>(_values, _values+sizeof(_values)/sizeof(_values[0])-1);
}
#else
;
#endif

