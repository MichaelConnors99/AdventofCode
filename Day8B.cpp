#include <bits/stdc++.h>

using namespace std;

int main(){
	string layers[100];
	string number;
	string image = "";
	cin >> number;
	string layer;
	int pos = 0;
	int index = 0;
	for(int i = 0;i < number.length();i += 150){
		//splits image into layers
		layer = number.substr(i,150);
		layers[index] = layer;
		index++;
	}
	for(int i = 0;i < 150;i++){
		//iterates through layers
		while(layers[pos][i] == '2' && pos < 100){
			//finds first colour that isn't transparent
			pos++;
		}
		image += layers[pos][i]; //adds prominant pixel to image
		if(layers[pos][i] == '0'){
			//helps clear things up by
			//leaving background blank
			cout << ' ';
		}
		else{
			//prints main pixel
			cout << layers[pos][i];
		}
		pos = 0;//resets position in layer
		if(i == 24 || i == 49 || i == 74 || i == 99 || i == 124 || i == 149){
			//all linebreaks
			cout << endl;
		}
	}
}
