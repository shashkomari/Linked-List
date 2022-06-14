#pragma once

#include <string>

class LinkedList
{
public:
	class Iterator;
	struct Node;

	LinkedList();
	~LinkedList();

	void add(std::string);
	LinkedList::Iterator getIterator();
	bool removeAll(std::string);
	void show();

private:
	Node* head = nullptr;
};

class LinkedList::Iterator
{
	friend LinkedList;
public:
	std::string getValue();
	void next();

	void operator++();
	operator bool();
	std::string operator*();
private:
	Iterator(Node*);

	Node* current;
};

struct LinkedList::Node {
	std::string data;
	Node* next = nullptr;
};
