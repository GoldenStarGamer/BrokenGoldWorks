#include <array>

#include "e_engine.hpp"

namespace gwe {

	Engine::Engine() {
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
		std::cout << "Engine Object Created\n";
	}

	Engine::~Engine() {
		vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);

	}

	void Engine::run() {
		std::cout << "Engine::run() invoked\n";
		while (!window.shouldClose()) {
			glfwPollEvents();
			drawFrame();
		}
		std::cout << "Window termination signal received\n";
		vkDeviceWaitIdle(device.device());
	}

	void Engine::createPipelineLayout() {
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

	void Engine::createPipeline() {
		auto pipelineConfig = gwPipeline::defaultPipelineConfigInfo(swapChain.width(), swapChain.height());
		pipelineConfig.renderPass = swapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		pipeline = std::make_unique<gwPipeline>("vertex_shader.spv", "fragment_shader.spv", device, pipelineConfig);
	}

	void Engine::createCommandBuffers() {
		commandBuffers.resize(swapChain.imageCount());
		VkCommandBufferAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = device.getCommandPool();
		allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

		if (vkAllocateCommandBuffers(device.device(), &allocInfo, commandBuffers.data()) != VK_SUCCESS) {
			throw std::runtime_error("Command Buffer Allocation Error.");
		}

		for (int i = 0; i < commandBuffers.size(); i++) {
			VkCommandBufferBeginInfo beginInfo{};
			beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
			
			if (vkBeginCommandBuffer(commandBuffers[i], &beginInfo) != VK_SUCCESS) {
				throw std::runtime_error("Command Buffer Recording Start Error.");
			}

			VkRenderPassBeginInfo renderPassInfo{};
			renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
			renderPassInfo.renderPass = swapChain.getRenderPass();
			renderPassInfo.framebuffer = swapChain.getFrameBuffer(i);

			renderPassInfo.renderArea.offset = { 0, 0 };
			renderPassInfo.renderArea.extent = swapChain.getSwapChainExtent();

			std::array<VkClearValue, 2> clearValues{};
			clearValues[0].color = { 0.1f, 0.1f, 0.1f, 1.0f };
			clearValues[1].depthStencil = { 1.0f, 0 };
			renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
			renderPassInfo.pClearValues = clearValues.data();

			vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

			pipeline->bind(commandBuffers[i]);
			vkCmdDraw(commandBuffers[i], 3, 1, 0, 0);

			vkCmdEndRenderPass(commandBuffers[i]);
			if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS) {
				throw std::runtime_error("Command Buffer Recording Error.");
			}
		}
	}
	void Engine::drawFrame() {
		uint32_t imageIndex;
		auto result = swapChain.acquireNextImage(&imageIndex);
		
		if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
			throw std::runtime_error("Swap Chain Image Acquisition Error");
		}

		result = swapChain.submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);

		if (result != VK_SUCCESS) {
			throw std::runtime_error("Swap Chain Image Acquisition Error");
		}
	}

}