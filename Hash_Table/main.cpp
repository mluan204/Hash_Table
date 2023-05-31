#include <iostream>
using namespace std;
#define M 7

struct Node
{
	int key;
	Node* next;
};

typedef Node* HashTable[M];

void InitHashTable(HashTable& HT)
{
	for (int i = 0; i < M; i++)
		HT[i] = NULL;
}

int Hash(int k)
{
	return k % M;
}

void AddTail(Node*& l, int k)
{
    Node* newNode = new Node{ k, NULL };
    if (l == NULL)
    {
        l = newNode;
    }
    else
    {
        Node* p = l;
        while (p != NULL && p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}

void InsertNode(HashTable& HT, int k)
{
	int i = Hash(k);
	AddTail(HT[i], k);
}

void Traverse(Node* p)
{
    while (p != NULL)
    {
        cout << p->key << " ";
        p = p->next;
    }
    cout << endl;
}

void TraverseHashTable(HashTable HT)
{
    for (int i = 0; i < M; i++)
    {
        cout << "Chi so " << i << ": ";
        Traverse(HT[i]);
    }
}


int main()
{
    int k;
    HashTable mHT;
    InitHashTable(mHT);
    for (int i = 0; i < M; i++)
    {
        cin >> k;
        InsertNode(mHT, k);       
    }
    TraverseHashTable(mHT);
    return 0;
}