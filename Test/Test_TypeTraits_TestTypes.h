// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

class CTestClass0
{
};

typedef CTestClass0 CTypedeffedClass0;

class CTestClass1
{
public:
	int m_Member;
};

struct CTestStruct0
{
};

struct CTestStruct1
{
	int m_Member;
};

struct CTestStruct2
{
	int m_Member;
};

struct CTestStruct3
{
	int m_Member()
	{
		return 0;
	}
};

struct CTestStruct4
{
	int m_Member(int)
	{
		return 1;
	}
};

struct CTestStruct5
{
	static int m_Member()
	{
		return 0;
	}
};

struct CTestStruct6
{
	static int m_Member(int)
	{
		return 1;
	}
};

struct CTestStruct7
{
	int m_Member()
	{
		return 0;
	}
	int m_Member(int)
	{
		return 1;
	}
};

struct CTestStruct8
{
	static int m_Member()
	{
		return 0;
	}
	static int m_Member(int)
	{
		return 1;
	}
};

struct CTestStruct9
{
	int m_Member()
	{
		return 0;
	}
	static int m_Member(int)
	{
		return 1;
	}
};

struct CTestStruct10
{
	static int m_Member;
};

struct CTestStruct11 : public CTestStruct10
{
};

struct CTestStruct12 : public CTestStruct2
{
};

struct CTestStruct13 : public CTestStruct3
{
};

using namespace NMib::NTraits;

enum ETestEnum
{
	ETestEnum_0,
	ETestEnum_1,
};

union CTestUnion
{
	int m_Member;
	float m_Member1;
};

union CTestUnion1
{
	int m_Member2;
	float m_Member1;
};

union CTestUnion2
{
	int m_Member;
};

union CTestUnion3
{
	int m_Member()
	{
		return 0;
	}
};

union CTestUnion4
{
	int m_Member(int)
	{
		return 1;
	}
};

union CTestUnion5
{
	static int m_Member()
	{
		return 0;
	}
};

union CTestUnion6
{
	static int m_Member(int)
	{
		return 1;
	}
};

union CTestUnion7
{
	int m_Member()
	{
		return 1;
	}
	static int m_Member(int)
	{
		return 1;
	}
};

class CTestClassVirtual
{
public:
	int m_Test;
	virtual void f_Test()
	{
	}
};

class CTestClassWithDestructor
{
public:
	int m_Test;
	~CTestClassWithDestructor()
	{
	}
};

class CTestClassWithDestructorNonTrivial
{
public:
	int m_Test;
	~CTestClassWithDestructorNonTrivial()
	{
		m_Test = 2;
	}
};

class CTestClassWithConstructor
{
public:
	int m_Test;
	CTestClassWithConstructor()
	{
	}
};

class CTestClassWithConstructorNonTrivial
{
public:
	int m_Test;
	CTestClassWithConstructorNonTrivial()
	{
		m_Test = 3;
	}
};

class CTestClassWithCopyConstructor
{
public:
	int m_Test;
	CTestClassWithCopyConstructor(CTestClassWithCopyConstructor const &_Other) : m_Test(_Other.m_Test)
	{
	}
};


class CTestClassWithCopyConstructorNonTrivial
{
public:
	int m_Test;
	CTestClassWithCopyConstructorNonTrivial(CTestClassWithCopyConstructorNonTrivial const &_Other)
	{
		m_Test = _Other.m_Test + 1;
	}
};

class CTestClassWithMoveConstructor
{
public:
	int m_Test;
	CTestClassWithMoveConstructor(CTestClassWithCopyConstructor const &&_Other) : m_Test(_Other.m_Test)
	{
	}
};

class CTestClassWithMoveConstructorNonTrivial
{
public:
	int m_Test;
	CTestClassWithMoveConstructorNonTrivial(CTestClassWithMoveConstructorNonTrivial const &&_Other)
	{
		m_Test = _Other.m_Test + 1;
	}
};

class CTestClassWithPrivateConstructor
{
	CTestClassWithPrivateConstructor()
	{
	}
public:
	int m_Test;
};

class CTestClassWithPrivateDestructor
{
	CTestClassWithPrivateDestructor()
	{
	}
public:
	int m_Test;
};

class CTestClassWithEnum
{
public:
	ETestEnum m_Test;
};

class CTestClassWithBase : public CTestClass1
{
public:
	int m_Test;
};

class CTestClassWithPrivate
{
private:
	ETestEnum m_Test;
public:
};




struct CTestBase
{
	int m_Test;
};

typedef CTestBase CTestClass;
typedef CTestBase const CTestC;
typedef CTestBase volatile CTestV;
typedef CTestBase const volatile CTestCV;

typedef CTestBase * CTestPtr;
typedef CTestBase const * CTestCPtr;
typedef CTestBase volatile * CTestVPtr;
typedef CTestBase const volatile * CTestCVPtr;

typedef CTestBase * const CTestPtrC;
typedef CTestBase const * const CTestCPtrC;
typedef CTestBase volatile * const CTestVPtrC;
typedef CTestBase const volatile * const CTestCVPtrC;

typedef CTestBase * volatile CTestPtrV;
typedef CTestBase const * volatile CTestCPtrV;
typedef CTestBase volatile * volatile CTestVPtrV;
typedef CTestBase const volatile * volatile CTestCVPtrV;

typedef CTestBase * const volatile CTestPtrCV;
typedef CTestBase const * const volatile CTestCPtrCV;
typedef CTestBase volatile * const volatile CTestVPtrCV;
typedef CTestBase const volatile * const volatile CTestCVPtrCV;

typedef CTestBase & CTestRef;
typedef CTestBase const & CTestCRef;
typedef CTestBase volatile & CTestVRef;
typedef CTestBase const volatile & CTestCVRef;

typedef CTestBase && CTestRRef;
typedef CTestBase const && CTestCRRef;
typedef CTestBase volatile && CTestVRRef;
typedef CTestBase const volatile && CTestCVRRef;


static void fsg_FFunc0(void)
{
}
static CTestBase fsg_FFunc1(void)
{
	return CTestBase();
}
static CTestBase fsg_FFunc2(int)
{
	return CTestBase();
}

typedef void (PFFunc0)(void);
typedef CTestBase (PFFunc1)(void);
typedef CTestBase (PFFunc2)(int);
typedef PFFunc0 * FFunc0Ptr;
typedef PFFunc1 * FFunc1Ptr;
typedef PFFunc2 * FFunc2Ptr;
typedef PFFunc0 & FFunc0Ref;
typedef PFFunc1 & FFunc1Ref;
typedef PFFunc2 & FFunc2Ref;
// Function rrefs shouldn't be possible?
typedef PFFunc0 && FFunc0RRef;
typedef PFFunc1 && FFunc1RRef;
typedef PFFunc2 && FFunc2RRef;
typedef FFunc0Ptr const FFunc0PtrC;
typedef FFunc1Ptr const FFunc1PtrC;
typedef FFunc2Ptr const FFunc2PtrC;
typedef FFunc0Ptr volatile FFunc0PtrV;
typedef FFunc1Ptr volatile FFunc1PtrV;
typedef FFunc2Ptr volatile FFunc2PtrV;
typedef FFunc0Ptr const volatile FFunc0PtrCV;
typedef FFunc1Ptr const volatile FFunc1PtrCV;
typedef FFunc2Ptr const volatile FFunc2PtrCV;

static void fsg_FFunc0El(...)
{
}
static CTestBase fsg_FFunc1El(...)
{
	return CTestBase();
}
static CTestBase fsg_FFunc2El(CTestBase, ...)
{
	return CTestBase();
}

typedef void (PFFunc0El)(...);
typedef CTestBase (PFFunc1El)(...);
typedef CTestBase (PFFunc2El)(CTestBase, ...);
typedef PFFunc0El * FFunc0ElPtr;
typedef PFFunc1El * FFunc1ElPtr;
typedef PFFunc2El * FFunc2ElPtr;
typedef PFFunc0El & FFunc0ElRef;
typedef PFFunc1El & FFunc1ElRef;
typedef PFFunc2El & FFunc2ElRef;
// Function rrefs shouldn't be possible?
typedef PFFunc0El && FFunc0ElRRef;
typedef PFFunc1El && FFunc1ElRRef;
typedef PFFunc2El && FFunc2ElRRef;
typedef FFunc0ElPtr const FFunc0ElPtrC;
typedef FFunc1ElPtr const FFunc1ElPtrC;
typedef FFunc2ElPtr const FFunc2ElPtrC;
typedef FFunc0ElPtr volatile FFunc0ElPtrV;
typedef FFunc1ElPtr volatile FFunc1ElPtrV;
typedef FFunc2ElPtr volatile FFunc2ElPtrV;
typedef FFunc0ElPtr const volatile FFunc0ElPtrCV;
typedef FFunc1ElPtr const volatile FFunc1ElPtrCV;
typedef FFunc2ElPtr const volatile FFunc2ElPtrCV;

typedef void (CTestClass0::* FMFunc0Ptr)(void);
typedef CTestBase (CTestClass0::* FMFunc1Ptr)(void);
typedef CTestBase (CTestClass0::* FMFunc2Ptr)(int);
typedef FMFunc0Ptr const FMFunc0PtrC;
typedef FMFunc1Ptr const FMFunc1PtrC;
typedef FMFunc2Ptr const FMFunc2PtrC;
typedef FMFunc0Ptr volatile FMFunc0PtrV;
typedef FMFunc1Ptr volatile FMFunc1PtrV;
typedef FMFunc2Ptr volatile FMFunc2PtrV;
typedef FMFunc0Ptr const volatile FMFunc0PtrCV;
typedef FMFunc1Ptr const volatile FMFunc1PtrCV;
typedef FMFunc2Ptr const volatile FMFunc2PtrCV;

typedef void (CTestClass0::* FMFunc0CPtr)(void) const;
typedef CTestBase (CTestClass0::* FMFunc1CPtr)(void) const;
typedef CTestBase (CTestClass0::* FMFunc2CPtr)(int) const;
typedef FMFunc0CPtr const FMFunc0CPtrC;
typedef FMFunc1CPtr const FMFunc1CPtrC;
typedef FMFunc2CPtr const FMFunc2CPtrC;
typedef FMFunc0CPtr volatile FMFunc0CPtrV;
typedef FMFunc1CPtr volatile FMFunc1CPtrV;
typedef FMFunc2CPtr volatile FMFunc2CPtrV;
typedef FMFunc0CPtr const volatile FMFunc0CPtrCV;
typedef FMFunc1CPtr const volatile FMFunc1CPtrCV;
typedef FMFunc2CPtr const volatile FMFunc2CPtrCV;

typedef void (CTestClass0::* FMFunc0VPtr)(void) volatile;
typedef CTestBase (CTestClass0::* FMFunc1VPtr)(void) volatile;
typedef CTestBase (CTestClass0::* FMFunc2VPtr)(int) volatile;
typedef FMFunc0VPtr const FMFunc0VPtrC;
typedef FMFunc1VPtr const FMFunc1VPtrC;
typedef FMFunc2VPtr const FMFunc2VPtrC;
typedef FMFunc0VPtr volatile FMFunc0VPtrV;
typedef FMFunc1VPtr volatile FMFunc1VPtrV;
typedef FMFunc2VPtr volatile FMFunc2VPtrV;
typedef FMFunc0VPtr const volatile FMFunc0VPtrCV;
typedef FMFunc1VPtr const volatile FMFunc1VPtrCV;
typedef FMFunc2VPtr const volatile FMFunc2VPtrCV;

typedef void (CTestClass0::* FMFunc0CVPtr)(void) const volatile;
typedef CTestBase (CTestClass0::* FMFunc1CVPtr)(void) const volatile;
typedef CTestBase (CTestClass0::* FMFunc2CVPtr)(int) const volatile;
typedef FMFunc0CVPtr const FMFunc0CVPtrC;
typedef FMFunc1CVPtr const FMFunc1CVPtrC;
typedef FMFunc2CVPtr const FMFunc2CVPtrC;
typedef FMFunc0CVPtr volatile FMFunc0CVPtrV;
typedef FMFunc1CVPtr volatile FMFunc1CVPtrV;
typedef FMFunc2CVPtr volatile FMFunc2CVPtrV;
typedef FMFunc0CVPtr const volatile FMFunc0CVPtrCV;
typedef FMFunc1CVPtr const volatile FMFunc1CVPtrCV;
typedef FMFunc2CVPtr const volatile FMFunc2CVPtrCV;

typedef void (CTestClass0::* FMFunc0ElPtr)(...);
typedef CTestBase (CTestClass0::* FMFunc1ElPtr)(...);
typedef CTestBase (CTestClass0::* FMFunc2ElPtr)(CTestBase, ...);
typedef FMFunc0ElPtr const FMFunc0ElPtrC;
typedef FMFunc1ElPtr const FMFunc1ElPtrC;
typedef FMFunc2ElPtr const FMFunc2ElPtrC;
typedef FMFunc0ElPtr volatile FMFunc0ElPtrV;
typedef FMFunc1ElPtr volatile FMFunc1ElPtrV;
typedef FMFunc2ElPtr volatile FMFunc2ElPtrV;
typedef FMFunc0ElPtr const volatile FMFunc0ElPtrCV;
typedef FMFunc1ElPtr const volatile FMFunc1ElPtrCV;
typedef FMFunc2ElPtr const volatile FMFunc2ElPtrCV;

typedef void (CTestClass0::* FMFunc0ElCPtr)(...) const;
typedef CTestBase (CTestClass0::* FMFunc1ElCPtr)(...) const;
typedef CTestBase (CTestClass0::* FMFunc2ElCPtr)(CTestBase, ...) const;
typedef FMFunc0ElCPtr const FMFunc0ElCPtrC;
typedef FMFunc1ElCPtr const FMFunc1ElCPtrC;
typedef FMFunc2ElCPtr const FMFunc2ElCPtrC;
typedef FMFunc0ElCPtr volatile FMFunc0ElCPtrV;
typedef FMFunc1ElCPtr volatile FMFunc1ElCPtrV;
typedef FMFunc2ElCPtr volatile FMFunc2ElCPtrV;
typedef FMFunc0ElCPtr const volatile FMFunc0ElCPtrCV;
typedef FMFunc1ElCPtr const volatile FMFunc1ElCPtrCV;
typedef FMFunc2ElCPtr const volatile FMFunc2ElCPtrCV;

typedef void (CTestClass0::* FMFunc0ElVPtr)(...) volatile;
typedef CTestBase (CTestClass0::* FMFunc1ElVPtr)(...) volatile;
typedef CTestBase (CTestClass0::* FMFunc2ElVPtr)(CTestBase, ...) volatile;
typedef FMFunc0ElVPtr const FMFunc0ElVPtrC;
typedef FMFunc1ElVPtr const FMFunc1ElVPtrC;
typedef FMFunc2ElVPtr const FMFunc2ElVPtrC;
typedef FMFunc0ElVPtr volatile FMFunc0ElVPtrV;
typedef FMFunc1ElVPtr volatile FMFunc1ElVPtrV;
typedef FMFunc2ElVPtr volatile FMFunc2ElVPtrV;
typedef FMFunc0ElVPtr const volatile FMFunc0ElVPtrCV;
typedef FMFunc1ElVPtr const volatile FMFunc1ElVPtrCV;
typedef FMFunc2ElVPtr const volatile FMFunc2ElVPtrCV;

typedef void (CTestClass0::* FMFunc0ElCVPtr)(...) const volatile;
typedef CTestBase (CTestClass0::* FMFunc1ElCVPtr)(...) const volatile;
typedef CTestBase (CTestClass0::* FMFunc2ElCVPtr)(CTestBase, ...) const volatile;
typedef FMFunc0ElCVPtr const FMFunc0ElCVPtrC;
typedef FMFunc1ElCVPtr const FMFunc1ElCVPtrC;
typedef FMFunc2ElCVPtr const FMFunc2ElCVPtrC;
typedef FMFunc0ElCVPtr volatile FMFunc0ElCVPtrV;
typedef FMFunc1ElCVPtr volatile FMFunc1ElCVPtrV;
typedef FMFunc2ElCVPtr volatile FMFunc2ElCVPtrV;
typedef FMFunc0ElCVPtr const volatile FMFunc0ElCVPtrCV;
typedef FMFunc1ElCVPtr const volatile FMFunc1ElCVPtrCV;
typedef FMFunc2ElCVPtr const volatile FMFunc2ElCVPtrCV;


typedef CTestBase CTestClass0::* CMPtr;
typedef CTestBase const CTestClass0::* CMCPtr;
typedef CTestBase volatile CTestClass0::* CMVPtr;
typedef CTestBase const volatile CTestClass0::* CMCVPtr;
typedef CMPtr const CMPtrC;
typedef CMCPtr const CMCPtrC;
typedef CMVPtr const CMVPtrC;
typedef CMCVPtr const CMCVPtrC;
typedef CMPtr volatile CMPtrV;
typedef CMCPtr volatile CMCPtrV;
typedef CMVPtr volatile CMVPtrV;
typedef CMCVPtr volatile CMCVPtrV;
typedef CMPtr const volatile CMPtrCV;
typedef CMCPtr const volatile CMCPtrCV;
typedef CMVPtr const volatile CMVPtrCV;
typedef CMCVPtr const volatile CMCVPtrCV;

typedef CTestBase CTestArray2 [2] ;
typedef const CTestBase CTestArray2C [2] ;
typedef volatile CTestBase CTestArray2V [2] ;
typedef const volatile CTestBase CTestArray2CV [2] ;

typedef CTestBase CTestArray [] ;
typedef const CTestBase CTestArrayC [] ;
typedef volatile CTestBase CTestArrayV [] ;
typedef const volatile CTestBase CTestArrayCV [] ;

typedef CTestBase CTest2DArray2 [3][2] ;
typedef const CTestBase CTest2DArray2C [3][2] ;
typedef volatile CTestBase CTest2DArray2V [3][2] ;
typedef const volatile CTestBase CTest2DArray2CV [3][2] ;

typedef CTestBase CTest2DArray [][2] ;
typedef const CTestBase CTest2DArrayC [][2] ;
typedef volatile CTestBase CTest2DArrayV [][2] ;
typedef const volatile CTestBase CTest2DArrayCV [][2] ;

typedef CTestBase CTest3DArray2 [4][3][2] ;
typedef const CTestBase CTest3DArray2C [4][3][2] ;
typedef volatile CTestBase CTest3DArray2V [4][3][2] ;
typedef const volatile CTestBase CTest3DArray2CV [4][3][2] ;

typedef CTestBase CTest3DArray [][3][2] ;
typedef const CTestBase CTest3DArrayC [][3][2] ;
typedef volatile CTestBase CTest3DArrayV [][3][2] ;
typedef const volatile CTestBase CTest3DArrayCV [][3][2] ;


struct CTestNoDefaultConstruct
{
	mint m_Value;
	CTestNoDefaultConstruct(int &&_Value)
		: m_Value(_Value)
	{

	}
};

typedef CTestNoDefaultConstruct CTestArrayNoDefault [2] ;

