#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include <ctime>
#include <cstdlib>
#include "stdafx.h"

using namespace std;

void merge(int[], int, int[], int, int[]);
void bubblemethod(int*, int);
void insertionmethod(int[], int);
void merge_sort(int[], int, int);
void mergemethod(int[], int, int, int);
void selectionmethod(int[], int, int);
int populateArray();

int size;
int* array;




int main(int argc, char** argv) {
    int menuOption;





    //int c2, n2;

    // printf("Ten random numbers in [1,100]\n");

    //for (c2 = 1; c2 <= 10; c2++) 
    //{
    //   n2 = rand()%100 + 1;
    //  printf("%d\n", n2);
    //}


    do

    {
        cout << endl << endl << "Select an option from the MENU:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Exit the Program" << endl;
        cin >> menuOption;

        time_t t1 = 0;
        time_t t2 = 0;
        switch (menuOption)
        {
        case 1:

            size = populateArray();
            t1 = time(0);
            bubblemethod(array, size);
            t2 = time(0);

            break;

        case 2:

            size = populateArray();
            t1 = time(0);
            insertionmethod(array, size);
            t2 = time(0);


            break;
            /*
            case 3:
            cout <<  endl << "Enter the size of the list with integers:" << endl ;
            cin >> size;

            randomnum=size;

            cout<< endl <<"The random numbers in this size are:" << endl;

            for (c1 = 1; c1 <= size; c1++)
            {
            n1 = rand()%size + 1;
            printf("%d\n", n1);
            array[c1-1]=n1;
            }

            merge_sort(array,c1,randomnum);

            cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;
            cout<<endl<<endl;

            for(c1=1;c1<=randomnum;c1++)
            cout<<array[c1-1]<<"    ";



            break;
            case 4:
            cout <<  endl << "Enter the size of the list with integers:" << endl ;
            cin>> size;

            randomnum=size;

            cout<< endl <<"The random numbers in this size are:" << endl;

            for (c1 = 1; c1 <= randomnum; c1++)
            {
            n1 = rand()%size + 1;
            printf("%d\n", n1);
            array[c1-1]=n1;
            }


            selectionmethod(array,c1,randomnum);

            break;
            case 5:

            break;
            case 6:
            cout << endl << "End the program" << endl  ;
            break;
            */
        default:
            cout << endl << "Error in menu input. Valid menu options are 1 to 6." << endl;
        }// end switch

        cout << "time taken = " << t2 - t1 << " seconds";
    } while (menuOption != 6); // end do-while



}


void bubblemethod(int array[], int size)
{
    int d, swap, c1;

    for (c1 = 0; c1 < size; c1++)
    {

        for (d = 0; d < size - 1; d++)
        {
            if (array[d] > array[d + 1]) /* For decreasing order use < */
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }

    cout << endl << "Sorted list:\n" << endl;


    for (c1 = 0; c1 < size; c1++)
        printf("%d\n", array[c1]);



}

void insertionmethod(int array[], int size)
{
    int d, t, c1;
    for (c1 = 1; c1 <= size - 1; c1++)
    {
        d = c1;

        while (d > 0 && array[d] < array[d - 1])
        {
            t = array[d];
            array[d] = array[d - 1];
            array[d - 1] = t;

            d--;
        }
    }

    printf("Sorted list:\n");

    for (c1 = 0; c1 <= size - 1; c1++)
        printf("%d\n", array[c1]);

}

void merge_sort(int array[], int c1, int size)
{
    int mid;
    if (c1 < size)
    {
        mid = (c1 + size) / 2;
        merge_sort(array, c1, mid);
        merge_sort(array, mid + 1, size);
        mergemethod(array, c1, mid, size);
    }
}

void mergemethod(int array[], int c1, int mid, int randomnum)
{
    int h, i, j, b[50], k;
    h = c1;
    i = c1;
    j = mid + 1;

    while ((h <= mid) && (j <= randomnum))
    {
        if (array[h] <= array[j])
        {
            b[i] = array[h];
            h++;
        }
        else
        {
            b[i] = array[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (k = j; k <= randomnum; k++)
        {
            b[i] = array[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = array[k];
            i++;
        }
    }
    for (k = c1; k <= randomnum; k++)
        array[k] = b[k];
}



void selectionmethod(int array[], int c1, int randomnum)
{
    int position, d, swap;
    for (c1 = 0; c1 < (randomnum - 1); c1++)
    {
        position = c1;

        for (d = c1 + 1; d < randomnum; d++)
        {
            if (array[position] > array[d])
                position = d;
        }
        if (position != c1)
        {
            swap = array[c1];
            array[c1] = array[position];
            array[position] = swap;
        }
    }

    printf("Sorted list:\n");

    for (c1 = 0; c1 < randomnum; c1++)
        printf("%d\n", array[c1]);
}


int populateArray()
{
    int size;
    cout << endl << "Enter the size of the list with integers:" << endl;
    cin >> size;


    int randomnum, c1, n1;

    randomnum = size;
    array = new int[size];

    cout << endl << "The random numbers in this size are:" << endl;

    for (c1 = 1; c1 <= size; c1++)
    {
        n1 = rand() % size + 1;
        printf("%d\n", n1);
        array[c1 - 1] = n1;
    }

    return size;

}