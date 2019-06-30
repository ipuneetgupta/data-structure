// DoublyLinkedList
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *next;
	node *prev;
	node(int d){
		this->data=d;
		this->next=NULL;
		this->prev=NULL;
	}
};
class DLL{
	public :
	node *head;
	DLL(node *temp){
		this->head=temp;
	}
	void PushFront(int data){
		node *newNode=new node(data);
		if(this->head==NULL) this->head=newNode;
		else{
			newNode->prev=NULL;
			newNode->next=(head);
			(this->head)->prev=newNode;
			head=newNode;
		}
	}
	node* LastNode(){
		node *temp=this->head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		return temp;
	}
	void PushEnd(int data){
		if(this->head==NULL)this->PushFront(data);
		else{
			node *lastnode=this->LastNode();
			node *newNode=new node(data);
			newNode->prev=lastnode;
			newNode->next=NULL;
			lastnode->next=newNode;
		}
		return;
	}
	node* getNode(int idx){
		if(idx<0&&this->head==NULL){
			return NULL;
		}
		node *temp=this->head;
		for(int j=1;j<idx;j++){
			temp=temp->next;
		}
		return temp;
	}
	void PushIthIndex(int data,int idx,bool left=true){
		if(idx==1) this->PushFront(data);
		else {
			node* IthNode=this->getNode(idx);
			node *newNode=new node(data);
			if(left){
				newNode->next=IthNode;
				newNode->prev=IthNode->prev;
				IthNode->prev->next=newNode;
				IthNode->prev=newNode;
			}else{
				newNode->prev=IthNode;
				newNode->next=IthNode->next;
				IthNode->next->prev=newNode;
				IthNode->next=newNode;
			}
		}
		return;
	}
	void RemoveAtIth(int idx){
		node*del=this->getNode(idx);
		if(del==head){
			del->next->prev=NULL;
			del=del->next;
		}else{
			del->next->prev=del->prev;
			del->prev->next=del->next;
		}
		delete del;
	}
	node* MidNode(){
		node *slow=this->head;
		node *fast=this->head;
		while(fast->next!=NULL&&fast->next->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		return slow;
	}
	node* KthNodeFromEnd(int k){
		if(this->head==NULL){
			cout<<"Linked List is Empty"<<endl;
			return NULL;
		}
		node *slow=this->head;
		node *fast=this->head;
		for(int i=1;i<=k&&fast!=NULL;i++){
			fast=fast->next;
		}
		if(fast!=NULL){
			while(fast!=NULL){
				slow=slow->next;
				fast=fast->next;
			}
		}
		return slow;
	}
	void KthSwapfromSAE(int k){
		node* KthBegin=this->getNode(k);
		node* KthEnd=this->KthNodeFromEnd(k);
		if(KthBegin==NULL||KthEnd==NULL) {
			cout<<"SwapIsNotPossible";
		}
		node *prevkthB=KthBegin->prev;
		node *prevKthE=KthEnd->prev;
		if(KthBegin->next!=NULL)
			KthBegin->next->prev=KthEnd;
		if(KthEnd->next!=NULL)
			KthEnd->next->prev=KthBegin;
		if(prevKthE!=NULL)
			prevKthE->next=KthBegin;

		if (prevkthB!=NULL)
			prevkthB->next=KthEnd;

		// KthBegin->prev=prevKthE;
		// KthEnd->prev=prevkthB;

		node *temp=KthBegin->next;
		KthBegin->next=KthEnd->next;
		KthEnd->next=temp;

        temp=KthBegin->prev;
        KthBegin->prev=KthEnd->prev;
        KthEnd->prev=temp;

		if(KthBegin->prev==NULL) this->head=KthBegin;
		else if(KthEnd->prev==NULL) this->head=KthEnd;
		return ;
	}
	void Display(){
		node *temp=this->head;
		while(temp->next!=NULL){
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		cout<<temp->data<<endl;
		while(temp->prev!=NULL){
			cout<<temp->data<<" -> ";
			temp=temp->prev;
		}
		cout<<temp->data<<endl;
		return;
	}
};
int main(){
	DLL list(NULL);
	for(int i=1;i<=5;i++){
		list.PushEnd(i*10);
	}
	cout<<"Left addition at 4th index::"<<endl;
	list.PushIthIndex(35,4);
	list.Display();
	cout<<"Right addition at 5th index::"<<endl;
	list.PushIthIndex(25,5,false);
	list.Display();
	cout<<"Remove at 2nd index::"<<endl;
	list.RemoveAtIth(2);
	list.Display();
	cout<<"The Mid Node of this data::"<<list.MidNode()->data<<endl;
	cout<<"The Kth Node From the End::"<<list.KthNodeFromEnd(1)->data<<endl;
	cout<<"KthSwapfrom begin and End::"<<endl;
	list.KthSwapfromSAE(1);
	list.Display();
}