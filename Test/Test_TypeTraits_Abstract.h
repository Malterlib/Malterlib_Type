// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

namespace NAbstract
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
	static_assert(cIsAbstract<CAbstract>);
	static_assert(cIsAbstract<CInheritAbstract>);
	static_assert(!cIsAbstract<CNonAbstract>);
	static_assert(!cIsAbstract<CNonVirtual>);

}

// Void
static_assert(!cIsAbstract<CTestUnion>);
static_assert(!cIsAbstract<CTestClass0>);
static_assert(!cIsAbstract<CTestClass1>);
static_assert(!cIsAbstract<CTestStruct0>);
static_assert(!cIsAbstract<CTestStruct1>);
static_assert(!cIsAbstract<const CTestClass0>);
static_assert(!cIsAbstract<const CTestClass1>);
static_assert(!cIsAbstract<const CTestStruct0>);
static_assert(!cIsAbstract<const CTestStruct1>);
static_assert(!cIsAbstract<ETestEnum>);
static_assert(!cIsAbstract<int>);
static_assert(!cIsAbstract<CTestClass>);
static_assert(!cIsAbstract<CTestC>);
static_assert(!cIsAbstract<CTestPtr>);
static_assert(!cIsAbstract<CTestCPtr>);
static_assert(!cIsAbstract<CTestPtrC>);
static_assert(!cIsAbstract<CTestCPtrC>);
static_assert(!cIsAbstract<CTestRef>);
static_assert(!cIsAbstract<CTestCRef>);
static_assert(!cIsAbstract<CTestRRef>);
static_assert(!cIsAbstract<CTestCRRef>);
static_assert(!cIsAbstract<PFFunc0>);
static_assert(!cIsAbstract<PFFunc1>);
static_assert(!cIsAbstract<PFFunc2>);
static_assert(!cIsAbstract<FFunc0Ref>);
static_assert(!cIsAbstract<FFunc1Ref>);
static_assert(!cIsAbstract<FFunc2Ref>);
static_assert(!cIsAbstract<FFunc0RRef>);
static_assert(!cIsAbstract<FFunc1RRef>);
static_assert(!cIsAbstract<FFunc2RRef>);
static_assert(!cIsAbstract<FFunc0Ptr>);
static_assert(!cIsAbstract<FFunc1Ptr>);
static_assert(!cIsAbstract<FFunc2Ptr>);
static_assert(!cIsAbstract<FFunc0PtrC>);
static_assert(!cIsAbstract<FFunc1PtrC>);
static_assert(!cIsAbstract<FFunc2PtrC>);
static_assert(!cIsAbstract<FMFunc0Ptr>);
static_assert(!cIsAbstract<FMFunc1Ptr>);
static_assert(!cIsAbstract<FMFunc2Ptr>);
static_assert(!cIsAbstract<FMFunc0PtrC>);
static_assert(!cIsAbstract<FMFunc1PtrC>);
static_assert(!cIsAbstract<FMFunc2PtrC>);
static_assert(!cIsAbstract<FMFunc0CPtr>);
static_assert(!cIsAbstract<FMFunc1CPtr>);
static_assert(!cIsAbstract<FMFunc2CPtr>);
static_assert(!cIsAbstract<FMFunc0CPtrC>);
static_assert(!cIsAbstract<FMFunc1CPtrC>);
static_assert(!cIsAbstract<FMFunc2CPtrC>);
static_assert(!cIsAbstract<PFFunc0El>);
static_assert(!cIsAbstract<PFFunc1El>);
static_assert(!cIsAbstract<PFFunc2El>);
static_assert(!cIsAbstract<FFunc0ElRef>);
static_assert(!cIsAbstract<FFunc1ElRef>);
static_assert(!cIsAbstract<FFunc2ElRef>);
static_assert(!cIsAbstract<FFunc0ElRRef>);
static_assert(!cIsAbstract<FFunc1ElRRef>);
static_assert(!cIsAbstract<FFunc2ElRRef>);
static_assert(!cIsAbstract<FFunc0ElPtr>);
static_assert(!cIsAbstract<FFunc1ElPtr>);
static_assert(!cIsAbstract<FFunc2ElPtr>);
static_assert(!cIsAbstract<FFunc0ElPtrC>);
static_assert(!cIsAbstract<FFunc1ElPtrC>);
static_assert(!cIsAbstract<FFunc2ElPtrC>);
static_assert(!cIsAbstract<FMFunc0ElPtr>);
static_assert(!cIsAbstract<FMFunc1ElPtr>);
static_assert(!cIsAbstract<FMFunc2ElPtr>);
static_assert(!cIsAbstract<FMFunc0ElPtrC>);
static_assert(!cIsAbstract<FMFunc1ElPtrC>);
static_assert(!cIsAbstract<FMFunc2ElPtrC>);
static_assert(!cIsAbstract<FMFunc0ElCPtr>);
static_assert(!cIsAbstract<FMFunc1ElCPtr>);
static_assert(!cIsAbstract<FMFunc2ElCPtr>);
static_assert(!cIsAbstract<FMFunc0ElCPtrC>);
static_assert(!cIsAbstract<FMFunc1ElCPtrC>);
static_assert(!cIsAbstract<FMFunc2ElCPtrC>);
static_assert(!cIsAbstract<CMPtr>);
static_assert(!cIsAbstract<CMCPtr>);
static_assert(!cIsAbstract<CMPtrC>);
static_assert(!cIsAbstract<CMCPtrC>);
static_assert(!cIsAbstract<CTestArray2>);
static_assert(!cIsAbstract<CTestArray2C>);
static_assert(!cIsAbstract<CTestArray>);
static_assert(!cIsAbstract<CTestArrayC>);
static_assert(!cIsAbstract<CTest2DArray2>);
static_assert(!cIsAbstract<CTest2DArray2C>);
static_assert(!cIsAbstract<CTest2DArray>);
static_assert(!cIsAbstract<CTest2DArrayC>);
static_assert(!cIsAbstract<CTest3DArray2>);
static_assert(!cIsAbstract<CTest3DArray2C>);
static_assert(!cIsAbstract<CTest3DArray>);
static_assert(!cIsAbstract<CTest3DArrayC>);
static_assert(!cIsAbstract<void *>);
static_assert(!cIsAbstract<void>);

