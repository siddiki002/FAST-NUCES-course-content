#include<iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class ArrayIndexOutOfBoundsException;

template <typename Type>
class DynArr
{
	private:
		Type* arr;
		int size;
		int capacity;
		
	public:
		enum { SPARE_CAPACITY = 10 };
		
		// Constructor
		DynArr(int size_=0){
			// Todo: check size can be zero or negative
			size = size_;
			capacity  = size + SPARE_CAPACITY;
			arr = new(nothrow) Type[capacity];
			
			for (int i=0;i<size;i++){
				arr[i] = 0;
			}
		}
		
		// Copy constructor
		DynArr(const DynArr& otherObject){
			size= otherObject.size;
			capacity = otherObject.capacity;
			
			arr = new(nothrow) Type[size];
			for(int i=0;i<size;i++){
				arr[i] = otherObject.arr[i];
			}
		}
		
		// Assignment operator
		DynArr& operator=(const DynArr& rightObject){
			if (this != &rightObject){
				size = rightObject.size;
				capacity = rightObject.capacity;
				
				delete [] arr;
				arr = new(nothrow) Type[capacity];
				for (int i=0;i<size;i++){
					arr[i] = rightObject.arr[i];
				}
			}
			return *this;
		}
		
		// Access operator
		Type& operator[](int index){
			if (index < 0 || index >= size){
				throw ArrayIndexOutOfBoundsException();
			}
			return arr[index];
		}
		
		// Destructor
		~DynArr(){
			delete [] arr;
		}
		
		// PushBack
		void pushBack(int val){
			if(size == capacity){
				Type* new_arr = new(nothrow) Type[2*capacity];
				for (int i=0;i<size;i++){
					new_arr[i] = arr[i];
				}
				delete arr;
				arr = new_arr;
				capacity = 2*capacity;
			}
			arr[size++]=val;
		}
		
		// Remove
		void remove(int index){
			if(index <0 || index >= size){
				throw ArrayIndexOutOfBoundsException();
			}
			for (int i=index;i<size-1;i++){
				arr[i] = arr[i+1];
			}
			size -= 1;
		}
		
		// Size
		int getSize(){
			return size;
		}
		
		// print array
		void printArray(){
			for (int i=0;i< size;i++){
				cout<<arr[i]<<",";
			}
			cout<<endl;
		}
};

class ArrayIndexOutOfBoundsException : public std::exception
{
	public:
	const char * what () const throw ()
    {
    	return "Exception: Index out of bound!";
    }
};

// Implementation of Priority Queue as Max Heap
class MaxHeap{
    // left child of `A[i]`
    int getLeft(int i) {
        return (2*i + 1);
    }
 
    // right child of `A[i]`
    int getRight(int i) {
        return (2*i + 2);
    }
    
    // Recursive sift-down algorithm.
    void sift_down(DynArr<int> &A, int i, int size)
    {
        // get left and right child of node at index `i`
        int left = getLeft(i);
        int right = getRight(i);
 
        int largest = i;
        
        // compare `A[i]` with its left and right child
        // and find the largest value
        if (left < size && A[left] > A[i]) {
            largest = left;
        }
 
        if (right < size && A[right] > A[largest]) {
            largest = right;
        }
 
        // swap with a child having greater value and
        // call sift-down on the child
        if (largest != i)
        {
            swap(A[i], A[largest]);
            sift_down(A, largest, size);
        }
    }
 
	public:
    // Function to remove an element with the highest priority (present at the root)
    int extractMax(DynArr<int> &A, int size) 		// pop
    {
        try {
            // if the heap has no elements, throw an exception
            if (size == 0)
            {
                throw out_of_range("index is out of range(Heap underflow)");
            }
 
			// getMax
			int max = A[0];
			// replace the root of the heap with the last element
			A[0] = A[size-1];
			// no need to remove last element
			// as it will shink the array by one.
			// So there will be no free space to place the
			// extracted value at the back of the array.
 
            // call sift-down on the root node
            sift_down(A, 0, size-1);
            return max;
        }
        // catch and print the exception
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
    
	// Constructor (Build-Heap step)
    MaxHeap(DynArr<int> &A, int n)
    {
        // call sift_down starting from the last internal node all the
        // way up to the root node
        int i = (n - 2) / 2;
        while (i >= 0) {
            sift_down(A, i--, n);
        }
    }
};

// Function to perform heapsort on array `A` of size `n`
void heapsort(DynArr<int> &A, int n)
{
    // build a priority queue and initialize it by the given array
    MaxHeap mh(A, n);

    // repeatedly extractMax from the heap till it becomes empty
    while (n > 0)
    {
        A[n - 1] = mh.extractMax(A, n);
        n--;
    }
}

int main()
{
	DynArr<int> A;
	A.pushBack(6);
	A.pushBack(4);
	A.pushBack(7);
	A.pushBack(1);
	A.pushBack(9);
	A.pushBack(2);
	int n  = A.getSize();

    // perform heapsort on the array
    heapsort(A, n);
 
    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
 
    return 0;
}
