#include <bits/stdc++.h>

using namespace std;

bool valid(int num){
	string s = to_string(num);
	bool two = false;
	for(int i = 1;i < 6;i++){ //iterates through digits
		int digit = s[i] - '0';
		int before = s[i-1] - '0';
		if(digit < before){//compares two adjacent digits
			return false;
		}
		else if(digit == before){//checks for pair
			two = true;
		}
	}
	if(!two){
		return false;
	}
	return true;
}

int main(){
	int count = 0;
	for(int i = 178417;i < 676461;i++){ //input range
		if(valid(i)){ //check if valid
			count++;
		}
	}
	cout << count;
}
