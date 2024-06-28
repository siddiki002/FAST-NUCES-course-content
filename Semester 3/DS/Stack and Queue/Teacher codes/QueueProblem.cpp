#include <iostream>
using namespace std;

#define MAX 5

// Queue using Array
class Queue{
	int front, rear;
	int arr[MAX];
	int count;
	
	public:
	Queue(){
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
			count--;
			return d;
		}
		else{
			d = arr[front];
			arr[front] = INT_MIN;
			front = (front + 1) % MAX;
			count--;
			return d;
		}
	}
	
	int getCount(){
		return count;
	}
	
	void displayArr(){
		if (isEmpty())
			return;
		cout << "\displaying queue elements:" << endl;
		for (int a = 0; a < MAX; a++)
			cout << arr[a] << " ";
		cout << endl;
	}
	
	void displayQueue(){
		if (isEmpty())
			return;

		cout << "\ndisplaying queue elements:" << endl;
		int i =front, c = 0;
		while (c < count){
			cout << arr[i] << " ";
			i = (i + 1) % MAX;
			c++;
		}
	}
};

Queue reverse(Queue q)
{
	// Size of queue
	int s = q.getCount();
	// Second queue
	Queue ans;

	for (int i = 0; i < s; i++) {

		// Get the last element to the
		// front of queue
		for (int j = 0; j < q.getCount() - 1; j++) {
			int x = q.dequeue();
			q.enqueue(x);
		}

		// Get the last element and
		// add it to the new queue
		ans.enqueue(q.peek());
		q.dequeue();
	}
	return ans;
}

int main()
{
	Queue q;
	
	// Insert elements
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.displayQueue();

	q = reverse(q);

	// Print the queue
	q.displayQueue();

	return 0;
}
