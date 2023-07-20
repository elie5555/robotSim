#include "geometry.h"

namespace N {
	class Robot {
		public:
		 Coordinates pos;
		 double max_vel;
		 double dt;
		 void set_coordinates(Coordinates new_pos);
		 void move(Coordinates const& target);
		 void initialize();
	
	};
	
}
