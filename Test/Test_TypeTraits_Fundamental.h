// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Is Int
	
#ifdef DMibPCanDo_int8192
DMibStaticCheck((	TCIsFundamental<int8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	TCIsFundamental<int4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	TCIsFundamental<int2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	TCIsFundamental<int1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	TCIsFundamental<int512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	TCIsFundamental<int256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	TCIsFundamental<int160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	TCIsFundamental<int128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	TCIsFundamental<int80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	TCIsFundamental<int64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	TCIsFundamental<int32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	TCIsFundamental<int16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	TCIsFundamental<int8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<int8>::mc_Value	));
#endif


// These must always be fundamental
DMibStaticCheck((	TCIsFundamental<aint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<uaint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<smint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<mint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<int>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<unsigned int>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	TCIsFundamental<uint8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	TCIsFundamental<uint4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	TCIsFundamental<uint2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	TCIsFundamental<uint1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	TCIsFundamental<uint512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	TCIsFundamental<uint256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	TCIsFundamental<uint160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	TCIsFundamental<uint128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	TCIsFundamental<uint80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	TCIsFundamental<uint64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	TCIsFundamental<uint32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	TCIsFundamental<uint16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	TCIsFundamental<uint8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	TCIsFundamental<pfp4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	TCIsFundamental<pfp2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	TCIsFundamental<pfp1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	TCIsFundamental<pfp512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	TCIsFundamental<pfp256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	TCIsFundamental<pfp128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	TCIsFundamental<pfp80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	TCIsFundamental<pfp64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	TCIsFundamental<pfp32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	TCIsFundamental<pfp16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	TCIsFundamental<pfp8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<fp8>::mc_Value	));
#endif

#ifdef DMibPCanDo_int8192
DMibStaticCheck((	TCIsFundamental<const int8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_int4096
DMibStaticCheck((	TCIsFundamental<const int4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_int2048
DMibStaticCheck((	TCIsFundamental<const int2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_int1024
DMibStaticCheck((	TCIsFundamental<const int1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_int512
DMibStaticCheck((	TCIsFundamental<const int512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int512>::mc_Value	));
#endif
#ifdef DMibPCanDo_int256
DMibStaticCheck((	TCIsFundamental<const int256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int256>::mc_Value	));
#endif
#ifdef DMibPCanDo_int160
DMibStaticCheck((	TCIsFundamental<const int160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int160>::mc_Value	));
#endif
#ifdef DMibPCanDo_int128
DMibStaticCheck((	TCIsFundamental<const int128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int128>::mc_Value	));
#endif
#ifdef DMibPCanDo_int80
DMibStaticCheck((	TCIsFundamental<const int80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int80>::mc_Value	));
#endif
#ifdef DMibPCanDo_int64
DMibStaticCheck((	TCIsFundamental<const int64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int64>::mc_Value	));
#endif
#ifdef DMibPCanDo_int32
DMibStaticCheck((	TCIsFundamental<const int32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int32>::mc_Value	));
#endif
#ifdef DMibPCanDo_int16
DMibStaticCheck((	TCIsFundamental<const int16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int16>::mc_Value	));
#endif
#ifdef DMibPCanDo_int8
DMibStaticCheck((	TCIsFundamental<const int8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const int8>::mc_Value	));
#endif

// These must always be fundamental
DMibStaticCheck((	TCIsFundamental<const aint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const uaint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const smint>::mc_Value	));
DMibStaticCheck((	TCIsFundamental<const mint>::mc_Value	));

#ifdef DMibPCanDo_uint8192
DMibStaticCheck((	TCIsFundamental<const uint8192>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint8192>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint4096
DMibStaticCheck((	TCIsFundamental<const uint4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint2048
DMibStaticCheck((	TCIsFundamental<const uint2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint1024
DMibStaticCheck((	TCIsFundamental<const uint1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint512
DMibStaticCheck((	TCIsFundamental<const uint512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint512>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint256
DMibStaticCheck((	TCIsFundamental<const uint256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint256>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint160
DMibStaticCheck((	TCIsFundamental<const uint160>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint160>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint128
DMibStaticCheck((	TCIsFundamental<const uint128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint128>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint80
DMibStaticCheck((	TCIsFundamental<const uint80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint80>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint64
DMibStaticCheck((	TCIsFundamental<const uint64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint64>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint32
DMibStaticCheck((	TCIsFundamental<const uint32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint32>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint16
DMibStaticCheck((	TCIsFundamental<const uint16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint16>::mc_Value	));
#endif
#ifdef DMibPCanDo_uint8
DMibStaticCheck((	TCIsFundamental<const uint8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const uint8>::mc_Value	));
#endif

#ifdef DMibPCanDo_fp4096
DMibStaticCheck((	TCIsFundamental<const pfp4096>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp4096>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp2048
DMibStaticCheck((	TCIsFundamental<const pfp2048>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp2048>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp1024
DMibStaticCheck((	TCIsFundamental<const pfp1024>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp1024>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp512
DMibStaticCheck((	TCIsFundamental<const pfp512>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp512>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp256
DMibStaticCheck((	TCIsFundamental<const pfp256>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp256>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp128
DMibStaticCheck((	TCIsFundamental<const pfp128>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp128>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp80
DMibStaticCheck((	TCIsFundamental<const pfp80>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp80>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp64
DMibStaticCheck((	TCIsFundamental<const pfp64>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp64>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp32
DMibStaticCheck((	TCIsFundamental<const pfp32>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp32>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp16
DMibStaticCheck((	TCIsFundamental<const pfp16>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp16>::mc_Value	));
#endif
#ifdef DMibPCanDo_fp8
DMibStaticCheck((	TCIsFundamental<const pfp8>::mc_Value	));
#else
DMibStaticCheck((	!TCIsFundamental<const fp8>::mc_Value	));
#endif


DMibStaticCheck((	!TCIsFundamental<CTestUnion>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestStruct0>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestStruct1>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<ETestEnum>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestClass>::mc_Value				));
DMibStaticCheck((	!TCIsFundamental<CTestC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestRef>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestCRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestCRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<PFFunc0>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc1>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc2>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0Ref>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1Ref>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2Ref>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0RRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1RRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2RRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<PFFunc0El>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc1El>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<PFFunc2El>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<FFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CMPtr>::mc_Value				));
DMibStaticCheck((	!TCIsFundamental<CMCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CMCPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<CTestArray2>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArray2C>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArray>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTestArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest2DArray>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsFundamental<CTest3DArray>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsFundamental<void *>::mc_Value			));
DMibStaticCheck((	!TCIsFundamental<void>::mc_Value				));

