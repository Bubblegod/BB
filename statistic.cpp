#include "stdafx.h"
#include "statistic.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;
string filetext="";
int BLKNum=0, CDNum=0, CMMNum=0;


statistic::statistic() {
	

}
statistic::statistic(string address) {
	this->address = address;

}


void statistic:: fileinit(string faddress) {
	// import the string from the file to the an string var
	string line;
	ifstream in(faddress);
	if (in) {
		while (getline(in, line)) {
			filetext += line;
			filetext += "\n";
		}
		//improt the string line by line by the getline function
		if (line == "") filetext += "\n";
		//if the end of line is empty, still should be regarded as a line, but I need to add a "\n" at the end of filetext manually
	}
}


int l_function(string faddress) {
	//the function to statistic the number of line in the whole file 
	string line;
	int count;
	count = 0;
	ifstream in(faddress);
	if (in) {
		while (getline(in, line)) {
			count++;
		}
	}
	if (line == "") count++;
	//if the end of line is empty, still should be regarded as a line, but I need to count it manually
	return count;

}


int c_function(int line) {
	return filetext.length() - line;
	//the number of the charaters equals the length of the filetext minus the number of lines
}


bool word_judgment(char a) {
	//the function of judging a single charater whether a actual charater we use in programming or not
	bool flag;
	if ((a <= 'z') && (a >= 'a') || (a <= 'Z') && (a >= 'A') || (a <= '9') && (a >= '0') || a == '-') flag = true;
	else flag = false;
	return flag;
}

int w_function() {
	//the function of counting the number of words
	int i, wordcount = 0;
	i = 0;
	if (!word_judgment(filetext[0])) {
		while (!word_judgment((char)filetext[i])) {
			i++;
		}
	}
	//locate the first word in the whole string
	while (i<filetext.length()) {
		while (word_judgment(filetext[i])&&(i<filetext.length())) {
			i++;
		}
		wordcount++;
		//locate the charater that before a word in the whole string
		while ((!word_judgment((char)filetext[i])&&(i<filetext.length()))) {
			i++;
		}
	}
	return wordcount;
}


void a_function(string faddress) {
	int count;
	int blankNum = 0, comNum = 0, codeNum = 0;
	string line;
	ifstream in(faddress);
	if (in) {
		while (getline(in, line)) {
			count = 0;
			for (int i = 0; i<line.length(); i++) {
				if (line[i] != ' '&&line[i] != '\n') count++;
			}
			if (count <= 1) {
				blankNum++;

			}
			else {
				int i, pos = -1;
				for (i = 0; i<line.length() - 1; i++) {
					if ((line[i] == '/') && (line[i + 1] == '/'))
						pos = i;
				}
				count = 0;
				if (pos != -1) {
					for (i = 0; i<pos; i++) {
						if (line[i] != ' '&&line[i] != '\n') count++;
					}
					if (count <= 1) {
						comNum++;
					}
					else codeNum++;
				}
				else codeNum++;
			}
		}
	}

	cout << "blankNum=" << blankNum << endl << "codeNum=" << codeNum << endl << "comNum=" << comNum << endl;
	BLKNum = blankNum;
	CDNum = codeNum;
	CMMNum = comNum;

}


int statistic:: getcharater() {
	int i = c_function(l_function(filetext));
	return c_function(l_function(filetext));

}
int statistic:: getword() {
	return w_function();

}
int statistic:: getlines() {
	return l_function(address);

}
int statistic:: getblank() {
	a_function(address);
	return BLKNum;

}
int statistic:: getcode() {
	
	return CDNum;

}
int statistic:: getcomment() {
	
	return CMMNum;

}


string statistic::transition(TCHAR* str)
{
	string strstr;
	try
	{
		int iLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);

		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, str, -1, chRtn, iLen, NULL, NULL);

		strstr = chRtn;
		
	}
	catch (std::exception e)
	{
	}

	return strstr;
}


	
