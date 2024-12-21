/*++

Module Name:

    device.h

Abstract:

    This file contains the device definitions.

Environment:

    Kernel-mode Driver Framework

--*/

#include "public.h"

EXTERN_C_START

#define FILE_NAME L"\\??\\C:\\TEMP\\HardwareIDs.txt"

#define MAX_FILE_SIZE 8192

//
// The device context performs the same job as
// a WDM device extension in the driver frameworks
//
typedef struct _DEVICE_CONTEXT
{
    ULONG PrivateDeviceData;  // just a placeholder

} DEVICE_CONTEXT, *PDEVICE_CONTEXT;

//
// This macro will generate an inline function called DeviceGetContext
// which will be used to get a pointer to the device context memory
// in a type safe manner.
//
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext)

//
// Function to initialize the device and its callbacks
//
NTSTATUS
ReadTextFileCreateDevice(
    _Inout_ PWDFDEVICE_INIT DeviceInit
    );

NTSTATUS ReadTextFile(
    _Out_ PWCHAR OutBuffer,
    _In_ PWCHAR FileName,
    _Out_ size_t* Length
);

EXTERN_C_END
