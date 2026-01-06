// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NNothrow
{
	static_assert(cIsNothrowCopyConstructible<CThrowsAssignment>);
	static_assert(cIsNothrowCopyConstructible<CThrowsAssignmentInt>);
	static_assert(cIsNothrowCopyConstructible<CThrowsAssignmentBoth>);
	static_assert(cIsNothrowCopyConstructible<CThrowsAssignmentDerived>);
	static_assert(cIsNothrowCopyConstructible<CThrowsAssignmentDerivedOverride>);
	static_assert(cIsNothrowCopyConstructible<CNothrow>);

	static_assert(!cIsNothrowCopyConstructible<CThrowsCopy>);
	static_assert(cIsNothrowCopyConstructible<CThrowsCopyInt>);
	static_assert(!cIsNothrowCopyConstructible<CThrowsCopyBoth>);
#ifndef DMibCompiler_GCC
	static_assert(!cIsNothrowCopyConstructible<CThrowsCopyDerived>);
#endif
	static_assert(cIsNothrowCopyConstructible<CThrowsCopyDerivedOverride>);
	static_assert(cIsNothrowCopyConstructible<CNothrow>);

	static_assert(cIsNothrowCopyConstructible<CThrowsConstruct>);
	static_assert(cIsNothrowCopyConstructible<CThrowsConstructDerived>);
	static_assert(cIsNothrowCopyConstructible<CThrowsConstructDerivedOverride>);
	static_assert(cIsNothrowCopyConstructible<CNothrow>);

	static_assert(cIsNothrowCopyConstructible<CTestClassVirtual>);
}

// Void
static_assert(cIsNothrowCopyConstructible<CTestUnion>);
static_assert(cIsNothrowCopyConstructible<CTestClass0>);
static_assert(cIsNothrowCopyConstructible<CTestClass1>);
static_assert(cIsNothrowCopyConstructible<CTestStruct0>);
static_assert(cIsNothrowCopyConstructible<CTestStruct1>);
static_assert(cIsNothrowCopyConstructible<const CTestClass0>);
static_assert(cIsNothrowCopyConstructible<const CTestClass1>);
static_assert(cIsNothrowCopyConstructible<const CTestStruct0>);
static_assert(cIsNothrowCopyConstructible<const CTestStruct1>);
static_assert(cIsNothrowCopyConstructible<ETestEnum>);
static_assert(cIsNothrowCopyConstructible<int>);
static_assert(cIsNothrowCopyConstructible<CTestClass>);
static_assert(cIsNothrowCopyConstructible<CTestC>);
static_assert(cIsNothrowCopyConstructible<CTestPtr>);
static_assert(cIsNothrowCopyConstructible<CTestCPtr>);
static_assert(cIsNothrowCopyConstructible<CTestPtrC>);
static_assert(cIsNothrowCopyConstructible<CTestCPtrC>);
static_assert(cIsNothrowCopyConstructible<CTestRef>);
static_assert(cIsNothrowCopyConstructible<CTestCRef>);
static_assert(!cIsNothrowCopyConstructible<CTestRRef>);
static_assert(!cIsNothrowCopyConstructible<CTestCRRef>);
static_assert(!cIsNothrowCopyConstructible<PFFunc0>);
static_assert(!cIsNothrowCopyConstructible<PFFunc1>);
static_assert(!cIsNothrowCopyConstructible<PFFunc2>);
static_assert(cIsNothrowCopyConstructible<FFunc0Ref>);
static_assert(cIsNothrowCopyConstructible<FFunc1Ref>);
static_assert(cIsNothrowCopyConstructible<FFunc2Ref>);
static_assert(cIsNothrowCopyConstructible<FFunc0RRef>);
static_assert(cIsNothrowCopyConstructible<FFunc1RRef>);
static_assert(cIsNothrowCopyConstructible<FFunc2RRef>);
static_assert(cIsNothrowCopyConstructible<FFunc0Ptr>);
static_assert(cIsNothrowCopyConstructible<FFunc1Ptr>);
static_assert(cIsNothrowCopyConstructible<FFunc2Ptr>);
static_assert(cIsNothrowCopyConstructible<FFunc0PtrC>);
static_assert(cIsNothrowCopyConstructible<FFunc1PtrC>);
static_assert(cIsNothrowCopyConstructible<FFunc2PtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc0Ptr>);
static_assert(cIsNothrowCopyConstructible<FMFunc1Ptr>);
static_assert(cIsNothrowCopyConstructible<FMFunc2Ptr>);
static_assert(cIsNothrowCopyConstructible<FMFunc0PtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc1PtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc2PtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc0CPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc1CPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc2CPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc0CPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc1CPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc2CPtrC>);
static_assert(!cIsNothrowCopyConstructible<PFFunc0El>);
static_assert(!cIsNothrowCopyConstructible<PFFunc1El>);
static_assert(!cIsNothrowCopyConstructible<PFFunc2El>);
static_assert(cIsNothrowCopyConstructible<FFunc0ElRef>);
static_assert(cIsNothrowCopyConstructible<FFunc1ElRef>);
static_assert(cIsNothrowCopyConstructible<FFunc2ElRef>);
static_assert(cIsNothrowCopyConstructible<FFunc0ElRRef>);
static_assert(cIsNothrowCopyConstructible<FFunc1ElRRef>);
static_assert(cIsNothrowCopyConstructible<FFunc2ElRRef>);
static_assert(cIsNothrowCopyConstructible<FFunc0ElPtr>);
static_assert(cIsNothrowCopyConstructible<FFunc1ElPtr>);
static_assert(cIsNothrowCopyConstructible<FFunc2ElPtr>);
static_assert(cIsNothrowCopyConstructible<FFunc0ElPtrC>);
static_assert(cIsNothrowCopyConstructible<FFunc1ElPtrC>);
static_assert(cIsNothrowCopyConstructible<FFunc2ElPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc0ElPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc1ElPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc2ElPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc0ElPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc1ElPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc2ElPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc0ElCPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc1ElCPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc2ElCPtr>);
static_assert(cIsNothrowCopyConstructible<FMFunc0ElCPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc1ElCPtrC>);
static_assert(cIsNothrowCopyConstructible<FMFunc2ElCPtrC>);
static_assert(cIsNothrowCopyConstructible<CMPtr>);
static_assert(cIsNothrowCopyConstructible<CMCPtr>);
static_assert(cIsNothrowCopyConstructible<CMPtrC>);
static_assert(cIsNothrowCopyConstructible<CMCPtrC>);
static_assert(!cIsNothrowCopyConstructible<CTestArray2>);
static_assert(!cIsNothrowCopyConstructible<CTestArray2C>);
static_assert(!cIsNothrowCopyConstructible<CTestArray>);
static_assert(!cIsNothrowCopyConstructible<CTestArrayC>);
static_assert(!cIsNothrowCopyConstructible<CTest2DArray2>);
static_assert(!cIsNothrowCopyConstructible<CTest2DArray2C>);
static_assert(!cIsNothrowCopyConstructible<CTest2DArray>);
static_assert(!cIsNothrowCopyConstructible<CTest2DArrayC>);
static_assert(!cIsNothrowCopyConstructible<CTest3DArray2>);
static_assert(!cIsNothrowCopyConstructible<CTest3DArray2C>);
static_assert(!cIsNothrowCopyConstructible<CTest3DArray>);
static_assert(!cIsNothrowCopyConstructible<CTest3DArrayC>);
static_assert(cIsNothrowCopyConstructible<void *>);
static_assert(!cIsNothrowCopyConstructible<void>);

