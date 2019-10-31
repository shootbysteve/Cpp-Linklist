// Link


#include "pch.h"
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
	Node* Head;
	Node* Tail;
public:
	List()
		:Head(nullptr),Tail(nullptr),m_Length(0)
	{
	}

	~List() {
	Node* CurrNode = Head;
		for (int i = 1; i < m_Length + 1; i++) {
			if (i == m_Length) delete CurrNode;  break;
			Node * temp = CurrNode;
			Head = temp->next;
			delete temp;
		}
	}


	void CreateNode(int& value) {
		Node* temp = new Node;
		temp->data = value;
		temp->next = NULL;
		m_Length++;
		if (Head == NULL) {
			Head = temp;
			Tail = temp;
		}
		else {
			Tail->next = temp;
			Tail = temp;
		}

	}
	

	void DisplayList() {
		Node* CurrNode;
		CurrNode = Head;
		std::cout << "Displaying List at Memory " << this << " |List Size" << m_Length << "\n||||||||||||||||" << std::endl;
		
		for (int i = 1; i < m_Length + 1; i++) {
			say("DATA")
				say(CurrNode->data)
				say("MEMORY")
				say(CurrNode)
				say("POINTS TO")
				say(CurrNode->next)
				say("-----------------")
				CurrNode = CurrNode->next;
		}
	}


	Node* FindByValue(int value) {
		Node* CurrNode = Head;

		for (int i = 1; i < m_Length + 1;i++) {

			if (CurrNode->data == value) {
				return CurrNode; break;
			}

			else {
				CurrNode = CurrNode->next;
			}

		}

		// If i return null and tries to acces the pointer program crashes.
		//How could this be fixed ? switch case ?
		return NULL;
	}



	int length() const {
		return m_Length;
	}

	void RemoveHead() {
		
		Node *temp = Head;
		Head = temp->next;
		delete temp;
		m_Length--;
	}

	void RemoveTail() {
		Node *CurrNode = Head;
		Node *PrevNode = nullptr;
		

		for (int i = 1; i < m_Length + 1; i++) {
			if (CurrNode->next == nullptr) {
			
				PrevNode->next = nullptr;
				delete CurrNode;
				m_Length--;
				break;
			}

			PrevNode = CurrNode;
			CurrNode = CurrNode->next;
		}

	}

	void RemoveByPtr(Node* DelNode) {
		Node* CurrNode = Head;
		Node* PrevNode = nullptr;

		for (int i = 1; i < m_Length + 1; i++) {
			
			if (CurrNode == DelNode) {
				PrevNode->next = DelNode->next;
				delete DelNode;
				m_Length--;
				break;
			}

			PrevNode = CurrNode;
			CurrNode = CurrNode->next;
		}

	}

	void AddByPtr(Node* AddNode,const int& value) {
		Node *CurrNode = Head;
		Node *PrevNode = nullptr;
		Node* temp = new Node;
		temp->data = value;
		for (int i = 1; i < m_Length + 1; i++) {
			
			if (CurrNode == AddNode) {
			   
				temp->next = CurrNode->next;
				CurrNode->next = temp;
				m_Length++;
				break;
			}

			PrevNode = CurrNode;
			CurrNode = CurrNode->next;
		}

	}

	Node* LastNode() {
		return Tail;
	}

	Node* FirstNode() {
		return Head;
	}


	void Merge(List* mergelist) {
		Tail->next = mergelist->FirstNode();
	}

};




int main()
{
	List mylist;
	for (int i = 1; i < 11; i++) {
		mylist.CreateNode(i);

	}
	
	mylist.DisplayList();



	mylist.AddByPtr(mylist.FindByValue(2),10);
	

		mylist.RemoveHead();
		mylist.RemoveTail();
		mylist.DisplayList();
	



	std::cin.get();
}	

