#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return -1;
}
int main(int argc, char const *argv[])
{
    stack<char>st;
    string s="(a+b)*c";
    for (int i = 0; i <s.length(); i++)
    {
        /* code */
       if(isalnum(s[i])){
        cout<<s[i];
       }
       else if(s[i]=='('){
        st.push(s[i]);
       }
       else if(s[i]==')'){
        while(st.top()!='('&&!st.empty()){
            cout<<st.top();
            st.pop();
        }
        if(!st.empty()){
            st.pop();
        }
       }
       else{
        while(!st.empty()&&precedence(s[i])<=precedence(st.top())){
            cout<<st.top();
            st.pop();
        }
        st.push(s[i]);
       }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }

    return 0;
}
