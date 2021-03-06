/**
 *  @file advanced/cloud_trace/app_data.cpp
 *  @brief Implements application-data-related functions
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2008-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#include "app_data.hpp"
#include "arg_parser.hpp"

#include <iostream>
#include <random>

namespace oglplus {
namespace cloud_trace {

AppData::AppData(void)
 : puser_intf(nullptr)
 , pset_status(nullptr)
 , perrstr(nullptr)
 , plogstr(nullptr)
 , allow_offscreen(false)
 , allow_x_rt_screens(false)
 , render_offscreen(false)
 , clip_tiles(false)
 , save_raytrace_data(false)
 , verbosity(0)
 , rand_seed(0)
 , output_prefix("clouds")
 , output_suffix("rgba")
 , skip_face()
 , finish_shader("rawdata")
 , raytrace_width(512)
 , raytrace_height(512)
 , render_width(raytrace_width)
 , render_height(raytrace_height)
 , tile(16)
 , unit_opacity(0.03)
 , unit_attenuation(0.02)
 , cloud_count(512)
 , cloud_res(256)
 , dump_cloud_image(false)
 , cloud_image_path()
 , cloud_data_path()
 , planet_radius(6371)
 , atm_thickness(50)
 , covered_angle(0.7)
 , cloud_mean_alt(3.0f)
 , cloud_alt_disp(0.4f)
 , cloud_mean_size(1.6f)
 , cloud_size_disp(0.5f)
 , cam_near(1)
 , cam_far(100)
 , light_x(100000)
 , light_y(100000)
 , light_z(100000)
 , high_light(1.0f)
 , ambi_light(0.0f)
 , crep_ray_far(cam_far*0.3)
 , crep_ray_sam(512)
{
	skip_face.fill(false);

	for(unsigned f=0; f!=6; ++f)
	{
		output_face_id[f] = "- ";
		output_face_id[f][1] = '0'+f;
	}
}

bool AppData::ParseArgs(int argc, char** argv)
{
	ArgParser parser;

	bool verbose;
	// verbose
	auto& verbose_opt = parser.AddOpt("-v", "--verbose", verbose)
		.AddDesc(
		"Increments the verbosity level value. This option can be "
		"used multiple times to increase the verbosity."
		);

	// verbosity level
	parser.AddArg("-vl", "--verbosity", verbosity)
		.AddDesc(
		"Sets the verbosity level to the specified value."
		);

	// random seed
	parser.AddArg("-rs", "--rand-seed", rand_seed)
		.AddDesc(
		"Sets the random seed for the cloud generator. "
		"If the default value is specified then a new "
		"random seed is used."
		);

	// output size
	parser.AddArg("-s", "--size", raytrace_width)
		.AddVar(raytrace_height)
		.AddVar(render_width)
		.AddVar(render_height)
		.AddDesc(
		"Sets the size of the raytrace output image. This option "
		"sets both the width and the height to the same value. "
		);

	// output width
	parser.AddArg("-w", "--raytrace-width", raytrace_width)
		.AddVar(render_width)
		.AddDesc(
		"Sets the width of the raytrace output image."
		);

	// output height
	parser.AddArg("-h", "--raytrace-height", raytrace_height)
		.AddVar(render_height)
		.AddDesc(
		"Sets the height of the raytrace output image."
		);

	// raytrace tile
	parser.AddArg("-t", "--tile", tile)
		.AddDesc(
		"Sets the size of the raytrace tile. The raytracer works "
		"on rectangular tiles, the width and height of which is set "
		"by this argument."
		);

	// cloud count
	parser.AddArg("-cc", "--cloud-count", cloud_count)
		.SetMax(1024)
		.AddDesc(
		"Sets the number of clouds that should be generated."
		);

	// cloud resolution
	parser.AddArg("-cr", "--cloud-res", cloud_res)
		.AddDesc(
		"Sets the resolution (width, height and depth) of the cloud "
		"cubic volume texture."
		);

	// dump cloud image
	parser.AddOpt("-di", "--dump-cloud-image", dump_cloud_image)
		.AddDesc(
		"If this option is used then a new cloud volume texture "
		"is generated and it is saved to the file specified by the "
		"--cloud-image-path option."
		);

	// cloud image path
	parser.AddArg("-ci", "--cloud-image-path", cloud_image_path)
		.AddDesc(
		"Specifies the path of the cloud volume texture to be loaded "
		"or saved. If the --dump-cloud-image option is used then a new "
		"cloud volume is generated and saved into a file, otherwise "
		"the cloud volume is not generated, and it is loaded from "
		"a file specified by this option."
		);

	// cloud data path
	parser.AddArg("-cd", "--cloud-data-path", cloud_data_path)
		.AddDesc(
		"Specifies the path of the cloud placment data file to be loaded."
		"If no file is specified then the clouds are generated by the "
		"built-in generator."
		);

	// cloud mean altitude
	parser.AddArg("-cma", "--cloud-mean-alt", cloud_mean_alt)
		.AddDesc(
		"The mean altitude at which the clouds created by the built-in "
		"cloud generator are placed."
		);

	// cloud altitude dispersion
	parser.AddArg("-cad", "--cloud-alt-disp", cloud_alt_disp)
		.AddDesc(
		"The dispersion in altitude of the clouds created by the built-in "
		"cloud generator."
		);

	// cloud mean size
	parser.AddArg("-cms", "--cloud-mean-size", cloud_mean_size)
		.AddDesc(
		"The mean size for the clouds created by the built-in "
		"cloud generator."
		);

	// cloud mean size
	parser.AddArg("-csd", "--cloud-size-disp", cloud_size_disp)
		.AddDesc(
		"The dispersion of size of the clouds created by the built-in "
		"cloud generator."
		);

	// planet radius
	parser.AddArg("-pr", "--planet-radius", planet_radius)
		.AddDesc(
		"The radius of the planet used by the built-in cloud generator "
		"to place the clouds on a spherical surface segment."
		);

	parser.AddArg("-ca", "--covered-angle", covered_angle)
		.AddDesc(
		"The angle (in degrees), used by the built-on cloud generator "
		"to limit the spherical surface segment on which clouds are "
		"generated."
		);

	// atmosphere thickness
	parser.AddArg("-at", "--atm-thickness", atm_thickness)
		.AddDesc(
		"The atmosphere thickness value used by some of the finishing "
		"shaders."
		);

	// unit opacity
	parser.AddArg("-uo", "--unit-opacity", unit_opacity)
		.SetMin(0.0f)
		.AddDesc(
		"The unit opacity value for cloud texture voxels. "
		"This value determines how dense the clouds look."
		);

	// unit attenuation
	parser.AddArg("-ua", "--unit-attenuation", unit_attenuation)
		.SetMin(0.0f)
		.AddDesc(
		"The unit light attenuation value for cloud texture voxels. "
		"This value determines how much light penetrating the clouds "
		"is attenuated."
		);

	// light x coord
	parser.AddArg("-lx", "--light-x", light_x)
		.AddDesc(
		"The X coordinate value of the light source."
		);

	// light y coord
	parser.AddArg("-ly", "--light-y", light_y)
		.AddDesc(
		"The Y coordinate value of the light source."
		);

	// light z coord
	parser.AddArg("-lz", "--light-z", light_z)
		.AddDesc(
		"The Z coordinate value of the light source."
		);

	// high light
	parser.AddArg("-hl", "--high-light", high_light)
		.AddDesc(
		"The high light value."
		);

	// ambient light
	parser.AddArg("-al", "--ambi-light", ambi_light)
		.AddDesc(
		"The ambient (lowest) light value."
		);

	// crepuscular ray samples
	parser.AddArg("-crs", "--crep-ray-sam", crep_ray_sam)
		.AddDesc(
		"Number of samples for crepuscular rays."
		);

	parser.AddOpt("-ct", "--clip-tiles", clip_tiles)
		.AddDesc(
		"Chooses the method of raytrace tile rendering. If enabled "
		"then the tiles are created polygon clipping otherwise the "
		"scissor test is used."
		);

	// save raytrace data
	parser.AddOpt("-srd", "--save-raytrace-data", save_raytrace_data)
		.AddDesc(
		"If this option is specified then the raytracer output data "
		"is saved instead of the finishing shader output."
		);

	// finish shader
	parser.AddArg("-fs", "--finish-shader", finish_shader)
		.AddDesc(
		"The name of the finishing fragment shader to be used "
		"to process the raytrace output data."
		);

	// output file prefix
	parser.AddArg("-o", "--output-prefix", output_prefix)
		.AddDesc(
		"The path prefix for the cube map image output files."
		);

	// output file suffix
	parser.AddArg("-s", "--output-suffix", output_suffix)
		.AddDesc(
		"The suffix for the cube map image output files."
		);

	// the X+ face id
	parser.AddArg("-of0", "--output-name-0", output_face_id[0])
		.AddDesc(
		"The name of the positive X cube map image output file."
		);

	// the X- face id
	parser.AddArg("-of1", "--output-name-1", output_face_id[1])
		.AddDesc(
		"The name of the negative X cube map image output file."
		);

	// the Y+ face id
	parser.AddArg("-of2", "--output-name-2", output_face_id[2])
		.AddDesc(
		"The name of the positive Y cube map image output file."
		);

	// the Y- face id
	parser.AddArg("-of3", "--output-name-3", output_face_id[3])
		.AddDesc(
		"The name of the negative Y cube map image output file."
		);

	// the Z+ face id
	parser.AddArg("-of4", "--output-name-4", output_face_id[4])
		.AddDesc(
		"The name of the positive Z cube map image output file."
		);

	// the Z- face id
	parser.AddArg("-of5", "--output-name-5", output_face_id[5])
		.AddDesc(
		"The name of the negative Z cube map image output file."
		);

	// skip X+ face
	parser.AddOpt("-sf0", "--skip-face-0", skip_face[0])
		.AddDesc(
		"Specifies that the rendering of the positive X face "
		"should be skipped."
		);

	// skip X- face
	parser.AddOpt("-sf1", "--skip-face-1", skip_face[1])
		.AddDesc(
		"Specifies that the rendering of the negative X face "
		"should be skipped."
		);

	// skip Y+ face
	parser.AddOpt("-sf2", "--skip-face-2", skip_face[2])
		.AddDesc(
		"Specifies that the rendering of the positive Y face "
		"should be skipped."
		);

	// skip Y- face
	parser.AddOpt("-sf3", "--skip-face-3", skip_face[3])
		.AddDesc(
		"Specifies that the rendering of the negative Y face "
		"should be skipped."
		);

	// skip Z+ face
	parser.AddOpt("-sf4", "--skip-face-4", skip_face[4])
		.AddDesc(
		"Specifies that the rendering of the positive Z face "
		"should be skipped."
		);

	// skip Z- face
	parser.AddOpt("-sf5", "--skip-face-5", skip_face[5])
		.AddDesc(
		"Specifies that the rendering of the negative Z face "
		"should be skipped."
		);

	// single-face mode
	unsigned single_face = 0;
	auto& single_face_arg = parser.AddArg("-f", "--single-face", single_face)
		.AddDesc(
		"Specifies a single face that should be rendered and saved. "
		"Rendering of other faces is skipped."
		);

	if(allow_offscreen)
	{
		parser.AddOpt("-os", "--offscreen", render_offscreen)
			.AddDesc(
			"Render into an offscreen buffer. When this options is "
			"specified no visible window is created and the rendering "
			"is done offscreen."
			);
	}

	if(allow_x_rt_screens)
	{
		parser.AddArg("-xrts", "--X-rt-screen", raytracer_params)
			.AddDesc(
			"This option may be used multiple times and each one "
			"specifies an X screen on which a new raytracing thread "
			"with its own GL context should be spawned."
			);
	}

	if(!parser.Parse(argc, argv))
		return false;

	// post parsing
	verbosity += verbose_opt.parse_count;

	if(single_face_arg.parse_count > 0)
	{
		for(unsigned f=0; f!=6; ++f)
		{
			skip_face[f] = (f != single_face);
		}
	}

	if(!rand_seed)
	{
		std::random_device rd;
		rand_seed = rd();
	}

	return true;
}

void AppData::LogInfo(void) const
{
	if(verbosity > 0)
	{
		if(render_offscreen)
		{
			logstr()
				<< "Rendering offscreen"
				<< std::endl;
		}
	}
	if(verbosity > 3)
	{
		logstr()
			<< "Raytrace width: "
			<< raytrace_width
			<< std::endl;
		logstr()
			<< "Raytrace height: "
			<< raytrace_height
			<< std::endl;
		logstr()
			<< "Raytrace columns: "
			<< cols()
			<< std::endl;
		logstr()
			<< "Raytrace rows: "
			<< rows()
			<< std::endl;
		logstr()
			<< "Raytrace tiles: "
			<< tiles()
			<< std::endl;
	}
	if(verbosity > 1)
	{
		logstr()
			<< "Random generator seed: "
			<< rand_seed
			<< std::endl;
	}
}

void AppData::set_status(const char* str)
{
	if(pset_status)
	{
		pset_status(puser_intf, str);
	}
}

std::ostream& AppData::errstr(void) const
{
	return (perrstr?*perrstr:std::cerr);
}

std::ostream& AppData::logstr(void) const
{
	return (plogstr?*plogstr:std::clog);
}

unsigned AppData::rows(void) const
{
	return (raytrace_height/tile)+(raytrace_height%tile?1:0);
}

unsigned AppData::cols(void) const
{
	return (raytrace_width/tile)+(raytrace_width%tile?1:0);
}

unsigned AppData::tiles(void) const
{
	return rows()*cols();
}

} // namespace cloud_trace
} // namespace oglplus
