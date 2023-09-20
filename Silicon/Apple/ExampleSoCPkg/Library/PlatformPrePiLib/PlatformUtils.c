#include <PiPei.h>
#include <Library/IoLib.h>
#include <Library/PlatformPrePiLib.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryMapHelperLib.h>

VOID PlatformInitialize (VOID)
{
  ARM_MEMORY_REGION_DESCRIPTOR_EX DisplayMemoryRegion;
  LocateMemoryMapAreaByName("Display Reserved", &DisplayMemoryRegion);
  //Remap our framebuffer
  MmioWrite32(0x3A100000 + 0x4044, DisplayMemoryRegion.Address);
}
