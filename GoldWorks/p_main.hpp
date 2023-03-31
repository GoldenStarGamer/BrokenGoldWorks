#pragma once

#include <iostream>

#include "w_window.hpp"

namespace gwe {
	class Application {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		gwWindow window{ WIDTH, HEIGHT, "GoldWorks Engine" };
	};
}