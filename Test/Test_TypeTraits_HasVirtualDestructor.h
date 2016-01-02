// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NHasVirtualDestrutor
{

	class CTestClassWithVirtualDestructor
	{
	public:
		virtual ~CTestClassWithVirtualDestructor()
		{
		}
	};

	class CTestClassWithVirtualDestructorDerived : public CTestClassWithVirtualDestructor
	{
	public:
	};

	DMibStaticCheck((	!TCHasVirtualDestructor<CTestClassVirtual>::mc_Value						));
	DMibStaticCheck((	!TCHasVirtualDestructor<CTestClassWithDestructor>::mc_Value						));
	DMibStaticCheck((	TCHasVirtualDestructor<CTestClassWithVirtualDestructor>::mc_Value						));
	DMibStaticCheck((	TCHasVirtualDestructor<CTestClassWithVirtualDestructorDerived>::mc_Value						));
	
	
}

// Void
DMibStaticCheck((	!TCHasVirtualDestructor<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<volatile CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCHasVirtualDestructor<volatile CTestClass1>::mc_Value			));
DMibStaticCheck((	!TCHasVirtualDestructor<volatile CTestStruct0>::mc_Value			));
DMibStaticCheck((	!TCHasVirtualDestructor<volatile CTestStruct1>::mc_Value			));
DMibStaticCheck((	!TCHasVirtualDestructor<const volatile CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCHasVirtualDestructor<const volatile CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCHasVirtualDestructor<const volatile CTestStruct0>::mc_Value	));
DMibStaticCheck((	!TCHasVirtualDestructor<const volatile CTestStruct1>::mc_Value	));
DMibStaticCheck((	!TCHasVirtualDestructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<int>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestC>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestV>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestVPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestPtrV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestVRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCVRef>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestVRRef>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCVRRef>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0PtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1PtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2PtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0PtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1PtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2PtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0PtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1PtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2PtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0PtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1PtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2PtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0VPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1VPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2VPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0VPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1VPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2VPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0VPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1VPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2VPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc0ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc1ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FFunc2ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMVPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCVPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMVPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCVPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMPtrV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCPtrV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMVPtrV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCVPtrV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMPtrCV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCPtrCV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMVPtrCV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCVPtrCV>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray2V>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray2CV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArrayV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArrayCV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray2V>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray2CV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArrayV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArrayCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray2V>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray2CV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArrayV>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArrayCV>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<void *>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<void>::mc_Value							));

