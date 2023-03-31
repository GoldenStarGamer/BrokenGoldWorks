#include "r_pipeline.hpp"

#include <fstream>
#include <stdexcept>

namespace gwe {
	std::vector<char> gwPipeline::readFile(const std::string& filepath) {
		std::ifstream file{filepath, std::ios::ate | std::ios::binary};
		if (!file.is_open()) {
			throw std::runtime_error("File open failure: " + filepath);
		}
	}
}