#include <iostream>
#include <array>
#include <string>
#include "input.h"

using namespace std;

bool isNumber(string const& s){

	bool decimal = false;
	bool number = false;

	for (size_t i(0); i<s.size(); ++i){
		if (isdigit(s[i])){
			number = true;
		}
		if (!i){
			if (!isdigit(s[i]) && s[i] != '-'){
				return false;
			}
		}
		else{
			if (s[i] == '.'){
				if (decimal){
					return false;
				}
				decimal = true;
			}
			else if (!isdigit(s[i]))
			{
				return false;
			}
		}
	}
	if (number){
		return true;
	}
	else{
		return false;
	}
}

bool get_coordinates(Coordinates& pos, string input, size_t cnt){
	if (cnt == 3){
		return true;
	}
	
	string sample;
	
	if (cnt < 2){
		if (input.find(";") == string::npos){
			cout << "Wrong input. No ; separator was detected. Try again: ";
			return false;
		}
		else {
			sample = input.substr(0, input.find(";"));
		}
	}
	else {
		sample = input;
	}
	
	if (sample.empty()){
		cout << "Wrong input. Try again: ";
		return false;
	}
	
	if (isNumber(sample)) {
		pos[cnt] = stod(sample);
		if (cnt < 2) {input.erase(0, input.find(";")+1);}
		++cnt;
		return get_coordinates(pos, input, cnt);
	}
	else{
		cout << "Wrong input. One of the coordinate is not a number. Try again: ";
		return false;
	}
}

bool get_target_pos(Coordinates& target){
	string input;
	cout << "Enter the robot's target coordinates separated by ; OR type stop to exit: ";
	do {
		cin >> input;
		if (!input.compare("stop")){return false;}
	} while(!get_coordinates(target, input));
	return true;
}

double positive_input(string name){
	
	bool correct(false);
	double val(0);
	
	do {
		
		string input;
		cin >> input;
		
		if (isNumber(input)) { 
			val = stod(input);
			if(val > 0){
				correct = true;
			}
			else {
				cout << "The " << name << " should be strictly greater than 0. Try again: ";
			}
		}
		else {
			cout << "Not a number, the "<< name <<" should be a number greater than 0. Try again: ";
		}
	} while(!correct);
	
	return val;
}
