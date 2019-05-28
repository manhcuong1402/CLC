#pragma one
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node<T>  *next;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};
template <typename T>
class Vector{
private:
    Node<T>  *head;
    Node<T>  *tail;
public:
    Vector(){
        this->head=NULL;
        this->tail=NULL;
    }
    void push_back(T data){
        Node<T> *temp=new Node<T>(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }
    }
    void push_front(T data){
        Node<T>*temp=new Node<T>(data);
        if(head==NULL)
            head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
    }  
    T size(){
        T count=0;
        Node<T>*p=head;
        while(p!=NULL){
            count=count+1;
            p=p->next;    
        }
    return count;
    }
    void pop_back(){
        Node<T> *p=head;
        while(p->next->next!=NULL)
            p=p->next;
        tail=p;
        p->next=NULL;
    }
    void erase(T pos){
        Node<T>*p=head;
        if(pos>size())
            return ;
        else if(pos==1){
            head=head->next;
            delete p;
        }
            
        else{
            
            int k=0;
            while(k!=pos-2 && p->next->next!=NULL){
                
                p=p->next;
                    ++k;
            }
            p->next=p->next->next;
        }
    }
    void find(T temp){
        Node<T> *p=head;
        if(p==NULL)
            cout<<"False"<<endl;
        else{
            int k=1;
            while(p!=NULL){
                k++;
                if(p->data==temp){
                    k=0;
                    break;
                }
                p=p->next;
            }
            if(k==0)
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
    }
    void display()const{
        Node<T> *p=head;
        while(p!=NULL){
            cout<<p->data<<endl;
            p=p->next;
        }
    }
    void resize(T n){
        Node<T>*p=head;
        int k=size();
        if(n>size()){
            while(k!=n){
                Node<T>*temp=new Node<T>(0);
                tail->next=temp;
                tail=temp;
                k++;
            }
        }
        else{
            for(int i=0;i<n-1;i++){
                p=p->next; 
            }
            tail=p;
            p->next=NULL;
        }
    }
    T &operator [](T i){
        Node<T> *p=head;
        int k=0;
        while(k!=i){
            p=p->next;
            k++;
        }
        return p->data;
    }
};
