#include<iostream>
using namespace std;
void create(int arr[],int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}
void disp(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void insert(int arr[],int n,int pos , int elem){
	n++;
    for ( int i = n-1; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=elem;
    for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void deletion(int arr[],int n,int pos){
	 --pos;
   for(int i=pos;i<n;i++)
   {
    arr[i]=arr[i+1];
   }
    for(int i=0;i<n-1;i++){
		cout<<arr[i]<<" ";
	}
    
}


int main(){
	int n;
	int pos,elem;
    int arr[10];
	char c;
	x: 
	cout<<"Enter what you want"<<endl;
	cin>>c;
	switch(c){
		case 'c':
			cout<<endl<<"Enter size of array"<<endl;
			cin>>n;
			create(arr,n);
			goto x;
		case 'v':
			disp(arr,n);
			cout<<endl;
			goto x;
		case 'i':
			cout<<endl<<"Enter the position where you want to insert"<<endl;
			cin>>pos;
			cout<<endl<<"Enter the element to insert"<<endl;
			cin>>elem;
			insert(arr,n,pos,elem);
			cout<<endl;
			goto x;
		case 'd':
			cout<<endl<<"Enter the position where you want to delete"<<endl;
			cin>>pos;                                               
			deletion(arr,n,pos);
			cout<<endl;
			goto x;
		default:
			cout<<"not valid";
			break;
		
	}

	
	
	

}