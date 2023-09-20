## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

# SoC Defines
[Defines]
  USE_PHYSICAL_TIMER = 1

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|19200000
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|17
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|18
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x50041000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x50040100
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0x50041000

  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x00000030
  gEmbeddedTokenSpaceGuid.PcdInterruptBaseAddress|0x50041000

  gApplePkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Example (R) ExampleSoC @ 5.70 GHz"
  gApplePkgTokenSpaceGuid.PcdSmbiosProcessorRetailModel|"ExSoC"

  gArmPlatformTokenSpaceGuid.PcdCoreCount|2
  gArmPlatformTokenSpaceGuid.PcdClusterCount|1

[LibraryClasses.common]
  PlatformPeiLib|ExampleSoCPkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  PlatformPrePiLib|ExampleSoCPkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf

[Components.common]
  ExampleSoCPkg/Drivers/SmBiosTableDxe/SmBiosTableDxe.inf

!include ApplePkg/ApplePkg.dsc.inc
