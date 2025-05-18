// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NStateless
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

	static_assert(!cIsStateless<CAbstract>);
	static_assert(!cIsStateless<CInheritAbstract>);
	static_assert(!cIsStateless<CNonAbstract>);
	static_assert(cIsStateless<CNonVirtual>);
}

// Void
static_assert(!cIsStateless<CTestUnion>);
static_assert(cIsStateless<CTestClass0>);
static_assert(!cIsStateless<CTestClass1>);
static_assert(cIsStateless<CTestStruct0>);
static_assert(!cIsStateless<CTestStruct1>);
static_assert(cIsStateless<const CTestClass0>);
static_assert(!cIsStateless<const CTestClass1>);
static_assert(cIsStateless<const CTestStruct0>);
static_assert(!cIsStateless<const CTestStruct1>);
static_assert(!cIsStateless<ETestEnum>);
static_assert(!cIsStateless<int>);
static_assert(!cIsStateless<CTestClass>);
static_assert(!cIsStateless<CTestC>);
static_assert(!cIsStateless<CTestPtr>);
static_assert(!cIsStateless<CTestCPtr>);
static_assert(!cIsStateless<CTestPtrC>);
static_assert(!cIsStateless<CTestCPtrC>);
static_assert(!cIsStateless<CTestRef>);
static_assert(!cIsStateless<CTestCRef>);
static_assert(!cIsStateless<CTestRRef>);
static_assert(!cIsStateless<CTestCRRef>);
static_assert(!cIsStateless<PFFunc0>);
static_assert(!cIsStateless<PFFunc1>);
static_assert(!cIsStateless<PFFunc2>);
static_assert(!cIsStateless<FFunc0Ref>);
static_assert(!cIsStateless<FFunc1Ref>);
static_assert(!cIsStateless<FFunc2Ref>);
static_assert(!cIsStateless<FFunc0RRef>);
static_assert(!cIsStateless<FFunc1RRef>);
static_assert(!cIsStateless<FFunc2RRef>);
static_assert(!cIsStateless<FFunc0Ptr>);
static_assert(!cIsStateless<FFunc1Ptr>);
static_assert(!cIsStateless<FFunc2Ptr>);
static_assert(!cIsStateless<FFunc0PtrC>);
static_assert(!cIsStateless<FFunc1PtrC>);
static_assert(!cIsStateless<FFunc2PtrC>);
static_assert(!cIsStateless<FMFunc0Ptr>);
static_assert(!cIsStateless<FMFunc1Ptr>);
static_assert(!cIsStateless<FMFunc2Ptr>);
static_assert(!cIsStateless<FMFunc0PtrC>);
static_assert(!cIsStateless<FMFunc1PtrC>);
static_assert(!cIsStateless<FMFunc2PtrC>);
static_assert(!cIsStateless<FMFunc0CPtr>);
static_assert(!cIsStateless<FMFunc1CPtr>);
static_assert(!cIsStateless<FMFunc2CPtr>);
static_assert(!cIsStateless<FMFunc0CPtrC>);
static_assert(!cIsStateless<FMFunc1CPtrC>);
static_assert(!cIsStateless<FMFunc2CPtrC>);
static_assert(!cIsStateless<PFFunc0El>);
static_assert(!cIsStateless<PFFunc1El>);
static_assert(!cIsStateless<PFFunc2El>);
static_assert(!cIsStateless<FFunc0ElRef>);
static_assert(!cIsStateless<FFunc1ElRef>);
static_assert(!cIsStateless<FFunc2ElRef>);
static_assert(!cIsStateless<FFunc0ElRRef>);
static_assert(!cIsStateless<FFunc1ElRRef>);
static_assert(!cIsStateless<FFunc2ElRRef>);
static_assert(!cIsStateless<FFunc0ElPtr>);
static_assert(!cIsStateless<FFunc1ElPtr>);
static_assert(!cIsStateless<FFunc2ElPtr>);
static_assert(!cIsStateless<FFunc0ElPtrC>);
static_assert(!cIsStateless<FFunc1ElPtrC>);
static_assert(!cIsStateless<FFunc2ElPtrC>);
static_assert(!cIsStateless<FMFunc0ElPtr>);
static_assert(!cIsStateless<FMFunc1ElPtr>);
static_assert(!cIsStateless<FMFunc2ElPtr>);
static_assert(!cIsStateless<FMFunc0ElPtrC>);
static_assert(!cIsStateless<FMFunc1ElPtrC>);
static_assert(!cIsStateless<FMFunc2ElPtrC>);
static_assert(!cIsStateless<FMFunc0ElCPtr>);
static_assert(!cIsStateless<FMFunc1ElCPtr>);
static_assert(!cIsStateless<FMFunc2ElCPtr>);
static_assert(!cIsStateless<FMFunc0ElCPtrC>);
static_assert(!cIsStateless<FMFunc1ElCPtrC>);
static_assert(!cIsStateless<FMFunc2ElCPtrC>);
static_assert(!cIsStateless<CMPtr>);
static_assert(!cIsStateless<CMCPtr>);
static_assert(!cIsStateless<CMPtrC>);
static_assert(!cIsStateless<CMCPtrC>);
static_assert(!cIsStateless<CTestArray2>);
static_assert(!cIsStateless<CTestArray2C>);
static_assert(!cIsStateless<CTestArray>);
static_assert(!cIsStateless<CTestArrayC>);
static_assert(!cIsStateless<CTest2DArray2>);
static_assert(!cIsStateless<CTest2DArray2C>);
static_assert(!cIsStateless<CTest2DArray>);
static_assert(!cIsStateless<CTest2DArrayC>);
static_assert(!cIsStateless<CTest3DArray2>);
static_assert(!cIsStateless<CTest3DArray2C>);
static_assert(!cIsStateless<CTest3DArray>);
static_assert(!cIsStateless<CTest3DArrayC>);
static_assert(!cIsStateless<void *>);
static_assert(!cIsStateless<void>);

