/**
 *  @file oglplus/shader.hpp
 *  @brief Shader wrappers
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2012 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef OGLPLUS_SHADER_1107121519_HPP
#define OGLPLUS_SHADER_1107121519_HPP

#include <oglplus/config.hpp>
#include <oglplus/fwd.hpp>
#include <oglplus/glfunc.hpp>
#include <oglplus/error.hpp>
#include <oglplus/object.hpp>
#include <oglplus/friend_of.hpp>
#include <oglplus/compile_error.hpp>
#include <oglplus/auxiliary/info_log.hpp>
#include <oglplus/string.hpp>
#include <oglplus/glsl_source.hpp>

#include <vector>
#include <cassert>

namespace oglplus {

/// The type of a Shader
/**
 *  @ingroup enumerations
 *
 *  @see Shader::Type()
 */
OGLPLUS_ENUM_CLASS_BEGIN(ShaderType, GLenum)
#include <oglplus/enums/shader_type.ipp>
OGLPLUS_ENUM_CLASS_END

OGLPLUS_LIB_FUNC StrLit EnumValueName(
	ShaderType*,
	EnumBaseType<ShaderType>::Type value
) OGLPLUS_NOEXCEPT(true)
#if OGLPLUS_LINK_LIBRARY
;
#else
{
#if !OGLPLUS_NO_ENUM_VALUE_NAMES
#include <oglplus/names/shader_type.ipp>
#endif
	OGLPLUS_FAKE_USE(value);
	return StrLit();
}
#endif

/// Shader operations wrapper helper class
/**
 *  @note Do not use this class directly, use Shader instead.
 *
 *  @see Shader
 *
 *  @glsymbols
 *  @glfunref{CreateShader}
 *  @glfunref{DeleteShader}
 *  @glfunref{IsShader}
 */
class ShaderOps
 : public Named
 , public BaseObject<false>
{
protected:
	static void _init(
		GLsizei _count,
		GLuint* _name,
		ShaderType type,
		std::true_type
	) OGLPLUS_NOEXCEPT(true)
	{
		assert(_count == 1);
		assert(_name != nullptr);
		try{*_name = OGLPLUS_GLFUNC(CreateShader)(GLenum(type));}
		catch(...){ }
	}

	static void _init(
		GLsizei _count,
		GLuint* _name,
		ShaderType type,
		std::false_type
	)
	{
		assert(_count == 1);
		assert(_name != nullptr);
		*_name = OGLPLUS_GLFUNC(CreateShader)(GLenum(type));
		OGLPLUS_CHECK(OGLPLUS_ERROR_INFO(CreateShader));
	}

	static void _cleanup(GLsizei _count, GLuint* _name)
	OGLPLUS_NOEXCEPT(true)
	{
		assert(_count == 1);
		assert(_name != nullptr);
		assert(*_name != 0);
		try{OGLPLUS_GLFUNC(DeleteShader)(*_name);}
		catch(...){ }
	}

	static GLboolean _is_x(GLuint _name)
	OGLPLUS_NOEXCEPT(true)
	{
		assert(_name != 0);
		try{return OGLPLUS_GLFUNC(IsShader)(_name);}
		catch(...){ }
		return GL_FALSE;
	}

	friend class FriendOf<ShaderOps>;
public:
	/// Types related to Shader
	struct Property
	{
		/// The type of a Shader
		typedef ShaderType Type;
	};

	/// Get the type of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{GetShader}
	 *  @gldefref{SHADER_TYPE}
	 */
	ShaderType Type(void) const
	{
		GLint result = 0;
		OGLPLUS_GLFUNC(GetShaderiv)(
			_name,
			GL_SHADER_TYPE,
			&result
		);
		OGLPLUS_VERIFY(OGLPLUS_OBJECT_ERROR_INFO(
			CreateShader,
			Shader,
			EnumValueName(ShaderType(result)),
			_name
		));
		return ShaderType(result);
	}

	/// Set the source code of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{ShaderSource}
	 */
	void Source(const String& source) const
	{
		assert(_name != 0);
		const GLchar* srcs[1] = {source.c_str()};
		GLint lens[] = {GLint(source.size())};
		OGLPLUS_GLFUNC(ShaderSource)(_name, 1, srcs, lens);
	}

	/// Set the source code of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{ShaderSource}
	 */
	void Source(const StrLit& source) const
	{
		assert(_name != 0);
		const GLchar* srcs[1] = {source.c_str()};
		GLint lens[] = {GLint(source.size())};
		OGLPLUS_GLFUNC(ShaderSource)(_name, 1, srcs, lens);
	}

	/// Set the source code of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{ShaderSource}
	 */
	void Source(const GLchar* source) const
	{
		assert(_name != 0);
		const GLchar* srcs[1] = {source};
		OGLPLUS_GLFUNC(ShaderSource)(_name, 1, srcs, 0);
	}

	/// Set the source code of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{ShaderSource}
	 */
	void Source(const GLchar** srcs, int count) const
	{
		assert(_name != 0);
		OGLPLUS_GLFUNC(ShaderSource)(_name, count, srcs, 0);
	}

	/// Set the source code of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{ShaderSource}
	 */
	void Source(const std::vector<const GLchar*>& srcs) const
	{
		assert(_name != 0);
		OGLPLUS_GLFUNC(ShaderSource)(
			_name,
			srcs.size(),
			const_cast<const GLchar**>(srcs.data()),
			0
		);
	}

	/// Set the source code of the shader
	/**
	 *  @glsymbols
	 *  @glfunref{ShaderSource}
	 */
	void Source(const GLSLSource& glsl_source) const
	{
		assert(_name != 0);
		OGLPLUS_GLFUNC(ShaderSource)(
			_name,
			glsl_source.Count(),
			glsl_source.Parts(),
			glsl_source.Lengths()
		);
	}

	/// Returns true if the shader is already compiled, returns false otherwise
	/**
	 *  @see Compile
	 *
	 *  @glsymbols
	 *  @glfunref{GetShader}
	 *  @gldefref{COMPILE_STATUS}
	 */
	bool IsCompiled(void) const
	{
		assert(_name != 0);
		int status;
		OGLPLUS_GLFUNC(GetShaderiv)(_name, GL_COMPILE_STATUS, &status);
		OGLPLUS_VERIFY(OGLPLUS_OBJECT_ERROR_INFO(
			GetShaderiv,
			Shader,
			EnumValueName(Type()),
			_name
		));
		return status == GL_TRUE;
	}

	/// Returns the compiler output if the program is compiled
	/**
	 *  @see IsCompiled
	 *  @see Compile
	 *
	 *  @glsymbols
	 *  @glfunref{GetShader}
	 *  @glfunref{GetShaderInfoLog}
	 */
	String GetInfoLog(void) const
	{
		assert(_name != 0);
		return aux::GetInfoLog(
			_name, OGLPLUS_GLFUNC(GetShaderiv),
			OGLPLUS_GLFUNC(GetShaderInfoLog),
			"GetShaderiv",
			"GetShaderInfoLog"
		);
	}

	/// Compiles the shader
	/**
	 *  @throws Error CompileError
	 *  @see IsCompiled
	 *
	 *  @glsymbols
	 *  @glfunref{CompileShader}
	 */
	void Compile(void) const
	{
		assert(_name != 0);
		OGLPLUS_GLFUNC(CompileShader)(_name);
		OGLPLUS_CHECK(OGLPLUS_OBJECT_ERROR_INFO(
			CompileShader,
			Shader,
			EnumValueName(Type()),
			_name
		));
		if(OGLPLUS_IS_ERROR(!IsCompiled()))
			HandleBuildError<CompileError>(
				GetInfoLog(),
				OGLPLUS_OBJECT_ERROR_INFO(
					CompileShader,
					Shader,
					EnumValueName(Type()),
					_name
				)
			);
	}
#if OGLPLUS_DOCUMENTATION_ONLY || GL_VERSION_4_1 || GL_ARB_ES2_compatibility
	/// Indicate that the resources associated with the compiler can be freed
	/**
	 *  @glvoereq{4,1,ARB,ES2_compatibility}
	 *  @glsymbols
	 *  @glfunref{ReleaseShaderCompiler}
	 */
	static void ReleaseCompiler(void)
	{
		OGLPLUS_GLFUNC(ReleaseShaderCompiler)();
		OGLPLUS_VERIFY(OGLPLUS_ERROR_INFO(ReleaseShaderCompiler));
	}
#endif
};

#if OGLPLUS_DOCUMENTATION_ONLY
/// An object encasulating the shading language shader functionality
/**
 *  @see Program
 *  @see VertexShader
 *  @see GeometryShader
 *  @see FragmentShader
 *  @see TessControlShader
 *  @see TessEvaluationShader
 */
class Shader
 : public ShaderOps
{
public:
	Shader(ShaderType type);
	Shader(ShaderType type, String description);
};
#else
typedef Object<ShaderOps> Shader;
OGLPLUS_OBJECT_TYPE_ID(Shader, 11)
#endif


struct SpecializedShaderInitializer
{
protected:
	typedef const GLSLSource& ParameterType;

	SpecializedShaderInitializer(void){ }

	SpecializedShaderInitializer(
		Shader& shader,
		Shader::Property::Type,
		const GLSLSource& source
	)
	{
		shader.Source(source);
		shader.Compile();
	}
};


#if OGLPLUS_DOCUMENTATION_ONLY
/// Vertex shader wrapper
/**
 *  @see Shader
 *  @see Program
 *  @ingroup objects
 */
class VertexShader
 : public Shader
{ };
#elif defined GL_VERTEX_SHADER
typedef Specialized<
	Shader,
	OGLPLUS_CONST_ENUM_VALUE(ShaderType::Vertex),
	SpecializedShaderInitializer
> VertexShader;
#endif

#if OGLPLUS_DOCUMENTATION_ONLY
/// Geometry shader wrapper
/**
 *  @see Shader
 *  @see Program
 *  @ingroup objects
 */
class GeometryShader
 : public Shader
{ };
#elif defined GL_GEOMETRY_SHADER
typedef Specialized<
	Shader,
	OGLPLUS_CONST_ENUM_VALUE(ShaderType::Geometry),
	SpecializedShaderInitializer
> GeometryShader;
#endif

#if OGLPLUS_DOCUMENTATION_ONLY
/// Fragment shader wrapper
/**
 *  @see Shader
 *  @see Program
 *  @ingroup objects
 */
class FragmentShader
 : public Shader
{ };
#elif GL_FRAGMENT_SHADER
typedef Specialized<
	Shader,
	OGLPLUS_CONST_ENUM_VALUE(ShaderType::Fragment),
	SpecializedShaderInitializer
> FragmentShader;
#endif

#if OGLPLUS_DOCUMENTATION_ONLY
/// Tesselation control shader wrapper
/**
 *  @see Shader
 *  @see Program
 *  @ingroup objects
 */
class TessControlShader
 : public Shader
{ };
#elif GL_TESS_CONTROL_SHADER
typedef Specialized<
	Shader,
	OGLPLUS_CONST_ENUM_VALUE(ShaderType::TessControl),
	SpecializedShaderInitializer
> TessControlShader;
#endif

#if OGLPLUS_DOCUMENTATION_ONLY
/// Tesselation evaluation shader wrapper
/**
 *  @see Shader
 *  @see Program
 *  @ingroup objects
 */
class TessEvaluationShader
 : public Shader
{ };
#elif GL_TESS_EVALUATION_SHADER
typedef Specialized<
	Shader,
	OGLPLUS_CONST_ENUM_VALUE(ShaderType::TessEvaluation),
	SpecializedShaderInitializer
> TessEvaluationShader;
#endif

#if OGLPLUS_DOCUMENTATION_ONLY
/// Compute shader wrapper
/**
 *  @see Shader
 *  @see Program
 *  @ingroup objects
 */
class ComputeShader
 : public Shader
{ };
#elif GL_COMPUTE_SHADER
typedef Specialized<
	Shader,
	OGLPLUS_CONST_ENUM_VALUE(ShaderType::Compute),
	SpecializedShaderInitializer
> ComputeShader;
#endif

} // namespace oglplus

#endif // include guard
