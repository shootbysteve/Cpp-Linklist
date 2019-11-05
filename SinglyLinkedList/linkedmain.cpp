#include<vector>
#include <iostream>
#include"linkedmain.h"

#define say(x) std::cout<<x<<std::endl;
#define debugprint(x) std::cout<<"[DEBUG] "<<x<<" [DEBUG]"<<std::endl;

// NODE CLASS

	Node::Node()
		:data(0), next(nullptr)
	{
	}

	Node::Node(int i_value, Node* i_next)
		:data(i_value), next(i_next)
	{
	}

//NODE CLASS ENDS



//LIST CLASS



	bool List::didOperationFail(Node* ptr) {
		if (ptr->next == m_DummyPointed)
			return true;
		else
			return false;
	}

	bool List::isListIntact(List* lst)
	{
		return 1;
		//check if length is true
		//check if nodes are null
	}

	Node* List::createNode(int value, Node* next) {
		Node* temp = new Node(value, next);
		return temp;
	}

	/*
	std::vector<int>* List::castToVector() {
		
			Node* iterNode = m_Head;
			std::vector<int> tempVec = new std::vector<int>(m_Length);


			for (int i = 0; i < m_Length; i++)
			{
				tempVec-
				tempVec[i] = iterNode->data;
				iterNode = iterNode->next;
			}
			WORK IN PROGRESS
		
		
	}

	*/

	bool List::collisionCheck() {

		Node* iterNode = m_Head;

		for (int i = 0; i < m_Length; i++)
		{

			for (int i = 0; i < m_Length; i++) {
				Node* findNode = m_Head;
				if ((iterNode->data == findNode->data) && (iterNode != findNode))
					return true;
				findNode = findNode->next;
			}

			iterNode = iterNode->next;

		}

		return false;
	}

	//move find to public
	Node* List::find(int i_findVal) {
		if (!isListIntact(this)) return m_Dummy;

		Node* iterNode = m_Head;
		for (int i = 0; i < m_Length; ++i)
		{
			if (iterNode->data == i_findVal) return iterNode;
			iterNode = iterNode->next;
		}

		return m_Dummy;
	}



	List::List()
		:m_Head(nullptr), m_Tail(nullptr), m_Length(0)
	{}

	List::~List()
	{
		Node* iterNode = m_Head;
		for (int i = 0; i < m_Length; ++i)
		{
			if (iterNode == NULL) return;

			Node* temp = iterNode;
			iterNode = iterNode->next;
			delete temp;
		}

		delete m_Dummy;
		delete m_DummyPointed;
	}


	void List::add(int value) {

		if (m_Head == nullptr) {
			m_Head = createNode(value, nullptr);
			m_Tail = m_Head;
			m_Length++;
		}

		else {
			Node* newNode = createNode(value, nullptr);
			m_Tail->next = newNode;
			m_Tail = newNode;
			m_Length++;
		}
	}

	void List::remove(int value)
	{
		if (collisionCheck())
		{

		}

		else {

		}

	}
	//void ptrRemove

	
	
	
	
	int main() {
		List a;
		a.emptyFunc();
	}