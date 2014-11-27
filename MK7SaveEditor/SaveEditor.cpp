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
int main() {
	string text=GetFileContents("test.txt");
	string coins;
	for (int i=0; i<4; i++) {
		coins+=text[19496+i];
	} 
	coins=littleendian32(coins);
	int coinsint[4];
	for (int i=0; i<4; i++) {
		coinsint[i]=(int) coins[i];
		if (coinsint[i]<0) {
			coinsint[i]+=256;
		}
		cout << coinsint[i];
		
	}
}
