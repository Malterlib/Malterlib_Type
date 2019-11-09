// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"


// Object
DMibStaticCheck((	TCIsUnion<CTestUnion>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestStruct0>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestStruct1>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<ETestEnum>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestClass>::mc_Value				));
DMibStaticCheck((	!TCIsUnion<CTestC>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestPtr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestRef>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestCRef>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestRRef>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestCRRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<PFFunc0>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<PFFunc1>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<PFFunc2>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc0Ref>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc1Ref>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc2Ref>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc0RRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc1RRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc2RRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2Ptr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2PtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2CPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<PFFunc0El>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<PFFunc1El>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<PFFunc2El>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc0ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc1ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc2ElRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc0ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc1ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc2ElRRef>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<FFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2ElPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2ElPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc0ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc1ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<FMFunc2ElCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CMPtr>::mc_Value				));
DMibStaticCheck((	!TCIsUnion<CMCPtr>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CMPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CMCPtrC>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<CTestArray2>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestArray2C>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestArray>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTestArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTest2DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTest2DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsUnion<CTest2DArray>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTest2DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTest3DArray2>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTest3DArray2C>::mc_Value	));
DMibStaticCheck((	!TCIsUnion<CTest3DArray>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<CTest3DArrayC>::mc_Value		));
DMibStaticCheck((	!TCIsUnion<void *>::mc_Value			));
DMibStaticCheck((	!TCIsUnion<void>::mc_Value				));


