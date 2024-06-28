#include <iostream>
#include<vector>
#include<string>
using namespace std;

// key matrix for the key string
void getKeyMatrix(string key, int keyMatrix[][3])
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			keyMatrix[i][j] = (key[k]) % 65;
			k++;
		}
	}
}

// Following function encrypts the message
void encrypt(int cipherMatrix[][1],
			int keyMatrix[][3],
			int messageVector[][1])
{
	int x, i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 1; j++)
		{
			cipherMatrix[i][j] = 0;
		
			for (x = 0; x < 3; x++)
			{
				cipherMatrix[i][j] +=
					keyMatrix[i][x] * messageVector[x][j];
			}
		
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

// Function to implement Hill Cipher
void HillCipher(string message, string key)
{
	// Get key matrix from the key string
	int keyMatrix[3][3];
	getKeyMatrix(key, keyMatrix);

	int messageVector[3][1];

	// Generate vector for the message
	for (int i = 0; i < 3; i++)
		messageVector[i][0] = (message[i]) % 65;

	int cipherMatrix[3][1];

	// Generate the encrypted vector
	encrypt(cipherMatrix, keyMatrix, messageVector);

	string CipherText;

	// Generate the encrypted text from
	// the encrypted vector
	for (int i = 0; i < 3; i++)
		CipherText += cipherMatrix[i][0] + 65;

	// Finally print the ciphertext
	cout << CipherText;
}

void cipher(string message){
	vector<string> v;
	
	for(int i = 0; i<message.size() ; i++){
		string word;
		
		for(int j=0 ; j<3 && i<message.size() ; j++, i++){
			word.push_back(message[i]);
		}

		i--;
		
		v.push_back(word);
		word.clear();
	}
	
	if(v.back().size() < 3){
		int i = 3 - v.back().size();
		char x = v.back().back();
		
		for(i = 3-i ; i<3 ; i++){
			v.back().push_back(x);
		}
	}

	// Get the key
	string key = "QUDGDWGCT";
	
	for(int j=0 ; j<v.size() ; j++){
		HillCipher(v[j], key);
	}
}

// Driver function for above code
int main()
{
	// Get the message to be encrypted
	cout<<" Message: ";
	string sent;
	getline(cin, sent);
	sent.push_back(' ');

	cout << " Ciphertext: ";
	
	string word;
	for(int i=0 ; i<sent.size() ; i++){
		if(sent[i] != ' '){
			word.push_back(sent[i]);
		}

		else{
			cipher(word);
			word.clear();
			cout<<" ";
		}
	}

	return 0;
}
