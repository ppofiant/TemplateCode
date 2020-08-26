#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
	Pair
	====
	library : <utility>
	
	pair ini seperti suatu element yang memiliki 2 nilai yang berpasangan
	pair <int, char>
	pair <int , int>
		   \	  \
			\	   \
		  first   second
	2 nilai ini boleh memiliki nilai yang berbeda
	
	function yang dimiliki
	
	.first -> mengambil element pertama
	.second -> mengambil element kedua
	.make_pair(element pertama, element kedua) -> assign pair
	
	contoh penggunaan pair
	
	pair <int, char> pair1;
	
	cout << pair1.first << endl;
	cout << pair1.second << endl;
	
	Vector Pair
	===========
	library <vector>
	
	sama seperti fungsi vector yang ada pada program language java
	fungsi yang bisa digunakan : 
	push_back(g) -> assign/memberikan element ke belakang vector
	
	begin() -> iterator dari element pertama vector (dari element pertama) -> iterator
	
	end() -> iterator element terakhir vector (dari element terakhir) -> iterator
	
	rbegin() -> reverse iterator element awal (dari element terakhir) -> reverse_iterator
	
	rend() -> reverse iterator element akhir (dari element awal) -> reverse_iterator
	
	crbegin() -> reverse iterator element awal (dari element terakhir)
	crend() -> reverse iterator element akhir (dari element awal)
	cbegin() -> iterator dari constant element pertama
	cend() -> iterator dari constant element terakhir
	front() -> element terdepan vector
	back() -> element paling belakang vector
	
*/

void printVectorPair(vector < pair <int, char> > vectorpair) {
	cout << "Vector Pair List : " << endl;
	for(int i = 0; i < vectorpair.size() ; i++) {
		cout << vectorpair[i].first << '\t'
			<< vectorpair[i].second << endl;
	}
}

void printVector(vector <int> v) {
	cout << "Vector List" << endl;
	for(vector<int>::iterator i = v.begin() ; i!= v.end() ; ++i) {
		cout << *i << " ";
	}
}

int main() {
	
	vector <pair <int, char> > vector_pair;
	for(int i = 0 ; i <= 5 ; i++) {
		vector_pair.push_back(make_pair(i, 'A' + i));
	}
	printVectorPair(vector_pair);
	
	
	vector <int> VECTOR;
	for(int j = 0 ; j <= 10 ; j++) {
		VECTOR.push_back(j);
	}
	
	printVector(VECTOR);
	
	
	return 0;
}
