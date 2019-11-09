// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NStandardLayout
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
	DMibStaticCheck((	!TCIsStandardLayout<CAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsStandardLayout<CInheritAbstract>::mc_Value						));
	DMibStaticCheck((	!TCIsStandardLayout<CNonAbstract>::mc_Value						));
	DMibStaticCheck((	TCIsStandardLayout<CNonVirtual>::mc_Value						));
	
}

// Void
DMibStaticCheck((	TCIsStandardLayout<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCIsStandardLayout<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCIsStandardLayout<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCIsStandardLayout<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCIsStandardLayout<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<int>::mc_Value							));
DMibStaticCheck((	TCIsStandardLayout<CTestClass>::mc_Value							));
DMibStaticCheck((	TCIsStandardLayout<CTestC>::mc_Value							));
DMibStaticCheck((	TCIsStandardLayout<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStandardLayout<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsStandardLayout<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsStandardLayout<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsStandardLayout<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CMPtr>::mc_Value							));
DMibStaticCheck((	TCIsStandardLayout<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTestArray>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCIsStandardLayout<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCIsStandardLayout<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCIsStandardLayout<void *>::mc_Value						));
DMibStaticCheck((	TCIsStandardLayout<void>::mc_Value							));

