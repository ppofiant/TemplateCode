#include <iostream>
#include <queue>
using namespace std;

/*
	QUEUE -> First In First Out
	=====
	
	beberapa fungsi utama dalam queue terdiri dari berikut:
	empty() -> cek apakah queue kosong atau tidak
	size() -> return banyaknya element yang masuk dalam queue
	swap() -> menganti masing masing queue
	
	constraint swap:
	masing-masing queue harus memiliki tipe data yang sama,
	terlepas dari size
	
	emplace() -> construct objek baru di belakang queue
	push() -> mengambil atau mencopy constructor yang sudah ada kedalam queue
	pop() -> mengahpus element mulai dari depan (queue::front)
	
	push() vs emplace
	push : mengcopy nilai dari constructor yang sudah ada
	emplace : membuat constructor objek baru
	
	front() -> return element terdepan queue
	back() -> return element terbelakang queue
	
*/

void printQueue(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << '\t';
		q.pop();
	}
	cout << endl;
}

int main() {
	
	queue <int> q;
	queue <int> q1;
	
	q.push(5);
	q.push(10);
	q.push(15);
	q.push(20);
	q.push(1);
	q.push(99);
	
	q1.push(2);
	q1.push(4);
	q1.push(100);
	q1.push(99);
	
	// queue : 5 10 15 20 1 99
	printQueue(q);
	cout << "Front Queue : " << q.front() << endl;
	cout << "Back Queue : " << q.back() << endl;
	
	q.pop();
	
	cout << endl;
	printQueue(q);
	
	cout << "Front Queue : " << q.front() << endl;
	cout << "Back Queue : " << q.back() << endl;
	
	cout << endl;
	
	cout << "Before swap q and q1" << endl;
	cout << "q1 :\t"; printQueue(q1);
	cout << "q: \t"; printQueue(q);
	
	cout << endl;
	
	swap(q, q1);
	cout << "After swap q and q1" << endl;
	cout << "q1 :\t"; printQueue(q1);
	cout << "q: \t"; printQueue(q);
	return 0;
}
