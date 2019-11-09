// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{

	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CNonTrivialAssignment>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CNonTrivialAssignmentInt>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CNonTrivialAssignmentBoth>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CNonTrivialAssignmentDerived>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CNonTrivialAssignmentDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialCopy>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialCopyInt>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialCopyBoth>::mc_Value						));
	
#ifndef DMibCompiler_GCC
	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialCopyDerived>::mc_Value						));
#endif
	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialCopyDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialConstruct>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialConstructDerived>::mc_Value						));
	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CNonTrivialConstructDerivedOverride>::mc_Value						));
	DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTrivial>::mc_Value						));

	DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CTestClassVirtual>::mc_Value						));

}

// Void
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestUnion>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<int>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestClass>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestC>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasTrivialDefaultConstructor<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CMPtr>::mc_Value							));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<void *>::mc_Value						));
DMibStaticCheck((	TCHasTrivialDefaultConstructor<void>::mc_Value							));

