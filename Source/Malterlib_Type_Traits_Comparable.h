// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Properties.h"
#include "Malterlib_Type_Traits_CompileTimeConstant.h"
#include <Mib/Core/EnableIf>

namespace NMib::NPrivate::NTraits
{
	// when operator< is not available, this one is used
	class CNoConvertible
	{
	};

	struct CAny
	{
		template <class T>
		CAny(const T&) ;

	};

	CNoConvertible operator == (const CAny&, const CAny&);
	CNoConvertible operator != (const CAny&, const CAny&);
	CNoConvertible operator < (const CAny&, const CAny&);
	CNoConvertible operator <=> (const CAny&, const CAny&);
	CNoConvertible operator <= (const CAny&, const CAny&);
	CNoConvertible operator > (const CAny&, const CAny&);
	CNoConvertible operator >= (const CAny&, const CAny&);
}

namespace NMib::NTraits::NPrivate::NIsComparable
{
#if 1
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4800)
#pragma warning(disable:4018)
#pragma warning(disable:4389)
#endif

	template <typename t_CType>
	t_CType &fg_GetTypeRef();

	using namespace NMib::NPrivate::NTraits;

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableHelper
	{
	protected:
		typedef typename TCDecay<t_CLeft>::CType CDecayedLeft;
		typedef typename TCDecay<t_CRight>::CType CDecayedRight;
		static CFalseBySize  fs_IsBool(CAny);
		static CTrueBySize  fs_IsBool(t_CConvertibleTo);
		static CDecayedLeft &fs_GetLeft();
		static CDecayedRight &fs_GetRight();


	};
	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableEqualHelper : public TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo>
	{
		typedef TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo> CSuper;
	public:
		enum
		{
			EValue = sizeof(CSuper::fs_IsBool(CSuper::fs_GetLeft() == CSuper::fs_GetRight())) == sizeof(CTrueBySize),
		};
	};

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableNotEqualHelper : public TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo>
	{
		typedef TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo> CSuper;
	public:
		enum
		{
			EValue = sizeof(CSuper::fs_IsBool(CSuper::fs_GetLeft() != CSuper::fs_GetRight())) == sizeof(CTrueBySize),
		};
	};
/*
	template <typename t_CLeft, typename t_CRight>
	class TCIsConvertible : public TCCompileTimeConstant<bool, __is_convertible_to(t_CLeft, t_CRight)>
	{
	};*/

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableLessThanHelper : public TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo>
	{
		typedef TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo> CSuper;
	public:
		template <typename t_CLeft2, typename t_CRight2>
			static auto fs_Compare(const t_CLeft2 &_Left, const t_CRight2 &_Right) -> typename TCDisableIf<TCIsSame<decltype(CSuper::fs_IsBool(_Left < _Right)), CFalseBySize>::mc_Value, CTrueBySize>::CType;

		template <typename t_CLeft2, typename t_CRight2>
			static auto fs_Compare(const t_CLeft2 &_Left, const t_CRight2 &_Right) -> typename TCDisableIf<TCIsSame<decltype(CSuper::fs_IsBool(_Left < _Right)), CTrueBySize>::mc_Value, CFalseBySize>::CType;

			/*
		template <typename t_CLeft2, typename t_CRight2>
			static auto fs_Compare(t_CLeft2 &_Left, t_CRight2 &_Right) ->
				typename TCDisableIf<
					sizeof(CSuper::fs_IsBool(fg_GetTypeRef<t_CLeft2>() < fg_GetTypeRef<t_CRight2>())) == sizeof(CFalseBySize)
					, CTrueBySize
				>::CType;*/

		enum
		{
			//EValue = TCIsSame<decltype(fs_Compare(CSuper::fs_GetLeft(), CSuper::fs_GetRight())), CTrueBySize>::mc_Value,
			EValue = sizeof(CSuper::fs_IsBool(CSuper::fs_GetLeft() < CSuper::fs_GetRight())) == sizeof(CTrueBySize),
			//EValue = TCIsSame<decltype(CSuper::fs_IsBool(CSuper::fs_GetLeft() < CSuper::fs_GetRight())), CTrueBySize>::mc_Value,
		};
	};
	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableLessThanEqualHelper : public TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo>
	{
		typedef TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo> CSuper;
	public:
		enum
		{
			EValue = sizeof(CSuper::fs_IsBool(CSuper::fs_GetLeft() <= CSuper::fs_GetRight())) == sizeof(CTrueBySize),
		};
	};
	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableGreaterThanHelper : public TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo>
	{
		typedef TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo> CSuper;
	public:
		enum
		{
			EValue = sizeof(CSuper::fs_IsBool(CSuper::fs_GetLeft() > CSuper::fs_GetRight())) == sizeof(CTrueBySize),
		};
	};
	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo>
	class TCIsComparableGreaterThanEqualHelper : public TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo>
	{
		typedef TCIsComparableHelper<t_CLeft, t_CRight, t_CConvertibleTo> CSuper;
	public:
		enum
		{
			EValue = sizeof(CSuper::fs_IsBool(CSuper::fs_GetLeft() >= CSuper::fs_GetRight())) == sizeof(CTrueBySize),
		};
	};
}

#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif

namespace NMib::NTraits
{
	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo = bool>
	class TCIsComparableEqual : public TCCompileTimeConstant<bool, NPrivate::NIsComparable::TCIsComparableEqualHelper<t_CLeft, t_CRight, t_CConvertibleTo>::EValue>
	{
	public:
	};

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo = bool>
	class TCIsComparableNotEqual : public TCCompileTimeConstant<bool, NPrivate::NIsComparable::TCIsComparableNotEqualHelper<t_CLeft, t_CRight, t_CConvertibleTo>::EValue>
	{
	public:
	};

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo = bool>
	class TCIsComparableLessThan : public TCCompileTimeConstant<bool, NPrivate::NIsComparable::TCIsComparableLessThanHelper<t_CLeft, t_CRight, t_CConvertibleTo>::EValue>
	{
	public:
	};

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo = bool>
	class TCIsComparableLessThanEqual : public TCCompileTimeConstant<bool, NPrivate::NIsComparable::TCIsComparableLessThanEqualHelper<t_CLeft, t_CRight, t_CConvertibleTo>::EValue>
	{
	public:
	};

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo = bool>
	class TCIsComparableGreaterThan : public TCCompileTimeConstant<bool, NPrivate::NIsComparable::TCIsComparableGreaterThanHelper<t_CLeft, t_CRight, t_CConvertibleTo>::EValue>
	{
	public:
	};

	template <typename t_CLeft, typename t_CRight, typename t_CConvertibleTo = bool>
	class TCIsComparableGreaterThanEqual : public TCCompileTimeConstant<bool, NPrivate::NIsComparable::TCIsComparableGreaterThanEqualHelper<t_CLeft, t_CRight, t_CConvertibleTo>::EValue>
	{
	public:
	};
#endif
}
