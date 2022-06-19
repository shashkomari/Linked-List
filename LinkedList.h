#pragma once

#include <iostream>
#include <string>

template<class T>
class LinkedList
{
public:
	class Iterator;
	struct Node;

	LinkedList();
	~LinkedList();

	void add(T);
	LinkedList<T>::Iterator getIterator();
	bool removeAll(T);
	void show();

private:
	Node* head = nullptr;
};

template<class T>
class LinkedList<T>::Iterator
{
	friend LinkedList;
public:
	T getValue();
	void next();

	void operator++();
	operator bool();
	T operator*();
private:
	Iterator(Node*);

	Node* current;
};

template<class T>
struct LinkedList<T>::Node {
	T data;
	Node* next = nullptr;
};

template<class T>
LinkedList<T>::LinkedList() {
}

template<class T>
LinkedList<T>::~LinkedList() {
}

template<class T>
void LinkedList<T>::add(T data) {
	Node* new_el = new Node;
	new_el->data = data;
	new_el->next = head;
	head = new_el;
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::getIterator() {
	LinkedList<T>::Iterator i(head);
	return i;
}

template<class T>
LinkedList<T>::Iterator::Iterator(Node* head) : current(head) {};

template<class T>
bool LinkedList<T>::removeAll(T data_for_removing) {
	Node* n = head;
	bool isElemDeleted = false;
	while (n->next != nullptr) {
		if (n == head) {
			if (n->data == data_for_removing) {
				head = n->next;
				delete n;
				n = head;

				isElemDeleted = true;
				continue;
			}
		}

		if (n->next->data == data_for_removing) {
			Node* save = n->next->next;
			delete n->next;
			n->next = save;

			isElemDeleted = true;
			continue;
		}

		n = n->next;
	}
	return isElemDeleted;
}

template<class T>
void LinkedList<T>::show() {
	for (auto it = LinkedList<T>::getIterator(); it; ++it) {
		std::cout << *it << std::endl;
	}
}

template<class T>
T LinkedList<T>::Iterator::getValue() {
	return current->data;
}

template<class T>
void LinkedList<T>::Iterator::next() {
	current = current->next;
}

template<class T>
void LinkedList<T>::Iterator::operator++() {
	next();
}

template<class T>
LinkedList<T>::Iterator::operator bool() {
	return current;
}

template<class T>
T LinkedList<T>::Iterator::operator*() {
	return getValue();
}
