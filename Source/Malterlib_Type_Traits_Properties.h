// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Qualifiers.h"
#include "Malterlib_Type_Traits_IntFloat.h"
#include <Mib/Preprocessor/Preprocessor>
#include <Mib/Meta/Meta>

#if defined(DMalterlibUseStaticLibCxx)
#	define DMibNewVisibility _LIBCPP_OVERRIDABLE_FUNC_VIS
#	include <stddef.h>

	namespace std
	{
		using ::nullptr_t;
		using ::ptrdiff_t _LIBCPP_USING_IF_EXISTS;
		using ::size_t _LIBCPP_USING_IF_EXISTS;
	}
#	include <__new/new.h>
#else
#	define DMibNewVisibility
#	include <new>
#endif

#include <type_traits>

namespace NMib::NTraits
{
	template <typename t_CFunction>
	class TCIsFunction;

	template <typename t_CType0>
	class TCRemoveReference;

	template <typename t_CType0>
	class TCAddPointer;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Convertible																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
#		if defined(DMibPIsTypeConvertibleToType)
			template <typename t_CTypeFrom, typename t_CTypeTo, bool t_bIsFunctions = NTraits::TCIsFunction<typename NTraits::TCRemoveReference<t_CTypeFrom>::CType>::mc_Value && NTraits::TCIsFunction<typename NTraits::TCRemoveReference<t_CTypeTo>::CType>::mc_Value>
			class TCIsConvertibleHelper
			{
			public:
				enum
				{
					mc_Value = DMibPIsTypeConvertibleToType(t_CTypeFrom, t_CTypeTo)
					|| (NTraits::TCIsVoid<t_CTypeFrom>::mc_Value && NTraits::TCIsVoid<t_CTypeTo>::mc_Value)
				};
			};
			template <typename t_CTypeFrom, typename t_CTypeTo>
			class TCIsConvertibleHelper<t_CTypeFrom, t_CTypeTo, true>
			{
			public:
				enum
				{
					mc_Value
						= !NTraits::TCIsFunction<t_CTypeFrom>::mc_Value
						&& !NTraits::TCIsFunction<t_CTypeTo>::mc_Value
						&& TCIsConvertibleHelper<typename NTraits::TCAddPointer<t_CTypeFrom>::CType, typename NTraits::TCAddPointer<t_CTypeTo>::CType>::mc_Value
				};
			};
#		else
			template
			<
				typename t_CTypeFrom,
				typename t_CTypeTo,
				bool t_bDisableCheck = NTraits::TCIsVoid<t_CTypeFrom>::mc_Value || NTraits::TCIsVoid<t_CTypeTo>::mc_Value || NTraits::TCIsFunction<t_CTypeTo>::mc_Value || NTraits::TCIsArray<t_CTypeTo>::mc_Value
			>
			class TCIsConvertibleHelper
			{
			public:
				enum
				{
					mc_Value = NTraits::TCIsVoid<t_CTypeFrom>::mc_Value && NTraits::TCIsVoid<t_CTypeTo>::mc_Value
				};
			};

			template <typename t_CTypeFrom, typename t_CTypeTo>
			class TCIsConvertibleHelper<t_CTypeFrom, t_CTypeTo, false>
			{
				static CTrueBySize fsp_Convertible(t_CTypeTo);
				static CFalseBySize fsp_Convertible(...);
				static t_CTypeFrom &fsp_FromType();
			public:

				enum
				{
					mc_Value = sizeof(fsp_Convertible(fsp_FromType())) == sizeof(CTrueBySize)
				};
			};
#		endif
	}

	template <typename t_CTypeFrom, typename t_CTypeTo>
	class TCIsConvertible : public TCCompileTimeConstant<bool, NPrivate::TCIsConvertibleHelper<t_CTypeFrom, t_CTypeTo>::mc_Value>
	{
	public:

	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Same																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType0, typename t_CType1>
		struct TCIsSameHelper
		{
			static constexpr bool mc_Value = false;
		};

		template <typename t_CType>
		struct TCIsSameHelper<t_CType, t_CType>
		{
			static constexpr bool mc_Value = true;
		};
	}

	template <typename t_CType0, typename t_CType1>
	class TCIsSame : public TCCompileTimeConstant<bool, NPrivate::TCIsSameHelper<t_CType0, t_CType1>::mc_Value>
	{
	public:
	};

	template <typename t_CType0, typename t_CType1>
	concept cIsSame = NPrivate::TCIsSameHelper<t_CType0, t_CType1>::mc_Value;

	template <typename t_CType0, typename t_CType1>
	class TCIsSameUnqualified : public TCCompileTimeConstant
		<
			bool
			, NPrivate::TCIsSameHelper<typename TCRemoveQualifiers<t_CType0>::CType, typename TCRemoveQualifiers<t_CType1>::CType>::mc_Value
		>
	{
	public:
	};

	template <typename t_CType>
	class TCRemoveReferenceAndQualifiers;

	template <typename t_CType0, typename t_CType1>
	class TCIsSameDereferencedUnqualified : public TCCompileTimeConstant
		<
			bool
			, NPrivate::TCIsSameHelper<typename TCRemoveReferenceAndQualifiers<t_CType0>::CType
			, typename TCRemoveReferenceAndQualifiers<t_CType1>::CType>::mc_Value
		>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| MakeValueDependent																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <auto t_Value, typename t_CMakeDependentOn>
	inline constexpr decltype(t_Value) gc_MakeValueDependent = t_Value;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Reference																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	// remove_reference
	// add_reference

	namespace NPrivate
	{
		template <typename t_CType>
		class TCIsReferenceHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCIsReferenceHelper<t_CType &>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CType>
		class TCIsReferenceHelper<t_CType &&>
		{
		public:
			enum
			{
				EValue = true
			};
		};


		template <typename t_CType>
		class TCAddReferenceHelper
		{
		public:
			typedef t_CType & CType;
		};

		template <typename t_CType>
		class TCAddReferenceHelper<t_CType &>
		{
		public:
			typedef t_CType & CType;
		};

		template <typename t_CType>
		class TCAddReferenceHelper<t_CType &&>
		{
		public:
			typedef t_CType && CType;
		};

		template <typename t_CType>
		class TCAddReferenceHelper<t_CType []>
		{
		public:
			typedef t_CType CType [];
		};

		template <>
		class TCAddReferenceHelper<void>
		{
		public:
			typedef void CType;
		};

		template <>
		class TCAddReferenceHelper<const void>
		{
		public:
			typedef void CType;
		};

		template <>
		class TCAddReferenceHelper<volatile void>
		{
		public:
			typedef void CType;
		};

		template <>
		class TCAddReferenceHelper<const volatile void>
		{
		public:
			typedef void CType;
		};


	}

	template <typename t_CType0>
	class TCIsReference : public TCCompileTimeConstant<bool, NPrivate::TCIsReferenceHelper<t_CType0>::EValue>
	{
	public:
	};

	template <typename t_CType0>
	class TCAddReference
	{
	public:
		typedef typename NPrivate::TCAddReferenceHelper<t_CType0>::CType CType;
	};

	template <typename t_CType>
	class TCRemoveReference
	{
	public:
		typedef t_CType CType;
	};

	template <typename t_CType>
	class TCRemoveReference<t_CType &>
	{
	public:
		typedef t_CType CType;
	};

	template <typename t_CType>
	class TCRemoveReference<t_CType &&>
	{
	public:
		typedef t_CType CType;
	};

	template <typename t_CType>
	using TCRemoveReferenceType = typename TCRemoveReference<t_CType>::CType;

	template <typename t_CType>
	class TCRemoveReferenceStorable
	{
	public:
		typedef t_CType CType;
	};

	template <typename t_CType>
	class TCRemoveReferenceStorable<t_CType &>
	{
	public:
		typedef typename TCChooseType<NTraits::TCIsFunction<t_CType>::mc_Value, t_CType &, t_CType>::CType CType;
	};

	template <typename t_CType>
	class TCRemoveReferenceStorable<t_CType &&>
	{
	public:
		typedef typename TCChooseType<NTraits::TCIsFunction<t_CType>::mc_Value, t_CType &&, t_CType>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Array																								|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/
	namespace NPrivate
	{

		template <typename t_CType>
		class TCIsArrayHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCIsArrayHelper<t_CType []>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CType, mint t_nElements>
		class TCIsArrayHelper<t_CType [t_nElements]>
		{
		public:
			enum
			{
				EValue = true
			};
		};


		template <typename t_CType>
		class TCIsArrayUnboundedHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCIsArrayUnboundedHelper<t_CType []>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CType>
		class TCRemoveExtentHelper
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemoveExtentHelper<t_CType []>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType, mint t_nElements>
		class TCRemoveExtentHelper<t_CType [t_nElements]>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemoveAllExtentsHelper
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemoveAllExtentsHelper<t_CType []>
		{
		public:
			typedef typename TCRemoveAllExtentsHelper<t_CType>::CType CType;
		};

		template <typename t_CType, mint t_nElements>
		class TCRemoveAllExtentsHelper<t_CType [t_nElements]>
		{
		public:
			typedef typename TCRemoveAllExtentsHelper<t_CType>::CType CType;
		};

		template <typename t_CType, mint t_Dimension>
		class TCExtentHelper
		{
		public:
			enum
			{
				mc_Value = 0
			};
		};

		template <typename t_CType, mint t_nExtent>
		class TCExtentHelper<t_CType[t_nExtent], 0>
		{
		public:
			enum
			{
				mc_Value = t_nExtent
			};
		};

		template <typename t_CType, mint t_Dimension, mint t_nExtent>
		class TCExtentHelper<t_CType[t_nExtent], t_Dimension>
		{
		public:
			enum
			{
				mc_Value = TCExtentHelper<t_CType, t_Dimension-1>::mc_Value
			};

		};

		template <typename t_CType, mint t_Dimension>
		class TCExtentHelper<t_CType[], t_Dimension>
		{
		public:
			enum
			{
				mc_Value = TCExtentHelper<t_CType, t_Dimension-1>::mc_Value
			};
		};

		template <typename t_CType>
		class TCRankHelper
		{
		public:
			enum
			{
				mc_Value = 0
			};
		};

		template <typename t_CType, mint t_nExtent>
		class TCRankHelper<t_CType[t_nExtent]>
		{
		public:
			enum
			{
				mc_Value = TCRankHelper<t_CType>::mc_Value + 1
			};
		};

		template <typename t_CType>
		class TCRankHelper<t_CType[]>
		{
		public:
			enum
			{
				mc_Value = TCRankHelper<t_CType>::mc_Value + 1
			};
		};

	}

	template <typename t_CType0>
	class TCIsArray : public TCCompileTimeConstant<bool, NPrivate::TCIsArrayHelper<t_CType0>::EValue>
	{
	public:
	};

	template <typename t_CType0>
	class TCIsArrayUnbounded : public TCCompileTimeConstant<bool, NPrivate::TCIsArrayUnboundedHelper<t_CType0>::EValue>
	{
	public:
	};


	template <typename t_CType0, mint t_Dimension = 0>
	class TCExtent : public TCCompileTimeConstant<mint, NPrivate::TCExtentHelper<t_CType0, t_Dimension>::mc_Value>
	{
	public:
	};

	template <typename t_CType0>
	class TCRank : public TCCompileTimeConstant<mint, NPrivate::TCRankHelper<t_CType0>::mc_Value>
	{
	public:
	};

	// rank


	template <typename t_CType0>
	class TCRemoveExtent
	{
	public:
		typedef typename NPrivate::TCRemoveExtentHelper<t_CType0>::CType CType;
	};

	template <typename t_CType0>
	class TCRemoveAllExtents
	{
	public:
		typedef typename NPrivate::TCRemoveAllExtentsHelper<t_CType0>::CType CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Void																								|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{

		template <typename t_CType>
		class TCIsVoidHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};


		template <>
		class TCIsVoidHelper<void>
		{
		public:
			enum
			{
				EValue = true
			};
		};


	}

	template <typename t_CType0>
	class TCIsVoid : public TCCompileTimeConstant<bool, NPrivate::TCIsVoidHelper<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| POD (Plain Old Data)																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{

#		ifdef DMibPHasTrivialDefaultConstructor
			template <typename t_CType>
			class TCHasTrivialDefaultConstructorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasTrivialDefaultConstructor(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif

#		ifdef DMibPIsPODType
			template <typename t_CType>
			class TCIsPOD
			{
			public:
				enum
				{
					EValue = DMibPIsPODType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif

		template <typename t_CType>
		struct TCIsPODHelper
		{
			enum
			{
				mc_Value
				=
				(TCHasTrivialDefaultConstructorHelper<t_CType>::EValue && TCIsPOD<t_CType>::EValue)
				|| NMib::NTraits::TCIsVoid<t_CType>::mc_Value
				|| NMib::NTraits::TCIsScalar<t_CType>::mc_Value
			};
		};
	}

	template <typename t_CType0>
	class TCIsPOD : public TCCompileTimeConstant<bool, NPrivate::TCIsPODHelper<typename TCRemoveAllExtents<t_CType0>::CType>::mc_Value>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Enum																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
#		ifdef DMibPIsEnumType
			template <typename t_CType>
			class TCIsEnumHelper
			{
			public:
				enum
				{
					EValue = DMibPIsEnumType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCIsEnum : public TCCompileTimeConstant<bool, NPrivate::TCIsEnumHelper<t_CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Underlying Type																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType>
	using TCEnumUnderlyingType = typename std::underlying_type<t_CType>::type;

	template <typename t_CType>
	concept cIsScopedEnum = std::is_scoped_enum_v<t_CType>;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Abstract																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
#		ifdef DMibPIsEnumType
			template <typename t_CType>
			class TCIsAbstractHelper
			{
			public:
				enum
				{
					EValue = DMibPIsAbstractType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCIsAbstract : public TCCompileTimeConstant<bool, NPrivate::TCIsAbstractHelper<t_CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Final																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType>
	concept cIsFinal = std::is_final_v<t_CType>;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Polymorphic																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
#		ifdef DMibPIsEnumType
			template <typename t_CType>
			class TCIsPolymorphicHelper
			{
			public:
				enum
				{
					EValue = DMibPIsPolymorphicType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCIsPolymorphic : public TCCompileTimeConstant<bool, NPrivate::TCIsPolymorphicHelper<t_CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Nothrow Assignment Operator																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		class TCSimpleTypeHelper
		{
		public:
			enum
			{
				mc_Value = NTraits::TCIsPOD<t_CType>::mc_Value
			};
		};
	}

	namespace NPrivate
	{
#		ifdef DMibPHasNothrowAssignmentOperator
			template <typename t_CType>
			class TCHasNothrowAssignmentOperatorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasNothrowAssignmentOperator(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasNothrowAssignmentOperator : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || NPrivate::TCHasNothrowAssignmentOperatorHelper<typename TCRemoveReference<t_CType>::CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Nothrow Copy Constructor																		|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
#		ifdef DMibPHasNothrowCopyConstructor
			template <typename t_CType>
			class TCHasNothrowCopyConstructorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasNothrowCopyConstructor(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasNothrowCopyConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || TCIsReference<t_CType>::mc_Value || NPrivate::TCHasNothrowCopyConstructorHelper<t_CType>::EValue>
	{
	public:
	};


	template <typename t_CType>
	concept cHasNothrowCopyConstructor = std::is_nothrow_copy_constructible_v<t_CType>;

	template <typename t_CType>
	concept cHasNothrowMoveConstructor = std::is_nothrow_move_constructible_v<t_CType>;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Nothrow Default Constructor																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
#		ifdef DMibPHasNothrowDefaultConstructor
			template <typename t_CType>
			class TCHasNothrowDefaultConstructorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasNothrowDefaultConstructor(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasNothrowDefaultConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || NPrivate::TCHasNothrowDefaultConstructorHelper<t_CType>::EValue>
	{
	public:
	};

	template <typename t_CType>
	concept cHasNothrowDefaultConstructor = std::is_nothrow_default_constructible_v<t_CType>;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Trivial Assignment Operator																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
#		ifdef DMibPHasTrivialAssignmentOperator
			template <typename t_CType>
			class TCHasTrivialAssignmentOperatorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasTrivialAssignmentOperator(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasTrivialAssignmentOperator : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || NPrivate::TCHasTrivialAssignmentOperatorHelper<typename TCRemoveReference<t_CType>::CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Trivial Copy Constructor																		|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
#		ifdef DMibPHasTrivialCopyConstructor
			template <typename t_CType>
			class TCHasTrivialCopyConstructorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasTrivialCopyConstructor(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasTrivialCopyConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || TCIsReference<t_CType>::mc_Value || NPrivate::TCHasTrivialCopyConstructorHelper<t_CType>::EValue>
	{
	public:
	};


	template <typename t_CType>
	concept cHasTrivialMoveConstructor = std::is_trivially_move_constructible_v<t_CType>;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Trivial Default Constructor																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	template <typename t_CType>
	class TCHasTrivialDefaultConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || NPrivate::TCHasTrivialDefaultConstructorHelper<t_CType>::EValue>
	{
	public:
	};

	template <typename t_CType>
	concept cHasTrivialDefaultConstructor = std::is_trivially_default_constructible_v<t_CType>;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Trivial Destructor																			|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
#		ifdef DMibPHasTrivialDestructor
			template <typename t_CType>
			class TCHasTrivialDestructorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasTrivialDestructor(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasTrivialDestructor : public TCCompileTimeConstant<bool, !TCIsVoid<t_CType>::mc_Value && (NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value
		|| NPrivate::TCHasTrivialDestructorHelper<t_CType>::EValue || TCIsReference<t_CType>::mc_Value)>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has Virtual Destructor																			|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
#		ifdef DMibPHasVirtualDestructor
			template <typename t_CType>
			class TCHasVirtualDestructorHelper
			{
			public:
				enum
				{
					EValue = DMibPHasVirtualDestructor(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType>
	class TCHasVirtualDestructor : public TCCompileTimeConstant<bool, NPrivate::TCHasVirtualDestructorHelper<t_CType>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Base Of																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
#		ifdef DMibPIsBaseOfType
			template <typename t_CBase, typename t_CDerived>
			class TCIsBaseOfHelper
			{
			public:
				enum
				{
					EValue = DMibPIsBaseOfType(t_CBase, t_CDerived)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CDerived, typename t_CBase>
	class TCIsBaseOf : public TCCompileTimeConstant<bool, NPrivate::TCIsBaseOfHelper<t_CBase, t_CDerived>::EValue>
	{
	public:
	};

	template <typename t_CDerived, typename t_CBase>
	class TCIsBaseOfOrSame : public TCCompileTimeConstant<bool, NPrivate::TCIsBaseOfHelper<t_CBase, t_CDerived>::EValue || TCIsSame<t_CBase, t_CDerived>::mc_Value>
	{
	public:
	};

	template <typename t_CDerived, typename t_CBase>
	concept cIsBaseOfOrSame = TCIsBaseOfOrSame<t_CDerived, t_CBase>::mc_Value;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Base Of																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename tf_CType, typename tf_CReturn>
		tf_CType fg_GetBaseType(tf_CReturn tf_CType::*);
	}

	/// Gets the base type of a type
	/**
		You must add a f_GetBaseHelper function to the base class for this to work.
	 */
	template <typename t_CType>
	class TCGetBase
	{
	public:
		typedef decltype(NPrivate::fg_GetBaseType(&t_CType::f_GetBaseHelper)) CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Virtual Base Of																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CDerived, typename t_CBase, bool t_bEval>
		class TCIsVirtualBaseOfHelper
		{
		public:
			enum
			{
				mc_Value = false
			};
		};


#ifdef DCompiler_GCC
#pragma GCC system_header
#endif
#ifdef DCompiler_clang
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winaccessible-base"
#endif
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4594)
#pragma warning(disable:4250)
#endif
		template <typename t_CDerived, typename t_CBase>
		class TCIsVirtualBaseOfHelper<t_CDerived, t_CBase, true>
		{
		public:
			struct CVirtual : t_CDerived, virtual t_CBase
			{
			   CVirtual();
			   CVirtual(const CVirtual&);
			   CVirtual& operator=(const CVirtual&);
			   ~CVirtual()throw();
			};
			struct CNonVirtual : private t_CDerived
			{
			   CNonVirtual();
			   CNonVirtual(const CNonVirtual&);
			   CNonVirtual& operator=(const CNonVirtual&);
			   ~CNonVirtual()throw();
			};
			enum
			{
				mc_Value = (sizeof(CVirtual)==sizeof(CNonVirtual))
			};
		};

#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif
#ifdef DCompiler_clang
#pragma clang diagnostic pop
#endif

	}

	template <typename t_CDerived, typename t_CBase>
	class TCIsVirtualBaseOf
		: public TCCompileTimeConstant
		<
			bool
			, NPrivate::TCIsVirtualBaseOfHelper
			<
				t_CDerived,
				t_CBase,
				TCIsBaseOf<t_CDerived, t_CBase>::mc_Value
				&& !TCIsSameUnqualified<t_CDerived, t_CBase>::mc_Value
			>::mc_Value
		>
	{
	public:
	};

#ifdef DCompiler_clang

#define DMibCanDetectVirtualMemberFunctions_Constexpr

	template <auto t_pMemberFunctionPointer>
	concept cIsNonVirtualMemberFunction =
		requires()
		{
			NTraits::TCCompileTimeConstant<bool, t_pMemberFunctionPointer == t_pMemberFunctionPointer>();
		}
	;

	template <auto t_pMemberFunctionPointer>
	concept cIsVirtualMemberFunction = !cIsNonVirtualMemberFunction<t_pMemberFunctionPointer>;

#endif

	namespace NPrivate
	{

		template <typename t_CType>
		class TCRemovePointerHelper
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemovePointerHelper<t_CType *>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemovePointerHelper<t_CType * const>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemovePointerHelper<t_CType * volatile>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemovePointerHelper<t_CType * const volatile>
		{
		public:
			typedef t_CType CType;
		};


	}

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| [Member] Function Pointer																			|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	struct CFunctionTraitTag_Ellipsis
	{
	};

	namespace NPrivate
	{
		template <typename t_CType>
		class TCMemberFunctionPointerTraitsHelper
		{
		public:
			typedef void CFunctionType;
			typedef void CReturn;
			typedef void CClass;
			typedef NMeta::TCTypeList<> CParams;

			static constexpr mint mc_Arity = 0;
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;
			static constexpr bool mc_IsNoExecpt = false;
			static constexpr bool mc_IsMemberFunctionPointer = false;
		};

		template <typename t_CType>
		class TCIsFunctionPointerHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CFunction, bool t_bIsFunction>
		class TCFunctionTraitsHelper
		{
		public:
			static constexpr bool mc_IsFunction = false;
			static constexpr mint mc_Arity = 0;
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExecpt = false;

			typedef void CReturn;
			typedef NMeta::TCTypeList<> CParams;
		};


		template <typename t_CReturn, typename... tp_CParams>
		class TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams...)>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams...) noexcept>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams..., ...)>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams..., ...) noexcept>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (*)(tp_CParams...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (*)(tp_CParams...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (*)(tp_CParams..., ...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (*)(tp_CParams..., ...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const)(tp_CParams...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const)(tp_CParams...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const)(tp_CParams..., ...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const)(tp_CParams..., ...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* volatile)(tp_CParams...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* volatile)(tp_CParams...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* volatile)(tp_CParams..., ...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* volatile)(tp_CParams..., ...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const volatile)(tp_CParams...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const volatile)(tp_CParams...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const volatile)(tp_CParams..., ...)>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...);
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCRemovePointerHelper<t_CReturn (* const volatile)(tp_CParams..., ...) noexcept>
		{
		public:
			typedef t_CReturn (CType)(tp_CParams..., ...) noexcept;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams...), true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;

			typedef t_CReturn CReturn;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};
		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams...) noexcept, true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;

			typedef t_CReturn CReturn;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams..., ...), true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;

			typedef t_CReturn CReturn;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};
		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams..., ...) noexcept, true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;

			typedef t_CReturn CReturn;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};

		template <typename t_CReturn, typename t_CClass , typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...)>
		{
		public:

			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};
		template <typename t_CReturn, typename t_CClass , typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) const>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) const noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) volatile>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) volatile noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) const volatile>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) const volatile noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams...> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...)>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) const>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) const noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool c_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) volatile>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) volatile noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};

		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) const volatile>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};
		template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
		class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) const volatile noexcept>
		{
		public:
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			typedef t_CReturn (CFunctionType)(tp_CParams..., ...) noexcept;
			typedef t_CReturn CReturn;
			typedef t_CClass CClass;
			typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
		};
	}

	template <typename t_CType0>
	class TCIsMemberFunctionPointer : public TCCompileTimeConstant
	<
		bool,
		NPrivate::TCMemberFunctionPointerTraitsHelper<typename TCRemoveQualifiers<t_CType0>::CType>::mc_IsMemberFunctionPointer
	>
	{
	public:
	};

	template <typename t_CType0>
	class TCRemoveMemberFunctionPointer
	{
	public:
		typedef typename TCChooseType
		<
			TCIsMemberFunctionPointer<t_CType0>::mc_Value,
			typename NPrivate::TCMemberFunctionPointerTraitsHelper<typename TCRemoveQualifiers<t_CType0>::CType>::CFunctionType,
			t_CType0
		>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Member Object Pointer																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		class TCIsMemberObjectPointerHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType0, typename t_CType1>
		class TCIsMemberObjectPointerHelper<t_CType0 t_CType1::*>
		{
		public:
			enum
			{
				EValue = true
			};
		};

	}

	template <typename t_CType0>
	class TCIsMemberObjectPointer : public TCCompileTimeConstant<bool, NPrivate::TCIsMemberObjectPointerHelper<typename TCRemoveQualifiers<t_CType0>::CType>::EValue && !TCIsMemberFunctionPointer<t_CType0>::mc_Value>
	{
	public:
	};


	namespace NPrivate
	{
		template <typename t_CType, typename t_COriginalType, bool t_bMemberFunctionPtr>
		class TCRemoveMemberObjectPointerHelper
		{
		public:
			typedef t_COriginalType CType;
			typedef void CClass;
		};

		template <typename t_CType0, typename t_CType1, typename t_COriginalType>
		class TCRemoveMemberObjectPointerHelper<t_CType0 t_CType1::*, t_COriginalType, false>
		{
		public:
			typedef t_CType0 CType;
			typedef t_CType1 CClass;
		};

	}

	template <typename t_CType0>
	class TCRemoveMemberObjectPointer
	{
	public:
		typedef typename NPrivate::TCRemoveMemberObjectPointerHelper<typename TCRemoveQualifiers<t_CType0>::CType, t_CType0, TCIsMemberFunctionPointer<t_CType0>::mc_Value>::CType CType;
	};

	template <typename t_CType0>
	class TCMemberObjectPointerClass
	{
	public:
		typedef typename NPrivate::TCRemoveMemberObjectPointerHelper<typename TCRemoveQualifiers<t_CType0>::CType, t_CType0, TCIsMemberFunctionPointer<t_CType0>::mc_Value>::CClass CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Member Pointer																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	template <typename t_CType0>
	class TCIsMemberPointer : public TCCompileTimeConstant<bool, TCIsMemberObjectPointer<t_CType0>::mc_Value || TCIsMemberFunctionPointer<t_CType0>::mc_Value >
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Pointer																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		class TCIsPointerHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCIsPointerHelper<t_CType *>
		{
		public:
			enum
			{
				EValue = !TCIsMemberPointer<t_CType *>::mc_Value
			};
		};

		template <typename t_CType>
		class TCAddPointerHelper
		{
		public:
			typedef t_CType * CType;
		};

		template <typename t_CType>
		class TCAddPointerHelper<t_CType &>
		{
		public:
			typedef t_CType * CType;
		};

		template <typename t_CType>
		class TCAddPointerHelper<t_CType &&>
		{
		public:
			typedef t_CType * CType;
		};
	}

	template <typename t_CType0>
	class TCIsPointer : public TCCompileTimeConstant<bool, NPrivate::TCIsPointerHelper<typename TCRemoveQualifiers<t_CType0>::CType>::EValue>
	{
	public:
	};

	template <typename t_CType0>
	class TCAddPointer
	{
	public:
		typedef typename NPrivate::TCAddPointerHelper<t_CType0>::CType CType;
	};

	template <typename t_CType0>
	class TCRemovePointer
	{
	public:
		typedef typename NPrivate::TCRemovePointerHelper<t_CType0>::CType CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| RValue Reference																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		class TCIsRValueReferenceHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCIsRValueReferenceHelper<t_CType &&>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CType>
		class TCRemoveRValueReferenceHelper
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemoveRValueReferenceHelper<t_CType &&>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCAddRValueReferenceHelper
		{
		public:
			typedef t_CType && CType;
		};

		template <typename t_CType>
		class TCAddRValueReferenceHelper<t_CType &&>
		{
		public:
			typedef t_CType && CType;
		};

		template <typename t_CType>
		class TCAddRValueReferenceHelper<t_CType &>
		{
		public:
			typedef t_CType && CType;
		};

		template <typename t_CType>
		class TCAddRValueReferenceHelper<t_CType []>
		{
		public:
			typedef t_CType CType [];
		};

		template <>
		class TCAddRValueReferenceHelper<void>
		{
		public:
			typedef void CType;
		};

	}

	template <typename t_CType0>
	class TCIsRValueReference : public TCCompileTimeConstant<bool, NPrivate::TCIsRValueReferenceHelper<t_CType0>::EValue>
	{
	public:
	};

	template <typename t_CType0>
	class TCAddRValueReference
	{
	public:
		typedef typename NPrivate::TCAddRValueReferenceHelper<t_CType0>::CType CType;
	};

	template <typename t_CType0>
	class TCRemoveRValueReference
	{
	public:
		typedef typename NPrivate::TCRemoveRValueReferenceHelper<t_CType0>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| LValue Reference																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		class TCIsLValueReferenceHelper
		{
		public:
			enum
			{
				EValue = false
			};
		};

		template <typename t_CType>
		class TCIsLValueReferenceHelper<t_CType &>
		{
		public:
			enum
			{
				EValue = true
			};
		};

		template <typename t_CType>
		class TCRemoveLValueReferenceHelper
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCRemoveLValueReferenceHelper<t_CType &>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCAddLValueReferenceHelper
		{
		public:
			typedef t_CType & CType;
		};

		template <typename t_CType>
		class TCAddLValueReferenceHelper<t_CType &>
		{
		public:
			typedef t_CType & CType;
		};

		template <typename t_CType>
		class TCAddLValueReferenceHelper<t_CType &&>
		{
		public:
			typedef t_CType & CType;
		};

		template <typename t_CType>
		class TCAddLValueReferenceHelper<t_CType []>
		{
		public:
			typedef t_CType CType [];
		};

		template <>
		class TCAddLValueReferenceHelper<void>
		{
		public:
			typedef void CType;
		};

	}

	template <typename t_CType0>
	class TCIsLValueReference : public TCCompileTimeConstant<bool, NPrivate::TCIsLValueReferenceHelper<t_CType0>::EValue>
	{
	public:
	};

	template <typename t_CType0>
	class TCAddLValueReference
	{
	public:
		typedef typename NPrivate::TCAddLValueReferenceHelper<t_CType0>::CType CType;
	};

	template <typename t_CType0>
	class TCAddLValueReferenceIfNotRef
	{
	public:
		typedef typename TCChooseType<TCIsReference<t_CType0>::mc_Value, t_CType0, typename TCAddLValueReference<t_CType0>::CType>::CType CType;
	};


	template <typename t_CType0>
	class TCRemoveLValueReference
	{
	public:
		typedef typename NPrivate::TCRemoveLValueReferenceHelper<t_CType0>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Copy reference																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CTypeFrom, typename t_CTypeTo>
	class TCCopyReference
	{
	public:
		typedef typename TCChooseType
		<
			TCIsLValueReference<t_CTypeFrom>::mc_Value
			, typename TCAddLValueReference<t_CTypeTo>::CType
			, typename TCChooseType
			<
				TCIsRValueReference<t_CTypeFrom>::mc_Value
				, typename TCAddRValueReference<t_CTypeTo>::CType
				, typename TCRemoveReference<t_CTypeTo>::CType
			>::CType
		>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Copy lvalue reference																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CTypeFrom, typename t_CTypeTo>
	class TCCopyLValueReference
	{
	public:
		typedef typename TCChooseType
		<
			TCIsReference<t_CTypeFrom>::mc_Value
			, typename TCAddLValueReference<t_CTypeTo>::CType
			, typename TCRemoveReference<t_CTypeTo>::CType
		>::CType CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Copy qualifiers and reference																		|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CCopyFrom, typename t_CCopyTo>
	class TCCopyQualifiersAndReference
	{
	public:
		typedef typename TCCopyReference
			<
				t_CCopyFrom
				, typename TCCopyQualifiers
				<
					typename TCRemoveReference<t_CCopyFrom>::CType
					, typename TCRemoveReference<t_CCopyTo>::CType
				>::CType
			>::CType CType
		;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Copy qualifiers from reference																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CCopyFrom, typename t_CCopyTo>
	class TCCopyQualifiersFromReference
	{
	public:
		typedef typename TCCopyQualifiers
			<
				typename TCRemoveReference<t_CCopyFrom>::CType
				, t_CCopyTo
			>::CType CType
		;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Promote qualifiers and reference																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CCopyFrom, typename t_CCopyTo>
	class TCPromoteQualifiersAndReference
	{
	public:
		typedef typename TCChooseType
			<
				TCIsReference<t_CCopyTo>::mc_Value
				, typename TCChooseType
				<
					TCIsRValueReference<t_CCopyFrom>::mc_Value
					, t_CCopyTo														// If from is a RValue reference we return whatever reference is in to
					, typename TCCopyLValueReference<t_CCopyFrom, t_CCopyTo>::CType // Otherwise we can only safely return a LValue reference
				>::CType
				, typename TCCopyReference
				<
					t_CCopyFrom
					, typename TCAddQualifiersFrom<t_CCopyFrom, t_CCopyTo>::CType
				>::CType
			>::CType CType
		;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Promote qualifiers																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CCopyFrom, typename t_CCopyTo>
	class TCPromoteQualifiers
	{
	public:
		typedef typename TCChooseType
			<
				TCIsRValueReference<t_CCopyTo>::mc_Value
				, typename TCAddRValueReference
				<
					typename TCAddQualifiersFrom<typename TCRemoveReference<t_CCopyFrom>::CType, typename TCRemoveReference<t_CCopyTo>::CType>::CType
				>::CType
				, typename TCChooseType
				<
					TCIsLValueReference<t_CCopyTo>::mc_Value
					, typename TCAddLValueReference
					<
						typename TCAddQualifiersFrom<typename TCRemoveReference<t_CCopyFrom>::CType, typename TCRemoveReference<t_CCopyTo>::CType>::CType
					>::CType
					, typename TCAddQualifiersFrom<typename TCRemoveReference<t_CCopyFrom>::CType, t_CCopyTo>::CType
				>::CType
			>::CType CType
		;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Remove qualifiers and reference																	|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType>
	class TCRemoveReferenceAndQualifiers
	{
	public:
		typedef typename TCRemoveQualifiers
			<
				typename TCRemoveReference
				<
					t_CType
				>::CType
			>::CType CType
		;
	};

	template <typename t_CType>
	using TCRemoveReferenceAndQualifiersType = typename TCRemoveReferenceAndQualifiers<t_CType>::CType;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Remove qualifiers and add RValueReference															|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType>
	class TCRemoveQualifiersAndAddRValueReference
	{
	public:
		typedef typename TCAddRValueReference
			<
				typename TCRemoveQualifiers
				<
					typename TCRemoveReference
					<
						t_CType
					>::CType
				>::CType
			>::CType CType
		;
	};

	template <typename t_CType>
	using TCRemoveQualifiersAndAddRValueReferenceType = typename TCRemoveQualifiersAndAddRValueReference<t_CType>::CType;
}

namespace NMib
{
	template <typename tf_CType>
	typename NTraits::TCAddLValueReferenceIfNotRef<tf_CType>::CType fg_GetReference() noexcept;
}

namespace NMib::NTraits
{

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is nothrow constructible with																		|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType, typename t_CFunctionCallType>
	struct TCIsConstructorCallableWith;


	namespace NPrivate
	{

		template <bool t_bConstructorCallable, typename t_CType, typename... t_PCArguments>
		struct TCIsConstructorNothrowCallableWithImp;

		template <typename t_CType, typename... t_PCArguments>
		struct TCIsConstructorNothrowCallableWithImp<true, t_CType, t_PCArguments...>
			: public TCCompileTimeConstant<bool, noexcept(t_CType(fg_GetType<t_PCArguments>()...))>
		{
		};

		template <typename t_CType, typename... t_PCArguments>
		struct TCIsConstructorNothrowCallableWithImp<false, t_CType, t_PCArguments...>
			: public CCompileTimeFalse
		{
		};

		template <typename t_CType, typename... t_PCArguments>
		struct TCIsConstructorNothrowCallableWithImp2
			: NPrivate::TCIsConstructorNothrowCallableWithImp<TCIsConstructorCallableWith<t_CType, void (t_PCArguments...)>::mc_Value, t_CType, t_PCArguments...>
		{
		};

		template <typename t_CType, mint t_nExtent>
		struct TCIsConstructorNothrowCallableWithImp2<t_CType[t_nExtent]>
			: TCIsConstructorNothrowCallableWithImp2<t_CType>
		{
		};
	}

	template <typename t_CType, typename t_CCallType>
	struct TCIsConstructorNothrowCallableWith;

	template <typename t_CType, typename... t_PCArguments>
	struct TCIsConstructorNothrowCallableWith<t_CType, void (t_PCArguments...)>
		: NPrivate::TCIsConstructorNothrowCallableWithImp2<t_CType, t_PCArguments...>
	{
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Function																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{

		template <typename t_CType>
		class TCAddFunctionPointerHelper
		{
		public:
			typedef t_CType * CType;
		};

		template <typename t_CType>
		class TCAddFunctionPointerHelper<t_CType &>
		{
		public:
			typedef t_CType CType;
		};

		template <typename t_CType>
		class TCAddFunctionPointerHelper<t_CType &&>
		{
		public:
			typedef t_CType CType;
		};

	}

	template <typename t_CFunction>
	class TCIsFunction : public TCCompileTimeConstant<bool, NPrivate::TCIsFunctionPointerHelper<typename NPrivate::TCAddFunctionPointerHelper<typename TCRemoveQualifiers<t_CFunction>::CType>::CType >::EValue>
		// public TCCompileTimeConstant<bool, NPrivate::TCFunctionTraitsHelper<t_CFunction, true>::mc_IsFunction>
	{
	public:
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Decay																								|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{

		template <typename t_CType>
		class TCDecayHelper
		{
		public:
			typedef typename TCRemoveReference<t_CType>::CType CWithoutReferenceType;

			typedef
				typename TCChooseType
				<
					TCIsArray<CWithoutReferenceType>::mc_Value,
					typename TCRemoveExtent<CWithoutReferenceType>::CType *,
					typename TCChooseType
					<
						TCIsFunction<CWithoutReferenceType>::mc_Value,
						typename TCAddPointer<CWithoutReferenceType>::CType,
						typename TCRemoveQualifiers<CWithoutReferenceType>::CType
					>::CType
				>::CType CType
			;
		};

	}

	template <typename t_CType0>
	class TCDecay
	{
	public:
		typedef typename NPrivate::TCDecayHelper<t_CType0>::CType CType;
	};


	namespace NPrivate
	{

		template <typename t_CType>
		class TCDecayForwardHelper
		{
		public:
			typedef typename TCRemoveReference<t_CType>::CType CWithoutReferenceType;

			typedef
				typename TCChooseType
				<
					TCIsArray<CWithoutReferenceType>::mc_Value
					, typename TCRemoveExtent<CWithoutReferenceType>::CType *
					, typename TCChooseType
					<
						TCIsFunction<CWithoutReferenceType>::mc_Value
						, typename TCAddPointer<CWithoutReferenceType>::CType
						, t_CType
					>::CType
				>::CType CType
			;
		};

	}

	template <typename t_CType0>
	class TCDecayForward
	{
	public:
		typedef typename NPrivate::TCDecayForwardHelper<t_CType0>::CType CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Function Traits																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CFunction>
	class TCFunctionTraits : public NPrivate::TCFunctionTraitsHelper<t_CFunction, NPrivate::TCIsFunctionPointerHelper<typename NPrivate::TCAddFunctionPointerHelper<typename TCRemoveQualifiers<t_CFunction>::CType>::CType>::EValue>
	{
	public:
	};

	template <typename t_CFunction, mint t_Index>
	struct TCFunctionTraits_ArgumentType
	{
		typedef typename NMeta::TCTypeList_GetOrVoid<t_Index, typename TCFunctionTraits<t_CFunction>::CParams>::CType CType;
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Member Function Traits																			|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CFunction>
	class TCMemberFunctionPointerTraits : public NPrivate::TCMemberFunctionPointerTraitsHelper<typename TCRemoveQualifiers<t_CFunction>::CType>
	{
	public:
	};

	template <typename t_CFunction, mint t_Index>
	struct TCMemberFunctionPointerTraits_ArgumentType
	{
		typedef typename NMeta::TCTypeList_GetOrVoid<t_Index, typename TCMemberFunctionPointerTraits<t_CFunction>::CParams>::CType CType;
	};


	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Empty																								|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{

#		ifdef DMibPIsEmptyType
			template <typename t_CType>
			class TCIsEmptyHelper
			{
			public:
				enum
				{
					EValue = DMibPIsEmptyType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType0>
	class TCIsEmpty : public TCCompileTimeConstant<bool, NPrivate::TCIsEmptyHelper<t_CType0>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Object																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType0>
	class TCIsObject : public TCCompileTimeConstant<bool, !TCIsFunction<t_CType0>::mc_Value && !TCIsReference<t_CType0>::mc_Value && !TCIsVoid<t_CType0>::mc_Value >
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Union																								|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{

#		ifdef DMibPIsUnionType
			template <typename t_CType>
			class TCIsUnionHelper
			{
			public:
				enum
				{
					EValue = DMibPIsUnionType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType0>
	class TCIsUnion : public TCCompileTimeConstant<bool, NPrivate::TCIsUnionHelper<t_CType0>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Class																								|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{

#		ifdef DMibPIsClassType
			template <typename t_CType>
			class TCIsClassHelper
			{
			public:
				enum
				{
					EValue = DMibPIsClassType(t_CType)
				};
			};
#		else
#			error "Implement this"
#		endif
	}

	template <typename t_CType0>
	class TCIsClass : public TCCompileTimeConstant<bool, NPrivate::TCIsClassHelper<t_CType0>::EValue>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Function Callable																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CFromType, typename t_CToType>
		struct TCReturnConvertibleHelper : public NTraits::TCCompileTimeConstant<bool, NMib::NTraits::TCIsConvertible<t_CFromType, t_CToType>::mc_Value>
		{
		};

		// Can always just throw away the value
		template <typename t_CFromType>
		struct TCReturnConvertibleHelper<t_CFromType, void> : public NTraits::TCCompileTimeConstant<bool, true>
		{
		};


		template <typename t_CFunctionType, typename t_CFunctionCallType>
		struct TCIsFunctionCallableWithHelper
		{
		private:
			template <typename t_CTraitsToCall, typename t_CTraitsCallWith, smint t_ParamNumber>
			struct TCEvaulateForTypeHelper
			{
			public:
				enum
				{
					mc_Value
					=
					NMib::NTraits::TCIsConvertible
					<
						typename NMeta::TCTypeList_GetOrVoid<t_ParamNumber, typename t_CTraitsCallWith::CParams>::CType
						, typename NMeta::TCTypeList_GetOrVoid<t_ParamNumber, typename t_CTraitsToCall::CParams>::CType
					>::mc_Value
					&& TCEvaulateForTypeHelper<t_CTraitsToCall, t_CTraitsCallWith, t_ParamNumber - 1>::mc_Value
				};
			};

			template <typename t_CTraitsToCall, typename t_CTraitsCallWith>
			struct TCEvaulateForTypeHelper<t_CTraitsToCall, t_CTraitsCallWith, -1>
			{
			public:
				enum
				{
					mc_Value = true
				};
			};

			template <typename t_CTraitsToCall, typename t_CTraitsCallWith, bool t_bEllipsis>
			struct TCEvaulateForType
			{
				enum
				{
					mc_Value =
					t_CTraitsCallWith::mc_Arity == t_CTraitsToCall::mc_Arity
					&& TCReturnConvertibleHelper<typename t_CTraitsToCall::CReturn, typename t_CTraitsCallWith::CReturn>::mc_Value
					&& TCEvaulateForTypeHelper<t_CTraitsToCall, t_CTraitsCallWith, smint(t_CTraitsCallWith::mc_Arity) - 1>::mc_Value
				};
			};

			template <typename t_CTraitsToCall, typename t_CTraitsCallWith>
			struct TCEvaulateForType<t_CTraitsToCall, t_CTraitsCallWith, true>
			{
				enum
				{
					mc_Value =
					t_CTraitsCallWith::mc_Arity >= t_CTraitsToCall::mc_Arity
					&& TCReturnConvertibleHelper<typename t_CTraitsToCall::CReturn, typename t_CTraitsCallWith::CReturn>::mc_Value
					&& TCEvaulateForTypeHelper<t_CTraitsToCall, t_CTraitsCallWith, smint(t_CTraitsToCall::mc_Arity) - 1>::mc_Value
				};
			};
		public:
			enum
			{
				mc_Value = NMib::NTraits::TCIsFunction<t_CFunctionType>::mc_Value
				&& NMib::NTraits::TCIsFunction<t_CFunctionCallType>::mc_Value
				&& TCEvaulateForType
				<
					NMib::NTraits::TCFunctionTraits<t_CFunctionType>
					, NMib::NTraits::TCFunctionTraits<t_CFunctionCallType>
					, NMib::NTraits::TCFunctionTraits<t_CFunctionType>::mc_IsEllipsis
				>::mc_Value
			};
		};

	}

	template <typename t_CFunctionType, typename t_CFunctionCallType>
	class TCIsFunctionCallable : public TCCompileTimeConstant
		<
			bool,
			NPrivate::TCIsFunctionCallableWithHelper<t_CFunctionType, t_CFunctionCallType>::mc_Value
		>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Detect																							|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename...>
		using TCVoid = void;
	}

	template <typename t_CType, template <typename t_CType2> class t_TCDetector, typename = NPrivate::TCVoid<>>
	struct TCDetect : NTraits::CCompileTimeFalse
	{
	};

	template <typename t_CType, template <typename t_CType2> class t_TCDetector>
	struct TCDetect<t_CType, t_TCDetector, NPrivate::TCVoid<t_TCDetector<t_CType>>> : NTraits::CCompileTimeTrue
	{
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is complete																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType, typename = void>
	struct TCIsComplete : NTraits::CCompileTimeFalse
	{
	};

	template <typename t_CType>
	struct TCIsComplete<t_CType, NPrivate::TCVoid<decltype(sizeof(t_CType))>> : NTraits::CCompileTimeTrue
	{
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Member traits																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Callable With																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

//	template <typename t_CType, typename t_CFunctionCallType>
//	class TCIsCallableWith;

	template <typename t_CType, typename t_CFunctionCallType>
	struct TCIsCallableWith;

	template <typename t_CType, typename t_CReturn, typename ...tp_CParams>
	struct TCIsCallableWith<t_CType, t_CReturn (tp_CParams...)>
	{
		static constexpr bool mc_Value = std::is_invocable_r_v<t_CReturn, t_CType, tp_CParams...>;

		using CType = bool;
		operator bool ()
		{
			return mc_Value != 0;
		}
	};

	template <typename t_CType, typename ...tp_CParams>
	struct TCIsCallableWith<t_CType, void (tp_CParams...)>
	{
		static constexpr bool mc_Value = std::is_invocable_v<t_CType, tp_CParams...>;

		using CType = bool;
		operator bool ()
		{
			return mc_Value != 0;
		}
	};

	template <typename t_CType, typename t_CFunctionCallType>
	concept cIsCallableWith = TCIsCallableWith<t_CType, t_CFunctionCallType>::mc_Value;


	namespace NPrivate
	{
		template <bool t_bCallable, typename t_CType, typename ...tp_CParams>
		struct TCGetCallableReturnType
		{
			using CType = void;
		};

		template <typename t_CType, typename ...tp_CParams>
		struct TCGetCallableReturnType<true, t_CType, tp_CParams...>
		{
			using CType = std::invoke_result_t<t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename t_CFunctionCallType>
		struct TCCallableReturnTypeForImp;

		template <typename t_CType, typename t_CReturn, typename ...tp_CParams>
		struct TCCallableReturnTypeForImp<t_CType, t_CReturn (tp_CParams...)>
		{
			static constexpr bool mc_Value = std::is_invocable_r_v<t_CReturn, t_CType, tp_CParams...>;

			using CType = typename TCGetCallableReturnType<mc_Value, t_CType, tp_CParams...>::CType;
		};

		template <typename t_CType, typename ...tp_CParams>
		struct TCCallableReturnTypeForImp<t_CType, void (tp_CParams...)>
		{
			static constexpr bool mc_Value = std::is_invocable_v<t_CType, tp_CParams...>;

			using CType = typename TCGetCallableReturnType<mc_Value, t_CType, tp_CParams...>::CType;
		};
	}

	template <typename t_CType, typename t_CFunctionCallType>
	using TCCallableReturnTypeFor = typename NPrivate::TCCallableReturnTypeForImp<t_CType, t_CFunctionCallType>::CType;

	namespace NPrivate
	{
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsNoExceptCallableWith;

		template <typename t_CType, typename t_CReturn, typename... tp_CParams>
		struct TCIsNoExceptCallableWith<t_CType, t_CReturn (tp_CParams...)> : TCCompileTimeConstant
			<
				bool
				, std::is_nothrow_invocable_r_v<t_CReturn, t_CType, tp_CParams...>
			>
		{
		};

		template <typename t_CType, typename t_CReturn, typename... tp_CParams>
		struct TCIsNoExceptCallableWith<t_CType, t_CReturn (tp_CParams...) noexcept> : TCCompileTimeConstant
			<
				bool
				, std::is_nothrow_invocable_r_v<t_CReturn, t_CType, tp_CParams...>
			>
		{
		};
	}

	template <typename t_CType, typename t_CFunctionCallType>
	concept cIsNoThrowCallableWith = NPrivate::TCIsNoExceptCallableWith<t_CType, t_CFunctionCallType>::mc_Value;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Constructor Callable With																		|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType, typename... tp_CParams>
	concept cConstructibleWithBrace = requires (void *_pMemory, tp_CParams && ... p_Params)
		{
			new(_pMemory) t_CType{static_cast<tp_CParams &&>(p_Params)...};
		}
	;
	
	template <typename t_CType, typename... tp_CParams>
	concept cConstructibleWith = requires (void *_pMemory, tp_CParams && ... p_Params)
		{
			new(_pMemory) t_CType(static_cast<tp_CParams &&>(p_Params)...);
		}
	;

	template <typename t_CType, typename t_CFunctionCallType>
	struct TCIsConstructorCallableWith;

	template <typename t_CType, typename ...tp_CParams>
	struct TCIsConstructorCallableWith<t_CType, void (tp_CParams...)> : public TCCompileTimeConstant<bool, std::is_constructible_v<t_CType, tp_CParams...>>
	{
	};

	template <typename t_CType, typename t_COther>
	concept cIsAssignable = std::is_assignable_v<t_CType, t_COther>;

	template <typename t_CType, typename t_COther>
	concept cIsNoThrowAssignable = std::is_nothrow_assignable_v<t_CType, t_COther>;

	template <typename t_CType, typename t_COther>
	concept cIsTriviallyAssignable = std::is_trivially_assignable_v<t_CType, t_COther>;
	
	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Has New Operator																					|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
		template <typename t_CType>
		concept cHasOperator_New_0 = requires (std::size_t _Size)
			{
				t_CType::operator new(_Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_New_1 = requires (std::size_t _Size, std::align_val_t _Align)
			{
				t_CType::operator new(_Size, _Align);
			}
		;
		template <typename t_CType>
		concept cHasOperator_New_2 = requires (std::size_t _Size)
			{
				&t_CType::operator new;
			}
		;
		template <typename t_CType>
		concept cHasOperator_NewArray_0 = requires (std::size_t _Size)
			{
				t_CType::operator new [](_Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_NewArray_1 = requires (std::size_t _Size, std::align_val_t _Align)
			{
				t_CType::operator new [](_Size, _Align);
			}
		;
		template <typename t_CType>
		concept cHasOperator_NewArray_2 = requires (void *_pMemory, std::size_t _Size)
			{
				&t_CType::operator new [];
			}
		;
	}

	template <typename t_CType>
	concept cHasOperatorNewArray
		= NPrivate::cHasOperator_NewArray_0<t_CType>
		|| NPrivate::cHasOperator_NewArray_1<t_CType>
		|| NPrivate::cHasOperator_NewArray_2<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorNew
		= NPrivate::cHasOperator_New_0<t_CType>
		|| NPrivate::cHasOperator_New_1<t_CType>
		|| NPrivate::cHasOperator_New_2<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorNewAny = cHasOperatorNew<t_CType> || cHasOperatorNewArray<t_CType>;

	template <typename t_CType>
	struct TCHasOperator_New: public TCCompileTimeConstant<bool, cHasOperatorNew<t_CType>>
	{
	};

	template <typename t_CType>
	struct TCHasOperator_NewArray: public TCCompileTimeConstant<bool, cHasOperatorNewArray<t_CType>>
	{
	};

	template <typename t_CType>
	class TCHasOperatorNew : public TCCompileTimeConstant<bool, cHasOperatorNewAny<t_CType>>
	{
	public:
	};

	namespace NPrivate
	{
		template <typename t_CType>
		concept cHasOperator_Delete_0 = requires (void *_pMemory)
			{
				t_CType::operator delete(_pMemory);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_1 = requires (void *_pMemory, std::size_t _Size)
			{
				t_CType::operator delete(_pMemory, _Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_2 = requires (t_CType *_pMemory, std::destroying_delete_t)
			{
				t_CType::operator delete(_pMemory, std::destroying_delete);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_3 = requires (t_CType *_pMemory, std::destroying_delete_t, std::size_t _Size)
			{
				t_CType::operator delete(_pMemory, std::destroying_delete, _Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_Delete_4 = requires (void *_pMemory)
			{
				&t_CType::operator delete;
			}
		;
		template <typename t_CType>
		concept cHasOperator_DeleteArray_0 = requires (void *_pMemory)
			{
				t_CType::operator delete [](_pMemory);
			}
		;
		template <typename t_CType>
		concept cHasOperator_DeleteArray_1 = requires (void *_pMemory, std::size_t _Size)
			{
				t_CType::operator delete [](_pMemory, _Size);
			}
		;
		template <typename t_CType>
		concept cHasOperator_DeleteArray_2 = requires (void *_pMemory, std::size_t _Size)
			{
				&t_CType::operator delete [];
			}
		;
	}

	template <typename t_CType>
	concept cHasOperatorDeleteArray
		= NPrivate::cHasOperator_DeleteArray_0<t_CType>
		|| NPrivate::cHasOperator_DeleteArray_1<t_CType>
		|| NPrivate::cHasOperator_DeleteArray_2<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorDelete
		= NPrivate::cHasOperator_Delete_0<t_CType>
		|| NPrivate::cHasOperator_Delete_1<t_CType>
		|| NPrivate::cHasOperator_Delete_2<t_CType>
		|| NPrivate::cHasOperator_Delete_3<t_CType>
		|| NPrivate::cHasOperator_Delete_4<t_CType>
	;

	template <typename t_CType>
	concept cHasOperatorDeleteAny = cHasOperatorDelete<t_CType> || cHasOperatorDeleteArray<t_CType>;

	template <typename t_CType>
	struct TCHasOperator_Delete: public TCCompileTimeConstant<bool, cHasOperatorDelete<t_CType>>
	{
	};

	template <typename t_CType>
	struct TCHasOperator_DeleteArray: public TCCompileTimeConstant<bool, cHasOperatorDeleteArray<t_CType>>
	{
	};

	template <typename t_CType>
	class TCHasOperatorDelete : public TCCompileTimeConstant<bool, cHasOperatorDeleteAny<t_CType>>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Comparison Operators																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	template <typename t_CType>
	class TCOperatorTraits_LessThan;
	template <typename t_CType>
	class TCOperatorFullType_LessThan;
	template <typename t_CType>
	class TCOperatorType_LessThan;
	template <typename t_CType>
	class TCHasOperator_LessThan;
	template <typename t_CType>
	class TCIsOperatorCallable_LessThan;
	template <typename t_CType, typename t_CFunctionCallType>
	struct TCIsOperatorCallableWith_LessThan;
	template <typename t_CType>
	class TCOperatorTraits_LessThan;

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Stateless																						|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/

	namespace NPrivate
	{
	}

	template <typename t_CType>
	class TCIsStateless : public TCCompileTimeConstant
		<
			bool
			,	TCHasTrivialDefaultConstructor<t_CType>::mc_Value
				&& TCHasTrivialCopyConstructor<t_CType>::mc_Value
				&& TCHasTrivialDestructor<t_CType>::mc_Value
				&& TCIsClass<t_CType>::mc_Value
				&& TCIsEmpty<t_CType>::mc_Value
		>
	{
	public:
	};

	/***************************************************************************************************\
	|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
	| Is Standard Layout																				|
	|___________________________________________________________________________________________________|
	\***************************************************************************************************/


	namespace NPrivate
	{
	}

	template <typename t_CType>
	class TCIsStandardLayout : public TCCompileTimeConstant<bool, TCIsPOD<t_CType>::mc_Value>
	{
	public:
	};
}
