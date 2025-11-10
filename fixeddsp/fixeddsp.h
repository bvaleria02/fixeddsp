#ifndef FIXED_DSP_H
#define FIXED_DSP_H

#include "stdint.h"
#include "../fixedpoint/fixedpoint.h"
#include "../fixedlinmath/fixedlinmath.h"

typedef enum {
	FDSP_CHANNEL_NO			= 0,
	FDSP_CHANNEL_SINGLE		= 1,
	FDSP_CHANNEL_DOUBLE		= 2,
	FDSP_CHANNEL_MULTILINK	= 3,
	FDSP_CHANNEL_MULTI		= 4,
	FDSP_CHANNEL_COMPLEX	= 5,
	FDSP_CHANNEL_CONTINUOUS	= 6,
	FDSP_CHANNEL_2D			= 7
} FDSPChannelType;

typedef enum {
	FDSP_SIGNAL_TIMESERIES	= 0,
	FDSP_SIGNAL_FOURIER		= 1,
	FDSP_SIGNAL_STFOURIER	= 2,
	FDSP_SIGNAL_PLANE		= 3
} FDSPSignalType;

typedef enum {
	FDSP_NO_ERROR				= 0,
	FDSP_ERROR_NULLPTR			= 1,
	FDSP_ERROR_SAMPLERATEZERO	= 2,
	FDSP_ERROR_DIMENSION		= 3,
	FDSP_ERROR_FLMERROR			= 127
} FDSPErrorCode;

typedef struct{
	FDSPChannelType channelType;
	FDSPSignalType signalType;
	uint32_t sampleRate;
	fixed64_t timeStart;
	flmmat_t mat;
} fdspsignal_t;

typedef fdspsignal_t fdspMonoSignal_t;
typedef fdspsignal_t fdspStereoSignal_t;
typedef fdspsignal_t fdspMultiChannelSignal_t;
typedef fdspsignal_t fdspMultiSignal_t;
typedef fdspsignal_t fdspContinuousSignal_t;
typedef fdspsignal_t fdsp2DSignal_t;
typedef fdspsignal_t fdspFourierResult_t;
typedef fdspsignal_t fdspSTFourierResult_t;

#define FDSP_MONO_SIGNAL_HEIGHT 1
#define FDSP_STEREO_SIGNAL_HEIGHT 1
#define FDSP_2D_SIGNAL_SAMPLERATE 1
#define FDSP_2D_SIGNAL_TIMESTART 0
#define FDSP_FOURIER_SIGNAL_HEIGHT 2
#define FDSP_FOURIER_SIGNAL_SAMPLERATE 1
#define FDSP_FOURIER_SIGNAL_TIMESTART 0
#define FDSP_STFOURIER_SIGNAL_SAMPLERATE 1
#define FDSP_STFOURIER_SIGNAL_TIMESTART 0

extern _Thread_local FDSPErrorCode fixedDSPErrno;
extern _Thread_local const char *fixedDSPFuncName;
extern _Thread_local const char *fixedDSPFileName;
extern _Thread_local int   fixedDSPLineNumber;

#define FDSP_RAISE_RETURN_ERROR(__errorcode) do{	\
	fixedDSPErrno = __errorcode;					\
	fixedDSPFuncName = __func__;					\
	fixedDSPFileName = __FILE__;					\
	fixedDSPLineNumber = __LINE__;					\
	return __errorcode;								\
} while(0)

#define FDSP_SIGNAL(__signal) 			((fdspsignal_t *) 				__signal)
#define FDSP_MONO(__signal) 			((fdspMonoSignal_t *) 			__signal)
#define FDSP_STEREO(__signal) 			((fdspStereoSignal_t*) 			__signal)
#define FDSP_MULTI_CHANNEL(__signal) 	((fdspMultiChannelSignal_t *) 	__signal)
#define FDSP_MULTI(__signal) 			((fdspMultiSignal_t *) 			__signal)
#define FDSP_CONTINUOUS(__signal) 		((fdspContinuousSignal_t *) 	__signal)
#define FDSP_2D(__signal) 				((fdsp2DSignal_t*) 				__signal)
#define FDSP_FOURIER(__signal) 			((fdspFourierResult_t *) 		__signal)
#define FDSP_ST_FOURIER(__signal) 		((fdspSTFourierResult_t *) 		__signal)


// fixeddspcreate.c
FDSPErrorCode fixedDSPCreateSignal(fdspsignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, FDSPChannelType channel, FDSPSignalType signalType, uint32_t sampleRate, fixed64_t timeStart);
FDSPErrorCode fixedDSPCreateMonoSignal(fdspMonoSignal_t *sig, flmdim_t width, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart);
FDSPErrorCode fixedDSPCreateStereoSignal(fdspStereoSignal_t *sig, flmdim_t width, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart);
FDSPErrorCode fixedDSPCreateMultiSignal(fdspMultiSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart);
FDSPErrorCode fixedDSPCreateMultiChannelSignal(fdspMultiChannelSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart);
FDSPErrorCode fixedDSPCreateContinuousSignal(fdspContinuousSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, uint32_t sampleRate, fixed64_t timeStart);
FDSPErrorCode fixedDSPCreate2DSignal(fdsp2DSignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data);
FDSPErrorCode fixedDSPCreateFourierSignal(fdspFourierResult_t *sig, flmdim_t width, flmtype_t type, void *data);
FDSPErrorCode fixedDSPCreateSTFourierSignal(fdspSTFourierResult_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data);

// fixeddspconvert.c
FDSPErrorCode fixedDSPFLMErrorConverter(FLMErrorCode code);

#endif // FIXED_DSP_H
