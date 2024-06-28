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

class qs { 
  public: 
    int low, high;
    qs(){};
    qs(int l, int h):low(l),high(h){};
};

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *a, int low, int high){
	int pivot = a[high];
	int pivot_index = low;
	
	for (int j = low; j < high; j++){
		// Just move smaller than pivot numbers to left, 
		// larger than pivot will automatically be left 
		// on the right side of the pivot.
		if (a[j] < pivot){
			swap(&a[j], &a[pivot_index]);
			pivot_index++;
		}
	}
	
	swap(&a[pivot_index], &a[high]);
	return pivot_index;
}

void quicksort(int *a, int low, int high){
	Stack<qs> s;
	s.push(qs(low, high));
	while(!s.isEmpty()){
		low = s.peek().low;
		high = s.peek().high;
		s.pop();
		
		if (low < high){
			int pivot_index = partition(a, low, high);
			
			// previously made recursive calls
			// quicksort(a, low, pivot_index - 1);
			// quicksort(a, pivot_index + 1, high);

			if (low < pivot_index)
				s.push(qs(low, pivot_index - 1));
			if (pivot_index < high)
				s.push(qs(pivot_index + 1, high));
		}
	}
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
	int a[6] = {3,9,8,2,5,6};
	int n = sizeof(a)/sizeof(a[0]);
	quicksort(a, 0, n-1);
	printArray(a, n);
	return 0;
}
