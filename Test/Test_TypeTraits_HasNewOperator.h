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

	DMibStaticCheck((	TCIsOperatorCallable_New<CWithNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithNewArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithNewBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithNew>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithNewArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithNewBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithNewArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithNewDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithNewArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithDelete>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithBothDerived>::mc_Value						));

	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithNew, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithNewArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithNewBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithNewDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDelete, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDeleteArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDeleteBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDeleteDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithBothDerived, void *(mint)>::mc_Value						));

#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithNew, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithNewArray, void *(mint)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithNewBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithNewDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDelete, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDeleteArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDeleteBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDeleteDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithBothDerived, void *(mint)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNew, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNewArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNewBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNewDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDelete, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDeleteArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDeleteBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDeleteDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithBothDerived, void (void *)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNew, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNewArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNewBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNewDerived, void (void *)>::mc_Value						));
#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDelete, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDeleteArray, void (void *)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDeleteBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDeleteDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithBothDerived, void (void *)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithNew, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithNewArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithNewBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithNewDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDelete, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDeleteArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDeleteBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDeleteDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithBothDerived, void *(mint, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithNew, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithNewArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithNewBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithNewDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDelete, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDeleteArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDeleteBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDeleteDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithBothDerived, void *(mint, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNew, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNewArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNewBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithNewDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDelete, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDeleteArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDeleteBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDeleteDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithBothDerived, void (void *, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNew, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNewArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNewBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithNewDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDelete, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDeleteArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDeleteBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDeleteDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithBothDerived, void (void *, CTestClass0)>::mc_Value						));

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

	DMibStaticCheck((	TCIsOperatorCallable_New<CWithSpecialNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithSpecialNewArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithSpecialNewBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithSpecialNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithSpecialDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithSpecialDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithSpecialDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithSpecialDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithSpecialBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithSpecialNew>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithSpecialNewArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithSpecialNewBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithSpecialNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithSpecialDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithSpecialDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithSpecialDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithSpecialDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithSpecialBothDerived>::mc_Value						));

#if _MSC_FULL_VER != 191225830
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithSpecialNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithSpecialNewArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithSpecialNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithSpecialNewDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithSpecialDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithSpecialDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithSpecialDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithSpecialDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithSpecialBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithSpecialNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithSpecialNewArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithSpecialNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithSpecialNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithSpecialDelete>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithSpecialDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithSpecialDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithSpecialDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithSpecialBothDerived>::mc_Value						));
#endif

	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialNew, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialNewArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialNewBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialNewDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDelete, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDeleteArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDeleteBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDeleteDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialBothDerived, void *(mint)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialNew, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialNewArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialNewBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialNewDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDelete, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDeleteArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDeleteBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDeleteDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialBothDerived, void *(mint)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNew, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNewArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNewBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNewDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialDelete, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialDeleteArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialDeleteBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialDeleteDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialBothDerived, void (void *)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNew, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNewArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNewBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNewDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialDelete, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialDeleteArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialDeleteBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialDeleteDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialBothDerived, void (void *)>::mc_Value						));

	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithSpecialNew, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialNewArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithSpecialNewBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithSpecialNewDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDelete, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDeleteArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDeleteBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithSpecialDeleteDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithSpecialBothDerived, void *(mint, CTestClass0)>::mc_Value						));

#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialNew, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithSpecialNewArray, void *(mint, CTestClass0)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithSpecialNewBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithSpecialNewDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDelete, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDeleteArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDeleteBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithSpecialDeleteDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithSpecialBothDerived, void *(mint, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNew, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNewArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNewBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialNewDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithSpecialDelete, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithSpecialDeleteArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithSpecialDeleteBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithSpecialDeleteDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithSpecialBothDerived, void (void *, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNew, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNewArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNewBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialNewDerived, void (void *, CTestClass0)>::mc_Value						));
#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithSpecialDelete, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithSpecialDeleteArray, void (void *, CTestClass0)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithSpecialDeleteBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithSpecialDeleteDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithSpecialBothDerived, void (void *, CTestClass0)>::mc_Value						));

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
	DMibStaticCheck((	TCHasOperatorNew<CWithDualBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCHasOperatorDelete<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCHasOperatorDelete<CWithDualBothDerived>::mc_Value						));

	DMibStaticCheck((	TCIsOperatorCallable_New<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_New<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_New<CWithDualBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_NewArray<CWithDualBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_Delete<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_Delete<CWithDualBothDerived>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithDualNew>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithDualNewArray>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithDualNewBoth>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithDualNewDerived>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CWithDualDelete>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDualDeleteArray>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDualDeleteBoth>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDualDeleteDerived>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallable_DeleteArray<CWithDualBothDerived>::mc_Value						));

	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualNew, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualNewArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualNewBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualNewDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDelete, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDeleteArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDeleteBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDeleteDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualBothDerived, void *(mint)>::mc_Value						));

#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualNew, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualNewArray, void *(mint)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualNewBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualNewDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDelete, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDeleteArray, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDeleteBoth, void *(mint)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDeleteDerived, void *(mint)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualBothDerived, void *(mint)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNew, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNewArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNewBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNewDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualDelete, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualDeleteArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualDeleteBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualDeleteDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualBothDerived, void (void *)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNew, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNewArray, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNewBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNewDerived, void (void *)>::mc_Value						));
#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualDelete, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualDeleteArray, void (void *)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualDeleteBoth, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualDeleteDerived, void (void *)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualBothDerived, void (void *)>::mc_Value						));

	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualNew, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualNewArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualNewBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualNewDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDelete, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDeleteArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDeleteBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_New<CWithDualDeleteDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_New<CWithDualBothDerived, void *(mint, CTestClass0)>::mc_Value						));

#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualNew, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualNewArray, void *(mint, CTestClass0)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualNewBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualNewDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDelete, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDeleteArray, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDeleteBoth, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CWithDualDeleteDerived, void *(mint, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_NewArray<CWithDualBothDerived, void *(mint, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNew, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNewArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNewBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualNewDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualDelete, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CWithDualDeleteArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualDeleteBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualDeleteDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_Delete<CWithDualBothDerived, void (void *, CTestClass0)>::mc_Value						));

	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNew, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNewArray, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNewBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualNewDerived, void (void *, CTestClass0)>::mc_Value						));
#if _MSC_VER != 1925
	DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CWithDualDelete, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualDeleteArray, void (void *, CTestClass0)>::mc_Value						));
#endif
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualDeleteBoth, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualDeleteDerived, void (void *, CTestClass0)>::mc_Value						));
	DMibStaticCheck((	TCIsOperatorCallableWith_DeleteArray<CWithDualBothDerived, void (void *, CTestClass0)>::mc_Value						));
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



DMibStaticCheck((	!TCIsOperatorCallable_New<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_New<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_New<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_New<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_New<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<int>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_New<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_New<void *>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_New<void>::mc_Value							));



DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<int>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<void *>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_NewArray<void>::mc_Value							));



DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<int>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<void *>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_Delete<void>::mc_Value							));



DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestUnion>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestClass0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestClass1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestStruct0>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestStruct1>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<const CTestClass0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<const CTestClass1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<const CTestStruct0>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<const CTestStruct1>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<ETestEnum>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<int>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestClass>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestC>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestCRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestCRRef>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<PFFunc0>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<PFFunc1>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<PFFunc2>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2Ref>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2RRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2Ptr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2Ptr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2PtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2CPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2CPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<PFFunc0El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<PFFunc1El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<PFFunc2El>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2ElRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2ElRRef>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2ElPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2ElPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2ElPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2ElCPtr>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc0ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc1ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<FMFunc2ElCPtrC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CMPtr>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CMCPtr>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CMPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CMCPtrC>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestArray2C>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTestArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest2DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest2DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest2DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest2DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest3DArray2>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest3DArray2C>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest3DArray>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<CTest3DArrayC>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<void *>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallable_DeleteArray<void>::mc_Value							));


DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestUnion, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestClass0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestClass1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestStruct0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestStruct1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<const CTestClass0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<const CTestClass1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<const CTestStruct0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<const CTestStruct1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<ETestEnum, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<int, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestClass, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestC, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestCRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestCRRef, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<PFFunc0, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<PFFunc1, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<PFFunc2, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<PFFunc0El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<PFFunc1El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<PFFunc2El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc0ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc1ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<FMFunc2ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CMPtr, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CMCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CMPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CMCPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestArray2C, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTestArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest2DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest2DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest2DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest2DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest3DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest3DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest3DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<CTest3DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<void *, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_New<void, void * (mint)>::mc_Value							));



DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestUnion, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestClass0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestClass1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestStruct0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestStruct1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<const CTestClass0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<const CTestClass1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<const CTestStruct0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<const CTestStruct1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<ETestEnum, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<int, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestClass, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestC, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestCRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestCRRef, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<PFFunc0, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<PFFunc1, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<PFFunc2, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<PFFunc0El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<PFFunc1El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<PFFunc2El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc0ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc1ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<FMFunc2ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CMPtr, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CMCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CMPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CMCPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestArray2C, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTestArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest2DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest2DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest2DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest2DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest3DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest3DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest3DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<CTest3DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<void *, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_NewArray<void, void * (mint)>::mc_Value							));



DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestUnion, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestClass0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestClass1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestStruct0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestStruct1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<const CTestClass0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<const CTestClass1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<const CTestStruct0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<const CTestStruct1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<ETestEnum, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<int, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestClass, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestC, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestCRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestCRRef, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<PFFunc0, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<PFFunc1, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<PFFunc2, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<PFFunc0El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<PFFunc1El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<PFFunc2El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc0ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc1ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<FMFunc2ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CMPtr, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CMCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CMPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CMCPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestArray2C, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTestArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest2DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest2DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest2DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest2DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest3DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest3DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest3DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<CTest3DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<void *, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_Delete<void, void * (mint)>::mc_Value							));


DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestUnion, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestClass0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestClass1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestStruct0, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestStruct1, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<const CTestClass0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<const CTestClass1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<const CTestStruct0, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<const CTestStruct1, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<ETestEnum, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<int, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestClass, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestC, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestCRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestCRRef, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<PFFunc0, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<PFFunc1, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<PFFunc2, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2Ref, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2RRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2Ptr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2Ptr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2PtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2CPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2CPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<PFFunc0El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<PFFunc1El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<PFFunc2El, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2ElRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2ElRRef, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2ElPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2ElPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2ElPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2ElCPtr, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc0ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc1ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<FMFunc2ElCPtrC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CMPtr, void * (mint)>::mc_Value							));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CMCPtr, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CMPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CMCPtrC, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestArray2C, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTestArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest2DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest2DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest2DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest2DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest3DArray2, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest3DArray2C, void * (mint)>::mc_Value				));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest3DArray, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<CTest3DArrayC, void * (mint)>::mc_Value					));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<void *, void * (mint)>::mc_Value						));
DMibStaticCheck((	!TCIsOperatorCallableWith_DeleteArray<void, void * (mint)>::mc_Value							));
