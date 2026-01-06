// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

namespace NTrivial
{
	static_assert(cIsTriviallyDestructible<CNonTrivialAssignment>);
	static_assert(cIsTriviallyDestructible<CNonTrivialAssignmentInt>);
	static_assert(cIsTriviallyDestructible<CNonTrivialAssignmentBoth>);
	static_assert(cIsTriviallyDestructible<CNonTrivialAssignmentDerived>);
	static_assert(cIsTriviallyDestructible<CNonTrivialAssignmentDerivedOverride>);
	static_assert(cIsTriviallyDestructible<CTrivial>);

	static_assert(cIsTriviallyDestructible<CNonTrivialCopy>);
	static_assert(cIsTriviallyDestructible<CNonTrivialCopyInt>);
	static_assert(cIsTriviallyDestructible<CNonTrivialCopyBoth>);
	static_assert(cIsTriviallyDestructible<CNonTrivialCopyDerived>);
	static_assert(cIsTriviallyDestructible<CNonTrivialCopyDerivedOverride>);
	static_assert(cIsTriviallyDestructible<CTrivial>);

	static_assert(cIsTriviallyDestructible<CNonTrivialConstruct>);
	static_assert(cIsTriviallyDestructible<CNonTrivialConstructDerived>);
	static_assert(cIsTriviallyDestructible<CNonTrivialConstructDerivedOverride>);
	static_assert(cIsTriviallyDestructible<CTrivial>);

	static_assert(cIsTriviallyDestructible<CTestClassVirtual>);
	static_assert(!cIsTriviallyDestructible<CTestClassWithDestructor>);
}


// Void
static_assert(cIsTriviallyDestructible<CTestUnion>);
static_assert(cIsTriviallyDestructible<CTestClass0>);
static_assert(cIsTriviallyDestructible<CTestClass1>);
static_assert(cIsTriviallyDestructible<CTestStruct0>);
static_assert(cIsTriviallyDestructible<CTestStruct1>);
static_assert(cIsTriviallyDestructible<const CTestClass0>);
static_assert(cIsTriviallyDestructible<const CTestClass1>);
static_assert(cIsTriviallyDestructible<const CTestStruct0>);
static_assert(cIsTriviallyDestructible<const CTestStruct1>);
static_assert(cIsTriviallyDestructible<ETestEnum>);
static_assert(cIsTriviallyDestructible<int>);
static_assert(cIsTriviallyDestructible<CTestClass>);
static_assert(cIsTriviallyDestructible<CTestC>);
static_assert(cIsTriviallyDestructible<CTestPtr>);
static_assert(cIsTriviallyDestructible<CTestCPtr>);
static_assert(cIsTriviallyDestructible<CTestPtrC>);
static_assert(cIsTriviallyDestructible<CTestCPtrC>);
static_assert(cIsTriviallyDestructible<CTestRef>);
static_assert(cIsTriviallyDestructible<CTestCRef>);
static_assert(cIsTriviallyDestructible<CTestRRef>);
static_assert(cIsTriviallyDestructible<CTestCRRef>);
static_assert(!cIsTriviallyDestructible<PFFunc0>);
static_assert(!cIsTriviallyDestructible<PFFunc1>);
static_assert(!cIsTriviallyDestructible<PFFunc2>);
static_assert(cIsTriviallyDestructible<FFunc0Ref>);
static_assert(cIsTriviallyDestructible<FFunc1Ref>);
static_assert(cIsTriviallyDestructible<FFunc2Ref>);
static_assert(cIsTriviallyDestructible<FFunc0RRef>);
static_assert(cIsTriviallyDestructible<FFunc1RRef>);
static_assert(cIsTriviallyDestructible<FFunc2RRef>);
static_assert(cIsTriviallyDestructible<FFunc0Ptr>);
static_assert(cIsTriviallyDestructible<FFunc1Ptr>);
static_assert(cIsTriviallyDestructible<FFunc2Ptr>);
static_assert(cIsTriviallyDestructible<FFunc0PtrC>);
static_assert(cIsTriviallyDestructible<FFunc1PtrC>);
static_assert(cIsTriviallyDestructible<FFunc2PtrC>);
static_assert(cIsTriviallyDestructible<FMFunc0Ptr>);
static_assert(cIsTriviallyDestructible<FMFunc1Ptr>);
static_assert(cIsTriviallyDestructible<FMFunc2Ptr>);
static_assert(cIsTriviallyDestructible<FMFunc0PtrC>);
static_assert(cIsTriviallyDestructible<FMFunc1PtrC>);
static_assert(cIsTriviallyDestructible<FMFunc2PtrC>);
static_assert(cIsTriviallyDestructible<FMFunc0CPtr>);
static_assert(cIsTriviallyDestructible<FMFunc1CPtr>);
static_assert(cIsTriviallyDestructible<FMFunc2CPtr>);
static_assert(cIsTriviallyDestructible<FMFunc0CPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc1CPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc2CPtrC>);
static_assert(!cIsTriviallyDestructible<PFFunc0El>);
static_assert(!cIsTriviallyDestructible<PFFunc1El>);
static_assert(!cIsTriviallyDestructible<PFFunc2El>);
static_assert(cIsTriviallyDestructible<FFunc0ElRef>);
static_assert(cIsTriviallyDestructible<FFunc1ElRef>);
static_assert(cIsTriviallyDestructible<FFunc2ElRef>);
static_assert(cIsTriviallyDestructible<FFunc0ElRRef>);
static_assert(cIsTriviallyDestructible<FFunc1ElRRef>);
static_assert(cIsTriviallyDestructible<FFunc2ElRRef>);
static_assert(cIsTriviallyDestructible<FFunc0ElPtr>);
static_assert(cIsTriviallyDestructible<FFunc1ElPtr>);
static_assert(cIsTriviallyDestructible<FFunc2ElPtr>);
static_assert(cIsTriviallyDestructible<FFunc0ElPtrC>);
static_assert(cIsTriviallyDestructible<FFunc1ElPtrC>);
static_assert(cIsTriviallyDestructible<FFunc2ElPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc0ElPtr>);
static_assert(cIsTriviallyDestructible<FMFunc1ElPtr>);
static_assert(cIsTriviallyDestructible<FMFunc2ElPtr>);
static_assert(cIsTriviallyDestructible<FMFunc0ElPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc1ElPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc2ElPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc0ElCPtr>);
static_assert(cIsTriviallyDestructible<FMFunc1ElCPtr>);
static_assert(cIsTriviallyDestructible<FMFunc2ElCPtr>);
static_assert(cIsTriviallyDestructible<FMFunc0ElCPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc1ElCPtrC>);
static_assert(cIsTriviallyDestructible<FMFunc2ElCPtrC>);
static_assert(cIsTriviallyDestructible<CMPtr>);
static_assert(cIsTriviallyDestructible<CMCPtr>);
static_assert(cIsTriviallyDestructible<CMPtrC>);
static_assert(cIsTriviallyDestructible<CMCPtrC>);
static_assert(cIsTriviallyDestructible<CTestArray2>);
static_assert(cIsTriviallyDestructible<CTestArray2C>);
static_assert(!cIsTriviallyDestructible<CTestArray>);
static_assert(!cIsTriviallyDestructible<CTestArrayC>);
static_assert(cIsTriviallyDestructible<CTest2DArray2>);
static_assert(cIsTriviallyDestructible<CTest2DArray2C>);
static_assert(!cIsTriviallyDestructible<CTest2DArray>);
static_assert(!cIsTriviallyDestructible<CTest2DArrayC>);
static_assert(cIsTriviallyDestructible<CTest3DArray2>);
static_assert(cIsTriviallyDestructible<CTest3DArray2C>);
static_assert(!cIsTriviallyDestructible<CTest3DArray>);
static_assert(!cIsTriviallyDestructible<CTest3DArrayC>);
static_assert(cIsTriviallyDestructible<void *>);
static_assert(!cIsTriviallyDestructible<void>);

