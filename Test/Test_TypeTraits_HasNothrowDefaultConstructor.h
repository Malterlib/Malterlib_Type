// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"


namespace NNothrow
{
	static_assert(cIsNothrowDefaultConstructible<CThrowsAssignment>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsAssignmentInt>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsAssignmentBoth>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsAssignmentDerived>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsAssignmentDerivedOverride>);
	static_assert(cIsNothrowDefaultConstructible<CNothrow>);

	static_assert(cIsNothrowDefaultConstructible<CThrowsCopy>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsCopyInt>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsCopyBoth>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsCopyDerived>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsCopyDerivedOverride>);
	static_assert(cIsNothrowDefaultConstructible<CNothrow>);

	static_assert(cIsNothrowDefaultConstructible<CNothrowDefault>);

	static_assert(!cIsNothrowDefaultConstructible<CThrowsConstruct>);
	static_assert(!cIsNothrowDefaultConstructible<CThrowsConstructDerived>);
	static_assert(cIsNothrowDefaultConstructible<CThrowsConstructDerivedOverride>);
	static_assert(cIsNothrowDefaultConstructible<CNothrow>);

	static_assert(cIsNothrowDefaultConstructible<CTestClassVirtual>);
}

// Void
static_assert(cIsNothrowDefaultConstructible<CTestUnion>);
static_assert(cIsNothrowDefaultConstructible<CTestClass0>);
static_assert(cIsNothrowDefaultConstructible<CTestClass1>);
static_assert(cIsNothrowDefaultConstructible<CTestStruct0>);
static_assert(cIsNothrowDefaultConstructible<CTestStruct1>);
static_assert(cIsNothrowDefaultConstructible<const CTestClass0>);
static_assert(cIsNothrowDefaultConstructible<const CTestClass1>);
static_assert(cIsNothrowDefaultConstructible<const CTestStruct0>);
static_assert(cIsNothrowDefaultConstructible<const CTestStruct1>);
static_assert(cIsNothrowDefaultConstructible<ETestEnum>);
static_assert(cIsNothrowDefaultConstructible<int>);
static_assert(cIsNothrowDefaultConstructible<CTestClass>);
static_assert(cIsNothrowDefaultConstructible<CTestC>);
static_assert(cIsNothrowDefaultConstructible<CTestPtr>);
static_assert(cIsNothrowDefaultConstructible<CTestCPtr>);
static_assert(cIsNothrowDefaultConstructible<CTestPtrC>);
static_assert(cIsNothrowDefaultConstructible<CTestCPtrC>);
static_assert(!cIsNothrowDefaultConstructible<CTestRef>);
static_assert(!cIsNothrowDefaultConstructible<CTestCRef>);
static_assert(!cIsNothrowDefaultConstructible<CTestRRef>);
static_assert(!cIsNothrowDefaultConstructible<CTestCRRef>);
static_assert(!cIsNothrowDefaultConstructible<PFFunc0>);
static_assert(!cIsNothrowDefaultConstructible<PFFunc1>);
static_assert(!cIsNothrowDefaultConstructible<PFFunc2>);
static_assert(!cIsNothrowDefaultConstructible<FFunc0Ref>);
static_assert(!cIsNothrowDefaultConstructible<FFunc1Ref>);
static_assert(!cIsNothrowDefaultConstructible<FFunc2Ref>);
static_assert(!cIsNothrowDefaultConstructible<FFunc0RRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc1RRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc2RRef>);
static_assert(cIsNothrowDefaultConstructible<FFunc0Ptr>);
static_assert(cIsNothrowDefaultConstructible<FFunc1Ptr>);
static_assert(cIsNothrowDefaultConstructible<FFunc2Ptr>);
static_assert(cIsNothrowDefaultConstructible<FFunc0PtrC>);
static_assert(cIsNothrowDefaultConstructible<FFunc1PtrC>);
static_assert(cIsNothrowDefaultConstructible<FFunc2PtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0Ptr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1Ptr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2Ptr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0PtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1PtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2PtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0CPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1CPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2CPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0CPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1CPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2CPtrC>);
static_assert(!cIsNothrowDefaultConstructible<PFFunc0El>);
static_assert(!cIsNothrowDefaultConstructible<PFFunc1El>);
static_assert(!cIsNothrowDefaultConstructible<PFFunc2El>);
static_assert(!cIsNothrowDefaultConstructible<FFunc0ElRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc1ElRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc2ElRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc0ElRRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc1ElRRef>);
static_assert(!cIsNothrowDefaultConstructible<FFunc2ElRRef>);
static_assert(cIsNothrowDefaultConstructible<FFunc0ElPtr>);
static_assert(cIsNothrowDefaultConstructible<FFunc1ElPtr>);
static_assert(cIsNothrowDefaultConstructible<FFunc2ElPtr>);
static_assert(cIsNothrowDefaultConstructible<FFunc0ElPtrC>);
static_assert(cIsNothrowDefaultConstructible<FFunc1ElPtrC>);
static_assert(cIsNothrowDefaultConstructible<FFunc2ElPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0ElPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1ElPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2ElPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0ElPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1ElPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2ElPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0ElCPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1ElCPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2ElCPtr>);
static_assert(cIsNothrowDefaultConstructible<FMFunc0ElCPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc1ElCPtrC>);
static_assert(cIsNothrowDefaultConstructible<FMFunc2ElCPtrC>);
static_assert(cIsNothrowDefaultConstructible<CMPtr>);
static_assert(cIsNothrowDefaultConstructible<CMCPtr>);
static_assert(cIsNothrowDefaultConstructible<CMPtrC>);
static_assert(cIsNothrowDefaultConstructible<CMCPtrC>);
static_assert(cIsNothrowDefaultConstructible<CTestArray2>);
static_assert(cIsNothrowDefaultConstructible<CTestArray2C>);
static_assert(!cIsNothrowDefaultConstructible<CTestArray>);
static_assert(!cIsNothrowDefaultConstructible<CTestArrayC>);
static_assert(cIsNothrowDefaultConstructible<CTest2DArray2>);
static_assert(cIsNothrowDefaultConstructible<CTest2DArray2C>);
static_assert(!cIsNothrowDefaultConstructible<CTest2DArray>);
static_assert(!cIsNothrowDefaultConstructible<CTest2DArrayC>);
static_assert(cIsNothrowDefaultConstructible<CTest3DArray2>);
static_assert(cIsNothrowDefaultConstructible<CTest3DArray2C>);
static_assert(!cIsNothrowDefaultConstructible<CTest3DArray>);
static_assert(!cIsNothrowDefaultConstructible<CTest3DArrayC>);
static_assert(cIsNothrowDefaultConstructible<void *>);
static_assert(!cIsNothrowDefaultConstructible<void>);

