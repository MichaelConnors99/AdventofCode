#include <bits/stdc++.h>

using namespace std;

//same as 4a but adds new opcodes which can update the instruction pointer

int main(){
	long arr[1000]; //empty intcode program
	long num;
	long index = 0;
	char pointless;
	while(cin >> num && cin >> pointless){
		//fills up intcode program
		arr[index] = num;
		index++;
		if(pointless != ','){
			break;
		}
	}
	long opcode;
	long parMode1, parMode2;
	long par1,par2,par3;
	long input = 5;
	for(int i = 0;i < index;i++){
		opcode = arr[i] % 10;
		if(opcode != 3){ //opcode 3 needs no parameters
			parMode1 = (arr[i]/100) % 10;
			parMode2 = (arr[i]/1000) % 10;
		}

		if(parMode1 == 0){
			//position
			par1 = arr[arr[i+1]];
		}
		else{
			//immediate
			par1 = arr[i+1];
		}

		if(parMode2 == 0){
			//position
			par2 = arr[arr[i+2]];
		}
		else{
			//immediate
			par2 = arr[i+2];
		}

		cout << i << " " << arr[i] << " "<<par1<<" "<<par2<< endl;

		if(arr[i]%100 == 99){// break statement
			cout << "DONE" << input << endl;
			break;
		}

		// follows opcode instruction and updates pointer
		else if(opcode == 1){
			arr[arr[i+3]] = par1 + par2;
			i+=3;
		}
		else if(opcode == 2){
			arr[arr[i+3]] = par1 * par2;
			i += 3;
		}

		else if(arr[i] == 3){
			arr[arr[i+1]] = input;
			i++;
		}

		else if(opcode == 4){
			input = par1;
			cout << "output = " << input << /*" "<<arr[i+2] <<*/ endl;
			break;
			i++;
		}

		else if(opcode == 5){
			if(par1 != 0){
				i = par2-1;
			}
			else{
				i += 2;
			}
		}

		else if(opcode == 6){
			if(par1 == 0){
				i = par2-1;
				//cout << i << endl;
			}
			else{
				i += 2;
			}
		}

		else if(opcode == 7){
			if(par1 < par2){
				arr[arr[i+3]] = 1;
			}
			else{
				arr[arr[i+3]] = 0;
			}
			i += 3;
		}

		else if(opcode == 8){
			if(par1 == par2){
				arr[arr[i+3]] = 1;
			}
			else{
				cout << arr[i+3] << endl;
				arr[arr[i+3]] = 0;
			}
			i += 3;
		}

		else{
			cout << "ERROR" << endl;
		}
	}
	cout<< arr[9] << endl;
}
