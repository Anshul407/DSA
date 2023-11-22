#include <iostream>
using namespace std;

void push(int stack[], int &size, int &top, int elem) {
    if (top == size - 1) {
        cout << "Overflow" << endl;
    } else {
        stack[++top] = elem;
    }
}

void pop(int stack[], int &size, int &top) {
    if (top == -1) {
        cout << "Underflow" << endl;
    } else {
        cout << stack[top--] << " popped" << endl;
    }
}

void topelm(int stack[], int &size, int top) {
    if (top == -1) {
        cout << "Underflow" << endl;
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}
bool pal(int stack[],int &size,int top){
	int f=0,l=top;
	while(f<top){
		if(stack[f]!=stack[l]){
			return 0;
		}
		f++,l--;
	}
	return 1;
	
}

int main() {
    int size = 5;
    int st[size];
    int elem;
    int top = -1;
    int choice;

    while (true) {
        cout << "Enter 1 for push, 2 for pop, 3 for display top element, 4 for checking overflow and underflow ,5 to check palindrom, 6 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> elem;
                push(st, size, top, elem);
                break;

            case 2:
                pop(st, size, top);
                break;

            case 3:
                topelm(st, size, top);
                break;

            case 4:
                if (top == size - 1) {
                    cout << "Overflow" << endl;
                } else if (top == -1) {
                    cout << "Underflow" << endl;
                } else {
                    cout << "No Overflow or Underflow" << endl;
                }
                break;

            case 5:
            	if(pal(st,size,top)){
				
            	cout<<"Palindrom"<<endl;
            	
            }
            else{
            	cout<<"not a palindrome"<<endl;
			}
			break;
            	
            case 6:
                return 0;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
