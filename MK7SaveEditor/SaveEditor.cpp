//This keeps shaping better and better.
#include "coinfunctions.h"

int main() {

	Import import;
	Endian32 endian;
	CountDecimalsFour dec;
	CountHexadecimalsFour hex;
	Export exportit;
	

	const int offset=19496;
	string text=import.GetFileContents("system0.dat");
	string coinsstr="ABCD";
	for (int i=offset; i<offset+4; i++) {
		coinsstr[i-offset]=text[i];
	} 
	//backup
	exportit.backup(text, "save.bak");
	
    
	coinsstr=endian.littleendian32(coinsstr);
	cout << coinsstr;
	int coinamt;
	coinamt=dec.fourbytedeccalculate(coinsstr);
	cout << coinamt;
	cin >> coinamt;
	cout << coinamt;
	coinsstr=endian.littleendian32(hex.fourbytehexcalculate(coinamt));
	cout << coinsstr;
	for (int i=offset; i<offset+4; i++) {
		text[i]=coinsstr[i-offset];
	}
	//output
    	exportit.backup(text, "edited.dat");
}
