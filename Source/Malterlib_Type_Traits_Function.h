// Copyright © 2025 Unbroken AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include <Mib/Meta/Meta>

namespace NMib::NTraits
{
	struct CFunctionTraitTag_Ellipsis
	{
	};

	namespace NPrivate
	{
		template <typename t_CType>
		class TCAddFunctionPointerHelper
		{
		public:
			using CType = t_CType *;
		};

		template <typename t_CType>
		class TCAddFunctionPointerHelper<t_CType &>
		{
		public:
			using CType = t_CType;
		};

		template <typename t_CType>
		class TCAddFunctionPointerHelper<t_CType &&>
		{
		public:
			using CType = t_CType;
		};

		template <typename t_CType>
		struct TCIsFunctionPointerHelper
		{
			constexpr static bool mc_Value = false;
		};

		template <typename t_CReturn, typename... tp_CParams>
		struct TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams...)>
		{
			constexpr static bool mc_Value = true;
		};

		template <typename t_CReturn, typename... tp_CParams>
		struct TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams...) noexcept>
		{
			constexpr static bool mc_Value = true;
		};

		template <typename t_CReturn, typename... tp_CParams>
		struct TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams..., ...)>
		{
			constexpr static bool mc_Value = true;
		};

		template <typename t_CReturn, typename... tp_CParams>
		struct TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams..., ...) noexcept>
		{
			constexpr static bool mc_Value = true;
		};

		template <typename t_CFunction, bool t_bIsFunction>
		class TCFunctionTraitsHelper
		{
		public:
			static constexpr bool mc_IsFunction = false;
			static constexpr mint mc_Arity = 0;
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExecpt = false;

			using CReturn = void;
			using CParams = NMeta::TCTypeList<>;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams...), true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;

			using CReturn = t_CReturn;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};
		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams...) noexcept, true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;

			using CReturn = t_CReturn;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams..., ...), true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;

			using CReturn = t_CReturn;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};
		template <typename t_CReturn, typename... tp_CParams>
		class TCFunctionTraitsHelper<t_CReturn (tp_CParams..., ...) noexcept, true>
		{
		public:
			static constexpr bool mc_IsFunction = true;
			static constexpr mint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;

			using CReturn = t_CReturn;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};
	}

	template <typename t_CFunction>
	class TCFunctionTraits : public NPrivate::TCFunctionTraitsHelper<t_CFunction, NPrivate::TCIsFunctionPointerHelper<typename NPrivate::TCAddFunctionPointerHelper<TCRemoveQualifiers<t_CFunction>>::CType>::mc_Value>
	{
	public:
	};

	template <typename t_CFunction, mint t_Index>
	using TCFunctionTraits_ArgumentType = NMeta::TCTypeList_GetOrVoid<t_Index, typename TCFunctionTraits<t_CFunction>::CParams>;

	// Callable With

	namespace NPrivate
	{
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsCallableWith
		{
			static constexpr bool mc_Value = false;
		};

		template <typename t_CType, typename t_CReturn, typename ...tp_CParams>
		struct TCIsCallableWith<t_CType, t_CReturn (tp_CParams...)>
		{
			static constexpr bool mc_Value = std::is_invocable_r_v<t_CReturn, t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename ...tp_CParams>
		struct TCIsCallableWith<t_CType, void (tp_CParams...)>
		{
			static constexpr bool mc_Value = std::is_invocable_v<t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename t_CReturn, typename ...tp_CParams>
		struct TCIsCallableWith<t_CType, t_CReturn (tp_CParams...) noexcept>
		{
			static constexpr bool mc_Value = std::is_invocable_r_v<t_CReturn, t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename ...tp_CParams>
		struct TCIsCallableWith<t_CType, void (tp_CParams...) noexcept>
		{
			static constexpr bool mc_Value = std::is_invocable_v<t_CType, tp_CParams...>;
		};
	}

	template <typename t_CType, typename t_CFunctionCallType>
	concept cIsCallableWith = NPrivate::TCIsCallableWith<t_CType, t_CFunctionCallType>::mc_Value;

	namespace NPrivate
	{
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsNoExceptCallableWith
		{
			static constexpr bool mc_Value = false;
		};

		template <typename t_CType, typename t_CReturn, typename... tp_CParams>
		struct TCIsNoExceptCallableWith<t_CType, t_CReturn (tp_CParams...)>
		{
			static constexpr bool mc_Value = std::is_nothrow_invocable_r_v<t_CReturn, t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename... tp_CParams>
		struct TCIsNoExceptCallableWith<t_CType, void (tp_CParams...)>
		{
			static constexpr bool mc_Value = std::is_nothrow_invocable_v<t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename t_CReturn, typename... tp_CParams>
		struct TCIsNoExceptCallableWith<t_CType, t_CReturn (tp_CParams...) noexcept>
		{
			static constexpr bool mc_Value = std::is_nothrow_invocable_r_v<t_CReturn, t_CType, tp_CParams...>;
		};

		template <typename t_CType, typename... tp_CParams>
		struct TCIsNoExceptCallableWith<t_CType, void (tp_CParams...) noexcept>
		{
			static constexpr bool mc_Value = std::is_nothrow_invocable_v<t_CType, tp_CParams...>;
		};
	}

	template <typename t_CType, typename t_CFunctionCallType>
	concept cIsNothrowCallableWith = NPrivate::TCIsNoExceptCallableWith<t_CType, t_CFunctionCallType>::mc_Value;

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
			using CType = typename TCGetCallableReturnType<std::is_invocable_r_v<t_CReturn, t_CType, tp_CParams...>, t_CType, tp_CParams...>::CType;
		};

		template <typename t_CType, typename ...tp_CParams>
		struct TCCallableReturnTypeForImp<t_CType, void (tp_CParams...)>
		{
			using CType = typename TCGetCallableReturnType<std::is_invocable_v<t_CType, tp_CParams...>, t_CType, tp_CParams...>::CType;
		};

		template <typename t_CType, typename t_CReturn, typename ...tp_CParams>
		struct TCCallableReturnTypeForImp<t_CType, t_CReturn (tp_CParams...) noexcept>
		{
			using CType = typename TCGetCallableReturnType<std::is_invocable_r_v<t_CReturn, t_CType, tp_CParams...>, t_CType, tp_CParams...>::CType;
		};

		template <typename t_CType, typename ...tp_CParams>
		struct TCCallableReturnTypeForImp<t_CType, void (tp_CParams...) noexcept>
		{
			using CType = typename TCGetCallableReturnType<std::is_invocable_v<t_CType, tp_CParams...>, t_CType, tp_CParams...>::CType;
		};
	}

	template <typename t_CType, typename t_CFunctionCallType>
	using TCCallableReturnTypeFor = typename NPrivate::TCCallableReturnTypeForImp<t_CType, t_CFunctionCallType>::CType;
}
