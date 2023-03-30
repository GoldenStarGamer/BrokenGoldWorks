#pragma once
#include "startup.h"
#include <string>

namespace gwe {
	class gwWindow {
	public:
		gwWindow(int w, int h, std::string name);
		~gwWindow();

	private:
		void initWindow();
		const int width;
		const int height;
		std::string windowName;
		GLFWwindow* window;
	};
}