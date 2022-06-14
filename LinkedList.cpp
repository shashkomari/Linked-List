#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
}

LinkedList::~LinkedList() {
}

void LinkedList::add(std::string data) {
	Node* new_el = new Node;
	new_el->data = data;
	new_el->next = head;
	head = new_el;
}

LinkedList::Iterator LinkedList::getIterator() {
	Iterator i(head);
	return i;
}

LinkedList::Iterator::Iterator(Node* head) : current(head) {};

bool LinkedList::removeAll(std::string data_for_removing) {
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

void LinkedList::show() {
	for (auto it = this->getIterator(); it; ++it) {
		std::cout << *it << std::endl;
	}
}

std::string LinkedList::Iterator::getValue() {
	return current->data;
}

void LinkedList::Iterator::next() {
	current = current->next;
}

void LinkedList::Iterator::operator++() {
	next();
}

LinkedList::Iterator::operator bool() {
	return current;
}

std::string LinkedList::Iterator::operator*() {
	return getValue();
}