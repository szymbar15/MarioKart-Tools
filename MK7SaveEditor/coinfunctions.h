#ifndef COINFUNCTIONS_H_
#define COINFUNCTIONS_H_
#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Import {
public:
	string GetFileContents(const char *filename);
};

class Endian16 {
public:
	string littleendian16 (string byte);
};

class Endian32 {
public:
	string littleendian32 (string byte);
};

class CountDecimalsFour {
public:
	long long fourbytedeccalculate (string amt);
};

class CountHexadecimalsFour {
public:
	string fourbytehexcalculate (long long amt);
};

class Export {
public:
	void backup (string text, string filename);
};

#endif
