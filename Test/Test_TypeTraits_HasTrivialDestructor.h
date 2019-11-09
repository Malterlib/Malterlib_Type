// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{

	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialAssignmentInt>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialAssignmentBoth>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialAssignmentDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialCopy>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialCopyInt>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialCopyBoth>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialCopyDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialConstruct>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialConstructDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CNonTrivialConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDestructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	TCHasTrivialDestructor<CTestClassVirtual>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialDestructor<CTestClassWithDestructor>::mc_Value						));
	
}

// Void
DMibStaticCheck((	TCHasTrivialDestructor<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDestructor<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDestructor<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDestructor<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDestructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<int>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDestructor<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDestructor<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDestructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialDestructor<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDestructor<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDestructor<PFFunc2>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialDestructor<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDestructor<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDestructor<PFFunc2El>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDestructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDestructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDestructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDestructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDestructor<void *>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDestructor<void>::mc_Value							));

