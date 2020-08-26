#include <iostream> 
#include <vector>
  
using namespace std; 
  
int main() 
{ 
    vector<int> g1; 
  
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Output of begin and end: "; 
    for (vector<int>::iterator i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
  
  	cout << "\nOutput of rbegin and rend: ";
    vector<int>::reverse_iterator rit = g1.rbegin();
  	for (; rit!= g1.rend(); ++rit)
    	cout << *rit << " "; 
  	
    return 0; 
} 
