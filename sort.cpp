#include <stdio.h>
#include <stdlib.h>

define N 100
void swap(int *a, int *b) {
	if (a == b){
		return;
	}
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_arry(int *arr,int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void max_adjust(int *arr, int i, int sz) {
	int max;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	while (true){
		if (l < sz && arr[l] > arr[i]){
			max = l;
		}
		else{
			max = i;
		}
		if (r < sz && arr[r] > arr[max]){
			max = r;
		}

		if (max != i) {
			swap(&arr[max], &arr[i]);
		}
		else
			break;
		i = max;
		l = 2 * max + 1;
		r = 2 * max + 2;
	}
}
void heap_sort(int *arr, int sz) {
	for (int i = (sz - 1) / 2; i >= 0; i--)
	{
		max_adjust(arr, i, sz);
	}
	for (size_t i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	for (int i = sz - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		max_adjust(arr, 0, i);;
	}
}

//[first,second)
int partition(int *arr,int first,int second){
	int select = arr[first];
	int mid = first;
	for (int i = first + 1; i < second; ++i)
	{
		if (arr[i] < select)
		{
			swap(&arr[i],&arr[++mid]);
		}
	}
	swap(&arr[mid],&arr[first]);
	return mid;
}

int partition2(int *arr,int first,int second){
	int select = arr[first];
	int begin = first;
	int end = second - 1;
	while(begin < end){
		while(begin < end && arr[end] > select) end--;
		if(begin < end ) arr[begin] = arr[end];
		while(begin < end && arr[begin] <= select) begin++;
		if(begin < end ) arr[end] = arr[begin];
	}
	arr[begin] = select;
	return begin;
}

void quick_sort(int *arr,int first ,int second){
	if (first + 1>= second)
	{
		return;
	}
	
	int pvoit = partition2(arr,first,second);
	quick_sort(arr,first,pvoit);
	quick_sort(arr,pvoit + 1,second);
}


void merge(int *arr,int begin,int privot,int end){
	//move first half to another space
	int *A = (int*)malloc((privot - begin) * sizeof(int));
	for(int i = begin;i < privot;i++){
		A[i - begin] = arr[i];
	}
	int *B = arr + privot;
	int m = 0;//A flag
	int n = 0;//B flag
	for (int i = begin; i < end; ++i)
	{
		int min;
		if (m + begin < privot && n + privot < end)	
			min = A[m] < B[n] ? A[m++]:B[n++];
		else if (m  + begin >= privot)		
			min = B[n++];
		else						
			min = A[m++];
		arr[i] = min;
	}
	free(A);
}
//[first,second)
void merge_sort(int *arr,int first,int second){
	if (first + 1 >= second)
	{
		return;
	}
	int prvoit = (first + second)/2;
	merge_sort(arr,first,prvoit);
	merge_sort(arr,prvoit,second);
	merge(arr,first,prvoit,second);
}

vood permute(int *arr,sz){
	for (int i = sz; i > 0; ++i)
	{
		swap(&arr[i - 1],arr[rand()%i]);
	}
}
int main()
{
	int A[N] = {0};
	
	printf("heap_sort sort ===========================\n");
	heap_sort(A, N);
	print_arry(A,N);
	printf("quick_sort sort ===========================\n");
	quick_sort(A,0,N);
	print_arry(A,N);
	printf("merge sort ===========================\n");
	merge_sort(A,0,N);
	print_arry(A,N);
	return 0;
}