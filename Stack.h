//
//  Stack.h
//  P2Battle
//
//  Created by Brendon Malouf on 3/26/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#define MAX_LENGTH 100
class StackEmptyException{};
class StackFullException{};

template <typename T>
class Stack{
private:
    T* data;
    int top;
    int maxLength;
public:
    Stack():maxLength{MAX_LENGTH}{
        data = new T[maxLength];
        top = -1;
    }
    Stack(int len):maxLength{len}{
        data = new T[maxLength];
        top = -1;
    }
    
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push(T item);
    T Top();
    void Pop();
};

template <typename T>
void Stack<T>::MakeEmpty(){
    top = -1;
}

template <typename T>
bool Stack<T>::IsEmpty(){
    return top == -1;
}

template <typename T>
bool Stack<T>::IsFull(){
    return top == maxLength - 1;
}

template <typename T>
void Stack<T>::Push(T item){
    if(IsFull()) throw StackFullException();
    
    data[++top] = item;
}
template <typename T>
T Stack<T>::Top(){
    if(IsEmpty()) throw StackEmptyException();
    
    return data[top];
}

template <typename T>
void Stack<T>::Pop(){
    if(IsEmpty()) throw StackEmptyException();
    
    top--;
}


#endif /* Stack_h */
