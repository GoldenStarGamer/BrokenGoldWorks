#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "w_window.hpp"
#include "r_pipeline.hpp"
#include "b_swap_chain.hpp"
#include "d_device.hpp"

namespace gwe {
	class Base {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		Base();
		~Base();

		Base(const Base&) = delete;
		Base& operator=(const Base&) = delete;

		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		gwWindow window{ WIDTH, HEIGHT, "GoldWorks Engine" };
		gwDevice device{ window };
		gwSwapChain swapChain{ device, window.getExent() };
		std::unique_ptr<gwPipeline> pipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}