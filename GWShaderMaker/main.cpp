#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]) {

	if (argc < 3 || argc > 4) {
		cout << "Invalid Arguments" << endl
			<< "Format: GWShaderMaker.exe <compiled vertex shader file> <compiled vfragment shader file> <output file>(optional)";
		return 1;
	}

	string name;
	int* buffer;

	if (argc == 3) {
		name = "out.gws";
	}
	else if (argc == 4) {
		name = argv[3];
		name.erase(remove(name.begin(), name.end(), '"'), name.end());
	}

	fstream shaders[2];

	shaders[0].open(argv[1], ios::in | ios::binary);

	fstream output(name);

	return 0;
}