#include <iostream>
#include <cmath>
using namespace std;

template<typename T>

// (: Create a Vector template class

class Vector
{
    // (: Declear data members

    T* arr;
    int size;

public:

    // (: Define the class constructor

    Vector(int num)
    {
        size=num;
        arr=new T[size];
    }


    void SetMethod(int index, T val )
    {
        arr[index]= val;
    }

    T getMethod(int index) const
    {
        return arr[index];
    }


    // (: Define a class method that will calculate the dot product of two vectors

    float dot(const Vector<T>&v3)const
    {
        float result=0.0;

        for(int i=0;i<size;i++)
        {
            result=result + this->arr[i]* v3.arr[i];
        }
        return result;
    }


    // (: Define a function that will calculate the norm of the vector
    // v=(v1^2  + v2^2)^1/2
    double norm() const
    {
        double result=0;

        for(int i=0;i<size; i++)
        {
            result=result+arr[i]*arr[i];
        }
        return sqrt(result);
    }



    // (: Define a function to calculate cosine similarity between two vectors
    double cosineSimilarity(const Vector<T> & v4) const 
    {
        T product = dot(v4);
        double norm1 = norm();
        double norm2 = v4.norm();

        return product / (norm1 * norm2);
    }



    ~Vector()
    {
        delete[] arr;
    }
};



int main() 
{
    int n;
    cout << "Enter the size of the vectors: ";
    cin >> n;

    // (: Create two vectors
    Vector<int> v1(n),v2(n);
    
    
    cout << "Enter elements of first vector:\n";
    // (: Write loop to take input from the user  
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v1.SetMethod(i, x);

    }

    cout << "Enter elements of second vector:\n";
    // (: Write loop to take input from the user  
    int y;
    for(int i=0;i<n;i++)
    {
        cin>>y;
        v2.SetMethod(i, y);
    }

    

    // (: Calculate dot product, and cosine similarity by calling relevant class methods
    // in the (?) placeholder.
 
    cout << "Dot product: " << v1.dot(v2) << endl;
    cout << "Cosine similarity: " << v1.cosineSimilarity(v2) << endl;

    
    cout << "---------------------------------" << endl<< endl<< endl;





    Vector<float> f1(n), f2(n);
    cout << "Enter elements of first float vector:\n";
    // (: Write loop to take input from the user  
    float p;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        f1.SetMethod(i, p);

    }

    cout << "Enter elements of second float vector:\n";
    // (: Write loop to take input from the user  
    float q;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        f2.SetMethod(i,q);
    }

    

    // (: Calculate dot product, and cosine similarity by calling relevant class methods
    // in the (?) placeholder.
 
    cout << "Dot product: " << f1.dot(f2) << endl;
    cout << "Cosine similarity: " << f1.cosineSimilarity(f2) << endl;

    
    cout << "---------------------------------" << endl;

    return 0;
}
