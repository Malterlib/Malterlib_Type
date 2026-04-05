// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{
	static_assert(!cIsTriviallyCopyAssignable<CNonTrivialAssignment>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialAssignmentInt>);
	static_assert(!cIsTriviallyCopyAssignable<CNonTrivialAssignmentBoth>);
#ifndef DCompiler_MSVC
	static_assert(!cIsTriviallyCopyAssignable<CNonTrivialAssignmentDerived>);
#endif
	static_assert(!cIsTriviallyCopyAssignable<CNonTrivialAssignmentDerivedOverride>);
	static_assert(cIsTriviallyCopyAssignable<CTrivial>);

	static_assert(cIsTriviallyCopyAssignable<CNonTrivialCopy>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialCopyInt>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialCopyBoth>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialCopyDerived>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialCopyDerivedOverride>);
	static_assert(cIsTriviallyCopyAssignable<CTrivial>);

	static_assert(cIsTriviallyCopyAssignable<CNonTrivialConstruct>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialConstructDerived>);
	static_assert(cIsTriviallyCopyAssignable<CNonTrivialConstructDerivedOverride>);
	static_assert(cIsTriviallyCopyAssignable<CTrivial>);

	static_assert(!cIsTriviallyCopyAssignable<CTestClassVirtual>);
}

// Void
static_assert(cIsTriviallyCopyAssignable<CTestUnion>);
static_assert(cIsTriviallyCopyAssignable<CTestClass0>);
static_assert(cIsTriviallyCopyAssignable<CTestClass1>);
static_assert(cIsTriviallyCopyAssignable<CTestStruct0>);
static_assert(cIsTriviallyCopyAssignable<CTestStruct1>);
static_assert(!cIsTriviallyCopyAssignable<const CTestClass0>);
static_assert(!cIsTriviallyCopyAssignable<const CTestClass1>);
static_assert(!cIsTriviallyCopyAssignable<const CTestStruct0>);
static_assert(!cIsTriviallyCopyAssignable<const CTestStruct1>);
static_assert(cIsTriviallyCopyAssignable<ETestEnum>);
static_assert(cIsTriviallyCopyAssignable<int>);
static_assert(cIsTriviallyCopyAssignable<CTestClass>);
static_assert(!cIsTriviallyCopyAssignable<CTestC>);
static_assert(cIsTriviallyCopyAssignable<CTestPtr>);
static_assert(cIsTriviallyCopyAssignable<CTestCPtr>);
static_assert(!cIsTriviallyCopyAssignable<CTestPtrC>);
static_assert(!cIsTriviallyCopyAssignable<CTestCPtrC>);
static_assert(cIsTriviallyCopyAssignable<CTestRef>);
static_assert(!cIsTriviallyCopyAssignable<CTestCRef>);
#ifndef DCompiler_MSVC
#endif
static_assert(cIsTriviallyCopyAssignable<CTestRRef>);
static_assert(!cIsTriviallyCopyAssignable<CTestCRRef>);
#ifndef DCompiler_MSVC
#endif
static_assert(!cIsTriviallyCopyAssignable<PFFunc0>);
static_assert(!cIsTriviallyCopyAssignable<PFFunc1>);
static_assert(!cIsTriviallyCopyAssignable<PFFunc2>);
static_assert(!cIsTriviallyCopyAssignable<FFunc0Ref>);
static_assert(!cIsTriviallyCopyAssignable<FFunc1Ref>);
static_assert(!cIsTriviallyCopyAssignable<FFunc2Ref>);
static_assert(!cIsTriviallyCopyAssignable<FFunc0RRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc1RRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc2RRef>);
static_assert(cIsTriviallyCopyAssignable<FFunc0Ptr>);
static_assert(cIsTriviallyCopyAssignable<FFunc1Ptr>);
static_assert(cIsTriviallyCopyAssignable<FFunc2Ptr>);
static_assert(!cIsTriviallyCopyAssignable<FFunc0PtrC>);
static_assert(!cIsTriviallyCopyAssignable<FFunc1PtrC>);
static_assert(!cIsTriviallyCopyAssignable<FFunc2PtrC>);
static_assert(cIsTriviallyCopyAssignable<FMFunc0Ptr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc1Ptr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc2Ptr>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc0PtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc1PtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc2PtrC>);
static_assert(cIsTriviallyCopyAssignable<FMFunc0CPtr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc1CPtr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc2CPtr>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc0CPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc1CPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc2CPtrC>);
static_assert(!cIsTriviallyCopyAssignable<PFFunc0El>);
static_assert(!cIsTriviallyCopyAssignable<PFFunc1El>);
static_assert(!cIsTriviallyCopyAssignable<PFFunc2El>);
static_assert(!cIsTriviallyCopyAssignable<FFunc0ElRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc1ElRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc2ElRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc0ElRRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc1ElRRef>);
static_assert(!cIsTriviallyCopyAssignable<FFunc2ElRRef>);
static_assert(cIsTriviallyCopyAssignable<FFunc0ElPtr>);
static_assert(cIsTriviallyCopyAssignable<FFunc1ElPtr>);
static_assert(cIsTriviallyCopyAssignable<FFunc2ElPtr>);
static_assert(!cIsTriviallyCopyAssignable<FFunc0ElPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FFunc1ElPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FFunc2ElPtrC>);
static_assert(cIsTriviallyCopyAssignable<FMFunc0ElPtr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc1ElPtr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc2ElPtr>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc0ElPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc1ElPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc2ElPtrC>);
static_assert(cIsTriviallyCopyAssignable<FMFunc0ElCPtr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc1ElCPtr>);
static_assert(cIsTriviallyCopyAssignable<FMFunc2ElCPtr>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc0ElCPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc1ElCPtrC>);
static_assert(!cIsTriviallyCopyAssignable<FMFunc2ElCPtrC>);
static_assert(cIsTriviallyCopyAssignable<CMPtr>);
static_assert(cIsTriviallyCopyAssignable<CMCPtr>);
static_assert(!cIsTriviallyCopyAssignable<CMPtrC>);
static_assert(!cIsTriviallyCopyAssignable<CMCPtrC>);
static_assert(!cIsTriviallyCopyAssignable<CTestArray2>);
static_assert(!cIsTriviallyCopyAssignable<CTestArray2C>);
static_assert(!cIsTriviallyCopyAssignable<CTestArray>);
static_assert(!cIsTriviallyCopyAssignable<CTestArrayC>);
static_assert(!cIsTriviallyCopyAssignable<CTest2DArray2>);
static_assert(!cIsTriviallyCopyAssignable<CTest2DArray2C>);
static_assert(!cIsTriviallyCopyAssignable<CTest2DArray>);
static_assert(!cIsTriviallyCopyAssignable<CTest2DArrayC>);
static_assert(!cIsTriviallyCopyAssignable<CTest3DArray2>);
static_assert(!cIsTriviallyCopyAssignable<CTest3DArray2C>);
static_assert(!cIsTriviallyCopyAssignable<CTest3DArray>);
static_assert(!cIsTriviallyCopyAssignable<CTest3DArrayC>);
static_assert(cIsTriviallyCopyAssignable<void *>);
static_assert(!cIsTriviallyCopyAssignable<void>);

