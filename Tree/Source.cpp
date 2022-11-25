#include<iostream>
#include"Binary_Tree.h"
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("file.txt");
	Binary_Tree<char> Tree;
	Tree.setroot(' ');
	string code = "";
	char c;
	Binary_Tree<char> subtree;
	subtree = Tree;
	int j = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, code);
			c = code[0];
			code = code.substr(2);
			subtree = Tree;
			j = 0;
			while (code[j] != '\0')
			{
				if (code[j] == '.')
				{
					subtree = subtree.get_left_subtree();
				}
				else if (code[j] == '-')
				{
					subtree = subtree.get_right_subtree();
				}
				j++;
			}
				subtree.setroot(c);


		}
	}
	else
	{
		cout << "Unable to read file\n";
	}
	cout << "\t\t\t**** Caution only use alphabets *****\t\t\t\n\n\n";
	cout << "Enter a message to encode\n";
	string input;
	getline(cin, input);
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] += 32;
		}
		i++;
	}
	char ch;
	i = 0;
	string encoded = "";
	while (input[i] != '\0')
	{
		fin.seekg(0);
		ch = input[i];
		if (input[i] == ' ')
		{
			encoded += ' ';
		}
		else
		{
			while (!fin.eof())
			{

				getline(fin, code);
				if (code[0] == ch)
				{
					encoded += code.substr(2);
					encoded += ',';
					break;
				}
			}
		}
		i++;
	}

	cout << "Coded message \n";
	cout << encoded;
	code = "";
	i = 0;
	j = 0;
	input = "";
	while (encoded[i] != '\0')
	{
		if (encoded[i] == ',')
		{
			subtree = Tree;
			j = 0;
			while (code[j] != '\0')
			{
				if (code[j] == '.')
				{
					subtree = subtree.get_left_subtree();
				}
				else if (code[j] == '-')
				{
					subtree = subtree.get_right_subtree();
				}
				j++;
			}
			code = "";
			if (!subtree.is_null())
			{
				input += subtree.getdata();
			}
		}
		else if(encoded[i]==' ')
		{
			input += ' ';
		}
		else
		{
			code += encoded[i];
		}
		i++;
	}
	cout << "\nDecoded message\n";
	cout << input;
	return 0;
}