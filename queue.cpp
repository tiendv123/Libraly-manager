//Cai dat danh sach lien ket bang mang
#include<bits/stdc++.h>
using namespace std;
#ifndef _queue__cpp_
#define _queue__cpp_
template<class T>
class Queue
{
	T*a;
	int n,cap,F,L;
	public:
		Queue(int c=1) // Contructor
		{
			cap=c;
			n=0;
			F=0;L=-1;
			a=new T[cap];
		}
		~Queue(){delete []a;} // Detructor
		void push(T x) // Them vao cuoi queue
		{
			if(n==cap)
			{
				int newcap=2*cap+1;
				T*b=new T[newcap];
				for(int i=F,j=0;i<F+cap;i++,j++) b[j]=a[i%cap];
				F=0,L=cap-1;
				cap=newcap;
				delete[]a;
				a=b;
			}
			L=(L+1)%cap;
			a[L]=x;
			n++;
		}
		
		void pop() // Xóa phan tu o dau queue
		{
			if(n==0) return;
			if(n==1) {n=F=0;L=-1;return;}
			F=(F+1)%cap; n--; 
		}
		int size(){return n;} // lay ra kich thuoc queue
		bool empty(){return n==0;} // kiem tra xem queue rong hay khong
		T front(){return a[F];} // lay phan tu dau tien cua queue
		T back(){return a[L];} // lay phan tu cuoi cung
};
#endif
