// Initialize recursive function simulation: 
// Returned result will be stored in retval 
#include <iostream>
#include <limits>
using namespace std;

template <typename Type>
class Node{
	public:
	Type data;
	Node* next;
	
	Node(){
		data = 0;
		next = NULL;
	}
	Node(Type d){
		data = d;
		next = NULL;
	}
};

template <typename Type>
class Stack{
	Node<Type>* root;
	
	public:
		Stack(){
			root = NULL;
		}
		
		void push(Type d){
			Node<Type>* n = new Node<Type>(d);
			n->next = root;
			root = n;
		}
		
		bool isEmpty(){
			return !root;
		}
		
		Type peek(){
			if(isEmpty())
				return numeric_limits<Type>::min();
				
			return root->data;
		}
		
		Type pop(){
			if(isEmpty())
				return numeric_limits<Type>::min();
			
			Node<Type>* temp = root;
			Type d = temp->data;
			root = root->next;
			delete temp;
			return d;
		}
		
		void display(){
			if(isEmpty())
				return;
			
			cout << "\ndisplaying stack elements:" << endl;
			Node<Type>* t = root;
			while(t != NULL){
				cout << t->data << endl;
				t = t->next;
			}
		}
};

class f_record { 
  public: 
    int n; 		// f's argument 
    int line; 	// current line in f 
    int k, r; 	// local variables 
    f_record(){};
    f_record(int arg):n(arg),line(0) { } 
}; 

int main(){
	int retval; 
	int x = 2;
	Stack<f_record> S; 	// stack of active calls 
	S.push(f_record(x)); 	// call f(x) 
	
	// While there's an active function call left 
	while(!S.isEmpty()) { 
	  f_record curr = S.pop(); 
	  int LINE = curr.line++; 
	  if (LINE == 0) { 
	    if (curr.n == 0) 
	      retval = 0; 
	    else 
	      S.push(curr); 
	  } 
	  else if (LINE == 1) { 
	    curr.k = curr.n*curr.n; 
	    S.push(curr); 
	  } 
	  else if (LINE == 2) { 
	    f_record recurse(curr.n - 1); 
	    S.push(curr); S.push(recurse); 
	  }
	  else if (LINE == 3) { 
	    curr.r = retval; 
	    S.push(curr); 
	  } 
	  else if (LINE == 4)
	    retval = curr.k + curr.r; 
	} 
	int y = retval;
	cout << y;
}

