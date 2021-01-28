//
//  DEMOADT_CLASS.h
//  ArrayADT
//
//  Created by Thanh Vu on 12/31/20.
//  Copyright © 2020 Thanh Vu. All rights reserved.
//

#ifndef DEMOADT_CLASS_h
#define DEMOADT_CLASS_h


template<class T>
class Array
{
private:
    T *A;
    int size,length;
    
    
public:
        //-------CONSTRUCTOR-------//
    Array();        //default Constructor
    Array(int sz);  //Copy constructor
    
        //-------MUTATOR--------//
    
    void setArray(int element, T val);    //CREATE/SET AN ARRAY
    void setLength(int length);             //GET LENGTH OF ARRAY, LENGTH IS INPUT, SIZE IS FIXED
    
        //-------ACCESOR-------///
    T *getArray();                        //GET ARRAY
    int getLength();                    //GET LENGTH
    
    
    
        //------- ADT OPS --------//
    
    T getIndex(int index);          //GET INDEX OF ARRAY
    T max();                        //GET THE MAXIMUM VALUE OF ARRAY
    T min();                        //GET THE MIMINUM VALUE OF ARRAY
    int sum();                        //GET THE SUM VALUE OF ARRAY
    float average();                    //GET THE AVERAGE OF ARRAY
    
    
    T add(T val);                       //APPEND ELEMENT
    T insert(int index, T val);         //INSERT ELEMENT
    int del(int index);                 //DELETE ELEMENT BY INDEX
    
    bool isSorted();                    //CHECK IF ARRAY IS SORTED
    T insertSorted(T val);              //INSERT TO A SORTED ARRAY
    
    
    void reverse();                 //Reverse elements
    
            //--------MERGING ARRAYS-------//
    
    //TO MERGE ARRAY A & ARRAY B, CREATE AN ARRAY C THAT COMBINE BOTH ARRAY A AND B'S LENGTH, AND COPY A->C, COPY B->C, COPY REMAING OF BOTH ARRAY TO C
    void mergeArr(T B[], int m, int n);
    
    
            //-------SEARCH OPS---------//
    
    void swap(T &x, T &y);          //SWAP, USED FOR IMPROVE LINEAR SEARCH 
    int linearSearch(T key);            //LINEAR SEARCH RETURN INDEX
    
    int binarySearch(T key);            //BINARY SEARCH RETURN INDEX
    int binarySearch2(T A[],  int l,  int h, T key);    //BINARY SEARCH USING RECURSION
    

            //--------- SET OPS -----------//
    
    // UNION IS EXACTLY THE SAME AS MERGING ARRAY/
    void intersection(T B[],int m, int n);
    void difference(T B[],int m, int n);
    
    
 
    void display();
    ~Array();                           //DESTRUCTOR
};


#endif /* DEMOADT_CLASS_h */
