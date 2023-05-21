#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "w_window.hpp"
#include "r_pipeline.hpp"
#include "b_swap_chain.hpp"
#include "d_device.hpp"
#include "m_model.hpp"

namespace gwe {
	class Engine {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		Engine();
		~Engine();

		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();
		void loadModels();
		void recreateSwapChain();
		void recordCommandBuffer( int imageIndex );

		gwWindow window{ WIDTH, HEIGHT, "GoldWorks Engine" };
		gwDevice device{ window };
		std::unique_ptr<gwSwapChain> swapChain;
		std::unique_ptr<gwPipeline> pipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
		std::unique_ptr<gwModel> model;
	};
}