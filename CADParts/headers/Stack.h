#pragma once
using namespace std;

//Stack of type variable T

template <class T>
class Stack {
private:
	T data[100];
	int top_;

public:

	Stack() : top_(-1) {}
	~Stack() {}

	void push(const T& item)
	{
		data[++top_] = item;
	}

	void pop()
	{
		top_--;
	}

	const T& top() const
	{
		return data[top_];
	}

	bool empty() const
	{
		return top_ == -1;
	}

};

