#include <bits/stdc++.h>

using namespace std;

int main(){
	set<pair<int,int>> points; //set of points
	vector<pair<int,int>> intersections; // vector of all intersections
	char direction,comma;
	int distance;
	int x = 5000,y = 5000; // origin point
	int max;
	while(cin >> direction && cin >> distance && cin >> comma){
		// takes in direction and updates wire points
		if(direction == 'U'){
			max = y + distance;
			for(y;y <= max;y++){
				points.insert(make_pair(x,y));
			}
			y--;
		}
		else if(direction == 'D'){
			max = y - distance;
			for(y;y >= max;y--){
				points.insert(make_pair(x,y));
			}
			y++;
		}
		else if(direction == 'R'){
			max = x + distance;
			for(x;x <= max;x++){
				points.insert(make_pair(x,y));
			}
			x--;
		}
		else if(direction == 'L'){
			max = x - distance;
			for(x;x >= max;x--){
				points.insert(make_pair(x,y));
			}
			x++;
		}
		else{
			cout << "ERROR" << endl;
			break;
		}
		
		if(comma != ','){
			break;
		}
	}
	x = 5000;//reset to origin
	y = 5000;
	while(cin >> direction && cin >> distance && cin >> comma){
		//takes direction and checks for intersection
		if(direction == 'U'){
			max = y + distance;
			for(y;y <= max;y++){
				if(points.find(make_pair(x,y)) != points.end()){
					intersections.push_back(make_pair(x,y));
					//cout << x << y << endl;
				}
			}
			y--;
		}
		else if(direction == 'D'){
			max = y - distance;
			for(y;y >= max;y--){
				if(points.find(make_pair(x,y)) != points.end()){
					intersections.push_back(make_pair(x,y));
				}
			}
			y++;
		}
		else if(direction == 'R'){
			max = x + distance;
			for(x;x <= max;x++){
				if(points.find(make_pair(x,y))!= points.end()){
					intersections.push_back(make_pair(x,y));

				}
			}
			x--;
		}
		else if(direction == 'L'){
			max = x - distance;
			for(x;x >= max;x--){
				if(points.find(make_pair(x,y)) != points.end()){
					intersections.push_back(make_pair(x,y));
				}
			}
			x++;
		}
		else{
			cout << "ERROR" << endl;
			break;
		}
		if(comma != ','){
			break;
		}
	}
	cout << "END"<< endl;
	int smallest = INT_MAX;
	int val;
	for(pair <int,int> i : intersections){
		//search for smallest distance
		val = abs(5000 - i.first) + abs(5000 - i.second);
		if(val < smallest && val != 0){
			smallest = val;
		}
	}
	cout << smallest << endl;
}
