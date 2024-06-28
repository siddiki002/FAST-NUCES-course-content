#include <iostream>
using namespace std;

#define MAX 5

// Queue using Array
class Queue{
	int front, rear;
	int arr[MAX];
	int priority[MAX];
	
	public:
	Queue(){
		front = rear = -1;
	}
	
	bool isEmpty(){
		return (front == -1 && rear == -1);
	}
	
	bool isFull(){
		return (rear == MAX-1);
	}
	
	bool enqueue(int d, int p){
		// if Queue is full
		if(isFull())
			return false;
		
		if (isEmpty()){
			front = rear = 0;
			arr[rear] = d;
			priority[rear] = p;
		}
		else{
			int x;
			for (x = rear; x>=front; x--){
				if(p > priority[x]){
					arr[x + 1] = arr[x];
					priority[x + 1] = priority[x];
				}
				else
					break;
			}
			arr[x + 1] = d;
			priority[x + 1] = p;
			rear++;
		}
		return true;
	}
	
	int peek(){
		if (isEmpty()){
			return INT_MIN;
		}
		return arr[front];
	}
	
	int dequeue(){
		if (isEmpty()){
			return INT_MIN;
		}
		int d;
		// if queue gets empty after dequeue
		// then reset queue
		if (front == rear){		
			d = arr[front];
			front = rear = -1;
			return d;
		}
		else{
			d = arr[front];
			arr[front] = INT_MIN;
			front++;
			return d;
		}
	}
	
	int count(){
    	return (rear - front + 1);
    }
	
	void display(){
		if (isEmpty())
			return;
		
		cout << "\ndisplaying queue elements:" << endl;
		for (int a = front; a <= rear; a++)
			cout << arr[a] << " " << priority[a] << endl;
	}
};

int main(){
	Queue q;
	cout << "Enqueue 10, 20, and 30 to the Queue."<<endl;
	q.enqueue(10, 1);
	q.enqueue(20, 2);
	q.enqueue(30, 3);
	q.display();
	cout << "Count: " << q.count() << endl;
	cout << "Peek: "<<q.peek() << endl;
	cout << "Dequeue: "<<q.dequeue() << endl;
	cout << "isEmpty: "<<q.isEmpty() << endl;
	q.display();
	return 0;
}
