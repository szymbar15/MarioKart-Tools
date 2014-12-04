#ifndef CRC32_H_
#define CRC32_H_
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class CRC32 {
public:
	long long crccalc(string text);
};
#endif
