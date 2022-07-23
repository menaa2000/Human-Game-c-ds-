#include "dictionary.h"
#include<iostream>
using namespace std;
#include<string>


dictionary::dictionary()
{
	word = '   ';
	meaning = '   ';
}
void dictionary::insert(string x, string y)
{
	word = x;
	meaning = y;

}
string dictionary::displayW()
{
	return word;
}
string dictionary::displayM()
{
	return meaning;
}
