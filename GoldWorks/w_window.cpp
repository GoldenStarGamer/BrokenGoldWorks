#include "w_window.hpp"

namespace gwe {
	gwWindow::gwWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	gwWindow::~gwWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
		std::cout << "Window destroyed\n";
	}

	void gwWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		std::cout << "Window created\n";
	}
}