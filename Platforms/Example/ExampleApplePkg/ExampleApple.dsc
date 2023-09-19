## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = ExampleApple
  PLATFORM_GUID                  = 0bc40a20-8da8-4003-8e28-67dfb3de362c
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/ExampleApplePkg
  SUPPORTED_ARCHITECTURES        = ARM
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = ExampleApplePkg/ExampleApple.fdf

[LibraryClasses.common]
  PlatformMemoryMapLib|ExampleApplePkg/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf

[PcdsFixedAtBuild.common]
  # Platform-specific
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000         # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x80000000         # 2GB Size

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"Hmmm"  # Device Maintainer

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x9FF8C000

  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x9FF90000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000      # 256K stack

  # SmBios
  gApplePkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Example Co"
  gApplePkgTokenSpaceGuid.PcdSmbiosSystemModel|"Example Apple"
  gApplePkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"ExApple"
  gApplePkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Example_Apple_ExApple"
  gApplePkgTokenSpaceGuid.PcdSmbiosBoardModel|"Example_Apple"

  # Simple FrameBuffer
  gApplePkgTokenSpaceGuid.PcdMipiFrameBufferWidth|2340
  gApplePkgTokenSpaceGuid.PcdMipiFrameBufferHeight|1080
  gApplePkgTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|32

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|2340
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|1080
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|2340
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|1080
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|170
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|40
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|170
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|40

!include ExampleSoCPkg/ExampleSoCPkg.dsc.inc
