// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{

	DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CNonTrivialAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialAssignmentInt>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CNonTrivialAssignmentBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CNonTrivialAssignmentDerived>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CNonTrivialAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTrivial>::mc_Value						));

	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialCopy>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialCopyInt>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialCopyBoth>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialCopyDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTrivial>::mc_Value						));

	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialConstruct>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialConstructDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CNonTrivialConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTrivial>::mc_Value						));

	DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CTestClassVirtual>::mc_Value						));

}

// Void
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<int>::mc_Value							));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CTestCRef>::mc_Value						));
#ifndef DCompiler_MSVC
#endif
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<CTestCRRef>::mc_Value					));
#ifndef DCompiler_MSVC
#endif
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialAssignmentOperator<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<void *>::mc_Value						));
DMibStaticCheck((	TCHasTrivialAssignmentOperator<void>::mc_Value							));

