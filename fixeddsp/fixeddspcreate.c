#include "stdlib.h"
#include "stdint.h"
#include "../fixedpoint/fixedpoint.h"
#include "../fixedlinmath/fixedlinmath.h"
#include "fixeddsp.h"

FDSPErrorCode fixedDSPCreateSignal(fdspsignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, FDSPChannelType channelType, FDSPSignalType signalType, uint32_t sampleRate, fixed64_t timeStart){
	if(sig == NULL || data == NULL){
		FDSP_RAISE_RETURN_ERROR(FDSP_ERROR_NULLPTR);
	}

	if(sampleRate == 0){
		FDSP_RAISE_RETURN_ERROR(FDSP_ERROR_SAMPLERATEZERO);
	}

	flmmat_t mat;
	FLMErrorCode flmcode = fixedLMCreateMatrix(&mat, width, height, type, data);
	if(flmcode != FLM_NO_ERROR){
		return fixedDSPFLMErrorConverter(flmcode);
	}

	sig->channelType = channelType;
	sig->signalType  = signalType;
	sig->sampleRate  = sampleRate;
	sig->timeStart   = timeStart;

	return FDSP_NO_ERROR;
}
