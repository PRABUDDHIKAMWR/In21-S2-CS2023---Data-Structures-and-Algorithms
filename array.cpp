#include <bits/stdc++.h>
#include <ctime>
#include <time.h>

using namespace std::chrono;
using namespace std;


struct Stack1{
    int size = 10;
    int top = -1;
    int stack[10];
};

struct Array_stack{

    void PUSH(Stack1& S, int x){
        S.top = S.top + 1;

        if (S.top > S.size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            S.stack[S.top] = x;
        }
    }

    int Pop(Stack1& S){
        if (IS_EMPTY(S)){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            S.top = S.top - 1;
            return S.stack[S.top + 1];
        }

    }

    int StackTop(Stack1& S){
        return S.top;
    }

    bool IS_EMPTY(Stack1& S){
        if (S.top == -1){
            return true;
        }
        return false;
    }

    bool IS_FULL(Stack1& S){
        if (S.top == S.size-1){
            return true;
        }
        return false;
    }

    void Display(Stack1& S){
        for(int i = 0; i < S.top; i++ ){
            cout<<S.stack[i]<<" ";
        }
        cout<<endl;
    }


};



int main(){

    clock_t start = clock();
    Stack1 s;
    Array_stack lls;
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
    lls.Display(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Pop(s);
    lls.Display(s);
    lls.PUSH(s, 4);
    lls.PUSH(s, 30);
    lls.PUSH(s, 3);
    lls.PUSH(s, 1);
    lls.Display(s);
    clock_t end = clock();
    double diff = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"Time taken : "<<diff;

}
