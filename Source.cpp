/*
 Module: Source.cpp
 Date: 21-11-2022
 Author: Yashkumar Patel
*/
#include<iostream>
#include"Binary_Tree.h"
#include<fstream>
#include<string>
using namespace std;
int main()
{

	
	ifstream fin;// creating a file stream object
	fin.open("file.txt");//opening file
	Binary_Tree<char> Tree;									//a character tree is initialized
	Tree.setroot(' ');
	string code = "";
	char c;
	Binary_Tree<char> subtree;
	subtree = Tree;
	int j = 0;
	/*Takes the input from the file
	 and then traverses the input.
	Character by character.
	The Huffman tree is bulid according to the code*/
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, code);								//the input is taken from the user's file.
			c = code[0];
			code = code.substr(2);
			subtree = Tree;
			j = 0;
			while (code[j] != '\0')
			{
				if (code[j] == '.')
				{
					subtree = subtree.get_left_subtree(); //getting the left child
				}
				else if (code[j] == '-')
				{
					subtree = subtree.get_right_subtree(); //getting the right child
				}
				j++;
			}
				subtree.setroot(c);//seting rood value accordance to code


		}
	}
	else
	{
		cout << "Unable to read file\n";
	}
	cout << "\t\t\t**** Caution only use alphabets *****\t\t\t\n\n\n";
	cout << "Enter a message to encode\n";					//The input is taken from the console.
	string input;
	getline(cin, input);
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 'A' && input[i] <= 'Z')				//Traversing the input.
		{
			input[i] += 32;//convarting upper to lower case
		}
		i++;
	}
	char ch;
	i = 0;

	/*Takes input from user
	the message to be encoded is stored in string
	encoding the message according to file code*/

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

	/*Decoding the encoded message using the Huffman Tree algorithm.*/

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
					subtree = subtree.get_left_subtree();	//getting left child
				}
				else if (code[j] == '-')
				{
					subtree = subtree.get_right_subtree();	//getting right child
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
			input += ' ';									//filling the decoded string
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
