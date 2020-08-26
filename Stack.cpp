#include <iostream>
#include <stack>
using namespace std;

/*
	STACK -> Last In First Out
	=====
	
	beberapa fungsi yang ada pada stack
	empty() -> mengetahui apakah dalam stack kosong atau ga
	push(n) -> memberikan nilai di atas elemen lain dalam stack
	pop() -> mengahpus nilai teratas pada stack (top stack di pop)
	top() -> element paling atas dalam stack
	size() -> return banyaknya element dalam stack
*/

void printStack(stack <int> s) {
	cout << endl;
	while(!s.empty()) {
		cout << s.top() << '\t';
		s.pop();
	}
}

int main() {
	
	stack <int> s;
	s.push(10);
	s.push(5);
	s.push(6);
	s.push(20);
	
	cout << "The Stack is : " << endl;
	printStack(s);
	cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
    
    //coba kita hapus topnya
    cout << endl << "\nAfter Pop "<< s.top() << " The Stack is : " << endl;
	s.pop();
	printStack(s);
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top() << endl;
    
    // cek apakah empty atau ga.. return 0 false , 1 true
    cout << "\nIs the Stack is Empty?" << endl;
    if(s.empty() == 0) cout << "False\n";
    else cout << "True\n";
    
	// sekarang kita coba hapus semua stacknya
	while(!s.empty()) {
		printStack(s);
		cout << "\ns.size() : " << s.size(); 
    	cout << "\ns.top() : " << s.top() << endl;
    	s.pop();
	}
	
	//seharusnya stack kita udah habis, maka return true
	cout << "\nIs the Stack is Empty Now?" << endl;
    if(s.empty() == 0) cout << "False\n";
    else cout << "True\n";
    
    
	return 0;
}
