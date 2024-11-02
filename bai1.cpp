#include <iostream> //cin, cout
using namespace std;
//#include<stdio.h> - scanf printf
#define MAX 100
#include <stdlib.h> //standard library
#include <time.h>
// void taoMang(int a[], int &n)
// {
// 	do
// 	{
// 		cout<<"Nhap vao so luong phan tu can su dung: ";
// 		cin>>n; //scanf("%d", &n);
// 	}while(n<1 || n>MAX); //n=[1..MAX];
// 	srand(time(0)); 
// 	for(int i=0; i<n; i++) //Duyet tu dau mang den cuoi mang
// 		a[i] = rand()%100; //tao mot so nguyen duong ngau nhien
// 		//min?0 - max?99
// }

// void xuatMang(int a[], int n)
// {
// 	for(int i=0; i<n; i++) //Duyet tu dau mang den cuoi mang
// 		cout<<a[i]<<"\t";
// 	cout<<endl; //end line
// 	//cout<<"\n";
// }

// void Sort(int a[], int n)
// {
// 	for(int i=0; i<n-1; i++)
// 		for(int j=i+1; j<n; j++)
// 			if(a[i] < a[j])
// 				swap(a[i], a[j]);
// }

// void TimMaxK(int a[], int n)
// {
// 	int k;
// 	do
// 	{
// 		cout<<"Nhap vao k: ";
// 		cin>>k;
// 	}while(k<1 || k>n); //k=[1..n];
	
// 	Sort(a, k);
// 	int h;	
// 	for(int t=k; t<n; t++)
// 	{
// 		int cur = a[t];
// 		for(h=k-1; h>=0; h--)
// 			if(cur > a[h])
// 				a[h+1] = a[h];
// 			else break;
// 		a[h+1] = cur;
// 		xuatMang(a, n);
// 	}
// 	cout<<"Phan tu lon thu "<<k<<" la: "<<a[k-1]<<endl;
// }
int main()
{
	// int a[MAX], n;
	// taoMang(a, n); //tao mang a gom n phan tu co gia tri ngau nhien
	// xuatMang(a, n);
	// TimMaxK(a, n);
	printf("heloo");
}