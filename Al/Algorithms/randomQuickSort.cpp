/*
Roll no :- 194CA014
randomized Qucik sort
For this program we need two files input.txt , output.txt
input file contain data and output file is empty
*/
#include<bits/stdc++.h>
using namespace std;
int Random_Partition(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = Random_Partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
int n=10000;
int a[n];
srand(time(NULL));
for(int i = 0; i < n; i++)
        a[i] = rand()%n+1;
cout<<"INPUT FILE DATA BEFORE SORT"<<endl;
cout<<"\n ";
for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
cout<<"\n\n";
quickSort(a,0,n-1);
 cout<<"FILE DATA AFTER SORT"<<endl;
 cout<<"\n ";
 for(int i=0;i<n;i++){
     cout<<a[i]<<" ";
 }
return 0;
}
/*
this code for if we have input file and want to store the data in output file
as we Cannot upload more then 5 file,
so for this we need input file for input data
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
     quickSort(a,0,n-1);
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
}*/
