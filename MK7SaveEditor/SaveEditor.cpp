#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <cstdlib>
using namespace std;
string GetFileContents(const char *filename) {
	ifstream in (filename, ios::in | ios::binary);
	if (in) {
		ostringstream contents;
		contents << in.rdbuf();
		in.close();
		
		return (contents.str());
	}  else {
				cout << "There isn't a valid file called ''arm9.bin'' in your directory.\nCheck if it really is there.\n";
				cin.ignore();			
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
		if (array[i]<0) {
			array[i]+=256;
		}
	}
	int returnamt;
	returnamt=16777216*array[0]+65536*array[1]+256*array[2]+array[3];
	return returnamt;
	
}
string fourbytehexcalculate (int amt) {
	int array[4];
	array[0]=amt/16777216;
	array[1]=(amt%16777216)/65536;
	array[2]=((amt%16777216)%65536)/256;
	array[3]=((amt%16777216)%65536)%256;
	string returnstr="ABCD";
	returnstr[0]=array[0];
	returnstr[1]=array[1];
	returnstr[2]=array[2];
	returnstr[3]=array[3];
	return returnstr;
	
}

void backup (string text, string filename) {
	ofstream out(filename.c_str(), ios_base::binary | ios_base::out);
    out << text;
    out.close();
}

int main() {
	const int offset=19496;
	string text=GetFileContents("system0.dat");
	string coinsstr="ABCD";
	for (int i=offset; i<offset+4; i++) {
		coinsstr[i-offset]=text[i];
	} 
	//backup
	backup(text, "save.bak");
	
    
	coinsstr=littleendian32(coinsstr);
	cout << coinsstr;
	int coinamt;
	coinamt=fourbytedeccalculate(coinsstr);
	cout << coinamt;
	cin >> coinamt;
	cout << coinamt;
	coinsstr=littleendian32(fourbytehexcalculate(coinamt));
	cout << coinsstr;
	for (int i=offset; i<offset+4; i++) {
		text[i]=coinsstr[i-offset];
	}
	//output
    	backup(text, "edited.dat");
}
