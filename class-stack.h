#pragma once

#include "node.h"
using namespace std;

template<typename t>

class stack
{
private:
	node<t>* TOP;
	int SIZE;
	int n;

public:

	stack(const int s = 100)
	{
		SIZE = s;
		n = 0;
		TOP = nullptr;
	}

	~stack()
	{
		clear();
	}

	void push(const t& val)
	{
		if (full())
		{
			throw("Stack overflow!");
		}
		node<t>* temp;
		temp = new node<t>;
		temp->data = val;
		temp->next = TOP;
		TOP = temp;
		n++;

	}

	void pop()
	{
		if (empty())
		{
			throw("Stack under flow!");
		}
		node<t>* temp;
		temp = TOP;
		TOP = TOP->next;
		delete temp;
		n--;
	}

	t top() const
	{
		if (empty())
		{
			throw("Stack underflow!");
		}
		return TOP->data;
	}

	bool full() const
	{
		return n == SIZE;
	}

	bool empty() const {
		return n == 0;
	}

	void clear()
	{
		while (!empty())
		{
			pop();
		}

	}

	int size() const
	{
		return n;
	}

	void display()
	{
		node<t>* temp;
		temp = TOP;

		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void operator=(const stack<t>& rhs)
	{
		this->clear();
		node<t>* temp;
		temp = rhs.TOP;

		stack<t> stemp;

		while (temp != nullptr)
		{
			stemp.push(temp->data);
			temp = temp->next;
		}

		while (!stemp.empty())
		{
			this->push(stemp.TOP->data);
			stemp.pop();
		}

	}

	void reverse()
	{
		stack<t> temp;

		while (!this->empty())
		{
			temp.push(this->TOP->data);
			this->pop();
		}

		this->operator=(temp);
		temp.clear();

	}



};
