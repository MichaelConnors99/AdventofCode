#include <bits/stdc++.h>

using namespace std;

int positions[4][3];
int velocities[4][3];
int energy[4];

void gravity(int plan1,int plan2){
	//applies gravity to velocity
	for(int i = 0;i < 3;i++){
		if(positions[plan1][i] > positions[plan2][i]){
			velocities[plan1][i] -=1;
			velocities[plan2][i] +=1;
		}
		else if(positions[plan1][i] < positions[plan2][i]){
			velocities[plan1][i]+=1;
			velocities[plan2][i]-=1;
		}
	}
}

void velocity(int planet){
	//applies velocity to position
	for(int i = 0;i < 3;i++){
		positions[planet][i] += velocities[planet][i];
	}
}

int main(){
	for(int i = 0;i < 4;i++){
		//takes in positions
		cin >> positions[i][0] >> positions[i][1] >> positions[i][2];
	}

	for(int i = 0;i < 1000;i++){//simulates 1000 steps
		//applies gravity then velocity
		for(int j = 0;j < 4;j++){
			for(int k = j;k < 4;k++){
				if(j!=k){
					gravity(j,k);
				}
			}
		}
		for(int j = 0;j < 4;j++){
			velocity(j);
		}
	}
	//calculate total energy
	energy[0] = (abs(positions[0][0]) + abs(positions[0][1]) + abs(positions[0][2])) * (abs(velocities[0][0]) + abs(velocities[0][1]) + abs(velocities[0][2]));
	energy[1] = (abs(positions[1][0]) + abs(positions[1][1]) + abs(positions[1][2])) * (abs(velocities[1][0]) + abs(velocities[1][1]) + abs(velocities[1][2]));
	energy[2] = (abs(positions[2][0]) + abs(positions[2][1]) + abs(positions[2][2])) * (abs(velocities[2][0]) + abs(velocities[2][1]) + abs(velocities[2][2]));
	energy[3] = (abs(positions[3][0]) + abs(positions[3][1]) + abs(positions[3][2])) * (abs(velocities[3][0]) + abs(velocities[3][1]) + abs(velocities[3][2]));
	cout << energy[0] + energy[1] + energy[2] + energy[3] << endl;
}
