// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NNothrow
{
	static_assert(!cIsNothrowCopyAssignable<CThrowsAssignment>);
	static_assert(cIsNothrowCopyAssignable<CThrowsAssignmentInt>);
	static_assert(!cIsNothrowCopyAssignable<CThrowsAssignmentBoth>);
#ifndef DMibCompiler_GCC
	static_assert(!cIsNothrowCopyAssignable<CThrowsAssignmentDerived>);
#endif
	static_assert(cIsNothrowCopyAssignable<CThrowsAssignmentDerivedOverride>);
	static_assert(cIsNothrowCopyAssignable<CNothrow>);

	static_assert(cIsNothrowCopyAssignable<CThrowsCopy>);
	static_assert(cIsNothrowCopyAssignable<CThrowsCopyInt>);
	static_assert(cIsNothrowCopyAssignable<CThrowsCopyBoth>);
	static_assert(cIsNothrowCopyAssignable<CThrowsCopyDerived>);
	static_assert(cIsNothrowCopyAssignable<CThrowsCopyDerivedOverride>);
	static_assert(cIsNothrowCopyAssignable<CNothrow>);

	static_assert(cIsNothrowCopyAssignable<CThrowsConstruct>);
	static_assert(cIsNothrowCopyAssignable<CThrowsConstructDerived>);
	static_assert(cIsNothrowCopyAssignable<CThrowsConstructDerivedOverride>);
	static_assert(cIsNothrowCopyAssignable<CNothrow>);

	static_assert(cIsNothrowCopyAssignable<CTestClassVirtual>);
}

// Void
static_assert(cIsNothrowCopyAssignable<CTestUnion>);
static_assert(cIsNothrowCopyAssignable<CTestClass0>);
static_assert(cIsNothrowCopyAssignable<CTestClass1>);
static_assert(cIsNothrowCopyAssignable<CTestStruct0>);
static_assert(cIsNothrowCopyAssignable<CTestStruct1>);
static_assert(!cIsNothrowCopyAssignable<const CTestClass0>);
static_assert(!cIsNothrowCopyAssignable<const CTestClass1>);
static_assert(!cIsNothrowCopyAssignable<const CTestStruct0>);
static_assert(!cIsNothrowCopyAssignable<const CTestStruct1>);
static_assert(cIsNothrowCopyAssignable<ETestEnum>);
static_assert(cIsNothrowCopyAssignable<int>);
static_assert(cIsNothrowCopyAssignable<CTestClass>);
static_assert(!cIsNothrowCopyAssignable<CTestC>);
static_assert(cIsNothrowCopyAssignable<CTestPtr>);
static_assert(cIsNothrowCopyAssignable<CTestCPtr>);
static_assert(!cIsNothrowCopyAssignable<CTestPtrC>);
static_assert(!cIsNothrowCopyAssignable<CTestCPtrC>);
static_assert(cIsNothrowCopyAssignable<CTestBase>);
static_assert(cIsNothrowCopyAssignable<CTestRef>);
static_assert(!cIsNothrowCopyAssignable<CTestCRef>);
static_assert(cIsNothrowCopyAssignable<CTestRRef>);
static_assert(!cIsNothrowCopyAssignable<CTestCRRef>);
static_assert(!cIsNothrowCopyAssignable<PFFunc0>);
static_assert(!cIsNothrowCopyAssignable<PFFunc1>);
static_assert(!cIsNothrowCopyAssignable<PFFunc2>);
static_assert(!cIsNothrowCopyAssignable<FFunc0Ref>);
static_assert(!cIsNothrowCopyAssignable<FFunc1Ref>);
static_assert(!cIsNothrowCopyAssignable<FFunc2Ref>);
static_assert(!cIsNothrowCopyAssignable<FFunc0RRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc1RRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc2RRef>);
static_assert(cIsNothrowCopyAssignable<FFunc0Ptr>);
static_assert(cIsNothrowCopyAssignable<FFunc1Ptr>);
static_assert(cIsNothrowCopyAssignable<FFunc2Ptr>);
static_assert(!cIsNothrowCopyAssignable<FFunc0PtrC>);
static_assert(!cIsNothrowCopyAssignable<FFunc1PtrC>);
static_assert(!cIsNothrowCopyAssignable<FFunc2PtrC>);
static_assert(cIsNothrowCopyAssignable<FMFunc0Ptr>);
static_assert(cIsNothrowCopyAssignable<FMFunc1Ptr>);
static_assert(cIsNothrowCopyAssignable<FMFunc2Ptr>);
static_assert(!cIsNothrowCopyAssignable<FMFunc0PtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc1PtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc2PtrC>);
static_assert(cIsNothrowCopyAssignable<FMFunc0CPtr>);
static_assert(cIsNothrowCopyAssignable<FMFunc1CPtr>);
static_assert(cIsNothrowCopyAssignable<FMFunc2CPtr>);
static_assert(!cIsNothrowCopyAssignable<FMFunc0CPtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc1CPtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc2CPtrC>);
static_assert(!cIsNothrowCopyAssignable<PFFunc0El>);
static_assert(!cIsNothrowCopyAssignable<PFFunc1El>);
static_assert(!cIsNothrowCopyAssignable<PFFunc2El>);
static_assert(!cIsNothrowCopyAssignable<FFunc0ElRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc1ElRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc2ElRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc0ElRRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc1ElRRef>);
static_assert(!cIsNothrowCopyAssignable<FFunc2ElRRef>);
static_assert(cIsNothrowCopyAssignable<FFunc0ElPtr>);
static_assert(cIsNothrowCopyAssignable<FFunc1ElPtr>);
static_assert(cIsNothrowCopyAssignable<FFunc2ElPtr>);
static_assert(!cIsNothrowCopyAssignable<FFunc0ElPtrC>);
static_assert(!cIsNothrowCopyAssignable<FFunc1ElPtrC>);
static_assert(!cIsNothrowCopyAssignable<FFunc2ElPtrC>);
static_assert(cIsNothrowCopyAssignable<FMFunc0ElPtr>);
static_assert(cIsNothrowCopyAssignable<FMFunc1ElPtr>);
static_assert(cIsNothrowCopyAssignable<FMFunc2ElPtr>);
static_assert(!cIsNothrowCopyAssignable<FMFunc0ElPtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc1ElPtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc2ElPtrC>);
static_assert(cIsNothrowCopyAssignable<FMFunc0ElCPtr>);
static_assert(cIsNothrowCopyAssignable<FMFunc1ElCPtr>);
static_assert(cIsNothrowCopyAssignable<FMFunc2ElCPtr>);
static_assert(!cIsNothrowCopyAssignable<FMFunc0ElCPtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc1ElCPtrC>);
static_assert(!cIsNothrowCopyAssignable<FMFunc2ElCPtrC>);
static_assert(cIsNothrowCopyAssignable<CMPtr>);
static_assert(cIsNothrowCopyAssignable<CMCPtr>);
static_assert(!cIsNothrowCopyAssignable<CMPtrC>);
static_assert(!cIsNothrowCopyAssignable<CMCPtrC>);
static_assert(!cIsNothrowCopyAssignable<CTestArray2>);
static_assert(!cIsNothrowCopyAssignable<CTestArray2C>);
static_assert(!cIsNothrowCopyAssignable<CTestArray>);
static_assert(!cIsNothrowCopyAssignable<CTestArrayC>);
static_assert(!cIsNothrowCopyAssignable<CTest2DArray2>);
static_assert(!cIsNothrowCopyAssignable<CTest2DArray2C>);
static_assert(!cIsNothrowCopyAssignable<CTest2DArray>);
static_assert(!cIsNothrowCopyAssignable<CTest2DArrayC>);
static_assert(!cIsNothrowCopyAssignable<CTest3DArray2>);
static_assert(!cIsNothrowCopyAssignable<CTest3DArray2C>);
static_assert(!cIsNothrowCopyAssignable<CTest3DArray>);
static_assert(!cIsNothrowCopyAssignable<CTest3DArrayC>);
static_assert(cIsNothrowCopyAssignable<void *>);
static_assert(!cIsNothrowCopyAssignable<void>);

