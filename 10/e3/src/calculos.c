#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double varianza ( double* nums, double prom, int length ){
	double tot=0;
	int i=0;
	while ( i<length ){
		tot+=pow( nums[i++]-prom, 2 );
	} 
	return tot/length;
};

double promedio ( double* nums, int length ) {
	double tot=0;
	int i=0;
	while ( i<length ){
		tot+=nums[i++];
	}
	return tot/length;
}; 

double* mostrarCalculos ( double* nums, int length ) {
        double prom = promedio( nums,length ),
                var = varianza( nums,prom,length );
        printf("inicio:%lf fin:%lf\n prom:%lf, var:%lf\n",nums[0],nums[length-1],prom,var);
        return  realloc( nums,101*sizeof(double) );
}

