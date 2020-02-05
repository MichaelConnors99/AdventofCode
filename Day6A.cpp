#include <bits/stdc++.h>

using namespace std;

int main(){
	map<string,string> orbits; //map of what orbits what
	map<string,string>::iterator itr; 
	string orbit;
	int count = 0;
	while(cin >> orbit && orbit != "."){
		//takes in input and splits into two objects
		string ob1 = orbit.substr(0,3);
		string ob2 = orbit.substr(4,3);
		orbits[ob2] = ob1; //ob1 orbits ob2
	}
	for(itr = orbits.begin();itr != orbits.end();itr++){
		//iterates through orbit data
		string ob = itr->first;
		while(ob != "COM"){
			//keeps counting distance until COM reached
			count++;
			ob = orbits[ob];
		}
	}
	cout << count;
}
