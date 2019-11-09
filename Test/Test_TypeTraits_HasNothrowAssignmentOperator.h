// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NNothrow
{
	//
	DMibStaticCheck((	!TCHasNothrowAssignmentOperator<CThrowsAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsAssignmentInt>::mc_Value						));
	DMibStaticCheck((	!TCHasNothrowAssignmentOperator<CThrowsAssignmentBoth>::mc_Value						));
#ifndef DMibCompiler_GCC
	DMibStaticCheck((	!TCHasNothrowAssignmentOperator<CThrowsAssignmentDerived>::mc_Value						));
#endif
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsCopy>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsCopyInt>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsCopyBoth>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsCopyDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CNothrow>::mc_Value						));

	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsConstruct>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsConstructDerived>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CThrowsConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CNothrow>::mc_Value						));
	
	DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestClassVirtual>::mc_Value						));


}

// Void
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<int>::mc_Value							));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestBase>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<CTestCRef>::mc_Value						));
#ifndef DCompiler_MSVC_Workaround
#endif
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<CTestCRRef>::mc_Value					));
#ifndef DCompiler_MSVC_Workaround
#endif
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasNothrowAssignmentOperator<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<void *>::mc_Value						));
DMibStaticCheck((	TCHasNothrowAssignmentOperator<void>::mc_Value							));

