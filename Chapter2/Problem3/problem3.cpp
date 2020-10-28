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

void DeleteMiddleNode(Node* node)
{
	if( node != NULL and node->next != NULL)
	{
		Node* TempNode = node->next;
		node->data = TempNode->data;
		node->next = TempNode->next;
	}
}

int main()
{
	srand(time(NULL));
	LinkedList TestList;

	TestList.AppendNode(4);
	TestList.AppendNode(3);
	TestList.AppendNode(2);
	TestList.AppendNode(5);
	TestList.AppendNode(1);
	TestList.PrintContents();

	Node *RandomNode = TestList.GetRandNode();
	cout << "Node to delete: " << RandomNode->data << endl;
	DeleteMiddleNode(RandomNode);

	TestList.PrintContents();

	
	return 0;
}
