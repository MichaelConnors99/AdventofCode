#include <bits/stdc++.h>

using namespace std;

int main(){
	int total = 0;
	int mass;
	while(cin >> mass){
		while(mass > 0){
			mass /= 3; //uses up fuel
			mass -= 2;
			if(mass < 0){//deals with overload
				mass = 0;
			}
			total += mass;//add to total
		}
	}
	cout << total;
}
