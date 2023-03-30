#pragma once
#include "p_startup.h"
#include <string>

// Put all in a namespace, gwe for GoldWorks Engine
namespace gwe {

	// Create window class
	class gwWindow {
	public:
		gwWindow(int w, int h, std::string name);
		~gwWindow();

		bool shouldClose() { return glfwWindowShouldClose(window); }

	private:
		void initWindow();
		const int width;
		const int height;
		std::string windowName;
		GLFWwindow* window;
	};
}