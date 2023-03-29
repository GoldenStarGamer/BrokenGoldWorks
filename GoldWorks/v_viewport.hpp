#pragma once
#include "startup.h"
#include <string>

namespace gwe {
	class gwViewport {
	public:
		gwViewport(int w, int h, std::string name);
		~gwViewport();

	private:
		void initWindow();
		const int width;
		const int height;
		std::string viewportName;
		GLFWwindow* window;
	};
}