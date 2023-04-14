#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "w_window.hpp"
#include "e_engine.hpp" 

int main(int argc, char* argv[]) {
	try {
	gwe::Engine app{};

	
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}