#pragma once
#include <iostream>

const int MaxStackSize = 100;

template<class T>
class Stack
{
private:
	T* pMem;
	T* end;
	int size;
public:
	TStack(int size) {
		this->size = size;
		if ((size < 1) || (size > MaxStackSize))
			throw size;
		this->pMem = new T[size];
	}

	~TStack() {
		delete[] this->pMem;
	}

	Stack(const Stack<T>& a) {
		this->size = a.size;
		this->pMem = new T[size];
		for (int i = 0; i < a.end - a.pMem; i++) {
			this->pMem[i] = a.pMem[i];
		}
		end = this->pMem + (a.end - a.pMem);
	}

	void push(T elem) {
		if (this->end - this->pMem == size) {
			T* tmp = new T[size * 2];
			this->size *= 2;
			for (int i = 0; i < size; i++) {
				tmp[i] = this->pMem[i];
			}
			this->end = tmp + (this->end - this->pMem);
			delete[] this->pMem;
			this->pMem = tmp;
		}
		*end = elem;
		end++;
	}

	const T& top() {
		if (isEmpty()) {
			throw std::out_of_range("Stack is empty!");
		}
		return *(end - 1);
	}

	void pop() {
		if (isEmpty()) {
			throw std::out_of_range("Stack is empty!");
		}
		this->end--;
	}
	bool isEmpty() {
		this->pMem == this->end;
	}

	int size() {
		return size;
	}

	int count() {
		return this->end - this->pMem;
	}

	bool operator==(const Stack<T>& a) {
		if (this->count != a.count) {
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

	friend std::ostream& operator<< (std::ostream& ostr, const Stack<T>& a);
	//friend std::istream& operator>> (std::istream& istr, const Stack<T>& a);
};

template<class T>
std::ostream& operator<< (std::ostream& ostr, const Stack<T>& a) {
	for (size_t i = 0; i < a.count(); i++) {
		ostr << a.pMem[i] << " ";
	}
	return ostr;
}

//template<class T>
//std::istream& operator>>(std::istream& istr, const Stack<T>& a) {
//	for (size_t i = 0; i < a.sz; i++)
//		istr >> a.pMem[i]; 
//	return istr;
//}