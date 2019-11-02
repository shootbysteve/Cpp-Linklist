// Link

#include"pch.h"
#include <iostream>
#define say(x) std::cout<<x<<std::endl;
#define debugprint(x) std::cout<<"[DEBUG] "<<x<<" [DEBUG]"<<std::endl;

class Node {
public:
	int data;
	Node* next;


	Node() 
		:data(0), next(nullptr)
	{	
	}



};

class List {
private:

	int m_Length;
	Node* m_Head;
	Node* m_Tail;
public:
	List()
		:m_Head(nullptr),m_Tail(nullptr),m_Length(0)
	{
	}

	~List() {
	Node* currNode = m_Head;
		for (int i = 1; i < m_Length + 1; i++) {
			if (currNode == m_Tail) delete currNode;  break;
			Node* temp = currNode;
			currNode = currNode->next;
			delete temp;
		}
	}


	void createNode(int& value) {
		Node* temp = new Node;
		temp->data = value;
		temp->next = NULL;
		m_Length++;
		if (m_Head == NULL) {
			m_Head = temp;
			m_Tail = temp;
		}
		else {
			m_Tail->next = temp;
			m_Tail = temp;
		}

	}
	

	void displayList() {
		Node* currNode;
		currNode = m_Head;
		std::cout << "Displaying List at Memory " << this << " |List Size" << m_Length << "\n||||||||||||||||" << std::endl;
		
		for (int i = 1; i < m_Length + 1; i++) {
			say("DATA")
				say(currNode->data)
				say("MEMORY")
				say(currNode)
				say("POINTS TO")
				say(currNode->next)
				say("-----------------")
				currNode = currNode->next;
		}
	}


	Node* findByValue(int value) {
		Node* currNode = m_Head;

		for (int i = 1; i < m_Length + 1;i++) {

			if (currNode->data == value) {
				return currNode; break;
			}

			else {
				currNode = currNode->next;
			}

		}

		// If i return null and tries to acces the pointer program crashes.
		//How could this be fixed ? switch case ?
		return NULL;
	}



	int length() const {
		return m_Length;
	}

	void removeHead() {
		
		Node *temp = m_Head;
		m_Head = temp->next;
		delete temp;
		m_Length--;
	}

	void removeTail() {
		Node *currNode = m_Head;
		Node *prevNode = nullptr;
		

		for (int i = 1; i < m_Length + 1; i++) {
			if (currNode->next == nullptr) {
			
				prevNode->next = nullptr;
				delete currNode;
				m_Length--;
				break;
			}

			prevNode = currNode;
			currNode = currNode->next;
		}

	}

	void removeByPtr(Node* DelNode) {
		Node* currNode = m_Head;
		Node* prevNode = nullptr;

		for (int i = 1; i < m_Length + 1; i++) {
			
			if (currNode == DelNode) {
				prevNode->next = DelNode->next;
				delete DelNode;
				m_Length--;
				break;
			}

			prevNode = currNode;
			currNode = currNode->next;
		}

	}

	void addByPtr(Node* AddNode,const int& value) {
		Node *currNode = m_Head;
		Node *prevNode = nullptr;
		Node* temp = new Node;
		temp->data = value;
		for (int i = 1; i < m_Length + 1; i++) {
			
			if (currNode == AddNode) {
			   
				temp->next = currNode->next;
				currNode->next = temp;
				m_Length++;
				break;
			}

			prevNode = currNode;
			currNode = currNode->next;
		}

	}

	Node* lastNode() {
		return m_Tail;
	}

	Node* firstNode() {
		return m_Head;
	}


	void merge(List* mergelist) {
		if (mergelist == NULL) return ;
		m_Tail->next = mergelist->firstNode();
	}

};




int main()
{
	List mylist;
	for (int i = 1; i < 11; i++) {
		mylist.createNode(i);

	}
	
	mylist.displayList();



	mylist.addByPtr(mylist.findByValue(2),10);
	

		mylist.removeHead();
		mylist.removeTail();
		mylist.displayList();
	



	std::cin.get();
}	

