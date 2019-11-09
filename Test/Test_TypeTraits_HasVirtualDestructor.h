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
DMibStaticCheck((	!TCHasVirtualDestructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<int>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestC>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestCRRef>::mc_Value					));
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
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2CPtrC>::mc_Value					));
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
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasVirtualDestructor<void *>::mc_Value						));
DMibStaticCheck((	!TCHasVirtualDestructor<void>::mc_Value							));

