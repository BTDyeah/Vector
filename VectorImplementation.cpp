#include <iostream>
#define ADD 10

/*Copy Constructor
  Assignment Operator
  Move Operator*/ 


template <typename T>
class Vector {
private:
    T* elements;
    T* newArray;
    int size; //current size 
    int capacity; //capacity of current allocation
public:
    
    Vector(int c) {
        capacity = c;
        size = 0;
        elements = new T[c];
        newArray = new T[c += ADD];
    }

    /*Copy constructor*/
    Vector(const Vector& other) {
        capacity = other.capacity;
        size = other.size;
        elements = new T[other.capacity];
        std::copy(&other.elements[0], &other.elements[size], &elements[0]);
    }

    void push_back(T newElem){
        if(size < capacity){
            elements[size++] = newElem;  //insert at size
        }
        else {
             
            
            std::copy(&elements[0], &elements[size], &newArray[0]);
            
            newArray = elements;
            newArray[size++] = newElem; //insert
        } 
    }
    void pop_back(){

    }

    void clear() {
        for(int i = 0; i < size; ++i) 
            delete newArray[i];
        
    }
    void printVec() {
        for(int i = 0; i < size; ++i){
            std::cout << elements[i] << std::endl;
            std::cout << newArray[i] << std::endl;
        }
    }

    T& operator[](T index){
        if(index < size)
            return elements[index];
        else
            exit(0);
    }    
    
    Vector& operator=(const Vector& other){
        if(this == &other)
            return *this;

        size = other.size;
        capacity = other.capacity; 
        std::copy(&other.elements[0], &other.elements[size], &elements[0]);
        
        return *this;
    }
    
};

int main() {
    Vector<int>vector(15);
    Vector<int>vector1(15);
    
    for(int i = 0; i <= 20; ++i)
        vector1.push_back(i);

    vector = vector1;
    vector1.printVec();
    //vector1.printVec();

    return 0;
}