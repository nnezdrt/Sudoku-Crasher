//2*10^8 multiple operations per second(about)
#include <iostream>
#include <thread>
#include <ctime>
using namespace std;

const int MAX_SIZE = 5000; //matrix's size
const int MOD = 32767;
int a[MAX_SIZE][MAX_SIZE],
	b[MAX_SIZE][MAX_SIZE],
	c[MAX_SIZE][MAX_SIZE], //a*b = c
	d[MAX_SIZE][MAX_SIZE]; //for threads

void init(){
	//make random matrixes for the calculation
	srand(time(0));
	for (int i=0;i<MAX_SIZE;++i){
		for (int j=0;j<MAX_SIZE;++j){
			a[i][j] = rand() % MOD;
			b[i][j] = rand() % MOD;
			c[i][j] = d[i][j] = 0;
		}
	}
}
void _thread_cal(int from,int to){
	for (int k=from;k<to;++k){
		for (int i=0;i<MAX_SIZE;++i){
			for (int j=0;j<MAX_SIZE;++j){
				d[i][k] += a[i][j] * b[j][k];
			}
		}
	}
}
void normal_cal(){
	for (int k=0;k<MAX_SIZE;++k){
		for (int i=0;i<MAX_SIZE;++i){
			for (int j=0;j<MAX_SIZE;++j){
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
}
bool judge(){
	for (int i=0;i<MAX_SIZE;++i){
		for (int j=0;j<MAX_SIZE;++j){
			if (c[i][j] != d[i][j]){
				cout << "in " << i << " " << j << " : " << c[i][j] << " and " << d[i][j] << endl;
				return false;
			}
		}
	}
	return true;
}
int main(){
	init();
	cout << "initiating accomplished" << endl;
	time_t t = clock();
	normal_cal();
	cout << "normal calculation time used: " << clock()-t << " ms" << endl;
	t = clock();
	//create two threads to calculate
	thread t1{[](){_thread_cal(0,MAX_SIZE/2);}},
			t2{[](){_thread_cal(MAX_SIZE/2, MAX_SIZE);}};
	t1.join();
	t2.join();
	cout << "thread calculation time used: " << clock()-t << " ms" << endl;
	if (!judge()){
		cout << "but the calculation is not correct" << endl;
	}else{
		cout << "and the calculation is correct" << endl;
	}
	return 0;
}
