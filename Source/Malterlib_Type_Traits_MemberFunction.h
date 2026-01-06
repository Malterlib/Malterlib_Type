// Copyright © 2025 Unbroken AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NTraits
{
	namespace NPrivate
	{
		template <typename t_CType>
		class TCMemberFunctionPointerTraitsHelper
		{
		public:
			using CFunctionType = void;
			using CReturn = void;
			using CClass = void;
			using CParams = NMeta::TCTypeList<>;

			static constexpr mint mc_Arity = 0;
			static constexpr bool mc_IsEllipsis = false;
			static constexpr bool mc_IsConst = false;
			static constexpr bool mc_IsVolatile = false;
			static constexpr bool mc_IsNoExecpt = false;
			static constexpr bool mc_IsMemberFunctionPointer = false;
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

			using CFunctionType = t_CReturn (tp_CParams...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams...>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...);
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
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

			using CFunctionType = t_CReturn (tp_CParams..., ...) noexcept;
			using CReturn = t_CReturn;
			using CClass = t_CClass;
			using CParams = NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis>;
		};
	}

	template <typename t_CFunction>
	struct TCMemberFunctionPointerTraits : public NPrivate::TCMemberFunctionPointerTraitsHelper<TCRemoveQualifiers<t_CFunction>>
	{
	};

	template <typename t_CFunction, mint t_Index>
	using TCMemberFunctionPointerTraits_ArgumentType = NMeta::TCTypeList_GetOrVoid<t_Index, typename TCMemberFunctionPointerTraits<t_CFunction>::CParams>;

	template <typename t_CType>
	using TCRemoveMemberFunctionPointer = TCConditional
		<
			cIsMemberFunctionPointer<t_CType>,
			typename NPrivate::TCMemberFunctionPointerTraitsHelper<TCRemoveQualifiers<t_CType>>::CFunctionType,
			t_CType
		>
	;
}
