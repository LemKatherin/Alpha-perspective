// Alpha-perspective.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
		
					// generates random array
void input_rand(vector<int>& mas, int& size, int& X)
{
	cout << "Input size of the array: ";
	cin >> size;
	cout << endl;

	mas.resize(size);
	mas[size-1] = rand() % 20 + 1;
	for (int i = size-2; i >=0; i--)
	{
		mas[i] = mas[i+1] + (rand() % 20 + 1);
	}

	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << ' ';
	}
	cout << endl << endl;

	cout << "Input the number X = ";
	cin >> X;
	cout << endl;
}

					// input array yourself
void input(vector<int>& mas, int& size, int& X)
{
	cout << "Input size of the array: ";
	cin >> size;
	cout << endl;

	mas.resize(size);

	for (int i = 0; i < size; i++)
	{
		cin >> mas[i];
	}
	cout << endl << endl;

	cout << "Input the number X = ";
	cin >> X;
	cout << endl;

}

						// 2 functions for searching the element
void rec(int X, vector<int> mas, int bord_l, int bord_r, int &result)
{
	if (bord_r - bord_l == 1)
	{
		result = (bord_l + bord_r) / 2 + 1;
		return;
	}
	if (mas[(bord_l + bord_r) / 2] > X)
	{
		bord_l = (bord_l + bord_r) / 2;
		rec(X, mas, bord_l, bord_r, result);
	}
	else if (mas[(bord_l + bord_r) / 2] < X)
	{
		bord_r = (bord_l + bord_r) / 2;
		rec(X, mas, bord_l, bord_r, result);
	}
	else
	{
		bord_l++;
		rec(X, mas, bord_l, bord_r, result);
	}

}

int bsearch(vector<int> mas, int size, int X)
{	
	if (X <= mas[size - 1])
		return -1;
	else if (X > mas[0])
		return 0;
	else
	{
		int result = 0;
		rec(X, mas, 0, size, result);
		return result;
	}
}

						// sorts the array
void sort(vector<int> &mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (mas[j] > mas[i])
			{
				int temp = mas[j];
				mas[j] = mas[i];
				mas[i] = temp;
			}
		}
	}
}

int main()
{
	vector<int> mas;
	int size, X;
	int flag = 1;

	while (true)
	{
		cout << "Would you like to input array yourself(1) or get random(0)? ";
		cin >> flag;
		cout << endl;
		try
		{
			if (flag != 1 && flag != 0)
				throw "Exception! Not correct choice. Try again.";
		}
		catch (char *str)
		{
			cout << str << endl << endl;
			continue;
		}
		break;
	}

	switch (flag)
	{
	case 0:
		input_rand(mas, size, X);
		break;
	case 1: 
		input(mas, size, X);
		sort(mas, size);
		for (int i = 0; i < size; i++)
		{
			cout << mas[i] << ' ';
		}
		cout << endl << endl;
		break;
	default:
		break;
	}

	int result =  bsearch(mas, size, X);
	if (result == -1)
		cout << "There's no such an element" << endl;
	else
		cout << "Result: "<< result << endl;
	return 0;
}


