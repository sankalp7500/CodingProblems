#include <vector>
#include <iostream>
using namespace std;

int main(){
	// This initialization is available at C++11 support compiler
	// For lower version C++ support check the reference document
	vector<int> arr (9);
	arr = {1,2,3,4,5,6,7,8,9};
	
	vector<int>::const_iterator begin = arr.begin();
	vector<int>::const_iterator last = arr.begin() + arr.size();
	vector<int> new_arr(begin+1, last);
	cout << "Size: "<< new_arr.size() << endl;

	for (int i = 0 ;  i < new_arr.size(); i++){
		cout << new_arr[i] << endl;
	}
}
