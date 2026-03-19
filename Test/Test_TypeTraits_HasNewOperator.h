// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#include <boost/type_traits/has_new_operator.hpp>

namespace NHasNewOperator
{
	class CWithNew
	{
	public:
		void * operator new(umint _Value);
	};

	class CWithNewArray
	{
	public:
		void * operator new [](umint _Value);
	};

	class CWithNewBoth
	{
	public:
		void * operator new(umint _Value);
		void * operator new [](umint _Value);
	};

	class CWithNewDerived : public CWithNewBoth
	{
	};

	class CWithDelete
	{
	public:
		void operator delete(void *);
	};

	class CWithDeleteArray
	{
	public:
		void operator delete [](void *);
	};

	class CWithDeleteBoth
	{
	public:
		void operator delete(void *);
		void operator delete [](void *);
	};

	class CWithDeleteDerived : public CWithDeleteBoth
	{
	};

	class CWithBothDerived : public CWithDeleteBoth, public CWithNewBoth
	{
	};


	class CWithSpecialNew
	{
	public:
		void * operator new(umint _Value, CTestClass0 _Special);
	};

	class CWithSpecialNewArray
	{
	public:
		void * operator new [](umint _Value, CTestClass0 _Special);
	};

	class CWithSpecialNewBoth
	{
	public:
		void * operator new(umint _Value, CTestClass0 _Special);
		void * operator new [](umint _Value, CTestClass0 _Special);
	};

	class CWithSpecialNewDerived : public CWithSpecialNewBoth
	{
	};

	class CWithSpecialDelete
	{
	public:
		void operator delete(void *, CTestClass0 _Special);
	};

	class CWithSpecialDeleteArray
	{
	public:
		void operator delete [](void *, CTestClass0 _Special);
	};

	class CWithSpecialDeleteBoth
	{
	public:
		void operator delete(void *, CTestClass0 _Special);
		void operator delete [](void *, CTestClass0 _Special);
	};

	class CWithSpecialDeleteDerived : public CWithSpecialDeleteBoth
	{
	};

	class CWithSpecialBothDerived : public CWithSpecialDeleteBoth, public CWithSpecialNewBoth
	{
	};


	class CWithDualNew
	{
	public:
		void * operator new(umint _Value, CTestClass0 _Special);
		void * operator new(umint _Value);
	};

	class CWithDualNewArray
	{
	public:
		void * operator new [](umint _Value, CTestClass0 _Special);
		void * operator new [](umint _Value);
	};

	class CWithDualNewBoth
	{
	public:
		void * operator new(umint _Value, CTestClass0 _Special);
		void * operator new [](umint _Value, CTestClass0 _Special);
		void * operator new(umint _Value);
		void * operator new [](umint _Value);
	};

	class CWithDualNewDerived : public CWithDualNewBoth
	{
	};

	class CWithDualDelete
	{
	public:
		void operator delete(void *, CTestClass0 _Special);
		void operator delete(void *);
	};

	class CWithDualDeleteArray
	{
	public:
		void operator delete [](void *, CTestClass0 _Special);
		void operator delete [](void *);
	};

	class CWithDualDeleteBoth
	{
	public:
		void operator delete(void *, CTestClass0 _Special);
		void operator delete [](void *, CTestClass0 _Special);
		void operator delete(void *);
		void operator delete [](void *);
	};

	class CWithDualDeleteDerived : public CWithDualDeleteBoth
	{
	};

	class CWithDualBothDerived : public CWithDualDeleteBoth, public CWithDualNewBoth
	{
	};

	void Testing()
	{
		//void *pTest = CWithNew::operator new(5);
		//CWithDelete::operator delete(pTest);
	}

	static_assert(cHasOperatorNewAny<CWithNew>);
	static_assert(cHasOperatorNewAny<CWithNewArray>);
	static_assert(cHasOperatorNewAny<CWithNewBoth>);
	static_assert(cHasOperatorNewAny<CWithNewDerived>);
	static_assert(!cHasOperatorNewAny<CWithDelete>);
	static_assert(!cHasOperatorNewAny<CWithDeleteArray>);
	static_assert(!cHasOperatorNewAny<CWithDeleteBoth>);
	static_assert(!cHasOperatorNewAny<CWithDeleteDerived>);
	static_assert(cHasOperatorNewAny<CWithBothDerived>);


	static_assert(!cHasOperatorDeleteAny<CWithNew>);
	static_assert(!cHasOperatorDeleteAny<CWithNewArray>);
	static_assert(!cHasOperatorDeleteAny<CWithNewBoth>);
	static_assert(!cHasOperatorDeleteAny<CWithNewDerived>);
	static_assert(cHasOperatorDeleteAny<CWithDelete>);
	static_assert(cHasOperatorDeleteAny<CWithDeleteArray>);
	static_assert(cHasOperatorDeleteAny<CWithDeleteBoth>);
	static_assert(cHasOperatorDeleteAny<CWithDeleteDerived>);
	static_assert(cHasOperatorDeleteAny<CWithBothDerived>);

	/////////////////
	///////
	/////////


	static_assert(cHasOperatorNewAny<CWithSpecialNew>);
	static_assert(cHasOperatorNewAny<CWithSpecialNewArray>);
	static_assert(cHasOperatorNewAny<CWithSpecialNewBoth>);
	static_assert(cHasOperatorNewAny<CWithSpecialNewDerived>);
	static_assert(!cHasOperatorNewAny<CWithSpecialDelete>);
	static_assert(!cHasOperatorNewAny<CWithSpecialDeleteArray>);
	static_assert(!cHasOperatorNewAny<CWithSpecialDeleteBoth>);
	static_assert(!cHasOperatorNewAny<CWithSpecialDeleteDerived>);
	static_assert(cHasOperatorNewAny<CWithSpecialBothDerived>);

	static_assert(!cHasOperatorDeleteAny<CWithSpecialNew>);
	static_assert(!cHasOperatorDeleteAny<CWithSpecialNewArray>);
	static_assert(!cHasOperatorDeleteAny<CWithSpecialNewBoth>);
	static_assert(!cHasOperatorDeleteAny<CWithSpecialNewDerived>);
	static_assert(cHasOperatorDeleteAny<CWithSpecialDelete>);
	static_assert(cHasOperatorDeleteAny<CWithSpecialDeleteArray>);
	static_assert(cHasOperatorDeleteAny<CWithSpecialDeleteBoth>);
	static_assert(cHasOperatorDeleteAny<CWithSpecialDeleteDerived>);
	static_assert(cHasOperatorDeleteAny<CWithSpecialBothDerived>);

	////
	////
	/////////////

	static_assert(cHasOperatorNewAny<CWithDualNew>);
	static_assert(cHasOperatorNewAny<CWithDualNewArray>);
	static_assert(cHasOperatorNewAny<CWithDualNewBoth>);
	static_assert(cHasOperatorNewAny<CWithDualNewDerived>);
	static_assert(!cHasOperatorNewAny<CWithDualDelete>);
	static_assert(!cHasOperatorNewAny<CWithDualDeleteArray>);
	static_assert(!cHasOperatorNewAny<CWithDualDeleteBoth>);
	static_assert(!cHasOperatorNewAny<CWithDualDeleteDerived>);
	static_assert(cHasOperatorNewAny<CWithDualBothDerived>);

	static_assert(!cHasOperatorDeleteAny<CWithDualNew>);
	static_assert(!cHasOperatorDeleteAny<CWithDualNewArray>);
	static_assert(!cHasOperatorDeleteAny<CWithDualNewBoth>);
	static_assert(!cHasOperatorDeleteAny<CWithDualNewDerived>);
	static_assert(cHasOperatorDeleteAny<CWithDualDelete>);
	static_assert(cHasOperatorDeleteAny<CWithDualDeleteArray>);
	static_assert(cHasOperatorDeleteAny<CWithDualDeleteBoth>);
	static_assert(cHasOperatorDeleteAny<CWithDualDeleteDerived>);
	static_assert(cHasOperatorDeleteAny<CWithDualBothDerived>);

}

// Void

static_assert(!cHasOperatorNewAny<CTestUnion>);
static_assert(!cHasOperatorNewAny<CTestClass0>);
static_assert(!cHasOperatorNewAny<CTestClass1>);
static_assert(!cHasOperatorNewAny<CTestStruct0>);
static_assert(!cHasOperatorNewAny<CTestStruct1>);
static_assert(!cHasOperatorNewAny<const CTestClass0>);
static_assert(!cHasOperatorNewAny<const CTestClass1>);
static_assert(!cHasOperatorNewAny<const CTestStruct0>);
static_assert(!cHasOperatorNewAny<const CTestStruct1>);
static_assert(!cHasOperatorNewAny<ETestEnum>);
static_assert(!cHasOperatorNewAny<int>);
static_assert(!cHasOperatorNewAny<CTestClass>);
static_assert(!cHasOperatorNewAny<CTestC>);
static_assert(!cHasOperatorNewAny<CTestPtr>);
static_assert(!cHasOperatorNewAny<CTestCPtr>);
static_assert(!cHasOperatorNewAny<CTestPtrC>);
static_assert(!cHasOperatorNewAny<CTestCPtrC>);
static_assert(!cHasOperatorNewAny<CTestRef>);
static_assert(!cHasOperatorNewAny<CTestCRef>);
static_assert(!cHasOperatorNewAny<CTestRRef>);
static_assert(!cHasOperatorNewAny<CTestCRRef>);
static_assert(!cHasOperatorNewAny<PFFunc0>);
static_assert(!cHasOperatorNewAny<PFFunc1>);
static_assert(!cHasOperatorNewAny<PFFunc2>);
static_assert(!cHasOperatorNewAny<FFunc0Ref>);
static_assert(!cHasOperatorNewAny<FFunc1Ref>);
static_assert(!cHasOperatorNewAny<FFunc2Ref>);
static_assert(!cHasOperatorNewAny<FFunc0RRef>);
static_assert(!cHasOperatorNewAny<FFunc1RRef>);
static_assert(!cHasOperatorNewAny<FFunc2RRef>);
static_assert(!cHasOperatorNewAny<FFunc0Ptr>);
static_assert(!cHasOperatorNewAny<FFunc1Ptr>);
static_assert(!cHasOperatorNewAny<FFunc2Ptr>);
static_assert(!cHasOperatorNewAny<FFunc0PtrC>);
static_assert(!cHasOperatorNewAny<FFunc1PtrC>);
static_assert(!cHasOperatorNewAny<FFunc2PtrC>);
static_assert(!cHasOperatorNewAny<FMFunc0Ptr>);
static_assert(!cHasOperatorNewAny<FMFunc1Ptr>);
static_assert(!cHasOperatorNewAny<FMFunc2Ptr>);
static_assert(!cHasOperatorNewAny<FMFunc0PtrC>);
static_assert(!cHasOperatorNewAny<FMFunc1PtrC>);
static_assert(!cHasOperatorNewAny<FMFunc2PtrC>);
static_assert(!cHasOperatorNewAny<FMFunc0CPtr>);
static_assert(!cHasOperatorNewAny<FMFunc1CPtr>);
static_assert(!cHasOperatorNewAny<FMFunc2CPtr>);
static_assert(!cHasOperatorNewAny<FMFunc0CPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc1CPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc2CPtrC>);
static_assert(!cHasOperatorNewAny<PFFunc0El>);
static_assert(!cHasOperatorNewAny<PFFunc1El>);
static_assert(!cHasOperatorNewAny<PFFunc2El>);
static_assert(!cHasOperatorNewAny<FFunc0ElRef>);
static_assert(!cHasOperatorNewAny<FFunc1ElRef>);
static_assert(!cHasOperatorNewAny<FFunc2ElRef>);
static_assert(!cHasOperatorNewAny<FFunc0ElRRef>);
static_assert(!cHasOperatorNewAny<FFunc1ElRRef>);
static_assert(!cHasOperatorNewAny<FFunc2ElRRef>);
static_assert(!cHasOperatorNewAny<FFunc0ElPtr>);
static_assert(!cHasOperatorNewAny<FFunc1ElPtr>);
static_assert(!cHasOperatorNewAny<FFunc2ElPtr>);
static_assert(!cHasOperatorNewAny<FFunc0ElPtrC>);
static_assert(!cHasOperatorNewAny<FFunc1ElPtrC>);
static_assert(!cHasOperatorNewAny<FFunc2ElPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc0ElPtr>);
static_assert(!cHasOperatorNewAny<FMFunc1ElPtr>);
static_assert(!cHasOperatorNewAny<FMFunc2ElPtr>);
static_assert(!cHasOperatorNewAny<FMFunc0ElPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc1ElPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc2ElPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc0ElCPtr>);
static_assert(!cHasOperatorNewAny<FMFunc1ElCPtr>);
static_assert(!cHasOperatorNewAny<FMFunc2ElCPtr>);
static_assert(!cHasOperatorNewAny<FMFunc0ElCPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc1ElCPtrC>);
static_assert(!cHasOperatorNewAny<FMFunc2ElCPtrC>);
static_assert(!cHasOperatorNewAny<CMPtr>);
static_assert(!cHasOperatorNewAny<CMCPtr>);
static_assert(!cHasOperatorNewAny<CMPtrC>);
static_assert(!cHasOperatorNewAny<CMCPtrC>);
static_assert(!cHasOperatorNewAny<CTestArray2>);
static_assert(!cHasOperatorNewAny<CTestArray2C>);
static_assert(!cHasOperatorNewAny<CTestArray>);
static_assert(!cHasOperatorNewAny<CTestArrayC>);
static_assert(!cHasOperatorNewAny<CTest2DArray2>);
static_assert(!cHasOperatorNewAny<CTest2DArray2C>);
static_assert(!cHasOperatorNewAny<CTest2DArray>);
static_assert(!cHasOperatorNewAny<CTest2DArrayC>);
static_assert(!cHasOperatorNewAny<CTest3DArray2>);
static_assert(!cHasOperatorNewAny<CTest3DArray2C>);
static_assert(!cHasOperatorNewAny<CTest3DArray>);
static_assert(!cHasOperatorNewAny<CTest3DArrayC>);
static_assert(!cHasOperatorNewAny<void *>);
static_assert(!cHasOperatorNewAny<void>);
static_assert(!cHasOperatorNewAny<CTestStructFinal>);

static_assert(!cHasOperatorDeleteAny<CTestUnion>);
static_assert(!cHasOperatorDeleteAny<CTestClass0>);
static_assert(!cHasOperatorDeleteAny<CTestClass1>);
static_assert(!cHasOperatorDeleteAny<CTestStruct0>);
static_assert(!cHasOperatorDeleteAny<CTestStruct1>);
static_assert(!cHasOperatorDeleteAny<const CTestClass0>);
static_assert(!cHasOperatorDeleteAny<const CTestClass1>);
static_assert(!cHasOperatorDeleteAny<const CTestStruct0>);
static_assert(!cHasOperatorDeleteAny<const CTestStruct1>);
static_assert(!cHasOperatorDeleteAny<ETestEnum>);
static_assert(!cHasOperatorDeleteAny<int>);
static_assert(!cHasOperatorDeleteAny<CTestClass>);
static_assert(!cHasOperatorDeleteAny<CTestC>);
static_assert(!cHasOperatorDeleteAny<CTestPtr>);
static_assert(!cHasOperatorDeleteAny<CTestCPtr>);
static_assert(!cHasOperatorDeleteAny<CTestPtrC>);
static_assert(!cHasOperatorDeleteAny<CTestCPtrC>);
static_assert(!cHasOperatorDeleteAny<CTestRef>);
static_assert(!cHasOperatorDeleteAny<CTestCRef>);
static_assert(!cHasOperatorDeleteAny<CTestRRef>);
static_assert(!cHasOperatorDeleteAny<CTestCRRef>);
static_assert(!cHasOperatorDeleteAny<PFFunc0>);
static_assert(!cHasOperatorDeleteAny<PFFunc1>);
static_assert(!cHasOperatorDeleteAny<PFFunc2>);
static_assert(!cHasOperatorDeleteAny<FFunc0Ref>);
static_assert(!cHasOperatorDeleteAny<FFunc1Ref>);
static_assert(!cHasOperatorDeleteAny<FFunc2Ref>);
static_assert(!cHasOperatorDeleteAny<FFunc0RRef>);
static_assert(!cHasOperatorDeleteAny<FFunc1RRef>);
static_assert(!cHasOperatorDeleteAny<FFunc2RRef>);
static_assert(!cHasOperatorDeleteAny<FFunc0Ptr>);
static_assert(!cHasOperatorDeleteAny<FFunc1Ptr>);
static_assert(!cHasOperatorDeleteAny<FFunc2Ptr>);
static_assert(!cHasOperatorDeleteAny<FFunc0PtrC>);
static_assert(!cHasOperatorDeleteAny<FFunc1PtrC>);
static_assert(!cHasOperatorDeleteAny<FFunc2PtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc0Ptr>);
static_assert(!cHasOperatorDeleteAny<FMFunc1Ptr>);
static_assert(!cHasOperatorDeleteAny<FMFunc2Ptr>);
static_assert(!cHasOperatorDeleteAny<FMFunc0PtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc1PtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc2PtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc0CPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc1CPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc2CPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc0CPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc1CPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc2CPtrC>);
static_assert(!cHasOperatorDeleteAny<PFFunc0El>);
static_assert(!cHasOperatorDeleteAny<PFFunc1El>);
static_assert(!cHasOperatorDeleteAny<PFFunc2El>);
static_assert(!cHasOperatorDeleteAny<FFunc0ElRef>);
static_assert(!cHasOperatorDeleteAny<FFunc1ElRef>);
static_assert(!cHasOperatorDeleteAny<FFunc2ElRef>);
static_assert(!cHasOperatorDeleteAny<FFunc0ElRRef>);
static_assert(!cHasOperatorDeleteAny<FFunc1ElRRef>);
static_assert(!cHasOperatorDeleteAny<FFunc2ElRRef>);
static_assert(!cHasOperatorDeleteAny<FFunc0ElPtr>);
static_assert(!cHasOperatorDeleteAny<FFunc1ElPtr>);
static_assert(!cHasOperatorDeleteAny<FFunc2ElPtr>);
static_assert(!cHasOperatorDeleteAny<FFunc0ElPtrC>);
static_assert(!cHasOperatorDeleteAny<FFunc1ElPtrC>);
static_assert(!cHasOperatorDeleteAny<FFunc2ElPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc0ElPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc1ElPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc2ElPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc0ElPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc1ElPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc2ElPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc0ElCPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc1ElCPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc2ElCPtr>);
static_assert(!cHasOperatorDeleteAny<FMFunc0ElCPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc1ElCPtrC>);
static_assert(!cHasOperatorDeleteAny<FMFunc2ElCPtrC>);
static_assert(!cHasOperatorDeleteAny<CMPtr>);
static_assert(!cHasOperatorDeleteAny<CMCPtr>);
static_assert(!cHasOperatorDeleteAny<CMPtrC>);
static_assert(!cHasOperatorDeleteAny<CMCPtrC>);
static_assert(!cHasOperatorDeleteAny<CTestArray2>);
static_assert(!cHasOperatorDeleteAny<CTestArray2C>);
static_assert(!cHasOperatorDeleteAny<CTestArray>);
static_assert(!cHasOperatorDeleteAny<CTestArrayC>);
static_assert(!cHasOperatorDeleteAny<CTest2DArray2>);
static_assert(!cHasOperatorDeleteAny<CTest2DArray2C>);
static_assert(!cHasOperatorDeleteAny<CTest2DArray>);
static_assert(!cHasOperatorDeleteAny<CTest2DArrayC>);
static_assert(!cHasOperatorDeleteAny<CTest3DArray2>);
static_assert(!cHasOperatorDeleteAny<CTest3DArray2C>);
static_assert(!cHasOperatorDeleteAny<CTest3DArray>);
static_assert(!cHasOperatorDeleteAny<CTest3DArrayC>);
static_assert(!cHasOperatorDeleteAny<void *>);
static_assert(!cHasOperatorDeleteAny<void>);
static_assert(!cHasOperatorDeleteAny<CTestStructFinal>);
