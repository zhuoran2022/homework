#include<iostream>
#include<Windows.h>
#include<stdlib.h>
using namespace std;

int main(){

	for(int n = 500; n<=1000; n+=100){

		//initialize
		int *a = new int[n];
		int *sum = new int[n];

		int **b = new int*[n];
		for(int i=0; i<n; i++){
			b[i] = new int[n];
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				b[i][j] = rand()%100;
			}
		}
		for(int i=0; i<n; i++)a[i] = i+1;
	
		//start time
		long long head, tail, freq;//timers
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);

		int cnt = 1000;//count circle time
		while(cnt--){
	
			//column_priority
			for(int j=0; j<n; j++){
				sum[j] = 0;
				for(int i=0; i<n; i++){
					sum[j]+=b[i][j]*a[i];
				}
			}

			//row_priority
			for(int i=0; i<n; i++)sum[i] = 0;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					sum[j]+=b[i][j]*a[i];
				}
			}

		}

		//out
		//when n reach 1000, out is so much that
		//it hinders our observation of the execution time, so note it
		/*for(int i=0; i<n; i++){
			cout<<sum[i]<<" ";
		}
		cout<<endl;*/

		//end time
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		cout<<"n="<<n<<" Col: "<<(tail-head)*1000.0/freq<<"ms"<<endl;
		//cout<<"n="<<n<<" Row: "<<(tail-head)*1000.0/freq<<"ms"<<endl;
		
		//avoid memory leak
		for(int i=0; i<n; i++)delete b[i];
		delete b;
		delete a;
		delete sum;

	}

return 0;
}