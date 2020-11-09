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
			return count;
		}

};

bool IsEqual(LinkedList a, LinkedList b)
{
	Node* CursorNode_1 = a.GetHeadNode();
	Node* CursorNode_2 = b.GetHeadNode();
	while(CursorNode_1 != NULL)
	{
		if(CursorNode_1->data != CursorNode_2->data)
		{
			return false;
		}
		CursorNode_1 = CursorNode_1->next;
		CursorNode_2 = CursorNode_2->next;
	}
	return true;
}

bool IsPalindrome(LinkedList list)
{
	LinkedList OriginalList = list;
	LinkedList ReversedList = list;
	ReversedList.ReverseList();
	return IsEqual(OriginalList,ReversedList);
}

int main()
{
	srand(time(NULL));
	LinkedList TestList_1;
	LinkedList TestList_2;

	TestList_1.AppendNode(7);
	TestList_1.AppendNode(1);
	TestList_1.AppendNode(7);


	TestList_1.PrintContents();

	cout << "-----" << endl;
	cout << IsPalindrome(TestList_1) << endl;

	//cout << TestList.GetHeadNode()->data << endl;

	
	return 0;
}
