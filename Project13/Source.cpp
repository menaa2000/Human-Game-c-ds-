#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include"dictionary.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <algorithm>
using namespace std;


void insert(string, vector<dictionary>&, int&);
void chooseWord(vector<dictionary>, int, dictionary&);
void start();
void check(vector<dictionary>, int, int);
void fewLettrers(string&, string&, int&);
void display(string&, string&);
void checkLetters(string& origin, string& word, int& dashNum, int counter, dictionary& d3, vector<dictionary>v);
void back(string x);
void re_arrange(string b, dictionary& d3,int);
void random(vector<dictionary>v, dictionary&);
void checkLenght(vector<dictionary>v, dictionary&, int);
vector<vector<dictionary>> categories;    //vector of vector of type dictionary

vector<dictionary> category1;
vector<dictionary> category2;
vector<dictionary> category3;
vector<dictionary> category4;

int categoryNumber = 4;
int* counter{ new int[categoryNumber] {0} };
dictionary d3;        //object for reciving information to push it into the vector and displaying its content

int score = 0;
int dashNum = 0;
string origin, word;





int main() {
	string* c{ new string[categoryNumber] {"countries.txt" ,"myAnimals.txt" ,"plants.txt" ,"myJobs.txt"} };
	categories.push_back(category1);
	categories.push_back(category2);
	categories.push_back(category3);
	categories.push_back(category4);

	for (int i = 0; i < categoryNumber; i++)
	{
		insert(c[i], categories.at(i), counter[i]);
	}
	start();


	system("pause");
	return 0;
}








void insert(string s, vector<dictionary>& v, int& counter)
{
	string line;
	ifstream myfile(s);
	string d1, d2;

	if (myfile.is_open())
	{

		while (getline(myfile, line))
		{

			if (counter % 2 == 0)
			{
				d1 = line;

			}
			else
			{
				d2 = line;
				d3.insert(d1, d2);
				v.push_back(d3);
			}
			counter++;

		}
		counter = counter / 2;

		myfile.close();
	}

	else cout << "Unable to open file";

}

void chooseWord(vector<dictionary>v, int counter, dictionary& d3)
{
	srand(time(NULL));

	int x = rand() % counter;
	d3 = v.at(x);
	cout << d3.displayM();
	cout << endl << endl;
}
void rand_word(vector<dictionary>v, int counter, dictionary& d3)
{
	srand(time(NULL));

	int x = rand() % counter;
	d3 = v.at(x);
}

void hangname()
{
	cout << "\
t---------------------------------------------------------------" << endl;
	cout << "\t        _   _                  ___  ___            " << endl;
	cout << "\t       | | | |                 |  \\/  |            " << endl;
	cout << "\t       | |_| | __ _ _ __   __ _| .  . | __ _ _ __  " << endl;
	cout << "\t       |  _  |/ _` | '_ \\ / _` | |\\/| |/ _` | '_ \\ " << endl;
	cout << "\t       | | | | (_| | | | | (_| | |  | | (_| | | | |" << endl;
	cout << "\t       \\_| |_/\\__,_|_| |_|\\__, \\_|  |_/\\__,_|_| |_|" << endl;
	cout << "\t                           __/ |                   " << endl;
	cout << "\t                          |___/                    " << endl;


}
void draw(int no)
{
	switch (no) {
	case 6:
		cout << endl;
		cout << "  +----+" << endl;
		cout << "  |    |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  +=========" << endl;
		break;
	case 5:
		cout << endl;
		cout << "  +----+" << endl;
		cout << "  |    |" << endl;
		cout << "  |    O" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  +=========" << endl;
		break;
	case 4:
		cout << endl;
		cout << "  +----+" << endl;
		cout << "  |    |" << endl;
		cout << "  |    O" << endl;
		cout << "  |    |" << endl;
		cout << "  |    |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  +=========" << endl;
		break;
	case 3:
		cout << endl;
		cout << "  +----+" << endl;
		cout << "  |    |" << endl;
		cout << "  |    O" << endl;
		cout << "  |    |" << endl;
		cout << "  |    |" << endl;
		cout << "  |     \\" << endl;
		cout << "  |      \\" << endl;
		cout << "  |" << endl;
		cout << "  +=========" << endl;
		break;
	case 2:
		cout << endl;
		cout << "  +----+" << endl;
		cout << "  |    |" << endl;
		cout << "  |    O" << endl;
		cout << "  |    |" << endl;
		cout << "  |    |" << endl;
		cout << "  |   / \\" << endl;
		cout << "  |  /   \\" << endl;
		cout << "  |" << endl;
		cout << "  +=========" << endl;
		break;

		break;
	case 1:
		cout << endl;
		cout << "  +----+" << endl;
		cout << "  |    |" << endl;
		cout << "  |    O" << endl;
		cout << "  |   /|\\" << endl;
		cout << "  |  / | \\" << endl;
		cout << "  |   / \\" << endl;
		cout << "  |  /   \\" << endl;
		cout << "  |" << endl;
		cout << "  +=========" << endl;
		break;
	}
}
string sortString(string& str)
{
	sort(str.begin(), str.end());
	return str;
}
void  re_arrange(string b,dictionary& d3,int i)
{
	
	
	rand_word(categories[i], counter[i], d3);
	int index = 0;
 	 b=d3.displayW() ;
	string reuse = b;
	string word;
	//int m;
	char letter;
	int position;
	word = sortString(reuse);
	cout << endl;
	 
	while (true)
	{
		system("CLS");
		cout << "For Home:press 0";
		cout << endl << "Rearrange: ";
		display(b, word);
		cout << endl<<"Enter The Letter and Position that You Want from 1 to " <<b.size() << endl;
		cin >> letter;
		if (letter == '0')
		{
			system("cls");
			start();
		}
		cin >> position;
		
		for (int i = 0; i < b.size(); i++)
		{
			if (letter == word[i])
			{
				index = i;
			}
		}
		swap(word[position-1], word[index]);
		
		if (word ==b)
		{
			display(b, word);
			cout << endl << "YOU WON ^-^" << endl;
			break;
		}
		else
		{
			continue;
		}
	}
}

void start()
{
	hangname();
	int n,level;
	cout << " \t\t\t\t\t\t   WELCOME TO DICTIONARY GAME \t" << endl << endl << endl;


	cout << "(1)Countries " << endl << "(2)Animals " << endl << "(3)Plants " << endl << "(4)Jobs "<<endl;
	cout << "Please,enter the number of the category: ";
	cin >> n;
	int i = n - 1;                  //because the number of categories starts from 1 and the vector starts from 0 
	//if (n==5)
	//	re_arrange(d3.displayW() ,d3);
	//else
	    system("CLS"); 
		cout << endl<<"Which level do you prefer? "<<endl;
		cout << "(1)easy " << endl << "(2)medium " << endl << "(3)Hard " << endl ;
		cin >> level;
		switch (level)
		{
		case 1:
			re_arrange(d3.displayW(), d3,i);
			break;
		case 2:
			system("CLS");
			cout << "For Home:press 0";
			cout << endl << endl << "\t\t\t\t what is the word that has this meaning?" << endl << endl << endl;
			chooseWord(categories[i], counter[i], d3);
			check(categories[i], counter[i], score);
			break;
		case 3:
			checkLenght( categories[i], d3, 8);
			check(categories[i], counter[i], score);
			break;
		}
	//}

}  
void check(vector<dictionary> v, int counter, int score)
{
	string myWord;
	string origin = d3.displayW();
	int trails = 3;
	while (trails != 0)
	{
		cout << "\t";
		cin >> myWord;
		back(myWord);
		if (myWord == origin)
		{
			cout << "That is right, Congratulations" << endl << endl;
			score += 10;
			break;
		}
		else
		{
			
			system("CLS");
			cout << "For Home:press 0";
			cout << endl << endl << "\t\t\t what is the word that has this meaning?" << endl << endl << endl;
			cout<<d3.displayM();
			draw(trails + 3);
			trails--;
			if (trails == 0)
				break;
			cout << "Please,try again  " << endl;

		}

	}
	if (trails > 0)
	{
		if (score < 100)
		{
			system("pause");
			system("CLS");
			cout << "For Home:press 0";
			cout << endl << endl << "\t\t\t what is the word that has this meaning?" << endl << endl << endl;
			chooseWord(v, counter, d3);
			check(v, counter, score);
		}
		else
			cout << " Congratulations,YOU WIN!! " << endl;


	}
	else
	{
		fewLettrers(origin, word, dashNum);
		display(origin, word);
		checkLetters(origin, word, dashNum, counter, d3, v);
	}
}

void fewLettrers(string& origin, string& word, int& dashNum)
{
	origin = d3.displayW();
	word = origin;
	srand(time(NULL));
	int m;
	for (int i = 0; i < origin.size(); i++)
	{
		word[i] = '_';
	}
	if (origin.size() % 2 == 0)
	{
		for (int i = 0; i < origin.size() / 2; i++)
		{
			m = rand() % origin.size();
			word[m] = origin[m];
			dashNum++;
		}
	}
	else
	{
		for (int i = 0; i < (origin.size() - 1) / 2; i++)
		{
			m = rand() % origin.size();
			word[m] = origin[m];
			dashNum++;
		}
	}



}
void display(string& origin, string& word)
{
	cout << endl << "\t";
	for (int i = 0; i < origin.size(); i++)
	{
		cout << word[i] << " ";
	}
}
void checkLetters(string& origin, string& word, int& dashNum, int counter, dictionary& d3, vector<dictionary>v)
{
	int trails = 3;
	int founded = -1;
	bool right;
	char c;
	while (trails != 0)
	{
		cin >> c;
		right = false;

		for (int k = 0; k < origin.size(); k++)
		{

			founded = origin.find(c, founded + 1);
			if (founded != -1)
			{
				right = true;
				word[founded] = c;

			}

		}
		system("CLS");
		cout << endl << endl << "\t\t\t what is the word that has this meaning?" << endl << endl << endl;
		cout << d3.displayM();
		display(origin, word);

		if (right == false)
		{
			draw(trails);
			trails--;
		}
		if (word == origin)
		{
			cout << endl << "That's right, congratulations!!" << endl;
			system("pause");

			cout << "For Home:press 0";
			cout << endl << endl << "\t\t\t what is the word that has this meaning?" << endl << endl << endl;
			chooseWord(v, counter, d3);
			check(v, counter, score);

			break;
		}
		else if (trails == 0)
		{
			cout << endl << "Game Over" << endl;
			system("pause");
			system("CLS");
			start();
		}

	}
}
void back(string x)
{
	if (x == "0")
	{
		system("CLS");
		start();
	}

}
void random(vector<dictionary>v, dictionary& d3)
{
	srand(time(NULL));
	int x = rand() % v.size();
	d3 = v.at(x);

}
void checkLenght(vector<dictionary>v, dictionary& d3, int num)
{
	string myWord = d3.displayW();

	while (myWord.size() < num)
	{
		random(v, d3);
	}
	cout << d3.displayM()<< endl;
}

