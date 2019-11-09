// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"


namespace NNothrow
{

	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsAssignmentInt>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsAssignmentBoth>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsAssignmentDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsCopy>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsCopyInt>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsCopyBoth>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsCopyDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CNothrowDefault>::mc_Value						));

	DMibStaticCheck((	!TCHasNothrowDefaultConstructor<CThrowsConstruct>::mc_Value						));
	DMibStaticCheck((	!TCHasNothrowDefaultConstructor<CThrowsConstructDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CThrowsConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestClassVirtual>::mc_Value						));

}

// Void
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<int>::mc_Value							));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowDefaultConstructor<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<void *>::mc_Value						));
DMibStaticCheck((	TCHasNothrowDefaultConstructor<void>::mc_Value							));

