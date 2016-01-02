// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NIsVirtualBaseOf
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
DMibStaticCheck((	!TCIsVirtualBaseOf<volatile CTestClass0, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsVirtualBaseOf<volatile CTestClass1, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsVirtualBaseOf<volatile CTestStruct0, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsVirtualBaseOf<volatile CTestStruct1, CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsVirtualBaseOf<const volatile CTestClass0, CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsVirtualBaseOf<const volatile CTestClass1, CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsVirtualBaseOf<const volatile CTestStruct0, CTestClass0>::mc_Value	));
DMibStaticCheck((	!TCIsVirtualBaseOf<const volatile CTestStruct1, CTestClass0>::mc_Value	));
DMibStaticCheck((	!TCIsVirtualBaseOf<ETestEnum, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<int, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestClass, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestC, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestV, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestVPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestVRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCVRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestRRef, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCRRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestVRRef, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestCVRRef, CTestClass0>::mc_Value					));
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
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2Ptr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2PtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2PtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2PtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0VPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1VPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2VPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0VPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1VPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2VPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0VPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1VPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2VPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0VPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1VPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2VPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0CVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1CVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2CVPtrCV, CTestClass0>::mc_Value				));
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
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc0ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc1ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FFunc2ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElVPtrCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCVPtr, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCVPtrC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCVPtrV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc0ElCVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc1ElCVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<FMFunc2ElCVPtrCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMPtr, CTestClass0>::mc_Value							));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMVPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCVPtr, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMVPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCVPtrC, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMVPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCVPtrV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMVPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CMCVPtrCV, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray2C, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray2V, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray2CV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArrayV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTestArrayCV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray2V, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray2CV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArrayV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest2DArrayCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray2, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray2C, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray2V, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray2CV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArray, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArrayC, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArrayV, CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsVirtualBaseOf<CTest3DArrayCV, CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsVirtualBaseOf<void *, CTestClass0>::mc_Value						));
DMibStaticCheck((	!TCIsVirtualBaseOf<void, CTestClass0>::mc_Value							));

