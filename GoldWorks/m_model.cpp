#include <cassert>

#include "m_model.hpp"

namespace gwe {
	gwModel::gwModel(gwDevice& argDevice, const std::vector<Vertex>& vertices) : device{ argDevice } {
		createVertexBuffers(vertices);
	}
	gwModel::~gwModel() {
		vkDestroyBuffer(device.device(), vertexBuffer, nullptr);
		vkFreeMemory(device.device(), vertexBufferMemory, nullptr);
	}
	void gwModel::createVertexBuffers(const std::vector<Vertex>& vertices) {
		vertexCount = static_cast<uint32_t>(vertices.size());
		assert(vertexCount >= 3 && "Vertex count must be at least 3");
		VkDeviceSize bufferSize = sizeof(vertices[0]) * vertexCount;
		device.createBuffer(bufferSize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
			vertexBuffer,
			vertexBufferMemory);

		void* data;
		vkMapMemory(device.device(), vertexBufferMemory, 0, bufferSize, 0, &data);
	}
}