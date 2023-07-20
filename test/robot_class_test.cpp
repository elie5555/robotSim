#include <iostream>
#include <string>
#include "robot_class.h"
#include "input.h"
#include "geometry.h"


using namespace N;
using namespace std;


void Robot::set_coordinates(Coordinates new_pos){
	for (int i(0); i<3; ++i){
		this->pos[i] = new_pos[i];
	}
}

void Robot::move(Coordinates const& target){
	if (check_termination(this->pos, target)){
		cout << "The robot has reached its target position." << endl;
		return;
	}

	Coordinates unit_vector;
	get_unit_vect(this->pos, target, unit_vector);

	while(!check_termination(this->pos, target)){
		if (this->max_vel*this->dt >= dist(this->pos, target)){
			assign_pos(this->pos, target);
		}
		else{
			for (int i (0); i<3; ++i){
				this->pos[i] += this->max_vel*this->dt*unit_vector[i];
			}
		}
		display_coordinates(this->pos);
	}
	cout << "The robot has reached its target position." << endl;
}

void Robot::initialize(){
	
	string input;
	cout << "Enter the robot's initial coordinates in meters: ";
	do {
		cin >> input;
	} while(!get_coordinates(this->pos, input));
	cout << endl;
	
	cout << "Enter the robot's maximum velocity in meters per second: ";
	this->max_vel = positive_input("maximum velocity");
	cout << endl;
	
	cout << "Enter the timestep in ms: ";
	this->dt = positive_input("time step");
	this->dt /= 1000;
	cout << endl;
}
