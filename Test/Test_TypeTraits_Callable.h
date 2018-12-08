// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

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

	struct CTestQualifiersVolatile
	{
		uint32 operator () () volatile;
	};

	struct CTestQualifiersConstVolatile
	{
		uint64 operator () () const volatile;
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

 		static_assert(NMib::NStorage::NPrivate::TCIsMemberCallableWith_f_RefCountIncrease<CTestInner, void ()>::mc_Value, "TCIsMemberCallableWith_f_RefCountIncrease broke.");

		static_assert(NMib::NStorage::TCHasIntrusiveRefcount<CTestInner>::mc_Value, "TCHasIntrusiveRefcount broke.");

	};

#endif // DCompiler_clang

	DMibStaticCheck((!TCIsFunctionObject<CTestClass>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestVoid>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestInt>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestFloat>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestTest>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestQualifiers>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestQualifiersConst>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestQualifiersVolatile>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestQualifiersConstVolatile>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsFunctionObject<CTestEllipsis>::mc_Value));
	DMibStaticCheck((!TCIsFunctionObject<CTestVirtual>::mc_Value));
	

	DMibStaticCheck((!TCIsCallable<CTestClass>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestVoid>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestInt>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestFloat>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestTest>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestQualifiers>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestQualifiersConst>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestQualifiersVolatile>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestQualifiersConstVolatile>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsCallable<CTestEllipsis>::mc_Value));
	DMibStaticCheck((!TCIsCallable<CTestVirtual>::mc_Value));	

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
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestVoid>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestInt>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestFloat>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestTest>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CMemberTestEllipsis>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CTestVirtual>::mc_Value));
	
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestVoid>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestInt>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestFloat>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestTest>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestNotCallable>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestNotCallable2>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestNoArg>::mc_Value));
	DMibStaticCheck((TCIsMemberCallable_m_Member<CLambdaMemberTestEllipsis>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestClass, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestVoid, void (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestInt, void (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestFloat, void (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestTest, void (float)>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestVoid, int (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestInt, int (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestFloat, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestTest, int (float)>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestVoid, float (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestInt, float (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestFloat, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestTest, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestVoid, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestInt, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestFloat, CTestClass (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestTest, CTestClass (float)>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestNotCallable, void (float)>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestNotCallable2, float (float)>::mc_Value));

	DMibStaticCheck((TCIsCallableWith<CTestQualifiers, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConst, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersVolatile, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConstVolatile, void ()>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestQualifiers const, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConst const, void ()>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestQualifiersVolatile const, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConstVolatile const, void ()>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestQualifiers volatile, void ()>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestQualifiersConst volatile, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersVolatile volatile, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConstVolatile volatile, void ()>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestQualifiers const volatile, void ()>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestQualifiersConst const volatile, void ()>::mc_Value));
	DMibStaticCheck((!TCIsCallableWith<CTestQualifiersVolatile const volatile, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestQualifiersConstVolatile const volatile, void ()>::mc_Value));

	DMibStaticCheck((!TCIsCallableWith<CTestNoArg, float (float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestNoArg, float ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestNoArg, void ()>::mc_Value));

	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void ()>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void (int)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void (int, float)>::mc_Value));
	DMibStaticCheck((TCIsCallableWith<CTestEllipsis, void (int, float, CTestClass)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTest, void ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestVoid, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestInt, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestFloat, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestTest, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CTestVirtual, void (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestVoid, int (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestInt, int (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestFloat, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestTest, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CTestVirtual, int (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestVoid, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestInt, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestFloat, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestTest, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CTestVirtual, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CTestInherit, void (int)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestVoid, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestInt, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestFloat, CTestClass (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestTest, CTestClass (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CTestVirtual, CTestClass (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestNotCallable, void (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestNotCallable2, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CMemberTestNoArg, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestNoArg, float ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestNoArg, void ()>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void ()>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void (int)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void (int, float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CMemberTestEllipsis, void (int, float, CTestClass)>::mc_Value));

	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestVoid, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, void (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, void (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestVoid, int (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, int (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, int (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, int (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestVoid, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestInt, float (float)>::mc_Value));
	DMibStaticCheck((TCIsMemberCallableWith_m_Member<CLambdaMemberTestFloat, float (float)>::mc_Value));
	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestTest, float (float)>::mc_Value));

	DMibStaticCheck((!TCIsMemberCallableWith_m_Member<CLambdaMemberTestVoid, CTestClass (float)>::mc_Value));
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
DMibStaticCheck((	!TCIsCallable<volatile CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsCallable<volatile CTestClass1>::mc_Value			));
DMibStaticCheck((	!TCIsCallable<volatile CTestStruct0>::mc_Value			));
DMibStaticCheck((	!TCIsCallable<volatile CTestStruct1>::mc_Value			));
DMibStaticCheck((	!TCIsCallable<const volatile CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsCallable<const volatile CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCIsCallable<const volatile CTestStruct0>::mc_Value	));
DMibStaticCheck((	!TCIsCallable<const volatile CTestStruct1>::mc_Value	));
DMibStaticCheck((	!TCIsCallable<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<int>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestV>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CTestCV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestVPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestCVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestVRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCVRef>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestVRRef>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestCVRRef>::mc_Value					));
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
DMibStaticCheck((	TCIsCallable<FFunc0PtrV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc1PtrV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc2PtrV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc0PtrCV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc1PtrCV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc2PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0VPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1VPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2VPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0VPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1VPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2VPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0VPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1VPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2VPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<FMFunc1CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<FMFunc2CVPtrCV>::mc_Value				));
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
DMibStaticCheck((	TCIsCallable<FFunc0ElPtrV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc1ElPtrV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc2ElPtrV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc0ElPtrCV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc1ElPtrCV>::mc_Value					));
DMibStaticCheck((	TCIsCallable<FFunc2ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<FMFunc0ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<FMFunc1ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<FMFunc2ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsCallable<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMVPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCVPtr>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMVPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCVPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMVPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCVPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMVPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CMCVPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsCallable<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArray2V>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArray2CV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArrayV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTestArrayCV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest2DArray2V>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest2DArray2CV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArrayV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest2DArrayCV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest3DArray2V>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest3DArray2CV>::mc_Value				));
DMibStaticCheck((	!TCIsCallable<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArrayV>::mc_Value					));
DMibStaticCheck((	!TCIsCallable<CTest3DArrayCV>::mc_Value				));
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
DMibStaticCheck((	!TCIsCallableWith<volatile CTestClass0, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsCallableWith<volatile CTestClass1, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsCallableWith<volatile CTestStruct0, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsCallableWith<volatile CTestStruct1, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsCallableWith<const volatile CTestClass0, void ()>::mc_Value		));
DMibStaticCheck((	!TCIsCallableWith<const volatile CTestClass1, void ()>::mc_Value		));
DMibStaticCheck((	!TCIsCallableWith<const volatile CTestStruct0, void ()>::mc_Value	));
DMibStaticCheck((	!TCIsCallableWith<const volatile CTestStruct1, void ()>::mc_Value	));
DMibStaticCheck((	!TCIsCallableWith<ETestEnum, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<int, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestClass, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestC, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestV, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CTestCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestVPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestCVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestVRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCVRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestCRRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestVRRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestCVRRef, void ()>::mc_Value					));
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
DMibStaticCheck((	TCIsCallableWith<FFunc0PtrV, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc1PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FFunc2PtrV, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc0PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc1PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FFunc2PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0VPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1VPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2VPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0VPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1VPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2VPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0VPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1VPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2VPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0VPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1VPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2VPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0CVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1CVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2CVPtrCV, void ()>::mc_Value				));
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
DMibStaticCheck((	TCIsCallableWith<FFunc0ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc1ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FFunc2ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc0ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	TCIsCallableWith<FFunc1ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FFunc2ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<FMFunc0ElCVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<FMFunc1ElCVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<FMFunc2ElCVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CMPtr, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsCallableWith<CMCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMVPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCVPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMVPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCVPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMVPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCVPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMVPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CMCVPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsCallableWith<CTestArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArray2C, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArray2V, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArray2CV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArrayV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTestArrayCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray2V, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray2CV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArrayV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest2DArrayCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray2V, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray2CV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArrayV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsCallableWith<CTest3DArrayCV, void ()>::mc_Value				));
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
DMibStaticCheck((	!TCIsFunctionCallable<volatile CTestClass0, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionCallable<volatile CTestClass1, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionCallable<volatile CTestStruct0, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionCallable<volatile CTestStruct1, void ()>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionCallable<const volatile CTestClass0, void ()>::mc_Value		));
DMibStaticCheck((	!TCIsFunctionCallable<const volatile CTestClass1, void ()>::mc_Value		));
DMibStaticCheck((	!TCIsFunctionCallable<const volatile CTestStruct0, void ()>::mc_Value	));
DMibStaticCheck((	!TCIsFunctionCallable<const volatile CTestStruct1, void ()>::mc_Value	));
DMibStaticCheck((	!TCIsFunctionCallable<ETestEnum, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<int, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestClass, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestC, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestV, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestVPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestVRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCVRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestRRef, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCRRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestVRRef, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestCVRRef, void ()>::mc_Value					));
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
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2Ptr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2PtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2PtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2PtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0VPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1VPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2VPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0VPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1VPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2VPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0VPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1VPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2VPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0VPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1VPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2VPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0CVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1CVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2CVPtrCV, void ()>::mc_Value				));
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
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc0ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc1ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FFunc2ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElVPtrCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCVPtr, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCVPtrC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCVPtrV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc0ElCVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc1ElCVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<FMFunc2ElCVPtrCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CMPtr, void ()>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionCallable<CMCPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMVPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCVPtr, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMVPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCVPtrC, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMVPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCVPtrV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMVPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CMCVPtrCV, void ()>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray2C, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray2V, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray2CV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArrayV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTestArrayCV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray2V, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray2CV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArrayV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest2DArrayCV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray2, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray2C, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray2V, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray2CV, void ()>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArray, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArrayC, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArrayV, void ()>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionCallable<CTest3DArrayCV, void ()>::mc_Value				));
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
DMibStaticCheck((	!TCIsFunctionObject<volatile CTestClass0>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionObject<volatile CTestClass1>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionObject<volatile CTestStruct0>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionObject<volatile CTestStruct1>::mc_Value			));
DMibStaticCheck((	!TCIsFunctionObject<const volatile CTestClass0>::mc_Value		));
DMibStaticCheck((	!TCIsFunctionObject<const volatile CTestClass1>::mc_Value		));
DMibStaticCheck((	!TCIsFunctionObject<const volatile CTestStruct0>::mc_Value	));
DMibStaticCheck((	!TCIsFunctionObject<const volatile CTestStruct1>::mc_Value	));
DMibStaticCheck((	!TCIsFunctionObject<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<int>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestV>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CTestCV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestVPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestCVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestVRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCVRef>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestVRRef>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestCVRRef>::mc_Value					));
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
DMibStaticCheck((	!TCIsFunctionObject<FFunc0PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2PtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2PtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0VPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1VPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2VPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0VPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1VPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2VPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0VPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1VPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2VPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2VPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1CVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2CVPtrCV>::mc_Value				));
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
DMibStaticCheck((	!TCIsFunctionObject<FFunc0ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc0ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc1ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FFunc2ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElVPtrCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCVPtr>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCVPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCVPtrV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc0ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc1ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<FMFunc2ElCVPtrCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsFunctionObject<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMVPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCVPtr>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMVPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCVPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMVPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCVPtrV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMVPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CMCVPtrCV>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray2V>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray2CV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArrayV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTestArrayCV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray2V>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray2CV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArrayV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest2DArrayCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray2V>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray2CV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArrayV>::mc_Value					));
DMibStaticCheck((	!TCIsFunctionObject<CTest3DArrayCV>::mc_Value				));
DMibStaticCheck((	!TCIsFunctionObject<void *>::mc_Value						));
DMibStaticCheck((	!TCIsFunctionObject<void>::mc_Value							));

