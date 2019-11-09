// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NStateless
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
	DMibStaticCheck((	!TCIsStateless<CAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsStateless<CInheritAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsStateless<CNonAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsStateless<CNonVirtual>::mc_Value						));
	
}

// Void
DMibStaticCheck((	!TCIsStateless<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCIsStateless<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCIsStateless<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCIsStateless<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsStateless<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCIsStateless<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsStateless<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsStateless<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<int>::mc_Value							));
DMibStaticCheck((	!TCIsStateless<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsStateless<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsStateless<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsStateless<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsStateless<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsStateless<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsStateless<void *>::mc_Value						));
DMibStaticCheck((	!TCIsStateless<void>::mc_Value							));

