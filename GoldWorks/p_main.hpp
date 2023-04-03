#pragma once

#include <iostream>

#include "w_window.hpp"
#include "r_pipeline.hpp"
#include "d_device.hpp"

namespace gwe {
	class Base {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		gwWindow window{ WIDTH, HEIGHT, "GoldWorks Engine" };
		gwDevice device{ window };
		gwPipeline pipeline{"vertex_shader.spv", "fragment_shader.spv", device, gwPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}