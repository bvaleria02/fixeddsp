#ifndef FIXED_DSP_H
#define FIXED_DSP_H

#include "stdint.h"
#include "../fixedpoint/fixedpoint.h"
#include "../fixedlinmath/fixedlinmath.h"

typedef enum {
	FDSP_CHANNEL_NO			= 0,
	FDSP_CHANNEL_SINGLE		= 1,
	FDSP_CHANNEL_MULTILINK	= 2,
	FDSP_CHANNEL_MULTI		= 3,
	FDSP_CHANNEL_COMPLEX	= 4,
	FDSP_CHANNEL_CONTINUOUS	= 5,
	FDSP_CHANNEL_2D			= 6
} FDSPChannelType;

typedef enum {
	FDSP_SIGNAL_TIMESERIES	= 0,
	FDSP_SIGNAL_FOURIER		= 1,
	FDSP_SIGNAL_PLANE		= 2
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

// fixeddspcreate.c
FDSPErrorCode fixedDSPCreateSignal(fdspsignal_t *sig, flmdim_t width, flmdim_t height, flmtype_t type, void *data, FDSPChannelType channel, FDSPSignalType signalType, uint32_t sampleRate, fixed64_t timeStart);

// fixeddspconvert.c
FDSPErrorCode fixedDSPFLMErrorConverter(FLMErrorCode code);

#endif // FIXED_DSP_H
