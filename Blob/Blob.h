#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T> //模板类的声明和函数体必须写在同一个文件中（cpp或h文件皆可），否则实例化时会找不到函数体（因为不同的T对应不同的函数体）
class Blob
{
public:
	typedef T value_type;//value_type即迭代器所指对象的型别，如果要与stl库兼容则必须有该定义
	typedef typename vector<T>::size_type size_type;//类似vector<T>这样带有类型参数的依赖名在typedef时必须带typename
	Blob();
	Blob(initializer_list<T> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(move(t)); }//C++11特有的移动语义
	void pop_back();
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string& msg) const;
};

template <typename T>
Blob<T>::Blob() :data(make_shared<vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(make_shared<vector<T>>(il)) { }

template <typename T>
void Blob<T>::check(size_type i, const string& msg) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}