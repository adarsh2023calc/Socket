/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "add.h"

int *
add_1_svc(num *argp, struct svc_req *rqstp)
{
	static int  result;

	result = argp->a + argp->b;
	printf("Received request to add  %d and %d" , argp->a,argp->b);

	return &result;
}

int* sub_1_svc(num *argp, struct svc_req *rqstp)
{
	static int  result;

	result = argp->a - argp->b;
	printf("Received request to subtract  %d and %d" , argp->a,argp->b);

	return &result;
}