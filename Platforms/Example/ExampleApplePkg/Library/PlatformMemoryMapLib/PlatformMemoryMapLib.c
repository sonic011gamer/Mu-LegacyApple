#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
/* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */

//------------- Register Regions ----------
{"Peripherals",     0x00000000, 0x80000000, AddDev, MMAP_IO,  UNCACHEABLE,  MmIO,   NS_DEVICE},
//------------- DDR Regions ----------
{"Display Reserved",0x80000000, 0x00C00000, AddMem, MEM_RES, WRITE_THROUGH, MaxMem, WRITE_THROUGH},
{"UEFI Stack",      0x80C00000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP,   BsData, WRITE_BACK_XN},
{"CPU Vectors",     0x80C40000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP,   BsCode, WRITE_BACK_XN},
{"UEFI FD",         0x80C50000, 0x00300000, AddMem, SYS_MEM, SYS_MEM_CAP,   BsCode, WRITE_BACK_XN},
{"DXE Heap",        0x80F50000, 0x04500000, AddMem, SYS_MEM, SYS_MEM_CAP,   Conv,   WRITE_BACK_XN},
//------------- RAM Regions ----------
{"RAM Partiton",    0x85450000, 0x1ABB0000, AddMem, SYS_MEM, SYS_MEM_CAP,   Conv,   WRITE_BACK_XN},
{"RAM Partiton",    0xA0000000, 0x20000000, AddMem, SYS_MEM, SYS_MEM_CAP,   Conv,   WRITE_BACK_XN},
//------------- Terminator for MMU ----------
{"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
    return gDeviceMemoryDescriptorEx;
}
