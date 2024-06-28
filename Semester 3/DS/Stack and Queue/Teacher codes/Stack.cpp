#include <iostream>
using namespace std;

#define MAX 50

// Stack using Array
class Stack{
	int top;
	int arr[MAX];
	// size?
	
	public:
	Stack(){
		top = -1;
	}
	
	bool push(int d){
		// if stack is full
		if(top >= MAX-1)
			return false;
		
		top++;
		arr[top] = d;
		return true;
	}
	
	bool isEmpty(){
		return (top < 0);
	}
	
	int peek(){
		if (isEmpty()){
			return INT_MIN;
		}
		return arr[top];
	}
	
	int pop(){
		if (isEmpty()){
			return INT_MIN;
		}
		int d = arr[top];
		top--;
		return d;
	}
	
	int getTop(){
		return top;
	}
	
	// isFull?
	
	void display(){
		if (isEmpty())
			return;
		
		cout << "\displaying stack elements:" << endl;
		for (int a = 0; a <= top; a++)
			cout << arr[a] << endl;
	}
};

int main(){
	Stack s;
	cout << "Top: "<<s.getTop() << endl;
	cout << "Add 10, 20, and 30 to the Stack."<<endl;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "Peek: "<<s.peek() << endl;
	cout << "Pop: "<<s.pop() << endl;
	cout << "isEmpty: "<<s.isEmpty() << endl;
	cout << "Top: "<<s.getTop() << endl;
	s.display();
	return 0;
}
