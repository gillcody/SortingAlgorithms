/*
Author: Cody Gill
File Name: sort.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "sort.h"

//SEARCH FUNCTIONS
//Linear int
int linearSearchIterative_int(int data[], int n, int target)
{
	int i;
	for (i = 0; i < n; i++)
	if (data[i] == target)
		return i;

	return -1;
}
//Linear str
int linearSearchIterative_str(char data[][MAX_LEN], int n, char target[][MAX_LEN])
{
	int i; 
	for (i = 0; i < n; i++)
	{
		if (strcmp(data[i],target[0])==0)
		{
			return i;
		}
	}
	return -1;
}
//Binary int
int BinarySearchIterative_int(int data[], int n, int target)
{ // data is sorted
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (data[mid] == target) return mid;
		else if (data[mid] < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
//Binary str
int BinarySearchIterative_str(char data[][MAX_LEN], int n, char target[][MAX_LEN])
{ // data is sorted
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (strcmp(data[mid],target[0])==0) return mid;
		else if (strcmp(data[mid],target[0])<0) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}



//HEAP SORT FUNCTIONS
//Heap int
void heapify_int(int b[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int left = 2*i + 1; // left = 2*i + 1 
    int right = 2*i + 2; // right = 2*i + 2 
    
    int temp;
    // If left child is larger than root 
    if (left < n && b[left] > b[largest]) 
        largest = left; 
        
    // If right child is larger than largest so far 
    if (right < n && b[right] > b[largest]) 
        largest = right; 
        
    // If largest is not root 
   
    if (largest != i) 
    { 
        temp = b[i];
        b[i] = b[largest];
        b[largest] = temp;
        // Recursively heapify the affected sub-tree 
        heapify_int(b, n, largest); 
    } 
} 
void heapSort_int(int b[], int n) 
{ 
    int temp, i;
    // Build heap (rearrange array) 
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify_int(b, n, i); 
  
    // One by one extract an element from heap 
    for (i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        temp = b[0];
        b[0] = b[i];
        b[i] = temp;
  
        // call max heapify on the reduced heap 
        heapify_int(b, i, 0); 
    } 
}
//Heap String
void heapify_str(char list[][MAX_LEN], int n, int i) 
{ 
    
    int largest = i; // Initialize largest as root 
    int left = 2*i + 1; // left = 2*i + 1 
    int right = 2*i + 2; // right = 2*i + 2 

    char temp[MAX_LEN];
    // If left child is larger than root 
    if (left < n && (strcmp(list[left],list[largest])> 0))
    {	 
        largest = left; 
    }
  
    // If right child is larger than largest so far 
    if (right < n && (strcmp(list[right],list[largest])>0)) 
    {
        largest = right; 
    }
    // If largest is not root  
    if (largest != i) 
    { 
        strcpy(temp, list[i]);
        strcpy(list[i], list[largest]);
        strcpy(list[largest], temp);
        // Recursively heapify the affected sub-tree 
        heapify_str(list, n, largest); 
    }
} 
void heapSort_str(char list[][MAX_LEN], int n) 
{ 
    int i;
    char temp[MAX_LEN];
    // Build heap (rearrange array) 
    
    for (i = n / 2 - 1; i >= 0; i--) 
    {
        heapify_str(list, n, i); 
    }
    // One by one extract an element from heap 
    for (i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        strcpy(temp, list[0]);
        strcpy(list[0], list[i]);
        strcpy(list[i], temp);
        // call max heapify on the reduced heap 
        heapify_str(list, i, 0); 
    } 
    
} 



//INSERTION SORT
//Insertion int
void insertionSort_int(int arr[], int n)
{
	int i, k, j;
	
	for(i = 1; i < n; i++)
	{
		k = arr[i];
		j = i -1;
		
		while(j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		
		arr[j + 1] = k;
	}
}
//Insertion string
void InsertionSort_str(char list[][MAX_LEN], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int j = i;

        while (j > 0 && strcmp(list[j - 1], list[j]) > 0)
        {
            char tmp[MAX_LEN];
            strncpy(tmp, list[j - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(list[j - 1], list[j], sizeof(list[j - 1]) - 1);
            list[j - 1][sizeof(list[j - 1]) - 1] = '\0';

            strncpy(list[j], tmp, sizeof(list[j]));
            list[j][sizeof(list[j]) - 1] = '\0';

            --j;
        }
    }
} 



//MERGE SORT
//Merge int
void merge_int(int arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    //allocate memory for left and right
    int* L = (int *) malloc(sizeof(int)*nL);
    int* R = (int *) malloc(sizeof(int)*nR);
    
    int i, j ,k;
    //copy data to left and right
    for(i=0;i<nL;i++)
    {
        //L = malloc(sizeof(arr[low+i]));
        L[i] = arr[low+i];
    }
    for(i=0;i<nR;i++)
    {
        //R = malloc(sizeof(arr[mid+i+1]));
        R[i] = arr[mid+i+1];
    }
    //merge
    j=0;
    i=0;
    k=low;
    
    while(i<nL && j<nR)
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else 
        {
            arr[k++] = R[j++];
        }
    }
    //copy remaining left
    while(i<nL)
    {
        arr[k++] = L[i++];
    }
    //copy remaining right
    while(j<nR)
    {
        arr[k++] = R[j++];
    }
}
void mergeSort_int(int arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort_int(arr,low,mid);
        mergeSort_int(arr,mid+1,high);
        merge_int(arr,low,mid,high);
    }
}
//Merge String
void merge_str(char arr[][MAX_LEN],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0;i<nL;i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}
void mergeSort_str(char arr[][MAX_LEN],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort_str(arr,low,mid);
        mergeSort_str(arr,mid+1,high);
        merge_str(arr,low,mid,high);
    }
}



//QUICK SORT
//Quick int
int partition_int (int arr[], int low, int high) 
{ 
    int temp, j;
    int pivot = arr[(high+low)/2];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        } 
    } 
    // Swapping array elemnents
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1); 
} 
void quickSort_int(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition_int(arr, low, high); 
        // Separately sort elements before 
        // partition and after partition 
        quickSort_int(arr, low, pi - 1); 
        quickSort_int(arr, pi + 1, high); 
    } 
} 
//Quick String
int partition_str (char arr[][MAX_LEN], int low, int high) 
{ 
    char temp[1][MAX_LEN]; //to store temp variable
    int j;
    char* pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (strcmp((arr[j]), (pivot)) <= 0)
        { 
            i++;    // increment index of smaller element 
            temp[0][0] = *arr[i];
            *arr[i] = *arr[j];
            *arr[j] = temp[0][0]; 
        } 
    } 
    // Swapping array elemnents
    temp[0][0] = *arr[i + 1];
    *arr[i + 1] = *arr[high];
    *arr[high] = temp[0][0];
    return (i + 1); 
} 
void quickSort_str(char arr[][MAX_LEN], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition_str(arr, low, high);
        // Separately sort elements before 
        // partition and after partition 
        quickSort_str(arr, low, (pi - 1)); 
        quickSort_str(arr, (pi + 1), high); 
    } 
} 



//SELECTION SORT
//Selection int
void selectionSort_int(int arr[], int n)
{
	int lh, rh, i, temp;
	
	for(lh = 0; lh < n; lh++)
	{
		rh = lh;
		
		for(i = lh + 1; i < n; i++)
		{
			if(arr[i] < arr[rh])
			rh = i;
		}
		
		temp = arr[lh];
		arr[lh] = arr[rh];
		arr[rh] = temp;
	}
}
//Selection String
void selectionSort_str(char arr[][MAX_LEN], int n) 
{ 
    int i, j, min_idx; 
   
    // One by one move boundary of unsorted subarray 
    char minStr[MAX_LEN]; 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        int min_idx = i; 
        strcpy(minStr, arr[i]); 
        for (j = i+1; j < n; j++) 
        { 
            // If min is greater than arr[j] 
            if (strcmp(minStr, arr[j]) > 0) 
            { 
                // Make arr[j] as minStr and update min_idx 
                strcpy(minStr, arr[j]); 
                min_idx = j; 
            } 
        } 
   
        // Swap the found minimum element with the first element 
        if (min_idx != i) 
        { 
            char temp[MAX_LEN]; 
            strcpy(temp, arr[i]); //swap item[pos] and item[i] 
            strcpy(arr[i], arr[min_idx]); 
            strcpy(arr[min_idx], temp); 
        } 
    } 
} 


//BUBBLE SORT
//Bubble int
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}  
void bubbleSort_int(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
//Bubble String
void bubbleSort_str(char arr[][MAX_LEN], int n) 
{ 
    char temp[MAX_LEN]; 
    int j, i;
    // Sorting strings using bubble sort 
    for (j=0; j<n-1; j++) 
    { 
        for (i=j+1; i<n; i++) 
        { 
            if (strcmp(arr[j], arr[i]) > 0) 
            { 
                strcpy(temp, arr[j]); 
                strcpy(arr[j], arr[i]); 
                strcpy(arr[i], temp); 
            } 
        } 
    } 
} 



//RADIX SORT
//Radix int
void countSort(int b[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++)
    {  
        count[ (b[i]/exp)%10 ]++; 
    }
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (b[i]/exp)%10 ] - 1] = b[i]; 
        count[ (b[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        b[i] = output[i]; 
} 
int getMax(int b[], int n) 
{ 
    int mx = b[0]; 
    int i;
    for (i = 1; i < n; i++) 
        if (b[i] > mx) 
            mx = b[i]; 
    return mx; 
} 
void radixSort_int(int b[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(b, n); 
    int exp;
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for ( exp = 1; m/exp > 0; exp *= 10) 
        countSort(b, n, exp); 
}

//Radix String
/* Initialise buckets */
static void init_buckets(bucket *buckets)
{
    unsigned int b;
    for (b = 0; b < 256; b++) {
        buckets[b].head = NULL;
        buckets[b].tail = NULL;
    }
}
/*
 * Turn entries into a linked list of words with their lengths
 * Return the length of the longest word
 */
static size_t init_entries(char strings[][MAX_LEN], size_t len, bucket_entry *entries)
{
    unsigned int s;
    size_t maxlen = 0;
    for (s = 0; s < len; s++) {
        entries[s].str = strings[s];
        entries[s].len = strlen(strings[s]);
        if (entries[s].len > maxlen) {
            maxlen = entries[s].len;
        }
        if (s < len - 1) {
            entries[s].next = &entries[s + 1];
        }
        else {
            entries[s].next = NULL;
        }
    }
    return maxlen;
}
 
/* Put strings into buckets according to the character c from the right */
void bucket_strings(bucket_entry *head, bucket *buckets, unsigned int c)
{
    bucket_entry *current = head;
    while (current != NULL) {
        bucket_entry * next = current->next;
        current->next = NULL;
        int pos = current->len - 1 - c;
        unsigned char ch;
        if (pos < 0) {
            ch = 0;
        }
        else {
            ch = current->str[pos];
        }
        if (buckets[ch].head == NULL) {
            buckets[ch].head = current;
            buckets[ch].tail = current;
        }
        else {
            buckets[ch].tail->next = current;
            buckets[ch].tail = buckets[ch].tail->next;
        }
        current = next;
    }
}
 
/* Merge buckets into a single linked list */
bucket_entry *merge_buckets(bucket *buckets)
{
    bucket_entry *head = NULL;
    bucket_entry *tail;
    unsigned int b;
    for (b = 0; b < 256; b++) {
        if (buckets[b].head != NULL) {
            if (head == NULL) {
                head = buckets[b].head;
                tail = buckets[b].tail;
            }
            else {
                tail->next = buckets[b].head;
                tail = buckets[b].tail;
            }
        }
    }
    return head;
}
 
void copy_list(const bucket_entry *head, char strings[][MAX_LEN])
{
    const bucket_entry *current;
    unsigned int s;
    for (current = head, s = 0; current != NULL; current = current->next, s++) {
        strcpy(strings[s], current->str);
    }
}
 
void radix_sort_string(char strings[][MAX_LEN], size_t len)
{
    size_t maxlen;
    unsigned int c;
    bucket_entry *head;
    bucket_entry *entries = malloc(len * sizeof(bucket_entry));
    bucket *buckets = malloc(256 * sizeof(bucket));
    if (!entries || !buckets) {
        free(entries);
        free(buckets);
        return;
    }
    init_buckets(buckets);
    maxlen = init_entries(strings, len, entries);
    head = &entries[0];
    /* Copy back into array */
    copy_list(head, strings);
    free(buckets);
    free(entries);

}
