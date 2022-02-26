//#include<iostream>
//#include<Windows.h>
//#include<stdlib.h>
//using namespace std;
//
//const int N = 100010;
//int a[N], A[N], sum = 0;
//int n = 4096*16, cnt = 1000;//输入规模 重复次数
//
//void recursion(int n){
//	if(n == 1)return;
//	for(int i=0; i<n/2; i++){
//		a[i]+=a[n-i-1];
//		//cout<<a[i]<<" ";
//	}
//	//for(int i=0; i<=n/2; i++)cout<<a[i]<<" ";
//	//cout<<endl;
//	n/=2;
//	recursion(n);
//}
//
//int main(){
//
//	//int nn = n;
//	long long head, tail, freq;//timers
//	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
//	//start time
//	QueryPerformanceCounter((LARGE_INTEGER*)&head);
//
//	for(int i=0; i<n; i++){
//		a[i] = rand();
//		//a[i] = i+1;
//		A[i] = a[i];
//	}
//
//	while(cnt--){
//	//平凡算法
//	for(int i=0; i<n; i++)sum+=a[i];
//	//优化算法
//	//recursion(n);sum = a[0];
//
//	//for(int m = n; m>1; m/=2){
//	//	for(int i = 0; i<m/2; i++){
//	//		a[i] = a[i*2]+a[i*2+1];
//	//		//cout<<a[i]<<" ";
//	//	}
//	//	//cout<<endl;
//	//}
//	//sum = a[0];
//
//	for(int i=0; i<n; i++)a[i] = A[i];
//	if(cnt)sum = 0;
//	}
//
//	//输出
//	cout<<sum<<endl;
//
//	//end time
//	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
//	cout<<"Col: "<<(tail-head)*1000.0/freq<<"ms"<<endl;
//
//return 0;
//}
///*
//8
//1 2 3 4 5 6 7 8
//*/