
//范围[begin,end)
//当前查找不一定保证有序性，可以让其尝试实现一个保证有序的版本（找出num首次出现的位置）
int binary_search(int *arr, int begin,int end,int num) {
	while (begin < end){
		int mid = begin + (end - begin) / 2;
		if (arr[mid] < num){
			begin = mid;
		}
		else if(arr[mid] > num){
			end = mid;
		}
		else{
			return mid;
		}
	}
	return -1;
}