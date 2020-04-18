
#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
    MyVector A;
    for (int i = 0; i < 5; ++i)
        A.pushBack(i);

    cout << "vector A" << endl
         << "vector elements - ";

    A.Show();

    cout << "operator [3] - " << A[3] << endl
         << endl;

    MyVector B;
    for (int i = 0; i < 6; ++i)
        B.pushBack(i * 2);

    cout << "vector B" << endl
         << "vector elements - ";

    B.Show();

    cout << "operator [5] - " << B[5] << endl
         << endl;

    cout << "insert an element at the end of the vector A" << endl;
    A.insert(3, 150);

    cout << "vector A" << endl
         << "vector elements - ";

    A.Show();

    cout << endl
         << endl;

    cout << "insert vector B in vector A" << endl;
    A.insert(3, B);

    cout << "vector A" << endl
         << "vector elements - ";

    A.Show();

    cout << endl
         << endl;

    cout << "popback element in vector A" << endl;
    A.popBack();

    cout << "vector A" << endl
         << "vector elements - ";

    A.Show();

    cout << endl
         << endl;

    cout << "erase element in vector B" << endl;
    B.erase(2);

    cout << "vector B" << endl
         << "vector elements - ";

    B.Show();

    cout << endl
         << endl;

    cout << "erase element Lenght in vector B" << endl;
    B.erase(1, 3);

    cout << "vector B" << endl
         << "vector elements - ";

    B.Show();

    cout << endl
         << endl;

    cout << "find an element 1 from the beginning in vector A" << endl;
    cout << A.find(1, 1);

    cout << endl
         << endl;
		 
	cout << "find an element 3 from the end in vector A" << endl;
    cout << A.find(3, 0);

    cout << endl
         << endl;

    cout << "resize vector A" << endl;
    A.resize(6, 5);

    cout << "vector A" << endl
         << "vector elements - ";

    A.Show();

    return 0;
}


