#include <iostream>
using namespace std;

int reverse(int x){
	int reversed = 0;
	int sign = false;

	if(x < 0){
		x = -x;
		sign = true;
	}
	
	while(x > 0){
		reversed = reversed * 10 + x % 10;
		x = x / 10;
	}
	return reversed;
}


int main(){
	int num;
	cin>>num;
	cout<<"reverse of "<<num<<" is "<<reverse(num);
	return 0;
}
