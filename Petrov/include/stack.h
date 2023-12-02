#pragma once
#include <iostream>

const int MaxStackSize = 100;

template<class T>
class Stack
{
private:
	T* pMem;
	T* end;
	int sz;
public:
	Stack(int sz = 5) {
		if ((sz < 1) || (sz > MaxStackSize))
			throw std::out_of_range("Stack size not allowed");
		this->sz = sz;
		this->pMem = new T[sz];
		this->end = this->pMem;
	}

	Stack(T* arr, int sz) {
		if ((sz < 1) || (sz > MaxStackSize))
			throw std::out_of_range("Stack size not allowed");
		this->sz = sz;
		this->pMem = new T[sz];
		this->end = this->pMem;

		for (size_t i = 0; i < sz; i++) {
			this->pMem[i] = arr[i];
			end++;
		}
	}

	~Stack() {
		delete[] this->pMem;
	}

	Stack(const Stack<T>& a) {
		this->sz = a.sz;
		this->pMem = new T[sz];
		for (int i = 0; i < a.end - a.pMem; i++) {
			this->pMem[i] = a.pMem[i];
		}
		end = this->pMem + (a.end - a.pMem);
	}

	void push(T elem) {
		if (this->end - this->pMem == sz) {
			T* tmp = new T[sz * 2];
			for (int i = 0; i < sz; i++) {
				tmp[i] = this->pMem[i];
			}
			this->sz *= 2;
			this->end = tmp + (this->end - this->pMem);
			delete[] this->pMem;
			this->pMem = tmp;
		}
		*end = elem;
		end++;
	}

	const T& top() {
		if (isEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		T a = *(end - 1);
		a;
		return *(end-1);
	}

	void pop() {
		if (isEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		this->end--;
	}
	bool isEmpty() {
		return this->pMem == this->end;
	}

	int size() {
		return this->sz;
	}

	int count() {
		return this->end - this->pMem;
	}

	bool operator==(Stack<T>& a) {
		if (this->count() != a.count()) {
			return false;
		}

		if (this->pMem == a.pMem) {
			return true;
		}

		for (size_t i = 0; i < this->count(); i++) {
			if (this->pMem[i] != a.pMem[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator!=(const Stack<T>& a) {
		return !(*this == a);
	}
};
