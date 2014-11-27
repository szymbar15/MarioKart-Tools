#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <cstdlib>
using namespace std;
string GetFileContents(const char *filename) {
	ifstream myfile (filename);
	if (myfile.is_open()) {
    	ostringstream contents;
    	contents << myfile.rdbuf();
		myfile.close();
    	return (contents.str());
  	}  else {
		cout << "There isn't a valid file called staff_ghost_time.bin in your directory.\nCheck if it really is there.\n";
		exit(1);
	}
}
string littleendian16 (string byte) {
	string endian="ab";
	endian[0]=byte[1];
	endian[1]=byte[0];
	return endian;
}
string littleendian32(string byte){
	string endian="abcd";
	endian[0]=byte[3];
	endian[1]=byte[2];
	endian[2]=byte[1];
	endian[3]=byte[0];
	return endian;
}
int fourbytedeccalculate (string amt) {
	int array[4];
	for (int i=0; i<4; i++) {
		array[i]=(int) amt[i];
	}
	int returnamt;
	returnamt=16777216*array[0]+65536*array[1]+256*array[2]+array[3];
	return returnamt;
	
}
int fourbytehexcalculate (int amt) {
	int array[4];
	array[0]=
	int returnamt;
	returnamt=16777216*array[0]+65536*array[1]+256*array[2]+array[3];
	return returnamt;
	
}

int main() {
	string text=GetFileContents("test.txt");
	string coinsstr;
	for (int i=0; i<4; i++) {
		coinsstr+=text[19496+i];
	} 
	coinsstr=littleendian32(coinsstr);
	int coinamt;
	coinamt=fourbytedeccalculate(coinsstr);
	cout << coinamt;
	cin >> coinamt;
	cout << coinamt;
	
}
