#pragma once
#include<iostream>
using namespace std;
#include<string>
class dictionary
{
	string word;
	string meaning;


public:
	dictionary();
	void insert(string x, string y);
	string displayW();
	string displayM();

};
