#pragma once
#include <iostream>
#include <vector>

template <class T> 
class Table {
public:
	virtual void insert(unsigned int k, const T& elem) = 0;
	virtual void remove(unsigned int k) = 0;
	virtual T find(unsigned int k) = 0;
	virtual size_t get_size() = 0;
	virtual void clear() = 0;
	virtual bool empty() = 0;
};

template <class T> 
class ArrayTable : public Table<T> 
{
protected:
	std::vector<unsigned int> key;
	std::vector<T> data;
	size_t size;
public:
	size_t get_size() { return size; }
};


// UNORDERED TABLE

template <class T>
class UnorderedTable : public ArrayTable<T>
{
	int find_key(unsigned int k)
	{
		int i = 0;
		while (i < size)
		{
			if (key[i] == k) return i;
			i++;
		}
		return -1;
	}
public:
	UnorderedTable()
	{
		size = 0;
	}
	UnorderedTable(const UnorderedTable& ut)
	{
		size = ut.size;
		key = ut.key;
		data = ut.data;
	}
	void insert(unsigned int k, const T& elem)
	{
		int i = find_key(k);
		if (i != -1) throw "Element already exists";
		key.push_back(k);
		data.push_back(elem);
		size++;
	}
	void remove(unsigned int k)
	{
		int i = find_key(k);
		if (i == -1) throw "Nothing found";
		key[i] = key[size - 1];
		data[i] = data[size - 1];
		key.pop_back();
		data.pop_back();
		size--;
	}
	T find(unsigned int k)
	{
		int i = find_key(k);
		if (i == -1) throw "Nothing found";
		return data[i];
	}
	void clear()
	{
		key.clear();
		data.clear();
		size = 0;
	}
	bool empty() 
	{
		if (size == 0) return true;
		return false;
	}
};


// ORDERED TABLE

template <class T>
class OrderedTable : public ArrayTable<T>
{
	int find_key(unsigned int k)
	{
		int i;
		int first = 0;
		int last = size - 1;
		while (first <= last)
		{
			i = (first + last) / 2;
			if (key[i] == k)
				return i;
			if (key[i] > k)
				last = i - 1;
			else
				first = i + 1;
		}
		return -1;
	}
public:
	OrderedTable()
	{
		size = 0;
	}
	OrderedTable(const OrderedTable& ot)
	{
		size = ot.size;
		key = ot.key;
		data = ot.data;
	}
	void insert(unsigned int k, const T& elem)
	{
		int i = find_key(k);
		if (i != -1) throw "Element already exists";
		if (empty())
		{
			key.push_back(k);
			data.push_back(elem);
		}
		else
		{
			int first = 0;
			int last = size - 1;
			while (first <= last)
			{
				i = (first + last) / 2;
				if (key[i] > k)
					last = i - 1;
				else
					first = i + 1;
			}
			i = first;
			key.insert(key.begin() + i, k);
			data.insert(data.begin() + i, elem);
		}
		size++;
	}
	void remove(unsigned int k)
	{
		int i = find_key(k);
		if (i == -1) throw "Nothing found";
		key.erase(key.begin() + i);
		data.erase(data.begin() + i);
		size--;
	}
	T find(unsigned int k)
	{
		int i = find_key(k);
		if (i == -1) throw "Nothing found";
		return data[i];
	}
	void clear()
	{
		key.clear();
		data.clear();
		size = 0;
	}
	bool empty()
	{
		if (size == 0) return true;
		return false;
	}
	friend std::ostream& operator<<(std::ostream &out, OrderedTable &ot)
	{
		if (ot.size == 0)
			out << "Table is empty";
		else
		{
			out << "KEY" << "         " << "DATA\n" << std::endl;
			for (int i = 0; i < ot.size; i++)
				out << ot.key[i] << "         " << ot.data[i] << std::endl;
		}
		return out;
	}
};
