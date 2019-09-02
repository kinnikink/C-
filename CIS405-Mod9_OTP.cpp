#include <iostream>
using namespace std;

int pos = 0; 								//current pad position
int pad[65] =								//our OTP array
	{8,	19,	13,	4,	23,
	22,	5,	23,	10,	16,
	5,	14,	3,	6,	21,
	20,	23,	9,	4,	18,
	6,	13,	17,	24,	16,
	2,	15,	15,	3,	24,
	15,	3,	2,	5,	19,
	6,	18,	15,	22,	19,
	18,	19,	3,	7,	11,
	18,	13,	8,	25,	16,
	9,	5,	18,	19,	9,
	20,	10,	19,	15,	2,
	5,	22,	20,	3,	23};

string encrypt(string plaintext)			//encryption function
{
	string ciphertext;
	for(int i=0; i<plaintext.size();i++)	//cycle through the plaintext
	{
		int num = plaintext[i] - 'A';		//convert to numbers
		num = (num + pad[pos++]) % 26;		//apply modular addition
		ciphertext.push_back(num + 'A');	//convert back to letters
	}
	pos=0;									//reset position
	return ciphertext;						//return the ciphertext
}

string decrypt(string ciphertext)
{
	string decryptedtext;										//write your decryption routine here
	for(int y = 0; y<ciphertext.size(); y++){
		
		int n = ciphertext[y] - 'A';
		n = (26 + n - pad[pos++]) % 26; //apply the reverse modular function 
		decryptedtext.push_back(n + 'A'); // convert back to letters
	
	
											}
	return decryptedtext;
}
int main()
{
	string plaintext = "HAPPY";				//encrypt plaintext HAPPY
	string ciphertext;
	ciphertext = encrypt(plaintext);
	cout<<"Ciphertext = "<<ciphertext<<endl;
	cout<<"Plaintext = "<<decrypt(ciphertext);
	return 1;
}
