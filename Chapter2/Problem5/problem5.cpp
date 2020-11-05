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

LinkedList AddLists(LinkedList list1, LinkedList list2)
{
	LinkedList result;
	Node* CursorNode_1 = list1.GetHeadNode();
	Node* CursorNode_2 = list2.GetHeadNode();

	int CarryOver = 0;
	int NodeSum = 0;

	while(CursorNode_1 != NULL)
	{
		NodeSum = CursorNode_1->data + CursorNode_2->data + CarryOver;
		if(NodeSum >= 10)
		{
			NodeSum = NodeSum - 10;
			CarryOver = 1;
		}
		else
		{
			CarryOver = 0;
		}
		result.AppendNode(NodeSum);
		CursorNode_1 = CursorNode_1->next;
		CursorNode_2 = CursorNode_2->next;
	}
	return result;

}

int main()
{
	srand(time(NULL));
	LinkedList TestList_1;
	LinkedList TestList_2;

	TestList_1.AppendNode(7);
	TestList_1.AppendNode(1);
	TestList_1.AppendNode(6);

	TestList_2.AppendNode(5);
	TestList_2.AppendNode(9);
	TestList_2.AppendNode(2);

	TestList_1.PrintContents();
	TestList_2.PrintContents();

	cout << "-----" << endl;
	LinkedList ResultList;
	ResultList = AddLists(TestList_1, TestList_2);

	ResultList.PrintContents();

	//cout << TestList.GetHeadNode()->data << endl;

	
	return 0;
}
