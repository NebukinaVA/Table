#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iterator>


template <class T>
class HashTable
{
	struct Pair
	{
		unsigned int key;
		T data;
		Pair(T data_ = {}, unsigned int key_ = 100)
		{
			data = data_;
			key = key_;
		}
	};
	size_t size;
	unsigned int num;
	std::vector<std::list<Pair>> hashtable;
	unsigned int HashFunction(unsigned int k)
	{
		return (k % num);
	}
	typename std::list<Pair>::iterator find_key(unsigned int k)
	{
		unsigned int hashed = HashFunction(k);
		std::list<Pair>::iterator it;
		for (it = hashtable[hashed].begin(); it != hashtable[hashed].end(); ++it)
		{
			if (it->key == k) return it;
		}
		return it;
	}
public:
	HashTable(unsigned int num_ = 7)
	{
		size = 0;
		num = num_;
		hashtable.resize(num);
	}
	HashTable(const HashTable& ht)
	{
		hashtable = ht.hashtable;
		size = ht.size;
		num = ht.num;
	}
	void insert(unsigned int k, const T& elem)
	{
		unsigned int i = HashFunction(k);
		std::list<Pair>::iterator it = find_key(k);
		if (it != (hashtable[i].end())) throw;
		Pair temp(elem, k);
		hashtable[i].push_back(temp);
		size++;
	}
	void remove(unsigned int k)
	{
		unsigned int i = HashFunction(k);
		std::list<Pair>::iterator it = find_key(k);
		if (it == (hashtable[i].end())) throw;
		hashtable[i].erase(it);
		size--;
	}
	T find(unsigned int k)
	{
		unsigned int i = HashFunction(k);
		std::list<Pair>::iterator it = find_key(k);
		if (it == (hashtable[i].end())) throw;
		return (it->data);
	}
	size_t get_size() { return size; }
	void clear() { hashtable.clear(); }
	bool empty()
	{
		if (size == 0) return true;
		return false;
	}
};