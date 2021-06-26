#ifndef SCURVE_H
#define SCURVE_H

#include "rtapi.h"          /* RTAPI realtime OS API */
#include "rtapi_app.h"		/* RTAPI realtime module decls */
#include "math.h"           /* Used for pow and sqrt */

#define toRadians M_PI/180.0
#define toDegrees (180.0/M_PI)

// Example function:
void myfirstvoid(float a, float b, float *result);

void myfirstvoid(float a, float b, float *result){
    *result=a+b;
}

// In the makefile the external so lib has to be present with -L/path -llibname

struct data {
    double x;
};

extern void init_opencascade();
extern void meat(struct data d);

#endif // SCURVE_H































