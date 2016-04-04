#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>
#include <list>
#include <algorithm>

using namespace std;


class Stack{
private:
    int max_size;
    double* stack;
    int top;
public:
    Stack() : stack(new double[1]), max_size(1), top(0) {}

    Stack(int size): stack(new double[size]), max_size(size), top(0) {}

    Stack(const list<double>& e_list) : max_size(2*e_list.size() + 1), stack(new double[max_size]), top(0) {
        for (double i : e_list){
            this->put(i);
        }
    }

    // Konstruktor kopiujacy
    Stack(const Stack& other) : max_size(other.max_size), stack(new double[max_size]), top(other.top) { 
        copy(other.stack, other.stack + top + 1, stack); 
    }

    // Operator kopiujacy
    Stack& operator=(const Stack& other){
        if (this != &other){
            double* new_stack = new double[other.max_size];
            copy(other.stack, other.stack + other.top, new_stack);

            delete [] stack;

            stack = new_stack;
            max_size = other.max_size;
            top = other.top;
        }
        return *this;
    }

    // Konstruktor przenoszacy
    Stack(Stack&& other) : stack(other.stack), max_size(other.max_size), top(other.top) {
        other.stack = nullptr;
        other.max_size = 0;
        other.top = 0;
    }

    // Operator przenoszacy
    Stack& operator=(Stack&& other) {
        if (this != &other){
            delete[] stack;

            stack = other.stack;
            max_size = other.max_size;
            top = other.top;

            other.stack = nullptr;
            other.max_size = 0;
            other.top = 0;
        }
        return *this;
    }

    double put(double value){ // Wstawia element na stos
        if (top < max_size){
            top++;
            stack[top] = value;
        } else {
            throw out_of_range("Stack is full. You can't add any more elements.");
        }
    }

    int size(){
        return top;
    }

    double pop(){ // Zwraca i zdejmuje element ze stosu
        if (top > 0) {    
            double tmp = stack[top];
            stack[top] = 0;
            top--;
            return tmp;
        } else {
            throw out_of_range("Stack is empty.");
        }
    }

    double peak(){ // Zwraca element, ale nie zdejmuje ze stosu
        return stack[top];
    }

    ~Stack(){
        delete[] stack;
    }
};

int main(int argc, char *argv[]){
    
    Stack* s1 = new Stack(3);

    s1->put(3);
    s1->put(2);

    cout << s1->pop() << endl;

    delete s1;

    return 0;
}