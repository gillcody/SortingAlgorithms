/*
Author: Cody Gill
File Name: sort.h
*/


#define MAX_LEN 100  
#define FALSE 0
#define TRUE 1

/* A linked list node containing a string and length */
struct bucket_entry
{
    char *str;
    size_t len;
    struct bucket_entry *next;
};
typedef struct bucket_entry bucket_entry;

/* A linked list */
struct bucket
{
    bucket_entry *head;
    bucket_entry *tail;
};
typedef struct bucket bucket;



//PROTOTYPES

//QUICK SORT
//int
int partition_int (int arr[], int low, int high);
void quickSort_int(int arr[], int low, int high);
//string
int partition_str (char arr[][MAX_LEN], int low, int high);
void quickSort_str(char arr[][MAX_LEN], int low, int high);

//MERGE SORT 
//int
void merge_int(int arr[],int low,int mid,int high);
void mergeSort_int(int arr[],int low,int high);
//str
void merge_str(char arr[][MAX_LEN],int low,int mid,int high);
void mergeSort_str(char arr[][MAX_LEN],int low,int high);

//RADIX SORT
//int
void countSort(int arr[], int n, int exp);
int getMax(int arr[], int n);
void radixsort_int(int arr[], int n);
//str
void bucket_strings(bucket_entry *head, bucket *buckets, unsigned int c);
bucket_entry *merge_buckets(bucket *buckets);
void copy_list(const bucket_entry *head, char strings[][MAX_LEN]); 
void radix_sort_string(char strings[][MAX_LEN], size_t len); 
void print_buckets(const bucket *buckets);
void print_list(const bucket_entry *head);
static void init_buckets(bucket *buckets);

//HEAP SORT
//int
void heapify(int arr[], int n, int i);
void heapSort_int(int arr[], int n);
//str

//INSERTION SORT
//str
void InsertionSort_str(char list[][MAX_LEN], int n);
//int
void insertionSort_int(int arr[], int n);

//SELECTION SORT
//int
void selectionSort_int(int arr[], int n);
//str


//BUBBLE SORT
//int
void swap(int *xp, int *yp);
void bubbleSort_int(int arr[], int n);
//str
void bubbleSort_str(char arr[][MAX_LEN], int n);

void clearbuff();
