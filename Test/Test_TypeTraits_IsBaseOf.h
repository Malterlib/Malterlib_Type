// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NIsBaseOf
{
	class CAbstract
	{
		virtual void f_Test() pure;
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
DMibStaticCheck((	TCIsBaseOf<volatile CTestClass0, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsBaseOf<volatile CTestClass1, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsBaseOf<volatile CTestStruct0, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsBaseOf<volatile CTestStruct1, CTestClass0>::mc_Value			));
DMibStaticCheck((	TCIsBaseOf<const volatile CTestClass0, CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsBaseOf<const volatile CTestClass1, CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsBaseOf<const volatile CTestStruct0, CTestClass0>::mc_Value	));
DMibStaticCheck((	!TCIsBaseOf<const volatile CTestStruct1, CTestClass0>::mc_Value	));
DMibStaticCheck((	!TCIsBaseOf<ETestEnum, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<int, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestClass, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestC, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestV, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CTestCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestVPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestCVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestVRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCVRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestCRRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestVRRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestCVRRef, CTestClass0>::mc_Value					));
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
DMibStaticCheck((	!TCIsBaseOf<FFunc0PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc1PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc2PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc0PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc1PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc2PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0VPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1VPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2VPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0VPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1VPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2VPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0VPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1VPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2VPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0VPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1VPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2VPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0CVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1CVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2CVPtrCV, CTestClass0>::mc_Value				));
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
DMibStaticCheck((	!TCIsBaseOf<FFunc0ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc1ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc2ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc0ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc1ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FFunc2ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<FMFunc0ElCVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<FMFunc1ElCVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<FMFunc2ElCVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CMPtr, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsBaseOf<CMCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMVPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCVPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMVPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCVPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMVPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCVPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMVPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CMCVPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<CTestArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArray2C, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArray2V, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArray2CV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArrayV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTestArrayCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray2V, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray2CV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArrayV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest2DArrayCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray2V, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray2CV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArrayV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsBaseOf<CTest3DArrayCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsBaseOf<void *, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsBaseOf<void, CTestClass0>::mc_Value							));

