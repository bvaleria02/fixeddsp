#include "stdlib.h"
#include "stdint.h"
#include "../fixedlinmath/fixedlinmath.h"
#include "fixeddsp.h"

FDSPErrorCode fixedDSPFLMErrorConverter(FLMErrorCode flmcode){
	FDSPErrorCode fdspcode = FDSP_NO_ERROR;

	switch(flmcode){
		case FLM_NO_ERROR: 			fdspcode = FDSP_NO_ERROR;
									break;

		case FLM_ERROR_NULLPTR: 	fdspcode = FDSP_ERROR_NULLPTR;
									break;

		case FLM_ERROR_DIMENSION: 	fdspcode = FDSP_ERROR_DIMENSION;
									break;

		default:					fdspcode = FDSP_ERROR_FLMERROR;
									break;
	}	

	return fdspcode;
}
