// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NPolymorphic
{
	class CAbstract
	{
		virtual void f_Test() = 0;
	};

	class CInheritAbstract : private CAbstract
	{
	};

	class CNonAbstract
	{
		virtual void f_Test();
	};

	class CNonVirtual
	{
		void f_Test();
	};

	static_assert(cIsPolymorphic<CAbstract>);
	static_assert(cIsPolymorphic<CInheritAbstract>);
	static_assert(cIsPolymorphic<CNonAbstract>);
	static_assert(!cIsPolymorphic<CNonVirtual>);
}

static_assert(!cIsPolymorphic<ETestEnum>);

// Void
static_assert(!cIsPolymorphic<CTestUnion>);
static_assert(!cIsPolymorphic<CTestClass0>);
static_assert(!cIsPolymorphic<CTestClass1>);
static_assert(!cIsPolymorphic<CTestStruct0>);
static_assert(!cIsPolymorphic<CTestStruct1>);
static_assert(!cIsPolymorphic<const CTestClass0>);
static_assert(!cIsPolymorphic<const CTestClass1>);
static_assert(!cIsPolymorphic<const CTestStruct0>);
static_assert(!cIsPolymorphic<const CTestStruct1>);
static_assert(!cIsPolymorphic<ETestEnum>);
static_assert(!cIsPolymorphic<int>);
static_assert(!cIsPolymorphic<CTestClass>);
static_assert(!cIsPolymorphic<CTestC>);
static_assert(!cIsPolymorphic<CTestPtr>);
static_assert(!cIsPolymorphic<CTestCPtr>);
static_assert(!cIsPolymorphic<CTestPtrC>);
static_assert(!cIsPolymorphic<CTestCPtrC>);
static_assert(!cIsPolymorphic<CTestRef>);
static_assert(!cIsPolymorphic<CTestCRef>);
static_assert(!cIsPolymorphic<CTestRRef>);
static_assert(!cIsPolymorphic<CTestCRRef>);
static_assert(!cIsPolymorphic<PFFunc0>);
static_assert(!cIsPolymorphic<PFFunc1>);
static_assert(!cIsPolymorphic<PFFunc2>);
static_assert(!cIsPolymorphic<FFunc0Ref>);
static_assert(!cIsPolymorphic<FFunc1Ref>);
static_assert(!cIsPolymorphic<FFunc2Ref>);
static_assert(!cIsPolymorphic<FFunc0RRef>);
static_assert(!cIsPolymorphic<FFunc1RRef>);
static_assert(!cIsPolymorphic<FFunc2RRef>);
static_assert(!cIsPolymorphic<FFunc0Ptr>);
static_assert(!cIsPolymorphic<FFunc1Ptr>);
static_assert(!cIsPolymorphic<FFunc2Ptr>);
static_assert(!cIsPolymorphic<FFunc0PtrC>);
static_assert(!cIsPolymorphic<FFunc1PtrC>);
static_assert(!cIsPolymorphic<FFunc2PtrC>);
static_assert(!cIsPolymorphic<FMFunc0Ptr>);
static_assert(!cIsPolymorphic<FMFunc1Ptr>);
static_assert(!cIsPolymorphic<FMFunc2Ptr>);
static_assert(!cIsPolymorphic<FMFunc0PtrC>);
static_assert(!cIsPolymorphic<FMFunc1PtrC>);
static_assert(!cIsPolymorphic<FMFunc2PtrC>);
static_assert(!cIsPolymorphic<FMFunc0CPtr>);
static_assert(!cIsPolymorphic<FMFunc1CPtr>);
static_assert(!cIsPolymorphic<FMFunc2CPtr>);
static_assert(!cIsPolymorphic<FMFunc0CPtrC>);
static_assert(!cIsPolymorphic<FMFunc1CPtrC>);
static_assert(!cIsPolymorphic<FMFunc2CPtrC>);
static_assert(!cIsPolymorphic<PFFunc0El>);
static_assert(!cIsPolymorphic<PFFunc1El>);
static_assert(!cIsPolymorphic<PFFunc2El>);
static_assert(!cIsPolymorphic<FFunc0ElRef>);
static_assert(!cIsPolymorphic<FFunc1ElRef>);
static_assert(!cIsPolymorphic<FFunc2ElRef>);
static_assert(!cIsPolymorphic<FFunc0ElRRef>);
static_assert(!cIsPolymorphic<FFunc1ElRRef>);
static_assert(!cIsPolymorphic<FFunc2ElRRef>);
static_assert(!cIsPolymorphic<FFunc0ElPtr>);
static_assert(!cIsPolymorphic<FFunc1ElPtr>);
static_assert(!cIsPolymorphic<FFunc2ElPtr>);
static_assert(!cIsPolymorphic<FFunc0ElPtrC>);
static_assert(!cIsPolymorphic<FFunc1ElPtrC>);
static_assert(!cIsPolymorphic<FFunc2ElPtrC>);
static_assert(!cIsPolymorphic<FMFunc0ElPtr>);
static_assert(!cIsPolymorphic<FMFunc1ElPtr>);
static_assert(!cIsPolymorphic<FMFunc2ElPtr>);
static_assert(!cIsPolymorphic<FMFunc0ElPtrC>);
static_assert(!cIsPolymorphic<FMFunc1ElPtrC>);
static_assert(!cIsPolymorphic<FMFunc2ElPtrC>);
static_assert(!cIsPolymorphic<FMFunc0ElCPtr>);
static_assert(!cIsPolymorphic<FMFunc1ElCPtr>);
static_assert(!cIsPolymorphic<FMFunc2ElCPtr>);
static_assert(!cIsPolymorphic<FMFunc0ElCPtrC>);
static_assert(!cIsPolymorphic<FMFunc1ElCPtrC>);
static_assert(!cIsPolymorphic<FMFunc2ElCPtrC>);
static_assert(!cIsPolymorphic<CMPtr>);
static_assert(!cIsPolymorphic<CMCPtr>);
static_assert(!cIsPolymorphic<CMPtrC>);
static_assert(!cIsPolymorphic<CMCPtrC>);
static_assert(!cIsPolymorphic<CTestArray2>);
static_assert(!cIsPolymorphic<CTestArray2C>);
static_assert(!cIsPolymorphic<CTestArray>);
static_assert(!cIsPolymorphic<CTestArrayC>);
static_assert(!cIsPolymorphic<CTest2DArray2>);
static_assert(!cIsPolymorphic<CTest2DArray2C>);
static_assert(!cIsPolymorphic<CTest2DArray>);
static_assert(!cIsPolymorphic<CTest2DArrayC>);
static_assert(!cIsPolymorphic<CTest3DArray2>);
static_assert(!cIsPolymorphic<CTest3DArray2C>);
static_assert(!cIsPolymorphic<CTest3DArray>);
static_assert(!cIsPolymorphic<CTest3DArrayC>);
static_assert(!cIsPolymorphic<void *>);
static_assert(!cIsPolymorphic<void>);

