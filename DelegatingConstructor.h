#pragma once

#include <iostream>

class A
{
private:
	int m_nX;

public:
	A(int x = 0) : m_nX{ x }
	{
		std::cout << "m_nX : " << m_nX << std::endl;
	}
	~A()
	{
		std::cout << "Destructor A" << std::endl;
	}
};

class B : public A
{
private:
	int m_nY;

public:
	B(int y = 0, int x = 0) : m_nY{ y }, A(x)
	{
		std::cout << "m_nY : " << m_nY << std::endl;
	}
	~B()
	{
		std::cout << "Destructor B" << std::endl;
	}
};

class C : public B
{
private:
	int m_nZ;

public:
	C(int z = 0, int y = 0, int x = 0) : m_nZ{ z }, B(y, x)
	{
		std::cout << "m_nZ : " << m_nZ << std::endl;
	}
	~C()
	{
		std::cout << "Destructor C" << std::endl;
	}
};

void DelegatingConstructor()
{
	A a{};
	B b{};
	C c{};

	A a1{ 1 };
	B b1{ 2 };
	C c1{ 3 };
}