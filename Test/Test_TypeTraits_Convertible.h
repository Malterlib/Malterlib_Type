// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"


namespace NConvertible
{

	DMibStaticCheck((	TCIsConvertible<int, float>::mc_Value					));

	class CTestConvert
	{
	public:
		CTestConvert(int);
		operator int ();
	};

	class CTestConvert2
	{
	public:
		operator CTestConvert ();
	};
	class CTestInherit : public CTestClass
	{
	public:
		int m_Test;
	};
	
	DMibStaticCheck((	TCIsConvertible<CTestConvert, int>::mc_Value					));
	DMibStaticCheck((	TCIsConvertible<int, CTestConvert>::mc_Value					));
	DMibStaticCheck((	!TCIsConvertible<CTestConvert, char *>::mc_Value					));
	DMibStaticCheck((	!TCIsConvertible<char *, CTestConvert>::mc_Value					));
	DMibStaticCheck((	TCIsConvertible<CTestConvert, float>::mc_Value					));
	DMibStaticCheck((	!TCIsConvertible<CTestConvert, char *>::mc_Value					));

	DMibStaticCheck((	!TCIsConvertible<CTestConvert2, int>::mc_Value					));
	DMibStaticCheck((	!TCIsConvertible<int, CTestConvert2>::mc_Value					));
	DMibStaticCheck((	!TCIsConvertible<CTestConvert2, char *>::mc_Value					));
	DMibStaticCheck((	!TCIsConvertible<char *, CTestConvert2>::mc_Value					));

	DMibStaticCheck((	TCIsConvertible<CTestInherit, CTestClass>::mc_Value					));
	DMibStaticCheck((	TCIsConvertible<CTestInherit &&, CTestClass &&>::mc_Value					));
}

// Void
DMibStaticCheck((	!TCIsConvertible<CTestUnion, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestClass0, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestClass1, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestStruct0, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestStruct1, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<const CTestClass0, int>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<const CTestClass1, int>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<const CTestStruct0, int>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<const CTestStruct1, int>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<ETestEnum, int>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<int, int>::mc_Value							));
DMibStaticCheck((	!TCIsConvertible<CTestClass, int>::mc_Value							));
DMibStaticCheck((	!TCIsConvertible<CTestC, int>::mc_Value							));
DMibStaticCheck((	!TCIsConvertible<CTestPtr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestCPtr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestPtrC, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestCPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestCRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestRRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestCRRef, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<PFFunc0, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc1, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc2, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0Ref, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1Ref, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2Ref, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0RRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1RRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2RRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0Ptr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1Ptr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2Ptr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0PtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FFunc1PtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FFunc2PtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0Ptr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1Ptr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2Ptr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0PtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1PtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2PtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0CPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1CPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2CPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0CPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1CPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2CPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<PFFunc0El, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc1El, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc2El, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0ElRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1ElRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2ElRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0ElRRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1ElRRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2ElRRef, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0ElPtr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1ElPtr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2ElPtr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0ElPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FFunc1ElPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FFunc2ElPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0ElPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1ElPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2ElPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0ElPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1ElPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2ElPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0ElCPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1ElCPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2ElCPtr, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc0ElCPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc1ElCPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<FMFunc2ElCPtrC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CMPtr, int>::mc_Value							));
DMibStaticCheck((	!TCIsConvertible<CMCPtr, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CMPtrC, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CMCPtrC, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<CTestArray2, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestArray2C, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestArray, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestArrayC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest2DArray2, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest2DArray2C, int>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<CTest2DArray, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest2DArrayC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest3DArray2, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest3DArray2C, int>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<CTest3DArray, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest3DArrayC, int>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<void *, int>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<void, int>::mc_Value							));


DMibStaticCheck((	TCIsConvertible<CTestUnion, CTestUnion>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestClass0, CTestClass0>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestClass1, CTestClass1>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestStruct0, CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestStruct1, CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<const CTestClass0, const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<const CTestClass1, const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<const CTestStruct0, const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<const CTestStruct1, const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<ETestEnum, ETestEnum>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<int, int>::mc_Value							));
DMibStaticCheck((	TCIsConvertible<CTestClass, CTestClass>::mc_Value							));
DMibStaticCheck((	TCIsConvertible<CTestC, CTestC>::mc_Value							));
DMibStaticCheck((	TCIsConvertible<CTestPtr, CTestPtr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CTestCPtr, CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CTestPtrC, CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CTestCPtrC, CTestCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestRef, CTestRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CTestCRef, CTestCRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CTestRRef, CTestRRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CTestCRRef, CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<PFFunc0, PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc1, PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc2, PFFunc2>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0Ref, FFunc0Ref>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1Ref, FFunc1Ref>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2Ref, FFunc2Ref>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0Ref, FFunc0RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1Ref, FFunc1RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2Ref, FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0Ref, FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1Ref, FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2Ref, FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0RRef, FFunc0RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1RRef, FFunc1RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2RRef, FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0RRef, FFunc0Ref>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1RRef, FFunc1Ref>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2RRef, FFunc2Ref>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0RRef, FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1RRef, FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2RRef, FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0Ptr, FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1Ptr, FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2Ptr, FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc0Ptr, FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc1Ptr, FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<FFunc2Ptr, FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0PtrC, FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FFunc1PtrC, FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FFunc2PtrC, FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0Ptr, FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1Ptr, FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2Ptr, FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0PtrC, FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1PtrC, FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2PtrC, FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0CPtr, FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1CPtr, FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2CPtr, FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0CPtrC, FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1CPtrC, FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2CPtrC, FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<PFFunc0El, PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc1El, PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsConvertible<PFFunc2El, PFFunc2El>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0ElRef, FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1ElRef, FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2ElRef, FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0ElRRef, FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1ElRRef, FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2ElRRef, FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0ElPtr, FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc1ElPtr, FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc2ElPtr, FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<FFunc0ElPtrC, FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FFunc1ElPtrC, FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FFunc2ElPtrC, FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0ElPtr, FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1ElPtr, FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2ElPtr, FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0ElPtrC, FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1ElPtrC, FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2ElPtrC, FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0ElCPtr, FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1ElCPtr, FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2ElCPtr, FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc0ElCPtrC, FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc1ElCPtrC, FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<FMFunc2ElCPtrC, FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CMPtr, CMPtr>::mc_Value							));
DMibStaticCheck((	TCIsConvertible<CMCPtr, CMCPtr>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CMPtrC, CMPtrC>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<CMCPtrC, CMCPtrC>::mc_Value						));

DMibStaticCheck((	TCIsConvertible<CTestArray2, TCDecay<CTestArray2>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestArray2C, TCDecay<CTestArray2C>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestArray, TCDecay<CTestArray>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTestArrayC, TCDecay<CTestArrayC>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTest2DArray2, TCDecay<CTest2DArray2>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTest2DArray2C, TCDecay<CTest2DArray2C>::CType>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<CTest2DArray, TCDecay<CTest2DArray>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTest2DArrayC, TCDecay<CTest2DArrayC>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTest3DArray2, TCDecay<CTest3DArray2>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTest3DArray2C, TCDecay<CTest3DArray2C>::CType>::mc_Value				));
DMibStaticCheck((	TCIsConvertible<CTest3DArray, TCDecay<CTest3DArray>::CType>::mc_Value					));
DMibStaticCheck((	TCIsConvertible<CTest3DArrayC, TCDecay<CTest3DArrayC>::CType>::mc_Value					));


DMibStaticCheck((	!TCIsConvertible<CTestArray2, CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestArray2C, CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestArray, CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTestArrayC, CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest2DArray2, CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest2DArray2C, CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<CTest2DArray, CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest2DArrayC, CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest3DArray2, CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest3DArray2C, CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsConvertible<CTest3DArray, CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsConvertible<CTest3DArrayC, CTest3DArrayC>::mc_Value					));

DMibStaticCheck((	TCIsConvertible<void *, void *>::mc_Value						));
DMibStaticCheck((	TCIsConvertible<void, void>::mc_Value							));

