/*
 *  .file oglplus/enums/buffer_select_bit_ese.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/buffer_select_bit.txt' instead.
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#if defined GL_COLOR_BUFFER_BIT
# if defined ColorBuffer
#  pragma push_macro("ColorBuffer")
#  undef ColorBuffer
   OGLPLUS_ENUM_CLASS_VALUE(ColorBuffer, GL_COLOR_BUFFER_BIT)
#  pragma pop_macro("ColorBuffer")
# else
   OGLPLUS_ENUM_CLASS_VALUE(ColorBuffer, GL_COLOR_BUFFER_BIT)
# endif
#endif
#if defined GL_DEPTH_BUFFER_BIT
# if defined DepthBuffer
#  pragma push_macro("DepthBuffer")
#  undef DepthBuffer
   OGLPLUS_ENUM_CLASS_VALUE(DepthBuffer, GL_DEPTH_BUFFER_BIT)
#  pragma pop_macro("DepthBuffer")
# else
   OGLPLUS_ENUM_CLASS_VALUE(DepthBuffer, GL_DEPTH_BUFFER_BIT)
# endif
#endif
#if defined GL_STENCIL_BUFFER_BIT
# if defined StencilBuffer
#  pragma push_macro("StencilBuffer")
#  undef StencilBuffer
   OGLPLUS_ENUM_CLASS_VALUE(StencilBuffer, GL_STENCIL_BUFFER_BIT)
#  pragma pop_macro("StencilBuffer")
# else
   OGLPLUS_ENUM_CLASS_VALUE(StencilBuffer, GL_STENCIL_BUFFER_BIT)
# endif
#endif
