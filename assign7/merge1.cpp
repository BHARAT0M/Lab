#include<bits/stdc++.h>
using namespace std;
int N;
void MergeA(int arr[], int low, int mid, int high,int f);
void MergeSortA(int arr[],int low, int high,int f);
void MergeSort(string arr[],int low, int high,int f);
void Merge(string arr[], int low, int mid, int high,int f)
{
    string temp[N];
	int k = low, i = low, j = mid + 1;
	while (i <= mid && j <= high)
	{
      if(f==0){
		if (arr[i].compare(arr[j])<0)
		    temp[k++].assign(arr[i++]);
		else
			 temp[k++].assign(arr[j++]);
      }
      else{
          if (arr[i].compare(arr[j])>0)
			 temp[k++].assign(arr[i++]);
		else
		   temp[k++].assign(arr[j++]);
      }
	}
	while (i <= mid)
	      temp[k++].assign(arr[i++]);

	while (j<= high)
	       temp[k++].assign(arr[j++]);

	for (int i = low; i <= high; i++)
		  arr[i].assign(temp[i]);
}
void MergeSort(string arr[],int low, int high,int f)
{
	if (high <= low)
		return;
	int mid = (low + ((high - low) >> 1));
	MergeSort(arr,low, mid,f);
	MergeSort(arr, mid + 1, high,f);
	Merge(arr,low, mid, high,f);
}
void MergeA(int arr[], int low, int mid, int high,int f)
{
    int temp[N];
	int k = low, i = low, j = mid + 1;
	while (i <= mid && j <= high)
	{
      if(f==0){
		if (arr[i]<=arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
      }
      else{
          if (arr[i]>=arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
      }
	}
	while (i <= mid)
		temp[k++] = arr[i++];

	while (j<= high)
		temp[k++] = arr[j++];

	for (int i = low; i <= high; i++)
		 arr[i] = temp[i];
}
void MergeSortA(int arr[],int low, int high,int f)
{
	if (high <= low)
		return;
	int mid = (low + ((high - low) >> 1));
	MergeSortA(arr,low, mid,f);
	MergeSortA(arr, mid + 1, high,f);
	MergeA(arr,low, mid, high,f);
}

int main()
{
    int f,ch;
    char choice;
    do{
    cout<<"\n\tEnter 0 for input as integer and 1 for string"<<endl;
    cout<<"\t";
     cin>>ch;
    cout<<"\n\tEnter no of element \n";
    cout<<"\t";
    cin>>N;
    fflush(stdin);
    string s[N];
    int arr[N];
    if(ch==1){
    cout<<"\n\tEnter Values "<<endl;
    for(int i=0;i<N;i++){
        fflush(stdin);
        cout<<"\t";
        getline(cin,s[i]);
    }
    cout<<"\n\tFor ascending order press 0 \n\tFor descending order press 1\n";
    cout<<"\t";
    cin>>f;
    MergeSort(s,0,N-1,f);
    cout<<"\t";
    for(int i=0;i<N;i++){
        cout<<s[i]<<"  ";
    }
    }else{
        cout<<"\n\tEnter Values "<<endl;
        for(int i=0;i<N;i++){
            cout<<"\t";
            cin>>arr[i];
        }
    cout<<"\n\tFor ascending order press 0 \n\tFor descending order press 1\n";
    cout<<"\t";
    cin>>f;
   MergeSortA(arr,0, N - 1,f);
   cout<<"\t";
   for (int i = 0; i < N; i++)
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n\tPress y for more input"<<endl;
    cout<<"\t";
    cin>>choice;
}while(choice=='y'||choice=='Y');
    return 0;
}
