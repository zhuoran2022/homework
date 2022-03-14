#include<iostream>
#include<Windows.h>
#include<stdlib.h>
using namespace std;

const int N = 3000000;
int a[N], A[N];

int main(){
	
	for(int n=1024; n<131072+1; n*=2){

		//initialize
		int sum = 0;
		for(int i=0; i<n; i++){
			a[i] = rand()%100;
			//a[i] = i+1;
			A[i] = a[i];
		}

		//start time
		long long head, tail, freq;//timers
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);

	

		int cnt = 1000;//count circle time
		while(cnt--){

			//singleline-unroll
			/*for(int i=0; i+1<n; i+=2){
				sum+=a[i];
				sum+=a[i+1];
			}*/
		
			//multiline-unroll
			for(int m = n; m>1; m/=2){
				for(int i = 0; i+1<m/2; i+=2){
					a[i] = a[i*2]+a[i*2+1];
					a[i+1] = a[(i+1)*2]+a[(i+1)*2+1];
				}
			}
			sum = a[0]+a[1];

			//recover
			for(int i=0; i+3<n; i+=4)
			{
				a[i] = A[i];
				a[i+1] = A[i+1];
				a[i+2] = A[i+2];
				a[i+3] = A[i+3];
			}
			if(cnt)sum = 0;
		}

		//out
		cout<<sum<<endl;

		//end time
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		cout<<"n="<<n<<" multiline: "<<(tail-head)*1000.0/freq<<"ms"<<endl;
		//cout<<"n="<<n<<" singleline: "<<(tail-head)*1000.0/freq<<"ms"<<endl;
	}

return 0;
}