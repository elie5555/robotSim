#include <array>
using namespace std;

typedef array<double, 3> Coordinates;

double dist(Coordinates const& p1, Coordinates const& p2);
void display_coordinates(Coordinates const& pos);
bool check_termination(Coordinates const& p1, Coordinates const& p2);
void get_unit_vect(Coordinates const& p1, Coordinates const& p2, Coordinates& u);
void assign_pos(Coordinates& p1, Coordinates const& p2);
