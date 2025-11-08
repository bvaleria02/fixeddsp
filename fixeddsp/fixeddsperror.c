#include "stdlib.h"
#include "stdint.h"
#include "fixeddsp.h"

_Thread_local FDSPErrorCode fixedDSPErrno = FDSP_NO_ERROR;
_Thread_local const char *fixedDSPFuncName = NULL;
_Thread_local const char *fixedDSPFileName = NULL;
_Thread_local int fixedDSPLineNumber = -1l;
