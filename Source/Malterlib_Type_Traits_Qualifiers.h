// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib


#pragma once

namespace NMib
{
	namespace NTraits
	{
		template <typename t_CType>
		class TCIsFunction;
		template <typename t_CType>
		class TCIsVoid;
		template <typename t_CType>
		class TCIsArray;
		template <typename t_CType>
		class TCRemoveReference;
		template <typename t_CType>
		class TCIsArrayUnbounded;
		template <typename t_CType>
		class TCIsEnum;
		template <typename t_CType>
		class TCIsPointer;
		template <typename t_CType>
		class TCIsMemberPointer;
		
		namespace NPrivate
		{
			template <typename t_CType>
			class TCConstQualifier
			{
			public:
				enum
				{
					EValue = false,
				};

				typedef t_CType CUnqualified;
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4180)
#endif
				typedef t_CType const CQualified;
#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif
			};
			template <typename t_CType>
			class TCConstQualifier<t_CType const>
			{
			public:
				enum
				{
					EValue = true,
				};
				typedef t_CType CUnqualified;
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4180)
#endif
				typedef t_CType const CQualified;
#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif
			};
			template <typename t_CType>
			class TCVolatileQualifier
			{
			public:
				enum
				{
					EValue = false,
				};

				typedef t_CType CUnqualified;
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4180)
#endif
				typedef t_CType volatile CQualified;
#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif
			};
			template <typename t_CType>
			class TCVolatileQualifier<volatile t_CType>
			{
			public:
				enum
				{
					EValue = true,
				};
				typedef t_CType CUnqualified;
#ifdef DCompiler_MSVC
#pragma warning(push)
#pragma warning(disable:4180)
#endif
				typedef t_CType volatile CQualified;
#ifdef DCompiler_MSVC
#pragma warning(pop)
#endif
			};

		}

		template <typename t_CType>
		class TCIsVolatile : public TCCompileTimeConstant<bool, NPrivate::TCVolatileQualifier<t_CType>::EValue>
		{
		};

		template <typename t_CType>
		class TCIsConst : public TCCompileTimeConstant<bool, NPrivate::TCConstQualifier<t_CType>::EValue>
		{
		};

		template <typename t_CType>
		class TCRemoveConst
		{
		public:
			typedef typename NPrivate::TCConstQualifier<t_CType>::CUnqualified CType;
		};

		template <typename t_CType>
		class TCRemoveVolatile
		{
		public:
			typedef typename NPrivate::TCVolatileQualifier<t_CType>::CUnqualified CType;
		};

		template <typename t_CType, bool t_bDoAdd = true>
		class TCAddConst
		{
		public:
			typedef typename NPrivate::TCConstQualifier<t_CType>::CQualified CType;
		};

		template <typename t_CType>
		class TCAddConst<t_CType, false>
		{
		public:
			typedef t_CType CType;
		};
		
		template <typename t_CType, bool t_bDoAdd = true>
		class TCAddVolatile
		{
		public:
			typedef typename NPrivate::TCVolatileQualifier<t_CType>::CQualified CType;
		};

		template <typename t_CType>
		class TCAddVolatile<t_CType, false>
		{
		public:
			typedef t_CType CType;
		};
		
		
		template <typename t_CType>
		class TCAddConstVolatile
		{
		public:
			typedef typename TCAddConst<typename TCAddVolatile<t_CType>::CType>::CType CType;
		};
		

		template <typename t_CType, bint t_bSetTo>
		class TCSetConst
		{
		public:
			typedef typename TCRemoveConst<t_CType>::CType CType;
		};

		template <typename t_CType>
		class TCSetConst<t_CType, 1>
		{
		public:
			typedef typename TCAddConst<t_CType>::CType CType;
		};

		template <typename t_CType, bint t_bSetTo>
		class TCSetVolatile
		{
		public:
			typedef typename TCRemoveVolatile<t_CType>::CType CType;
		};

		template <typename t_CType>
		class TCSetVolatile<t_CType, 1>
		{
		public:
			typedef typename TCAddVolatile<t_CType>::CType CType;
		};

		template <typename t_CCopyFrom, typename t_CCopyTo>
		class TCCopyConst
		{
		public:
			typedef typename TCSetConst<t_CCopyTo, TCIsConst<t_CCopyFrom>::mc_Value>::CType CType;
		};

		template <typename t_CCopyFrom, typename t_CCopyTo>
		class TCCopyVolatile
		{
		public:
			typedef typename TCSetVolatile<t_CCopyTo, TCIsVolatile<t_CCopyFrom>::mc_Value>::CType CType;
		};

		template <typename t_CCopyFrom, typename t_CCopyTo>
		class TCCopyQualifiers
		{
		public:
			typedef typename TCSetConst<typename TCSetVolatile<t_CCopyTo ,TCIsVolatile<t_CCopyFrom>::mc_Value>::CType, TCIsConst<t_CCopyFrom>::mc_Value>::CType CType;
		};

		template <typename t_CCopyFrom, typename t_CCopyTo>
		class TCAddQualifiersFrom
		{
		public:
			typedef typename TCAddConst
				<
					typename TCAddVolatile
					<
						t_CCopyTo
						, TCIsVolatile<t_CCopyFrom>::mc_Value
					>::CType
					, TCIsConst<t_CCopyFrom>::mc_Value
				>::CType CType
			;
		};	
		

		template <typename t_CType>
		class TCRemoveQualifiers
		{
		public:
			typedef typename TCRemoveVolatile<typename TCRemoveConst<t_CType>::CType>::CType CType;
		};
		
	}
}

