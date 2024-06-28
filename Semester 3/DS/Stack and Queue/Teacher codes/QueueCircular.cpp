#include <iostream>
using namespace std;

#define MAX 4

// Queue using Array
class QueueCircular{
	int front, rear;
	int arr[MAX];
	int count;
	
	public:
	QueueCircular(){
		front = rear = -1;
		count = 0;
	}
	
	bool isEmpty(){
		return (front == -1 && rear == -1);
	}
	
	bool isFull(){
		return ((rear + 1) % MAX == front);
	}
	
	bool enqueue(int d){
		// if Queue is full
		if(isFull())
			return false;
		
		if (isEmpty()){
			front = rear = 0;
			arr[rear] = d;
		}
		else{
			rear = (rear + 1) % MAX;
			arr[rear] = d;
		}
		count++;
//		cout << "front: " << front << " rear: " <<rear <<endl;
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
//			cout << "front: " << front << " rear: " <<rear <<endl;
			return d;
		}
		else{
			d = arr[front];
			arr[front] = INT_MIN;
			front = (front + 1) % MAX;
//			cout << "front: " << front << " rear: " <<rear <<endl;
			return d;
		}
		count--;
		
	}
	
	int getCount(){
		return count;
	}
	
	void displayArr(){
		if (isEmpty())
			return;
		cout << "\n displaying queue elements:" << endl;
		for (int a = 0; a < MAX; a++)
			cout << arr[a] << " ";
		cout << endl;
	}
	
	void displayQueue(){
		if (isEmpty())
			return;

		cout << "\n displaying queue elements:" << endl;
		int i =front, c = 0;
		while (c < count-1){
			cout << arr[i] << " ";
			i = (i + 1) % MAX;
			c++;
		}
	}
};

int main(){
	QueueCircular q;
	cout << "Enqueue 10, 20, 30 and 40 to the Queue."<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	cout << "Count: " << q.getCount() << endl;
	cout << "isFull: "<<q.isFull() << endl;
	cout << "Peek: "<<q.peek() << endl;
	cout << "Dequeue: "<<q.dequeue() << endl;
	cout << "Dequeue: "<<q.dequeue() << endl;
	cout << "Enqueue 50: "<<q.enqueue(50) << endl;
	cout << "isEmpty: "<<q.isEmpty() << endl;
	q.displayArr();
	q.displayQueue();
	return 0;
}
