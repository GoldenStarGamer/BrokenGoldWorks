#include "w_window.hpp"

namespace gwe {
	gwWindow::gwWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	gwWindow::~gwWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
		std::cerr << "Window destroyed\n";
	}

	void gwWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
		std::cerr << "Window created\n";
	}

	void gwWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Window Surface creation error.");
		}
		std::cerr << "Window Surface created\n";
	}

	void gwWindow::framebufferResizeCallback(GLFWwindow* argwindow, int width, int height) {
		auto window = reinterpret_cast<gwWindow*>(glfwGetWindowUserPointer(argwindow));
		window->framebufferResized = true;
		window->width = width;
		window->height = height;

	}

}