// HashMap
#include<iostream>
using namespace std;
template <class T>
class node{
public:
	string key;
    T value;
    node<T>* next;
    node(string key,T value){
    	this->key=key;
    	this->value=value;
    	    }
};
template<class T>
class HashMap{
public:
   node<T> **Bucket;
   int ts;    //bucket size
   int cs;   //total element in bucket
   int hashfunction(string key){
   	int hashcode=0;
   	int factor=1;
   	for(int i=0;i<key.size();i++){
   		hashcode+=key[i]*factor;
   		hashcode%=ts;
   		factor=factor*37;
   		factor%=ts;
   	}
   	return hashcode%ts;
   }
   void rehash(){
   	node<T>**  oldBucket=Bucket;
   	int oldts=ts;
   	cs=0;
   	ts=2*ts;
   	Bucket=new node<T>*[ts];
   	for(int i=0;i<oldts;i++){
   		node<T> *temp=oldBucket[i];
   		while(temp!=NULL){
   			insert(temp->key,temp->value);
   			temp=temp->next;
   		}
   		delete oldBucket[i];
   	}
   	delete oldBucket;
   	return; 
   }
   HashMap(int ts=10){
      this->ts=ts;
      this->cs=0;
      Bucket=new node<T>*[ts];
      for(int i=0;i<ts;i++) Bucket[i]=NULL;
   }
  void insert(string key,T value){
  	int index=hashfunction(key);

  	node<T> *newNode=new node<T>(key,value);

  	newNode->next=Bucket[index];
  	Bucket[index]=newNode;
  	cs++;
  	float LoadFactor=(cs/1.0*ts);
    if(LoadFactor<0.7){
    	rehash();
    }
  }
  T* search(string key){
  	int index=hashfunction(key);
  	node<T>* temp=Bucket[index];
  	while(temp!=NULL){
  		if(temp->key==key){
           return &(temp->value);
  		}
  		temp=temp->next;
  	}
  	return NULL;
  }
  //operator overload
  T& operator[](string key){
      T * temp=search(key);
      if(temp==NULL){  //key not found - insert
          T value;  //garbage value at &value
           insert(key,value);
           temp=search(key);
           return *temp;
      }
      else{         //key found
          return *temp;
      }
  }
  void print(){
  	for(int i=0;i<ts;i++){
  		cout<<i<<"-->";
  		node<T>*temp= Bucket[i];
  		while(temp!=NULL){
  			cout<<"("<<temp->key<<","<<temp->value<<")"<<"->";
  			temp=temp->next;
  		}
  		cout<<"END"<<endl;
  	}
  	return;
  }
   void remove(string key){
  	int index=hashfunction(key);
  	node<T>* temp=Bucket[index];
  	node<T>* curr=temp;
  	while(temp!=NULL){
  		if(temp->key==key){
  			if(curr==temp){
  				Bucket[index]=NULL;
  				return;
  			}
          curr->next=temp->next;
          return;
  		}
  		else{
  		curr=temp;
  		temp=temp->next;
  	}
  	}
  	cout<<"Key Does'nt exist";
  	return ;
  }
};

int main(){
	HashMap<int> h;
	h.insert("puneet",100);
	h.insert("sumit",70);
	h.insert("preeti",20);
	h["puneet"]=500;
	h["mohan"]=80;
	h["Vaibav"]=0;
	h.insert("hero",40);;
	h.insert("puneet gupta",6);
	h.insert("pu",80);
    h.remove("puneet");
    h.remove("sumit");
	//cout<<*h.search("puneet")<<endl;
	h.print();
}