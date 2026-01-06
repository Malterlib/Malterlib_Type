// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Is Int

#ifdef DMibPCanDo_int16384
static_assert(!cIsCompound<int16384>);
#else
static_assert(cIsCompound<int16384>);
#endif
#ifdef DMibPCanDo_int8192
static_assert(!cIsCompound<int8192>);
#else
static_assert(cIsCompound<int8192>);
#endif
#ifdef DMibPCanDo_int4096
static_assert(!cIsCompound<int4096>);
#else
static_assert(cIsCompound<int4096>);
#endif
#ifdef DMibPCanDo_int2048
static_assert(!cIsCompound<int2048>);
#else
static_assert(cIsCompound<int2048>);
#endif
#ifdef DMibPCanDo_int1024
static_assert(!cIsCompound<int1024>);
#else
static_assert(cIsCompound<int1024>);
#endif
#ifdef DMibPCanDo_int512
static_assert(!cIsCompound<int512>);
#else
static_assert(cIsCompound<int512>);
#endif
#ifdef DMibPCanDo_int256
static_assert(!cIsCompound<int256>);
#else
static_assert(cIsCompound<int256>);
#endif
#ifdef DMibPCanDo_int160
static_assert(!cIsCompound<int160>);
#else
static_assert(cIsCompound<int160>);
#endif
#ifdef DMibPCanDo_int192
static_assert(!cIsCompound<int192>);
#else
static_assert(cIsCompound<int192>);
#endif
#ifdef DMibPCanDo_int128
static_assert(!cIsCompound<int128>);
#else
static_assert(cIsCompound<int128>);
#endif
#ifdef DMibPCanDo_int80
static_assert(!cIsCompound<int80>);
#else
static_assert(cIsCompound<int80>);
#endif
#ifdef DMibPCanDo_int96
static_assert(!cIsCompound<int96>);
#else
static_assert(cIsCompound<int96>);
#endif
#ifdef DMibPCanDo_int64
static_assert(!cIsCompound<int64>);
#else
static_assert(cIsCompound<int64>);
#endif
#ifdef DMibPCanDo_int32
static_assert(!cIsCompound<int32>);
#else
static_assert(cIsCompound<int32>);
#endif
#ifdef DMibPCanDo_int16
static_assert(!cIsCompound<int16>);
#else
static_assert(cIsCompound<int16>);
#endif
#ifdef DMibPCanDo_int8
static_assert(!cIsCompound<int8>);
#else
static_assert(cIsCompound<int8>);
#endif

// These must always be fundamental
static_assert(!cIsCompound<aint>);
static_assert(!cIsCompound<uaint>);
static_assert(!cIsCompound<smint>);
static_assert(!cIsCompound<mint>);

#ifdef DMibPCanDo_uint16384
static_assert(!cIsCompound<uint16384>);
#else
static_assert(cIsCompound<uint16384>);
#endif
#ifdef DMibPCanDo_uint8192
static_assert(!cIsCompound<uint8192>);
#else
static_assert(cIsCompound<uint8192>);
#endif
#ifdef DMibPCanDo_uint4096
static_assert(!cIsCompound<uint4096>);
#else
static_assert(cIsCompound<uint4096>);
#endif
#ifdef DMibPCanDo_uint2048
static_assert(!cIsCompound<uint2048>);
#else
static_assert(cIsCompound<uint2048>);
#endif
#ifdef DMibPCanDo_uint1024
static_assert(!cIsCompound<uint1024>);
#else
static_assert(cIsCompound<uint1024>);
#endif
#ifdef DMibPCanDo_uint512
static_assert(!cIsCompound<uint512>);
#else
static_assert(cIsCompound<uint512>);
#endif
#ifdef DMibPCanDo_uint256
static_assert(!cIsCompound<uint256>);
#else
static_assert(cIsCompound<uint256>);
#endif
#ifdef DMibPCanDo_uint160
static_assert(!cIsCompound<uint160>);
#else
static_assert(cIsCompound<uint160>);
#endif
#ifdef DMibPCanDo_uint192
static_assert(!cIsCompound<uint192>);
#else
static_assert(cIsCompound<uint192>);
#endif
#ifdef DMibPCanDo_uint128
static_assert(!cIsCompound<uint128>);
#else
static_assert(cIsCompound<uint128>);
#endif
#ifdef DMibPCanDo_uint80
static_assert(!cIsCompound<uint80>);
#else
static_assert(cIsCompound<uint80>);
#endif
#ifdef DMibPCanDo_uint96
static_assert(!cIsCompound<uint96>);
#else
static_assert(cIsCompound<uint96>);
#endif
#ifdef DMibPCanDo_uint64
static_assert(!cIsCompound<uint64>);
#else
static_assert(cIsCompound<uint64>);
#endif
#ifdef DMibPCanDo_uint32
static_assert(!cIsCompound<uint32>);
#else
static_assert(cIsCompound<uint32>);
#endif
#ifdef DMibPCanDo_uint16
static_assert(!cIsCompound<uint16>);
#else
static_assert(cIsCompound<uint16>);
#endif
#ifdef DMibPCanDo_uint8
static_assert(!cIsCompound<uint8>);
#else
static_assert(cIsCompound<uint8>);
#endif

#ifdef DMibPCanDo_fp4096
static_assert(!cIsCompound<pfp4096>);
#else
static_assert(cIsCompound<fp4096>);
#endif
#ifdef DMibPCanDo_fp2048
static_assert(!cIsCompound<pfp2048>);
#else
static_assert(cIsCompound<fp2048>);
#endif
#ifdef DMibPCanDo_fp1024
static_assert(!cIsCompound<pfp1024>);
#else
static_assert(cIsCompound<fp1024>);
#endif
#ifdef DMibPCanDo_fp512
static_assert(!cIsCompound<pfp512>);
#else
static_assert(cIsCompound<fp512>);
#endif
#ifdef DMibPCanDo_fp256
static_assert(!cIsCompound<pfp256>);
#else
static_assert(cIsCompound<fp256>);
#endif
#ifdef DMibPCanDo_fp128
static_assert(!cIsCompound<pfp128>);
#else
static_assert(cIsCompound<fp128>);
#endif
#ifdef DMibPCanDo_fp80
static_assert(!cIsCompound<pfp80>);
#else
static_assert(cIsCompound<fp80>);
#endif
#ifdef DMibPCanDo_fp64
static_assert(!cIsCompound<pfp64>);
#else
static_assert(cIsCompound<fp64>);
#endif
#ifdef DMibPCanDo_fp32
static_assert(!cIsCompound<pfp32>);
#else
static_assert(cIsCompound<fp32>);
#endif
#ifdef DMibPCanDo_fp16
static_assert(!cIsCompound<pfp16>);
#else
static_assert(cIsCompound<fp16>);
#endif
#ifdef DMibPCanDo_fp8
static_assert(!cIsCompound<pfp8>);
#else
static_assert(cIsCompound<fp8>);
#endif

#ifdef DMibPCanDo_int16384
static_assert(!cIsCompound<const int16384>);
#else
static_assert(cIsCompound<const int16384>);
#endif
#ifdef DMibPCanDo_int8192
static_assert(!cIsCompound<const int8192>);
#else
static_assert(cIsCompound<const int8192>);
#endif
#ifdef DMibPCanDo_int4096
static_assert(!cIsCompound<const int4096>);
#else
static_assert(cIsCompound<const int4096>);
#endif
#ifdef DMibPCanDo_int2048
static_assert(!cIsCompound<const int2048>);
#else
static_assert(cIsCompound<const int2048>);
#endif
#ifdef DMibPCanDo_int1024
static_assert(!cIsCompound<const int1024>);
#else
static_assert(cIsCompound<const int1024>);
#endif
#ifdef DMibPCanDo_int512
static_assert(!cIsCompound<const int512>);
#else
static_assert(cIsCompound<const int512>);
#endif
#ifdef DMibPCanDo_int256
static_assert(!cIsCompound<const int256>);
#else
static_assert(cIsCompound<const int256>);
#endif
#ifdef DMibPCanDo_int160
static_assert(!cIsCompound<const int160>);
#else
static_assert(cIsCompound<const int160>);
#endif
#ifdef DMibPCanDo_int192
static_assert(!cIsCompound<const int192>);
#else
static_assert(cIsCompound<const int192>);
#endif
#ifdef DMibPCanDo_int128
static_assert(!cIsCompound<const int128>);
#else
static_assert(cIsCompound<const int128>);
#endif
#ifdef DMibPCanDo_int80
static_assert(!cIsCompound<const int80>);
#else
static_assert(cIsCompound<const int80>);
#endif
#ifdef DMibPCanDo_int96
static_assert(!cIsCompound<const int96>);
#else
static_assert(cIsCompound<const int96>);
#endif
#ifdef DMibPCanDo_int64
static_assert(!cIsCompound<const int64>);
#else
static_assert(cIsCompound<const int64>);
#endif
#ifdef DMibPCanDo_int32
static_assert(!cIsCompound<const int32>);
#else
static_assert(cIsCompound<const int32>);
#endif
#ifdef DMibPCanDo_int16
static_assert(!cIsCompound<const int16>);
#else
static_assert(cIsCompound<const int16>);
#endif
#ifdef DMibPCanDo_int8
static_assert(!cIsCompound<const int8>);
#else
static_assert(cIsCompound<const int8>);
#endif

// These must always be fundamental
static_assert(!cIsCompound<const aint>);
static_assert(!cIsCompound<const uaint>);
static_assert(!cIsCompound<const smint>);
static_assert(!cIsCompound<const mint>);

#ifdef DMibPCanDo_uint16384
static_assert(!cIsCompound<const uint16384>);
#else
static_assert(cIsCompound<const uint16384>);
#endif
#ifdef DMibPCanDo_uint8192
static_assert(!cIsCompound<const uint8192>);
#else
static_assert(cIsCompound<const uint8192>);
#endif
#ifdef DMibPCanDo_uint4096
static_assert(!cIsCompound<const uint4096>);
#else
static_assert(cIsCompound<const uint4096>);
#endif
#ifdef DMibPCanDo_uint2048
static_assert(!cIsCompound<const uint2048>);
#else
static_assert(cIsCompound<const uint2048>);
#endif
#ifdef DMibPCanDo_uint1024
static_assert(!cIsCompound<const uint1024>);
#else
static_assert(cIsCompound<const uint1024>);
#endif
#ifdef DMibPCanDo_uint512
static_assert(!cIsCompound<const uint512>);
#else
static_assert(cIsCompound<const uint512>);
#endif
#ifdef DMibPCanDo_uint256
static_assert(!cIsCompound<const uint256>);
#else
static_assert(cIsCompound<const uint256>);
#endif
#ifdef DMibPCanDo_uint160
static_assert(!cIsCompound<const uint160>);
#else
static_assert(cIsCompound<const uint160>);
#endif
#ifdef DMibPCanDo_uint192
static_assert(!cIsCompound<const uint192>);
#else
static_assert(cIsCompound<const uint192>);
#endif
#ifdef DMibPCanDo_uint128
static_assert(!cIsCompound<const uint128>);
#else
static_assert(cIsCompound<const uint128>);
#endif
#ifdef DMibPCanDo_uint80
static_assert(!cIsCompound<const uint80>);
#else
static_assert(cIsCompound<const uint80>);
#endif
#ifdef DMibPCanDo_uint96
static_assert(!cIsCompound<const uint96>);
#else
static_assert(cIsCompound<const uint96>);
#endif
#ifdef DMibPCanDo_uint64
static_assert(!cIsCompound<const uint64>);
#else
static_assert(cIsCompound<const uint64>);
#endif
#ifdef DMibPCanDo_uint32
static_assert(!cIsCompound<const uint32>);
#else
static_assert(cIsCompound<const uint32>);
#endif
#ifdef DMibPCanDo_uint16
static_assert(!cIsCompound<const uint16>);
#else
static_assert(cIsCompound<const uint16>);
#endif
#ifdef DMibPCanDo_uint8
static_assert(!cIsCompound<const uint8>);
#else
static_assert(cIsCompound<const uint8>);
#endif

#ifdef DMibPCanDo_fp4096
static_assert(!cIsCompound<const pfp4096>);
#else
static_assert(cIsCompound<const fp4096>);
#endif
#ifdef DMibPCanDo_fp2048
static_assert(!cIsCompound<const pfp2048>);
#else
static_assert(cIsCompound<const fp2048>);
#endif
#ifdef DMibPCanDo_fp1024
static_assert(!cIsCompound<const pfp1024>);
#else
static_assert(cIsCompound<const fp1024>);
#endif
#ifdef DMibPCanDo_fp512
static_assert(!cIsCompound<const pfp512>);
#else
static_assert(cIsCompound<const fp512>);
#endif
#ifdef DMibPCanDo_fp256
static_assert(!cIsCompound<const pfp256>);
#else
static_assert(cIsCompound<const fp256>);
#endif
#ifdef DMibPCanDo_fp128
static_assert(!cIsCompound<const pfp128>);
#else
static_assert(cIsCompound<const fp128>);
#endif
#ifdef DMibPCanDo_fp80
static_assert(!cIsCompound<const pfp80>);
#else
static_assert(cIsCompound<const fp80>);
#endif
#ifdef DMibPCanDo_fp64
static_assert(!cIsCompound<const pfp64>);
#else
static_assert(cIsCompound<const fp64>);
#endif
#ifdef DMibPCanDo_fp32
static_assert(!cIsCompound<const pfp32>);
#else
static_assert(cIsCompound<const fp32>);
#endif
#ifdef DMibPCanDo_fp16
static_assert(!cIsCompound<const pfp16>);
#else
static_assert(cIsCompound<const fp16>);
#endif
#ifdef DMibPCanDo_fp8
static_assert(!cIsCompound<const pfp8>);
#else
static_assert(cIsCompound<const fp8>);
#endif

// These must always be fundamental
static_assert(!cIsCompound<int>);
static_assert(!cIsCompound<unsigned int>);

static_assert(cIsCompound<CTestUnion>);
static_assert(cIsCompound<CTestClass0>);
static_assert(cIsCompound<CTestClass1>);
static_assert(cIsCompound<CTestStruct0>);
static_assert(cIsCompound<CTestStruct1>);
static_assert(cIsCompound<ETestEnum>);
static_assert(cIsCompound<CTestClass>);
static_assert(cIsCompound<CTestC>);
static_assert(cIsCompound<CTestPtr>);
static_assert(cIsCompound<CTestCPtr>);
static_assert(cIsCompound<CTestPtrC>);
static_assert(cIsCompound<CTestCPtrC>);
static_assert(cIsCompound<CTestRef>);
static_assert(cIsCompound<CTestCRef>);
static_assert(cIsCompound<CTestRRef>);
static_assert(cIsCompound<CTestCRRef>);
static_assert(cIsCompound<PFFunc0>);
static_assert(cIsCompound<PFFunc1>);
static_assert(cIsCompound<PFFunc2>);
static_assert(cIsCompound<FFunc0Ref>);
static_assert(cIsCompound<FFunc1Ref>);
static_assert(cIsCompound<FFunc2Ref>);
static_assert(cIsCompound<FFunc0RRef>);
static_assert(cIsCompound<FFunc1RRef>);
static_assert(cIsCompound<FFunc2RRef>);
static_assert(cIsCompound<FFunc0Ptr>);
static_assert(cIsCompound<FFunc1Ptr>);
static_assert(cIsCompound<FFunc2Ptr>);
static_assert(cIsCompound<FFunc0PtrC>);
static_assert(cIsCompound<FFunc1PtrC>);
static_assert(cIsCompound<FFunc2PtrC>);
static_assert(cIsCompound<FMFunc0Ptr>);
static_assert(cIsCompound<FMFunc1Ptr>);
static_assert(cIsCompound<FMFunc2Ptr>);
static_assert(cIsCompound<FMFunc0PtrC>);
static_assert(cIsCompound<FMFunc1PtrC>);
static_assert(cIsCompound<FMFunc2PtrC>);
static_assert(cIsCompound<FMFunc0CPtr>);
static_assert(cIsCompound<FMFunc1CPtr>);
static_assert(cIsCompound<FMFunc2CPtr>);
static_assert(cIsCompound<FMFunc0CPtrC>);
static_assert(cIsCompound<FMFunc1CPtrC>);
static_assert(cIsCompound<FMFunc2CPtrC>);
static_assert(cIsCompound<PFFunc0El>);
static_assert(cIsCompound<PFFunc1El>);
static_assert(cIsCompound<PFFunc2El>);
static_assert(cIsCompound<FFunc0ElRef>);
static_assert(cIsCompound<FFunc1ElRef>);
static_assert(cIsCompound<FFunc2ElRef>);
static_assert(cIsCompound<FFunc0ElRRef>);
static_assert(cIsCompound<FFunc1ElRRef>);
static_assert(cIsCompound<FFunc2ElRRef>);
static_assert(cIsCompound<FFunc0ElPtr>);
static_assert(cIsCompound<FFunc1ElPtr>);
static_assert(cIsCompound<FFunc2ElPtr>);
static_assert(cIsCompound<FFunc0ElPtrC>);
static_assert(cIsCompound<FFunc1ElPtrC>);
static_assert(cIsCompound<FFunc2ElPtrC>);
static_assert(cIsCompound<FMFunc0ElPtr>);
static_assert(cIsCompound<FMFunc1ElPtr>);
static_assert(cIsCompound<FMFunc2ElPtr>);
static_assert(cIsCompound<FMFunc0ElPtrC>);
static_assert(cIsCompound<FMFunc1ElPtrC>);
static_assert(cIsCompound<FMFunc2ElPtrC>);
static_assert(cIsCompound<FMFunc0ElCPtr>);
static_assert(cIsCompound<FMFunc1ElCPtr>);
static_assert(cIsCompound<FMFunc2ElCPtr>);
static_assert(cIsCompound<FMFunc0ElCPtrC>);
static_assert(cIsCompound<FMFunc1ElCPtrC>);
static_assert(cIsCompound<FMFunc2ElCPtrC>);
static_assert(cIsCompound<CMPtr>);
static_assert(cIsCompound<CMCPtr>);
static_assert(cIsCompound<CMPtrC>);
static_assert(cIsCompound<CMCPtrC>);
static_assert(cIsCompound<CTestArray2>);
static_assert(cIsCompound<CTestArray2C>);
static_assert(cIsCompound<CTestArray>);
static_assert(cIsCompound<CTestArrayC>);
static_assert(cIsCompound<CTest2DArray2>);
static_assert(cIsCompound<CTest2DArray2C>);
static_assert(cIsCompound<CTest2DArray>);
static_assert(cIsCompound<CTest2DArrayC>);
static_assert(cIsCompound<CTest3DArray2>);
static_assert(cIsCompound<CTest3DArray2C>);
static_assert(cIsCompound<CTest3DArray>);
static_assert(cIsCompound<CTest3DArrayC>);
static_assert(cIsCompound<void *>);
static_assert(!cIsCompound<void>);
