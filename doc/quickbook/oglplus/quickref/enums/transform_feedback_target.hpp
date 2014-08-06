//  File doc/quickbook/oglplus/quickref/enums/transform_feedback_target.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/transform_feedback_target.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_transform_feedback_target
namespace oglplus {

enum class TransformFeedbackTarget : GLenum
{
	TransformFeedback = GL_TRANSFORM_FEEDBACK
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<TransformFeedbackTarget> __EnumValueName<TransformFeedbackTarget>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(TransformFeedbackTarget);
#endif

} // namespace oglplus
//]
