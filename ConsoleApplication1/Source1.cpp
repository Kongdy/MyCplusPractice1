#include<iostream>
#include<sstream>
#include<math.h>
#include<time.h>

const int MAX_AREA = 20;

using namespace std;

void mergeSort(float a[], int first, int last, float temp[]);
void mergeArray(float a[], int first, int mid, int last, float temp[]);

/*
 * ACM 6 
 * @author wangk
 */
int main3() {
	int count;
	cin >> count;
	while (count -- >0)
	{
		int sprayDevicecount = 0;
		cin >> sprayDevicecount;
		float ris[600];
		for (size_t i = 0; i < sprayDevicecount; i++)
		{
			cin>>ris[i];
		}

		// sort by asc,merge sort
		float *temp = new float[sprayDevicecount];
		time_t startTime = time(NULL);
		mergeSort(ris,0,sprayDevicecount-1,temp);
		time_t endTime = time(NULL);
		time_t sortTime = endTime - startTime;
		long time = sortTime;
		float *area = new float[sprayDevicecount];
		int needCount = 0;
		float tempArea = 0;
		// caclute area
		for (size_t i = 0; i < sprayDevicecount; i++)
		{
			if (tempArea < MAX_AREA) {
				needCount++;
				tempArea += sqrt(ris[i] * ris[i] - 1)*2.0;
			}
			
		}
		cout << needCount << endl;
	}
	system("pause");
	return 0;
}

void mergeArray(float a[], int first, int mid, int last, float temp[]) {

	int i = first, j = mid + 1, k = 0, m = mid, n = last;
	while (i <= m && j <= n)
	{
		if (a[i] >= a[j]) {
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
	while (j <= n) {
		temp[k++] = a[j++];
	}

	for (size_t i = 0; i < k; i++)
	{
		a[i + first] = temp[i];
	}
}

void mergeSort(float a[], int first, int last, float temp[]) {

	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(a, first, mid, temp);
		mergeSort(a, mid + 1, last, temp);
		mergeArray(a, first, mid, last, temp);
	}
}


