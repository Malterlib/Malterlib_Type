// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Is Int
	
#ifdef DMibPCanDo_int8192
DMibStaticCheck((	!TCIsCompound<int8192>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	!TCIsCompound<int4096>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	!TCIsCompound<int2048>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	!TCIsCompound<int1024>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	!TCIsCompound<int512>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	!TCIsCompound<int256>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	!TCIsCompound<int160>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	!TCIsCompound<int128>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	!TCIsCompound<int80>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	!TCIsCompound<int64>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	!TCIsCompound<int32>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	!TCIsCompound<int16>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	!TCIsCompound<int8>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<int8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	!TCIsCompound<aint>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<uaint>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<smint>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<mint>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	!TCIsCompound<uint8192>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	!TCIsCompound<uint4096>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	!TCIsCompound<uint2048>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	!TCIsCompound<uint1024>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	!TCIsCompound<uint512>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	!TCIsCompound<uint256>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	!TCIsCompound<uint160>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	!TCIsCompound<uint128>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	!TCIsCompound<uint80>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	!TCIsCompound<uint64>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	!TCIsCompound<uint32>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	!TCIsCompound<uint16>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	!TCIsCompound<uint8>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	!TCIsCompound<pfp4096>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	!TCIsCompound<pfp2048>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	!TCIsCompound<pfp1024>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	!TCIsCompound<pfp512>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	!TCIsCompound<pfp256>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	!TCIsCompound<pfp128>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	!TCIsCompound<pfp80>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	!TCIsCompound<pfp64>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	!TCIsCompound<pfp32>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	!TCIsCompound<pfp16>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	!TCIsCompound<pfp8>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<fp8>::mc_Value	));
#endif

#ifdef DMibPCanDo_int8192
DMibStaticCheck((	!TCIsCompound<const int8192>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	!TCIsCompound<const int4096>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	!TCIsCompound<const int2048>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	!TCIsCompound<const int1024>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	!TCIsCompound<const int512>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	!TCIsCompound<const int256>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	!TCIsCompound<const int160>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	!TCIsCompound<const int128>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	!TCIsCompound<const int80>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	!TCIsCompound<const int64>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	!TCIsCompound<const int32>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	!TCIsCompound<const int16>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	!TCIsCompound<const int8>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const int8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	!TCIsCompound<const aint>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<const uaint>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<const smint>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<const mint>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	!TCIsCompound<const uint8192>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	!TCIsCompound<const uint4096>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	!TCIsCompound<const uint2048>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	!TCIsCompound<const uint1024>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	!TCIsCompound<const uint512>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	!TCIsCompound<const uint256>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	!TCIsCompound<const uint160>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	!TCIsCompound<const uint128>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	!TCIsCompound<const uint80>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	!TCIsCompound<const uint64>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	!TCIsCompound<const uint32>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	!TCIsCompound<const uint16>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	!TCIsCompound<const uint8>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	!TCIsCompound<const pfp4096>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	!TCIsCompound<const pfp2048>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	!TCIsCompound<const pfp1024>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	!TCIsCompound<const pfp512>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	!TCIsCompound<const pfp256>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	!TCIsCompound<const pfp128>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	!TCIsCompound<const pfp80>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	!TCIsCompound<const pfp64>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	!TCIsCompound<const pfp32>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	!TCIsCompound<const pfp16>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	!TCIsCompound<const pfp8>::mc_Value	));
#else
DMibStaticCheck((	TCIsCompound<const fp8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	!TCIsCompound<int>::mc_Value	));
DMibStaticCheck((	!TCIsCompound<unsigned int>::mc_Value	));

DMibStaticCheck((	TCIsCompound<CTestUnion>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestClass0>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestClass1>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestStruct0>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestStruct1>::mc_Value		));
DMibStaticCheck((	TCIsCompound<ETestEnum>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestClass>::mc_Value				));
DMibStaticCheck((	TCIsCompound<CTestC>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestPtr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestCPtr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestRef>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<PFFunc0>::mc_Value			));
DMibStaticCheck((	TCIsCompound<PFFunc1>::mc_Value			));
DMibStaticCheck((	TCIsCompound<PFFunc2>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc0Ref>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc1Ref>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc2Ref>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc0RRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc1RRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc2RRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc0PtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc1PtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc2PtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0Ptr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1Ptr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2Ptr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0PtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1PtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2PtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<PFFunc0El>::mc_Value			));
DMibStaticCheck((	TCIsCompound<PFFunc1El>::mc_Value			));
DMibStaticCheck((	TCIsCompound<PFFunc2El>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc0ElRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc1ElRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc2ElRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc0ElRRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc1ElRRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc2ElRRef>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<FFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0ElPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1ElPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2ElPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CMPtr>::mc_Value				));
DMibStaticCheck((	TCIsCompound<CMCPtr>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CMPtrC>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CMCPtrC>::mc_Value			));
DMibStaticCheck((	TCIsCompound<CTestArray2>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestArray2C>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestArray>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTestArrayC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTest2DArray2>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	TCIsCompound<CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTest3DArray2>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	TCIsCompound<CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsCompound<CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	TCIsCompound<void *>::mc_Value			));
DMibStaticCheck((	TCIsCompound<void>::mc_Value				));
