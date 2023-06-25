#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdint>

using namespace std;

struct ShaderHeader {
	uint32_t version = 0; // version for compability, for now doesn't matter but it might come in handy distinguish versions
	uint32_t vertexsize = 0; // size of vertex code
	uint32_t fragmentsize = 0; // size of fragment code
	uint32_t vertexlocation = 0; // location of vertex code
	uint32_t fragmentlocation = 0; // location of fragment code
};

const char* itc(int value) { // takes an int and returns char, used for write opperations that require chars instead of ints
	return reinterpret_cast<const char*>(&value);
}

int main(int argc, char* argv[]) {

	if (argc < 3 || argc > 4) {
		cout << "Invalid Arguments" << endl
			<< "Format: GWShaderMaker.exe <compiled vertex shader file> <compiled fragment shader file> <output file>(optional)";
		return 1;
	}

	string name;

	if (argc == 3) {
		name = "shader.gws"; // default name
	}
	else if (argc == 4) {
		name = argv[3];
		name.erase(remove(name.begin(), name.end(), '"'), name.end()); // remove ""
	}

	fstream shaders[2]; // vertex and fragment shader code

	shaders[0].open(argv[1], ios::in | ios::binary | ios::ate); // open vertex file

	shaders[1].open(argv[2], ios::in | ios::binary | ios::ate); //open fragment file

	fstream output(name, ios::in | ios::out | ios::trunc); // create output file

	ShaderHeader buffer; // structure of GoldWorksShader file

	buffer.vertexsize = shaders[0].tellp(); // get size of vertex code
	buffer.fragmentsize = shaders[1].tellp(); // get size of fragment code

	buffer.vertexlocation = 4 * 5; // all 5 header variables are 4 bytes, and the vertex code comes immediately after the header,
	// so 4 bytes * 5 variables

	buffer.fragmentlocation = buffer.vertexlocation + buffer.vertexsize; // fragment code comes immediately after vertex code,
	// so we go to the location of the vertex code wich we already know and skip the vertex code since we know the size of it

	// write header
	output.write(itc(buffer.version), 4);
	output.write(itc(buffer.vertexsize), 4);
	output.write(itc(buffer.fragmentsize), 4);
	output.write(itc(buffer.vertexlocation), 4);
	output.write(itc(buffer.fragmentlocation), 4);

	// write the shader code
	output << shaders[0].rdbuf();
	output << shaders[1].rdbuf();
	
	// don't forget to close the files
	shaders[0].close();
	shaders[1].close();
	output.close();

	return 0; // finish
}