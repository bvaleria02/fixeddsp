#include <stdio.h>
#include <stdint.h>
#include "fixedpoint/fixedpoint.h"
#include "fixedlinmath/fixedlinmath.h"
#include "fixeddsp/fixeddsp.h"

int main(){
	fixed32_t data[2048 * 1];
	fdspMonoSignal_t signal;
	fixedDSPCreateMonoSignal(&signal, 2048, FIXED32_T, data, 44100, 0);

	return 0;
}
