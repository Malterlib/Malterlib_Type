// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NIsVirtualBaseOf
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

	#ifdef DCompiler_MSVC
		#pragma warning(disable:4594)
		#pragma warning(disable:4624)
	#endif

	class CInheritVirtualAbstract : private virtual CAbstract
	{
	};

	class CInheritVirtualAbstract2 : private virtual CAbstract
	{
	};

	class CInheritVirtualAbstractCombined : CInheritVirtualAbstract, CInheritVirtualAbstract2
	{
	};

	static_assert(!cIsVirtualBaseOf<CAbstract, CAbstract>);
	static_assert(!cIsVirtualBaseOf<CInheritAbstract, CAbstract>);
	static_assert(!cIsVirtualBaseOf<CNonAbstract, CAbstract>);
	static_assert(!cIsVirtualBaseOf<CNonVirtual, CAbstract>);
	static_assert(cIsVirtualBaseOf<CInheritVirtualAbstract, CAbstract>);
	static_assert(cIsVirtualBaseOf<CInheritVirtualAbstract2, CAbstract>);
	static_assert(cIsVirtualBaseOf<CInheritVirtualAbstractCombined, CAbstract>);
}

// Void
static_assert(!cIsVirtualBaseOf<CTestUnion, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestClass0, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestClass1, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestStruct0, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestStruct1, CTestClass0>);
static_assert(!cIsVirtualBaseOf<const CTestClass0, CTestClass0>);
static_assert(!cIsVirtualBaseOf<const CTestClass1, CTestClass0>);
static_assert(!cIsVirtualBaseOf<const CTestStruct0, CTestClass0>);
static_assert(!cIsVirtualBaseOf<const CTestStruct1, CTestClass0>);
static_assert(!cIsVirtualBaseOf<ETestEnum, CTestClass0>);
static_assert(!cIsVirtualBaseOf<int, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestClass, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestCPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestCPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestCRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestRRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestCRRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<PFFunc0, CTestClass0>);
static_assert(!cIsVirtualBaseOf<PFFunc1, CTestClass0>);
static_assert(!cIsVirtualBaseOf<PFFunc2, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0Ref, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1Ref, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2Ref, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0RRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1RRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2RRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0Ptr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1Ptr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2Ptr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0PtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1PtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2PtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0Ptr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1Ptr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2Ptr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0PtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1PtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2PtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0CPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1CPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2CPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0CPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1CPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2CPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<PFFunc0El, CTestClass0>);
static_assert(!cIsVirtualBaseOf<PFFunc1El, CTestClass0>);
static_assert(!cIsVirtualBaseOf<PFFunc2El, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0ElRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1ElRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2ElRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0ElRRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1ElRRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2ElRRef, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0ElPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1ElPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2ElPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc0ElPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc1ElPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FFunc2ElPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0ElPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1ElPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2ElPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0ElPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1ElPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2ElPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0ElCPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1ElCPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2ElCPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc0ElCPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc1ElCPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<FMFunc2ElCPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CMPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CMCPtr, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CMPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CMCPtrC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestArray2, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestArray2C, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestArray, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTestArrayC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest2DArray2, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest2DArray2C, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest2DArray, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest2DArrayC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest3DArray2, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest3DArray2C, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest3DArray, CTestClass0>);
static_assert(!cIsVirtualBaseOf<CTest3DArrayC, CTestClass0>);
static_assert(!cIsVirtualBaseOf<void *, CTestClass0>);
static_assert(!cIsVirtualBaseOf<void, CTestClass0>);

