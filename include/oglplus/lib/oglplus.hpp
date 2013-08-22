/**
 *  @file oglplus/lib/oglplus.hpp
 *  @brief All-in-one include file for the separatelly-built oglplus functions
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_LIB_OGLPLUS_1208310818_HPP
#define OGLPLUS_LIB_OGLPLUS_1208310818_HPP

#ifdef None
# pragma push_macro("None")
# undef None
# define OGLPLUS_None_WAS_DEFINED
#endif

#ifndef OGLPLUS_IMPLEMENTING_LIBRARY
#define OGLPLUS_IMPLEMENTING_LIBRARY 1
#endif

#include <oglplus/config.hpp>
#include <oglplus/string.hpp>
#include <oglplus/fwd.hpp>

#include <oglplus/auxiliary/strings.hpp>
#include <oglplus/auxiliary/base_range.hpp>
#include <oglplus/auxiliary/uniform_typecheck.hpp>
#include <oglplus/auxiliary/info_log.hpp>
#include <oglplus/auxiliary/glsl_source.hpp>
#include <oglplus/auxiliary/shader_data.hpp>
#include <oglplus/auxiliary/uniform_init.hpp>

#include <oglplus/error.hpp>
#include <oglplus/vertex_attrib.hpp>
#include <oglplus/uniform_block.hpp>
#include <oglplus/uniform_subroutines.hpp>
#include <oglplus/framebuffer.hpp>
#include <oglplus/shader.hpp>
#include <oglplus/program.hpp>
#include <oglplus/program_pipeline.hpp>

#include <oglplus/imports/blend_file.hpp>

#include <oglplus/shapes/cage.hpp>
#include <oglplus/shapes/cube.hpp>
#include <oglplus/shapes/grid.hpp>
#include <oglplus/shapes/icosahedron.hpp>
#include <oglplus/shapes/plane.hpp>
#include <oglplus/shapes/torus.hpp>
#include <oglplus/shapes/sphere.hpp>
#include <oglplus/shapes/spiral_sphere.hpp>
#include <oglplus/shapes/tetrahedrons.hpp>
#include <oglplus/shapes/twisted_torus.hpp>
#include <oglplus/shapes/wicker_torus.hpp>

#include <oglplus/shapes/blender_mesh.hpp>
#include <oglplus/shapes/obj_mesh.hpp>

#include <oglplus/shapes/draw.hpp>
#include <oglplus/shapes/wrapper.hpp>
#include <oglplus/shapes/analyzer.hpp>

#include <oglplus/images/image.hpp>
#include <oglplus/images/brushed_metal.hpp>
#include <oglplus/images/checker.hpp>
#include <oglplus/images/cloud.hpp>
#include <oglplus/images/squares.hpp>
#include <oglplus/images/sphere_bmap.hpp>
#include <oglplus/images/random.hpp>

#if !OGLPLUS_NO_VARIADIC_TEMPLATES
#include <oglplus/text/unicode.hpp>
#include <oglplus/text/bitmap_glyph.hpp>
#include <oglplus/text/stb_truetype.hpp>
#endif //OGLPLUS_NO_VARIADIC_TEMPLATES

#include <oglplus/opt/resources.hpp>

#include <oglplus/ext/ARB_debug_output.hpp>

namespace oglplus {

// EnumValueName implementations
#include <oglplus/lib/enum_value_name.ipp>
// EnumValueRange implementations
#include <oglplus/lib/enum_value_range.ipp>

} // namespace oglplus

#undef OGLPLUS_IMPLEMENTING_LIBRARY

#ifdef OGLPLUS_None_WAS_DEFINED
# pragma pop_macro("None")
#endif

#endif // include guard
