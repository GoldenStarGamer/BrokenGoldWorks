#pragma once

#include <string>
#include <vector>

#include "d_device.hpp"

namespace gwe {

	struct PipelineConfigInfo {
		VkViewport viewport;
		VkRect2D scissor;
		
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};
	class gwPipeline {
	public:
		gwPipeline(
			const std::string& vertFilepath,
			const std::string& fragFilepath,
			gwDevice& device,
			const PipelineConfigInfo& configInfo);

		~gwPipeline();

		gwPipeline(const gwPipeline&) = delete;
		void operator=(const gwPipeline&) = delete;

		void bind(VkCommandBuffer commandBuffer);

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(
			const std::string& vertFilepath,
			const std::string& fragFilepath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);


		gwDevice& workDevice;
		VkPipeline gwGraphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}