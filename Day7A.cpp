#include <bits/stdc++.h>

using namespace std;

//several connected intcode programs with amplifiers that feed
//their output to the connected input

int amplify(long arr[1000],int phase,int inputValue,int index){
	//runs intcode program and returns output
	bool done = false;
	long opcode = arr[0] %10;
	long parMode1 = 0, parMode2 = 0;
	long par1 = 0,par2 = 0;
	int input = phase;
	for(int i = 0;i < index;i++){
		opcode = arr[i] % 10;
		if(opcode != 3 && opcode != 9){
			parMode1 = (arr[i]/100) % 10;
			parMode2 = (arr[i]/1000) % 10;
			if(parMode1 == 0){
				par1 = arr[arr[i+1]];
			}
			else{
				par1 = arr[i+1];
			}

			if(parMode2 == 0){
				par2 = arr[arr[i+2]];
			}
			else{
				par2 = arr[i+2];
			}
		}
		cout << i << " " << arr[i] << " "<<par1<<" "<<par2<< endl;

		if(arr[i]%100 == 99){
			cout << "DONE " << input << endl;
			break;
		}

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
			if(!done){
				done = true;
				input = inputValue;
			}
		}

		else if(opcode == 4){
			input = par1;
			i++;
			return input;
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
	return input;
}

int main(){
	long intCode[1000];
	long num;
	char pointless;
	int index = 0;
	while(cin >> num && cin >> pointless){
		intCode[index] = num;
		index++;
		if(pointless != ','){
			break;
		}
	}
	//cout << intCode[3] << endl;
	int phaseSetting = 0;
	int phases[] = {0,1,2,3,4};
	long input = 0;
	long biggest = 0;
	do{
		//iterates though all permutations of amplifiers
		input = 0;
		for(int i = 0;i < 5;i++){
			phaseSetting = phases[i];
			input = amplify(intCode,phaseSetting,input,index);
		}
		if(input > biggest){
			biggest = input;
		}
	}while(next_permutation(phases,phases+5));
	cout << biggest;
}
