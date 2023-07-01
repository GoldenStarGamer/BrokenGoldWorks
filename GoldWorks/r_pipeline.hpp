#pragma once

#include <string>
#include <vector>

#include "d_device.hpp"

namespace gwe {
	struct gwShaderHeader
	{
		uint32_t version = 0;           // Version for compatibility
		uint32_t vertexSize = 0;        // Size of the vertex code
		uint32_t fragmentSize = 0;      // Size of the fragment code
		uint32_t vertexLocation = 0;    // Location of the vertex code
		uint32_t fragmentLocation = 0;  // Location of the fragment code
	};

	enum shadertype
	{
		vertex,
		fragment
	};

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
			const std::string& filePath,
			gwDevice& device,
			const PipelineConfigInfo& configInfo);

		~gwPipeline();

		gwPipeline(const gwPipeline&) = delete;
		void operator=(const gwPipeline&) = delete;

		void bind(VkCommandBuffer commandBuffer);

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filepath, shadertype shader);

		void createGraphicsPipeline(
			const std::string& filePath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);


		gwDevice& workDevice;
		VkPipeline gwGraphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}