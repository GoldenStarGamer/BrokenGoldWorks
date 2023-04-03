#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

#include "p_startup.h"

// Put all in a namespace, gwe for GoldWorks Engine
namespace gwe {

	// Create window class
	class gwWindow {
	public:
		gwWindow(int w, int h, std::string name);
		~gwWindow();

		gwWindow(const gwWindow&) = delete;
		gwWindow& operator=(const gwWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }

		VkExtent2D getExent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		void initWindow();
		const int width;
		const int height;
		std::string windowName;
		GLFWwindow* window;
	};
}