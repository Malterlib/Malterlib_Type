// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#if 1
//ndef DMibCompiler_GCC
// POD definition changed for C++0x, lets not check this yet
// Void

// Special POD testing
DMibStaticCheck((	!TCIsPOD<CTestClassVirtual>::mc_Value					));
DMibStaticCheck((	!TCIsPOD<CTestClassWithDestructor>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithDestructorNonTrivial>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithConstructor>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithConstructorNonTrivial>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithCopyConstructor>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithCopyConstructorNonTrivial>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithMoveConstructor>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithMoveConstructorNonTrivial>::mc_Value			));
DMibStaticCheck((	TCIsPOD<CTestClassWithEnum>::mc_Value			));
DMibStaticCheck((	TCIsPOD<CTestClassWithPrivate>::mc_Value			));
DMibStaticCheck((	!TCIsPOD<CTestClassWithBase>::mc_Value			));


DMibStaticCheck((	TCIsPOD<CTestUnion>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestClass0>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestClass1>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestStruct0>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestStruct1>::mc_Value					));
DMibStaticCheck((	TCIsPOD<const CTestClass0>::mc_Value				));
DMibStaticCheck((	TCIsPOD<const CTestClass1>::mc_Value				));
DMibStaticCheck((	TCIsPOD<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	TCIsPOD<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	TCIsPOD<ETestEnum>::mc_Value						));
DMibStaticCheck((	TCIsPOD<int>::mc_Value							));
DMibStaticCheck((	TCIsPOD<CTestClass>::mc_Value							));
DMibStaticCheck((	TCIsPOD<CTestC>::mc_Value							));
DMibStaticCheck((	TCIsPOD<CTestPtr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<CTestCPtr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<CTestPtrC>::mc_Value						));
DMibStaticCheck((	TCIsPOD<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPOD<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsPOD<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsPOD<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsPOD<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CMPtr>::mc_Value							));
DMibStaticCheck((	TCIsPOD<CMCPtr>::mc_Value						));
DMibStaticCheck((	TCIsPOD<CMPtrC>::mc_Value						));
DMibStaticCheck((	TCIsPOD<CMCPtrC>::mc_Value						));
DMibStaticCheck((	TCIsPOD<CTestArray2>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestArray2C>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestArray>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTestArrayC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	TCIsPOD<CTest2DArray>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	TCIsPOD<CTest3DArray>::mc_Value					));
DMibStaticCheck((	TCIsPOD<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	TCIsPOD<void *>::mc_Value						));
DMibStaticCheck((	TCIsPOD<void>::mc_Value							));

#endif
