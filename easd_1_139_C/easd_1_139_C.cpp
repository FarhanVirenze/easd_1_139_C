// easd_1_139_C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//1. Jelaskan Mengapa Suatu Algoritma dibutuhkan untuk menyelesaikan suatu masalah?
//jawab : karena Algoritma dapat mempermudah anda dalam menyelesaikan suatu permasalahan yang berkaitan dengan program dan tidak dapat anda selesaikan dengan mudah 

//2. Dalam algoritma, diklasifikasikan menjadi 2 data struktur. sebutkan 2 data struktur tersebut
//jawab : Boolean dan String

//3. Sebutkan faktor-faktor yang mempengaruhi efesiensi suatu progress algoritma!
//jawab : adanya input,proses, dan output

//4. Dari 6 algortima yang telah dipelajari. Algorit manakah yang paling efesiensi untuk menggunakan data yang ukurannya kecil. Jelaskan kenapa anda memilih ini.
//jawab : Bubble Sort

//5. Sebutkan dari algoritma yang telah dipelajari mana yang termasuk kedalam Quadratis dan mana yang termasuk kedalam Loglinear
//jawab : Quadratis =
//        - Bubble Sort
//        - Quick Sort

//        Loglinear =
//        - InsertionSort

//6. Buatlah sebuah Program yang mengimplementasikan selection sort menggunakan bahasa c++. Berikut merupakan algoritma selection sort
//1.) Repeat steps w and 3 varying j from 0 to n - 2
//2.) find the minimum value in arr[j] to arr(n - 1) :
//    a. Set min_index = j
//    b. repeat step c varying i from j + 1 to n - 1
//    c. if arr[i] < arr[min_index]
//       1. min_index = 1
//3.) Swap arr[j] with arr[min_index]
//There are additional requirements to create the program :
//a. The maximum number of data is th e sum of the last two digits of yout student number + 20 - 2 
//b. Changes the "j" in the algorithms to the two initials of your name (example: if your name is fahmi azhar then "f" is changed to "fa", if your name consists of more than 2 words. the inititals are taken from the firts letter of your name and one letter from your last name)
//c. change "arr" with your nickname


#include <iostream>
using namespace std;

int arr[20];            //array of integera to hold values
int cmp_count = 0;      // number of comparasion
int mov_count = 0;      // number of data movements
int n;

void input() {
    while (true)
    {
        cout << "Masukan panjang element array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }

    cout << "\n===================" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n===================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}

void swap(int x, int y)
{
    int temp;

    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void q_short(int low, int high)
{
    int pivot, i, j;
    if (low > high)
        return;

    pivot = arr[low];
    i = low + 1;                        //Langkah Algoritma No. 3
    j = high;                           //Langkah Algoritma N0. 4

    while (i <= j)                      //Langkah Algoritma No. 5
    {
        //search for or element greather than pivot
        while ((arr[i] <= pivot) && (j <= high))        //Langkah Algoritma No. 5
        {
            i++;                                        //Langkah Algoritma No. 6
            cmp_count++;
        }
        cmp_count++;

        //search for an element less than or equal to pivot
        while ((arr[j] > pivot) && (j >= low))          //Langkah Algoritma No. 7
        {
            j--;                                        //Langkah Algoritma No. 8
            cmp_count++;
        }
        cmp_count++;

        // if the greater element is on the left of the element 
        if (i < j)                                      //Langkah Algoritma No. 9
        {
            //swap the element at index i with the element at index j
            swap(i, j);
            mov_count++;
        }
    }
    // j now contain the index of the last element in the sorted list
    if (low < j)                                        //Langkah Algoritma No. 11
    {
        //move the pivot to its correct position in the list
        swap(low, j);
        mov_count++;
    }
    //sort the list on the left of pivot using quick sort
    q_short(low, j - 1);                                //Langkah Algoritma No. 12

    //sort the list on the right of pivot using quick sort
    q_short(j + 1, high);                               //Langkah Algoritma No. 13

}

void display() {
    cout << "\n==================" << endl;
    cout << "Sorted Array" << endl;
    cout << "==================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparation: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);      //Sort the array using quick sort
    display();
    system("pause");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
