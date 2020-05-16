#include<bits/stdc++.h>
using namespace std;
void selectSort(string s[],int n,int f){
    int min;
for(int i=0;i<n-1;i++){
 min=i;
 for(int j=i+1;j<n;j++){
     if(f){
         if(s[j].compare(s[min])>0)
           min=j;
     }else{
         if(s[j].compare(s[min])<0)
          min=j;
     }
 }
 string t;
 t.assign(s[i]);
   s[i].assign(s[min]);
   s[min].assign(t);
}
}
void selectSort1(int arr[],int n,int f){
    int min;
for(int i=0;i<n-1;i++){
 min=i;
 for(int j=i+1;j<n;j++){
     if(f){
         if(arr[j]>arr[min])
           min=j;
     }else{
         if(arr[j]<arr[min])
          min=j;
     }
 }
 int t=arr[i];
  arr[i]=arr[min];
   arr[min]=t;
}
}
int main(){
    int f,ch,N;
    char choice;
    do{
    cout<<"\n\tEnter 0 for input as integer and 1 for string"<<endl;
    cout<<"\t";
	cin>>ch;
    cout<<"\tEnter no of element \n";
    cout<<"\t";
	cin>>N;
    fflush(stdin);
    string s[N];
    int arr[N];
    if(ch==1){
    cout<<"\tEnter Values "<<endl;
    for(int i=0;i<N;i++){
        fflush(stdin);
        cout<<"\t";
		getline(cin,s[i]);
    }
    cout<<"\n\tFor ascending order press 0 \n\tFor descending order press 1\n";
    cout<<"\t"; cin>>f;
    selectSort(s,N,f);
    cout<<"\t";
    for(int i=0;i<N;i++){
        cout<<s[i]<<"  ";
    }
    }else{
        cout<<"\tEnter Values "<<endl;
        for(int i=0;i<N;i++){
            cout<<"\t";
			cin>>arr[i];
        }
    cout<<"\n\tFor ascending order press 0 \n\tFor descending order press 1\n";
    cout<<"\t";
	cin>>f;
    selectSort1(arr,N,f);
    cout<<"\t";
    for (int i = 0; i < N; i++)
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n\tPress Y for more input"<<endl;
    cout<<"\t";
	cin>>choice;
}while(choice=='y'||choice=='Y');
    return 0;
}
