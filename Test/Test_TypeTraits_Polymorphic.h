// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NPolymorphic
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

	DMibStaticCheck((	TCIsPolymorphic<CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsPolymorphic<CInheritAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsPolymorphic<CNonAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsPolymorphic<CNonVirtual>::mc_Value						));
}

DMibStaticCheck((	!TCIsPolymorphic<ETestEnum>::mc_Value	));

// Void
DMibStaticCheck((	!TCIsPolymorphic<CTestUnion>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsPolymorphic<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsPolymorphic<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsPolymorphic<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsPolymorphic<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<int>::mc_Value							));
DMibStaticCheck((	!TCIsPolymorphic<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsPolymorphic<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsPolymorphic<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsPolymorphic<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsPolymorphic<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsPolymorphic<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsPolymorphic<void *>::mc_Value						));
DMibStaticCheck((	!TCIsPolymorphic<void>::mc_Value							));

