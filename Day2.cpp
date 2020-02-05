#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[1000];// empty intcode program
	int num;
	int index = 0;
	char pointless;//takes in space
	while(cin >> num && cin >> pointless && pointless != 's'){
		arr[index] = num;//take in input and fill in intcode program
		index++;
	}
	arr[1] = 12;//question specifies to replace values
	arr[2] = 2;
	int ans;
	for(int i = 0;i < index;i++){
		if(arr[i] == 99){//break statement
			break;
		}
		else if(arr[i] == 1){
			ans = arr[arr[i+1]] + arr[arr[i+2]];
			arr[arr[i+3]] = ans; //addition
		}
		else if(arr[i] == 2){
			ans = arr[arr[i+1]] * arr[arr[i+2]];
			arr[i+3] = ans; //multiplacation
		}
		else{ //for edge case
			cout << "ERROR" << endl;
		}
		i += 3;
	}
	cout << arr[0];//final output
}
