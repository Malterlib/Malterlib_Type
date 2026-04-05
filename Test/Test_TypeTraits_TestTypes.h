// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

#include <Mib/Numeric/fp80>
#include <Mib/Numeric/ufp80>
#include <Mib/Numeric/fp4096>
#include <Mib/Numeric/ufp4096>

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

struct CTestStructFinal final : public CTestStruct0
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

typedef CTestBase * CTestPtr;
typedef CTestBase const * CTestCPtr;

typedef CTestBase * const CTestPtrC;
typedef CTestBase const * const CTestCPtrC;

typedef CTestBase & CTestRef;
typedef CTestBase const & CTestCRef;

typedef CTestBase && CTestRRef;
typedef CTestBase const && CTestCRRef;


[[maybe_unused]] static void fsg_FFunc0(void)
{
}
[[maybe_unused]] static CTestBase fsg_FFunc1(void)
{
	return CTestBase();
}
[[maybe_unused]] static CTestBase fsg_FFunc2(int)
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

[[maybe_unused]] static void fsg_FFunc0El(...)
{
}
[[maybe_unused]] static CTestBase fsg_FFunc1El(...)
{
	return CTestBase();
}
[[maybe_unused]] static CTestBase fsg_FFunc2El(CTestBase, ...)
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

typedef void (CTestClass0::* FMFunc0Ptr)(void);
typedef CTestBase (CTestClass0::* FMFunc1Ptr)(void);
typedef CTestBase (CTestClass0::* FMFunc2Ptr)(int);
typedef FMFunc0Ptr const FMFunc0PtrC;
typedef FMFunc1Ptr const FMFunc1PtrC;
typedef FMFunc2Ptr const FMFunc2PtrC;

typedef void (CTestClass0::* FMFunc0CPtr)(void) const;
typedef CTestBase (CTestClass0::* FMFunc1CPtr)(void) const;
typedef CTestBase (CTestClass0::* FMFunc2CPtr)(int) const;
typedef FMFunc0CPtr const FMFunc0CPtrC;
typedef FMFunc1CPtr const FMFunc1CPtrC;
typedef FMFunc2CPtr const FMFunc2CPtrC;

typedef void (CTestClass0::* FMFunc0ElPtr)(...);
typedef CTestBase (CTestClass0::* FMFunc1ElPtr)(...);
typedef CTestBase (CTestClass0::* FMFunc2ElPtr)(CTestBase, ...);
typedef FMFunc0ElPtr const FMFunc0ElPtrC;
typedef FMFunc1ElPtr const FMFunc1ElPtrC;
typedef FMFunc2ElPtr const FMFunc2ElPtrC;

typedef void (CTestClass0::* FMFunc0ElCPtr)(...) const;
typedef CTestBase (CTestClass0::* FMFunc1ElCPtr)(...) const;
typedef CTestBase (CTestClass0::* FMFunc2ElCPtr)(CTestBase, ...) const;
typedef FMFunc0ElCPtr const FMFunc0ElCPtrC;
typedef FMFunc1ElCPtr const FMFunc1ElCPtrC;
typedef FMFunc2ElCPtr const FMFunc2ElCPtrC;

typedef CTestBase CTestClass0::* CMPtr;
typedef CTestBase const CTestClass0::* CMCPtr;
typedef CMPtr const CMPtrC;
typedef CMCPtr const CMCPtrC;

typedef CTestBase CTestArray2 [2] ;
typedef const CTestBase CTestArray2C [2] ;

typedef CTestBase CTestArray [] ;
typedef const CTestBase CTestArrayC [] ;

typedef CTestBase CTest2DArray2 [3][2] ;
typedef const CTestBase CTest2DArray2C [3][2] ;

typedef CTestBase CTest2DArray [][2] ;
typedef const CTestBase CTest2DArrayC [][2] ;

typedef CTestBase CTest3DArray2 [4][3][2] ;
typedef const CTestBase CTest3DArray2C [4][3][2] ;

typedef CTestBase CTest3DArray [][3][2] ;
typedef const CTestBase CTest3DArrayC [][3][2] ;

struct CTestNoDefaultConstruct
{
	umint m_Value;
	CTestNoDefaultConstruct(int &&_Value)
		: m_Value(_Value)
	{

	}
};

typedef CTestNoDefaultConstruct CTestArrayNoDefault [2] ;

