/* IN THIS ASSIGNMENT WE HAVE TWO FILE input.txt and output.txt
input.txt FILE contain unsorted element,which we need to Sort
out.txt FILE cuurently empty file it contain the value of input.txt in sorted form*/
#include<bits/stdc++.h>
using namespace std;
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

    //Insertion Sort Present here
   // Here we use i=1 because array start with index 0.
    for (int i = 1; i < n; ++i) {
        int val = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            j--;
        }
        a[++j] = val;
     }
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
