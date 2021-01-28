//
//  impADT.h
//  ArrayADT
//
//  Created by Thanh Vu on 12/31/20.
//  Copyright © 2020 Thanh Vu. All rights reserved.
//

#ifndef impADT_h
#define impADT_h
using namespace std;
void implStructArr();
string getString(char);

void implStructArr()
{
    
    //INTIALIZE THE ARRAY
    Array<int> arrInt(20);
    
    static int length = 5;
    arrInt.setLength(length);
    //int getVal{0};
    for(int i = 0; i < length; i++)
    {
        //cout << "Enter your value: ";
        //cin >> getVal;
        arrInt.setArray(i, i*2);
    }
    cout << "ORIGNAL ARRAY: ";
    arrInt.display();
    cout<<endl;
    
                // ---------------- ADT OPERATIONS ------------------- //
    
    
    //APPEND ARRAY
    arrInt.add(69);
    cout << "ARRAY AFTER APPEND X: ";
    arrInt.display();
    
    
   
    //INSERT THE ARRAY
    arrInt.insert(5, 15);
    cout << "ARRAY AFTER INSERT: ";
    arrInt.display();
    
    
    
    //DELETE AN ELEMENT BY INDEX
    arrInt.del(3);
    cout << "ARRAY AFTER DELETE AN ELEMENT BY INDEX: ";
    arrInt.display();
    cout << endl;
    
    
    //GET INDEX
    int index;
    cout << "Enter the index of desired value: ";
    cin >> index;
    int getValue = arrInt.getIndex(index);
    cout << "Value at index " << index << " : " << getValue << endl;
    
    
    //SET INDEX
    arrInt.setArray(1, 3);
    
    
    
    //RETURN ARRAY FROM CLASS
   
    //int newLength = arrInt.getLength();

    cout << endl;
    auto *newArr = arrInt.getArray();
    cout << "CURRENT ARRAY: ";
    arrInt.display();
    
    
    
    //MAX  && MIN
    int getMax = arrInt.max();
    cout << "Max value of array: " << getMax << endl;
    int getMin = arrInt.min();
    cout << "Min value of array: " << getMin << endl << "\n";
    
    
    
    //GET SUM
    int getSum = arrInt.sum();
    cout << "Sum of all array element: " << getSum << endl;
    //GET AVG
    float getAvg = arrInt.average();
    cout << "Average of all array element: " << getAvg << endl << "\n";
    
    
    //CHECK IF ARRAY IS SORTED
    cout << "Check if Int array is sorted :" << arrInt.isSorted() << "\n";
    
    
    //ADD AN INSERT ARRAY
    int sortedKey = 7;
    arrInt.insertSorted(sortedKey);
    cout << "Insert " << sortedKey << " to a sorted array ... \n";
    cout << "Current Array: ";
    arrInt.display();
    cout << "\n";
    
    
    
  
    
    //          --------    SEARCH OPERATIONS    --------          //
    
    
    //BINARY SEARCH USING LOOP
    int newLength = arrInt.getLength();
    int key = 69;
    cout << "Binary Search for number " << key << " in the array ...." << endl;
    int binaryFind = arrInt.binarySearch(key);
    cout << "Number found at: " << binaryFind << endl;
    cout << endl;



    //BINARY SEARCH USING RECURSION
    cout << "Binary Search(recursion) for number " << key << " in the array ...." << endl;
    int binaryFind2 = arrInt.binarySearch2(newArr, 0, newLength, key);
   // delete[] newArr;
    cout << "Number found at: " << binaryFind2 << endl;
    cout << endl;
    
    
    
    //LINEAR SEARCH
    cout << "Linear Search for number " << key << " in the array ...." << endl;
    //int count = 0; //count keep track of how many times the algorithm search through.
    int linearFind = arrInt.linearSearch(key);
    cout << "Number found at index:  " << linearFind << endl;
    cout << endl;
    
    
    
    
    
    
    //REVERSING THE INT ARRAY
    //cout << "\n Reversing int array: ... \n";
    //arrInt.reverse();
    //cout << "Int Array after reverse: ";
    // arrInt.display();
    cout << "\n\n";
    
    
    //  ------------------ SETS OPERATION ----------------- //
    arrInt.display();
    
    const unsigned int sizeArr = 5;
    auto *newArr2 = new int[sizeArr];
    newArr2[0] = 2; newArr2[1] = 4; newArr2[2] = 6; newArr2[3] = 9; newArr2[4] = 12;
    //int newArr2[sizeArr2] = {2,4,6,9,12};
    cout << "\n";
    for(int i = 0;i < sizeArr; i++) cout << "\t" << newArr2[i];
    cout <<"\n";
    //MERGE ARRAY IS THE SAME AS UNION OPERATION
    arrInt.mergeArr(newArr2, newLength, sizeArr);            //Merge array2 to arra1, parameter(arrB[],m,n)
    cout << "\n\t\tSET OPERATION \n UNION: ";
    arrInt.display();
    delete [] newArr2;
    
    cout << "\n\n";
    
    
    static int newArr3[sizeArr] = {1,3,4,5,8};
    int newArr3Size = sizeof(newArr3)/sizeof(newArr3[0]);
    
    
    
    
    
    //INTERSECTION
    arrInt.display();
    for(int x : newArr3) cout << "\t" << x;
    cout << "\nINTERSECTION: ";
    arrInt.intersection(newArr3, newLength, sizeArr);
    arrInt.display();
    cout << "\n\n\n";
    
    
    
    
    
    //DIFFERENCE SET
    arrInt.display();
    for(int x : newArr3) cout << "\t" << x;
    cout << "\nDIFFERENCE : ";
    arrInt.difference(newArr3, arrInt.getLength(), newArr3Size);
    arrInt.display();
    cout << "\n\n\n";
    
    
    
    
   
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
            //  ---------------- REVERSE ARRAY -------------------- //

    cout << "\n\n\t\t--------------------------\n\n";
    //REVERSE AN CHAR ARRAY
    //CREATE AN CHAR ARRAY TYPE FROM CLASS
    Array<char> arrChar(10);
    
    string s = "fuckyou";

    int n = s.length();
    arrChar.setLength(n);
    char cstr[s.size() + 1];
    strcpy(cstr, s.c_str());
    
   // cout << cstr << "\n";
    
    for (int i = 0; i < n ; i++)    arrChar.setArray(i, cstr[i]);
    
   
    cout << "CHAR ARRAY: ";
    arrChar.display();
    //Check if Array is sorted
    cout << "Check if array is sorted: " << arrChar.isSorted() << "\n";
    
    
    
    //Reversing array
    cout << "Reversing Char array ... \n";
    arrChar.reverse();
    cout << "Char array after reverse ... :";
    arrChar.display();
    
    
    
    
   
    

    
}


#endif /* impADT_h */
