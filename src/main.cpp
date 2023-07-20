#include <iostream>
#include <string>
#include "robot_class.h"
#include "input.h"

using namespace N;
using namespace std;

int main() {
	
	Robot bot;
	Coordinates target_pos;
	
	bot.initialize();
	
	while (get_target_pos(target_pos)){
		bot.move(target_pos);
	}
	return 0;
}
