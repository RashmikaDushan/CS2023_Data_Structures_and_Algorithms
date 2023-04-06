#include <iostream>

using namespace std;

class Stack_Array{                   //Stack using array
private:
    int *arr;
    int top;
    int size;
public:
    Stack_Array(int n) {
        arr = new int[n];
        size = n;
        top = -1;
    }
    void push(int value){
        top ++;
        if(top>(size-1)){
            cout<<"Stack overflow"<<endl;
        }
        else{
            arr[top]=value;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow"<<endl;
        }
        else{
            int value = arr[top];
            top--;
            return value;
        }
    }

    int stackTop(){
        if(isEmpty()){
            cout<<"Stack underflow";
        }
        else{
            return arr[top];
        }
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    bool isEmpty(){
        if(top<0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top==(size-1)){
            return true;
        }
        else{
            return false;
        }
    }
};

struct Node {
    int value;
    Node* next;
};


class Stack_List {                 //Stack using array
private:
    Node* head;
    Node* top;
    int size;
    int top_number;

public:
    Stack_List(int n) {
        top = nullptr;
        top_number=-1;
        head = nullptr;
        size = n;
    }

    void push(int val) {
        if (top_number >= (size - 1)) {
            cout << "Stack overflow";
        }
        else {
            Node* node = new Node;
            node->value = val;
            node->next = nullptr;
            top_number++;
            if (head == nullptr) {
                head = node;
                top = node;
            }
            else {
                top->next = node;
                top = node;
            }
        }
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
        }
        else{
            Node* current_node = head;
            while (current_node->next != top){
                current_node = current_node->next;
            }
            top = current_node;
            int temp = current_node->next->value;
            delete current_node->next;
            current_node->next = nullptr;
            top_number--;
            return temp;
        }
    }

    bool isEmpty() {
        if(top_number<0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top_number==(size-1)){
            return true;
        }
        else{
            return false;
        }
    }

    void display() {
        Node* current_node = head;
        while (current_node != nullptr) {
            cout << current_node->value << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};

int main() {

    auto start_time = chrono::high_resolution_clock::now();
    //array
    Stack_Array stack_Array(10);
    stack_Array.push(8);
    stack_Array.push(10);
    stack_Array.push(5);
    stack_Array.push(11);
    stack_Array.push(15);
    stack_Array.push(23);
    stack_Array.push(6);
    stack_Array.push(18);
    stack_Array.push(20);
    stack_Array.push(17);
    stack_Array.display();
    stack_Array.pop();
    stack_Array.pop();
    stack_Array.pop();
    stack_Array.pop();
    stack_Array.pop();
    stack_Array.display();
    stack_Array.push(4);
    stack_Array.push(30);
    stack_Array.push(3);
    stack_Array.push(1);
    stack_Array.display();

    auto end_time = chrono::high_resolution_clock::now();
    auto time_taken = chrono::duration_cast<chrono::microseconds >(end_time - start_time).count();
    cout << "Time taken for the array: " << time_taken << " microseconds" << endl<<endl<<endl;


    auto start_timel = chrono::high_resolution_clock::now();

    //Linked list
    Stack_List stack_List(10);
    stack_List.push(8);
    stack_List.push(10);
    stack_List.push(5);
    stack_List.push(11);
    stack_List.push(15);
    stack_List.push(23);
    stack_List.push(6);
    stack_List.push(18);
    stack_List.push(20);
    stack_List.push(17);
    stack_List.display();
    stack_List.pop();
    stack_List.pop();
    stack_List.pop();
    stack_List.pop();
    stack_List.pop();
    stack_List.display();
    stack_List.push(4);
    stack_List.push(30);
    stack_List.push(3);
    stack_List.push(1);
    stack_List.display();

    auto end_timel = chrono::high_resolution_clock::now();
    auto time_takenl = chrono::duration_cast<chrono::microseconds >(end_timel - start_timel).count();
    cout << "Time taken for the linked list: " << time_takenl << " microseconds" << endl;

}
