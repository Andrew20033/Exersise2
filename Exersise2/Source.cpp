#include <iostream>
#include <string>
using namespace std;

class BaseException
{
protected:
	string text;

public:
	virtual string what() = 0;
};
class ArithmeticException :public BaseException
{
public:
	ArithmeticException()
	{
		text = "Error. Arithmetic Exception.";
	}

	ArithmeticException(string _text) { text = _text; }
	string what() { return text; }
};

class DivideByZero final :public ArithmeticException
{
public:
	
	DivideByZero() :ArithmeticException()
	{
		text = "Divide by zero."; 
	}
	DivideByZero(string _text) :ArithmeticException(_text)
	{
	}

	string what()
	{
		return text;
	}
};

class NegativeIndex final :public BaseException
{
public:
	
	NegativeIndex(string _text = "Error. Negative Index.") { text = _text; }
	string what() { return text; }
};

void DemoExceptions1()
{
	int a[10];
	int index;

	for (int i = 0; i < 10; i++)
		a[i] = i * i;
	cout << "Input index: " << endl;
	cin >> index;

	if (index < 0)
		throw NegativeIndex(); 
	cout << "a[" << index << "] = " << a[index] << endl;
}

void DemoExceptions2()
{
	int a, b, c;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	if (b == 0)
		throw DivideByZero("Divide by 0.");
	cout << "a / b = " << (double)a / b << endl;
}
void main()
{
	try
	{
		DemoExceptions1();
		DemoExceptions2(); 
		cout << "OK!" << endl;
	}
	catch (NegativeIndex e)
	{
		cout << e.what() << endl;
	}
	catch (DivideByZero e)
	{
		cout << e.what() << endl;
	}
}