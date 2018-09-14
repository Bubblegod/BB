#pragma once
#include<string>

using std::string;
class statistic
{
public:
	statistic();
	statistic(string);
	int getcharater();
	int getword();
	int getlines();
	int getblank();
	int getcode();
	int getcomment();
	void fileinit(string);
	string transition(TCHAR*);

private:
	string address;
};

