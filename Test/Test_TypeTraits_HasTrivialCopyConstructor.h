// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialAssignment>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialAssignmentInt>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialAssignmentBoth>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialAssignmentDerived>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialAssignmentDerivedOverride>);
	static_assert(cIsTriviallyCopyConstructible<CTrivial>);

	static_assert(!cIsTriviallyCopyConstructible<CNonTrivialCopy>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialCopyInt>);
	static_assert(!cIsTriviallyCopyConstructible<CNonTrivialCopyBoth>);
	static_assert(!cIsTriviallyCopyConstructible<CNonTrivialCopyDerived>);
	static_assert(!cIsTriviallyCopyConstructible<CNonTrivialCopyDerivedOverride>);
	static_assert(cIsTriviallyCopyConstructible<CTrivial>);

	static_assert(cIsTriviallyCopyConstructible<CNonTrivialConstruct>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialConstructDerived>);
	static_assert(cIsTriviallyCopyConstructible<CNonTrivialConstructDerivedOverride>);
	static_assert(cIsTriviallyCopyConstructible<CTrivial>);

	static_assert(!cIsTriviallyCopyConstructible<CTestClassVirtual>);
}

// Void
static_assert(cIsTriviallyCopyConstructible<CTestUnion>);
static_assert(cIsTriviallyCopyConstructible<CTestClass0>);
static_assert(cIsTriviallyCopyConstructible<CTestClass1>);
static_assert(cIsTriviallyCopyConstructible<CTestStruct0>);
static_assert(cIsTriviallyCopyConstructible<CTestStruct1>);
static_assert(cIsTriviallyCopyConstructible<const CTestClass0>);
static_assert(cIsTriviallyCopyConstructible<const CTestClass1>);
static_assert(cIsTriviallyCopyConstructible<const CTestStruct0>);
static_assert(cIsTriviallyCopyConstructible<const CTestStruct1>);
static_assert(cIsTriviallyCopyConstructible<ETestEnum>);
static_assert(cIsTriviallyCopyConstructible<int>);
static_assert(cIsTriviallyCopyConstructible<CTestClass>);
static_assert(cIsTriviallyCopyConstructible<CTestC>);
static_assert(cIsTriviallyCopyConstructible<CTestPtr>);
static_assert(cIsTriviallyCopyConstructible<CTestCPtr>);
static_assert(cIsTriviallyCopyConstructible<CTestPtrC>);
static_assert(cIsTriviallyCopyConstructible<CTestCPtrC>);
static_assert(cIsTriviallyCopyConstructible<CTestRef>);
static_assert(cIsTriviallyCopyConstructible<CTestCRef>);
static_assert(!cIsTriviallyCopyConstructible<CTestRRef>);
static_assert(!cIsTriviallyCopyConstructible<CTestCRRef>);
static_assert(!cIsTriviallyCopyConstructible<PFFunc0>);
static_assert(!cIsTriviallyCopyConstructible<PFFunc1>);
static_assert(!cIsTriviallyCopyConstructible<PFFunc2>);
static_assert(cIsTriviallyCopyConstructible<FFunc0Ref>);
static_assert(cIsTriviallyCopyConstructible<FFunc1Ref>);
static_assert(cIsTriviallyCopyConstructible<FFunc2Ref>);
static_assert(cIsTriviallyCopyConstructible<FFunc0RRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc1RRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc2RRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc0Ptr>);
static_assert(cIsTriviallyCopyConstructible<FFunc1Ptr>);
static_assert(cIsTriviallyCopyConstructible<FFunc2Ptr>);
static_assert(cIsTriviallyCopyConstructible<FFunc0PtrC>);
static_assert(cIsTriviallyCopyConstructible<FFunc1PtrC>);
static_assert(cIsTriviallyCopyConstructible<FFunc2PtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0Ptr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1Ptr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2Ptr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0PtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1PtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2PtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0CPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1CPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2CPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0CPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1CPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2CPtrC>);
static_assert(!cIsTriviallyCopyConstructible<PFFunc0El>);
static_assert(!cIsTriviallyCopyConstructible<PFFunc1El>);
static_assert(!cIsTriviallyCopyConstructible<PFFunc2El>);
static_assert(cIsTriviallyCopyConstructible<FFunc0ElRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc1ElRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc2ElRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc0ElRRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc1ElRRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc2ElRRef>);
static_assert(cIsTriviallyCopyConstructible<FFunc0ElPtr>);
static_assert(cIsTriviallyCopyConstructible<FFunc1ElPtr>);
static_assert(cIsTriviallyCopyConstructible<FFunc2ElPtr>);
static_assert(cIsTriviallyCopyConstructible<FFunc0ElPtrC>);
static_assert(cIsTriviallyCopyConstructible<FFunc1ElPtrC>);
static_assert(cIsTriviallyCopyConstructible<FFunc2ElPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0ElPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1ElPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2ElPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0ElPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1ElPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2ElPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0ElCPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1ElCPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2ElCPtr>);
static_assert(cIsTriviallyCopyConstructible<FMFunc0ElCPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc1ElCPtrC>);
static_assert(cIsTriviallyCopyConstructible<FMFunc2ElCPtrC>);
static_assert(cIsTriviallyCopyConstructible<CMPtr>);
static_assert(cIsTriviallyCopyConstructible<CMCPtr>);
static_assert(cIsTriviallyCopyConstructible<CMPtrC>);
static_assert(cIsTriviallyCopyConstructible<CMCPtrC>);
static_assert(!cIsTriviallyCopyConstructible<CTestArray2>);
static_assert(!cIsTriviallyCopyConstructible<CTestArray2C>);
static_assert(!cIsTriviallyCopyConstructible<CTestArray>);
static_assert(!cIsTriviallyCopyConstructible<CTestArrayC>);
static_assert(!cIsTriviallyCopyConstructible<CTest2DArray2>);
static_assert(!cIsTriviallyCopyConstructible<CTest2DArray2C>);
static_assert(!cIsTriviallyCopyConstructible<CTest2DArray>);
static_assert(!cIsTriviallyCopyConstructible<CTest2DArrayC>);
static_assert(!cIsTriviallyCopyConstructible<CTest3DArray2>);
static_assert(!cIsTriviallyCopyConstructible<CTest3DArray2C>);
static_assert(!cIsTriviallyCopyConstructible<CTest3DArray>);
static_assert(!cIsTriviallyCopyConstructible<CTest3DArrayC>);
static_assert(cIsTriviallyCopyConstructible<void *>);
static_assert(!cIsTriviallyCopyConstructible<void>);

