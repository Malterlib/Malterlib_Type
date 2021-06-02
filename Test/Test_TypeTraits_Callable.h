// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#include <Mib/Storage/SharedPointer>

#ifdef DMibCompiler_GCC
#pragma GCC system_header
#endif

namespace NCallable
{
	struct CTestClass
	{
	};

	struct CTestVoid
	{
		void operator () (int _Value);
	};

	struct CTestInt
	{
		int operator () (int _Value);
	};

	struct CTestFloat
	{
		float operator () (int _Value);
	};

	struct CTestTest
	{
		CTestClass operator () (int _Value);
	};

	struct CTestNotCallable
	{
		void operator () (CTestClass _Value);
	};

	struct CTestNotCallable2
	{
		float operator () (CTestClass _Value);
	};

	struct CTestNoArg
	{
		float operator () ();
	};

	struct CTestEllipsis
	{
		float operator () (...);
	};

	struct CTestQualifiers
	{
		uint8 operator () ();
	};

	struct CTestQualifiersConst
	{
		uint16 operator () () const;
	};

	struct CMemberTest
	{
		CTestClass m_Member;
	};

	struct CMemberTestVoid
	{
		CTestVoid m_Member;
	};

	struct CMemberTestInt
	{
		CTestInt m_Member;
	};

	struct CMemberTestFloat
	{
		CTestFloat m_Member;
	};

	struct CMemberTestTest
	{
		CTestTest m_Member;
	};

	struct CMemberTestNotCallable
	{
		CTestNotCallable m_Member;
	};

	struct CMemberTestNotCallable2
	{
		CTestNotCallable2 m_Member;
	};

	struct CMemberTestNoArg
	{
		CTestNoArg m_Member;
	};

	struct CMemberTestEllipsis
	{
		CTestEllipsis m_Member;
	};

	auto LambdaVoid = [](int _Value)
		{
		};
	
	auto LambdaInt = [](int _Value) -> int
		{
			return 0;
		};
	
	auto LambdaFloat = [](int _Value) -> float
		{
			return 0.0f;
		};
	
	auto LambdaTest = [](int _Value) -> NCallable::CTestClass
		{
			return NCallable::CTestClass();
		};
	
	auto LambdaNotCallable = [](CTestClass _Value) -> void
		{
		};
	
	auto LambdaNotCallable2 = [](CTestClass _Value) -> float
		{
			return 0.0f;
		};

	auto LambdaNoArg = []() -> float
		{
			return 0.0f;
		};

	auto LambdaEllipsis = [](...) -> float
		{
			return 0.0f;
		};

	struct CLambdaMemberTestVoid
	{
		decltype(LambdaVoid) m_Member;
	};

	struct CLambdaMemberTestInt
	{
		decltype(LambdaInt) m_Member;
	};

	struct CLambdaMemberTestFloat
	{
		decltype(LambdaFloat) m_Member;
	};

	struct CLambdaMemberTestTest
	{
		decltype(LambdaTest) m_Member;
	};

	struct CLambdaMemberTestNotCallable
	{
		decltype(LambdaNotCallable) m_Member;
	};

	struct CLambdaMemberTestNotCallable2
	{
		decltype(LambdaNotCallable2) m_Member;
	};

	struct CLambdaMemberTestNoArg
	{
		decltype(LambdaNoArg) m_Member;
	};

	struct CLambdaMemberTestEllipsis
	{
		decltype(LambdaEllipsis) m_Member;
	};

	struct CTestVirtual
	{
		virtual void m_Member();
		virtual void m_Member(int);
	};

	struct CHasFunction
	{
		void m_Member(int _X);
	};

	struct CTestInherit : public CHasFunction
	{

	};

#ifndef DCompiler_clang
	// Disabled due to possible clang bug with SINFAE and private member access.

	struct CTestInnerInherit
	{
		class CTestInner : public NMib::NStorage::TCSharedPointerIntrusiveBase<>
		{
			public:
				virtual void f_GetDigest() const = 0;

				virtual ~CTestInner() 
				{
				}
		};

 		static_assert(NMib::NStorage::NPrivate::TCIsMemberCallableWith_f_RefCountIncrease<CTestInner, void (DMibRefcountDebuggingOnly(NMib::NStorage::CRefCountDebugReference &o_DebugRef))>::mc_Value, "TCIsMemberCallableWith_f_RefCountIncrease broke.");

		static_assert(NMib::NStorage::TCHasIntrusiveRefcount<CTestInner>::mc_Value, "TCHasIntrusiveRefcount broke.");

	};

#endif // DCompiler_clang

	DMibStaticCheck((!TCIsFunctionObject<CTestClass>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestInt>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestFloat>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestTest>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestQualifiers>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestQualifiersConst>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestEllipsis>::mc_Value));
	

	DMibStaticCheck((!TCIsCallable<CTestClass>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestInt>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestFloat>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestTest>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestQualifiers>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestQualifiersConst>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestEllipsis>::mc_Value));	

	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaVoid)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaInt)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaFloat)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaTest)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaNotCallable)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaNotCallable2)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaNoArg)>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<decltype(LambdaEllipsis)>::mc_Value));

	DMibStaticCheck((TCIsCallable<decltype(LambdaVoid)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaInt)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaFloat)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaTest)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaNotCallable)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaNotCallable2)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaNoArg)>::mc_Value));
	DMibStaticCheck((TCIsCallable<decltype(LambdaEllipsis)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallable_m_Member<CMemberTest>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestInt>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestFloat>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestTest>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestEllipsis>::mc_Value));
	
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestInt>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestFloat>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestTest>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestEllipsis>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestClass, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestInt, void (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestFloat, void (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestTest, void (float)>::mc_Value));

	DMibStaticCheck((TCIsCallableWith<CTestInt, int (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestFloat, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestTest, int (float)>::mc_Value));

	DMibStaticCheck((TCIsCallableWith<CTestInt, float (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestFloat, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestTest, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestInt, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestFloat, CTestClass (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestTest, CTestClass (float)>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestNotCallable, void (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestNotCallable2, float (float)>::mc_Value));

	DMibStaticCheck((TCIsCallableWith<CTestQualifiers, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConst, void ()>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestQualifiers const, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConst const, void ()>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestNoArg, float (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestNoArg, float ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestNoArg, void ()>::mc_Value));

	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void (int)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void (int, float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void (int, float, CTestClass)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTest, void ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestInt, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestFloat, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestTest, void (float)>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestInt, int (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestFloat, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestTest, int (float)>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestInt, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestFloat, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestTest, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CTestInherit, void (int)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestInt, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestFloat, CTestClass (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestTest, CTestClass (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestNotCallable, void (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestNotCallable2, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestNoArg, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestNoArg, float ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestNoArg, void ()>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void (int)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void (int, float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void (int, float, CTestClass)>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, void (float)>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, int (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, int (float)>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, CTestClass (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, CTestClass (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestNotCallable, void (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestNotCallable2, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestNoArg, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestNoArg, float ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestNoArg, void ()>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestEllipsis, void ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestEllipsis, void (int)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestEllipsis, void (int, float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestEllipsis, void (int, float, CTestClass)>::mc_Value));

}

// Void
DMibStaticCheck((	!TCIsCallable<CTestUnion>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<int>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<PFFunc2>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<PFFunc2El>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	TCIsCallable<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<void *>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<void>::mc_Value							));


DMibStaticCheck((	!TCIsCallableWith<CTestUnion, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestClass0, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestClass1, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestStruct0, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestStruct1, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<const CTestClass0, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<const CTestClass1, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<const CTestStruct0, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<const CTestStruct1, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<ETestEnum, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<int, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestClass, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestC, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCRRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<PFFunc0, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<PFFunc1, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<PFFunc2, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0Ref, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc1Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<FFunc2Ref, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0RRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc1RRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<FFunc2RRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0Ptr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc1Ptr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<FFunc2Ptr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<PFFunc0El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<PFFunc1El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<PFFunc2El, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0ElRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc1ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<FFunc2ElRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc1ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<FFunc2ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc1ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<FFunc2ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	TCIsCallableWith<FFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CMPtr, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CMCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArray2C, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<void *, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<void, void ()>::mc_Value							));





DMibStaticCheck((	!TCIsFunctionCallable<CTestUnion, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestClass0, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestClass1, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestStruct0, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestStruct1, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<const CTestClass0, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<const CTestClass1, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<const CTestStruct0, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<const CTestStruct1, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<ETestEnum, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<int, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestClass, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestC, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCRRef, void ()>::mc_Value					));
DMibStaticCheck((	TCIsFunctionCallable<PFFunc0, void ()>::mc_Value						));
DMibStaticCheck((	TCIsFunctionCallable<PFFunc1, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<PFFunc2, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2Ref, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0RRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1RRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2RRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0Ptr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1Ptr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2Ptr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	TCIsFunctionCallable<PFFunc0El, void ()>::mc_Value						));
DMibStaticCheck((	TCIsFunctionCallable<PFFunc1El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<PFFunc2El, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2ElRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2ElRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2ElPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CMPtr, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CMCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray2C, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<void *, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<void, void ()>::mc_Value							));


DMibStaticCheck((	!TCIsFunctionObject<CTestUnion>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<int>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<void *>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<void>::mc_Value							));

