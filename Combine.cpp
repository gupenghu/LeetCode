#include <stdio.h>
#include <stdlib.h>

void print_allcombine(int m, int n);
void allcombine(int *source, int m, int n, int *dest, int dest_len);
void print_array(int *arr, int sz);

int main( int argc, char *argv[])
{
	if (argc != 3 ){
		printf("please input two numbers\n");
		return -1;
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	print_allcombine(m, n);
	return 0;
}

void print_allcombine(int m,int n) {
	int *source = (int*)malloc(sizeof(int) * m);
	int *dest = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < m; i++){
		source[i] = i + 1;
	}
	allcombine(source, m, n, dest, n);
	free(source);
	free(dest);
}

void allcombine(int *source, int m, int n, int *dest, int dest_len) {
	if (n == 0) {
		print_array(dest, dest_len);
		return;
	}
	//选定一个，简化为从m - 1个数中找出n-1个数
	for (int i = m; i >= n; --i)
	{
		dest[n - 1] = source[i - 1];
		allcombine(source, i - 1, n - 1, dest, dest_len);
	}
}

void print_array(int *arr, int sz) {
	for (int i = 0; i < sz; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}