//
//  DEMOADT.h
//  ArrayADT
//
//  Created by Thanh Vu on 12/30/20.
//  Copyright © 2020 Thanh Vu. All rights reserved.
//

#ifndef DEMOADT_h
#define DEMOADT_h
#include "DEMOADT_CLASS.h"
#include <set>
#include <functional>
#include <algorithm>
#include <iostream>



//Default Constructor
template<class T>
Array<T>::Array() {
    T *A = nullptr;
    size = 0;
   // length = 0;
}


//copy constructor
template<class T>
Array<T>::Array(int sz)
{
    size = sz;
    A = new T [sz];
}


//Set Array
template<class T>
void Array<T>::setArray(int element, T val)
{
    A[element] = val;
}

//Set Length
template<class T>
void Array<T>::setLength(int length)
{
    this->length = length;
}

//GET ARRAY
template<class T>
T *Array<T>::getArray()
{
    return A;
}

//GET_LENGTH
template<class T>
int Array<T>::getLength()
{
    return length;
}


//  ------------------------ ARRAY ADT OPS ------------------------    //

//GET INDEX.
template<class T>
T Array<T>::getIndex(int index)
////INPUT INDEX AND RETURN THE VALUE AT THE INDEX
{
    if(index >= 0 && index < length)  return A[index];
    else return -1;                      //RETURN -1 if INDEX IS OUT OF RANGE
}



//MAX
template<class T>
T Array<T>::max()
{
    T max = A[0];
    for(int i = 1; i < length; i++)
    {
        if (A[i] > max) max = A[i];
    }
    return max;
}


//MIN
template<class T>
T Array<T>::min()
{
    T min = A[0];
    for(int i =1; i<length;i++)
    {
        if(A[i] < min) min = A[i];
    }
    return min;
}


//SUM
template<class T>
int Array<T>::sum()
{
    int total = 0;
    for(int i = 0; i < length; i++) total = total + A[i];
    return total;
}


//AVERAGE
template<class T>
float Array<T>::average()
{
    float total = sum();
    return (total/length);
}


//ADD ELEMENT
template<class T>
T Array<T>::add(T val)
{
    if(length<size)
    {
        A[length] = val;
        length++;
        return val;
    }
    else return 0;
    
}



//INSERT
template<class T>
T Array<T>::insert(int index, T val)
{
    if ( index >= 0 && index <= length)
    {
        for(int i = length; i > index; i--)    A[i] = A[i-1];
        A[index] = val;
        length++;
        return val;
    }
    else return 0;
    
}



//DELETE ELEMENT BY INDEX
template <class T>
int Array<T>::del(int index)
{
    int x = 0;
    if(index >= 0 && index < length)
    {
        x = A[index];
        for(int i = index; i < length - 1; i++) A[i] = A[i+1];
        length--;
        return x;
    }
    else return 0;
}

//REVERSE AN ARRAY
template <class T>
void Array<T>::reverse()
{
    int i,j;
    for(i = 0,j = length -1; i<j ; i++ , j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}



//CHECK IF IS SORTED.
template <class T>
bool Array<T>::isSorted()
{
    for(int i = 0; i < length; i++)
    {
        if(A[i] > A[i+1]) return false;
    }
    return true;
}



//INSERT A SORTED VALUE. 
template <class T>
T Array<T>::insertSorted(T val)
{
    int i = length - 1;
    while(A[i] > val)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = val;
    length++;
    std::cout << "\n"<< i << "\n";
    return i;
    
}




// ------------------ SEARCH OPS --------------------///

//LINEAR SEARCH

template <class T>
void Array<T>::swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}
template <class T>
int Array<T>::linearSearch(T key)
{
   // int count = 0;
    for (int i = 0; i < length; i++)
    {
        std::cout << "Searching at index " << i << "..." << "\n";
        //count++;
        if(key == A[i]) return i;
          //  swap(A[i], A[i-1]);
            //swap is used for improve linear search, whenever a key is found, the element
            //will swap to the element before it, so it can search faster the next time.
    }
    return -1;
}




//BINARY SEARCH
template <class T>
int Array<T>::binarySearch(T key)
{
    int mid = 0; int l = 0; int h = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l+h)/2;
        if(key == A[mid]) return mid;
        else if (key < A[mid]) h = mid-1;
        else l = mid + 1;
    }
 
    return -1;      //return -1 if can't find
}



//BINARY SEARCH USING RECURSION
template <class T>
int Array<T>::binarySearch2(T A[],  int l,  int h, T key)
{
    int mid = 0;
    if (l <= h)
    {
        mid = (l+h)/2;
        if(A[mid] == key) return mid;
        else if(A[mid] > key) return binarySearch2(A, l, mid-1 , key);
        else if(A[mid] < key) return binarySearch2(A, mid+1, h, key);
    }
    return -1;
}





//  ------------MERGING ARRAY ----------------- //

template<class T>
void Array<T>::mergeArr(T B[], int m,int n)
{
    int i =0;       //INDICES of A
    int j =0;       //INDICES of B
    int k =0;       //INDICES of C
    
    T *C = new T[m+n];
    
    while(i < m && j < n)
    {
        if (A[i] < B[j])        C[k++] = A[i++];
        else if(A[i] > B[j])    C[k++] = B[j++];
        else
        {
            C[k++] = A[i++];
            j++;
        }
        
    }
      
    while(i < m) C[k++] = A[i++];
    while(j < n) C[k++] = B[j++];
    

    for(int i = 0; i < k; i++)
    {
        A[i] = C[i];
    
    }
    
    for(int i = 0; i <= k; i++)
    {
        setLength(i);
    }
   // std::cout << lengthOfA;
    
    C = nullptr;
    
    delete[] C;
    
 
}

//  ------------------ SETS OPERATION -------------------- //

// INTERSECTION.
template<class T>
void Array<T>::intersection(T B[], int m, int n)
{
    int i = 0, j = 0,k=0;
    T* C = new T[k];
    while(i < m && j < n)
    {
        if(A[i] > B[j]) j++;
        else if(A[i] < B[j]) i++;
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    
   
    
    for(int i = 0;i < k;i++) setLength(i);
    for(int i = 0; i < k; i++)
    {
        A[i] = C[i];
    }
    
    C = nullptr;
    delete [] C;
    

}


//DIFFERENCE

template<class T>
void Array<T>::difference(T B[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    T *C = new T[k];
    while(i < m || j < n)
    {
       if(A[i] < B[j])
       {
           C[k++] = A[i++];
         
       }
    
       else if(A[i] > B[j]) j++;
       else
       {
           i++;
           j++;
       }
    }
    
    
    for(int i = 0;i <= k;i++) setLength(i);
    
    for(int i = 0; i < k; i++)
    {
        A[i] = C[i];
    }
    
   
    
    C = nullptr;
    delete [] C;
    
}

    





        // ----------------- DISPLAY ------------------ //



//Display Array
template<class T>
void Array<T>::display()
{
    for (int i{0};i < length; i++)
    {
        std::cout << "\t" << A[i];
    }
    std::cout << "\n";
}


    
//Destructor
template<class T>
Array<T>::~Array<T>()
{
    delete [] A;
    
}

#endif /* DEMOADT_h */
