/*חני לוי 326337532
אילה הרצברג 325921005
סדנה c++
תרגיל 9 שאלה 2
*/
#include <iostream>
using namespace std;
#include "SearchTree.h"
#include "Library.h"
int main()
{
	SearchTree<Library> t;
	char tav;
	Library book;
	cout << "enter a-e:" << endl;
	cin >> tav;
	while (tav != 'e')
	{
		switch (tav)
		{
		case 'a':
			cout << "enter a book:"<<endl;
			cin >> book;
			t.add(book);
			cout << endl;
			break;
		case 'b':
			cout << "enter a book:";
			cin >> book;
			cout << endl;
			if (!t.search(book))
			{
				cout << "not exist " << endl;
			}
			else
			{
				t.remove(book);
			}
			break;
		case 'c':
			cout << "enter a book to search ";
			cin >> book;
			if (t.search(book))
				cout << "exist " << endl;
			else
				cout << "not exist " << endl;
			break;
		case 'd':
			t.inOrder();
			break;
		default:
			cout << "error";
			break;
		}
		cout << "enter a-e:" << endl;
		cin >> tav;
	}
	return 0;
}
/*דוגמת הרצה:
enter a-e:
a
enter a book: 2 b b
enter a-e:
a
enter a book: 5 e e
enter a-e:
a
enter a book: 1 a a
enter a-e:
a
enter a book: 4 d d
enter a-e:
a
enter a book: 7 g g
enter a-e:
b
enter a book to remove 5 e e
enter a-e:
d
code: 1 auother: a bookName: a
 code: 2 auother: b bookName: b
 code: 4 auother: d bookName: d
 code: 7 auother: g bookName: g
 enter a-e:
e
*/
