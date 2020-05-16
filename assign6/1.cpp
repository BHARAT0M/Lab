#include <bits/stdc++.h>
using namespace std;
int prec(char c);
class stackk
{
private:
	int size;
	int top;
	char *array;
public:
	stackk(int x)
	{
		size = x;
		top = -1;
		array = new char[x];
	}
	void push(char x)
	{
		if(isFull())
		{
			cout << " Stack is Full\n";
			return;
		}
		array[++top] = x;
	}
	void pop()
	{
		if(isEmpty())
		{
			cout << " Stack is empty\n";
			return;
		}
		top--;
	}
	int peek()
	{
		if(isEmpty())
		{
			return -1;
		}
		return array[top];
	}
	bool isFull()
	{
		return top == size-1;
	}
	bool isEmpty()
	{
		return top == -1;
	}
};
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
int main()
{
	int temp;
	cout << " Size of stack : ";
	cin >> temp; 
	stackk st(temp);
        string s,str;
        cout<<"ENTER A expression"<<endl;
        fflush(stdin);
        cin>>s;
        int k=s.length(); 
        for(int i = 0; i<k; i++) 
        {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
          str+=s[i]; 
         else if(s[i] == '('||s[i]=='[') 
               st.push('('); 
         else if(s[i] == ')') 
         { 
            while(st.peek()!=-1 && st.peek() != '(') 
            { 
                char c = st.peek(); 
                st.pop(); 
                str+= c; 
            } 
            if(st.peek() == '(') 
            { 
                char c = st.peek(); 
                st.pop(); 
            } 
         } 
       else if(s[i] == ']') 
         { 
            while(st.peek()!=-1 && st.peek() != '[') 
            { 
                char c = st.peek(); 
                st.pop(); 
                str+= c; 
            } 
            if(st.peek() == '[') 
            { 
                char c = st.peek(); 
                st.pop(); 
            } 
          } 
        else{ 
            while(st.peek()!=-1 && prec(s[i]) <= prec(st.peek())) 
            { 
                char c = st.peek(); 
                st.pop(); 
                str+= c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
 
    while(st.peek()!=-1) 
    { 
        char c = st.peek(); 
        st.pop(); 
        str+= c; 
    } 
  //   int l=str.length();
   //  str[l-1]='\0'; 
    cout <<str<< endl; 
  return 0;
}
