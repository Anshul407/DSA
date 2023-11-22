#include<iostream>
using namespace std;
void replace(string s,string p,string r){
    int cnt=0;
    int j=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==p[j]){
            cnt++;
            j++;
            if(j==p.size())break;
        }
        else{
            j=0;
            cnt=0;
        }
        
    }
    int key=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==p[0])key=i;
    }
     j=0;
    if(cnt==p.length()){
        for (int i = key;p[j]!='\0'; i++)
        {
            /* code */
            s[i]=r[j];
            j++;
        }
        
    }
   cout<<s;
    

}
int main(int argc, char const *argv[])
{
    string s,r,p;
    cin>>s>>p>>r;
    replace(s,p,r);
    return 0;
}
