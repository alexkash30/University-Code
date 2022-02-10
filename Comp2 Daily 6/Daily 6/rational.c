#include "rational.h"
#include <stdlib.h>
#include <stdio.h>

struct rational {
	int numerator;
	int demoniator;
};
typedef struct rational Rational;


RATIONAL ratioanl_init_default(void){
	Rational* pRatioanl = (Rational*)malloc(sizeof(Rational));
	if (pRatioanl != NULL) {
		pRatioanl->demoniator = 1;
		pRatioanl->numerator = 0;
	}
	free(pRatioanl);
	return pRatioanl;
}

void rational_destroy(RATIONAL* phRational) {
	Rational* pRatioanl = (Rational*)*phRational;
	free(pRatioanl);
	*phRational = NULL;
}
