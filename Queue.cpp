#include <iostream>
#include <fstream>

using namespace std;

int*stack = new int[10];

struct Node{
    int data;
    Node *next;
    Node(int data):data(data),next(nullptr){}

};

class Queue{
    Node*front;
    Node* rear;
    
Public:

    Queue(){
        front = rear = nullptr;
    }
    void push(int x){
        Node *temp = new Node(x);
        if(!front){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }


    int pop(){
        return 0; 
    }


    void print(){
        Node* travel = front;
        while(travel){
            cout<<travel ->data<<"->";
            if(travel->next)
            travel = travel ->next;
        }
    }
};

int main(){
    Queue queue;

    queue(5);
    queue(3);
    queue(2);

}