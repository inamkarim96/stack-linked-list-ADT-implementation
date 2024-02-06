
#include <iostream>
#include "class-stack.h"

using namespace std;

int main()
{
	stack<int> s(10), a;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.display(); cout << endl;
	cout << "Top=" << s.top() << " Size=" << s.size() << endl;

	s.pop();
	s.pop();

	s.display(); cout << endl;
	cout << "Top=" << s.top() << " Size=" << s.size() << endl;

	try
	{

		s.push(6);
		s.push(7);
		s.push(8);
		s.push(9);
		s.push(10);
		s.push(11);
		s.push(12);
		s.push(13);
		s.push(14);
		s.push(15);

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	s.display(); cout << endl;
	cout << "Top=" << s.top() << " Size=" << s.size() << endl;

	a.operator=(s);

	a.display(); cout << endl;
	cout << "Top=" << a.top() << " Size=" << a.size() << endl;

	a.reverse();

	a.display(); cout << endl;
	cout << "Top=" << a.top() << " Size=" << a.size() << endl;

}
