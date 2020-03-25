#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Node {
public:
	Node *next;
	int data;

	Node(int d) {
		this->data = d;
		this->next = NULL;
	}
};

class LinkedList {
public:
	Node *head;

	LinkedList() {
		this->head = takeInput();
	}
	LinkedList(int p) {
		this->head = NULL;
	}
	Node* takeInput() {
		Node *ans = NULL;
		Node *temp = NULL;
		while (true) {
			int data;
			cin >> data;
			if (data == -1) return temp;
			Node *newNode = new Node(data);
			if (ans == NULL) {
				ans = newNode;
				temp = ans;
			}
			else {
				ans->next = newNode;
				ans =  ans->next;
			}
		}
		return NULL;
	}
	void display() {
		Node *temp = this->head;
		while (temp != NULL) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "End" << endl;
	}
};
void display1(Node *head1) {
	Node *temp = head1;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "End" << endl;
}
LinkedList *merge(LinkedList *list1, LinkedList *list2) {
	Node *head1 = list1->head;
	Node *head2 = list2->head;
	Node *temp = NULL;
	Node *ans = NULL;

	while (head1 != NULL && head2 != NULL) {
		if (head1->data < head2->data) {
			if (ans == NULL) {
				ans = new Node(head1->data);
				temp = ans;
			} else {
				ans->next = new Node(head1->data);
				ans = ans->next;
			}
			head1 = head1->next;
		}
		else {
			if (ans == NULL) {
				ans = new Node(head2->data);
				temp = ans;
			}
			else {
				ans->next = new Node(head2->data);
				ans = ans->next;
			}
			head2 = head2->next;
		}
	}
	while (head1 != NULL) {
		ans->next = new Node(head1->data);
		head1 = head1->next;
		ans = ans->next;
	}
	while (head2 != NULL) {
		ans->next = new Node(head2->data);
		head2 = head2->next;
		ans = ans->next;
	}
	LinkedList *newList = new LinkedList(0);
	newList->head = temp;
	return newList;
}
Node* mergeSortedLinkedList(vector<LinkedList*> &list) {
	int last_idx = list.size() - 1;
	while (last_idx != 0) {
		int left = 0, right = last_idx;
		while (left < right) {
			list[left] = merge(list[left], list[right]);
			left++;
			right--;
			if (left >= right) last_idx = right;
		}
	}
	 // LinkedList *nList = merge(list[0],list[1]);
	return list[0]->head;
}
int main() {
	vector<LinkedList*> list;
	int k;
	cin >> k;
	int temp2 = k;
	while (temp2--) {
		list.push_back(new LinkedList());
	}
	Node *merged = mergeSortedLinkedList(list);
	display1(merged);
	// for(auto v : list){
	// 	v->display();
	// }
}