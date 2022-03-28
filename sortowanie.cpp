#include <chrono>
#include <fstream>
#include <iostream>

#include "sortowanie.hh"


int arr1[100][SIZE_1], arr2[100][SIZE_2], arr3[100][SIZE_3], arr4[100][SIZE_4], arr5[100][SIZE_5];
double T1[100], T2[100], T3[100], T4[100], T5[100];

int main()
{
    
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<SIZE_1; j++)
        {
            arr1[i][j]=rand()%SIZE_1;
        }
        for(int j=0; j<SIZE_2; j++)
        {
            arr2[i][j]=rand()%SIZE_2;
        }
        for(int j=0; j<SIZE_3; j++)
        {
            arr3[i][j]=rand()%SIZE_3;
        }
        for(int j=0; j<SIZE_4; j++)
        {
            arr4[i][j]=rand()%SIZE_4;
        }
        for(int j=0; j<SIZE_5; j++)
        {
            arr5[i][j]=rand()%SIZE_5;
        }
    }
    int option;
    std::cin>>option;
    std::cout<<std::endl;
    switch (option)
    {
    case 1:
        break;
    case 2:
            for(int i{0}; i<100; i++)
            {
                mergeSort(arr1[i], 0, SIZE_1/4);
                mergeSort(arr2[i], 0, SIZE_2/4);
                mergeSort(arr3[i], 0, SIZE_3/4);
                mergeSort(arr4[i], 0, SIZE_4/4);
                mergeSort(arr5[i], 0, SIZE_5/4);
            }
        break;
    case 3:
            for(int i{0}; i<100; i++)
            {
                mergeSort(arr1[i], 0, SIZE_1/2);
                mergeSort(arr2[i], 0, SIZE_2/2);
                mergeSort(arr3[i], 0, SIZE_3/2);
                mergeSort(arr4[i], 0, SIZE_4/2);
                mergeSort(arr5[i], 0, SIZE_5/2);
            }
        break;
    case 4:
            for(int i{0}; i<100; i++)
            {
                mergeSort(arr1[i], 0, SIZE_1*3/4);
                mergeSort(arr2[i], 0, SIZE_2*3/4);
                mergeSort(arr3[i], 0, SIZE_3*3/4);
                mergeSort(arr4[i], 0, SIZE_4*3/4);
                mergeSort(arr5[i], 0, SIZE_5*3/4);
            }
        break;
    case 5:
            for(int i{0}; i<100; i++)
            {
                mergeSort(arr1[i], 0, SIZE_1*95/100);
                mergeSort(arr2[i], 0, SIZE_2*95/100);
                mergeSort(arr3[i], 0, SIZE_3*95/100);
                mergeSort(arr4[i], 0, SIZE_4*95/100);
                mergeSort(arr5[i], 0, SIZE_5*95/100);
            }
        break;
    case 6:
            for(int i{0}; i<100; i++)
            {
                mergeSort(arr1[i], 0, SIZE_1*99/100);
                mergeSort(arr2[i], 0, SIZE_2*99/100);
                mergeSort(arr3[i], 0, SIZE_3*99/100);
                mergeSort(arr4[i], 0, SIZE_4*99/100);
                mergeSort(arr5[i], 0, SIZE_5*99/100);
            }
        break;
    case 7:
            for(int i{0}; i<100; i++)
            {
                mergeSort(arr1[i], 0, SIZE_1*997/1000);
                mergeSort(arr2[i], 0, SIZE_2*997/1000);
                mergeSort(arr3[i], 0, SIZE_3*997/1000);
                mergeSort(arr4[i], 0, SIZE_4*997/1000);
                mergeSort(arr5[i], 0, SIZE_5*997/1000);
            }
        break;
    case 8:
            for(int i{0}; i<100; i++)
            {
                mergeSortDOWN(arr1[i], 0, SIZE_1);
                mergeSortDOWN(arr2[i], 0, SIZE_2);
                mergeSortDOWN(arr3[i], 0, SIZE_3);
                mergeSortDOWN(arr4[i], 0, SIZE_4);
                mergeSortDOWN(arr5[i], 0, SIZE_5);
            }
        break;
    default:
        return 1;
        break;
    }
    
    for(int i=0; i<100; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            quickSort(arr1[i], 0, SIZE_1-1);
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            T1[i] = elapsed.count();



            start = std::chrono::high_resolution_clock::now();
            quickSort(arr2[i], 0, SIZE_2-1);
            finish = std::chrono::high_resolution_clock::now();
            elapsed = finish - start;
            T2[i] = elapsed.count();


            start = std::chrono::high_resolution_clock::now();
            quickSort(arr3[i], 0, SIZE_3-1);
            finish = std::chrono::high_resolution_clock::now();
            elapsed = finish - start;
            T3[i] = elapsed.count();
            

            start = std::chrono::high_resolution_clock::now();
            quickSort(arr4[i], 0, SIZE_4-1);
            finish = std::chrono::high_resolution_clock::now();
            elapsed = finish - start;
            T4[i] = elapsed.count();


            start = std::chrono::high_resolution_clock::now();
            quickSort(arr5[i], 0, SIZE_5-1);
            finish = std::chrono::high_resolution_clock::now();
            elapsed = finish - start;
            T5[i] = elapsed.count();
            
        }
    std::ofstream outdata;
    switch (option)
    {
    case 1:
        outdata.open("quicksortA.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 2:
        outdata.open("quicksortB.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 3:
        outdata.open("quicksortC.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 4:
        outdata.open("quicksortD.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 5:
        outdata.open("quicksortE.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 6:
        outdata.open("quicksortF.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 7:
        outdata.open("quicksortG.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    case 8:
        outdata.open("quicksortH.txt");
        for(int i{0}; i<100; i++)
        {outdata<<T1[i]<<'\t'<<T2[i]<<'\t'<<T3[i]<<'\t'<<T4[i]<<'\t'<<T5[i]<<std::endl;}
        outdata.close();
        break;
    default:
        break;
    }
    

    return 0;
}