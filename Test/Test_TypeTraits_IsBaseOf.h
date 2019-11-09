// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

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

	DMibStaticCheck((	!TCIsBaseOf<CAbstract, CTestClass0>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstract, CAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsBaseOf<CNonAbstract, CTestClass0>::mc_Value						));
	DMibStaticCheck((	!TCIsBaseOf<CNonVirtual, CTestClass0>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstractDual, CNonVirtual>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstractDual, CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstractDual2, CNonVirtual>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstractDual2, CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstractDualCombined, CNonVirtual>::mc_Value						));
	DMibStaticCheck((	TCIsBaseOf<CInheritAbstractDualCombined, CAbstract>::mc_Value						));

	
	
}

// Void
DMibStaticCheck((	!TCIsBaseOf<CTestUnion, CTestClass0>::mc_Value						));
DMibStaticCheck((	TCIsBaseOf<CTestClass0, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestClass1, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestStruct0, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestStruct1, CTestClass0>::mc_Value					));
DMibStaticCheck((	TCIsBaseOf<const CTestClass0, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<const CTestClass1, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<const CTestStruct0, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<const CTestStruct1, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<ETestEnum, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<int, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestClass, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestC, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCRRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<PFFunc0, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<PFFunc1, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<PFFunc2, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0Ref, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc1Ref, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc2Ref, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0RRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc1RRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc2RRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0Ptr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc1Ptr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc2Ptr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc1PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc2PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<PFFunc0El, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<PFFunc1El, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<PFFunc2El, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0ElRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc1ElRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc2ElRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0ElRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc1ElRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc2ElRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0ElPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc1ElPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc2ElPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<FFunc0ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc1ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc2ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CMPtr, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CMCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArray2C, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<void *, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<void, CTestClass0>::mc_Value							));

