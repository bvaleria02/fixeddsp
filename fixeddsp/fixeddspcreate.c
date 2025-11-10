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

FDSPErrorCode fixedDSPCreateMonoSignal(fdspMonoSignal_t *sig, flmdim_t width, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		FDSP_MONO_SIGNAL_HEIGHT,
		type,
		data,
		FDSP_CHANNEL_SINGLE,
		FDSP_SIGNAL_TIMESERIES,
		sampleRate,
		timeStart
	);
}

FDSPErrorCode fixedDSPCreateStereoSignal(fdspStereoSignal_t *sig, flmdim_t width, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		FDSP_STEREO_SIGNAL_HEIGHT,
		type,
		data,
		FDSP_CHANNEL_DOUBLE,
		FDSP_SIGNAL_TIMESERIES,
		sampleRate,
		timeStart
	);
}

FDSPErrorCode fixedDSPCreateMultiSignal(fdspMultiSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		height,
		type,
		data,
		FDSP_CHANNEL_MULTILINK,
		FDSP_SIGNAL_TIMESERIES,
		sampleRate,
		timeStart
	);
}

FDSPErrorCode fixedDSPCreateMultiChannelSignal(fdspMultiChannelSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		height,
		type,
		data,
		FDSP_CHANNEL_MULTI,
		FDSP_SIGNAL_TIMESERIES,
		sampleRate,
		timeStart
	);
}

FDSPErrorCode fixedDSPCreateContinuousSignal(fdspContinuousSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		height,
		type,
		data,
		FDSP_CHANNEL_CONTINUOUS,
		FDSP_SIGNAL_TIMESERIES,
		sampleRate,
		timeStart
	);
}

FDSPErrorCode fixedDSPCreate2DSignal(fdsp2DSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		height,
		type,
		data,
		FDSP_CHANNEL_2D,
		FDSP_SIGNAL_PLANE,
		FDSP_2D_SIGNAL_SAMPLERATE,
		FDSP_2D_SIGNAL_TIMESTART
	);
}

FDSPErrorCode fixedDSPCreateFourierSignal(fdspFourierResult_t *sig, flmdim_t width, flmtype_t type, void *data){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		FDSP_FOURIER_SIGNAL_HEIGHT,
		type,
		data,
		FDSP_CHANNEL_COMPLEX,
		FDSP_SIGNAL_FOURIER,
		FDSP_FOURIER_SIGNAL_SAMPLERATE,
		FDSP_FOURIER_SIGNAL_TIMESTART
	);
}

FDSPErrorCode fixedDSPCreateSTFourierSignal(fdspSTFourierResult_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data){
	return fixedDSPCreateSignal(
		FDSP_SIGNAL(sig),
		width,
		(height << 1),
		type,
		data,
		FDSP_CHANNEL_COMPLEX,
		FDSP_SIGNAL_STFOURIER,
		FDSP_STFOURIER_SIGNAL_SAMPLERATE,
		FDSP_STFOURIER_SIGNAL_TIMESTART
	);
}
