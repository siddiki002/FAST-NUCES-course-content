#include <iostream>
using namespace std;
#include <limits> 

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
			
			cout << "\n displaying stack elements:" << endl;
			Node<Type>* t = root;
			while(t != NULL){
				cout << t->data << endl;
				t = t->next;
			}
		}
};

template <typename Type>
bool balancedParenthesis(Stack<Type> s, string str){
	char c;
	
	for (int a = 0; a < str.length(); a++){
		if (str[a] == '(' || str[a] == '{' || str[a] == '['){
			s.push(str[a]);
		}
		
		else{
			// when there is a closing in str 
			// but no opening in stack
			if (s.isEmpty())
				return false;
			
			switch(str[a]){
				case ')':
					c = s.pop();
					if (c == '('){
						break;
					}
					else{
						return false;
					}
				case '}':
					c = s.pop();
					if (c == '{'){
						break;
					}
					else{
						return false;
					}
				case ']':
					c = s.pop();
					if (c == '['){
						break;
					}
					else{
						return false;
					}
			}
		}
	}
	
	if (!s.isEmpty())
		return false;
	return true;
}

int main(){
	Stack<char> s;
	string str = "{()}[{}([])]";
 
    // Function call
    if (balancedParenthesis<char>(s, str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
	
	return 0;
}
