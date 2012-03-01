/*
 *  .file oglplus/names/buffer_indexed_target.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/buffer_indexed_target.txt' instead.
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

switch(GLenum(value))
{
#if defined GL_TRANSFORM_FEEDBACK_BUFFER
	case GL_TRANSFORM_FEEDBACK_BUFFER: return "TRANSFORM_FEEDBACK_BUFFER";
#endif
#if defined GL_UNIFORM_BUFFER
	case GL_UNIFORM_BUFFER: return "UNIFORM_BUFFER";
#endif
	default:;
}
