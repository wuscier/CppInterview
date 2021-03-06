// ReverseSingleLinkedList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

struct Node
{
	int data;
	Node* next;
};

void PrintSingleLinkedList(Node* head) {

	while (head != NULL)
	{
		std::cout << head->data << std::endl;

		head = head->next;
	}
}


Node*  ReverseSingleLinkedList(Node* head) {

	if (head == NULL)
	{
		return head;
	}

	Node* p = head;
	Node* q = head;

	head = NULL;

	do
	{
		q = p->next;
		p->next = head;

		head = p;
		p = q;
	} while (q != NULL);


	return head;
}



int main()
{
	int input = 0;


	Node* head = new Node();

	if (head == NULL)
	{
		std::cout << "申请内存空间失败！" << std::endl;
	}

	head->next = NULL;



	while (true)
	{
		std::cin >> input;

		if (input == 0)
		{
			break;
		}

		Node* newNode = new Node();
		newNode->data = input;
		newNode->next = head->next;
		head->next = newNode;
	}

	PrintSingleLinkedList(head);

	Node* reversedNodeList = ReverseSingleLinkedList(head);

	PrintSingleLinkedList(reversedNodeList);

	
	system("pause");
	

    return 0;
}


