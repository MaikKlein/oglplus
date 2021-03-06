//  File doc/quickbook/oglplus/quickref/enums/framebuffer_status.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/framebuffer_status.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_framebuffer_status
namespace oglplus {

enum class FramebufferStatus : GLenum
{
	Complete                    = GL_FRAMEBUFFER_COMPLETE,
	Undefined                   = GL_FRAMEBUFFER_UNDEFINED,
	IncompleteAttachment        = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
	IncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
	Unsupported                 = GL_FRAMEBUFFER_UNSUPPORTED,
	IncompleteMultisample       = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
	IncompleteLayerTargets      = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
};

template <>
__Range<FramebufferStatus> __EnumValueRange<FramebufferStatus>(void);

__StrCRef __EnumValueName(FramebufferStatus);

} // namespace oglplus
//]
