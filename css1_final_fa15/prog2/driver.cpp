// Program comments here 
// 
// 
#include <iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void display( string s[][C], ofstream& A_out);


int main()
{

   string array[R][C];
	
	ifstream fin;
	ofstream fout;
	
	fin.open("northpole.txt");
	fout.open("status.txt");

	if( fin.fail() || fout.fail())
		{
			cout<< " Error openeing files!" << endl;
			exit(1);
		}
	
	fillArray( fin, array);

	display( array, fout);

	return 0;
}

// **************************************************************
void fillArray(ifstream& A_in, string S[][C])
{
	string word;

	for( int i = 0; i < R; i++)
		{
			for( int j = 0; j < C; j++)
				{

					A_in >> S[i][j];

				}

		}
return;
}//end fillArray
// ***************************************************************
void display( string s[][C], ofstream& A_out)
{

 for( int i = 1; i < R - 1; i++)
	{
		for( int j =1; j < C - 1; j++)
		{
			if( s[i][j] =="@" && (s[i][j + 1] == "!" || s[i][j - 1] == "!" || s[i + 1][j] == "!" || s[i - 1][j] == "!"))
				 continue;

		  if( s[i][j] == "@" && s[i + 1][j] =="!" && s[i-1][j] == "!" && ( s[i][j + 1] == "!" || s[i][j - 1] == "!"))
					{
						A_out << "Elf [" << i << "][" << j << "]: Run!\n";
					}

			if (s[i][j] == "@" && s[i + 1][j] == "!" && s[i -1][j] == "!" && s[i][j + 1] == "!" && s[i][j - 1] == "!")
					{
						A_out << "Elf [" << i << "][" << j << "]: Munch!\n";
					}
			//A_out << "Hello" << endl;
		}
	}


return;
}


 
