//
//#include <iostream>
//using namespace std;
//#include "SearchTree.h"
//enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
//int main()
//{
//	SearchTree<int> T1;
//	cout << "enter 10 numbers:\n";
//	int x, y, z;
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> x;
//		T1.add(x);
//	}
//	cout << "inorder: ";
//	T1.inOrder();
//	cout << "\nenter 0-8:\n";
//	cin >> x;
//	while (x != END)
//	{
//		switch (x)
//		{
//		case ADD: cout << "enter a number: ";
//			cin >> y;
//			T1.add(y);
//			cout << "after adding " << y << ": ";
//			T1.inOrder();
//			cout << endl;
//			break;
//		case SEARCH: cout << "enter a number: ";
//			cin >> y;
//			if (T1.search(y))
//				cout << "exist" << endl;
//			else
//				cout << "does not exist" << endl;
//			break;
//		case REMOVE:cout << "enter a number: ";
//			cin >> y;
//			try
//			{
//				T1.remove(y);
//				cout << "after removing " << y << ": ";
//				T1.inOrder();
//				cout << endl;
//			}
//			catch (const char* str)
//			{
//				cout << str << endl;
//			}
//			break;
//		case BREADTHSCAN: cout << "breadth first scan: ";
//			T1.breadthScan();
//			cout << endl;
//			break;
//		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
//			break;
//		case SUCCESSOR:cout << "enter a number: ";
//			cin >> y;
//			try
//			{
//				z = T1.successor(y);
//				cout << "successor of " << y << " is: " << z << endl;
//
//			}
//			catch (const char* str)
//			{
//				cout << str << endl;
//			}
//			break;
//		case DELETEDUP: cout << "after deleting duplicates: ";
//			T1.deleteDuplicates();
//			T1.inOrder();
//			cout << endl;
//			break;
//		case REFLECT:T1.reflect();
//			cout << "reflected tree: ";
//			T1.inOrder();
//			T1.reflect();
//			cout << endl;
//			break;
//		}
//		cout << "enter 0-8:\n";
//		cin >> x;
//	}
//	return 0;
//}
///*
//דוגמת הרצה:
//enter 10 numbers:
//2 5 6 78 78 78 79 79 90 100
//inorder: 2 5 6 78 78 78 79 79 90 100
//enter 0-8:
//1
//enter a number: 23
//after adding 23: 2 5 6 23 78 78 78 79 79 90 100
//enter 0-8:
//3
//enter a number: 5
//after removing 5: 2 6 23 78 78 78 79 79 90 100
//enter 0-8:
//4
//breadth first scan: 2 6 78 78 79 78 79 90 23 100
//enter 0-8:
//5
//height of tree: 5
//enter 0-8:
//6
//enter a number: 100
//no successor
//enter 0-8:
//6
//enter a number: 78
//successor of 78 is: 79
//enter 0-8:
//7
//after deleting duplicates: 2 6 78 23 79 90 100
//enter 0-8:
//8
//reflected tree: 100 90 79 23 78 6 2
//enter 0-8:
//0
//*/
//
//
