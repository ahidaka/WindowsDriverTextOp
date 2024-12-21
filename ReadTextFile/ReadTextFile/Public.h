/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_ReadTextFile,
    0xc7b39325,0xd33b,0x4468,0xad,0x8f,0x94,0x1d,0x29,0x82,0xc0,0xf0);
// {c7b39325-d33b-4468-ad8f-941d2982c0f0}
