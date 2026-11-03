// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NTraits
{
	namespace NPrivate
	{
		template <typename t_CType>
		struct TCMemberFunctionPointerTraitsHelper
		{
			using FFunctionType = void; // NOLINT(malterlib-type-naming): what isn't a function gets void
			using CReturn = void;
			using CClass = void;
			using CParams = NMeta::TCTypeList<>;

			static constexpr umint mc_Arity = 0;
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;
			static constexpr bool mc_IsNoExecpt = false;
			static constexpr bool mc_IsMemberFunctionPointer = false;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params)>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) const>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) const noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) volatile>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) volatile noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) const volatile>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params) const volatile noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...)>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) const>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) const noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool c_IsConst = true;
			static constexpr bool mc_IsVolatile = false;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) volatile>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) volatile noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) const volatile>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = false;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};

		template <typename t_CReturn, typename t_CClass, typename ...tp_CParams>
		struct TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass:: *)(tp_CParams ...p_Params, ...) const volatile noexcept>
		{
			static constexpr bool mc_IsMemberFunctionPointer = true;
			static constexpr umint mc_Arity = sizeof...(tp_CParams);
			static constexpr bool mc_IsEllipsis = true;
			static constexpr bool mc_IsNoExcept = true;
			static constexpr bool mc_IsConst = true;
			static constexpr bool mc_IsVolatile = true;

			using FFunctionType = t_CReturn (tp_CParams ...p_Params, ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};
	}

	template <typename t_CFunction>
	struct TCMemberFunctionPointerTraits : public NPrivate::TCMemberFunctionPointerTraitsHelper<TCRemoveQualifiers<t_CFunction>>
	{
	};

	template <typename t_CFunction, umint t_Index>
	using TCMemberFunctionPointerTraits_ArgumentType = NMeta::TCTypeList_GetOrVoid<t_Index, typename TCMemberFunctionPointerTraits<t_CFunction>::CParams>;

	template <typename t_CType>
	using TCRemoveMemberFunctionPointer = TCConditional
		<
			cIsMemberFunctionPointer<t_CType>
			, typename NPrivate::TCMemberFunctionPointerTraitsHelper<TCRemoveQualifiers<t_CType>>::FFunctionType
			, t_CType
		>
	;
}
