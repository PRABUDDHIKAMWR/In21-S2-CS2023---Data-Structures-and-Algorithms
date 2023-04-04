#include <bits/stdc++.h>
#include <ctime>
#include <time.h>

using namespace std::chrono;

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node* top;
};

struct LinkedList_stack{

    Node *head = NULL;

    void PUSH(Stack& S, int x){
    
            Node* new_node = new Node;
            new_node->data = x;
            new_node ->next = head;
            head = new_node;
            S.top = new_node;
    }

    int Pop(Stack& S){

        if (IS_EMPTY(S)){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        else{
            int x = S.top->data;
            Node* temp = S.top;
            S.top = S.top->next;
            delete temp;
            return x;
        }
    }

    int top(Stack& S){
        if (S.top == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return S.top->data;
    }

    bool IS_EMPTY(Stack& S){
        if(S.top == NULL){
            return true;
        }
        return false;
    }

    void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


};

int main(){

    clock_t start = clock();

    Stack s;
    LinkedList_stack lls;
    lls.PUSH(s, 8);
    lls.PUSH(s, 10);
    lls.PUSH(s, 5);
    lls.PUSH(s, 11);
    lls.PUSH(s, 15);
    lls.PUSH(s, 23);
    lls.PUSH(s, 6);
    lls.PUSH(s, 18);
    lls.PUSH(s, 20);
    lls.PUSH(s, 17);
    lls.Display();
    lls.Pop(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Display();
    lls.PUSH(s, 4);
    lls.PUSH(s, 30);
    lls.PUSH(s, 3);
    lls.PUSH(s, 1);
    lls.Display();
    clock_t end = clock();
    double diff = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"Time taken : "<<diff;
}
