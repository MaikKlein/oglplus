/*
 *  .file oglplus/names/program_interface.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/program_interface.txt' instead.
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

switch(value)
{
#if defined GL_UNIFORM
	case GL_UNIFORM: return StrLit("UNIFORM");
#endif
#if defined GL_UNIFORM_BLOCK
	case GL_UNIFORM_BLOCK: return StrLit("UNIFORM_BLOCK");
#endif
#if defined GL_ATOMIC_COUNTER_BUFFER
	case GL_ATOMIC_COUNTER_BUFFER: return StrLit("ATOMIC_COUNTER_BUFFER");
#endif
#if defined GL_PROGRAM_INPUT
	case GL_PROGRAM_INPUT: return StrLit("PROGRAM_INPUT");
#endif
#if defined GL_PROGRAM_OUTPUT
	case GL_PROGRAM_OUTPUT: return StrLit("PROGRAM_OUTPUT");
#endif
#if defined GL_VERTEX_SUBROUTINE
	case GL_VERTEX_SUBROUTINE: return StrLit("VERTEX_SUBROUTINE");
#endif
#if defined GL_TESS_CONTROL_SUBROUTINE
	case GL_TESS_CONTROL_SUBROUTINE: return StrLit("TESS_CONTROL_SUBROUTINE");
#endif
#if defined GL_TESS_EVALUATION_SUBROUTINE
	case GL_TESS_EVALUATION_SUBROUTINE: return StrLit("TESS_EVALUATION_SUBROUTINE");
#endif
#if defined GL_GEOMETRY_SUBROUTINE
	case GL_GEOMETRY_SUBROUTINE: return StrLit("GEOMETRY_SUBROUTINE");
#endif
#if defined GL_FRAGMENT_SUBROUTINE
	case GL_FRAGMENT_SUBROUTINE: return StrLit("FRAGMENT_SUBROUTINE");
#endif
#if defined GL_COMPUTE_SUBROUTINE
	case GL_COMPUTE_SUBROUTINE: return StrLit("COMPUTE_SUBROUTINE");
#endif
#if defined GL_VERTEX_SUBROUTINE_UNIFORM
	case GL_VERTEX_SUBROUTINE_UNIFORM: return StrLit("VERTEX_SUBROUTINE_UNIFORM");
#endif
#if defined GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	case GL_TESS_CONTROL_SUBROUTINE_UNIFORM: return StrLit("TESS_CONTROL_SUBROUTINE_UNIFORM");
#endif
#if defined GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	case GL_TESS_EVALUATION_SUBROUTINE_UNIFORM: return StrLit("TESS_EVALUATION_SUBROUTINE_UNIFORM");
#endif
#if defined GL_GEOMETRY_SUBROUTINE_UNIFORM
	case GL_GEOMETRY_SUBROUTINE_UNIFORM: return StrLit("GEOMETRY_SUBROUTINE_UNIFORM");
#endif
#if defined GL_FRAGMENT_SUBROUTINE_UNIFORM
	case GL_FRAGMENT_SUBROUTINE_UNIFORM: return StrLit("FRAGMENT_SUBROUTINE_UNIFORM");
#endif
#if defined GL_COMPUTE_SUBROUTINE_UNIFORM
	case GL_COMPUTE_SUBROUTINE_UNIFORM: return StrLit("COMPUTE_SUBROUTINE_UNIFORM");
#endif
#if defined GL_TRANSFORM_FEEDEBACK_VARYING
	case GL_TRANSFORM_FEEDEBACK_VARYING: return StrLit("TRANSFORM_FEEDEBACK_VARYING");
#endif
#if defined GL_BUFFER_VARIABLE
	case GL_BUFFER_VARIABLE: return StrLit("BUFFER_VARIABLE");
#endif
#if defined GL_SHADER_STORAGE_BLOCK
	case GL_SHADER_STORAGE_BLOCK: return StrLit("SHADER_STORAGE_BLOCK");
#endif
	default:;
}

