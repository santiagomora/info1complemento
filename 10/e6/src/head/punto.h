#ifndef COORD
#define COORD
	struct punto {
        	double x;
        	double y;
	};
#endif 
#ifndef COORDARR
	struct ptarr {
		int length;
		struct punto* puntos;
	};
#endif
