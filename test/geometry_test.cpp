#include <iostream>
#include <cmath>
#include <assert.h>
#include "geometry.h"
using namespace std;

int int main()
{
	Coordinates p1 = {0, 0, 0}, p2 = {0, 0, 0};
	Coordinates u, v = {0, 0 ,0};
	assert(0 == dist(p1, p2));
	assert(true == check_termination(p1, p2));
	get_unit_vect(p1, p2, u);
	assert(v == u);
	assign_pos(p1, p2);
	assert(p1 == p2);

	return 0;
}
