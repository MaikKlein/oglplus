//  File doc/quickbook/oglplus/quickref/enums/sync_condition.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/sync_condition.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2014 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_sync_condition
namespace oglplus {

enum class SyncCondition : GLenum
{
	GPUCommandsComplete = GL_SYNC_GPU_COMMANDS_COMPLETE
};

#if !__OGLPLUS_NO_ENUM_VALUE_RANGES
template <>
__Range<SyncCondition> __EnumValueName<SyncCondition>(void);
#endif

#if !__OGLPLUS_NO_ENUM_VALUE_NAMES
__StrCRef __EnumValueName(SyncCondition);
#endif

} // namespace oglplus
//]
