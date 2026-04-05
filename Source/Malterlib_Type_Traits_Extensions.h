// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

#include "Malterlib_Type_Traits_Qualifiers.h"
#include "Malterlib_Type_Traits_IntFloat.h"

#include <Mib/Meta/Meta>

namespace NMib::NTraits
{
	template <auto t_Value, typename t_CMakeDependentOn>
	inline constexpr decltype(t_Value) gc_MakeValueDependent = t_Value;

	// Is complete

	namespace NPrivate
	{
		template <typename...>
		using TCVoid = void;

		template <typename t_CType, typename = void>
		struct TCIsCompleteHelper : NTraits::CCompileTimeFalse
		{
		};

		template <typename t_CType>
		struct TCIsCompleteHelper<t_CType, NPrivate::TCVoid<decltype(sizeof(t_CType))>> : NTraits::CCompileTimeTrue
		{
		};
	}

	template <typename t_CType>
	concept cIsComplete = NPrivate::TCIsCompleteHelper<t_CType>::mc_Value;

	namespace NPrivate
	{
		template <typename t_CType>
		class TCRemoveReferenceStorableHelper
		{
		public:
			using CType = t_CType;
		};

		template <typename t_CType>
		class TCRemoveReferenceStorableHelper<t_CType &>
		{
		public:
			using CType = TCConditional<NTraits::cIsFunction<t_CType>, t_CType &, t_CType>;
		};

		template <typename t_CType>
		class TCRemoveReferenceStorableHelper<t_CType &&>
		{
		public:
			using CType = TCConditional<NTraits::cIsFunction<t_CType>, t_CType &&, t_CType>;
		};
	}

	template <typename t_CType>
	using TCRemoveReferenceStorable = typename NPrivate::TCRemoveReferenceStorableHelper<t_CType>::CType;


	template <typename t_CType, typename... tp_CParams>
	concept cIsPlacementNewConstructibleWith = requires (void *_pMemory, tp_CParams && ... p_Params)
		{
			new(_pMemory) t_CType(static_cast<tp_CParams &&>(p_Params)...);
		}
	;

	namespace NPrivate
	{
		template <typename tf_CType, typename tf_CReturn>
		tf_CType fg_GetBaseType(tf_CReturn tf_CType::*);

		template <typename t_CType>
		struct TCGetBaseHelper
		{
			using CType = decltype(NPrivate::fg_GetBaseType(&t_CType::f_GetBaseHelper));
		};
	}

	/// Gets the base type of a type
	/**
		You must add a f_GetBaseHelper function to the base class for this to work.
	 */

	template <typename t_CType>
	using TCGetBase = typename NPrivate::TCGetBaseHelper<t_CType>::CType;

	namespace NPrivate
	{
		template <typename t_CType, typename t_COriginalType, bool t_bMemberFunctionPtr>
		class TCRemoveMemberObjectPointerHelper
		{
		public:
			using CType = t_COriginalType;
			using CClass = void;
		};

		template <typename t_CType0, typename t_CType1, typename t_COriginalType>
		class TCRemoveMemberObjectPointerHelper<t_CType0 t_CType1::*, t_COriginalType, false>
		{
		public:
			using CType = t_CType0;
			using CClass = t_CType1;
		};

	}

	template <typename t_CType0>
	using TCRemoveMemberObjectPointer = typename NPrivate::TCRemoveMemberObjectPointerHelper
		<
			TCRemoveQualifiers<t_CType0>
			, t_CType0
			, cIsMemberFunctionPointer<t_CType0>
		>::CType
	;

	template <typename t_CType0>
	using TCMemberObjectPointerClass = typename NPrivate::TCRemoveMemberObjectPointerHelper
		<
			TCRemoveQualifiers<t_CType0>
			, t_CType0
			, cIsMemberFunctionPointer<t_CType0>
		>::CClass
	;

	namespace NPrivate
	{
		template <typename t_CType>
		class TCRemoveRValueReferenceHelper
		{
		public:
			using CType = t_CType;
		};

		template <typename t_CType>
		class TCRemoveRValueReferenceHelper<t_CType &&>
		{
		public:
			using CType = t_CType;
		};
	}

	template <typename t_CType0>
	using TCRemoveRValueReference = typename NPrivate::TCRemoveRValueReferenceHelper<t_CType0>::CType;

	template <typename t_CType0>
	using TCAddLValueReferenceIfNotRef = TCConditional<cIsReference<t_CType0>, t_CType0, TCAddLValueReference<t_CType0>>;

	namespace NPrivate
	{
		template <typename t_CType>
		class TCRemoveLValueReferenceHelper
		{
		public:
			using CType = t_CType;
		};

		template <typename t_CType>
		class TCRemoveLValueReferenceHelper<t_CType &>
		{
		public:
			using CType = t_CType;
		};
	}

	template <typename t_CType0>
	using TCRemoveLValueReference = typename NPrivate::TCRemoveLValueReferenceHelper<t_CType0>::CType;


	template <typename t_CTypeFrom, typename t_CTypeTo>
	using TCCopyReference = TCConditional
		<
			cIsLValueReference<t_CTypeFrom>
			, TCAddLValueReference<t_CTypeTo>
			, TCConditional
			<
				cIsRValueReference<t_CTypeFrom>
				, TCAddRValueReference<t_CTypeTo>
				, TCRemoveReference<t_CTypeTo>
			>
		>
	;

	template <typename t_CTypeFrom, typename t_CTypeTo>
	using TCCopyLValueReference = TCConditional
		<
			cIsReference<t_CTypeFrom>
			, TCAddLValueReference<t_CTypeTo>
			, TCRemoveReference<t_CTypeTo>
		>
	;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCCopyQualifiersAndReference = TCCopyReference
		<
			t_CCopyFrom
			, TCCopyQualifiers
			<
				TCRemoveReference<t_CCopyFrom>
				, TCRemoveReference<t_CCopyTo>
			>
		>
	;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCCopyQualifiersFromReference = TCCopyQualifiers
		<
			TCRemoveReference<t_CCopyFrom>
			, t_CCopyTo
		>
	;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCPromoteQualifiersAndReference = TCConditional
		<
			cIsReference<t_CCopyTo>
			, TCConditional
			<
				cIsRValueReference<t_CCopyFrom>
				, t_CCopyTo										// If from is a RValue reference we return whatever reference is in to
				, TCCopyLValueReference<t_CCopyFrom, t_CCopyTo> // Otherwise we can only safely return a LValue reference
			>
			, TCCopyReference
			<
				t_CCopyFrom
				, TCAddQualifiersFrom<t_CCopyFrom, t_CCopyTo>
			>
		>
	;

	template <typename t_CCopyFrom, typename t_CCopyTo>
	using TCPromoteQualifiers = TCConditional
		<
			cIsRValueReference<t_CCopyTo>
			, TCAddRValueReference
			<
				TCAddQualifiersFrom<TCRemoveReference<t_CCopyFrom>, TCRemoveReference<t_CCopyTo>>
			>
			, TCConditional
			<
				cIsLValueReference<t_CCopyTo>
				, TCAddLValueReference
				<
					TCAddQualifiersFrom<TCRemoveReference<t_CCopyFrom>, TCRemoveReference<t_CCopyTo>>
				>
				, TCAddQualifiersFrom<TCRemoveReference<t_CCopyFrom>, t_CCopyTo>
			>
		>
	;

	template <typename t_CType>
	using TCRemoveQualifiersAndAddRValueReference = TCAddRValueReference<TCRemoveReferenceAndQualifiers<t_CType>>;

	// Detect

	namespace NPrivate
	{
		template <typename t_CType, template <typename t_CType2> class t_TCDetector, typename = NPrivate::TCVoid<>>
		struct TCDetectHelper : NTraits::CCompileTimeFalse
		{
		};

		template <typename t_CType, template <typename t_CType2> class t_TCDetector>
		struct TCDetectHelper<t_CType, t_TCDetector, NPrivate::TCVoid<t_TCDetector<t_CType>>> : NTraits::CCompileTimeTrue
		{
		};
	}

	template <typename t_CType, template <typename t_CType2> class t_TCDetector>
	concept cIsDetected = NPrivate::TCDetectHelper<t_CType, t_TCDetector>::mc_Value;

	// Stateless

	template <typename t_CType>
	concept cIsStateless = cIsTrivialllyDefaultConstructible<t_CType>
		&& cIsTriviallyCopyConstructible<t_CType>
		&& cIsTriviallyDestructible<t_CType>
		&& cIsClass<t_CType>
		&& cIsEmpty<t_CType>
	;

	namespace NPrivate
	{
		template <typename t_CType>
		struct TCIsStringHelper
		{
			constexpr static bool mc_bValue = false;
		};

		template <>	struct TCIsStringHelper<const ch8 *>
		{
			constexpr static bool mc_bValue = true;
		};

		template <>	struct TCIsStringHelper<ch8 *>
		{
			constexpr static bool mc_bValue = true;
		};

		template <>	struct TCIsStringHelper<const ch16 *>
		{
			constexpr static bool mc_bValue = true;
		};

		template <>	struct TCIsStringHelper<ch16 *>
		{
			constexpr static bool mc_bValue = true;
		};

		template <>	struct TCIsStringHelper<const ch32 *>
		{
			constexpr static bool mc_bValue = true;
		};

		template <>	struct TCIsStringHelper<ch32 *>
		{
			constexpr static bool mc_bValue = true;
		};
	}

	template <typename t_CType>
	concept cIsString = NPrivate::TCIsStringHelper<t_CType>::mc_bValue;
}

namespace NMib
{
	template <typename tf_CType>
	NTraits::TCAddLValueReferenceIfNotRef<tf_CType> fg_GetReference() noexcept;
}
