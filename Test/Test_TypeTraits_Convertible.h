// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NConvertible
{
	static_assert(cIsConvertible<int, float>);

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

	static_assert(cIsConvertible<CTestConvert, int>);
	static_assert(cIsConvertible<int, CTestConvert>);
	static_assert(!cIsConvertible<CTestConvert, char *>);
	static_assert(!cIsConvertible<char *, CTestConvert>);
	static_assert(cIsConvertible<CTestConvert, float>);
	static_assert(!cIsConvertible<CTestConvert, char *>);

	static_assert(!cIsConvertible<CTestConvert2, int>);
	static_assert(!cIsConvertible<int, CTestConvert2>);
	static_assert(!cIsConvertible<CTestConvert2, char *>);
	static_assert(!cIsConvertible<char *, CTestConvert2>);

	static_assert(cIsConvertible<CTestInherit, CTestClass>);
	static_assert(cIsConvertible<CTestInherit &&, CTestClass &&>);
}

// Void
static_assert(!cIsConvertible<CTestUnion, int>);
static_assert(!cIsConvertible<CTestClass0, int>);
static_assert(!cIsConvertible<CTestClass1, int>);
static_assert(!cIsConvertible<CTestStruct0, int>);
static_assert(!cIsConvertible<CTestStruct1, int>);
static_assert(!cIsConvertible<const CTestClass0, int>);
static_assert(!cIsConvertible<const CTestClass1, int>);
static_assert(!cIsConvertible<const CTestStruct0, int>);
static_assert(!cIsConvertible<const CTestStruct1, int>);
static_assert(cIsConvertible<ETestEnum, int>);
static_assert(cIsConvertible<int, int>);
static_assert(!cIsConvertible<CTestClass, int>);
static_assert(!cIsConvertible<CTestC, int>);
static_assert(!cIsConvertible<CTestPtr, int>);
static_assert(!cIsConvertible<CTestCPtr, int>);
static_assert(!cIsConvertible<CTestPtrC, int>);
static_assert(!cIsConvertible<CTestCPtrC, int>);
static_assert(!cIsConvertible<CTestRef, int>);
static_assert(!cIsConvertible<CTestCRef, int>);
static_assert(!cIsConvertible<CTestRRef, int>);
static_assert(!cIsConvertible<CTestCRRef, int>);
static_assert(!cIsConvertible<PFFunc0, int>);
static_assert(!cIsConvertible<PFFunc1, int>);
static_assert(!cIsConvertible<PFFunc2, int>);
static_assert(!cIsConvertible<FFunc0Ref, int>);
static_assert(!cIsConvertible<FFunc1Ref, int>);
static_assert(!cIsConvertible<FFunc2Ref, int>);
static_assert(!cIsConvertible<FFunc0RRef, int>);
static_assert(!cIsConvertible<FFunc1RRef, int>);
static_assert(!cIsConvertible<FFunc2RRef, int>);
static_assert(!cIsConvertible<FFunc0Ptr, int>);
static_assert(!cIsConvertible<FFunc1Ptr, int>);
static_assert(!cIsConvertible<FFunc2Ptr, int>);
static_assert(!cIsConvertible<FFunc0PtrC, int>);
static_assert(!cIsConvertible<FFunc1PtrC, int>);
static_assert(!cIsConvertible<FFunc2PtrC, int>);
static_assert(!cIsConvertible<FMFunc0Ptr, int>);
static_assert(!cIsConvertible<FMFunc1Ptr, int>);
static_assert(!cIsConvertible<FMFunc2Ptr, int>);
static_assert(!cIsConvertible<FMFunc0PtrC, int>);
static_assert(!cIsConvertible<FMFunc1PtrC, int>);
static_assert(!cIsConvertible<FMFunc2PtrC, int>);
static_assert(!cIsConvertible<FMFunc0CPtr, int>);
static_assert(!cIsConvertible<FMFunc1CPtr, int>);
static_assert(!cIsConvertible<FMFunc2CPtr, int>);
static_assert(!cIsConvertible<FMFunc0CPtrC, int>);
static_assert(!cIsConvertible<FMFunc1CPtrC, int>);
static_assert(!cIsConvertible<FMFunc2CPtrC, int>);
static_assert(!cIsConvertible<PFFunc0El, int>);
static_assert(!cIsConvertible<PFFunc1El, int>);
static_assert(!cIsConvertible<PFFunc2El, int>);
static_assert(!cIsConvertible<FFunc0ElRef, int>);
static_assert(!cIsConvertible<FFunc1ElRef, int>);
static_assert(!cIsConvertible<FFunc2ElRef, int>);
static_assert(!cIsConvertible<FFunc0ElRRef, int>);
static_assert(!cIsConvertible<FFunc1ElRRef, int>);
static_assert(!cIsConvertible<FFunc2ElRRef, int>);
static_assert(!cIsConvertible<FFunc0ElPtr, int>);
static_assert(!cIsConvertible<FFunc1ElPtr, int>);
static_assert(!cIsConvertible<FFunc2ElPtr, int>);
static_assert(!cIsConvertible<FFunc0ElPtrC, int>);
static_assert(!cIsConvertible<FFunc1ElPtrC, int>);
static_assert(!cIsConvertible<FFunc2ElPtrC, int>);
static_assert(!cIsConvertible<FMFunc0ElPtr, int>);
static_assert(!cIsConvertible<FMFunc1ElPtr, int>);
static_assert(!cIsConvertible<FMFunc2ElPtr, int>);
static_assert(!cIsConvertible<FMFunc0ElPtrC, int>);
static_assert(!cIsConvertible<FMFunc1ElPtrC, int>);
static_assert(!cIsConvertible<FMFunc2ElPtrC, int>);
static_assert(!cIsConvertible<FMFunc0ElCPtr, int>);
static_assert(!cIsConvertible<FMFunc1ElCPtr, int>);
static_assert(!cIsConvertible<FMFunc2ElCPtr, int>);
static_assert(!cIsConvertible<FMFunc0ElCPtrC, int>);
static_assert(!cIsConvertible<FMFunc1ElCPtrC, int>);
static_assert(!cIsConvertible<FMFunc2ElCPtrC, int>);
static_assert(!cIsConvertible<CMPtr, int>);
static_assert(!cIsConvertible<CMCPtr, int>);
static_assert(!cIsConvertible<CMPtrC, int>);
static_assert(!cIsConvertible<CMCPtrC, int>);
static_assert(!cIsConvertible<CTestArray2, int>);
static_assert(!cIsConvertible<CTestArray2C, int>);
static_assert(!cIsConvertible<CTestArray, int>);
static_assert(!cIsConvertible<CTestArrayC, int>);
static_assert(!cIsConvertible<CTest2DArray2, int>);
static_assert(!cIsConvertible<CTest2DArray2C, int>);
static_assert(!cIsConvertible<CTest2DArray, int>);
static_assert(!cIsConvertible<CTest2DArrayC, int>);
static_assert(!cIsConvertible<CTest3DArray2, int>);
static_assert(!cIsConvertible<CTest3DArray2C, int>);
static_assert(!cIsConvertible<CTest3DArray, int>);
static_assert(!cIsConvertible<CTest3DArrayC, int>);
static_assert(!cIsConvertible<void *, int>);
static_assert(!cIsConvertible<void, int>);


static_assert(cIsConvertible<CTestUnion, CTestUnion>);
static_assert(cIsConvertible<CTestClass0, CTestClass0>);
static_assert(cIsConvertible<CTestClass1, CTestClass1>);
static_assert(cIsConvertible<CTestStruct0, CTestStruct0>);
static_assert(cIsConvertible<CTestStruct1, CTestStruct1>);
static_assert(cIsConvertible<const CTestClass0, const CTestClass0>);
static_assert(cIsConvertible<const CTestClass1, const CTestClass1>);
static_assert(cIsConvertible<const CTestStruct0, const CTestStruct0>);
static_assert(cIsConvertible<const CTestStruct1, const CTestStruct1>);
static_assert(cIsConvertible<ETestEnum, ETestEnum>);
static_assert(cIsConvertible<int, int>);
static_assert(cIsConvertible<CTestClass, CTestClass>);
static_assert(cIsConvertible<CTestC, CTestC>);
static_assert(cIsConvertible<CTestPtr, CTestPtr>);
static_assert(cIsConvertible<CTestCPtr, CTestCPtr>);
static_assert(cIsConvertible<CTestPtrC, CTestPtrC>);
static_assert(cIsConvertible<CTestCPtrC, CTestCPtrC>);
static_assert(cIsConvertible<CTestRef, CTestRef>);
static_assert(cIsConvertible<CTestCRef, CTestCRef>);
static_assert(cIsConvertible<CTestRRef, CTestRRef>);
static_assert(cIsConvertible<CTestCRRef, CTestCRRef>);
static_assert(!cIsConvertible<PFFunc0, PFFunc0>);
static_assert(!cIsConvertible<PFFunc1, PFFunc1>);
static_assert(!cIsConvertible<PFFunc2, PFFunc2>);
static_assert(cIsConvertible<FFunc0Ref, FFunc0Ref>);
static_assert(cIsConvertible<FFunc1Ref, FFunc1Ref>);
static_assert(cIsConvertible<FFunc2Ref, FFunc2Ref>);
static_assert(cIsConvertible<FFunc0Ref, FFunc0RRef>);
static_assert(cIsConvertible<FFunc1Ref, FFunc1RRef>);
static_assert(cIsConvertible<FFunc2Ref, FFunc2RRef>);
static_assert(cIsConvertible<FFunc0Ref, FFunc0Ptr>);
static_assert(cIsConvertible<FFunc1Ref, FFunc1Ptr>);
static_assert(cIsConvertible<FFunc2Ref, FFunc2Ptr>);
static_assert(cIsConvertible<FFunc0RRef, FFunc0RRef>);
static_assert(cIsConvertible<FFunc1RRef, FFunc1RRef>);
static_assert(cIsConvertible<FFunc2RRef, FFunc2RRef>);
static_assert(cIsConvertible<FFunc0RRef, FFunc0Ref>);
static_assert(cIsConvertible<FFunc1RRef, FFunc1Ref>);
static_assert(cIsConvertible<FFunc2RRef, FFunc2Ref>);
static_assert(cIsConvertible<FFunc0RRef, FFunc0Ptr>);
static_assert(cIsConvertible<FFunc1RRef, FFunc1Ptr>);
static_assert(cIsConvertible<FFunc2RRef, FFunc2Ptr>);
static_assert(!cIsConvertible<FFunc0Ptr, FFunc0Ref>);
static_assert(!cIsConvertible<FFunc1Ptr, FFunc1Ref>);
static_assert(!cIsConvertible<FFunc2Ptr, FFunc2Ref>);
static_assert(!cIsConvertible<FFunc0Ptr, FFunc0RRef>);
static_assert(!cIsConvertible<FFunc1Ptr, FFunc1RRef>);
static_assert(!cIsConvertible<FFunc2Ptr, FFunc2RRef>);
static_assert(cIsConvertible<FFunc0PtrC, FFunc0PtrC>);
static_assert(cIsConvertible<FFunc1PtrC, FFunc1PtrC>);
static_assert(cIsConvertible<FFunc2PtrC, FFunc2PtrC>);
static_assert(cIsConvertible<FMFunc0Ptr, FMFunc0Ptr>);
static_assert(cIsConvertible<FMFunc1Ptr, FMFunc1Ptr>);
static_assert(cIsConvertible<FMFunc2Ptr, FMFunc2Ptr>);
static_assert(cIsConvertible<FMFunc0PtrC, FMFunc0PtrC>);
static_assert(cIsConvertible<FMFunc1PtrC, FMFunc1PtrC>);
static_assert(cIsConvertible<FMFunc2PtrC, FMFunc2PtrC>);
static_assert(cIsConvertible<FMFunc0CPtr, FMFunc0CPtr>);
static_assert(cIsConvertible<FMFunc1CPtr, FMFunc1CPtr>);
static_assert(cIsConvertible<FMFunc2CPtr, FMFunc2CPtr>);
static_assert(cIsConvertible<FMFunc0CPtrC, FMFunc0CPtrC>);
static_assert(cIsConvertible<FMFunc1CPtrC, FMFunc1CPtrC>);
static_assert(cIsConvertible<FMFunc2CPtrC, FMFunc2CPtrC>);
static_assert(!cIsConvertible<PFFunc0El, PFFunc0El>);
static_assert(!cIsConvertible<PFFunc1El, PFFunc1El>);
static_assert(!cIsConvertible<PFFunc2El, PFFunc2El>);
static_assert(cIsConvertible<FFunc0ElRef, FFunc0ElRef>);
static_assert(cIsConvertible<FFunc1ElRef, FFunc1ElRef>);
static_assert(cIsConvertible<FFunc2ElRef, FFunc2ElRef>);
static_assert(cIsConvertible<FFunc0ElRRef, FFunc0ElRRef>);
static_assert(cIsConvertible<FFunc1ElRRef, FFunc1ElRRef>);
static_assert(cIsConvertible<FFunc2ElRRef, FFunc2ElRRef>);
static_assert(cIsConvertible<FFunc0ElPtr, FFunc0ElPtr>);
static_assert(cIsConvertible<FFunc1ElPtr, FFunc1ElPtr>);
static_assert(cIsConvertible<FFunc2ElPtr, FFunc2ElPtr>);
static_assert(cIsConvertible<FFunc0ElPtrC, FFunc0ElPtrC>);
static_assert(cIsConvertible<FFunc1ElPtrC, FFunc1ElPtrC>);
static_assert(cIsConvertible<FFunc2ElPtrC, FFunc2ElPtrC>);
static_assert(cIsConvertible<FMFunc0ElPtr, FMFunc0ElPtr>);
static_assert(cIsConvertible<FMFunc1ElPtr, FMFunc1ElPtr>);
static_assert(cIsConvertible<FMFunc2ElPtr, FMFunc2ElPtr>);
static_assert(cIsConvertible<FMFunc0ElPtrC, FMFunc0ElPtrC>);
static_assert(cIsConvertible<FMFunc1ElPtrC, FMFunc1ElPtrC>);
static_assert(cIsConvertible<FMFunc2ElPtrC, FMFunc2ElPtrC>);
static_assert(cIsConvertible<FMFunc0ElCPtr, FMFunc0ElCPtr>);
static_assert(cIsConvertible<FMFunc1ElCPtr, FMFunc1ElCPtr>);
static_assert(cIsConvertible<FMFunc2ElCPtr, FMFunc2ElCPtr>);
static_assert(cIsConvertible<FMFunc0ElCPtrC, FMFunc0ElCPtrC>);
static_assert(cIsConvertible<FMFunc1ElCPtrC, FMFunc1ElCPtrC>);
static_assert(cIsConvertible<FMFunc2ElCPtrC, FMFunc2ElCPtrC>);
static_assert(cIsConvertible<CMPtr, CMPtr>);
static_assert(cIsConvertible<CMCPtr, CMCPtr>);
static_assert(cIsConvertible<CMPtrC, CMPtrC>);
static_assert(cIsConvertible<CMCPtrC, CMCPtrC>);

static_assert(cIsConvertible<CTestArray2, TCDecay<CTestArray2>>);
static_assert(cIsConvertible<CTestArray2C, TCDecay<CTestArray2C>>);
static_assert(cIsConvertible<CTestArray, TCDecay<CTestArray>>);
static_assert(cIsConvertible<CTestArrayC, TCDecay<CTestArrayC>>);
static_assert(cIsConvertible<CTest2DArray2, TCDecay<CTest2DArray2>>);
static_assert(cIsConvertible<CTest2DArray2C, TCDecay<CTest2DArray2C>>);
static_assert(cIsConvertible<CTest2DArray, TCDecay<CTest2DArray>>);
static_assert(cIsConvertible<CTest2DArrayC, TCDecay<CTest2DArrayC>>);
static_assert(cIsConvertible<CTest3DArray2, TCDecay<CTest3DArray2>>);
static_assert(cIsConvertible<CTest3DArray2C, TCDecay<CTest3DArray2C>>);
static_assert(cIsConvertible<CTest3DArray, TCDecay<CTest3DArray>>);
static_assert(cIsConvertible<CTest3DArrayC, TCDecay<CTest3DArrayC>>);


static_assert(!cIsConvertible<CTestArray2, CTestArray2>);
static_assert(!cIsConvertible<CTestArray2C, CTestArray2C>);
static_assert(!cIsConvertible<CTestArray, CTestArray>);
static_assert(!cIsConvertible<CTestArrayC, CTestArrayC>);
static_assert(!cIsConvertible<CTest2DArray2, CTest2DArray2>);
static_assert(!cIsConvertible<CTest2DArray2C, CTest2DArray2C>);
static_assert(!cIsConvertible<CTest2DArray, CTest2DArray>);
static_assert(!cIsConvertible<CTest2DArrayC, CTest2DArrayC>);
static_assert(!cIsConvertible<CTest3DArray2, CTest3DArray2>);
static_assert(!cIsConvertible<CTest3DArray2C, CTest3DArray2C>);
static_assert(!cIsConvertible<CTest3DArray, CTest3DArray>);
static_assert(!cIsConvertible<CTest3DArrayC, CTest3DArrayC>);

static_assert(cIsConvertible<void *, void *>);
static_assert(cIsConvertible<void, void>);

