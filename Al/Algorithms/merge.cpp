/* IN THIS ASSIGNMENT WE HAVE TWO FILE input.txt and output.txt
input.txt FILE contain unsorted element,which we need to Sort
out.txt FILE cuurently empty file it contain the value of input.txt in sorted form*/
#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[], int low, int mid, int high)
{
    int temp[100000];
	int k = low, i = low, j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)
		temp[k++] = arr[i++];

	while (j<= high)
		temp[k++] = arr[j++];

	for (int i = low; i <= high; i++)
		 arr[i] = temp[i];
}
void MergeSort(int arr[],int low, int high)
{
	if (high <= low)
		return;
	int mid = (low + ((high - low) >> 1));
	MergeSort(arr,low, mid);
	MergeSort(arr, mid + 1, high);
	Merge(arr,low, mid, high);
}

int main(){
    int a[100000];
    FILE *fp;
    char ch;
    int i=0;
    fp=fopen("input.txt","r");
    if(fp==NULL)
	{
	printf("\n Cannot open the file \n");
	exit(0);
	}
	while(ch!=EOF)
	{
	fscanf(fp,"%d",&a[i]);
	ch=fgetc(fp);
	i++;
	}
    int n=i-1;
    cout<<"INPUT FILE DATA BEFORE SORT"<<endl;
    cout<<"\n ";
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
    cout<<"\n\n";
    ofstream ofs;
    ofs.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    // Sort Present here
   // Here we use i=1 because array start with index 0.
     MergeSort(a,0,n-1);
     // End of sort
     fstream file;
     file.open ("output.txt", ios::out | ios::in );
     cout<<"FILE DATA AFTER SORT"<<endl;
     cout<<"\n ";
     for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
         file <<a[i]<<" ";
     }
     file.close();
    return 0;
}
