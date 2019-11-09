// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

DMibStaticCheck(	(sizeof(ch8) == 1)	);
DMibStaticCheck(	(sizeof(ch16) == 2)	);
DMibStaticCheck(	(sizeof(ch32) == 4)	);

#ifdef DMibPSignedType_ch8
	DMibStaticCheck(int32(ch8(uint8(0xffu))) == -1);
#else
	DMibStaticCheck(int32(ch8(uint8(0xffu))) == 0xffu);
#endif

#ifdef DMibPSignedType_ch16
	DMibStaticCheck(int32(ch16(uint16(0xffffu))) == -1);
#else
	DMibStaticCheck(int32(ch16(uint16(0xffffu))) == 0xffffu);
#endif

#ifdef DMibPSignedType_ch32
	DMibStaticCheck(int64(ch32(uint32(0xffffffffu))) == -1);
#else
	DMibStaticCheck(int64(ch32(uint32(0xffffffffu))) == 0xffffffffu);
#endif

// Is Signed
DMibStaticCheck((	!TCIsSigned<ufp32>::mc_Value	));

	
DMibStaticCheck((	TCIsSigned<int8192>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int4096>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int2048>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int1024>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int512>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int256>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int160>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int128>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int80>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int64>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int32>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int16>::mc_Value	));
DMibStaticCheck((	TCIsSigned<int8>::mc_Value	));

DMibStaticCheck((	TCIsSigned<aint>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<uaint>::mc_Value	));
DMibStaticCheck((	TCIsSigned<smint>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<mint>::mc_Value		));

DMibStaticCheck((	!TCIsSigned<uint4096>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint2048>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint1024>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint512>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint256>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint160>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint128>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint80>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint64>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint32>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint16>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<uint8>::mc_Value	));

DMibStaticCheck((	TCIsSigned<fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp512>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp256>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp128>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp80>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp64>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp32>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp16>::mc_Value	));
DMibStaticCheck((	TCIsSigned<fp8>::mc_Value	));

DMibStaticCheck((	TCIsSigned<const int8192>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int4096>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int2048>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int1024>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int512>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int256>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int160>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int128>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int80>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int64>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int32>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int16>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const int8>::mc_Value	));

DMibStaticCheck((	!TCIsSigned<const uint4096>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint2048>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint1024>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint512>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint256>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint160>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint128>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint80>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint64>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint32>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint16>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<const uint8>::mc_Value	));

DMibStaticCheck((	TCIsSigned<const fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp512>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp256>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp128>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp80>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp64>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp32>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp16>::mc_Value	));
DMibStaticCheck((	TCIsSigned<const fp8>::mc_Value	));







DMibStaticCheck((	!TCIsSigned<CTestUnion>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestStruct0>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestStruct1>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<ETestEnum>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestClass>::mc_Value				));
DMibStaticCheck((	!TCIsSigned<CTestC>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestPtr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestRef>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestCRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestCRRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<PFFunc0>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<PFFunc1>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<PFFunc2>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc0Ref>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc1Ref>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc2Ref>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc0RRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc1RRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc2RRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<PFFunc0El>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<PFFunc1El>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<PFFunc2El>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc0ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc1ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc2ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc0ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc1ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc2ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<FFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CMPtr>::mc_Value				));
DMibStaticCheck((	!TCIsSigned<CMCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CMPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CMCPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<CTestArray2>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestArray2C>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestArray>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTestArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTest2DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<CTest2DArray>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTest3DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsSigned<CTest3DArray>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsSigned<void *>::mc_Value			));
DMibStaticCheck((	!TCIsSigned<void>::mc_Value				));

// Types
DMibStaticCheck((	TCIsSame<TCSigned<int8192>::CType, int8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int4096>::CType, int4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int2048>::CType, int2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int1024>::CType, int1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int512>::CType, int512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int256>::CType, int256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int160>::CType, int160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int128>::CType, int128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int80>::CType, int80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int64>::CType, int64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int32>::CType, int32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int16>::CType, int16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<int8>::CType, int8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSigned<aint>::CType, aint>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uaint>::CType, aint>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<smint>::CType, smint>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<mint>::CType, smint>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSigned<uint8192>::CType, int8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint4096>::CType, int4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint2048>::CType, int2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint1024>::CType, int1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint512>::CType, int512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint256>::CType, int256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint160>::CType, int160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint128>::CType, int128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint80>::CType, int80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint64>::CType, int64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint32>::CType, int32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint16>::CType, int16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<uint8>::CType, int8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSigned<fp4096>::CType, fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp2048>::CType, fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp1024>::CType, fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp512>::CType, fp512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp256>::CType, fp256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp128>::CType, fp128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp80>::CType, fp80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp64>::CType, fp64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp32>::CType, fp32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp16>::CType, fp16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<fp8>::CType, fp8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSigned<const int8192>::CType, const int8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int4096>::CType, const int4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int2048>::CType, const int2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int1024>::CType, const int1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int512>::CType, const int512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int256>::CType, const int256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int160>::CType, const int160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int128>::CType, const int128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int80>::CType, const int80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int64>::CType, const int64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int32>::CType, const int32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int16>::CType, const int16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const int8>::CType, const int8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSigned<const uint8192>::CType, const int8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint4096>::CType, const int4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint2048>::CType, const int2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint1024>::CType, const int1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint512>::CType, const int512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint256>::CType, const int256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint160>::CType, const int160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint128>::CType, const int128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint80>::CType, const int80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint64>::CType, const int64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint32>::CType, const int32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint16>::CType, const int16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const uint8>::CType, const int8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSigned<const fp4096>::CType, const fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp2048>::CType, const fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp1024>::CType, const fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp512>::CType, const fp512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp256>::CType, const fp256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp128>::CType, const fp128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp80>::CType, const fp80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp64>::CType, const fp64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp32>::CType, const fp32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp16>::CType, const fp16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<const fp8>::CType, const fp8>::mc_Value	));


DMibStaticCheck((	TCIsSame<TCSigned<CTestUnion>::CType, CTestUnion>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTestClass0>::CType, CTestClass0>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTestClass1>::CType, CTestClass1>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTestStruct0>::CType, CTestStruct0>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTestStruct1>::CType, CTestStruct1>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<ETestEnum>::CType, ETestEnum>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<CTestClass>::CType, CTestClass>::mc_Value						));
DMibStaticCheck((	TCIsSame<TCSigned<CTestC>::CType, CTestC>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<CTestPtr>::CType, CTestPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<CTestCPtr>::CType, CTestCPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<CTestPtrC>::CType, CTestPtrC>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<CTestCPtrC>::CType, CTestCPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTestRef>::CType, CTestRef>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<CTestCRef>::CType, CTestCRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<CTestRRef>::CType, CTestRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<CTestCRRef>::CType, CTestCRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<PFFunc0>::CType, PFFunc0>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<PFFunc1>::CType, PFFunc1>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<PFFunc2>::CType, PFFunc2>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0Ref>::CType, FFunc0Ref>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1Ref>::CType, FFunc1Ref>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2Ref>::CType, FFunc2Ref>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0RRef>::CType, FFunc0RRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1RRef>::CType, FFunc1RRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2RRef>::CType, FFunc2RRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0Ptr>::CType, FFunc0Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1Ptr>::CType, FFunc1Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2Ptr>::CType, FFunc2Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0PtrC>::CType, FFunc0PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1PtrC>::CType, FFunc1PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2PtrC>::CType, FFunc2PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0Ptr>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1Ptr>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2Ptr>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0PtrC>::CType, FMFunc0PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1PtrC>::CType, FMFunc1PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2PtrC>::CType, FMFunc2PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0CPtr>::CType, FMFunc0CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1CPtr>::CType, FMFunc1CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2CPtr>::CType, FMFunc2CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0CPtrC>::CType, FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1CPtrC>::CType, FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2CPtrC>::CType, FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<PFFunc0El>::CType, PFFunc0El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<PFFunc1El>::CType, PFFunc1El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<PFFunc2El>::CType, PFFunc2El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0ElRef>::CType, FFunc0ElRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1ElRef>::CType, FFunc1ElRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2ElRef>::CType, FFunc2ElRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0ElRRef>::CType, FFunc0ElRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1ElRRef>::CType, FFunc1ElRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2ElRRef>::CType, FFunc2ElRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0ElPtr>::CType, FFunc0ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1ElPtr>::CType, FFunc1ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2ElPtr>::CType, FFunc2ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc0ElPtrC>::CType, FFunc0ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc1ElPtrC>::CType, FFunc1ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FFunc2ElPtrC>::CType, FFunc2ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0ElPtr>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1ElPtr>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2ElPtr>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0ElPtrC>::CType, FMFunc0ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1ElPtrC>::CType, FMFunc1ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2ElPtrC>::CType, FMFunc2ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0ElCPtr>::CType, FMFunc0ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1ElCPtr>::CType, FMFunc1ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2ElCPtr>::CType, FMFunc2ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc0ElCPtrC>::CType, FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc1ElCPtrC>::CType, FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<FMFunc2ElCPtrC>::CType, FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CMPtr>::CType, CMPtr>::mc_Value						));
DMibStaticCheck((	TCIsSame<TCSigned<CMCPtr>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<CMPtrC>::CType, CMPtrC>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<CMCPtrC>::CType, CMCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<CTestArray2>::CType, CTestArray2>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTestArray2C>::CType, CTestArray2C>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTestArray>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTestArrayC>::CType, CTestArrayC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSigned<CTest2DArray2>::CType, CTest2DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTest2DArray2C>::CType, CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<CTest2DArray>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTest2DArrayC>::CType, CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTest3DArray2>::CType, CTest3DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTest3DArray2C>::CType, CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSigned<CTest3DArray>::CType, CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<CTest3DArrayC>::CType, CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSigned<void *>::CType, void *>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCSigned<void>::CType, void>::mc_Value						));

// Types
DMibStaticCheck((	TCIsSame<TCUnsigned<int8192>::CType, uint8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int4096>::CType, uint4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int2048>::CType, uint2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int1024>::CType, uint1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int512>::CType, uint512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int256>::CType, uint256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int160>::CType, uint160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int128>::CType, uint128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int80>::CType, uint80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int64>::CType, uint64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int32>::CType, uint32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int16>::CType, uint16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<int8>::CType, uint8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<aint>::CType, uaint>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uaint>::CType, uaint>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<smint>::CType, mint>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<mint>::CType, mint>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<uint4096>::CType, uint4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint2048>::CType, uint2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint1024>::CType, uint1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint512>::CType, uint512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint256>::CType, uint256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint160>::CType, uint160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint128>::CType, uint128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint80>::CType, uint80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint64>::CType, uint64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint32>::CType, uint32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint16>::CType, uint16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<uint8>::CType, uint8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<fp4096>::CType, fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp2048>::CType, fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp1024>::CType, fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp512>::CType, fp512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp256>::CType, fp256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp128>::CType, fp128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp80>::CType, fp80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp64>::CType, fp64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp32>::CType, fp32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp16>::CType, fp16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<fp8>::CType, fp8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<const int8192>::CType, const uint8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int4096>::CType, const uint4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int2048>::CType, const uint2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int1024>::CType, const uint1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int512>::CType, const uint512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int256>::CType, const uint256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int160>::CType, const uint160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int128>::CType, const uint128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int80>::CType, const uint80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int64>::CType, const uint64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int32>::CType, const uint32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int16>::CType, const uint16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const int8>::CType, const uint8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<const uint4096>::CType, const uint4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint2048>::CType, const uint2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint1024>::CType, const uint1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint512>::CType, const uint512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint256>::CType, const uint256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint160>::CType, const uint160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint128>::CType, const uint128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint80>::CType, const uint80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint64>::CType, const uint64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint32>::CType, const uint32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint16>::CType, const uint16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const uint8>::CType, const uint8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<const fp4096>::CType, const fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp2048>::CType, const fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp1024>::CType, const fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp512>::CType, const fp512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp256>::CType, const fp256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp128>::CType, const fp128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp80>::CType, const fp80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp64>::CType, const fp64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp32>::CType, const fp32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp16>::CType, const fp16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<const fp8>::CType, const fp8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCUnsigned<CTestUnion>::CType, CTestUnion>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestClass0>::CType, CTestClass0>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestClass1>::CType, CTestClass1>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestStruct0>::CType, CTestStruct0>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestStruct1>::CType, CTestStruct1>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<ETestEnum>::CType, ETestEnum>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestClass>::CType, CTestClass>::mc_Value						));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestC>::CType, CTestC>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestPtr>::CType, CTestPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestCPtr>::CType, CTestCPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestPtrC>::CType, CTestPtrC>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestCPtrC>::CType, CTestCPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestRef>::CType, CTestRef>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestCRef>::CType, CTestCRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestRRef>::CType, CTestRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestCRRef>::CType, CTestCRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<PFFunc0>::CType, PFFunc0>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<PFFunc1>::CType, PFFunc1>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<PFFunc2>::CType, PFFunc2>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0Ref>::CType, FFunc0Ref>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1Ref>::CType, FFunc1Ref>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2Ref>::CType, FFunc2Ref>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0RRef>::CType, FFunc0RRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1RRef>::CType, FFunc1RRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2RRef>::CType, FFunc2RRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0Ptr>::CType, FFunc0Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1Ptr>::CType, FFunc1Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2Ptr>::CType, FFunc2Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0PtrC>::CType, FFunc0PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1PtrC>::CType, FFunc1PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2PtrC>::CType, FFunc2PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0Ptr>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1Ptr>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2Ptr>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0PtrC>::CType, FMFunc0PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1PtrC>::CType, FMFunc1PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2PtrC>::CType, FMFunc2PtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0CPtr>::CType, FMFunc0CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1CPtr>::CType, FMFunc1CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2CPtr>::CType, FMFunc2CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0CPtrC>::CType, FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1CPtrC>::CType, FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2CPtrC>::CType, FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<PFFunc0El>::CType, PFFunc0El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<PFFunc1El>::CType, PFFunc1El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<PFFunc2El>::CType, PFFunc2El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0ElRef>::CType, FFunc0ElRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1ElRef>::CType, FFunc1ElRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2ElRef>::CType, FFunc2ElRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0ElRRef>::CType, FFunc0ElRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1ElRRef>::CType, FFunc1ElRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2ElRRef>::CType, FFunc2ElRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0ElPtr>::CType, FFunc0ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1ElPtr>::CType, FFunc1ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2ElPtr>::CType, FFunc2ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc0ElPtrC>::CType, FFunc0ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc1ElPtrC>::CType, FFunc1ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FFunc2ElPtrC>::CType, FFunc2ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0ElPtr>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1ElPtr>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2ElPtr>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0ElPtrC>::CType, FMFunc0ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1ElPtrC>::CType, FMFunc1ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2ElPtrC>::CType, FMFunc2ElPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0ElCPtr>::CType, FMFunc0ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1ElCPtr>::CType, FMFunc1ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2ElCPtr>::CType, FMFunc2ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc0ElCPtrC>::CType, FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc1ElCPtrC>::CType, FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<FMFunc2ElCPtrC>::CType, FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CMPtr>::CType, CMPtr>::mc_Value						));
DMibStaticCheck((	TCIsSame<TCUnsigned<CMCPtr>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<CMPtrC>::CType, CMPtrC>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<CMCPtrC>::CType, CMCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestArray2>::CType, CTestArray2>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestArray2C>::CType, CTestArray2C>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestArray>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTestArrayC>::CType, CTestArrayC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest2DArray2>::CType, CTest2DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest2DArray2C>::CType, CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest2DArray>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest2DArrayC>::CType, CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest3DArray2>::CType, CTest3DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest3DArray2C>::CType, CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest3DArray>::CType, CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<CTest3DArrayC>::CType, CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCUnsigned<void *>::CType, void *>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCUnsigned<void>::CType, void>::mc_Value						));


// From size
DMibStaticCheck((	TCIsSame<TCIntFromSize<8192/8>::CType, int8192>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<4096/8>::CType, int4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<2048/8>::CType, int2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<1024/8>::CType, int1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<512/8>::CType, int512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<256/8>::CType, int256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<160/8>::CType, int160>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<128/8>::CType, int128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<64/8>::CType, int64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<80/8>::CType, int80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<32/8>::CType, int32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<16/8>::CType, int16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCIntFromSize<8/8>::CType, int8>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCFloatFromSize<4096/8>::CType, fp4096>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<2048/8>::CType, fp2048>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<1024/8>::CType, fp1024>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<512/8>::CType, fp512>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<256/8>::CType, fp256>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<128/8>::CType, fp128>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<80/8>::CType, fp80>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<64/8>::CType, fp64>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<32/8>::CType, fp32>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<16/8>::CType, fp16>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCFloatFromSize<8/8>::CType, fp8>::mc_Value	));

