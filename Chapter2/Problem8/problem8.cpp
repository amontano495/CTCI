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

Node* LoopDetector(LinkedList list)
{
	Node* SlowCursorNode = list.GetHeadNode();
	Node* FastCursorNode = SlowCursorNode->next->next;

	while(SlowCursorNode != FastCursorNode)
	{
		SlowCursorNode = SlowCursorNode->next;
		FastCursorNode = FastCursorNode->next->next;
	}
	SlowCursorNode = list.GetHeadNode();
	while(SlowCursorNode->next != FastCursorNode->next)
	{
		SlowCursorNode = SlowCursorNode->next;
		FastCursorNode = FastCursorNode->next;
	}
	return SlowCursorNode;
}

int main()
{
	LinkedList TestList_1;

	TestList_1.AppendNode(1);
	TestList_1.AppendNode(2);
	TestList_1.AppendNode(3);
	TestList_1.AppendNode(4);
	TestList_1.AppendNode(5);

	Node* HEAD = TestList_1.GetHeadNode();
	HEAD->next->next->next->next = HEAD->next->next;
	Node* result = LoopDetector(TestList_1);
	cout << result->data << endl;
	
	return 0;
}
