#include <string>
#include "geometry.h"

bool isNumber(const string& s);
bool get_coordinates(Coordinates& pos, string input, size_t cnt = 0);
bool get_target_pos(Coordinates& target);
double positive_input(string name);
