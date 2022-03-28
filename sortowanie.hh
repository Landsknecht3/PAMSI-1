#include <cmath>
#include <algorithm>

#define SIZE_1 10000
#define SIZE_2 50000
#define SIZE_3 100000
#define SIZE_4 500000
#define SIZE_5 1000000


template <typename T>
void merge(T arr[], int begin, int mid, int end)
{
    int i {begin}, j {mid+1}, k {0};
    T arr_temp[end-begin+1];


    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
            arr_temp[k++]=arr[i++];
        else
            arr_temp[k++]=arr[j++];
    }

    while(i<=mid)
    {
        arr_temp[k++]=arr[i++];
    }
    while(j<=end)
    {
        arr_temp[k++]=arr[j++];
    }
    j=begin; i=0;
    while(i<k)
    {
        arr[j++]=arr_temp[i++];
    }
}

template <typename T>
void mergeSort(T arr[], int begin, int end)
{
    if(end<=begin){return;}

    int mid = (begin+end)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

template <typename T>
void mergeDOWN(T arr[], int begin, int mid, int end)
{
    int i {begin}, j {mid+1}, k {0};
    T arr_temp[end-begin+1];


    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
            arr_temp[k++]=arr[i++];
        else
            arr_temp[k++]=arr[j++];
    }

    while(i<=mid)
    {
        arr_temp[k++]=arr[i++];
    }
    while(j<=end)
    {
        arr_temp[k++]=arr[j++];
    }
    j=begin; i=0;
    while(i<k)
    {
        arr[j++]=arr_temp[i++];
    }
}

template <typename T>
void mergeSortDOWN(T arr[], int begin, int end)
{
    if(end<=begin){return;}

    int mid = (begin+end)/2;
    mergeSortDOWN(arr, begin, mid);
    mergeSortDOWN(arr, mid+1, end);
    mergeDOWN(arr, begin, mid, end);
}


template <typename T>
int partition(T arr[], int begin, int end)
{
	int i {begin-1}, j {end+1};
	T pivot{arr[(begin+end)/2]}; //wybieramy punkt odniesienia

        while(1)
	    {
		    while(pivot>arr[++i]);
		    while(pivot<arr[--j]);
		    if( i <= j)
			    std::swap(arr[i],arr[j]);
		    else
			    break;
	    }
    return i;
}

template <typename T>
void quickSort(T *arr, int begin, int end)
{
	if(end<=begin)
        return;
	
    int p = partition(arr, begin, end);
	quickSort(arr, begin, p-1);
	quickSort(arr, p, end);
}

template <typename T>
void siftdown(T arr, int start, int end)
{
    int root {start};
    while(2*root+1<=end)
    {
        int child {2*root+1}, swap {root};
        if(arr[swap]<arr[child])
            swap = child;
        if(arr[swap]<arr[child+1] && child+1<=end)
            swap=child+1;
        if(swap==root)
            return;
        else
        {
            std::swap(arr[root], arr[swap]);
             root = swap;
        }
    }
}

template <typename T>
void heapify(T arr[], int end)
{
    int start {(end-1)/2};
    while(start>=0)
    {
        siftdown(arr, start, end);
        start--;
    }
}
template <typename T>
void heapSort(T arr[], int end)
{
    heapify(arr, end);
    int n {end};
    while(n>0)
    {
        std::swap(arr[n], arr[0]);
        n--;
        siftdown(arr, 0, n);
    }
}


template <typename T>
bool check_heapify(T arr[], int begin, int end)
{
    for(int i {begin}; i<=(end-1)/2; i++)
    {
        if(arr[2*i+1-begin]>arr[i])
            return false;
        if (arr[2*i+2-begin]>arr[i])
            return false;
        i++;
        
    }
    return true;
}

template <typename T>
void insertSort (T arr[], int begin, int end)
{
    for(int i=begin+1; i <= end; i++)
    {
        T insert = arr[i];
        int j {i-1};
        while(j>begin-1 && arr[j]>insert)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = insert;
    }
}

template <typename T>
void introSort(T arr[], int begin, int end, int maxdepth)
{
	if(end-begin+1<=16)
        insertSort(arr, begin, end);
//    else if(maxdepth == 0)
//        heapSort(arr, end);
    else
    {
        int p = partition(arr, begin, end);
        introSort(arr, begin, p-1, maxdepth-1);
        introSort(arr, p, end, maxdepth-1);
    }
}

template <typename T>
void sort(T arr[], int end)
{
    int maxdepth {static_cast<int>(std::floor(2*std::log2(end+1)))};
    introSort(arr, 0, end, maxdepth);
}

template <typename T>
bool check(T arr[], int begin, int end)
{
    for(int i {begin}; i<end; i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}