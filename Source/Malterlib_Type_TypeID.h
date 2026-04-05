// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

#define DMibCurrentTypeIDType(_Type) NMib::NMisc::TCTypeID<_Type>::ETypeID + 1
#define DMibCurrentTypeID 0

DMibTypeID(int8, DMibCurrentTypeID + 1);
DMibTypeID(int16, DMibCurrentTypeID + 2);
DMibTypeID(int32, DMibCurrentTypeID + 3);
DMibTypeID(int64, DMibCurrentTypeID + 4);
DMibTypeID(uint8, DMibCurrentTypeID + 5);
DMibTypeID(uint16, DMibCurrentTypeID + 6);
DMibTypeID(uint32, DMibCurrentTypeID + 7);
DMibTypeID(uint64, DMibCurrentTypeID + 8);


#ifdef DMibPUniqueType_mint
DMibTypeID(umint, DMibCurrentTypeID + 9);
#endif

#ifdef DMibPUniqueType_smint
DMibTypeID(smint, DMibCurrentTypeID + 10);
#endif

#ifdef DMibPUniqueType_aint
DMibTypeID(aint, DMibCurrentTypeID + 11);
#endif

#ifdef DMibPUniqueType_uaint
DMibTypeID(uaint, DMibCurrentTypeID + 12);
#endif

#ifdef DMibPUniqueType_ch8
DMibTypeID(ch8, DMibCurrentTypeID + 13);
#endif
DMibTypeID(const ch8 *, DMibCurrentTypeID + 14);

#ifdef DMibPUniqueType_ch16
DMibTypeID(ch16, DMibCurrentTypeID + 15);
#endif
DMibTypeID(const ch16 *, DMibCurrentTypeID + 16);

#ifdef DMibPUniqueType_ch32
DMibTypeID(ch32, DMibCurrentTypeID + 17);
#endif
DMibTypeID(const ch32 *, DMibCurrentTypeID + 18);

DMibTypeID(fp32, DMibCurrentTypeID + 19);
DMibTypeID(fp64, DMibCurrentTypeID + 20);

DMibTypeID(NMib::NStr::CStr, DMibCurrentTypeID + 21);
DMibTypeID(NMib::NStr::CWStr, DMibCurrentTypeID + 22);
DMibTypeID(NMib::NStr::CUStr, DMibCurrentTypeID + 23);
DMibTypeID(NMib::NStr::CFStr256, DMibCurrentTypeID + 24);
DMibTypeID(NMib::NStr::CFUStr256, DMibCurrentTypeID + 25);
#ifndef DDocumentation_Doxygen
DMibTypeID(NMib::NStr::CFWStr256, DMibCurrentTypeID + 26);
#endif

// 27 is CMStrDeprecated

#ifdef DMibPUniqueType_int
DMibTypeID(int, DMibCurrentTypeID + 28);
#endif

#ifdef DMibPUniqueType_uint
DMibTypeID(unsigned int, DMibCurrentTypeID + 29);
#endif

DMibTypeID(NMib::NContainer::CByteVector, DMibCurrentTypeID + 30);
DMibTypeID(NMib::NTime::CTime, DMibCurrentTypeID + 31);

#undef DMibCurrentTypeID
#define DMibCurrentTypeID DMibCurrentTypeIDType(NMib::NTime::CTime)

