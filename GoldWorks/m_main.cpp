#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "w_window.hpp"
#include "p_main.hpp" 

int main(int argc, char* argv[]) {
	gwe::Engine app{};

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}