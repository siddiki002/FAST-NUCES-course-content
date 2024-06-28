#include<iostream>
using namespace std;

void towerofHanoi(int n, char src, char dest, char helper){
	if(n==0) {
		return;	//base case
	}
	
	towerofHanoi(n-1, src, helper, dest);
	cout<<"Move from "<<src<<" to "<<dest<<endl;	// move nth or last piece
	towerofHanoi(n-1, helper,dest, src);
}

int main(){
	towerofHanoi(3, 'A', 'C', 'B');
	return 0;
}
