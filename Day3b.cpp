#include <bits/stdc++.h>

using namespace std;

//same as 3a except shortest journey rather than distance

int main(){
	set<pair<int,int>> points;
	map<pair<int,int>,int> steps1; //map of point to distance of the journey
	vector<int> steps2;
	int count = 0;
	vector<pair<int,int>> intersections;
	char direction,comma; // input variables
	int distance;
	int x = 5000,y = 5000; //origin
	int max;
	while(cin >> direction && cin >> distance && cin >> comma){
		//same as 3a except records journey distance of first wire
		if(direction == 'U'){
			max = y + distance;
			for(y;y <= max;y++){
				points.insert(make_pair(x,y));
				steps1[make_pair(x,y)] = count;
				count++;
			}
			count--;
			y--;
		}
		else if(direction == 'D'){
			max = y - distance;
			for(y;y >= max;y--){
				points.insert(make_pair(x,y));
				steps1[make_pair(x,y)] = count;
				count++;
			}
			count--;
			y++;
		}
		else if(direction == 'R'){
			max = x + distance;
			for(x;x <= max;x++){
				points.insert(make_pair(x,y));
				steps1[make_pair(x,y)] = count;
				count++;
			}
			count--;
			x--;
		}
		else if(direction == 'L'){
			max = x - distance;
			for(x;x >= max;x--){
				points.insert(make_pair(x,y));
				steps1[make_pair(x,y)] = count;
				count++;
			}
			count--;
			x++;
		}
		else{
			cout << "ERROR" << endl;
			break;
		}
		
		if(comma != ','){
			//cout << "NEXT\n";
			break;
		}
	}
	x = 5000;//reset to origin
	y = 5000;
	count = 0;
	while(cin >> direction && cin >> distance && cin >> comma){
		//finds intersections and calculates total journey distance
		if(direction == 'U'){
			max = y + distance;
			for(y;y <= max;y++){
				if(points.find(make_pair(x,y)) != points.end()){
					intersections.push_back(make_pair(x,y));
					steps2.push_back(count + steps1[make_pair(x,y)]);
					//cout << x << y << endl;
				}
				count++;
				cout << count << endl;
			}
			y--;
			count--;
		}
		else if(direction == 'D'){
			max = y - distance;
			for(y;y >= max;y--){
				if(points.find(make_pair(x,y)) != points.end()){
					intersections.push_back(make_pair(x,y));
					steps2.push_back(count + steps1[make_pair(x,y)]);
				}
				count++;
				cout << count << endl;
			}
			y++;
			count--;
		}
		else if(direction == 'R'){
			max = x + distance;
			for(x;x <= max;x++){
				if(points.find(make_pair(x,y))!= points.end()){
					intersections.push_back(make_pair(x,y));
					steps2.push_back(count + steps1[make_pair(x,y)]);
				}
				count++;
				cout << count << endl;
			}
			x--;
			count--;
		}
		else if(direction == 'L'){
			max = x - distance;
			for(x;x >= max;x--){
				if(points.find(make_pair(x,y)) != points.end()){
					intersections.push_back(make_pair(x,y));
					steps2.push_back(count + steps1[make_pair(x,y)]);
				}
				count++;
				cout << count << endl;
			}
			x++;
			count--;
		}
		else{ // checks for error
			cout << "ERROR" << endl;
			break;
		}
		if(comma != ','){
			break;
		}
	}
	int smallest = INT_MAX;
	for(int i : steps2){
		if(i < smallest && i != 0){
			smallest = i;
		}
	}
	cout << smallest << endl;
}
