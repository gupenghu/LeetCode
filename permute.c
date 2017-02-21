void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int *arr,int sz){
	for (int i = sz; i > 0; i--)
	{
		swap(&arr[rand()%i],&arr[i - 1]);
	}
}