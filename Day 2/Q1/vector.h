#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

template< typename T>

// TODO: Make it a template class
class Vector {
private:

    // TODO: Replace ? with appropriate type
    T* arr;
    int _size;
    int _capacity;


    // Utility: Resize the array when needed
    void resize(int new_capacity) 
    {
        // TODO: Create a new array of `new_capacity` size
        T* arr2 = new T[new_capacity];
        
        // TODO: Copy old elements to the new array
        for(int i=0;i<_size;i++)
        {
            arr2[i]=arr[i];
        }

        // TODO: Delete the old array and update arr and _capacity
        delete[] arr;
        
        arr =arr2; // double size

        _capacity=new_capacity;
    }



public:
    
    // Constructor

    Vector(int capacity = 2) 
    {
        // TODO: Initialize _capacity with given capacity
        _capacity=capacity;
        // TODO: Initialize _size as 0
        _size=0;
        // TODO: Allocate memory for arr
        arr= new T[_capacity];
    }




    // Destructor
    ~Vector() {
        // TODO: Release allocate
        delete[] arr;
    }



    bool is_dublicate(T value)
    {
        for(int i=0;i<_size ;i++)
        {
            if(arr[i]==value) return true;
        }
        
        return false;
    }



    // Add element at the end

    void push_back(T value) {

        if(_size==_capacity) resize(2*_capacity);

        if(is_dublicate(value))
        {
            cout<<"Dublicate values not allowed ";
        }
        arr[_size++]=value;
        

        /*
        
         // TODO: Add value at the end and increment size
        int newsize= _size+1;

        T * arr2= new T[newsize];

        for(int i=0; i< _size ;i++)
        {
            arr2[i]=arr[i];
        }

        arr2[newsize]=value;

        */
       
    }



    // Add element at the start
    void push_front(T value) 
    {
       
       for(int i=_size ;i>0 ;i--)
       {
            arr[i]=arr[i-1];
       }
       arr[0]=value;
       _size++;
      

    }



    // Insert element at a specific index
    void insert_at(int index, T value) {
        // TODO: Resize if full
        if(_size== _capacity)
        {
            resize(_capacity*2);
        }
        // TODO: Shift elements right from index
        for(int i= _size ;i> index ; i--)
        {
            arr[i]=arr[i-1];
        }
        // TODO: Insert value at the given index
        arr[index]= value;
        _size++;
    }



    // Remove element at a specific index
    void remove_at(int index) {
        // TODO: Shift elements left to fill the gap
        for(int i= index ;i< _size ; i++)
        {
            arr[i]=arr[i+1];
        }
        // TODO: Decrement size
        _size--;
    }

    // Remove element from the end
    void remove_back() {
        // TODO: Decrement size

        _size--;
    }

    // Remove element from the front
    void remove_front() {
        // TODO: Shift elements left
        for(int i=0;i<_size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        // TODO: Decrement size
        _size--;
    }

    // Get element at index
    int get(int index) const {
        // TODO: Return the element
        return arr[index];
    }

    // Current number of elements
    int size() const {
        // TODO: Return current size
        return _size;
    }

    // Current allocated capacity
    int capacity() const {
        // TODO: Return current capacity
        return _capacity;
    }

    // Check if Vector is empty
    bool empty() const {
        // TODO: Return true if _size == 0
        if(_size == 0) return true;
    }

    // Display Vector contents
    void display() const {
        cout << "[";
        for (int i = 0; i < _size; i++) {
            cout << arr[i];
            if (i != _size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

#endif
