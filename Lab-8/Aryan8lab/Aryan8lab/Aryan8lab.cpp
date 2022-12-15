#include <iostream>
#include <string>
#include <fstream>
#include "gnom_sort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Ща сделаем!\n";
	int prosto = 0, numb;
	char name[100][100];
	string check;
	ifstream text;
	ofstream text2;

	text.open("maind.txt");
	while (!text.eof())
	{
		text.getline(name[prosto], 256);
		prosto++;
	}
	text.close();

	int size = prosto * 2;
	int* date = new int[size];
	int* sort = new int[size];
	int* numeration = new int[size];
	int* result = new int[size];
	
	text.open("maind.txt");
	for (int i = 0; !text.eof(); i +=2)
	{
		text >> check;
		text >> date[i];
	}
	text.close();
	text.open("maind.txt");
	for (int i = 0, number = 0; i < prosto; i++, number += 2)
	{
		sort[i] = date[number + 1] + date[number];
		numeration[i] = i;
	}
	text.close();

	result = gnom_sort(prosto, sort, numeration);
	text2.open("maind.txt");
	for (int end = 0; end < prosto;end++)
	{
		numb = result[end];
		text2 << name[numb] << endl;
	}
	text2.close();
	cout << "Готово, boss!\n";
}