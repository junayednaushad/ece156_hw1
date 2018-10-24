#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addi(ofstream &out, int rd, int rs1, int imm);
void sw(ofstream &out, int rs2, int imm, int rs1);
string decimalToBinary(int input, int length);
string binaryToHex(string binary);

int main()
{
	ofstream out;
	out.open("input.txt");
	addi(out,3,0,200); 
	
	addi(out,5,0,5);
	sw(out,5,0,3); //[200] = 5 
	
	addi(out,5,0,3);
	sw(out,5,4,3); //[204] = 3
	
	addi(out,5,0,7);
	sw(out,5,8,3); //[208] = 7
	
	addi(out,5,0,12);
	sw(out,5,12,3); //[212] = 12
	
	addi(out,5,0,4);
	sw(out,5,16,3); //[212] = 4
	
	out.close();
	return 0;
}

void addi(ofstream &out, int rd, int rs1, int imm)
{
	string s_rd = decimalToBinary(rd, 5);
	string s_rs1 = decimalToBinary(rs1, 5);
	string s_imm = decimalToBinary(imm, 12);
	string opcode = "0010011";
	string funct3 = "000";
	string binary = s_imm + s_rs1 + funct3 + s_rd + opcode;
	string hex = binaryToHex(binary);
	out << hex << "\n";
}

void sw(ofstream &out, int rs2, int imm, int rs1)
{
	string s_rs1 = decimalToBinary(rs1, 5);
	string s_rs2 = decimalToBinary(rs2, 5);
	string s_imm = decimalToBinary(imm, 12);
	string opcode = "0100011";
	string funct3 = "010";
	string imm40 = "";
	string imm115 = "";
	for(int i = 0; i < 7; i++)
		imm115 += s_imm.at(i);
	for(int i = 7; i < 12; i++)
		imm40 += s_imm.at(i);
	string binary = imm115 + s_rs2 + s_rs1 + funct3 + imm40 + opcode;
	string hex = binaryToHex(binary);
	out << hex << "\n";
}

string decimalToBinary(int input, int length)
{
	int *arr;
	arr = new int[length];
	string s = "";
	for(int i = length-1; i > -1; i--)
	{
		arr[i] = input%2;
		input = input/2;
	}
	for(int i = 0; i < length; i++)
		s+= to_string(arr[i]);
	delete [] arr;
	return s;
}

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