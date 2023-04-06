#include "p_main.hpp"

namespace gwe {

	Base::Base() {
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}

	Base::~Base() {
		vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);

	}

	void Base::run() {
		std::cout << "Application::run() invoked\n";
		while (!window.shouldClose()) {
			glfwPollEvents();
		}
		std::cout << "Window termination signal received\n";
	}

	void Base::createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;

		if (vkCreatePipelineLayout(device.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("Pipeline Layout Creation Error.");
		}
	}

	void Base::createPipeline() {
		auto pipelineConfig = gwPipeline::defaultPipelineConfigInfo(swapChain.width(), swapChain.height());
		pipelineConfig.renderPass = swapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		pipeline = std::make_unique<gwPipeline>("vertex_shader.spv", "fragment_shader.spv", device, pipelineConfig);
	}

	void Base::createCommandBuffers() {}
	void Base::drawFrame() {}

}