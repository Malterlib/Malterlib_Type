// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

namespace NHasVirtualDestrutor
{
	class CTestClassWithVirtualDestructor
	{
	public:
		virtual ~CTestClassWithVirtualDestructor()
		{
		}
	};

	class CTestClassWithVirtualDestructorDerived : public CTestClassWithVirtualDestructor
	{
	public:
	};

	static_assert(!cHasVirtualDestructor<CTestClassVirtual>);
	static_assert(!cHasVirtualDestructor<CTestClassWithDestructor>);
	static_assert(cHasVirtualDestructor<CTestClassWithVirtualDestructor>);
	static_assert(cHasVirtualDestructor<CTestClassWithVirtualDestructorDerived>);
}

// Void
static_assert(!cHasVirtualDestructor<CTestUnion>);
static_assert(!cHasVirtualDestructor<CTestClass0>);
static_assert(!cHasVirtualDestructor<CTestClass1>);
static_assert(!cHasVirtualDestructor<CTestStruct0>);
static_assert(!cHasVirtualDestructor<CTestStruct1>);
static_assert(!cHasVirtualDestructor<const CTestClass0>);
static_assert(!cHasVirtualDestructor<const CTestClass1>);
static_assert(!cHasVirtualDestructor<const CTestStruct0>);
static_assert(!cHasVirtualDestructor<const CTestStruct1>);
static_assert(!cHasVirtualDestructor<ETestEnum>);
static_assert(!cHasVirtualDestructor<int>);
static_assert(!cHasVirtualDestructor<CTestClass>);
static_assert(!cHasVirtualDestructor<CTestC>);
static_assert(!cHasVirtualDestructor<CTestPtr>);
static_assert(!cHasVirtualDestructor<CTestCPtr>);
static_assert(!cHasVirtualDestructor<CTestPtrC>);
static_assert(!cHasVirtualDestructor<CTestCPtrC>);
static_assert(!cHasVirtualDestructor<CTestRef>);
static_assert(!cHasVirtualDestructor<CTestCRef>);
static_assert(!cHasVirtualDestructor<CTestRRef>);
static_assert(!cHasVirtualDestructor<CTestCRRef>);
static_assert(!cHasVirtualDestructor<PFFunc0>);
static_assert(!cHasVirtualDestructor<PFFunc1>);
static_assert(!cHasVirtualDestructor<PFFunc2>);
static_assert(!cHasVirtualDestructor<FFunc0Ref>);
static_assert(!cHasVirtualDestructor<FFunc1Ref>);
static_assert(!cHasVirtualDestructor<FFunc2Ref>);
static_assert(!cHasVirtualDestructor<FFunc0RRef>);
static_assert(!cHasVirtualDestructor<FFunc1RRef>);
static_assert(!cHasVirtualDestructor<FFunc2RRef>);
static_assert(!cHasVirtualDestructor<FFunc0Ptr>);
static_assert(!cHasVirtualDestructor<FFunc1Ptr>);
static_assert(!cHasVirtualDestructor<FFunc2Ptr>);
static_assert(!cHasVirtualDestructor<FFunc0PtrC>);
static_assert(!cHasVirtualDestructor<FFunc1PtrC>);
static_assert(!cHasVirtualDestructor<FFunc2PtrC>);
static_assert(!cHasVirtualDestructor<FMFunc0Ptr>);
static_assert(!cHasVirtualDestructor<FMFunc1Ptr>);
static_assert(!cHasVirtualDestructor<FMFunc2Ptr>);
static_assert(!cHasVirtualDestructor<FMFunc0PtrC>);
static_assert(!cHasVirtualDestructor<FMFunc1PtrC>);
static_assert(!cHasVirtualDestructor<FMFunc2PtrC>);
static_assert(!cHasVirtualDestructor<FMFunc0CPtr>);
static_assert(!cHasVirtualDestructor<FMFunc1CPtr>);
static_assert(!cHasVirtualDestructor<FMFunc2CPtr>);
static_assert(!cHasVirtualDestructor<FMFunc0CPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc1CPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc2CPtrC>);
static_assert(!cHasVirtualDestructor<PFFunc0El>);
static_assert(!cHasVirtualDestructor<PFFunc1El>);
static_assert(!cHasVirtualDestructor<PFFunc2El>);
static_assert(!cHasVirtualDestructor<FFunc0ElRef>);
static_assert(!cHasVirtualDestructor<FFunc1ElRef>);
static_assert(!cHasVirtualDestructor<FFunc2ElRef>);
static_assert(!cHasVirtualDestructor<FFunc0ElRRef>);
static_assert(!cHasVirtualDestructor<FFunc1ElRRef>);
static_assert(!cHasVirtualDestructor<FFunc2ElRRef>);
static_assert(!cHasVirtualDestructor<FFunc0ElPtr>);
static_assert(!cHasVirtualDestructor<FFunc1ElPtr>);
static_assert(!cHasVirtualDestructor<FFunc2ElPtr>);
static_assert(!cHasVirtualDestructor<FFunc0ElPtrC>);
static_assert(!cHasVirtualDestructor<FFunc1ElPtrC>);
static_assert(!cHasVirtualDestructor<FFunc2ElPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc0ElPtr>);
static_assert(!cHasVirtualDestructor<FMFunc1ElPtr>);
static_assert(!cHasVirtualDestructor<FMFunc2ElPtr>);
static_assert(!cHasVirtualDestructor<FMFunc0ElPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc1ElPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc2ElPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc0ElCPtr>);
static_assert(!cHasVirtualDestructor<FMFunc1ElCPtr>);
static_assert(!cHasVirtualDestructor<FMFunc2ElCPtr>);
static_assert(!cHasVirtualDestructor<FMFunc0ElCPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc1ElCPtrC>);
static_assert(!cHasVirtualDestructor<FMFunc2ElCPtrC>);
static_assert(!cHasVirtualDestructor<CMPtr>);
static_assert(!cHasVirtualDestructor<CMCPtr>);
static_assert(!cHasVirtualDestructor<CMPtrC>);
static_assert(!cHasVirtualDestructor<CMCPtrC>);
static_assert(!cHasVirtualDestructor<CTestArray2>);
static_assert(!cHasVirtualDestructor<CTestArray2C>);
static_assert(!cHasVirtualDestructor<CTestArray>);
static_assert(!cHasVirtualDestructor<CTestArrayC>);
static_assert(!cHasVirtualDestructor<CTest2DArray2>);
static_assert(!cHasVirtualDestructor<CTest2DArray2C>);
static_assert(!cHasVirtualDestructor<CTest2DArray>);
static_assert(!cHasVirtualDestructor<CTest2DArrayC>);
static_assert(!cHasVirtualDestructor<CTest3DArray2>);
static_assert(!cHasVirtualDestructor<CTest3DArray2C>);
static_assert(!cHasVirtualDestructor<CTest3DArray>);
static_assert(!cHasVirtualDestructor<CTest3DArrayC>);
static_assert(!cHasVirtualDestructor<void *>);
static_assert(!cHasVirtualDestructor<void>);

