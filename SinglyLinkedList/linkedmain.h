#pragma once
class Node {
public:
	int data;
	Node* next;

	Node();
	Node(int i_value, Node* i_next);

};

class List {
private:

	int m_Length;
	Node* m_Head;
	Node* m_Tail;
	Node* m_DummyPointed = new Node(0, nullptr);
	Node* m_Dummy = new Node(0, m_DummyPointed);

	bool didOperationFail(Node* ptr);

	bool isListIntact(List* lst);

	Node* createNode(int value, Node* next);

	bool collisionCheck();

public:
	List();

	~List();

	void add(int value);

	void remove(int value);

	void emptyFunc();

	Node* find(int i_findVal);

	void get(int index);
};