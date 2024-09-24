#include "Library.h"
using namespace std;
#include <iostream>

bool Library::operator==(const Library& book) const
{
	if (this->author == book.author && this->code == book.code && this->bookName == book.bookName)
		return true;
	return false;
}

bool Library::operator!=(const Library& book) const
{
	return !(*this == book);
}

bool Library::operator>=(const Library& book) const
{
	return !(*this < book);
}

bool Library::operator<=(const Library& book) const
{
	return !(*this > book);
}

bool Library::operator>(const Library& book) const
{
	if (this->author == book.author)
	{
		if (this->bookName == book.bookName)
			if (this->code < book.code)
				return false;
		if (this->bookName < book.bookName)
			return false;
	}
	if (this->author < book.author)
		return false;
	return true;
}

bool Library::operator<(const Library& book) const
{
	if (*this == book)
		return false;
	return !(*this > book);
}

istream& operator>>(istream& is, Library& book)
{
	is >> book.code;
	is >> book.author;
	is >> book.bookName;
	return is;
}

ostream& operator<<(ostream& os, const Library& book)
{
	os << book.bookName << " " << book.author << " " << book.code;
	//<< endl;
	return os;
}
