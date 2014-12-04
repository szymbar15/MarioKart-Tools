//A freaking mess, but it'll get fixed. Eventually.
#include "CRC32.h"
#include "coinfunctions.h"

int main() {

	Import import;
	Endian32 endian;
	CountDecimalsFour dec;
	CountHexadecimalsFour hex;
	Export exportit;
	CRC32 crc;
	

	const int offset=19496;
	string text=import.GetFileContents("test.txt");
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
	cout << endl << coinamt;
	cin >> coinamt;
	cout << endl << coinamt;
	coinsstr=endian.littleendian32(hex.fourbytehexcalculate(coinamt));
	cout << endl << coinsstr;
	for (int i=offset; i<offset+4; i++) {
		text[i]=coinsstr[i-offset];
	}
	string textcrc;
	textcrc=text.substr(0, text.size()-4);
	long long notcomplete;
	notcomplete=crc.crccalc(textcrc);
	string complete;
	complete=endian.littleendian32(hex.fourbytehexcalculate(notcomplete));
	/*string complete=notcomplete;
	cout << notcomplete;*/
	//cout << endl << (int) notcomplete[0] << " " << (int) notcomplete[1] << " " << (int) notcomplete[2] << " " << (int) notcomplete[3] << endl;
	for (int i=0; i<4; i++) {
		text[text.size()-4+i]=complete[i];
	}
	//output
    exportit.backup(text, "edited.dat");
}
