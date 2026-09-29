// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

static_assert(!cIsScalar<int16384>);
static_assert(!cIsScalar<int8192>);
static_assert(!cIsScalar<int4096>);
static_assert(!cIsScalar<int2048>);
static_assert(!cIsScalar<int1024>);
static_assert(!cIsScalar<int512>);
static_assert(!cIsScalar<int256>);
static_assert(!cIsScalar<int160>);
static_assert(!cIsScalar<int192>);
#ifdef DMibPCanDo_int128
static_assert(cIsScalar<int128>);
#else
static_assert(!cIsScalar<int128>);
#endif
#ifdef DMibPCanDo_int80
static_assert(cIsScalar<int80>);
#else
static_assert(!cIsScalar<int80>);
#endif
#ifdef DMibPCanDo_int96
static_assert(cIsScalar<int96>);
#else
static_assert(!cIsScalar<int96>);
#endif
#ifdef DMibPCanDo_int64
static_assert(cIsScalar<int64>);
#else
static_assert(!cIsScalar<int64>);
#endif
#ifdef DMibPCanDo_int32
static_assert(cIsScalar<int32>);
#else
static_assert(!cIsScalar<int32>);
#endif
#ifdef DMibPCanDo_int16
static_assert(cIsScalar<int16>);
#else
static_assert(!cIsScalar<int16>);
#endif
#ifdef DMibPCanDo_int8
static_assert(cIsScalar<int8>);
#else
static_assert(!cIsScalar<int8>);
#endif

static_assert(cIsScalar<aint>);
static_assert(cIsScalar<uaint>);
static_assert(cIsScalar<smint>);
static_assert(cIsScalar<umint>);

static_assert(!cIsScalar<uint16384>);
static_assert(!cIsScalar<uint8192>);
static_assert(!cIsScalar<uint4096>);
static_assert(!cIsScalar<uint2048>);
static_assert(!cIsScalar<uint1024>);
static_assert(!cIsScalar<uint512>);
static_assert(!cIsScalar<uint256>);
static_assert(!cIsScalar<uint160>);
static_assert(!cIsScalar<uint192>);
#ifdef DMibPCanDo_uint128
static_assert(cIsScalar<uint128>);
#else
static_assert(!cIsScalar<uint128>);
#endif
#ifdef DMibPCanDo_uint80
static_assert(cIsScalar<uint80>);
#else
static_assert(!cIsScalar<uint80>);
#endif
#ifdef DMibPCanDo_uint96
static_assert(cIsScalar<uint96>);
#else
static_assert(!cIsScalar<uint96>);
#endif
#ifdef DMibPCanDo_uint64
static_assert(cIsScalar<uint64>);
#else
static_assert(!cIsScalar<uint64>);
#endif
#ifdef DMibPCanDo_uint32
static_assert(cIsScalar<uint32>);
#else
static_assert(!cIsScalar<uint32>);
#endif
#ifdef DMibPCanDo_uint16
static_assert(cIsScalar<uint16>);
#else
static_assert(!cIsScalar<uint16>);
#endif
#ifdef DMibPCanDo_uint8
static_assert(cIsScalar<uint8>);
#else
static_assert(!cIsScalar<uint8>);
#endif

static_assert(!cIsScalar<fp4096>);
static_assert(!cIsScalar<fp2048>);
static_assert(!cIsScalar<fp1024>);
static_assert(!cIsScalar<fp512>);
static_assert(!cIsScalar<fp256>);
static_assert(!cIsScalar<fp128>);
static_assert(!cIsScalar<fp80>);
static_assert(!cIsScalar<fp64>);
static_assert(!cIsScalar<fp32>);
static_assert(!cIsScalar<fp16>);
static_assert(!cIsScalar<fp8>);

static_assert(!cIsScalar<int16384 const>);
static_assert(!cIsScalar<int8192 const>);
static_assert(!cIsScalar<int4096 const>);
static_assert(!cIsScalar<int2048 const>);
static_assert(!cIsScalar<int1024 const>);
static_assert(!cIsScalar<int512 const>);
static_assert(!cIsScalar<int256 const>);
static_assert(!cIsScalar<int160 const>);
static_assert(!cIsScalar<int192 const>);
#ifdef DMibPCanDo_int128
static_assert(cIsScalar<int128 const>);
#else
static_assert(!cIsScalar<int128 const>);
#endif
#ifdef DMibPCanDo_int80
static_assert(cIsScalar<int80 const>);
#else
static_assert(!cIsScalar<int80 const>);
#endif
#ifdef DMibPCanDo_int96
static_assert(cIsScalar<int96 const>);
#else
static_assert(!cIsScalar<int96 const>);
#endif
#ifdef DMibPCanDo_int64
static_assert(cIsScalar<int64 const>);
#else
static_assert(!cIsScalar<int64 const>);
#endif
#ifdef DMibPCanDo_int32
static_assert(cIsScalar<int32 const>);
#else
static_assert(!cIsScalar<int32 const>);
#endif
#ifdef DMibPCanDo_int16
static_assert(cIsScalar<int16 const>);
#else
static_assert(!cIsScalar<int16 const>);
#endif
#ifdef DMibPCanDo_int8
static_assert(cIsScalar<int8 const>);
#else
static_assert(!cIsScalar<int8 const>);
#endif

static_assert(cIsScalar<aint const>);
static_assert(cIsScalar<uaint const>);
static_assert(cIsScalar<smint const>);
static_assert(cIsScalar<umint const>);

static_assert(!cIsScalar<uint16384 const>);
static_assert(!cIsScalar<uint8192 const>);
static_assert(!cIsScalar<uint4096 const>);
static_assert(!cIsScalar<uint2048 const>);
static_assert(!cIsScalar<uint1024 const>);
static_assert(!cIsScalar<uint512 const>);
static_assert(!cIsScalar<uint256 const>);
static_assert(!cIsScalar<uint160 const>);
static_assert(!cIsScalar<uint192 const>);
#ifdef DMibPCanDo_uint128
static_assert(cIsScalar<uint128 const>);
#else
static_assert(!cIsScalar<uint128 const>);
#endif
#ifdef DMibPCanDo_uint80
static_assert(cIsScalar<uint80 const>);
#else
static_assert(!cIsScalar<uint80 const>);
#endif
#ifdef DMibPCanDo_uint96
static_assert(cIsScalar<uint96 const>);
#else
static_assert(!cIsScalar<uint96 const>);
#endif
#ifdef DMibPCanDo_uint64
static_assert(cIsScalar<uint64 const>);
#else
static_assert(!cIsScalar<uint64 const>);
#endif
#ifdef DMibPCanDo_uint32
static_assert(cIsScalar<uint32 const>);
#else
static_assert(!cIsScalar<uint32 const>);
#endif
#ifdef DMibPCanDo_uint16
static_assert(cIsScalar<uint16 const>);
#else
static_assert(!cIsScalar<uint16 const>);
#endif
#ifdef DMibPCanDo_uint8
static_assert(cIsScalar<uint8 const>);
#else
static_assert(!cIsScalar<uint8 const>);
#endif

static_assert(!cIsScalar<fp4096 const>);
static_assert(!cIsScalar<fp2048 const>);
static_assert(!cIsScalar<fp1024 const>);
static_assert(!cIsScalar<fp512 const>);
static_assert(!cIsScalar<fp256 const>);
static_assert(!cIsScalar<fp128 const>);
static_assert(!cIsScalar<fp80 const>);
static_assert(!cIsScalar<fp64 const>);
static_assert(!cIsScalar<fp32 const>);
static_assert(!cIsScalar<fp16 const>);
static_assert(!cIsScalar<fp8 const>);

static_assert(!cIsScalar<CTestUnion>);
static_assert(!cIsScalar<CTestClass0>);
static_assert(!cIsScalar<CTestClass1>);
static_assert(!cIsScalar<CTestStruct0>);
static_assert(!cIsScalar<CTestStruct1>);
static_assert(cIsScalar<ETestEnum>);
static_assert(!cIsScalar<CTestClass>);
static_assert(!cIsScalar<CTestC>);
static_assert(cIsScalar<CTestPtr>);
static_assert(cIsScalar<CTestCPtr>);
static_assert(cIsScalar<CTestPtrC>);
static_assert(cIsScalar<CTestCPtrC>);
static_assert(!cIsScalar<CTestRef>);
static_assert(!cIsScalar<CTestCRef>);
static_assert(!cIsScalar<CTestRRef>);
static_assert(!cIsScalar<CTestCRRef>);
static_assert(!cIsScalar<PFFunc0>);
static_assert(!cIsScalar<PFFunc1>);
static_assert(!cIsScalar<PFFunc2>);
static_assert(!cIsScalar<FFunc0Ref>);
static_assert(!cIsScalar<FFunc1Ref>);
static_assert(!cIsScalar<FFunc2Ref>);
static_assert(!cIsScalar<FFunc0RRef>);
static_assert(!cIsScalar<FFunc1RRef>);
static_assert(!cIsScalar<FFunc2RRef>);
static_assert(cIsScalar<FFunc0Ptr>);
static_assert(cIsScalar<FFunc1Ptr>);
static_assert(cIsScalar<FFunc2Ptr>);
static_assert(cIsScalar<FFunc0PtrC>);
static_assert(cIsScalar<FFunc1PtrC>);
static_assert(cIsScalar<FFunc2PtrC>);
static_assert(cIsScalar<FMFunc0Ptr>);
static_assert(cIsScalar<FMFunc1Ptr>);
static_assert(cIsScalar<FMFunc2Ptr>);
static_assert(cIsScalar<FMFunc0PtrC>);
static_assert(cIsScalar<FMFunc1PtrC>);
static_assert(cIsScalar<FMFunc2PtrC>);
static_assert(cIsScalar<FMFunc0CPtr>);
static_assert(cIsScalar<FMFunc1CPtr>);
static_assert(cIsScalar<FMFunc2CPtr>);
static_assert(cIsScalar<FMFunc0CPtrC>);
static_assert(cIsScalar<FMFunc1CPtrC>);
static_assert(cIsScalar<FMFunc2CPtrC>);
static_assert(!cIsScalar<PFFunc0El>);
static_assert(!cIsScalar<PFFunc1El>);
static_assert(!cIsScalar<PFFunc2El>);
static_assert(!cIsScalar<FFunc0ElRef>);
static_assert(!cIsScalar<FFunc1ElRef>);
static_assert(!cIsScalar<FFunc2ElRef>);
static_assert(!cIsScalar<FFunc0ElRRef>);
static_assert(!cIsScalar<FFunc1ElRRef>);
static_assert(!cIsScalar<FFunc2ElRRef>);
static_assert(cIsScalar<FFunc0ElPtr>);
static_assert(cIsScalar<FFunc1ElPtr>);
static_assert(cIsScalar<FFunc2ElPtr>);
static_assert(cIsScalar<FFunc0ElPtrC>);
static_assert(cIsScalar<FFunc1ElPtrC>);
static_assert(cIsScalar<FFunc2ElPtrC>);
static_assert(cIsScalar<FMFunc0ElPtr>);
static_assert(cIsScalar<FMFunc1ElPtr>);
static_assert(cIsScalar<FMFunc2ElPtr>);
static_assert(cIsScalar<FMFunc0ElPtrC>);
static_assert(cIsScalar<FMFunc1ElPtrC>);
static_assert(cIsScalar<FMFunc2ElPtrC>);
static_assert(cIsScalar<FMFunc0ElCPtr>);
static_assert(cIsScalar<FMFunc1ElCPtr>);
static_assert(cIsScalar<FMFunc2ElCPtr>);
static_assert(cIsScalar<FMFunc0ElCPtrC>);
static_assert(cIsScalar<FMFunc1ElCPtrC>);
static_assert(cIsScalar<FMFunc2ElCPtrC>);
static_assert(cIsScalar<CMPtr>);
static_assert(cIsScalar<CMCPtr>);
static_assert(cIsScalar<CMPtrC>);
static_assert(cIsScalar<CMCPtrC>);
static_assert(!cIsScalar<CTestArray2>);
static_assert(!cIsScalar<CTestArray2C>);
static_assert(!cIsScalar<CTestArray>);
static_assert(!cIsScalar<CTestArrayC>);
static_assert(!cIsScalar<CTest2DArray2>);
static_assert(!cIsScalar<CTest2DArray2C>);
static_assert(!cIsScalar<CTest2DArray>);
static_assert(!cIsScalar<CTest2DArrayC>);
static_assert(!cIsScalar<CTest3DArray2>);
static_assert(!cIsScalar<CTest3DArray2C>);
static_assert(!cIsScalar<CTest3DArray>);
static_assert(!cIsScalar<CTest3DArrayC>);
static_assert(cIsScalar<void *>);
static_assert(!cIsScalar<void>);

