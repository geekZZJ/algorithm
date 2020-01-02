#include"List.h"
#include"Node.h"
#include<iostream>
using namespace std;

List::List(){
	m_pList=new Node;
	m_pList->data=0;
	m_pList->next=NULL;
	m_iLength=0;
}

bool List::ListEmpty(){
	if (m_iLength==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int List::ListLength(){
	return m_iLength;
}

void List::ClearList(){
	Node *currentNode=m_pList->next;
	while (currentNode!=NULL)
	{
		Node *temp=currentNode->next;
		delete currentNode;
		currentNode=temp;
	}
	m_pList->next=NULL;
}

List::`List(){
	ClearList();
	delete m_pList;
	m_pList=NULL;
}

bool List::ListInsertHead(Node *pNode){
	Node *temp=m_pList->next;
	Node *newNode=new Node;
	if (newNode==NULL)
	{
		return false;
	}
	newNode->data=pNode->data;
	m_pList->next=newNode;
	newNOde->next=temp;
	m_iLength++;
	return true;
}
bool List::ListInsertTail(Node *pNode){
	Node *currentNode=m_pList;
	while (currentNode->next!=NULL)
	{
		currentNode=currentNode->next
	}
	Node *newNode=new Node;
	if(newNode==NULL){
		return false;
	}
	newNode->data=pNode->data;
	newNode->next=NULL;
	currentNode->next=newNode;
	m_iLength++;
	return true;
}
bool List::ListInsert(int i,Node  *pNode){
	if (i<0||i>m_iLength)
	{
		return false;
	}
	Node *currentNode=m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode=currentNode->next;
	}
	Node *newNode=new Node;
	if(newNode==NULL){
		return false;
	}
	newNode->data=pNode->data;
	newNode->next=currentNode->next;
	currentNode->next=newNode;
	return true;
}
bool List::ListDelete(int i,Node *pNode){
	if (i<0||i>=m_iLength)
	{
		return false;
	}
	Node *currentNode=m_pList;
	Node *currentNodeBefore=NULL;
	for (int k = 0; k  <=i; k ++)
	{
		currentNodeBefore=currentNode;
		currentNode=currentNode->next;
	}
	currentNodeBefore->next=currentNode->next;
	pNode->data=current->data;
	delete currentNode;
	currentNode=NULL;
	m_iLength--;
	return true;
}
bool List::GetElem(int i,Node *pNode){
	if (i<0||i>=m_iLength)
	{
		return false;
	}
	Node *currentNode=m_pList;
	Node *currentNodeBefore=NULL;
	for (int k = 0; k  <=i; k ++)
	{
		currentNodeBefore=currentNode;
		currentNode=currentNode->next;
	}
	pNode->data=currentNode->data;
	return true;
}
int List::LocateElem(Node *pNode){
	Node *currentNode=m_pList;
	int count=0;
	while (currentNode->next!=NULL)
	{
		currentNode=currentNode->next;
		if (currentNode->data==pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;
}
bool List::PriorElem(Node *pCurrentNode,Node *pPreNode){
	Node *currentNode=m_pList;
	Node *tempNode=NULL;
	int count=0;
	while (currentNode->next!=NULL)
	{
		tempNode=currentNode;
		currentNode=currentNode->next;
		if (currentNode->data==pNode->data)
		{
			if (tempNode==m_pList)
			{
				return false;
			}
			pPreNode->data=tempNode->data;
			return true;
		}	
	}
	return false;
}
bool List::NextElem(Node *pCurrentNode,Node *pNextNode){
	Node *current=m_pList;
	while (currentNode->next!=NULL)
	{
		currentNode=currentNode->next;
		if (currentNode->data==pNode->data)
		{
			if (currentNode->next==NULL)
			{
				return false;
			}
			pNextNode->data=currentNode->next->data;
			return true;
		}	
	}
	return false;
}
void List::ListTraverse(){
	Node *currentNode=m_pList;
	while (currentNode->next!=NULL)
	{
		currentNode=currentNode->next;
		currentNode->printNode();
	}
}

int main(void){
	Node node1();
	node1.data=3;
	List *pList=new List();
	pList->ListInsertHead(&node1);
	pList->ListTraverse();
	delete pList;
	pList=NULL;
	system("pause");
	return 0;
}