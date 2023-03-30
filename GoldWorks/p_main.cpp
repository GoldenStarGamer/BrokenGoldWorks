#include "p_main.hpp"

namespace gwe {
	void Application::run() {
		while (!window.shouldClose()) {
			glfwPollEvents();
		}
	}
}