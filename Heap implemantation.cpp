#include <iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;
template<class T>
class Heap
{
public :
    vector<T> arr;
    bool isMin;
    Heap()
    {   this->isMin=true;
        //this->Heap(true);
    }
    Heap(bool isMin)
    {
        this->isMin=isMin;
    }
    int size()
    {
        return this->arr.size();
    }
    bool isEmpty()
    {
        return this->arr.size()==0;
    }
    T getHP(int i)
    {
        return this->arr[0];
    }
    void swap1(int a,int b){
    T temp=this->arr[a];
    this->arr[a]=this->arr[b];
    this->arr[b]=temp;
    }
    void upheapify(int ci)
    {
        int pi=ci-1/2;
        if(this->isLarger(pi,ci))
        {
            swap1(pi,ci);
            upheapify(pi);
        }
    }
    bool isLarger(int i,int j)
    {
        T p=this->arr[i];
        T c=this->arr[j];
        if(this->isMin)
            return p-c>0;
        else
            return c-p<0;
    }
    void add(T value)
    {
        this->arr.push_back(value);
        upheapify(this->size()-1);
    }
     void downheapify(int i){
     int lci=2*i+1;
     int rci=2*i+2;
     int smaller=i;
     if(lci>this.size()-1&&isLarger(smaller,lci)){
        smaller=lci;
     }
     if(rci>this.size()-1&&isLarger((smaller,rci))){
        smaller=rci;
     }
     if(smaller!=i){
        this.swap1(i,smaller);
        downheapify(smaller);
     }
     }
    T Remove()
    {
        T rVal=this->arr[0];
        this->arr[0]=this->arr[this->size()-1];
        this->arr.erase(arr.begin()+this->size()-1);
        this.downheapify(0);
        return rVal;
    }
    void display(){
     this->display(0);
    }
    void display(int pi){
        int lci=2*pi+1;
        int rci=2*pi+2;
        string str="";
        if(lci<this->size()){
            str=str+to_string(this->arr[lci])+" => ";
        }else str=str+" END=> ";
         str=str+to_string(this->arr[pi]);
        if(rci<this->size()){
            str=str+" <= "+to_string(this->arr[rci]);
        }else str=str+" <=END ";
        cout<<str<<endl;
        if(lci<this->size()) display(lci);
        if(rci<this->size())display(rci);
    }

};

int main()
{
    Heap<int> heap;
    heap.add(50);
    heap.add(27);
    heap.add(78);
    heap.add(5);
    heap.add(80);
    heap.display();

}
