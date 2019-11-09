// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NNothrow
{

	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsAssignmentInt>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsAssignmentBoth>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsAssignmentDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CNothrow>::mc_Value						));

	DMibStaticCheck((	!TCHasNothrowCopyConstructor<CThrowsCopy>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsCopyInt>::mc_Value						));
	DMibStaticCheck((	!TCHasNothrowCopyConstructor<CThrowsCopyBoth>::mc_Value						));
#ifndef DMibCompiler_GCC
	DMibStaticCheck((	!TCHasNothrowCopyConstructor<CThrowsCopyDerived>::mc_Value						));
#endif
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsConstruct>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsConstructDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CThrowsConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowCopyConstructor<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestClassVirtual>::mc_Value						));
	
}

// Void
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasNothrowCopyConstructor<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasNothrowCopyConstructor<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasNothrowCopyConstructor<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasNothrowCopyConstructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<int>::mc_Value							));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasNothrowCopyConstructor<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowCopyConstructor<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowCopyConstructor<PFFunc2>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasNothrowCopyConstructor<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowCopyConstructor<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowCopyConstructor<PFFunc2El>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowCopyConstructor<void *>::mc_Value						));
DMibStaticCheck((	TCHasNothrowCopyConstructor<void>::mc_Value							));

