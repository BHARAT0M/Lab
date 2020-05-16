#include<bits/stdc++.h>
using namespace std;
struct bank{
    string branch;
    int loan_no;
    int amount;
};
int seq_Search(struct bank b[],int N,int key,int f,string str){
for(int i=0;i<N;i++){
    if(f){
       if((b[i].loan_no)==key || b[i].amount==key)
          return 1;
     }
   else{
       if((b[i].branch).compare(str)==0)
        return 1;
   }
}
return 0;
}
int binarySearch(struct bank b[],int l,int h,int key,int f,string str){
if(l<=h){
    int mid=(l+h)/2;
    if(f==1){
       if((b[mid].loan_no)==key)
            return 1;
        else if(key<b[mid].loan_no){
            return  binarySearch(b,l,mid-1,key,f,str);
        }
        else{
          return binarySearch(b,mid+1,h,key,f,str);
        }
     }
     else if(f==2){
         if(b[mid].amount==key){
             return 1;
         }
         else if(key<b[mid].amount){
             return  binarySearch(b,l,mid-1,key,f,str);
         }
         else{
            return binarySearch(b,mid+1,h,key,f,str);
         }
     }
   else{
       if((b[mid].branch).compare(str)==0)
        return 1;
        else if((b[mid].branch).compare(str)>0){
            return  binarySearch(b,l,mid-1,key,f,str);
        }
        else if((b[mid].branch).compare(str)<0){
          return binarySearch(b,mid+1,h,key,f,str);
        }
   }
}
return 0;
}
void display(struct bank s[],int n){
    cout<<"\n\n\t########################### DATA ################################\n";
    cout<<"\n\tBRANCH NAME\t\t\tLOAN NUMBER\t\t\tAMOUNT\n";
    for(int i=0;i<n;i++){
        cout<<"\n\t";
        cout<<s[i].branch<<"\t\t\t\t"<<s[i].loan_no<<"\t\t\t\t"<<s[i].amount<<endl;
    }
    cout<<"\n\t#################################################################\n";
}
int main(){
    int N;
    cout<<"\n\tEnter no of data entry\n";
    cout<<"\t";
    cin>>N;
    struct bank b[N];
    cout<<"\n\tDeatails Are...."<<endl;
    for(int i=0;i<N;i++){
        cout<<"\n\tEntry for "<<i+1<<"\n\t";
        cout<<"\n\tBranch name\t";
        fflush(stdin);
        getline(cin,b[i].branch);
        cout<<"\n\t Loan no \t";
        cin>>b[i].loan_no;
        cout<<"\n\t Amount \t";
        cin>>b[i].amount;
    }
    char choice;
    do{
    string keyword="\0";
    int key=0,f,ans,flag;
    cout<<"\n\n\tEnter 1 for Display the deatial\n\t  2 for Sequential Search\n\t  3 for Binary Search"<<endl;
    cout<<"\t";
    cin>>flag;
    if(flag==1)
       display(b,N);
    else{
    cout<<"\n\tPress 0 for searching branch name \n\t\t1 for loan no and 2 for amount \n";
    cout<<"\t";
    cin>>f;
    if(f){
        cout<<"\n\tEnter key value you want to search\t";
        fflush(stdin);
        cin>>key;
    }
    else{
        cout<<"\n\tEnter key value you want to search\t";
        fflush(stdin);
        getline(cin,keyword);
    }
     if(flag==2)
      ans=seq_Search(b,N,key,f,keyword);
     else
      ans=binarySearch(b,0,N-1,key,f,keyword);
    if(ans){
            cout<<"\n\tRecord is founded"<<endl;;
       }
    else{
            cout<<"\n\tRecord is NOT founded"<<endl;
     }
    }
    fflush(stdin);
    cout<<"\n\t Enter y for Do more operation \t";
    cin>>choice;
 }while(choice=='y'||choice=='Y');
     return 0;
}
