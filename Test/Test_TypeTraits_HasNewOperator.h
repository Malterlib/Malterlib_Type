// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Test_TypeTraits_TestTypes.h"

#include <boost/type_traits/has_new_operator.hpp>

namespace NHasNewOperator
{

	class CWithNew
	{
	public:
		void * operator new(mint _Value);
	};

	class CWithNewArray
	{
	public:
		void * operator new [](mint _Value);
	};

	class CWithNewBoth
	{
	public:
		void * operator new(mint _Value);
		void * operator new [](mint _Value);
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
		void * operator new(mint _Value, CTestClass0 _Special);
	};

	class CWithSpecialNewArray
	{
	public:
		void * operator new [](mint _Value, CTestClass0 _Special);
	};

	class CWithSpecialNewBoth
	{
	public:
		void * operator new(mint _Value, CTestClass0 _Special);
		void * operator new [](mint _Value, CTestClass0 _Special);
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
		void * operator new(mint _Value, CTestClass0 _Special);
		void * operator new(mint _Value);
	};

	class CWithDualNewArray
	{
	public:
		void * operator new [](mint _Value, CTestClass0 _Special);
		void * operator new [](mint _Value);
	};

	class CWithDualNewBoth
	{
	public:
		void * operator new(mint _Value, CTestClass0 _Special);
		void * operator new [](mint _Value, CTestClass0 _Special);
		void * operator new(mint _Value);
		void * operator new [](mint _Value);
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
//		void *pTest = CWithNew::operator new(5);
	//	CWithDelete::operator delete(pTest);
	}
	
	

	DMibStaticCheck((	TCHasOperatorNew<CWithNew>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithNewArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithNewBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDelete>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithBothDerived>::mc_Value						));


	DMibStaticCheck((	!TCHasOperatorDelete<CWithNew>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithNewArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithNewDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDelete>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithBothDerived>::mc_Value						));

	/////////////////
	///////
	/////////


	DMibStaticCheck((	TCHasOperatorNew<CWithSpecialNew>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithSpecialNewArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithSpecialNewBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithSpecialNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithSpecialDelete>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithSpecialDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithSpecialDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithSpecialDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithSpecialBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCHasOperatorDelete<CWithSpecialNew>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithSpecialNewArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithSpecialNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithSpecialNewDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithSpecialDelete>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithSpecialDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithSpecialDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithSpecialDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithSpecialBothDerived>::mc_Value						));

	////
	////
	/////////////

	DMibStaticCheck((	TCHasOperatorNew<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorNew<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorNew<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	cHasOperatorNewAny<CWithDualBothDerived>						));

	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualBothDerived>::mc_Value						));

}

// Void

DMibStaticCheck((	!TCHasOperatorNew<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorNew<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorNew<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorNew<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorNew<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<int>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorNew<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorNew<CTestC>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorNew<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorNew<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorNew<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorNew<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorNew<void *>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorNew<void>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorNew<CTestStructFinal>::mc_Value						));

DMibStaticCheck((	!TCHasOperatorDelete<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorDelete<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorDelete<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorDelete<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorDelete<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<int>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorDelete<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorDelete<CTestC>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorDelete<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorDelete<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorDelete<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCHasOperatorDelete<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCHasOperatorDelete<void *>::mc_Value						));
DMibStaticCheck((	!TCHasOperatorDelete<void>::mc_Value							));
DMibStaticCheck((	!TCHasOperatorDelete<CTestStructFinal>::mc_Value						));
