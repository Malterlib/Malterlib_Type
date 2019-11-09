// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Test const qualifiers

DMibStaticCheck((	!TCIsConst<CTestClass>::mc_Value			));
DMibStaticCheck((	TCIsConst<CTestC>::mc_Value			));

DMibStaticCheck((	!TCIsConst<CTestRef>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCRef>::mc_Value		));

DMibStaticCheck((	!TCIsConst<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCRRef>::mc_Value	));

DMibStaticCheck((	!TCIsConst<CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestCPtrC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestClass>::CType, CTestClass>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestC>::CType, CTestClass>::mc_Value				));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCRef>::CType, CTestCRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestRRef>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCRRef>::CType, CTestCRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestPtr>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestPtrC>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCPtr>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCPtrC>::CType, CTestCPtr>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestC>::CType, CTestC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCRef>::CType, CTestCRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestRRef>::CType, CTestRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCRRef>::CType, CTestCRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestPtr>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestPtrC>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCPtr>::CType, CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCPtrC>::CType, CTestCPtrC>::mc_Value		));
	

DMibStaticCheck((	TCIsSame<TCSetConst<CTestClass, 1>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestC, 1>::CType, CTestC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestRef, 1>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCRef, 1>::CType, CTestCRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtr, 1>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrC, 1>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtr, 1>::CType, CTestCPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrC, 1>::CType, CTestCPtrC>::mc_Value		));



DMibStaticCheck((	TCIsSame<TCSetConst<CTestClass, 0>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestC, 0>::CType, CTestClass>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestRef, 0>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCRef, 0>::CType, CTestCRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestRRef, 0>::CType, CTestRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCRRef, 0>::CType, CTestCRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtr, 0>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrC, 0>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtr, 0>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrC, 0>::CType, CTestCPtr>::mc_Value		));


DMibStaticCheck((	TCIsSame<TCCopyConst<CTestClass, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestC, CTestClass>::CType, CTestC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyConst<CTestRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCRef, CTestClass>::CType, CTestClass>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCCopyConst<CTestPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestPtrC, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCPtrC, CTestClass>::CType, CTestC>::mc_Value	));

// Test volatile qualifiers

DMibStaticCheck((	!TCIsVolatile<CTestClass>::mc_Value	));
DMibStaticCheck((	!TCIsVolatile<CTestC>::mc_Value	));

DMibStaticCheck((	!TCIsVolatile<CTestRef>::mc_Value	));
DMibStaticCheck((	!TCIsVolatile<CTestCRef>::mc_Value	));

DMibStaticCheck((	!TCIsVolatile<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCRRef>::mc_Value		));

DMibStaticCheck((	!TCIsVolatile<CTestPtr>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCPtrC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestC>::CType, CTestC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCRef>::CType, CTestCRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestRRef>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCRRef>::CType, CTestCRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestPtr>::CType, CTestPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestPtrC>::CType, CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCPtr>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCPtrC>::CType, CTestCPtrC>::mc_Value		));



DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCRef>::CType, CTestCRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestRRef>::CType, CTestRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCRRef>::CType, CTestCRRef>::mc_Value		));




DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRef, 1>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRef, 1>::CType, CTestCRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRRef, 1>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRRef, 1>::CType, CTestCRRef>::mc_Value		));



DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestClass, 0>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestC, 0>::CType, CTestC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRef, 0>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRef, 0>::CType, CTestCRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRRef, 0>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRRef, 0>::CType, CTestCRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtr, 0>::CType, CTestPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrC, 0>::CType, CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtr, 0>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrC, 0>::CType, CTestCPtrC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestClass, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestC, CTestClass>::CType, CTestClass>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestRRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCRRef, CTestClass>::CType, CTestClass>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestPtrC, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCPtrC, CTestClass>::CType, CTestClass>::mc_Value		));

// Test dual qualifier operations

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestClass, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestC, CTestClass>::CType, CTestC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestRRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCRRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestPtr, CTestClass>::CType, CTestClass>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestPtrC, CTestClass>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCPtrC, CTestClass>::CType, CTestC>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestC>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCRef>::CType, CTestCRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestRRef>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCRRef>::CType, CTestCRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestPtr>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestPtrC>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCPtr>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCPtrC>::CType, CTestCPtr>::mc_Value	));


DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<PFFunc0>::CType, PFFunc0>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<PFFunc1>::CType, PFFunc1>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<PFFunc2>::CType, PFFunc2>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0Ref>::CType, FFunc0Ref>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1Ref>::CType, FFunc1Ref>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2Ref>::CType, FFunc2Ref>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0RRef>::CType, FFunc0RRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1RRef>::CType, FFunc1RRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2RRef>::CType, FFunc2RRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0Ptr>::CType, FFunc0Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1Ptr>::CType, FFunc1Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2Ptr>::CType, FFunc2Ptr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0PtrC>::CType, FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1PtrC>::CType, FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2PtrC>::CType, FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0Ptr>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1Ptr>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2Ptr>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0PtrC>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1PtrC>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2PtrC>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CPtr>::CType, FMFunc0CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CPtr>::CType, FMFunc1CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CPtr>::CType, FMFunc2CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CPtrC>::CType, FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CPtrC>::CType, FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CPtrC>::CType, FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<PFFunc0El>::CType, PFFunc0El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<PFFunc1El>::CType, PFFunc1El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<PFFunc2El>::CType, PFFunc2El>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0ElRef>::CType, FFunc0ElRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1ElRef>::CType, FFunc1ElRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2ElRef>::CType, FFunc2ElRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0ElRRef>::CType, FFunc0ElRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1ElRRef>::CType, FFunc1ElRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2ElRRef>::CType, FFunc2ElRRef>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0ElPtr>::CType, FFunc0ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1ElPtr>::CType, FFunc1ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2ElPtr>::CType, FFunc2ElPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0ElPtrC>::CType, FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1ElPtrC>::CType, FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2ElPtrC>::CType, FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElPtr>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElPtr>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElPtr>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElPtrC>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElPtrC>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElPtrC>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCPtr>::CType, FMFunc0ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCPtr>::CType, FMFunc1ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCPtr>::CType, FMFunc2ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCPtrC>::CType, FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCPtrC>::CType, FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCPtrC>::CType, FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMPtr>::CType, CMPtr>::mc_Value						));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCPtr>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMPtrC>::CType, CMPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCPtrC>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray2>::CType, CTestArray2>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray2C>::CType, CTestArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArrayC>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray2>::CType, CTest2DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray2C>::CType, CTest2DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArrayC>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray2>::CType, CTest3DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray2C>::CType, CTest3DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray>::CType, CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArrayC>::CType, CTest3DArray>::mc_Value		));
