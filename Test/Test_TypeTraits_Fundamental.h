// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

// Is Int

#ifdef DMibPCanDo_int16384
static_assert(cIsFundamental<int16384>);
#else
static_assert(!cIsFundamental<int16384>);
#endif
#ifdef DMibPCanDo_int8192
static_assert(cIsFundamental<int8192>);
#else
static_assert(!cIsFundamental<int8192>);
#endif
#ifdef DMibPCanDo_int4096
static_assert(cIsFundamental<int4096>);
#else
static_assert(!cIsFundamental<int4096>);
#endif
#ifdef DMibPCanDo_int2048
static_assert(cIsFundamental<int2048>);
#else
static_assert(!cIsFundamental<int2048>);
#endif
#ifdef DMibPCanDo_int1024
static_assert(cIsFundamental<int1024>);
#else
static_assert(!cIsFundamental<int1024>);
#endif
#ifdef DMibPCanDo_int512
static_assert(cIsFundamental<int512>);
#else
static_assert(!cIsFundamental<int512>);
#endif
#ifdef DMibPCanDo_int256
static_assert(cIsFundamental<int256>);
#else
static_assert(!cIsFundamental<int256>);
#endif
#ifdef DMibPCanDo_int160
static_assert(cIsFundamental<int160>);
#else
static_assert(!cIsFundamental<int160>);
#endif
#ifdef DMibPCanDo_int192
static_assert(cIsFundamental<int192>);
#else
static_assert(!cIsFundamental<int192>);
#endif
#ifdef DMibPCanDo_int128
static_assert(cIsFundamental<int128>);
#else
static_assert(!cIsFundamental<int128>);
#endif
#ifdef DMibPCanDo_int80
static_assert(cIsFundamental<int80>);
#else
static_assert(!cIsFundamental<int80>);
#endif
#ifdef DMibPCanDo_int96
static_assert(cIsFundamental<int96>);
#else
static_assert(!cIsFundamental<int96>);
#endif
#ifdef DMibPCanDo_int64
static_assert(cIsFundamental<int64>);
#else
static_assert(!cIsFundamental<int64>);
#endif
#ifdef DMibPCanDo_int32
static_assert(cIsFundamental<int32>);
#else
static_assert(!cIsFundamental<int32>);
#endif
#ifdef DMibPCanDo_int16
static_assert(cIsFundamental<int16>);
#else
static_assert(!cIsFundamental<int16>);
#endif
#ifdef DMibPCanDo_int8
static_assert(cIsFundamental<int8>);
#else
static_assert(!cIsFundamental<int8>);
#endif


// These must always be fundamental
static_assert(cIsFundamental<aint>);
static_assert(cIsFundamental<uaint>);
static_assert(cIsFundamental<smint>);
static_assert(cIsFundamental<umint>);
static_assert(cIsFundamental<int>);
static_assert(cIsFundamental<unsigned int>);

#ifdef DMibPCanDo_uint16384
static_assert(cIsFundamental<uint16384>);
#else
static_assert(!cIsFundamental<uint16384>);
#endif
#ifdef DMibPCanDo_uint8192
static_assert(cIsFundamental<uint8192>);
#else
static_assert(!cIsFundamental<uint8192>);
#endif
#ifdef DMibPCanDo_uint4096
static_assert(cIsFundamental<uint4096>);
#else
static_assert(!cIsFundamental<uint4096>);
#endif
#ifdef DMibPCanDo_uint2048
static_assert(cIsFundamental<uint2048>);
#else
static_assert(!cIsFundamental<uint2048>);
#endif
#ifdef DMibPCanDo_uint1024
static_assert(cIsFundamental<uint1024>);
#else
static_assert(!cIsFundamental<uint1024>);
#endif
#ifdef DMibPCanDo_uint512
static_assert(cIsFundamental<uint512>);
#else
static_assert(!cIsFundamental<uint512>);
#endif
#ifdef DMibPCanDo_uint256
static_assert(cIsFundamental<uint256>);
#else
static_assert(!cIsFundamental<uint256>);
#endif
#ifdef DMibPCanDo_uint160
static_assert(cIsFundamental<uint160>);
#else
static_assert(!cIsFundamental<uint160>);
#endif
#ifdef DMibPCanDo_uint192
static_assert(cIsFundamental<uint192>);
#else
static_assert(!cIsFundamental<uint192>);
#endif
#ifdef DMibPCanDo_uint128
static_assert(cIsFundamental<uint128>);
#else
static_assert(!cIsFundamental<uint128>);
#endif
#ifdef DMibPCanDo_uint80
static_assert(cIsFundamental<uint80>);
#else
static_assert(!cIsFundamental<uint80>);
#endif
#ifdef DMibPCanDo_uint96
static_assert(cIsFundamental<uint96>);
#else
static_assert(!cIsFundamental<uint96>);
#endif
#ifdef DMibPCanDo_uint64
static_assert(cIsFundamental<uint64>);
#else
static_assert(!cIsFundamental<uint64>);
#endif
#ifdef DMibPCanDo_uint32
static_assert(cIsFundamental<uint32>);
#else
static_assert(!cIsFundamental<uint32>);
#endif
#ifdef DMibPCanDo_uint16
static_assert(cIsFundamental<uint16>);
#else
static_assert(!cIsFundamental<uint16>);
#endif
#ifdef DMibPCanDo_uint8
static_assert(cIsFundamental<uint8>);
#else
static_assert(!cIsFundamental<uint8>);
#endif

#ifdef DMibPCanDo_fp4096
static_assert(cIsFundamental<pfp4096>);
#else
static_assert(!cIsFundamental<fp4096>);
#endif
#ifdef DMibPCanDo_fp2048
static_assert(cIsFundamental<pfp2048>);
#else
static_assert(!cIsFundamental<fp2048>);
#endif
#ifdef DMibPCanDo_fp1024
static_assert(cIsFundamental<pfp1024>);
#else
static_assert(!cIsFundamental<fp1024>);
#endif
#ifdef DMibPCanDo_fp512
static_assert(cIsFundamental<pfp512>);
#else
static_assert(!cIsFundamental<fp512>);
#endif
#ifdef DMibPCanDo_fp256
static_assert(cIsFundamental<pfp256>);
#else
static_assert(!cIsFundamental<fp256>);
#endif
#ifdef DMibPCanDo_fp128
static_assert(cIsFundamental<pfp128>);
#else
static_assert(!cIsFundamental<fp128>);
#endif
#ifdef DMibPCanDo_fp80
static_assert(cIsFundamental<pfp80>);
#else
static_assert(!cIsFundamental<fp80>);
#endif
#ifdef DMibPCanDo_fp64
static_assert(cIsFundamental<pfp64>);
#else
static_assert(!cIsFundamental<fp64>);
#endif
#ifdef DMibPCanDo_fp32
static_assert(cIsFundamental<pfp32>);
#else
static_assert(!cIsFundamental<fp32>);
#endif
#ifdef DMibPCanDo_fp16
static_assert(cIsFundamental<pfp16>);
#else
static_assert(!cIsFundamental<fp16>);
#endif
#ifdef DMibPCanDo_fp8
static_assert(cIsFundamental<pfp8>);
#else
static_assert(!cIsFundamental<fp8>);
#endif

#ifdef DMibPCanDo_int16384
static_assert(cIsFundamental<const int16384>);
#else
static_assert(!cIsFundamental<const int16384>);
#endif
#ifdef DMibPCanDo_int8192
static_assert(cIsFundamental<const int8192>);
#else
static_assert(!cIsFundamental<const int8192>);
#endif
#ifdef DMibPCanDo_int4096
static_assert(cIsFundamental<const int4096>);
#else
static_assert(!cIsFundamental<const int4096>);
#endif
#ifdef DMibPCanDo_int2048
static_assert(cIsFundamental<const int2048>);
#else
static_assert(!cIsFundamental<const int2048>);
#endif
#ifdef DMibPCanDo_int1024
static_assert(cIsFundamental<const int1024>);
#else
static_assert(!cIsFundamental<const int1024>);
#endif
#ifdef DMibPCanDo_int512
static_assert(cIsFundamental<const int512>);
#else
static_assert(!cIsFundamental<const int512>);
#endif
#ifdef DMibPCanDo_int256
static_assert(cIsFundamental<const int256>);
#else
static_assert(!cIsFundamental<const int256>);
#endif
#ifdef DMibPCanDo_int160
static_assert(cIsFundamental<const int160>);
#else
static_assert(!cIsFundamental<const int160>);
#endif
#ifdef DMibPCanDo_int192
static_assert(cIsFundamental<const int192>);
#else
static_assert(!cIsFundamental<const int192>);
#endif
#ifdef DMibPCanDo_int128
static_assert(cIsFundamental<const int128>);
#else
static_assert(!cIsFundamental<const int128>);
#endif
#ifdef DMibPCanDo_int80
static_assert(cIsFundamental<const int80>);
#else
static_assert(!cIsFundamental<const int80>);
#endif
#ifdef DMibPCanDo_int96
static_assert(cIsFundamental<const int96>);
#else
static_assert(!cIsFundamental<const int96>);
#endif
#ifdef DMibPCanDo_int64
static_assert(cIsFundamental<const int64>);
#else
static_assert(!cIsFundamental<const int64>);
#endif
#ifdef DMibPCanDo_int32
static_assert(cIsFundamental<const int32>);
#else
static_assert(!cIsFundamental<const int32>);
#endif
#ifdef DMibPCanDo_int16
static_assert(cIsFundamental<const int16>);
#else
static_assert(!cIsFundamental<const int16>);
#endif
#ifdef DMibPCanDo_int8
static_assert(cIsFundamental<const int8>);
#else
static_assert(!cIsFundamental<const int8>);
#endif

// These must always be fundamental
static_assert(cIsFundamental<const aint>);
static_assert(cIsFundamental<const uaint>);
static_assert(cIsFundamental<const smint>);
static_assert(cIsFundamental<const umint>);

#ifdef DMibPCanDo_uint16384
static_assert(cIsFundamental<const uint16384>);
#else
static_assert(!cIsFundamental<const uint16384>);
#endif
#ifdef DMibPCanDo_uint8192
static_assert(cIsFundamental<const uint8192>);
#else
static_assert(!cIsFundamental<const uint8192>);
#endif
#ifdef DMibPCanDo_uint4096
static_assert(cIsFundamental<const uint4096>);
#else
static_assert(!cIsFundamental<const uint4096>);
#endif
#ifdef DMibPCanDo_uint2048
static_assert(cIsFundamental<const uint2048>);
#else
static_assert(!cIsFundamental<const uint2048>);
#endif
#ifdef DMibPCanDo_uint1024
static_assert(cIsFundamental<const uint1024>);
#else
static_assert(!cIsFundamental<const uint1024>);
#endif
#ifdef DMibPCanDo_uint512
static_assert(cIsFundamental<const uint512>);
#else
static_assert(!cIsFundamental<const uint512>);
#endif
#ifdef DMibPCanDo_uint256
static_assert(cIsFundamental<const uint256>);
#else
static_assert(!cIsFundamental<const uint256>);
#endif
#ifdef DMibPCanDo_uint160
static_assert(cIsFundamental<const uint160>);
#else
static_assert(!cIsFundamental<const uint160>);
#endif
#ifdef DMibPCanDo_uint192
static_assert(cIsFundamental<const uint192>);
#else
static_assert(!cIsFundamental<const uint192>);
#endif
#ifdef DMibPCanDo_uint128
static_assert(cIsFundamental<const uint128>);
#else
static_assert(!cIsFundamental<const uint128>);
#endif
#ifdef DMibPCanDo_uint80
static_assert(cIsFundamental<const uint80>);
#else
static_assert(!cIsFundamental<const uint80>);
#endif
#ifdef DMibPCanDo_uint96
static_assert(cIsFundamental<const uint96>);
#else
static_assert(!cIsFundamental<const uint96>);
#endif
#ifdef DMibPCanDo_uint64
static_assert(cIsFundamental<const uint64>);
#else
static_assert(!cIsFundamental<const uint64>);
#endif
#ifdef DMibPCanDo_uint32
static_assert(cIsFundamental<const uint32>);
#else
static_assert(!cIsFundamental<const uint32>);
#endif
#ifdef DMibPCanDo_uint16
static_assert(cIsFundamental<const uint16>);
#else
static_assert(!cIsFundamental<const uint16>);
#endif
#ifdef DMibPCanDo_uint8
static_assert(cIsFundamental<const uint8>);
#else
static_assert(!cIsFundamental<const uint8>);
#endif

#ifdef DMibPCanDo_fp4096
static_assert(cIsFundamental<const pfp4096>);
#else
static_assert(!cIsFundamental<const fp4096>);
#endif
#ifdef DMibPCanDo_fp2048
static_assert(cIsFundamental<const pfp2048>);
#else
static_assert(!cIsFundamental<const fp2048>);
#endif
#ifdef DMibPCanDo_fp1024
static_assert(cIsFundamental<const pfp1024>);
#else
static_assert(!cIsFundamental<const fp1024>);
#endif
#ifdef DMibPCanDo_fp512
static_assert(cIsFundamental<const pfp512>);
#else
static_assert(!cIsFundamental<const fp512>);
#endif
#ifdef DMibPCanDo_fp256
static_assert(cIsFundamental<const pfp256>);
#else
static_assert(!cIsFundamental<const fp256>);
#endif
#ifdef DMibPCanDo_fp128
static_assert(cIsFundamental<const pfp128>);
#else
static_assert(!cIsFundamental<const fp128>);
#endif
#ifdef DMibPCanDo_fp80
static_assert(cIsFundamental<const pfp80>);
#else
static_assert(!cIsFundamental<const fp80>);
#endif
#ifdef DMibPCanDo_fp64
static_assert(cIsFundamental<const pfp64>);
#else
static_assert(!cIsFundamental<const fp64>);
#endif
#ifdef DMibPCanDo_fp32
static_assert(cIsFundamental<const pfp32>);
#else
static_assert(!cIsFundamental<const fp32>);
#endif
#ifdef DMibPCanDo_fp16
static_assert(cIsFundamental<const pfp16>);
#else
static_assert(!cIsFundamental<const fp16>);
#endif
#ifdef DMibPCanDo_fp8
static_assert(cIsFundamental<const pfp8>);
#else
static_assert(!cIsFundamental<const fp8>);
#endif


static_assert(!cIsFundamental<CTestUnion>);
static_assert(!cIsFundamental<CTestClass0>);
static_assert(!cIsFundamental<CTestClass1>);
static_assert(!cIsFundamental<CTestStruct0>);
static_assert(!cIsFundamental<CTestStruct1>);
static_assert(!cIsFundamental<ETestEnum>);
static_assert(!cIsFundamental<CTestClass>);
static_assert(!cIsFundamental<CTestC>);
static_assert(!cIsFundamental<CTestPtr>);
static_assert(!cIsFundamental<CTestCPtr>);
static_assert(!cIsFundamental<CTestPtrC>);
static_assert(!cIsFundamental<CTestCPtrC>);
static_assert(!cIsFundamental<CTestRef>);
static_assert(!cIsFundamental<CTestCRef>);
static_assert(!cIsFundamental<CTestRRef>);
static_assert(!cIsFundamental<CTestCRRef>);
static_assert(!cIsFundamental<PFFunc0>);
static_assert(!cIsFundamental<PFFunc1>);
static_assert(!cIsFundamental<PFFunc2>);
static_assert(!cIsFundamental<FFunc0Ref>);
static_assert(!cIsFundamental<FFunc1Ref>);
static_assert(!cIsFundamental<FFunc2Ref>);
static_assert(!cIsFundamental<FFunc0RRef>);
static_assert(!cIsFundamental<FFunc1RRef>);
static_assert(!cIsFundamental<FFunc2RRef>);
static_assert(!cIsFundamental<FFunc0Ptr>);
static_assert(!cIsFundamental<FFunc1Ptr>);
static_assert(!cIsFundamental<FFunc2Ptr>);
static_assert(!cIsFundamental<FFunc0PtrC>);
static_assert(!cIsFundamental<FFunc1PtrC>);
static_assert(!cIsFundamental<FFunc2PtrC>);
static_assert(!cIsFundamental<FMFunc0Ptr>);
static_assert(!cIsFundamental<FMFunc1Ptr>);
static_assert(!cIsFundamental<FMFunc2Ptr>);
static_assert(!cIsFundamental<FMFunc0PtrC>);
static_assert(!cIsFundamental<FMFunc1PtrC>);
static_assert(!cIsFundamental<FMFunc2PtrC>);
static_assert(!cIsFundamental<FMFunc0CPtr>);
static_assert(!cIsFundamental<FMFunc1CPtr>);
static_assert(!cIsFundamental<FMFunc2CPtr>);
static_assert(!cIsFundamental<FMFunc0CPtrC>);
static_assert(!cIsFundamental<FMFunc1CPtrC>);
static_assert(!cIsFundamental<FMFunc2CPtrC>);
static_assert(!cIsFundamental<PFFunc0El>);
static_assert(!cIsFundamental<PFFunc1El>);
static_assert(!cIsFundamental<PFFunc2El>);
static_assert(!cIsFundamental<FFunc0ElRef>);
static_assert(!cIsFundamental<FFunc1ElRef>);
static_assert(!cIsFundamental<FFunc2ElRef>);
static_assert(!cIsFundamental<FFunc0ElRRef>);
static_assert(!cIsFundamental<FFunc1ElRRef>);
static_assert(!cIsFundamental<FFunc2ElRRef>);
static_assert(!cIsFundamental<FFunc0ElPtr>);
static_assert(!cIsFundamental<FFunc1ElPtr>);
static_assert(!cIsFundamental<FFunc2ElPtr>);
static_assert(!cIsFundamental<FFunc0ElPtrC>);
static_assert(!cIsFundamental<FFunc1ElPtrC>);
static_assert(!cIsFundamental<FFunc2ElPtrC>);
static_assert(!cIsFundamental<FMFunc0ElPtr>);
static_assert(!cIsFundamental<FMFunc1ElPtr>);
static_assert(!cIsFundamental<FMFunc2ElPtr>);
static_assert(!cIsFundamental<FMFunc0ElPtrC>);
static_assert(!cIsFundamental<FMFunc1ElPtrC>);
static_assert(!cIsFundamental<FMFunc2ElPtrC>);
static_assert(!cIsFundamental<FMFunc0ElCPtr>);
static_assert(!cIsFundamental<FMFunc1ElCPtr>);
static_assert(!cIsFundamental<FMFunc2ElCPtr>);
static_assert(!cIsFundamental<FMFunc0ElCPtrC>);
static_assert(!cIsFundamental<FMFunc1ElCPtrC>);
static_assert(!cIsFundamental<FMFunc2ElCPtrC>);
static_assert(!cIsFundamental<CMPtr>);
static_assert(!cIsFundamental<CMCPtr>);
static_assert(!cIsFundamental<CMPtrC>);
static_assert(!cIsFundamental<CMCPtrC>);
static_assert(!cIsFundamental<CTestArray2>);
static_assert(!cIsFundamental<CTestArray2C>);
static_assert(!cIsFundamental<CTestArray>);
static_assert(!cIsFundamental<CTestArrayC>);
static_assert(!cIsFundamental<CTest2DArray2>);
static_assert(!cIsFundamental<CTest2DArray2C>);
static_assert(!cIsFundamental<CTest2DArray>);
static_assert(!cIsFundamental<CTest2DArrayC>);
static_assert(!cIsFundamental<CTest3DArray2>);
static_assert(!cIsFundamental<CTest3DArray2C>);
static_assert(!cIsFundamental<CTest3DArray>);
static_assert(!cIsFundamental<CTest3DArrayC>);
static_assert(!cIsFundamental<void *>);
static_assert(cIsFundamental<void>);

