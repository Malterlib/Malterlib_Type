// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{

	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialAssignmentInt>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialAssignmentBoth>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialAssignmentDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	!TCHasTrivialCopyConstructor<CNonTrivialCopy>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialCopyInt>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialCopyConstructor<CNonTrivialCopyBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialCopyConstructor<CNonTrivialCopyDerived>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialCopyConstructor<CNonTrivialCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialConstruct>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialConstructDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CNonTrivialConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialCopyConstructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	!TCHasTrivialCopyConstructor<CTestClassVirtual>::mc_Value						));

}

// Void
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialCopyConstructor<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialCopyConstructor<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialCopyConstructor<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialCopyConstructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<int>::mc_Value							));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialCopyConstructor<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialCopyConstructor<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialCopyConstructor<PFFunc2>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialCopyConstructor<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialCopyConstructor<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialCopyConstructor<PFFunc2El>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialCopyConstructor<void *>::mc_Value						));
DMibStaticCheck((	TCHasTrivialCopyConstructor<void>::mc_Value							));

