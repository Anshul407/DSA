#include<iostream>
using namespace std;
void repl(string str,string pat,string rep){
	
		int cnt=0;
	    int j=0;
	
	for(int i=0;i<str[i]!='\0';i++){
		if(str[i]==pat[j]){
		
			j++;
			
			cnt++;
			if(j==pat.size())
			break;
		}
		else{
			cnt=0;
			j=0;
		}
	}
		int key=0;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==pat[0]){
			key=i;
		}
	
	}
	int patvalue=0;
	for(int i=0;pat[i]!='\0';i++){
		patvalue++;
	}
	if(cnt==patvalue){
		int j=0;
		for(int i=key;pat[j]!='\0';i++){
			str[i]=rep[j];
		j++;
		
		}
	}
	cout<<str;

	
	

	
	
	
}
int main(){
	string str;
	string pat;
	string rep;
	cin>>str>>pat>>rep;

	repl(str,pat,rep);

	
		
}