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
	string text=import.GetFileContents("system.dat");
	string coinsstr="ABCD";
	for (int i=offset; i<offset+4; i++) {
		coinsstr[i-offset]=text[i];
	} 
	//backup
	exportit.backup(text, "save.bak");
	
    //Load the amount of munny
	coinsstr=endian.littleendian32(coinsstr);
	int coinamt;
	coinamt=dec.fourbytedeccalculate(coinsstr);
	cout << endl << "Your current amount of coins is " << coinamt << endl;
	//Import amount of munny and convert it back
	cout << endl << "Type new amount of coins: ";
	cin >> coinamt;
	coinsstr=endian.littleendian32(hex.fourbytehexcalculate(coinamt));
	for (int i=offset; i<offset+4; i++) {
		text[i]=coinsstr[i-offset];
	}
	//Calculate CRC32
		//string shortened by 4
		string textcrc;
		textcrc=text.substr(0, text.size()-4);
		
		//Make all kinds of operations of your CRC32
		long long notcomplete;
		string complete;
		notcomplete=crc.crccalc(textcrc);
		complete=endian.littleendian32(hex.fourbytehexcalculate(notcomplete));
		cout << "CRC32 generated" << endl;
		
		//replace CRC values in original string
		for (int i=0; i<4; i++) {
			text[text.size()-4+i]=complete[i];
		}
	//output
    	exportit.backup(text, "newsave.dat");
    	cout << "File saved as newsave.dat in your tool\'s directory. Remember to rename it \nand place it on your SD card." <<endl;
    	cin.get();
	cin.get();
	return 0;
}
