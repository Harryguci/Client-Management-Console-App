#ifndef NODE_H_
#define NODE_H_
//#include <iostream>

template<class T>
class node {
	T elem; // Value of node
	node<T>* prev, * next;
public:
	node(T x, node<T>* L = 0, node<T>* R = 0);
	// Get value
	T& getelem();
	// Get previous node (of this)
	node<T>*& getprev();
	node<T>*& getnext();
	void setelem(T x);
	void setprev(node<T>* p = nullptr);
	void setnext(node<T>* p = nullptr);
};

//
//		NODE Methods:
//
template<class T>
node<T>::node<T>(T x, node<T>* L, node<T>* R) {
	elem = x; prev = L; next = R;
}
// Get value
template<class T>
T& node<T>::getelem() {
	if (this == NULL) {
		T temp;
		return temp;
	}

	return elem;
}

// Get previous node (of this)
template<class T>
node<T>*& node<T>::getprev() {
	return prev;
}

template<class T>
node<T>*& node<T>::getnext() {
	return next;
}

template<class T>
void node<T>::setelem(T x) {
	elem = x;
}

template<class T>
void node<T>::setprev(node<T>* p) {
	prev = p;
}

template<class T>
void node<T>::setnext(node<T>* p) {
	next = p;
}

#endif // !NODE_H_
