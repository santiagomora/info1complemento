#include "../../../../11/info1includes/sock-lib.h"
#include "aux.h"
#define NAMESTOSOLVE 1

int errno;

int cctr;
// struct donde se guardan las variables de configuracion
// por el momento solo el maximo numero de procesos children
struct vconf init;

int sig_trap (void);

void child_process (int s); 
