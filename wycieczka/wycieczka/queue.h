#pragma once
#include "Node.h"
template <class T>
class queue {
	
public:
	node<T> *head;
	node<T> *last;

	queue() : head(NULL), last(NULL) {}

	~queue() {
		if (!empty()) {
			node<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	bool empty() {
		if (head == NULL) return 1;
		else return 0;
	}

	node<T> *addNewElement(T data) {
		node<T> *tmp = new node<T>;
		tmp->data = data;
		tmp->next = NULL;
		return tmp;
	}

	void push(T data) {
		if (!empty()) {
			node<T> *tmp = addNewElement(data);
			last->next = tmp;
			last = tmp;
		}
		else {
			node<T> *tmp = addNewElement(data);
			head = tmp;
			last = tmp;
		}
	}

	void pop() {
		if (!empty()) {
			node<T> *tmp = head;
			head = head->next;
		}
	}

	T front() {
		if (!empty())
			return head->data;
		else return NULL;
	}
	
};
