#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
	private:
		Node *head;
		int count;
	public:
		LinkedList()
		{
			head = NULL;
			count = 0;
		}

		void ReverseList()
		{
			Node* current = head;
			Node* prev = NULL;
			Node* next = NULL;

			while(current != NULL)
			{
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			head = prev;
		}

		void AppendNode(int x)
		{
			Node *temp = new Node;
			temp->data = x;
			temp->next = NULL;

			if(head == NULL)
			{
				head = temp;
			}
			else
			{
				Node *EndNode = head;
				while(EndNode->next != NULL)
				{
					EndNode = EndNode->next;
				}
				EndNode->next = temp;
			}

			count++;
		}

		Node* GetRandNode()
		{
			Node *temp = head;
			int RandomNodeIndex = (rand() % (this->count - 2)) + 1;
			//cout << "this->count = " << this->count << endl;
			//cout << "RandomNodeIndex: " << RandomNodeIndex << endl;

			for(int i = 0; i < RandomNodeIndex; i++)
			{
				temp = temp->next;
			}

			return temp;
		}

		Node* GetHeadNode()
		{
			return head;
		}

		void PrintContents()
		{
			char ListContents[2*count];
			Node *CursorNode = head;
			int index = 0;
			while(CursorNode != NULL)
			{
				ListContents[index] = CursorNode->data + '0';
				CursorNode = CursorNode->next;
				index++;
				ListContents[index] = '-';
				index++;
			}
			ListContents[index] = '\0';
			cout << ListContents << endl;
		}

		int GetLength()
		{
			count = 0;
			Node* CursorNode = head;
			while(CursorNode != NULL)
			{
				CursorNode=CursorNode->next;
				count++;
			}
			return count;
		}

};

Node* FindIntersect(LinkedList list1, LinkedList list2)
{
	int List1Len = list1.GetLength();
	int List2Len = list2.GetLength();
	int SizeDiff = List1Len - List2Len;

	Node* CursorNode_1 = list1.GetHeadNode();
	Node* CursorNode_2 = list2.GetHeadNode();

	if(SizeDiff > 0)
	{
		for(int i = 0; i < SizeDiff; i++)
		{
			CursorNode_1 = CursorNode_1->next;
		}
	}
	else if(SizeDiff < 0)
	{
		for(int i = 0; i < (-1*SizeDiff); i++)
		{
			CursorNode_2 = CursorNode_2->next;
		}
	}


	while(CursorNode_1 != CursorNode_2)
	{
		CursorNode_1 = CursorNode_1->next;
		CursorNode_2 = CursorNode_2->next;
	}
	return CursorNode_1;
}

int main()
{
	LinkedList TestList_1;
	LinkedList TestList_2;

	TestList_1.AppendNode(7);
	TestList_1.AppendNode(1);
	TestList_1.AppendNode(7);

	Node* CursorNode = TestList_1.GetHeadNode();
	for(int i = 0; i < 1; i++)
	{
		CursorNode = CursorNode->next;
	}


	TestList_2.AppendNode(5);

	Node* CursorNode1 = TestList_2.GetHeadNode();
	CursorNode1->next = CursorNode;


	TestList_1.PrintContents();
	cout << "-----" << endl;
	TestList_2.PrintContents();

	Node* result = FindIntersect(TestList_1,TestList_2);
	cout << result->data << endl;

	//cout << TestList.GetHeadNode()->data << endl;

	
	return 0;
}
