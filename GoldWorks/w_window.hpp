#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

#include "p_startup.hpp"

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
		
		bool wasWindowResized() { return framebufferResized; }

		void resetWindowResizedFlag() { framebufferResized = false; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);


	private:
		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

		void initWindow();

		int width;
		int height;
		bool framebufferResized = false;

		std::string windowName;
		GLFWwindow* window;
	};
}