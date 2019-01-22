#include <iostream>
#include<cstring>
using namespace std;
template<typename T>
class Node{
 string key;
 T value;
 Node * next;
 //constructor
 public:
 Node(string key,T value){
  this->key=key;
  this->value=value;
  this->next=NULL;
 }
 //destructor
 ~Node(){
   if(next!=NULL){
    delete next;
   }
 }
};
template<typename T>
class HashTable{
 Node<T> **table;
int ts;
int cs;
//hashfuntion
int hashfun(string key){
  int ans=0;
  int p=1;
  for(int i=0;key[i]!='\0';i++){
    ans+=key[i]*p;
    ans%=ts;
    p=(p*37)%ts;
  }
  return ans%37;
}
void rehash(){
    //O_T=oldTable
    Node<T> **O_T=table;
    int O_ts=ts;
    cs=0;
    ts=2*ts;
    table= new Node<T>*[ts];
    for(int i=0;i<O_ts;i++){
        Node<T> *temp=O_T[i];
        while(temp!=NULL){
            insert(temp->key,temp->value);
            temp=temp->next;
        }
        if(O_T[i]!=NULL){
            delete O_T[i];
        }
    }
    delete [] O_T;
}
public:
    HashTable(int d=10){
        cs=0;
        ts=d;
        table=new Node<T>*[ts];
        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }
    }
    void insert(string key,T value){
      int idx=hashfun(key);
      Node<T> *node=new Node<T>(key,value);
      node->next=table[idx];
      table[idx]=node;
      cs++;

      float l_f=cs/(float)(ts);
      if(l_f>0.7){
        rehash();
      }
    }
    T *search(string key){
     int i=hashfun(key);
    Node<T>* temp=table[i];
     while(temp!=NULL){
        if(temp->key==key){
            return&(temp->value);
        }
        temp=temp->next;
     }
     return NULL;
    }
    T &operator[](string key){
     T *found=search(key);
     if(found==NULL){
        T garbage;
        insert(key,garbage);
     }
     found=search(key);
     return (*found);
    }
    void display(){
    for(int i=0;i<ts;i++){
        Node<T> *temp=table[i];
        cout<<"Head"<<i<<" = ";
        while(temp!=NULL){
            cout<<temp->key<<"-->";
            temp=temp->next;
        }
        cout<<endl;
    }
    }
};
 int main(){
     return 0;
 }
