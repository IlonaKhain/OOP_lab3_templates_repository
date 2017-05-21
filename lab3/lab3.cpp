// OOP_lab3_Templates.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Container.h"
#include "PushPopContainer.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedDeque.h"
#include "LinkedList.h"
#include "StaticArray.h"
#include<iostream>
#include  <algorithm>
#include <memory>
#include <vector> 
using namespace std;

int main()
{
		Stack<int> st, st2;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		cout << " This is stack1 after push " << st << endl;
		st.selection_sort(st);

		cout << " This is stack1 after sort " << st << endl;
		LinkedDeque<int> ld;
		ld.pushFront(1);
		ld.pushBack(3);
		ld.pushBack(2);
		ld.pushBack(10);
		ld.pushBack(1);
		cout << " This is deque after push " << ld << endl;
		ld.selection_sort(ld);

		cout << " This is deque after sort " << ld << endl;
		//st2 = st; realize
 		//st2.push(1);
 		//cout << " This is stack1 after push " << st << endl;
	//	cout << " This is stack2 after push " << st2 << endl;
		//cout << (st == st2); redone
		/*cout << " This is stack after push " << st<<endl;
		cout<<"This is stack size "<<st.size() << endl;
		st.selection_sort(st);
		cout << " This is stack after sort " << st << endl;
		//test stack for int
		cout<<"Poped value is "<< st.pop() << endl;
		cout << " This is stack after pop " << st << endl;
		cout <<"Peeked value is "<< st.peek() << endl;
		cout << " This is stack after peek " << st << endl;*/
	//test stack for string
		/*Stack<string> st_string;
		st_string.push("aa");
		st_string.push("bb");
		st_string.push("cc");
		cout << " This is stack after push " << st_string << endl;
		st_string.selection_sort(st_string);
		cout << " This is stack after sort " << st_string << endl;
		cout << "This is stack size " << st_string.size() << endl;
		cout << "Poped value is " << st_string.pop() << endl;
		cout << " This is stack after pop " << st_string << endl;
		cout << "Peeked value is " << st_string.peek() << endl;
		cout << " This is stack after peek " << st_string << endl;

		
	//test queue for int 
		Queue<int> q;
		q.push(1);
		q.push(2);
		q.push(7);
		q.push(3);
		cout << " This is queue after push " << q << endl;
		cout << "This is queue size " << q.size() << endl;
		q.selection_sort(q);
		cout << " This is queue after sort " << q<< endl;
		cout << "Poped value is " << q.pop() << endl;
		cout << " This is queue after pop " << q << endl;
		cout << "Peeked value is " << q.peek() << endl;
		cout << " This is queue after peek " << q << endl;
	//test queue for string 
		Queue<string> q_string;
		q_string.push("aa");
		q_string.push("bb");
		q_string.push("qq");
		q_string.push("cc");
		cout << " This is queue after push " << q_string << endl;
		cout << "This is queue size " << q_string.size() << endl;
		q_string.selection_sort(q_string);
		cout << " This is queue after sort " << q_string << endl;
		cout << "Poped value is " << q_string.pop() << endl;
		cout << " This is queue after pop " << q_string << endl;
		cout << "Peeked value is " << q_string.peek() << endl;
		cout << " This is queue after peek " << q_string << endl;
	//test StaticArray for int 
		StaticArray<double> sa(4);
		sa.set(0,2.2);
		sa.set(1,3.3);
		sa.set(2,4.4);
		sa.set(3, 1.1);
		cout << " This is static array after push " << sa<< endl;
		sa.selection_sort(sa);
		cout << " This is queue after sort " << sa << endl;
		cout << "Try [] operation " << sa[0]<<endl;
		cout << "This is static array size " << sa.size() << endl;
		cout << "Got value with index 2 is " << sa.get(2) << endl;
		cout << " This is static array after pop " << sa << endl;*/
	//test StaticArray for string 
		/*StaticArray<string> sa(3);
		sa.set(0,"aa");
		sa.set(1,"bb");
		sa.set(2,"cc");
		cout << " This is static array after push " << sa<< endl;
		cout << "This is static array size " << sa.size() << endl;
		cout << "Got value with index 2 is " << sa.get(2) << endl;
		cout << " This is static array after pop " << sa << endl;*/
		//	LinkedDeque<string> ld;*/
//	LinkedList<string> ll;
	/*LinkedDeque<int> ld;
	ld.pushFront(1);
	ld.pushFront(2);
	ld.pushFront(3);
	cout << " This is Deque after pushFront " << ld << endl;
	cout << "This is Deque size " << ld.size() << endl;
	cout << "PopedFront value is " << ld.popFront() << endl;
	cout << " This is Dequeue after pop " << ld << endl;
	cout << "PeekedFront value is " << ld.peekFront() << endl;
	cout << " This is Deque after peek " << ld << endl;
	ld.pushBack(7);
	ld.pushBack(8);
	ld.pushBack(9);
	cout << " This is Deque after pushBack " << ld << endl;
	cout << "This is Deque size " << ld.size() << endl;
	cout << "PopedBack value is " << ld.popBack() << endl;
	cout << " This is Dequeue after pop " << ld << endl;
	cout << "PeekedBack value is " << ld.peekBack() << endl;
	cout << " This is Deque after peek " << ld << endl;
//test linked deque for string
	LinkedDeque<string> ld_string;
	ld_string.pushFront("aa");
	ld_string.pushFront("bb");
	ld_string.pushFront("cc");
	cout << " This is Deque after pushFront " << ld_string << endl;
	cout << "This is Deque size " << ld_string.size() << endl;
	cout << "PopedFront value is " << ld_string.popFront() << endl;
	cout << " This is Dequeue after pop " << ld_string << endl;
	cout << "PeekedFront value is " << ld_string.peekFront() << endl;
	ld_string.pushBack("xx");
	ld_string.pushBack("yy");
	ld_string.pushBack("zz");
	cout << " This is Deque after pushBack " << ld_string << endl;
	cout << "This is Deque size " << ld_string.size() << endl;
	cout << "PopedBack value is " << ld_string.popBack() << endl;
	cout << " This is Dequeue after pop " << ld_string << endl;
	cout << "PeekedBack value is " << ld_string.peekBack() << endl;
	cout << " This is Deque after peek " << ld_string << endl;
//test linked list for int
	LinkedList<int> ll;
	ll.push(1);
	ll.push(2);
	ll.push(3);
	ll.push(4);
	cout << " This is list after push " << ll << endl;
	cout << "This is list size " << ll.size() << endl;
	cout << "Poped value is " << ll.pop() << endl;
	cout << " This is list after pop " << ll << endl;
	cout << "Peeked value is " << ll.peek() << endl;                                                                                                                                                                                                                                                        
	cout << " This is list after peek " << ll << endl;
	ll.insertAt(1, 8);
	cout << " This is list after insert " << ll << endl;
	cout << "Get value is " << ll.get(0)<<endl;*/
	
	system("pause");
    return 0;
}

