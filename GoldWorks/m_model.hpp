#pragma once

#include <vector>

#include "p_startup.hpp"
#include "d_device.hpp"


namespace gwe {

	class gwModel {
	public:		
		struct Vertex {
			glm::vec2 position;

			static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
			static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
		};
		gwModel(gwDevice& argDevice, const std::vector<Vertex> &vertices);
		~gwModel();

		gwModel(const gwModel&) = delete;
		gwModel& operator=(const gwModel&) = delete;

		void bind(VkCommandBuffer commandBuffer);
		void draw(VkCommandBuffer commandBuffer);



	private:

		void createVertexBuffers(const std::vector<Vertex>& vertices);

		gwDevice& device;
		VkBuffer vertexBuffer;
		VkDeviceMemory vertexBufferMemory;
		uint32_t vertexCount;
	};

}