// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

namespace NIsBaseOf
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
	class CInheritAbstractDual : private CAbstract, private CNonVirtual
	{
	};

	class CInheritAbstractDual2 : private CAbstract, private CNonVirtual
	{
	};

	class CInheritAbstractDualCombined : private CInheritAbstractDual, private CInheritAbstractDual2
	{
	};

	static_assert(!cIsBaseOf<CAbstract, CTestClass0>);
	static_assert(cIsBaseOf<CInheritAbstract, CAbstract>);
	static_assert(!cIsBaseOf<CNonAbstract, CTestClass0>);
	static_assert(!cIsBaseOf<CNonVirtual, CTestClass0>);
	static_assert(cIsBaseOf<CInheritAbstractDual, CNonVirtual>);
	static_assert(cIsBaseOf<CInheritAbstractDual, CAbstract>);
	static_assert(cIsBaseOf<CInheritAbstractDual2, CNonVirtual>);
	static_assert(cIsBaseOf<CInheritAbstractDual2, CAbstract>);
	static_assert(cIsBaseOf<CInheritAbstractDualCombined, CNonVirtual>);
	static_assert(cIsBaseOf<CInheritAbstractDualCombined, CAbstract>);
}

// Void
static_assert(!cIsBaseOf<CTestUnion, CTestClass0>);
static_assert(cIsBaseOf<CTestClass0, CTestClass0>);
static_assert(!cIsBaseOf<CTestClass1, CTestClass0>);
static_assert(!cIsBaseOf<CTestStruct0, CTestClass0>);
static_assert(!cIsBaseOf<CTestStruct1, CTestClass0>);
static_assert(cIsBaseOf<const CTestClass0, CTestClass0>);
static_assert(!cIsBaseOf<const CTestClass1, CTestClass0>);
static_assert(!cIsBaseOf<const CTestStruct0, CTestClass0>);
static_assert(!cIsBaseOf<const CTestStruct1, CTestClass0>);
static_assert(!cIsBaseOf<ETestEnum, CTestClass0>);
static_assert(!cIsBaseOf<int, CTestClass0>);
static_assert(!cIsBaseOf<CTestClass, CTestClass0>);
static_assert(!cIsBaseOf<CTestC, CTestClass0>);
static_assert(!cIsBaseOf<CTestPtr, CTestClass0>);
static_assert(!cIsBaseOf<CTestCPtr, CTestClass0>);
static_assert(!cIsBaseOf<CTestPtrC, CTestClass0>);
static_assert(!cIsBaseOf<CTestCPtrC, CTestClass0>);
static_assert(!cIsBaseOf<CTestRef, CTestClass0>);
static_assert(!cIsBaseOf<CTestCRef, CTestClass0>);
static_assert(!cIsBaseOf<CTestRRef, CTestClass0>);
static_assert(!cIsBaseOf<CTestCRRef, CTestClass0>);
static_assert(!cIsBaseOf<PFFunc0, CTestClass0>);
static_assert(!cIsBaseOf<PFFunc1, CTestClass0>);
static_assert(!cIsBaseOf<PFFunc2, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0Ref, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1Ref, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2Ref, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0RRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1RRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2RRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0Ptr, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1Ptr, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2Ptr, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0PtrC, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1PtrC, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2PtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0Ptr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1Ptr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2Ptr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0PtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1PtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2PtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0CPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1CPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2CPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0CPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1CPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2CPtrC, CTestClass0>);
static_assert(!cIsBaseOf<PFFunc0El, CTestClass0>);
static_assert(!cIsBaseOf<PFFunc1El, CTestClass0>);
static_assert(!cIsBaseOf<PFFunc2El, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0ElRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1ElRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2ElRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0ElRRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1ElRRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2ElRRef, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0ElPtr, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1ElPtr, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2ElPtr, CTestClass0>);
static_assert(!cIsBaseOf<FFunc0ElPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FFunc1ElPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FFunc2ElPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0ElPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1ElPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2ElPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0ElPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1ElPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2ElPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0ElCPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1ElCPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2ElCPtr, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc0ElCPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc1ElCPtrC, CTestClass0>);
static_assert(!cIsBaseOf<FMFunc2ElCPtrC, CTestClass0>);
static_assert(!cIsBaseOf<CMPtr, CTestClass0>);
static_assert(!cIsBaseOf<CMCPtr, CTestClass0>);
static_assert(!cIsBaseOf<CMPtrC, CTestClass0>);
static_assert(!cIsBaseOf<CMCPtrC, CTestClass0>);
static_assert(!cIsBaseOf<CTestArray2, CTestClass0>);
static_assert(!cIsBaseOf<CTestArray2C, CTestClass0>);
static_assert(!cIsBaseOf<CTestArray, CTestClass0>);
static_assert(!cIsBaseOf<CTestArrayC, CTestClass0>);
static_assert(!cIsBaseOf<CTest2DArray2, CTestClass0>);
static_assert(!cIsBaseOf<CTest2DArray2C, CTestClass0>);
static_assert(!cIsBaseOf<CTest2DArray, CTestClass0>);
static_assert(!cIsBaseOf<CTest2DArrayC, CTestClass0>);
static_assert(!cIsBaseOf<CTest3DArray2, CTestClass0>);
static_assert(!cIsBaseOf<CTest3DArray2C, CTestClass0>);
static_assert(!cIsBaseOf<CTest3DArray, CTestClass0>);
static_assert(!cIsBaseOf<CTest3DArrayC, CTestClass0>);
static_assert(!cIsBaseOf<void *, CTestClass0>);
static_assert(!cIsBaseOf<void, CTestClass0>);

