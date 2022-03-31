//***ASSUMPTIONS***
//Case-insensitivity.
//save all values to a .txt file?
//use those to try in web browser?
#include <iostream>
#include <time.h>

using namespace std;

void GenerateCodesOfLength(int len);
char NextChar(char * alph, char c);

int main()
{
	int chars = 0;

	cout << "This is a test of the \"GenerateCodesOfLength()\" function." << endl;
	cout << "To begin generating alphanumeric permuations, enter a desired character length 0-16." << endl;
	cout << "Number of characters: " << endl;
	cin >> chars;

	cout << "Possible " << chars << "-character length codes:" << endl;
	GenerateCodesOfLength(chars);

	return 0;
}

void GenerateCodesOfLength(int len)
{	
	char* str = new char[len + 1]();	//Initializing the chars of a dynam cstring to NULL.
	char alphanum[36]{};
	int curr = 0;						//Tracks current char A-Z & 0-9.
	int rs = len - 1;					//Rightmost side of cstring before null.

	
	for(int i = 0; i < 26; i++)			//Setting alphanum to "ABC...XYZ0...9" w/ ASCII vals.
		alphanum[i] = 65 + i;
	for(int i = 26; i < 36; i++)
		alphanum[i] = 22 + i;
	for(int i = 0; i < len; i++)		//Set cstring to repeating As. Ex) AAA...\0
		str[i] = alphanum[0];

	if(len > 0)
	{
		for(int i = rs; i >= 0; i--)	    //Imagine the string is counting up. Ex) AAA,AAB,AAC... ABA,ABB,ABC..999
		{									//Start at str[len-2] to avoid landing on the '\0' in cstring.
			do
			{
				cout << "MARK1" << endl;
				if(str[rs] != alphanum[35])
					str[rs] = NextChar(alphanum, str[rs]);
				else
				{
					cout << "MARK2" << endl;
					do	//Place-value is about to increase so move left.
					{
						str[rs] = alphanum[0];
						rs--;
						cout << "MARK3" << endl;
					}while(str[rs] == alphanum[35]);
					
					str[rs] = NextChar(alphanum, str[rs]);
				}
				
				cout << str << endl;
				
			}while (str[i] != alphanum[35]);
			
			rs = len - 1;			//MAY NEED THIS ELSEWHERE TOO :)!!!!!!!!!!!!!!!!

			//rs = len - 2;
			//while (str[i - col] != alphanum[35])  //Whil
			//{
			//	for (int j = 0; j < 36; j++)
			//	{
			//		str[i + col] = alphanum[j];
			//		cout << str;
			//	}
			//}

			//for(int j=col; j < rs)
			//for(int)
			//str[col] = alphanum[0];
			//col++;
		}
	}
	


	
	//for(int i=0; i<len; i++)
	delete[] str;
}

char NextChar(char * alph, char c)
{
	char nextchar;					
	if(c == alph[35])				//IF last char in given alphabet...
		nextchar = c;				//Return the current char.
	else if(c == alph[25])			//ELIF the char is 'Z'...
		nextchar = alph[26];		//The next char will be '0';
	else							//ELSE get the following ASCII value.
		nextchar = c + 1;
	
	return nextchar;
}