// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NAbstract
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
	DMibStaticCheck((	TCIsAbstract<CAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsAbstract<CInheritAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsAbstract<CNonAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsAbstract<CNonVirtual>::mc_Value						));
	
}

// Void
DMibStaticCheck((	!TCIsAbstract<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsAbstract<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsAbstract<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsAbstract<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsAbstract<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<int>::mc_Value							));
DMibStaticCheck((	!TCIsAbstract<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsAbstract<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsAbstract<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsAbstract<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsAbstract<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsAbstract<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsAbstract<void *>::mc_Value						));
DMibStaticCheck((	!TCIsAbstract<void>::mc_Value							));

