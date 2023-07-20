#include <iostream>
#include <cmath>
#include "geometry.h"
using namespace std;

double dist(Coordinates const& p1, Coordinates const& p2){
	double ans(0);
	for (int i(0); i<3; ++i){
		ans += pow(p1[i]-p2[i], 2);
	}
	return sqrt(ans);
}

void display_coordinates(Coordinates const& pos){
	cout << "X: " << pos[0] << " Y: " << pos[1] << " Z: " << pos[2] << endl;
}

bool check_termination(Coordinates const& p1, Coordinates const& p2){
	bool same(true);
	for (int i(0); i<3; ++i){
		same = same && (p1[i] == p2[i]);
	}
	
	return same;
}

void get_unit_vect(Coordinates const& p1, Coordinates const& p2, Coordinates& u){
	for (int i(0); i<3; ++i){
		u[i] = (p2[i] - p1[i])/dist(p1, p2);
	}
}

void assign_pos(Coordinates& p1, Coordinates const& p2){
	for (int i(0); i<3; ++i){
		p1[i] = p2[i];
	}
}
