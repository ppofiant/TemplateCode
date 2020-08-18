#include <stdio.h>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
	
	//Assigning map
	map<int, int> gmap1;
	
	//Insert Value in map
	gmap1.insert(pair<int, int>(1,40));
	gmap1.insert(pair<int, int>(2,30));
	gmap1.insert(pair<int, int>(3,60));
	gmap1.insert(pair<int, int>(4,20));
	gmap1.insert(pair<int, int>(5,50));
	gmap1.insert(pair<int, int>(6,50));
	gmap1.insert(pair<int, int>(7,10));
	gmap1.insert(pair<int, int>(8,20));
	
	//Printing map gmap1
	map<int, int>::iterator itr; //Buat variabel map baru untuk set
	cout << "\nThe map qmap1 is : \n\n";
	cout << "\tKEY\tELEMENT\n";
	for(itr = gmap1.begin() ; itr != gmap1.end() ; ++itr) {
		cout << '\t' << itr->first;
		cout << '\t' << itr->second << '\n';
	}
	cout << endl;
	
	printf("=================================\n");
	
	map<int, int> gmap2(gmap1.begin(), gmap1.end());
		
	//Alternatif printing map gmap2
	map<int, int>::iterator it = gmap2.begin();
	cout << "\nThe map qmap2 is : \n\n";
	cout << "\tKEY\tELEMENT\n";
	while(it != gmap2.end()) {
		cout << '\t' << it->first;
		cout << '\t' << it->second << '\n';
		it++;
	}
	cout << endl;
	
	printf("=================================\n");
	
	// Remove all element in map
	int key = 3;
	gmap1.erase(gmap1.begin(), gmap1.find(key)); // Remove until key 5 -> start from 5
	cout << "\nThe map qmap1 is : after delete from begin to " << key-1 << "\n\n";
	cout << "\tKEY\tELEMENT\n";
	for(itr = gmap1.begin() ; itr != gmap1.end() ; ++itr) {
		cout << '\t' << itr->first;
		cout << '\t' << itr->second << '\n';
	}
	cout << endl;
	
	printf("=================================\n");
	
	// Remove only spesific key in map
	int del;
	del = gmap1.erase(6);
	map<int, int>::iterator tt = gmap1.begin();
	cout << "\nThe map qmap1 is : after delete key: " << del << "\n\n";
	cout << "\tKEY\tELEMENT\n";
	while(tt != gmap1.end()) {
		cout << '\t' << tt->first;
		cout << '\t' << tt->second << '\n';
		tt++;
	}
	cout << endl;
	
	//Lower bound and Upper bound for map gmap1 key = 5
	cout << "gmap1.lower_bound(7): ";
	cout << "\tKEY = ";
	cout << gmap1.lower_bound(7)->first << '\t';
	
	cout << "\tELEMENT = ";
	cout << gmap1.lower_bound(7)->second << '\n';
	
	cout << "gmap1.upper_bound(7): ";
	cout << "\tKEY = ";
	cout << gmap1.upper_bound(7)->first << '\t';
	
	cout << "\tELEMENT = ";
	cout << gmap1.upper_bound(7)->second << '\n';
	
	//Lower bound punya lowerbound
	map<int, int> lower;
	lower.insert(pair<int, int>(gmap1.lower_bound(7)->first, gmap1.lower_bound(7)->second));
	
	cout << endl;
	cout << "KEY\t"<< lower.lower_bound(7)->first << endl;
	cout << "ELEMENT\t" << lower.lower_bound(7)->second << endl << endl;
	
	//Upper bound punya upperbound
	map<int, int> upper;
	upper.insert(pair<int, int>(gmap1.upper_bound(7)->first, gmap1.upper_bound(7)->second));

	cout << "KEY\t"<< upper.lower_bound(8)->first << endl;
	cout << "ELEMENT\t" << upper.lower_bound(8)->second << endl;	
	
	return 0;
}
