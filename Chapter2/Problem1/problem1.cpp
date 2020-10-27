#include <iostream>
#include <stdlib.h>
#include <time.h>
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

		void AppendNode(int x)
		{
			Node *temp = new Node;
			temp->data = x;
			temp->next = NULL;

			if(head == NULL)
			{
				head = temp;
				count++;
			}
			else
			{
				Node *EndNode = head;
				count++;
				while(EndNode->next != NULL)
				{
					count++;
					EndNode = EndNode->next;
				}
				EndNode->next = temp;
			}
		}

		void RemoveDuplicates()
		{
			Node *CursorNode_1 = head;
			Node *CursorNode_2 = head;
			while(CursorNode_2->next != NULL)
			{
				CursorNode_2 = CursorNode_2->next;
				if(CursorNode_2->next == NULL)
				{
					CursorNode_1 = CursorNode_1->next;
					CursorNode_2 = CursorNode_1;
				}

				if(CursorNode_1->data == CursorNode_2->data)
				{
					while(CursorNode_2->next->next != NULL)
					{
						CursorNode_2->data = CursorNode_2->next->data;
						CursorNode_2 = CursorNode_2->next;
					}
					CursorNode_2->data = CursorNode_2->next->data;
					CursorNode_2->next = NULL;
				}
			}
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

int main()
{
	srand(time(NULL));
	LinkedList TestList;

	TestList.AppendNode(4);
	TestList.AppendNode(3);
	TestList.AppendNode(2);
	TestList.AppendNode(4);
	TestList.AppendNode(5);
	TestList.AppendNode(1);
	TestList.PrintContents();

	TestList.RemoveDuplicates();
	TestList.PrintContents();
	
	return 0;
}
