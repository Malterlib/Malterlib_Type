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
	
	DMibStaticCheck((	!TCIsVirtualBaseOf<CAbstract, CAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsVirtualBaseOf<CInheritAbstract, CAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsVirtualBaseOf<CNonAbstract, CAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsVirtualBaseOf<CNonVirtual, CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsVirtualBaseOf<CInheritVirtualAbstract, CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsVirtualBaseOf<CInheritVirtualAbstract2, CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsVirtualBaseOf<CInheritVirtualAbstractCombined, CAbstract>::mc_Value						));
	
}

// Void
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestUnion, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestClass0, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestClass1, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestStruct0, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestStruct1, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<const CTestClass0, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<const CTestClass1, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<const CTestStruct0, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<const CTestStruct1, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<ETestEnum, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<int, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestClass, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestC, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCRRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<PFFunc0, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<PFFunc1, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<PFFunc2, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0Ref, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1Ref, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2Ref, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0RRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1RRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2RRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0Ptr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1Ptr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2Ptr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<PFFunc0El, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<PFFunc1El, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<PFFunc2El, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0ElRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1ElRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2ElRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0ElRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1ElRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2ElRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0ElPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1ElPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2ElPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMPtr, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray2C, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<void *, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<void, CTestClass0>::mc_Value							));

