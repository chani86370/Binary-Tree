#pragma once
#include <string>
using namespace std;
class Library
{
	int code;
	string author;
	string bookName;
public:
	Library(int code = 0, string author = "", string bookName = "")
	{
		this->code = code;
		this->author = author;
		this->bookName = bookName;
	}
	bool operator== (const Library& book) const;
	bool operator!= (const Library& book) const;
	bool operator>(const Library& book) const;
	bool operator< (const Library& book) const;
	bool operator>= (const Library& book) const;
	bool operator<= (const Library& book) const;
	friend istream& operator>>(istream& is, Library& book);
	friend ostream& operator<<(ostream& os, const Library& book);

};


