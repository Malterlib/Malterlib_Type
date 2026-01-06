// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

// Test const qualifiers

static_assert(!cIsConst<CTestClass>);
static_assert(cIsConst<CTestC>);

static_assert(!cIsConst<CTestRef>);
static_assert(!cIsConst<CTestCRef>);

static_assert(!cIsConst<CTestRRef>);
static_assert(!cIsConst<CTestCRRef>);

static_assert(!cIsConst<CTestPtr>);
static_assert(cIsConst<CTestPtrC>);
static_assert(!cIsConst<CTestCPtr>);
static_assert(cIsConst<CTestCPtrC>);

static_assert(cIsSame<TCRemoveConst<CTestClass>, CTestClass>);
static_assert(cIsSame<TCRemoveConst<CTestC>, CTestClass>);

static_assert(cIsSame<TCRemoveConst<CTestRef>, CTestRef>);
static_assert(cIsSame<TCRemoveConst<CTestCRef>, CTestCRef>);

static_assert(cIsSame<TCRemoveConst<CTestRRef>, CTestRRef>);
static_assert(cIsSame<TCRemoveConst<CTestCRRef>, CTestCRRef>);

static_assert(cIsSame<TCRemoveConst<CTestPtr>, CTestPtr>);
static_assert(cIsSame<TCRemoveConst<CTestPtrC>, CTestPtr>);
static_assert(cIsSame<TCRemoveConst<CTestCPtr>, CTestCPtr>);
static_assert(cIsSame<TCRemoveConst<CTestCPtrC>, CTestCPtr>);

static_assert(cIsSame<TCAddConst<CTestClass>, CTestC>);
static_assert(cIsSame<TCAddConst<CTestC>, CTestC>);

static_assert(cIsSame<TCAddConst<CTestRef>, CTestRef>);
static_assert(cIsSame<TCAddConst<CTestCRef>, CTestCRef>);

static_assert(cIsSame<TCAddConst<CTestRRef>, CTestRRef>);
static_assert(cIsSame<TCAddConst<CTestCRRef>, CTestCRRef>);

static_assert(cIsSame<TCAddConst<CTestPtr>, CTestPtrC>);
static_assert(cIsSame<TCAddConst<CTestPtrC>, CTestPtrC>);
static_assert(cIsSame<TCAddConst<CTestCPtr>, CTestCPtrC>);
static_assert(cIsSame<TCAddConst<CTestCPtrC>, CTestCPtrC>);


static_assert(cIsSame<TCSetConst<CTestClass, 1>, CTestC>);
static_assert(cIsSame<TCSetConst<CTestC, 1>, CTestC>);

static_assert(cIsSame<TCSetConst<CTestRef, 1>, CTestRef>);
static_assert(cIsSame<TCSetConst<CTestCRef, 1>, CTestCRef>);

static_assert(cIsSame<TCSetConst<CTestPtr, 1>, CTestPtrC>);
static_assert(cIsSame<TCSetConst<CTestPtrC, 1>, CTestPtrC>);
static_assert(cIsSame<TCSetConst<CTestCPtr, 1>, CTestCPtrC>);
static_assert(cIsSame<TCSetConst<CTestCPtrC, 1>, CTestCPtrC>);

static_assert(cIsSame<TCSetConst<CTestClass, 0>, CTestClass>);
static_assert(cIsSame<TCSetConst<CTestC, 0>, CTestClass>);

static_assert(cIsSame<TCSetConst<CTestRef, 0>, CTestRef>);
static_assert(cIsSame<TCSetConst<CTestCRef, 0>, CTestCRef>);

static_assert(cIsSame<TCSetConst<CTestRRef, 0>, CTestRRef>);
static_assert(cIsSame<TCSetConst<CTestCRRef, 0>, CTestCRRef>);

static_assert(cIsSame<TCSetConst<CTestPtr, 0>, CTestPtr>);
static_assert(cIsSame<TCSetConst<CTestPtrC, 0>, CTestPtr>);
static_assert(cIsSame<TCSetConst<CTestCPtr, 0>, CTestCPtr>);
static_assert(cIsSame<TCSetConst<CTestCPtrC, 0>, CTestCPtr>);


static_assert(cIsSame<TCCopyConst<CTestClass, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyConst<CTestC, CTestClass>, CTestC>);

static_assert(cIsSame<TCCopyConst<CTestRef, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyConst<CTestCRef, CTestClass>, CTestClass>);

static_assert(cIsSame<TCCopyConst<CTestPtr, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyConst<CTestPtrC, CTestClass>, CTestC>);
static_assert(cIsSame<TCCopyConst<CTestCPtr, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyConst<CTestCPtrC, CTestClass>, CTestC>);

// Test volatile qualifiers

static_assert(!cIsVolatile<CTestClass>);
static_assert(!cIsVolatile<CTestC>);

static_assert(!cIsVolatile<CTestRef>);
static_assert(!cIsVolatile<CTestCRef>);

static_assert(!cIsVolatile<CTestRRef>);
static_assert(!cIsVolatile<CTestCRRef>);

static_assert(!cIsVolatile<CTestPtr>);
static_assert(!cIsVolatile<CTestPtrC>);
static_assert(!cIsVolatile<CTestCPtr>);
static_assert(!cIsVolatile<CTestCPtrC>);

static_assert(cIsSame<TCRemoveVolatile<CTestClass>, CTestClass>);
static_assert(cIsSame<TCRemoveVolatile<CTestC>, CTestC>);

static_assert(cIsSame<TCRemoveVolatile<CTestRef>, CTestRef>);
static_assert(cIsSame<TCRemoveVolatile<CTestCRef>, CTestCRef>);

static_assert(cIsSame<TCRemoveVolatile<CTestRRef>, CTestRRef>);
static_assert(cIsSame<TCRemoveVolatile<CTestCRRef>, CTestCRRef>);

static_assert(cIsSame<TCRemoveVolatile<CTestPtr>, CTestPtr>);
static_assert(cIsSame<TCRemoveVolatile<CTestPtrC>, CTestPtrC>);
static_assert(cIsSame<TCRemoveVolatile<CTestCPtr>, CTestCPtr>);
static_assert(cIsSame<TCRemoveVolatile<CTestCPtrC>, CTestCPtrC>);

static_assert(cIsSame<TCAddVolatile<CTestRef>, CTestRef>);
static_assert(cIsSame<TCAddVolatile<CTestCRef>, CTestCRef>);

static_assert(cIsSame<TCAddVolatile<CTestRRef>, CTestRRef>);
static_assert(cIsSame<TCAddVolatile<CTestCRRef>, CTestCRRef>);

static_assert(cIsSame<TCSetVolatile<CTestRef, 1>, CTestRef>);
static_assert(cIsSame<TCSetVolatile<CTestCRef, 1>, CTestCRef>);

static_assert(cIsSame<TCSetVolatile<CTestRRef, 1>, CTestRRef>);
static_assert(cIsSame<TCSetVolatile<CTestCRRef, 1>, CTestCRRef>);

static_assert(cIsSame<TCSetVolatile<CTestClass, 0>, CTestClass>);
static_assert(cIsSame<TCSetVolatile<CTestC, 0>, CTestC>);

static_assert(cIsSame<TCSetVolatile<CTestRef, 0>, CTestRef>);
static_assert(cIsSame<TCSetVolatile<CTestCRef, 0>, CTestCRef>);

static_assert(cIsSame<TCSetVolatile<CTestRRef, 0>, CTestRRef>);
static_assert(cIsSame<TCSetVolatile<CTestCRRef, 0>, CTestCRRef>);

static_assert(cIsSame<TCSetVolatile<CTestPtr, 0>, CTestPtr>);
static_assert(cIsSame<TCSetVolatile<CTestPtrC, 0>, CTestPtrC>);
static_assert(cIsSame<TCSetVolatile<CTestCPtr, 0>, CTestCPtr>);
static_assert(cIsSame<TCSetVolatile<CTestCPtrC, 0>, CTestCPtrC>);

static_assert(cIsSame<TCCopyVolatile<CTestClass, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyVolatile<CTestC, CTestClass>, CTestClass>);

static_assert(cIsSame<TCCopyVolatile<CTestRef, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyVolatile<CTestCRef, CTestClass>, CTestClass>);

static_assert(cIsSame<TCCopyVolatile<CTestRRef, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyVolatile<CTestCRRef, CTestClass>, CTestClass>);

static_assert(cIsSame<TCCopyVolatile<CTestPtr, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyVolatile<CTestPtrC, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyVolatile<CTestCPtr, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyVolatile<CTestCPtrC, CTestClass>, CTestClass>);

// Test dual qualifier operations

static_assert(cIsSame<TCCopyQualifiers<CTestClass, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyQualifiers<CTestC, CTestClass>, CTestC>);

static_assert(cIsSame<TCCopyQualifiers<CTestRef, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyQualifiers<CTestCRef, CTestClass>, CTestClass>);

static_assert(cIsSame<TCCopyQualifiers<CTestRRef, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyQualifiers<CTestCRRef, CTestClass>, CTestClass>);

static_assert(cIsSame<TCCopyQualifiers<CTestPtr, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyQualifiers<CTestPtrC, CTestClass>, CTestC>);
static_assert(cIsSame<TCCopyQualifiers<CTestCPtr, CTestClass>, CTestClass>);
static_assert(cIsSame<TCCopyQualifiers<CTestCPtrC, CTestClass>, CTestC>);

static_assert(cIsSame<TCRemoveQualifiers<CTestClass>, CTestClass>);
static_assert(cIsSame<TCRemoveQualifiers<CTestC>, CTestClass>);

static_assert(cIsSame<TCRemoveQualifiers<CTestRef>, CTestRef>);
static_assert(cIsSame<TCRemoveQualifiers<CTestCRef>, CTestCRef>);

static_assert(cIsSame<TCRemoveQualifiers<CTestRRef>, CTestRRef>);
static_assert(cIsSame<TCRemoveQualifiers<CTestCRRef>, CTestCRRef>);

static_assert(cIsSame<TCRemoveQualifiers<CTestPtr>, CTestPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CTestPtrC>, CTestPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CTestCPtr>, CTestCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CTestCPtrC>, CTestCPtr>);


static_assert(cIsSame<TCRemoveQualifiers<PFFunc0>, PFFunc0>);
static_assert(cIsSame<TCRemoveQualifiers<PFFunc1>, PFFunc1>);
static_assert(cIsSame<TCRemoveQualifiers<PFFunc2>, PFFunc2>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0Ref>, FFunc0Ref>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1Ref>, FFunc1Ref>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2Ref>, FFunc2Ref>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0RRef>, FFunc0RRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1RRef>, FFunc1RRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2RRef>, FFunc2RRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0Ptr>, FFunc0Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1Ptr>, FFunc1Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2Ptr>, FFunc2Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0PtrC>, FFunc0Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1PtrC>, FFunc1Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2PtrC>, FFunc2Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0Ptr>, FMFunc0Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1Ptr>, FMFunc1Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2Ptr>, FMFunc2Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0PtrC>, FMFunc0Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1PtrC>, FMFunc1Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2PtrC>, FMFunc2Ptr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0CPtr>, FMFunc0CPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1CPtr>, FMFunc1CPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2CPtr>, FMFunc2CPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0CPtrC>, FMFunc0CPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1CPtrC>, FMFunc1CPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2CPtrC>, FMFunc2CPtr>);
static_assert(cIsSame<TCRemoveQualifiers<PFFunc0El>, PFFunc0El>);
static_assert(cIsSame<TCRemoveQualifiers<PFFunc1El>, PFFunc1El>);
static_assert(cIsSame<TCRemoveQualifiers<PFFunc2El>, PFFunc2El>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0ElRef>, FFunc0ElRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1ElRef>, FFunc1ElRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2ElRef>, FFunc2ElRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0ElRRef>, FFunc0ElRRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1ElRRef>, FFunc1ElRRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2ElRRef>, FFunc2ElRRef>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0ElPtr>, FFunc0ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1ElPtr>, FFunc1ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2ElPtr>, FFunc2ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc0ElPtrC>, FFunc0ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc1ElPtrC>, FFunc1ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FFunc2ElPtrC>, FFunc2ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0ElPtr>, FMFunc0ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1ElPtr>, FMFunc1ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2ElPtr>, FMFunc2ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0ElPtrC>, FMFunc0ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1ElPtrC>, FMFunc1ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2ElPtrC>, FMFunc2ElPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0ElCPtr>, FMFunc0ElCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1ElCPtr>, FMFunc1ElCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2ElCPtr>, FMFunc2ElCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc0ElCPtrC>, FMFunc0ElCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc1ElCPtrC>, FMFunc1ElCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<FMFunc2ElCPtrC>, FMFunc2ElCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CMPtr>, CMPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CMCPtr>, CMCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CMPtrC>, CMPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CMCPtrC>, CMCPtr>);
static_assert(cIsSame<TCRemoveQualifiers<CTestArray2>, CTestArray2>);
static_assert(cIsSame<TCRemoveQualifiers<CTestArray2C>, CTestArray2>);
static_assert(cIsSame<TCRemoveQualifiers<CTestArray>, CTestArray>);
static_assert(cIsSame<TCRemoveQualifiers<CTestArrayC>, CTestArray>);
static_assert(cIsSame<TCRemoveQualifiers<CTest2DArray2>, CTest2DArray2>);
static_assert(cIsSame<TCRemoveQualifiers<CTest2DArray2C>, CTest2DArray2>);
static_assert(cIsSame<TCRemoveQualifiers<CTest2DArray>, CTest2DArray>);
static_assert(cIsSame<TCRemoveQualifiers<CTest2DArrayC>, CTest2DArray>);
static_assert(cIsSame<TCRemoveQualifiers<CTest3DArray2>, CTest3DArray2>);
static_assert(cIsSame<TCRemoveQualifiers<CTest3DArray2C>, CTest3DArray2>);
static_assert(cIsSame<TCRemoveQualifiers<CTest3DArray>, CTest3DArray>);
static_assert(cIsSame<TCRemoveQualifiers<CTest3DArrayC>, CTest3DArray>);
