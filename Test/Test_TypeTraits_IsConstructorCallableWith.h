// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#ifdef DMibCompiler_GCC
#pragma GCC system_header
#endif

class CTestInherit : public CTestClass
{
public:
	int m_Test;
};

void blaha()
{
	class CTestInherit : public CTestClass
	{
	public:
	int m_Test;
	};

	CTestInherit Test3;
	//CTestClass &Test2 = NMib::fg_Move(Test3);
	[[maybe_unused]] CTestClass &Test4 = Test3;
	[[maybe_unused]] CTestClass &&Test5 = NMib::fg_Move(Test3);
}

#include <type_traits>

static_assert(!cIsConstructibleWith<CTestArrayNoDefault>);
static_assert(!cIsConstructibleWith<CTestClass *, CTestClass const *>);
static_assert(cIsConstructibleWith<CTestClass *, CTestClass *>);
static_assert(cIsConstructibleWith<CTestClass &, CTestClass &>);
static_assert(cIsConstructibleWith<CTestClass &&, CTestClass &&>);
static_assert(!cIsConstructibleWith<CTestInherit &&, CTestClass &&>);
static_assert(cIsConstructibleWith<CTestClass &&, CTestInherit &&>);
#ifndef DCompiler_MSVC
	static_assert(!cIsConstructibleWith<CTestClass &, CTestClass &&>);
#endif
static_assert(!cIsConstructibleWith<CTestClass &&, CTestClass &>);
static_assert(cIsConstructibleWith<CTestClass &&, CTestClass>);
#ifndef DCompiler_MSVC
	static_assert(!cIsConstructibleWith<CTestClass &, CTestClass>);
#endif
static_assert(cIsConstructibleWith<CTestBase, CTestBase&&>);
static_assert(!cIsConstructibleWith<CTestNoDefaultConstruct>);
static_assert(cIsConstructibleWith<CTestBase, int &>);
static_assert(cIsConstructibleWith<CTestNoDefaultConstruct, int &&>);


static_assert(cIsConstructibleWith<CTestUnion>);
static_assert(cIsConstructibleWith<CTestClass0>);
static_assert(cIsConstructibleWith<CTestClass1>);
static_assert(cIsConstructibleWith<CTestStruct0>);
static_assert(cIsConstructibleWith<CTestStruct1>);
static_assert(cIsConstructibleWith<const CTestClass0>);
static_assert(cIsConstructibleWith<const CTestClass1>);
static_assert(cIsConstructibleWith<const CTestStruct0>);
static_assert(cIsConstructibleWith<const CTestStruct1>);
static_assert(cIsConstructibleWith<ETestEnum>);
static_assert(cIsConstructibleWith<int>);
static_assert(cIsConstructibleWith<CTestClass>);
static_assert(cIsConstructibleWith<CTestC>);
static_assert(cIsConstructibleWith<CTestPtr>);
static_assert(cIsConstructibleWith<CTestCPtr>);
static_assert(cIsConstructibleWith<CTestPtrC>);
static_assert(cIsConstructibleWith<CTestCPtrC>);
static_assert(!cIsConstructibleWith<CTestRef>);
static_assert(!cIsConstructibleWith<CTestCRef>);
static_assert(!cIsConstructibleWith<CTestRRef>);
static_assert(!cIsConstructibleWith<CTestCRRef>);
static_assert(!cIsConstructibleWith<PFFunc0>);
static_assert(!cIsConstructibleWith<PFFunc1>);
static_assert(!cIsConstructibleWith<PFFunc2>);
static_assert(!cIsConstructibleWith<FFunc0Ref>);
static_assert(!cIsConstructibleWith<FFunc1Ref>);
static_assert(!cIsConstructibleWith<FFunc2Ref>);
static_assert(!cIsConstructibleWith<FFunc0RRef>);
static_assert(!cIsConstructibleWith<FFunc1RRef>);
static_assert(!cIsConstructibleWith<FFunc2RRef>);
static_assert(cIsConstructibleWith<FFunc0Ptr>);
static_assert(cIsConstructibleWith<FFunc1Ptr>);
static_assert(cIsConstructibleWith<FFunc2Ptr>);
static_assert(cIsConstructibleWith<FFunc0PtrC>);
static_assert(cIsConstructibleWith<FFunc1PtrC>);
static_assert(cIsConstructibleWith<FFunc2PtrC>);
static_assert(cIsConstructibleWith<FMFunc0Ptr>);
static_assert(cIsConstructibleWith<FMFunc1Ptr>);
static_assert(cIsConstructibleWith<FMFunc2Ptr>);
static_assert(cIsConstructibleWith<FMFunc0PtrC>);
static_assert(cIsConstructibleWith<FMFunc1PtrC>);
static_assert(cIsConstructibleWith<FMFunc2PtrC>);
static_assert(cIsConstructibleWith<FMFunc0CPtr>);
static_assert(cIsConstructibleWith<FMFunc1CPtr>);
static_assert(cIsConstructibleWith<FMFunc2CPtr>);
static_assert(cIsConstructibleWith<FMFunc0CPtrC>);
static_assert(cIsConstructibleWith<FMFunc1CPtrC>);
static_assert(cIsConstructibleWith<FMFunc2CPtrC>);
static_assert(!cIsConstructibleWith<PFFunc0El>);
static_assert(!cIsConstructibleWith<PFFunc1El>);
static_assert(!cIsConstructibleWith<PFFunc2El>);
static_assert(!cIsConstructibleWith<FFunc0ElRef>);
static_assert(!cIsConstructibleWith<FFunc1ElRef>);
static_assert(!cIsConstructibleWith<FFunc2ElRef>);
static_assert(!cIsConstructibleWith<FFunc0ElRRef>);
static_assert(!cIsConstructibleWith<FFunc1ElRRef>);
static_assert(!cIsConstructibleWith<FFunc2ElRRef>);
static_assert(cIsConstructibleWith<FFunc0ElPtr>);
static_assert(cIsConstructibleWith<FFunc1ElPtr>);
static_assert(cIsConstructibleWith<FFunc2ElPtr>);
static_assert(cIsConstructibleWith<FFunc0ElPtrC>);
static_assert(cIsConstructibleWith<FFunc1ElPtrC>);
static_assert(cIsConstructibleWith<FFunc2ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc0ElPtr>);
static_assert(cIsConstructibleWith<FMFunc1ElPtr>);
static_assert(cIsConstructibleWith<FMFunc2ElPtr>);
static_assert(cIsConstructibleWith<FMFunc0ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc1ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc2ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc0ElCPtr>);
static_assert(cIsConstructibleWith<FMFunc1ElCPtr>);
static_assert(cIsConstructibleWith<FMFunc2ElCPtr>);
static_assert(cIsConstructibleWith<FMFunc0ElCPtrC>);
static_assert(cIsConstructibleWith<FMFunc1ElCPtrC>);
static_assert(cIsConstructibleWith<FMFunc2ElCPtrC>);
static_assert(cIsConstructibleWith<CMPtr>);
static_assert(cIsConstructibleWith<CMCPtr>);
static_assert(cIsConstructibleWith<CMPtrC>);
static_assert(cIsConstructibleWith<CMCPtrC>);
static_assert(cIsConstructibleWith<CTestArray2>);
static_assert(cIsConstructibleWith<CTestArray2C>);
static_assert(!cIsConstructibleWith<CTestArray>);
static_assert(!cIsConstructibleWith<CTestArrayC>);
static_assert(cIsConstructibleWith<CTest2DArray2>);
static_assert(cIsConstructibleWith<CTest2DArray2C>);
static_assert(!cIsConstructibleWith<CTest2DArray>);
static_assert(!cIsConstructibleWith<CTest2DArrayC>);
static_assert(cIsConstructibleWith<CTest3DArray2>);
static_assert(cIsConstructibleWith<CTest3DArray2C>);
static_assert(!cIsConstructibleWith<CTest3DArray>);
static_assert(!cIsConstructibleWith<CTest3DArrayC>);
static_assert(cIsConstructibleWith<void *>);
static_assert(!cIsConstructibleWith<void>);


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


static_assert(cIsConstructibleWith<CTestUnion, CTestUnion>);
static_assert(cIsConstructibleWith<CTestClass0, CTestClass0>);
static_assert(cIsConstructibleWith<CTestClass1, CTestClass1>);
static_assert(cIsConstructibleWith<CTestStruct0, CTestStruct0>);
static_assert(cIsConstructibleWith<CTestStruct1, CTestStruct1>);
static_assert(cIsConstructibleWith<const CTestClass0, CTestClass0>);
static_assert(cIsConstructibleWith<const CTestClass1, CTestClass1>);
static_assert(cIsConstructibleWith<const CTestStruct0, CTestStruct0>);
static_assert(cIsConstructibleWith<const CTestStruct1, CTestStruct1>);
static_assert(cIsConstructibleWith<ETestEnum, ETestEnum>);
static_assert(cIsConstructibleWith<int, int>);
static_assert(cIsConstructibleWith<CTestClass, CTestClass>);
static_assert(cIsConstructibleWith<CTestC, CTestC>);
static_assert(cIsConstructibleWith<CTestPtr, CTestPtr>);
static_assert(cIsConstructibleWith<CTestCPtr, CTestCPtr>);
static_assert(cIsConstructibleWith<CTestPtrC, CTestPtrC>);
static_assert(cIsConstructibleWith<CTestCPtrC, CTestCPtrC>);
static_assert(cIsConstructibleWith<CTestRef, CTestRef>);
static_assert(cIsConstructibleWith<CTestCRef, CTestCRef>);
static_assert(cIsConstructibleWith<CTestRRef, CTestRRef>);
static_assert(cIsConstructibleWith<CTestCRRef, CTestCRRef>);
static_assert(!cIsConstructibleWith<PFFunc0>);
static_assert(!cIsConstructibleWith<PFFunc1>);
static_assert(!cIsConstructibleWith<PFFunc2>);
static_assert(cIsConstructibleWith<FFunc0Ref, FFunc0Ref>);
static_assert(cIsConstructibleWith<FFunc1Ref, FFunc1Ref>);
static_assert(cIsConstructibleWith<FFunc2Ref, FFunc2Ref>);
static_assert(cIsConstructibleWith<FFunc0Ref, FFunc0RRef>);
static_assert(cIsConstructibleWith<FFunc1Ref, FFunc1RRef>);
static_assert(cIsConstructibleWith<FFunc2Ref, FFunc2RRef>);
static_assert(cIsConstructibleWith<FFunc0RRef, FFunc0RRef>);
static_assert(cIsConstructibleWith<FFunc1RRef, FFunc1RRef>);
static_assert(cIsConstructibleWith<FFunc2RRef, FFunc2RRef>);
static_assert(cIsConstructibleWith<FFunc0RRef, FFunc0Ref>);
static_assert(cIsConstructibleWith<FFunc1RRef, FFunc1Ref>);
static_assert(cIsConstructibleWith<FFunc2RRef, FFunc2Ref>);
static_assert(!cIsConstructibleWith<FFunc0Ref, FFunc0Ptr>);
static_assert(!cIsConstructibleWith<FFunc1Ref, FFunc1Ptr>);
static_assert(!cIsConstructibleWith<FFunc2Ref, FFunc2Ptr>);
static_assert(!cIsConstructibleWith<FFunc0RRef, FFunc0Ptr>);
static_assert(!cIsConstructibleWith<FFunc1RRef, FFunc1Ptr>);
static_assert(!cIsConstructibleWith<FFunc2RRef, FFunc2Ptr>);
static_assert(cIsConstructibleWith<FFunc0Ptr, FFunc0Ref>);
static_assert(cIsConstructibleWith<FFunc1Ptr, FFunc1Ref>);
static_assert(cIsConstructibleWith<FFunc2Ptr, FFunc2Ref>);
static_assert(cIsConstructibleWith<FFunc0Ptr, FFunc0RRef>);
static_assert(cIsConstructibleWith<FFunc1Ptr, FFunc1RRef>);
static_assert(cIsConstructibleWith<FFunc2Ptr, FFunc2RRef>);
static_assert(cIsConstructibleWith<FFunc0Ptr, FFunc0Ptr>);
static_assert(cIsConstructibleWith<FFunc1Ptr, FFunc1Ptr>);
static_assert(cIsConstructibleWith<FFunc2Ptr, FFunc2Ptr>);
static_assert(cIsConstructibleWith<FFunc0PtrC, FFunc0PtrC>);
static_assert(cIsConstructibleWith<FFunc1PtrC, FFunc1PtrC>);
static_assert(cIsConstructibleWith<FFunc2PtrC, FFunc2PtrC>);
static_assert(cIsConstructibleWith<FMFunc0Ptr, FMFunc0Ptr>);
static_assert(cIsConstructibleWith<FMFunc1Ptr, FMFunc1Ptr>);
static_assert(cIsConstructibleWith<FMFunc2Ptr, FMFunc2Ptr>);
static_assert(cIsConstructibleWith<FMFunc0PtrC, FMFunc0PtrC>);
static_assert(cIsConstructibleWith<FMFunc1PtrC, FMFunc1PtrC>);
static_assert(cIsConstructibleWith<FMFunc2PtrC, FMFunc2PtrC>);
static_assert(cIsConstructibleWith<FMFunc0CPtr, FMFunc0CPtr>);
static_assert(cIsConstructibleWith<FMFunc1CPtr, FMFunc1CPtr>);
static_assert(cIsConstructibleWith<FMFunc2CPtr, FMFunc2CPtr>);
static_assert(cIsConstructibleWith<FMFunc0CPtrC, FMFunc0CPtrC>);
static_assert(cIsConstructibleWith<FMFunc1CPtrC, FMFunc1CPtrC>);
static_assert(cIsConstructibleWith<FMFunc2CPtrC, FMFunc2CPtrC>);
static_assert(!cIsConstructibleWith<PFFunc0El>);
static_assert(!cIsConstructibleWith<PFFunc1El>);
static_assert(!cIsConstructibleWith<PFFunc2El>);
static_assert(cIsConstructibleWith<FFunc0ElRef, FFunc0ElRef>);
static_assert(cIsConstructibleWith<FFunc1ElRef, FFunc1ElRef>);
static_assert(cIsConstructibleWith<FFunc2ElRef, FFunc2ElRef>);
static_assert(cIsConstructibleWith<FFunc0ElRRef, FFunc0ElRRef>);
static_assert(cIsConstructibleWith<FFunc1ElRRef, FFunc1ElRRef>);
static_assert(cIsConstructibleWith<FFunc2ElRRef, FFunc2ElRRef>);
static_assert(cIsConstructibleWith<FFunc0ElPtr, FFunc0ElPtr>);
static_assert(cIsConstructibleWith<FFunc1ElPtr, FFunc1ElPtr>);
static_assert(cIsConstructibleWith<FFunc2ElPtr, FFunc2ElPtr>);
static_assert(cIsConstructibleWith<FFunc0ElPtrC, FFunc0ElPtrC>);
static_assert(cIsConstructibleWith<FFunc1ElPtrC, FFunc1ElPtrC>);
static_assert(cIsConstructibleWith<FFunc2ElPtrC, FFunc2ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc0ElPtr, FMFunc0ElPtr>);
static_assert(cIsConstructibleWith<FMFunc1ElPtr, FMFunc1ElPtr>);
static_assert(cIsConstructibleWith<FMFunc2ElPtr, FMFunc2ElPtr>);
static_assert(cIsConstructibleWith<FMFunc0ElPtrC, FMFunc0ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc1ElPtrC, FMFunc1ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc2ElPtrC, FMFunc2ElPtrC>);
static_assert(cIsConstructibleWith<FMFunc0ElCPtr, FMFunc0ElCPtr>);
static_assert(cIsConstructibleWith<FMFunc1ElCPtr, FMFunc1ElCPtr>);
static_assert(cIsConstructibleWith<FMFunc2ElCPtr, FMFunc2ElCPtr>);
static_assert(cIsConstructibleWith<FMFunc0ElCPtrC, FMFunc0ElCPtrC>);
static_assert(cIsConstructibleWith<FMFunc1ElCPtrC, FMFunc1ElCPtrC>);
static_assert(cIsConstructibleWith<FMFunc2ElCPtrC, FMFunc2ElCPtrC>);
static_assert(cIsConstructibleWith<CMPtr, CMPtr>);
static_assert(cIsConstructibleWith<CMCPtr, CMCPtr>);
static_assert(cIsConstructibleWith<CMPtrC, CMPtrC>);
static_assert(cIsConstructibleWith<CMCPtrC, CMCPtrC>);
static_assert(!cIsConstructibleWith<CTestArray2, CTestArray2>);
static_assert(!cIsConstructibleWith<CTestArray2C, CTestArray2C>);
static_assert(!cIsConstructibleWith<CTestArray, CTestArray>);
static_assert(!cIsConstructibleWith<CTestArrayC, CTestArrayC>);
static_assert(!cIsConstructibleWith<CTest2DArray2, CTest2DArray2>);
static_assert(!cIsConstructibleWith<CTest2DArray2C, CTest2DArray2C>);
static_assert(!cIsConstructibleWith<CTest2DArray, CTest2DArray>);
static_assert(!cIsConstructibleWith<CTest2DArrayC, CTest2DArrayC>);
static_assert(!cIsConstructibleWith<CTest3DArray2, CTest3DArray2>);
static_assert(!cIsConstructibleWith<CTest3DArray2C, CTest3DArray2C>);
static_assert(!cIsConstructibleWith<CTest3DArray, CTest3DArray>);
static_assert(!cIsConstructibleWith<CTest3DArrayC, CTest3DArrayC>);
static_assert(cIsConstructibleWith<void *, void *>);
static_assert(!cIsConstructibleWith<void>);
