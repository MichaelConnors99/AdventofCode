#include <bits/stdc++.h>

using namespace std;

//exact same as 4a except needs an isolated pair

bool valid(int num){
	string s = to_string(num);
	bool two = false;
	for(int i = 0;i < 5;i++){
		int digit = s[i] - '0';
		int after = s[i+1] - '0';
		if(digit > after){
			return false;
		}
	}
	for(int i = 0;i < 5;i++){
		if(s[i] == s[i+1]){
			if(s[i] != s[i-1] && s[i] != s[i+2]){ // checks if pair is isolated
				two = true;
			}
		}
		while(s[i] == s[i+1]){//skips through group
			i++;
		}
	}
	if(!two){
		return false;
	}
	return true;
}

int main(){
	int count = 0;
	for(int i = 178417;i < 676461;i++){
		if(valid(i)){
			count++;
		}
	}
	cout << count;
}
