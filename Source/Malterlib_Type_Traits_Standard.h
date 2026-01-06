// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#if defined(DMalterlibUseStaticLibCxx)
#	define DMibNewVisibility _LIBCPP_OVERRIDABLE_FUNC_VIS
#	include <stddef.h>

	namespace std
	{
		using ::nullptr_t;
		using ::ptrdiff_t _LIBCPP_USING_IF_EXISTS;
		using ::size_t _LIBCPP_USING_IF_EXISTS;
	}
#	include <__new/align_val_t.h>
#	include <__new/destroying_delete_t.h>
#else
#	define DMibNewVisibility
#	include <new>
#endif

#include <type_traits>

namespace NMib::NTraits
{
	template <typename t_CType>
	using TCRemoveReference = std::remove_reference_t<t_CType>;

	template <typename t_CType>
	using TCRemoveReferenceAndQualifiers = std::remove_cvref_t<t_CType>;

	// Misc properties

	template <typename t_CType>
	concept cIsVoid = std::is_void_v<t_CType>;

	template <typename t_CType>
	concept cIsPod = std::is_pod_v<t_CType>;

	template <typename t_CType>
	concept cIsAbstract = std::is_abstract_v<t_CType>;

	template <typename t_CType>
	concept cIsFinal = std::is_final_v<t_CType>;

	template <typename t_CType>
	concept cIsPolymorphic = std::is_polymorphic_v<t_CType>;

	template <typename t_CType>
	concept cIsStandardLayout = std::is_standard_layout_v<t_CType>;

	template <typename t_CType>
	concept cIsFunction = std::is_function_v<t_CType>;

	template <typename t_CTypeFrom, typename t_CTypeTo>
	concept cIsConvertible = std::is_convertible_v<t_CTypeFrom, t_CTypeTo>;

	template <typename t_CType>
	concept cIsEmpty = std::is_empty_v<t_CType>;

	template <typename t_CType>
	concept cIsObject = std::is_object_v<t_CType>;

	template <typename t_CType>
	concept cIsUnion = std::is_union_v<t_CType>;

	template <typename t_CType>
	concept cIsClass = std::is_class_v<t_CType>;

	// Is same

	template <typename t_CType0, typename t_CType1>
	concept cIsSame = std::is_same_v<t_CType0, t_CType1>;

	template <typename t_CType0, typename t_CType1>
	concept cIsSameUnqualified = std::is_same_v<std::remove_cv_t<t_CType0>, std::remove_cv_t<t_CType1>>;

	template <typename t_CType0, typename t_CType1>
	concept cIsSameDereferencedUnqualified = std::is_same_v<std::remove_cvref_t<t_CType0>, std::remove_cvref_t<t_CType1>>;

	// Reference

	template <typename t_CType>
	concept cIsReference = std::is_reference_v<t_CType>;

	// Array

	template <typename t_CType>
	concept cIsArray = std::is_array_v<t_CType>;

	template <typename t_CType>
	concept cIsUnboundedArray = std::is_unbounded_array_v<t_CType>;

	template <typename t_CType, mint t_Dimension = 0>
	inline constexpr size_t gc_ArrayExtent = std::extent_v<t_CType, t_Dimension>;

	template <typename t_CType>
	inline constexpr size_t gc_ArrayRank = std::rank_v<t_CType>;

	template <typename t_CType>
	using TCRemoveExtent = std::remove_extent_t<t_CType>;

	template <typename t_CType>
	using TCRemoveAllExtents = std::remove_all_extents_t<t_CType>;

	// Enum

	template <typename t_CType>
	concept cIsEnum = std::is_enum_v<t_CType>;

	template <typename t_CType>
	concept cIsScopedEnum = std::is_scoped_enum_v<t_CType>;

	template <typename t_CType>
	using TCEnumUnderlyingType = typename std::underlying_type<t_CType>::type;

	// Assignable

	template <typename t_CType, typename t_COther>
	concept cIsAssignableWith = std::is_assignable_v<t_CType, t_COther>;

	template <typename t_CType>
	concept cIsCopyAssignable = std::is_copy_assignable_v<t_CType>;

	template <typename t_CType, typename t_COther>
	concept cIsMoveAssignable = std::is_move_assignable_v<t_CType>;


	template <typename t_CType, typename t_COther>
	concept cIsNothrowAssignableWith = std::is_nothrow_assignable_v<t_CType, t_COther>;

	template <typename t_CType>
	concept cIsNothrowCopyAssignable = std::is_nothrow_copy_assignable_v<t_CType>;

	template <typename t_CType>
	concept cIsNothrowMoveAssignable = std::is_nothrow_move_assignable_v<t_CType>;


	template <typename t_CType, typename t_COther>
	concept cIsTriviallyAssignableWith = std::is_trivially_assignable_v<t_CType, t_COther>;

	template <typename t_CType>
	concept cIsTriviallyCopyAssignable = std::is_trivially_copy_assignable_v<t_CType>;

	template <typename t_CType>
	concept cIsTriviallyMoveAssignable = std::is_trivially_move_assignable_v<t_CType>;

	// Constructor

	template <typename t_CType, typename ...tp_COther>
	concept cIsConstructibleWith = std::is_constructible_v<t_CType, tp_COther...>;

	template <typename t_CType>
	concept cIsCopyConstructible = std::is_copy_constructible_v<t_CType>;

	template <typename t_CType>
	concept cIsMoveConstructible = std::is_move_constructible_v<t_CType>;

	template <typename t_CType>
	concept cIsDefaultConstructible = std::is_default_constructible_v<t_CType>;


	template <typename t_CType, typename ...tp_CFunctionCallType>
	concept cIsNothrowConstructibleWith = std::is_nothrow_constructible_v<t_CType, tp_CFunctionCallType...>;

	template <typename t_CType>
	concept cIsNothrowCopyConstructible = std::is_nothrow_copy_constructible_v<t_CType>;

	template <typename t_CType>
	concept cIsNothrowMoveConstructible = std::is_nothrow_move_constructible_v<t_CType>;

	template <typename t_CType>
	concept cIsNothrowDefaultConstructible = std::is_nothrow_default_constructible_v<t_CType>;


	template <typename t_CType, typename ...tp_COther>
	concept cIsTriviallyConstructibleWith = std::is_trivially_constructible_v<t_CType, tp_COther...>;

	template <typename t_CType>
	concept cIsTriviallyCopyConstructible = std::is_trivially_copy_constructible_v<t_CType>;

	template <typename t_CType>
	concept cIsTriviallyMoveConstructible = std::is_trivially_move_constructible_v<t_CType>;

	template <typename t_CType>
	concept cIsTrivialllyDefaultConstructible = std::is_trivially_default_constructible_v<t_CType>;

	// Destructor

	template <typename t_CType>
	concept cIsDestructible = std::is_destructible_v<t_CType>;

	template <typename t_CType>
	concept cIsTriviallyDestructible = std::is_trivially_destructible_v<t_CType>;

	template <typename t_CType>
	struct TCHasVirtualDestructorOverride
	{
		constexpr static bool mc_Value = std::has_virtual_destructor_v<t_CType>;
	};

	template <typename t_CType>
	concept cHasVirtualDestructor = TCHasVirtualDestructorOverride<t_CType>::mc_Value;

	// Virtual classes

	template <typename t_CDerived, typename t_CBase>
	concept cIsBaseOf = std::is_base_of_v<t_CBase, t_CDerived>;

	template <typename t_CDerived, typename t_CBase>
	concept cIsBaseOfOrSame = cIsBaseOf<t_CDerived, t_CBase> || cIsSame<t_CDerived, t_CBase>;

#if defined(DCompiler_clang) && _LIBCPP_STD_VER >= 26
	template <typename t_CDerived, typename t_CBase>
	concept cIsVirtualBaseOf = std::is_virtual_base_of_v<t_CBase, t_CDerived>;
#else
	namespace NPrivate
	{
		template <typename t_CDerived, typename t_CBase, bool t_bEval>
		struct TCIsVirtualBaseOfHelper
		{
			constexpr static bool mc_bValue = false;
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
		struct TCIsVirtualBaseOfHelper<t_CDerived, t_CBase, true>
		{
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

			constexpr static bool mc_bValue = (sizeof(CVirtual)==sizeof(CNonVirtual));
		};

#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif
#ifdef DCompiler_clang
#pragma clang diagnostic pop
#endif
		template <typename t_CDerived, typename t_CBase>
		struct TCIsVirtualBaseOf
		{
			constexpr static bool mc_bValue = NPrivate::TCIsVirtualBaseOfHelper
				<
					t_CDerived,
					t_CBase,
					cIsBaseOf<t_CDerived, t_CBase>
					&& !cIsSameUnqualified<t_CDerived, t_CBase>
				>::mc_bValue
			;
		};
	}

	template <typename t_CDerived, typename t_CBase>
	concept cIsVirtualBaseOf = NPrivate::TCIsVirtualBaseOf<t_CDerived, t_CBase>::mc_bValue;
#endif

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

	// Member pointers

	template <typename t_CType0>
	concept cIsMemberFunctionPointer = std::is_member_function_pointer_v<t_CType0>;

	template <typename t_CType0>
	concept cIsMemberObjectPointer = std::is_member_object_pointer_v<t_CType0>;

	template <typename t_CType0>
	concept cIsMemberPointer = std::is_member_pointer_v<t_CType0>;

	// Pointer

	template <typename t_CType0>
	concept cIsPointer = std::is_pointer_v<t_CType0>;

	template <typename t_CType0>
	using TCAddPointer = std::add_pointer_t<t_CType0>;

	template <typename t_CType>
	using TCRemovePointer = std::remove_pointer_t<t_CType>;

	// References

	template <typename t_CType0>
	concept cIsRValueReference = std::is_rvalue_reference_v<t_CType0>;

	// Note: Does not follow collapsing rules
	template <typename t_CType0>
	using TCAddRValueReference = std::add_rvalue_reference_t<std::remove_reference_t<t_CType0>>;

	template <typename t_CType0>
	concept cIsLValueReference = std::is_lvalue_reference_v<t_CType0>;

	template <typename t_CType0>
	using TCAddLValueReference = std::add_lvalue_reference_t<t_CType0>;

	// Decay

	template <typename t_CType0>
	using TCDecay = std::decay_t<t_CType0>;
}
