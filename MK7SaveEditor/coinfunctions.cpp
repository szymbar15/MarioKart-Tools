#include "coinfunctions.h"
string Import::GetFileContents(const char *filename) {
	ifstream in (filename, ios::in | ios::binary);
	if (in) {
		ostringstream contents;
		contents << in.rdbuf();
		in.close();
		
		return (contents.str());
	}  else {
		cout << "There isn't a valid file called ''system0.bin'' in your directory.\nCheck if it really is there.\n";
		cin.ignore();			
		exit(1);
	}
}

string Endian16::littleendian16 (string byte) {
	string endian="ab";
	endian[0]=byte[1];
	endian[1]=byte[0];
	return endian;
}
string Endian32::littleendian32(string byte){
	string endian="abcd";
	endian[0]=byte[3];
	endian[1]=byte[2];
	endian[2]=byte[1];
	endian[3]=byte[0];
	return endian;
}
int CountDecimalsFour::fourbytedeccalculate (string amt) {
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
string CountHexadecimalsFour::fourbytehexcalculate (int amt) {
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

void Export::backup (string text, string filename) {
	ofstream out(filename.c_str(), ios_base::binary | ios_base::out);
    	out << text;
    	out.close();
}
