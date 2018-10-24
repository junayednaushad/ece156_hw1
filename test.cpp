#include <iostream> 
#include <string> 
using namespace std; 

string binaryToHex(string binary)
{
	string hex = "";
	string byte = "";
	for(int i = 0; i < 32; i=i+4)
	{
		byte = "";
		for(int j = 0; j < 4; j++)
		{
			byte += binary.at(i+j);
		}
		if(byte.compare("0000") == 0)
			hex+= "0";
		else if(byte.compare("0001") == 0)
			hex+= "1";
		else if(byte.compare("0010") == 0)
			hex+= "2";
		else if(byte.compare("0011") == 0)
			hex+= "3";
		else if(byte.compare("0100") == 0)
			hex+= "4";
		else if(byte.compare("0101") == 0)
			hex+= "5";
		else if(byte.compare("0110") == 0)
			hex+= "6";
		else if(byte.compare("0111") == 0)
			hex+= "7";
		else if(byte.compare("1000") == 0)
			hex+= "8";
		else if(byte.compare("1001") == 0)
			hex+= "9";
		else if(byte.compare("1010") == 0)
			hex+= "A";
		else if(byte.compare("1011") == 0)
			hex+= "B";
		else if(byte.compare("1100") == 0)
			hex+= "C";
		else if(byte.compare("1101") == 0)
			hex+= "D";
		else if(byte.compare("1110") == 0)
			hex+= "E";
		else
			hex+= "F";
	}
	return hex;
}

int main()
{
	string binary = "00001100100000000000000110010011";
	string output = binaryToHex(binary);
	cout << output << endl;
	return 0;
}