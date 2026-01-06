// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#if 1
//ndef DMibCompiler_GCC
// POD definition changed for C++0x, lets not check this yet
// Void

// Special POD testing
static_assert(!cIsPod<CTestClassVirtual>);
static_assert(!cIsPod<CTestClassWithDestructor>);
static_assert(!cIsPod<CTestClassWithDestructorNonTrivial>);
static_assert(!cIsPod<CTestClassWithConstructor>);
static_assert(!cIsPod<CTestClassWithConstructorNonTrivial>);
static_assert(!cIsPod<CTestClassWithCopyConstructor>);
static_assert(!cIsPod<CTestClassWithCopyConstructorNonTrivial>);
static_assert(!cIsPod<CTestClassWithMoveConstructor>);
static_assert(!cIsPod<CTestClassWithMoveConstructorNonTrivial>);
static_assert(cIsPod<CTestClassWithEnum>);
static_assert(cIsPod<CTestClassWithPrivate>);
static_assert(!cIsPod<CTestClassWithBase>);


static_assert(cIsPod<CTestUnion>);
static_assert(cIsPod<CTestClass0>);
static_assert(cIsPod<CTestClass1>);
static_assert(cIsPod<CTestStruct0>);
static_assert(cIsPod<CTestStruct1>);
static_assert(cIsPod<const CTestClass0>);
static_assert(cIsPod<const CTestClass1>);
static_assert(cIsPod<const CTestStruct0>);
static_assert(cIsPod<const CTestStruct1>);
static_assert(cIsPod<ETestEnum>);
static_assert(cIsPod<int>);
static_assert(cIsPod<CTestClass>);
static_assert(cIsPod<CTestC>);
static_assert(cIsPod<CTestPtr>);
static_assert(cIsPod<CTestCPtr>);
static_assert(cIsPod<CTestPtrC>);
static_assert(cIsPod<CTestCPtrC>);
static_assert(!cIsPod<CTestRef>);
static_assert(!cIsPod<CTestCRef>);
static_assert(!cIsPod<CTestRRef>);
static_assert(!cIsPod<CTestCRRef>);
static_assert(!cIsPod<PFFunc0>);
static_assert(!cIsPod<PFFunc1>);
static_assert(!cIsPod<PFFunc2>);
static_assert(!cIsPod<FFunc0Ref>);
static_assert(!cIsPod<FFunc1Ref>);
static_assert(!cIsPod<FFunc2Ref>);
static_assert(!cIsPod<FFunc0RRef>);
static_assert(!cIsPod<FFunc1RRef>);
static_assert(!cIsPod<FFunc2RRef>);
static_assert(cIsPod<FFunc0Ptr>);
static_assert(cIsPod<FFunc1Ptr>);
static_assert(cIsPod<FFunc2Ptr>);
static_assert(cIsPod<FFunc0PtrC>);
static_assert(cIsPod<FFunc1PtrC>);
static_assert(cIsPod<FFunc2PtrC>);
static_assert(cIsPod<FMFunc0Ptr>);
static_assert(cIsPod<FMFunc1Ptr>);
static_assert(cIsPod<FMFunc2Ptr>);
static_assert(cIsPod<FMFunc0PtrC>);
static_assert(cIsPod<FMFunc1PtrC>);
static_assert(cIsPod<FMFunc2PtrC>);
static_assert(cIsPod<FMFunc0CPtr>);
static_assert(cIsPod<FMFunc1CPtr>);
static_assert(cIsPod<FMFunc2CPtr>);
static_assert(cIsPod<FMFunc0CPtrC>);
static_assert(cIsPod<FMFunc1CPtrC>);
static_assert(cIsPod<FMFunc2CPtrC>);
static_assert(!cIsPod<PFFunc0El>);
static_assert(!cIsPod<PFFunc1El>);
static_assert(!cIsPod<PFFunc2El>);
static_assert(!cIsPod<FFunc0ElRef>);
static_assert(!cIsPod<FFunc1ElRef>);
static_assert(!cIsPod<FFunc2ElRef>);
static_assert(!cIsPod<FFunc0ElRRef>);
static_assert(!cIsPod<FFunc1ElRRef>);
static_assert(!cIsPod<FFunc2ElRRef>);
static_assert(cIsPod<FFunc0ElPtr>);
static_assert(cIsPod<FFunc1ElPtr>);
static_assert(cIsPod<FFunc2ElPtr>);
static_assert(cIsPod<FFunc0ElPtrC>);
static_assert(cIsPod<FFunc1ElPtrC>);
static_assert(cIsPod<FFunc2ElPtrC>);
static_assert(cIsPod<FMFunc0ElPtr>);
static_assert(cIsPod<FMFunc1ElPtr>);
static_assert(cIsPod<FMFunc2ElPtr>);
static_assert(cIsPod<FMFunc0ElPtrC>);
static_assert(cIsPod<FMFunc1ElPtrC>);
static_assert(cIsPod<FMFunc2ElPtrC>);
static_assert(cIsPod<FMFunc0ElCPtr>);
static_assert(cIsPod<FMFunc1ElCPtr>);
static_assert(cIsPod<FMFunc2ElCPtr>);
static_assert(cIsPod<FMFunc0ElCPtrC>);
static_assert(cIsPod<FMFunc1ElCPtrC>);
static_assert(cIsPod<FMFunc2ElCPtrC>);
static_assert(cIsPod<CMPtr>);
static_assert(cIsPod<CMCPtr>);
static_assert(cIsPod<CMPtrC>);
static_assert(cIsPod<CMCPtrC>);
static_assert(cIsPod<CTestArray2>);
static_assert(cIsPod<CTestArray2C>);
static_assert(cIsPod<CTestArray>);
static_assert(cIsPod<CTestArrayC>);
static_assert(cIsPod<CTest2DArray2>);
static_assert(cIsPod<CTest2DArray2C>);
static_assert(cIsPod<CTest2DArray>);
static_assert(cIsPod<CTest2DArrayC>);
static_assert(cIsPod<CTest3DArray2>);
static_assert(cIsPod<CTest3DArray2C>);
static_assert(cIsPod<CTest3DArray>);
static_assert(cIsPod<CTest3DArrayC>);
static_assert(cIsPod<void *>);
static_assert(!cIsPod<void>);

#endif
