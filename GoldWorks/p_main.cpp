#include "p_main.hpp"

namespace gwe {
	void Base::run() {
		std::cout << "Application::run() invoked\n";
		while (!window.shouldClose()) {
			glfwPollEvents();
		}
		std::cout << "Window termination signal received\n";
	}

	void Base::createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO; // 17:7
	}
}