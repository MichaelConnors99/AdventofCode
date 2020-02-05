#include <bits/stdc++.h>

using namespace std;

int main(){
	string layers[100];
	string number;
	cin >> number;
	string layer;
	int smallest = INT_MAX;
	int index = 0;
	int position = 0;
	int count = 0;
	for(int i = 0;i < number.length();i += 150){
		//splits image into layers
		layer = number.substr(i,150);
		layers[index] = layer;
		index++;
		for(int j = 0;j < 150;j++){
			//counts characters that aren't 1 or 2
			if(layer[j] == '0'){
				count++;
			}
		}
		if(count < smallest){
			//checks for smallest
			smallest = count;
			position = i;
		}
		count = 0;
	}
	int ones = 0, twos = 0;
	position /= 150;
	cout << position << endl;
	for(int i = 0;i < 150;i++){
		//counts 1's and 2's of answer layer and multiplies them
		if(layers[position][i] == '1'){
			ones++;
		}
		else if(layers[position][i] == '2'){
			twos++;
		}
	}
	cout << ones * twos << endl;
}
