// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Test const qualifiers

DMibStaticCheck((	!TCIsConst<CTestClass>::mc_Value			));
DMibStaticCheck((	TCIsConst<CTestC>::mc_Value			));
DMibStaticCheck((	!TCIsConst<CTestV>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestCV>::mc_Value		));

DMibStaticCheck((	!TCIsConst<CTestRef>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCRef>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestVRef>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCVRef>::mc_Value	));

DMibStaticCheck((	!TCIsConst<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCRRef>::mc_Value	));
DMibStaticCheck((	!TCIsConst<CTestVRRef>::mc_Value	));
DMibStaticCheck((	!TCIsConst<CTestCVRRef>::mc_Value	));

DMibStaticCheck((	!TCIsConst<CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestCPtrV>::mc_Value	));
DMibStaticCheck((	TCIsConst<CTestCPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsConst<CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsConst<CTestVPtrC>::mc_Value		));
DMibStaticCheck((	!TCIsConst<CTestVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsConst<CTestVPtrCV>::mc_Value	));
DMibStaticCheck((	!TCIsConst<CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsConst<CTestCVPtrC>::mc_Value	));
DMibStaticCheck((	!TCIsConst<CTestCVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsConst<CTestCVPtrCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestClass>::CType, CTestClass>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestC>::CType, CTestClass>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestV>::CType, CTestV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCV>::CType, CTestV>::mc_Value			));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCRef>::CType, CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestVRef>::CType, CTestVRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCVRef>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestRRef>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCRRef>::CType, CTestCRRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestVRRef>::CType, CTestVRRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCVRRef>::CType, CTestCVRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestPtr>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestPtrC>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestPtrV>::CType, CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestPtrCV>::CType, CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCPtr>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCPtrC>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCPtrV>::CType, CTestCPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCPtrCV>::CType, CTestCPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestVPtr>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestVPtrC>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestVPtrV>::CType, CTestVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestVPtrCV>::CType, CTestVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCVPtr>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCVPtrC>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCVPtrV>::CType, CTestCVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveConst<CTestCVPtrCV>::CType, CTestCVPtrV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestC>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestV>::CType, CTestCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCV>::CType, CTestCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCRef>::CType, CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestVRef>::CType, CTestVRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCVRef>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestRRef>::CType, CTestRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCRRef>::CType, CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestVRRef>::CType, CTestVRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCVRRef>::CType, CTestCVRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCAddConst<CTestPtr>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestPtrC>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestPtrV>::CType, CTestPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestPtrCV>::CType, CTestPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCPtr>::CType, CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCPtrC>::CType, CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCPtrV>::CType, CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCPtrCV>::CType, CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestVPtr>::CType, CTestVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestVPtrC>::CType, CTestVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestVPtrV>::CType, CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestVPtrCV>::CType, CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCVPtr>::CType, CTestCVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCVPtrC>::CType, CTestCVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCVPtrV>::CType, CTestCVPtrCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddConst<CTestCVPtrCV>::CType, CTestCVPtrCV>::mc_Value	));
	

DMibStaticCheck((	TCIsSame<TCSetConst<CTestClass, 1>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestC, 1>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestV, 1>::CType, CTestCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCV, 1>::CType, CTestCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestRef, 1>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCRef, 1>::CType, CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVRef, 1>::CType, CTestVRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVRef, 1>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtr, 1>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrC, 1>::CType, CTestPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrV, 1>::CType, CTestPtrCV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrCV, 1>::CType, CTestPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtr, 1>::CType, CTestCPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrC, 1>::CType, CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrV, 1>::CType, CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrCV, 1>::CType, CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtr, 1>::CType, CTestVPtrC>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtrC, 1>::CType, CTestVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtrV, 1>::CType, CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtrCV, 1>::CType, CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtr, 1>::CType, CTestCVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtrC, 1>::CType, CTestCVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtrV, 1>::CType, CTestCVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtrCV, 1>::CType, CTestCVPtrCV>::mc_Value	));



DMibStaticCheck((	TCIsSame<TCSetConst<CTestClass, 0>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestC, 0>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestV, 0>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCV, 0>::CType, CTestV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestRef, 0>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCRef, 0>::CType, CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVRef, 0>::CType, CTestVRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVRef, 0>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestRRef, 0>::CType, CTestRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCRRef, 0>::CType, CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVRRef, 0>::CType, CTestVRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVRRef, 0>::CType, CTestCVRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtr, 0>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrC, 0>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrV, 0>::CType, CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestPtrCV, 0>::CType, CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtr, 0>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrC, 0>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrV, 0>::CType, CTestCPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCPtrCV, 0>::CType, CTestCPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtr, 0>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtrC, 0>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtrV, 0>::CType, CTestVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestVPtrCV, 0>::CType, CTestVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtr, 0>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtrC, 0>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtrV, 0>::CType, CTestCVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetConst<CTestCVPtrCV, 0>::CType, CTestCVPtrV>::mc_Value	));


DMibStaticCheck((	TCIsSame<TCCopyConst<CTestClass, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestC, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestV, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCV, CTestClass>::CType, CTestC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyConst<CTestRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestVRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCVRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyConst<CTestPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestPtrC, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestPtrV, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestPtrCV, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCPtrC, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCPtrV, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCPtrCV, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestVPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestVPtrC, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestVPtrV, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestVPtrCV, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCVPtr, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCVPtrC, CTestClass>::CType, CTestC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCVPtrV, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyConst<CTestCVPtrCV, CTestClass>::CType, CTestC>::mc_Value	));


// Test volatile qualifiers

DMibStaticCheck((	!TCIsVolatile<CTestClass>::mc_Value	));
DMibStaticCheck((	!TCIsVolatile<CTestC>::mc_Value	));
DMibStaticCheck((	TCIsVolatile<CTestV>::mc_Value	));
DMibStaticCheck((	TCIsVolatile<CTestCV>::mc_Value	));

DMibStaticCheck((	!TCIsVolatile<CTestRef>::mc_Value	));
DMibStaticCheck((	!TCIsVolatile<CTestCRef>::mc_Value	));
DMibStaticCheck((	!TCIsVolatile<CTestVRef>::mc_Value	));
DMibStaticCheck((	!TCIsVolatile<CTestCVRef>::mc_Value	));

DMibStaticCheck((	!TCIsVolatile<CTestRRef>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCRRef>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestVRRef>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCVRRef>::mc_Value	));

DMibStaticCheck((	!TCIsVolatile<CTestPtr>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCPtr>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestCPtrV>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCVPtr>::mc_Value		));
DMibStaticCheck((	!TCIsVolatile<CTestCVPtrC>::mc_Value	));
DMibStaticCheck((	TCIsVolatile<CTestCVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsVolatile<CTestCVPtrCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestC>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestV>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCV>::CType, CTestC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCRef>::CType, CTestCRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestVRef>::CType, CTestVRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCVRef>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestRRef>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCRRef>::CType, CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestVRRef>::CType, CTestVRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCVRRef>::CType, CTestCVRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestPtr>::CType, CTestPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestPtrC>::CType, CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestPtrV>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestPtrCV>::CType, CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCPtr>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCPtrC>::CType, CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCPtrV>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCPtrCV>::CType, CTestCPtrC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestVPtr>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestVPtrC>::CType, CTestVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestVPtrV>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestVPtrCV>::CType, CTestVPtrC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCVPtr>::CType, CTestCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCVPtrC>::CType, CTestCVPtrC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCVPtrV>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveVolatile<CTestCVPtrCV>::CType, CTestCVPtrC>::mc_Value	));


DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestC>::CType, CTestCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestV>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCV>::CType, CTestCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCRef>::CType, CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestVRef>::CType, CTestVRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCVRef>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestRRef>::CType, CTestRRef>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCRRef>::CType, CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestVRRef>::CType, CTestVRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCVRRef>::CType, CTestCVRRef>::mc_Value		));

DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestPtr>::CType, CTestPtrV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestPtrC>::CType, CTestPtrCV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestPtrV>::CType, CTestPtrV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestPtrCV>::CType, CTestPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCPtr>::CType, CTestCPtrV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCPtrC>::CType, CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCPtrV>::CType, CTestCPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCPtrCV>::CType, CTestCPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestVPtr>::CType, CTestVPtrV>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestVPtrC>::CType, CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestVPtrV>::CType, CTestVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestVPtrCV>::CType, CTestVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCVPtr>::CType, CTestCVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCVPtrC>::CType, CTestCVPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCVPtrV>::CType, CTestCVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCAddVolatile<CTestCVPtrCV>::CType, CTestCVPtrCV>::mc_Value	));


DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestClass, 1>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestC, 1>::CType, CTestCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestV, 1>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCV, 1>::CType, CTestCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRef, 1>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRef, 1>::CType, CTestCRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVRef, 1>::CType, CTestVRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVRef, 1>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRRef, 1>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRRef, 1>::CType, CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVRRef, 1>::CType, CTestVRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVRRef, 1>::CType, CTestCVRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtr, 1>::CType, CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrC, 1>::CType, CTestPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrV, 1>::CType, CTestPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrCV, 1>::CType, CTestPtrCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtr, 1>::CType, CTestCPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrC, 1>::CType, CTestCPtrCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrV, 1>::CType, CTestCPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrCV, 1>::CType, CTestCPtrCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtr, 1>::CType, CTestVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtrC, 1>::CType, CTestVPtrCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtrV, 1>::CType, CTestVPtrV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtrCV, 1>::CType, CTestVPtrCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtr, 1>::CType, CTestCVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtrC, 1>::CType, CTestCVPtrCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtrV, 1>::CType, CTestCVPtrV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtrCV, 1>::CType, CTestCVPtrCV>::mc_Value	));


DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestClass, 0>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestC, 0>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestV, 0>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCV, 0>::CType, CTestC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRef, 0>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRef, 0>::CType, CTestCRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVRef, 0>::CType, CTestVRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVRef, 0>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestRRef, 0>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCRRef, 0>::CType, CTestCRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVRRef, 0>::CType, CTestVRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVRRef, 0>::CType, CTestCVRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtr, 0>::CType, CTestPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrC, 0>::CType, CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrV, 0>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestPtrCV, 0>::CType, CTestPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtr, 0>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrC, 0>::CType, CTestCPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrV, 0>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCPtrCV, 0>::CType, CTestCPtrC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtr, 0>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtrC, 0>::CType, CTestVPtrC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtrV, 0>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestVPtrCV, 0>::CType, CTestVPtrC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtr, 0>::CType, CTestCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtrC, 0>::CType, CTestCVPtrC>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtrV, 0>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCSetVolatile<CTestCVPtrCV, 0>::CType, CTestCVPtrC>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestClass, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestC, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCV, CTestClass>::CType, CTestV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestVRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCVRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestRRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCRRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestVRRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCVRRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestPtrC, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestPtrV, CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestPtrCV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCPtrC, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCPtrV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCPtrCV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestVPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestVPtrC, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestVPtrV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestVPtrCV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCVPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCVPtrC, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCVPtrV, CTestClass>::CType, CTestV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyVolatile<CTestCVPtrCV, CTestClass>::CType, CTestV>::mc_Value	));

// Test dual qualifier operations

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestClass, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestC, CTestClass>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestV, CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCV, CTestClass>::CType, CTestCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestRef, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestVRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCVRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestRRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCRRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestVRRef, CTestClass>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCVRRef, CTestClass>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestPtr, CTestClass>::CType, CTestClass>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestPtrC, CTestClass>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestPtrV, CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestPtrCV, CTestClass>::CType, CTestCV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCPtrC, CTestClass>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCPtrV, CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCPtrCV, CTestClass>::CType, CTestCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestVPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestVPtrC, CTestClass>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestVPtrV, CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestVPtrCV, CTestClass>::CType, CTestCV>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCVPtr, CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCVPtrC, CTestClass>::CType, CTestC>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCVPtrV, CTestClass>::CType, CTestV>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCCopyQualifiers<CTestCVPtrCV, CTestClass>::CType, CTestCV>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestClass>::CType, CTestClass>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestC>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestV>::CType, CTestClass>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCV>::CType, CTestClass>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestRef>::CType, CTestRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCRef>::CType, CTestCRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestVRef>::CType, CTestVRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCVRef>::CType, CTestCVRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestRRef>::CType, CTestRRef>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCRRef>::CType, CTestCRRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestVRRef>::CType, CTestVRRef>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCVRRef>::CType, CTestCVRRef>::mc_Value	));

DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestPtr>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestPtrC>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestPtrV>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestPtrCV>::CType, CTestPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCPtr>::CType, CTestCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCPtrC>::CType, CTestCPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCPtrV>::CType, CTestCPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCPtrCV>::CType, CTestCPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestVPtr>::CType, CTestVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestVPtrC>::CType, CTestVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestVPtrV>::CType, CTestVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestVPtrCV>::CType, CTestVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCVPtr>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCVPtrC>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCVPtrV>::CType, CTestCVPtr>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestCVPtrCV>::CType, CTestCVPtr>::mc_Value	));


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
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0PtrV>::CType, FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1PtrV>::CType, FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2PtrV>::CType, FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0PtrCV>::CType, FFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1PtrCV>::CType, FFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2PtrCV>::CType, FFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0Ptr>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1Ptr>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2Ptr>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0PtrC>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1PtrC>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2PtrC>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0PtrV>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1PtrV>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2PtrV>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0PtrCV>::CType, FMFunc0Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1PtrCV>::CType, FMFunc1Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2PtrCV>::CType, FMFunc2Ptr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CPtr>::CType, FMFunc0CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CPtr>::CType, FMFunc1CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CPtr>::CType, FMFunc2CPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CPtrC>::CType, FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CPtrC>::CType, FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CPtrC>::CType, FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CPtrV>::CType, FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CPtrV>::CType, FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CPtrV>::CType, FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CPtrCV>::CType, FMFunc0CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CPtrCV>::CType, FMFunc1CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CPtrCV>::CType, FMFunc2CPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0VPtr>::CType, FMFunc0VPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1VPtr>::CType, FMFunc1VPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2VPtr>::CType, FMFunc2VPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0VPtrC>::CType, FMFunc0VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1VPtrC>::CType, FMFunc1VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2VPtrC>::CType, FMFunc2VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0VPtrV>::CType, FMFunc0VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1VPtrV>::CType, FMFunc1VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2VPtrV>::CType, FMFunc2VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0VPtrCV>::CType, FMFunc0VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1VPtrCV>::CType, FMFunc1VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2VPtrCV>::CType, FMFunc2VPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CVPtr>::CType, FMFunc0CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CVPtr>::CType, FMFunc1CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CVPtr>::CType, FMFunc2CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CVPtrC>::CType, FMFunc0CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CVPtrC>::CType, FMFunc1CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CVPtrC>::CType, FMFunc2CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CVPtrV>::CType, FMFunc0CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CVPtrV>::CType, FMFunc1CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CVPtrV>::CType, FMFunc2CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0CVPtrCV>::CType, FMFunc0CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1CVPtrCV>::CType, FMFunc1CVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2CVPtrCV>::CType, FMFunc2CVPtr>::mc_Value		));
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
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0ElPtrV>::CType, FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1ElPtrV>::CType, FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2ElPtrV>::CType, FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc0ElPtrCV>::CType, FFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc1ElPtrCV>::CType, FFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FFunc2ElPtrCV>::CType, FFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElPtr>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElPtr>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElPtr>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElPtrC>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElPtrC>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElPtrC>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElPtrV>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElPtrV>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElPtrV>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElPtrCV>::CType, FMFunc0ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElPtrCV>::CType, FMFunc1ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElPtrCV>::CType, FMFunc2ElPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCPtr>::CType, FMFunc0ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCPtr>::CType, FMFunc1ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCPtr>::CType, FMFunc2ElCPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCPtrC>::CType, FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCPtrC>::CType, FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCPtrC>::CType, FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCPtrV>::CType, FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCPtrV>::CType, FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCPtrV>::CType, FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCPtrCV>::CType, FMFunc0ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCPtrCV>::CType, FMFunc1ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCPtrCV>::CType, FMFunc2ElCPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElVPtr>::CType, FMFunc0ElVPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElVPtr>::CType, FMFunc1ElVPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElVPtr>::CType, FMFunc2ElVPtr>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElVPtrC>::CType, FMFunc0ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElVPtrC>::CType, FMFunc1ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElVPtrC>::CType, FMFunc2ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElVPtrV>::CType, FMFunc0ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElVPtrV>::CType, FMFunc1ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElVPtrV>::CType, FMFunc2ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElVPtrCV>::CType, FMFunc0ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElVPtrCV>::CType, FMFunc1ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElVPtrCV>::CType, FMFunc2ElVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCVPtr>::CType, FMFunc0ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCVPtr>::CType, FMFunc1ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCVPtr>::CType, FMFunc2ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCVPtrC>::CType, FMFunc0ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCVPtrC>::CType, FMFunc1ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCVPtrC>::CType, FMFunc2ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCVPtrV>::CType, FMFunc0ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCVPtrV>::CType, FMFunc1ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCVPtrV>::CType, FMFunc2ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc0ElCVPtrCV>::CType, FMFunc0ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc1ElCVPtrCV>::CType, FMFunc1ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<FMFunc2ElCVPtrCV>::CType, FMFunc2ElCVPtr>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMPtr>::CType, CMPtr>::mc_Value						));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCPtr>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMVPtr>::CType, CMVPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCVPtr>::CType, CMCVPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMPtrC>::CType, CMPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCPtrC>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMVPtrC>::CType, CMVPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCVPtrC>::CType, CMCVPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMPtrV>::CType, CMPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCPtrV>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMVPtrV>::CType, CMVPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCVPtrV>::CType, CMCVPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMPtrCV>::CType, CMPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCPtrCV>::CType, CMCPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMVPtrCV>::CType, CMVPtr>::mc_Value					));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CMCVPtrCV>::CType, CMCVPtr>::mc_Value				));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray2>::CType, CTestArray2>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray2C>::CType, CTestArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray2V>::CType, CTestArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray2CV>::CType, CTestArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArray>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArrayC>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArrayV>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTestArrayCV>::CType, CTestArray>::mc_Value			));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray2>::CType, CTest2DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray2C>::CType, CTest2DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray2V>::CType, CTest2DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray2CV>::CType, CTest2DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArray>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArrayC>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArrayV>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest2DArrayCV>::CType, CTest2DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray2>::CType, CTest3DArray2>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray2C>::CType, CTest3DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray2V>::CType, CTest3DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray2CV>::CType, CTest3DArray2>::mc_Value	));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArray>::CType, CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArrayC>::CType, CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArrayV>::CType, CTest3DArray>::mc_Value		));
DMibStaticCheck((	TCIsSame<TCRemoveQualifiers<CTest3DArrayCV>::CType, CTest3DArray>::mc_Value		));
