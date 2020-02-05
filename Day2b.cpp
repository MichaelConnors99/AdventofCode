#include <bits/stdc++.h>

using namespace std;

//simulates intcode program
int grav(int arr[1000],int index){
	int ans;
	for(int i = 0;i < index;i++){
		if(arr[i] == 99){
			break;
		}
		else if(arr[i] == 1){
			ans = arr[arr[i+1]] + arr[arr[i+2]];
			arr[arr[i+3]] = ans;
		}
		else if(arr[i] == 2){
			ans = arr[arr[i+1]] * arr[arr[i+2]];
			arr[i+3] = ans;
		}
		else{ //edge case
			cout << "ERROR" << endl;
		}
		i += 3;
	}
	return arr[0];
}

int main(){
	int arr[1000];
	int num;
	int index = 0;
	char pointless;
	while(cin >> num && cin >> pointless && pointless != 's'){
		arr[index] = num;
		index++;
	}

	bool found = false;
	for(int noun = 0;noun < 100;noun++){
		//loop through all possible combos
		if(found){
			break;
		}
		for(int verb = 0;verb < 100;verb++){
			int temp[1000];
			copy(begin(arr),end(arr),begin(temp));
			temp[1] = noun;
			temp[2] = verb;
			//grav function simulates intcode program
			if(grav(temp,index) == 19690720){//check for desired result
				cout << 100 * noun + verb << endl;
				found = true;
				break;
			}
		}
	}
}
