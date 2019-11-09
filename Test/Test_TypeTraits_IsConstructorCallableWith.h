// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#ifdef DMibCompiler_GCC
#pragma GCC system_header
#endif

class CTestInherit : public CTestClass
{
public:
	int m_Test;
};

void blaha()
{
	class CTestInherit : public CTestClass
	{
	public:
		int m_Test;
	};

	CTestInherit Test3;
//	CTestClass &Test2 = NMib::fg_Move(Test3);
	[[maybe_unused]] CTestClass &Test4 = Test3;
	[[maybe_unused]] CTestClass &&Test5 = NMib::fg_Move(Test3);
}

#include <type_traits>

DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArrayNoDefault, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestClass *, void (CTestClass const *)>::mc_Value	));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass *, void (CTestClass *)>::mc_Value	));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass &, void (CTestClass &)>::mc_Value	));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass &&, void (CTestClass &&)>::mc_Value	));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestInherit &&, void (CTestClass &&)>::mc_Value	));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass &&, void (CTestInherit &&)>::mc_Value	));
#ifndef DCompiler_MSVC
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestClass &, void (CTestClass &&)>::mc_Value	));
#endif
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestClass &&, void (CTestClass &)>::mc_Value	));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass &&, void (CTestClass)>::mc_Value	));
#ifndef DCompiler_MSVC
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestClass &, void (CTestClass)>::mc_Value	));
#endif
DMibStaticCheck((	TCIsConstructorCallableWith<CTestBase, void (CTestBase&&)>::mc_Value	));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestNoDefaultConstruct, void ()>::mc_Value	));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestBase, void (int &)>::mc_Value	));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestNoDefaultConstruct, void (int &&)>::mc_Value	));


DMibStaticCheck((	TCIsConstructorCallableWith<CTestUnion, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass0, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass1, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestStruct0, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestStruct1, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestClass0, void ()>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestClass1, void ()>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestStruct0, void ()>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestStruct1, void ()>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<ETestEnum, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<int, void ()>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass, void ()>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestC, void ()>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestCPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestPtrC, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestCRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestCRRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc0, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc1, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc2, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc0Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc1Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc2Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc0RRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc1RRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc2RRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0Ptr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1Ptr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2Ptr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0Ptr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1Ptr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2Ptr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0CPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1CPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2CPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc0El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc1El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc2El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc0ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc1ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc2ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc0ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc1ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc2ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CMPtr, void ()>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CMCPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CMPtrC, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CMCPtrC, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestArray2, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestArray2C, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArrayC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTest2DArray2, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTest2DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest2DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest2DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTest3DArray2, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTest3DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest3DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest3DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<void *, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<void, void ()>::mc_Value							));


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


DMibStaticCheck((	TCIsConstructorCallableWith<CTestUnion, void (CTestUnion)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass0, void (CTestClass0)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass1, void (CTestClass1)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestStruct0, void (CTestStruct0)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestStruct1, void (CTestStruct1)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestClass0, void (CTestClass0)>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestClass1, void (CTestClass1)>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestStruct0, void (CTestStruct0)>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<const CTestStruct1, void (CTestStruct1)>::mc_Value				));
DMibStaticCheck((	TCIsConstructorCallableWith<ETestEnum, void (ETestEnum)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<int, void (int)>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestClass, void (CTestClass)>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestC, void (CTestC)>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestPtr, void (CTestPtr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestCPtr, void (CTestCPtr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestPtrC, void (CTestPtrC)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestCPtrC, void (CTestCPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestRef, void (CTestRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestCRef, void (CTestCRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestRRef, void (CTestRRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CTestCRRef, void (CTestCRRef)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc0, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc1, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc2, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0Ref, void (FFunc0Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1Ref, void (FFunc1Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2Ref, void (FFunc2Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0Ref, void (FFunc0RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1Ref, void (FFunc1RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2Ref, void (FFunc2RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0RRef, void (FFunc0RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1RRef, void (FFunc1RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2RRef, void (FFunc2RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0RRef, void (FFunc0Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1RRef, void (FFunc1Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2RRef, void (FFunc2Ref)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc0Ref, void (FFunc0Ptr)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc1Ref, void (FFunc1Ptr)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc2Ref, void (FFunc2Ptr)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc0RRef, void (FFunc0Ptr)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc1RRef, void (FFunc1Ptr)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<FFunc2RRef, void (FFunc2Ptr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0Ptr, void (FFunc0Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1Ptr, void (FFunc1Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2Ptr, void (FFunc2Ref)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0Ptr, void (FFunc0RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1Ptr, void (FFunc1RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2Ptr, void (FFunc2RRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0Ptr, void (FFunc0Ptr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1Ptr, void (FFunc1Ptr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2Ptr, void (FFunc2Ptr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0PtrC, void (FFunc0PtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1PtrC, void (FFunc1PtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2PtrC, void (FFunc2PtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0Ptr, void (FMFunc0Ptr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1Ptr, void (FMFunc1Ptr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2Ptr, void (FMFunc2Ptr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0PtrC, void (FMFunc0PtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1PtrC, void (FMFunc1PtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2PtrC, void (FMFunc2PtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0CPtr, void (FMFunc0CPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1CPtr, void (FMFunc1CPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2CPtr, void (FMFunc2CPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0CPtrC, void (FMFunc0CPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1CPtrC, void (FMFunc1CPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2CPtrC, void (FMFunc2CPtrC)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc0El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc1El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<PFFunc2El, void ()>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0ElRef, void (FFunc0ElRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1ElRef, void (FFunc1ElRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2ElRef, void (FFunc2ElRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0ElRRef, void (FFunc0ElRRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1ElRRef, void (FFunc1ElRRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2ElRRef, void (FFunc2ElRRef)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0ElPtr, void (FFunc0ElPtr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1ElPtr, void (FFunc1ElPtr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2ElPtr, void (FFunc2ElPtr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc0ElPtrC, void (FFunc0ElPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc1ElPtrC, void (FFunc1ElPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FFunc2ElPtrC, void (FFunc2ElPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElPtr, void (FMFunc0ElPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElPtr, void (FMFunc1ElPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElPtr, void (FMFunc2ElPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElPtrC, void (FMFunc0ElPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElPtrC, void (FMFunc1ElPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElPtrC, void (FMFunc2ElPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElCPtr, void (FMFunc0ElCPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElCPtr, void (FMFunc1ElCPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElCPtr, void (FMFunc2ElCPtr)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc0ElCPtrC, void (FMFunc0ElCPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc1ElCPtrC, void (FMFunc1ElCPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<FMFunc2ElCPtrC, void (FMFunc2ElCPtrC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<CMPtr, void (CMPtr)>::mc_Value							));
DMibStaticCheck((	TCIsConstructorCallableWith<CMCPtr, void (CMCPtr)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CMPtrC, void (CMPtrC)>::mc_Value						));
DMibStaticCheck((	TCIsConstructorCallableWith<CMCPtrC, void (CMCPtrC)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArray2, void (CTestArray2)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArray2C, void (CTestArray2C)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArray, void (CTestArray)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTestArrayC, void (CTestArrayC)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest2DArray2, void (CTest2DArray2)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest2DArray2C, void (CTest2DArray2C)>::mc_Value				));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest2DArray, void (CTest2DArray)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest2DArrayC, void (CTest2DArrayC)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest3DArray2, void (CTest3DArray2)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest3DArray2C, void (CTest3DArray2C)>::mc_Value				));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest3DArray, void (CTest3DArray)>::mc_Value					));
DMibStaticCheck((	!TCIsConstructorCallableWith<CTest3DArrayC, void (CTest3DArrayC)>::mc_Value					));
DMibStaticCheck((	TCIsConstructorCallableWith<void *, void (void *)>::mc_Value						));
DMibStaticCheck((	!TCIsConstructorCallableWith<void, void ()>::mc_Value							));
