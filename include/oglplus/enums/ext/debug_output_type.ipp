/*
 *  .file oglplus/enums/ext/debug_output_type.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/ext/debug_output_type.txt' instead.
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#if OGLPLUS_DOCUMENTATION_ONLY

/// DEBUG_TYPE_ERROR_ARB
Error,
/// DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB
DeprecatedBehavior,
/// DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB
UndefinedBehavior,
/// DEBUG_TYPE_PORTABILITY_ARB
Portability,
/// DEBUG_TYPE_PERFORMANCE_ARB
Performance,
/// DEBUG_TYPE_OTHER_ARB
Other

#else // !OGLPLUS_DOCUMENTATION_ONLY

#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

#if defined GL_DEBUG_TYPE_ERROR_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
,
# endif
Error = GL_DEBUG_TYPE_ERROR_ARB
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
,
# endif
DeprecatedBehavior = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
,
# endif
UndefinedBehavior = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_DEBUG_TYPE_PORTABILITY_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
,
# endif
Portability = GL_DEBUG_TYPE_PORTABILITY_ARB
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_DEBUG_TYPE_PERFORMANCE_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
,
# endif
Performance = GL_DEBUG_TYPE_PERFORMANCE_ARB
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined GL_DEBUG_TYPE_OTHER_ARB
# if OGLPLUS_LIST_NEEDS_COMMA
,
# endif
Other = GL_DEBUG_TYPE_OTHER_ARB
# ifndef OGLPLUS_LIST_NEEDS_COMMA
#  define OGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#ifdef OGLPLUS_LIST_NEEDS_COMMA
# undef OGLPLUS_LIST_NEEDS_COMMA
#endif

#endif // !OGLPLUS_DOCUMENTATION_ONLY

