#include "MyBoolVector.h"
#include <algorithm>
#include <cstdlib>
#include <cassert>

MyBoolVector::MyBoolVector() {
	//postcondition: v_capacity = 10이고 v_used = 0 인 불벡터 생성 

	data = new value_type[10];
	v_capacity = 10;
	v_used = 0;
}

MyBoolVector::MyBoolVector(const MyBoolVector& source)
{	//precondition: 불벡터 자체를 넣음
	//postcondition: source과 같은 공간, 사용공간, 값을 복사한 불벡터

	data = new value_type[source.v_capacity];
	v_capacity = source.v_capacity;
	v_used = source.v_used;
	copy(source.data, source.data + v_used, data);
}

MyBoolVector::~MyBoolVector()
{
	//postcondition: 불벡터를 삭제

	delete[] data;
}

void MyBoolVector::pop_back() {
	//postcondition: 

	data[v_used-1] = "NULL";
	v_used--;
}

void MyBoolVector::push_back(bool x)
{
	//precondition: 불값(true or false)
	//postcondition: v_used 다음 값에 입력받은 x값을 삽입

	if (v_capacity <= v_used)
	{
		reserve(v_used * 2);
	}
	data[v_used] = x;
	v_used++;
}

size_t MyBoolVector::capacity() const
{
	//postcondition: v_capacity를 리턴

	return v_capacity;
}

size_t MyBoolVector::size() const
{
	//postcondition: v_used를 리턴

	return v_used;
}

void MyBoolVector::reserve(size_t new_capacity)
{
	value_type* larger_array;
	if (new_capacity == v_capacity)
		return;
	if (new_capacity < v_used)
	{
		new_capacity = v_used;	
	}
	larger_array = new value_type[new_capacity];
	copy(data, data + v_used, larger_array);
	delete[] data;
	data = larger_array;
	v_capacity = new_capacity;
}

bool MyBoolVector::is_empty() const
{
	if (v_used == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MyBoolVector::clear()
{
	for (int i = 0; i < v_used; i++)
	{
		data[i] = "NULL";
	}
	v_used = 0;
}

bool MyBoolVector::operator = (const MyBoolVector& source)
{
	if (data == source.data)
		return data;
	if (v_capacity != source.v_capacity)
	{
		delete[] data;
		data = new value_type[source.v_capacity];
		v_capacity = source.v_capacity;
	}
	v_used = source.v_used;
	copy(source.data, source.data + v_used, data);
	return data;
}

bool MyBoolVector::operator+=(const MyBoolVector& addend)
{
	if (size() + addend.size() > v_capacity)
	{
		reserve(v_used + addend.v_used);
	}

	copy(addend.data, addend.data + addend.v_used, data + v_used);
	v_used += addend.v_used;

	return data;
}

bool MyBoolVector::operator[](size_t num)
{
	assert(num < v_used);
	return data[num];
}

bool MyBoolVector::operator-()
{
	for (int i = 0; i < v_used; i++)
	{
		if (data[i] == true)
		{
			data[i] = false;
		}
		else
		{
			data[i] = "true";
		}
	}

	return data;
}

bool MyBoolVector::operator+(const MyBoolVector& v)
{
	/*if (v.v_used != v_used)
	{
		perror("two operands is not the same");
		exit(-1);
	}*/

	assert(v.v_used == v_used);

	for (int i = 0; i < v_used; i++)
	{
		if (v.data[i] == data[i])
		{
			data[i] = false;
		}
		else
		{
			data[i] = true;
		}
	}

	return data;
}

bool MyBoolVector::operator==(const MyBoolVector& v)
{
	int count = 0;
	if (v.v_used == v_used)
	{
		for (int i = 0; i < v_used; i++)
		{
			if (v.data[i] == data[i])
			{
				count += 1;
			}
		}

		if (count == v_used)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool MyBoolVector::operator!=(const MyBoolVector& v)
{
	if ((v.data == data) == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}