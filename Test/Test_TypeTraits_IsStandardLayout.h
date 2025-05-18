// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NStandardLayout
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

	static_assert(!cIsStandardLayout<CAbstract>);
	static_assert(!cIsStandardLayout<CInheritAbstract>);
	static_assert(!cIsStandardLayout<CNonAbstract>);
	static_assert(cIsStandardLayout<CNonVirtual>);
}

// Void
static_assert(cIsStandardLayout<CTestUnion>);
static_assert(cIsStandardLayout<CTestClass0>);
static_assert(cIsStandardLayout<CTestClass1>);
static_assert(cIsStandardLayout<CTestStruct0>);
static_assert(cIsStandardLayout<CTestStruct1>);
static_assert(cIsStandardLayout<const CTestClass0>);
static_assert(cIsStandardLayout<const CTestClass1>);
static_assert(cIsStandardLayout<const CTestStruct0>);
static_assert(cIsStandardLayout<const CTestStruct1>);
static_assert(cIsStandardLayout<ETestEnum>);
static_assert(cIsStandardLayout<int>);
static_assert(cIsStandardLayout<CTestClass>);
static_assert(cIsStandardLayout<CTestC>);
static_assert(cIsStandardLayout<CTestPtr>);
static_assert(cIsStandardLayout<CTestCPtr>);
static_assert(cIsStandardLayout<CTestPtrC>);
static_assert(cIsStandardLayout<CTestCPtrC>);
static_assert(!cIsStandardLayout<CTestRef>);
static_assert(!cIsStandardLayout<CTestCRef>);
static_assert(!cIsStandardLayout<CTestRRef>);
static_assert(!cIsStandardLayout<CTestCRRef>);
#ifndef DCompiler_MSVC_Workaround
static_assert(!cIsStandardLayout<PFFunc0>);
static_assert(!cIsStandardLayout<PFFunc1>);
static_assert(!cIsStandardLayout<PFFunc2>);
#endif
static_assert(!cIsStandardLayout<FFunc0Ref>);
static_assert(!cIsStandardLayout<FFunc1Ref>);
static_assert(!cIsStandardLayout<FFunc2Ref>);
static_assert(!cIsStandardLayout<FFunc0RRef>);
static_assert(!cIsStandardLayout<FFunc1RRef>);
static_assert(!cIsStandardLayout<FFunc2RRef>);
static_assert(cIsStandardLayout<FFunc0Ptr>);
static_assert(cIsStandardLayout<FFunc1Ptr>);
static_assert(cIsStandardLayout<FFunc2Ptr>);
static_assert(cIsStandardLayout<FFunc0PtrC>);
static_assert(cIsStandardLayout<FFunc1PtrC>);
static_assert(cIsStandardLayout<FFunc2PtrC>);
static_assert(cIsStandardLayout<FMFunc0Ptr>);
static_assert(cIsStandardLayout<FMFunc1Ptr>);
static_assert(cIsStandardLayout<FMFunc2Ptr>);
static_assert(cIsStandardLayout<FMFunc0PtrC>);
static_assert(cIsStandardLayout<FMFunc1PtrC>);
static_assert(cIsStandardLayout<FMFunc2PtrC>);
static_assert(cIsStandardLayout<FMFunc0CPtr>);
static_assert(cIsStandardLayout<FMFunc1CPtr>);
static_assert(cIsStandardLayout<FMFunc2CPtr>);
static_assert(cIsStandardLayout<FMFunc0CPtrC>);
static_assert(cIsStandardLayout<FMFunc1CPtrC>);
static_assert(cIsStandardLayout<FMFunc2CPtrC>);
#ifndef DCompiler_MSVC_Workaround
static_assert(!cIsStandardLayout<PFFunc0El>);
static_assert(!cIsStandardLayout<PFFunc1El>);
static_assert(!cIsStandardLayout<PFFunc2El>);
#endif
static_assert(!cIsStandardLayout<FFunc0ElRef>);
static_assert(!cIsStandardLayout<FFunc1ElRef>);
static_assert(!cIsStandardLayout<FFunc2ElRef>);
static_assert(!cIsStandardLayout<FFunc0ElRRef>);
static_assert(!cIsStandardLayout<FFunc1ElRRef>);
static_assert(!cIsStandardLayout<FFunc2ElRRef>);
static_assert(cIsStandardLayout<FFunc0ElPtr>);
static_assert(cIsStandardLayout<FFunc1ElPtr>);
static_assert(cIsStandardLayout<FFunc2ElPtr>);
static_assert(cIsStandardLayout<FFunc0ElPtrC>);
static_assert(cIsStandardLayout<FFunc1ElPtrC>);
static_assert(cIsStandardLayout<FFunc2ElPtrC>);
static_assert(cIsStandardLayout<FMFunc0ElPtr>);
static_assert(cIsStandardLayout<FMFunc1ElPtr>);
static_assert(cIsStandardLayout<FMFunc2ElPtr>);
static_assert(cIsStandardLayout<FMFunc0ElPtrC>);
static_assert(cIsStandardLayout<FMFunc1ElPtrC>);
static_assert(cIsStandardLayout<FMFunc2ElPtrC>);
static_assert(cIsStandardLayout<FMFunc0ElCPtr>);
static_assert(cIsStandardLayout<FMFunc1ElCPtr>);
static_assert(cIsStandardLayout<FMFunc2ElCPtr>);
static_assert(cIsStandardLayout<FMFunc0ElCPtrC>);
static_assert(cIsStandardLayout<FMFunc1ElCPtrC>);
static_assert(cIsStandardLayout<FMFunc2ElCPtrC>);
static_assert(cIsStandardLayout<CMPtr>);
static_assert(cIsStandardLayout<CMCPtr>);
static_assert(cIsStandardLayout<CMPtrC>);
static_assert(cIsStandardLayout<CMCPtrC>);
static_assert(cIsStandardLayout<CTestArray2>);
static_assert(cIsStandardLayout<CTestArray2C>);
static_assert(cIsStandardLayout<CTestArray>);
static_assert(cIsStandardLayout<CTestArrayC>);
static_assert(cIsStandardLayout<CTest2DArray2>);
static_assert(cIsStandardLayout<CTest2DArray2C>);
static_assert(cIsStandardLayout<CTest2DArray>);
static_assert(cIsStandardLayout<CTest2DArrayC>);
static_assert(cIsStandardLayout<CTest3DArray2>);
static_assert(cIsStandardLayout<CTest3DArray2C>);
static_assert(cIsStandardLayout<CTest3DArray>);
static_assert(cIsStandardLayout<CTest3DArrayC>);
static_assert(cIsStandardLayout<void *>);
static_assert(!cIsStandardLayout<void>);

