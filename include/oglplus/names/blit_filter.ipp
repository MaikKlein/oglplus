/*
 *  .file oglplus/names/blit_filter.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/blit_filter.txt' instead.
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

switch(value)
{
#if defined GL_NEAREST
	case GL_NEAREST: return StrLit("NEAREST");
#endif
#if defined GL_LINEAR
	case GL_LINEAR: return StrLit("LINEAR");
#endif
	default:;
}

