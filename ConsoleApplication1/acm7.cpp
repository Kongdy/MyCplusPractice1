#include<iostream>
#include<sstream>

using namespace std;

const int N = 20;

void mergeArray(int a[], int first, int mid, int last, int temp[]);
void mergeSort(int a[], int first, int last, int temp[]);

int main() {

	int count;
	cin >> count;
	while (count-->0) {
		int xs[N];
		int ys[N];
		int house;
		cin >> house;
		for (size_t i = 0; i < N && i < house; i++)
		{
			cin >> xs[i] >> ys[i];
		}
		int *tempXs = new int[house];
		int *tempYs = new int[house];
		mergeSort(xs,0,house-1,tempXs);
		mergeSort(ys, 0, house-1, tempYs);
		
		int result = 0;
		for (size_t i = 0; i < house/2; i++)
		{	
			result += xs[house - 1 - i] - xs[i] + ys[house - 1 - i] - ys[i];
		}
		cout << result << endl;
	}
}

void mergeArray(int a[],int first,int mid,int last,int temp[]) {

	int i = first, j = mid + 1, k = 0, m = mid, n = last;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}

	while (i <= m)
	{
		temp[k++] = a[i++];
	}

	while (j <= n)
	{
		temp[k++] = a[j++];
	}

	for (size_t i = 0; i < k; i++)
	{
		a[i + first] = temp[i];
	}

}

void mergeSort(int a[],int first,int last,int temp[]) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(a,first,mid,temp);
		mergeSort(a,mid+1,last,temp);
		mergeArray(a,first,mid,last,temp);
	}
}