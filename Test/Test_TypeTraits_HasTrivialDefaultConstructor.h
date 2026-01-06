// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{
	static_assert(cIsTrivialllyDefaultConstructible<CNonTrivialAssignment>);
	static_assert(cIsTrivialllyDefaultConstructible<CNonTrivialAssignmentInt>);
	static_assert(cIsTrivialllyDefaultConstructible<CNonTrivialAssignmentBoth>);
	static_assert(cIsTrivialllyDefaultConstructible<CNonTrivialAssignmentDerived>);
	static_assert(cIsTrivialllyDefaultConstructible<CNonTrivialAssignmentDerivedOverride>);
	static_assert(cIsTrivialllyDefaultConstructible<CTrivial>);

	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialCopy>);
	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialCopyInt>);
	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialCopyBoth>);

	#ifndef DMibCompiler_GCC
	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialCopyDerived>);
	#endif
	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialCopyDerivedOverride>);
	static_assert(cIsTrivialllyDefaultConstructible<CTrivial>);

	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialConstruct>);
	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialConstructDerived>);
	static_assert(!cIsTrivialllyDefaultConstructible<CNonTrivialConstructDerivedOverride>);
	static_assert(cIsTrivialllyDefaultConstructible<CTrivial>);

	static_assert(!cIsTrivialllyDefaultConstructible<CTestClassVirtual>);
}

// Void
static_assert(cIsTrivialllyDefaultConstructible<CTestUnion>);
static_assert(cIsTrivialllyDefaultConstructible<CTestClass0>);
static_assert(cIsTrivialllyDefaultConstructible<CTestClass1>);
static_assert(cIsTrivialllyDefaultConstructible<CTestStruct0>);
static_assert(cIsTrivialllyDefaultConstructible<CTestStruct1>);
static_assert(cIsTrivialllyDefaultConstructible<const CTestClass0>);
static_assert(cIsTrivialllyDefaultConstructible<const CTestClass1>);
static_assert(cIsTrivialllyDefaultConstructible<const CTestStruct0>);
static_assert(cIsTrivialllyDefaultConstructible<const CTestStruct1>);
static_assert(cIsTrivialllyDefaultConstructible<ETestEnum>);
static_assert(cIsTrivialllyDefaultConstructible<int>);
static_assert(cIsTrivialllyDefaultConstructible<CTestClass>);
static_assert(cIsTrivialllyDefaultConstructible<CTestC>);
static_assert(cIsTrivialllyDefaultConstructible<CTestPtr>);
static_assert(cIsTrivialllyDefaultConstructible<CTestCPtr>);
static_assert(cIsTrivialllyDefaultConstructible<CTestPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<CTestCPtrC>);
static_assert(!cIsTrivialllyDefaultConstructible<CTestRef>);
static_assert(!cIsTrivialllyDefaultConstructible<CTestCRef>);
static_assert(!cIsTrivialllyDefaultConstructible<CTestRRef>);
static_assert(!cIsTrivialllyDefaultConstructible<CTestCRRef>);
static_assert(!cIsTrivialllyDefaultConstructible<PFFunc0>);
static_assert(!cIsTrivialllyDefaultConstructible<PFFunc1>);
static_assert(!cIsTrivialllyDefaultConstructible<PFFunc2>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc0Ref>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc1Ref>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc2Ref>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc0RRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc1RRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc2RRef>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc0Ptr>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc1Ptr>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc2Ptr>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc0PtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc1PtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc2PtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0Ptr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1Ptr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2Ptr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0PtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1PtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2PtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0CPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1CPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2CPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0CPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1CPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2CPtrC>);
static_assert(!cIsTrivialllyDefaultConstructible<PFFunc0El>);
static_assert(!cIsTrivialllyDefaultConstructible<PFFunc1El>);
static_assert(!cIsTrivialllyDefaultConstructible<PFFunc2El>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc0ElRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc1ElRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc2ElRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc0ElRRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc1ElRRef>);
static_assert(!cIsTrivialllyDefaultConstructible<FFunc2ElRRef>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc0ElPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc1ElPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc2ElPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc0ElPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc1ElPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FFunc2ElPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0ElPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1ElPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2ElPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0ElPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1ElPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2ElPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0ElCPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1ElCPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2ElCPtr>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc0ElCPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc1ElCPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<FMFunc2ElCPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<CMPtr>);
static_assert(cIsTrivialllyDefaultConstructible<CMCPtr>);
static_assert(cIsTrivialllyDefaultConstructible<CMPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<CMCPtrC>);
static_assert(cIsTrivialllyDefaultConstructible<CTestArray2>);
static_assert(cIsTrivialllyDefaultConstructible<CTestArray2C>);
static_assert(!cIsTrivialllyDefaultConstructible<CTestArray>);
static_assert(!cIsTrivialllyDefaultConstructible<CTestArrayC>);
static_assert(cIsTrivialllyDefaultConstructible<CTest2DArray2>);
static_assert(cIsTrivialllyDefaultConstructible<CTest2DArray2C>);
static_assert(!cIsTrivialllyDefaultConstructible<CTest2DArray>);
static_assert(!cIsTrivialllyDefaultConstructible<CTest2DArrayC>);
static_assert(cIsTrivialllyDefaultConstructible<CTest3DArray2>);
static_assert(cIsTrivialllyDefaultConstructible<CTest3DArray2C>);
static_assert(!cIsTrivialllyDefaultConstructible<CTest3DArray>);
static_assert(!cIsTrivialllyDefaultConstructible<CTest3DArrayC>);
static_assert(cIsTrivialllyDefaultConstructible<void *>);
static_assert(!cIsTrivialllyDefaultConstructible<void>);

