#include <stdio.h>
#include <stdint.h>
#include "fixedpoint/fixedpoint.h"
#include "fixedlinmath/fixedlinmath.h"
#include "fixeddsp/fixeddsp.h"

int main(){
	fixed32_t data[2048 * 1];
	fdspsignal_t signal;
	fixedDSPCreateSignal(&signal, 2048, 1, FIXED32_T, data, FDSP_CHANNEL_SINGLE, FDSP_SIGNAL_TIMESERIES, 44100, 0);

	return 0;
}
