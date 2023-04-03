#include "p_main.hpp"

namespace gwe {
	void Base::run() {
		std::cout << "Application::run() invoked\n";
		while (!window.shouldClose()) {
			glfwPollEvents();
		}
		std::cout << "Window termination signal received\n";
	}
}