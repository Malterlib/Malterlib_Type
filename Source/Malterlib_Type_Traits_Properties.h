// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Type_Traits_Qualifiers.h"
#include "Malterlib_Type_Traits_IntFloat.h"
#include <Mib/Preprocessor/Preprocessor>
#include <Mib/Meta/Meta>

namespace NMib
{
	namespace NTraits
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
#			if defined(DMibPIsTypeConvertibleToType)
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
#			else
				template 
				<
					typename t_CTypeFrom, 
					typename t_CTypeTo, 
					bint t_bDisableCheck = NTraits::TCIsVoid<t_CTypeFrom>::mc_Value || NTraits::TCIsVoid<t_CTypeTo>::mc_Value || NTraits::TCIsFunction<t_CTypeTo>::mc_Value || NTraits::TCIsArray<t_CTypeTo>::mc_Value
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
#			endif
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
			class TCIsSameHelper
			{
			public:
				enum
				{
					EValue = false
				};
			};

			template <typename t_CType>
			class TCIsSameHelper<t_CType, t_CType>
			{
			public:
				enum
				{
					EValue = true
				};
			};
		}

		template <typename t_CType0, typename t_CType1>
		class TCIsSame : public TCCompileTimeConstant<bool, NPrivate::TCIsSameHelper<t_CType0, t_CType1>::EValue>
		{ 
		public:
		};

		template <typename t_CType0, typename t_CType1>
		class TCIsSameUnqualified : public TCCompileTimeConstant<bool, NPrivate::TCIsSameHelper<typename TCRemoveQualifiers<t_CType0>::CType, typename TCRemoveQualifiers<t_CType1>::CType>::EValue>
		{ 
		public:
		};

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
			
#			ifdef DMibPHasTrivialDefaultConstructor
				template <typename t_CType>
				class TCHasTrivialDefaultConstructorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasTrivialDefaultConstructor(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif

#			ifdef DMibPIsPODType
				template <typename t_CType>
				class TCIsPOD
				{
				public:
					enum
					{
						EValue = DMibPIsPODType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif

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
#			ifdef DMibPIsEnumType
				template <typename t_CType>
				class TCIsEnumHelper
				{
				public:
					enum
					{
						EValue = DMibPIsEnumType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
		}

		template <typename t_CType>
		class TCIsEnum : public TCCompileTimeConstant<bool, NPrivate::TCIsEnumHelper<t_CType>::EValue>
		{ 
		public:
		};

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Is Abstract																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/


		namespace NPrivate
		{
#			ifdef DMibPIsEnumType
				template <typename t_CType>
				class TCIsAbstractHelper
				{
				public:
					enum
					{
						EValue = DMibPIsAbstractType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
		}

		template <typename t_CType>
		class TCIsAbstract : public TCCompileTimeConstant<bool, NPrivate::TCIsAbstractHelper<t_CType>::EValue>
		{ 
		public:
		};

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Is Polymorphic																					|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/


		namespace NPrivate
		{
#			ifdef DMibPIsEnumType
				template <typename t_CType>
				class TCIsPolymorphicHelper
				{
				public:
					enum
					{
						EValue = DMibPIsPolymorphicType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
#			ifdef DMibPHasNothrowAssignmentOperator
				template <typename t_CType>
				class TCHasNothrowAssignmentOperatorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasNothrowAssignmentOperator(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
#			ifdef DMibPHasNothrowCopyConstructor
				template <typename t_CType>
				class TCHasNothrowCopyConstructorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasNothrowCopyConstructor(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
		}

		template <typename t_CType>
		class TCHasNothrowCopyConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || TCIsReference<t_CType>::mc_Value || NPrivate::TCHasNothrowCopyConstructorHelper<t_CType>::EValue>
		{ 
		public:
		};

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Has Nothrow Default Constructor																	|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/


		namespace NPrivate
		{
#			ifdef DMibPHasNothrowDefaultConstructor
				template <typename t_CType>
				class TCHasNothrowDefaultConstructorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasNothrowDefaultConstructor(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
		}

		template <typename t_CType>
		class TCHasNothrowDefaultConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || NPrivate::TCHasNothrowDefaultConstructorHelper<t_CType>::EValue>
		{ 
		public:
		};

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Has Trivial Assignment Operator																	|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		namespace NPrivate
		{
#			ifdef DMibPHasTrivialAssignmentOperator
				template <typename t_CType>
				class TCHasTrivialAssignmentOperatorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasTrivialAssignmentOperator(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
#			ifdef DMibPHasTrivialCopyConstructor
				template <typename t_CType>
				class TCHasTrivialCopyConstructorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasTrivialCopyConstructor(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
		}

		template <typename t_CType>
		class TCHasTrivialCopyConstructor : public TCCompileTimeConstant<bool, NPrivate::TCSimpleTypeHelper<t_CType>::mc_Value || TCIsReference<t_CType>::mc_Value || NPrivate::TCHasTrivialCopyConstructorHelper<t_CType>::EValue>
		{ 
		public:
		};

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

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Has Trivial Destructor																			|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/


		namespace NPrivate
		{
#			ifdef DMibPHasTrivialDestructor
				template <typename t_CType>
				class TCHasTrivialDestructorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasTrivialDestructor(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
#			ifdef DMibPHasVirtualDestructor
				template <typename t_CType>
				class TCHasVirtualDestructorHelper
				{
				public:
					enum
					{
						EValue = DMibPHasVirtualDestructor(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
#			ifdef DMibPIsBaseOfType
				template <typename t_CBase, typename t_CDerived>
				class TCIsBaseOfHelper
				{
				public:
					enum
					{
						EValue = DMibPIsBaseOfType(t_CBase, t_CDerived)
					};
				};
#			else
#				error "Implement this"
#			endif
		}

		template <typename t_CDerived, typename t_CBase>
		class TCIsBaseOf : public TCCompileTimeConstant<bool, NPrivate::TCIsBaseOfHelper<t_CBase, t_CDerived>::EValue>
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
			template <typename t_CDerived, typename t_CBase, bint t_bEval>
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
				bint
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

				enum
				{
					mc_Arity = 0
					, mc_IsEllipsis = false
					, mc_IsConst = false
					, mc_IsVolatile = false
					, mc_IsMemberFunctionPointer = false
				};
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

			template <typename t_CFunction, bint t_bIsFunction>
			class TCFunctionTraitsHelper
			{
			public:
				enum
				{
					mc_IsFunction = false
					, mc_Arity = 0
					, mc_IsEllipsis = false
				};

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
			class TCIsFunctionPointerHelper<t_CReturn (*)(tp_CParams..., ...)>
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
			class TCRemovePointerHelper<t_CReturn (*)(tp_CParams..., ...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};

			template <typename t_CReturn, typename... tp_CParams>
			class TCRemovePointerHelper<t_CReturn (* const)(tp_CParams...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams...);
			};


			template <typename t_CReturn, typename... tp_CParams>
			class TCRemovePointerHelper<t_CReturn (* const)(tp_CParams..., ...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};

			template <typename t_CReturn, typename... tp_CParams>
			class TCRemovePointerHelper<t_CReturn (* volatile)(tp_CParams...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams...);
			};


			template <typename t_CReturn, typename... tp_CParams>
			class TCRemovePointerHelper<t_CReturn (* volatile)(tp_CParams..., ...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};

			template <typename t_CReturn, typename... tp_CParams>
			class TCRemovePointerHelper<t_CReturn (* const volatile)(tp_CParams...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams...);
			};


			template <typename t_CReturn, typename... tp_CParams>
			class TCRemovePointerHelper<t_CReturn (* const volatile)(tp_CParams..., ...)>
			{
			public:
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};

			template <typename t_CReturn, typename... tp_CParams>
			class TCFunctionTraitsHelper<t_CReturn (tp_CParams...), true>
			{
			public:
				enum
				{
					mc_IsFunction = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = false
				};
				typedef t_CReturn CReturn;
				typedef NMeta::TCTypeList<tp_CParams...> CParams;
			};

			template <typename t_CReturn, typename... tp_CParams>
			class TCFunctionTraitsHelper<t_CReturn (tp_CParams..., ...), true>
			{
			public:
				enum
				{
					mc_IsFunction = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = true
				};
				typedef t_CReturn CReturn;
				typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
			};

			template <typename t_CReturn, typename t_CClass , typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...)>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = false
					, mc_IsConst = false
					, mc_IsVolatile = false
				};
				typedef t_CReturn (CFunctionType)(tp_CParams...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams...> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) const>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = false
					, mc_IsConst = true
					, mc_IsVolatile = false
				};
				typedef t_CReturn (CFunctionType)(tp_CParams...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams...> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) volatile>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = false
					, mc_IsConst = false
					, mc_IsVolatile = true
				};
				typedef t_CReturn (CFunctionType)(tp_CParams...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams...> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams...) const volatile>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = false
					, mc_IsConst = true
					, mc_IsVolatile = true
				};
				typedef t_CReturn (CFunctionType)(tp_CParams...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams...> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...)>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = true
					, mc_IsConst = false
					, mc_IsVolatile = false
				};
				typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) const>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = true
					, mc_IsConst = true
					, mc_IsVolatile = false
				};
				typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) volatile>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = true
					, mc_IsConst = false
					, mc_IsVolatile = true
				};
				typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
			};

			template <typename t_CReturn, typename t_CClass, typename... tp_CParams>
			class TCMemberFunctionPointerTraitsHelper<t_CReturn (t_CClass ::*)(tp_CParams..., ...) const volatile>
			{
			public:
				enum
				{
					mc_IsMemberFunctionPointer = true
					, mc_Arity = sizeof...(tp_CParams)
					, mc_IsEllipsis = true
					, mc_IsConst = true
					, mc_IsVolatile = true
				};
				typedef t_CReturn (CFunctionType)(tp_CParams..., ...);
				typedef t_CReturn CReturn;
				typedef t_CClass CClass;
				typedef NMeta::TCTypeList<tp_CParams..., CFunctionTraitTag_Ellipsis> CParams;
			};

		}

		template <typename t_CType0>
		class TCIsMemberFunctionPointer : public TCCompileTimeConstant
		<
			bint, 
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
			template <typename t_CType, typename t_COriginalType, bint t_bMemberFunctionPtr>
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
		
		
	}

	template <typename tf_CType>
	typename NTraits::TCAddLValueReferenceIfNotRef<tf_CType>::CType fg_GetReference() noexcept;

	namespace NTraits
	{

#ifdef DCompiler_clang
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
#endif

		
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
			
#			ifdef DMibPIsEmptyType
				template <typename t_CType>
				class TCIsEmptyHelper
				{
				public:
					enum
					{
						EValue = DMibPIsEmptyType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
			
#			ifdef DMibPIsUnionType
				template <typename t_CType>
				class TCIsUnionHelper
				{
				public:
					enum
					{
						EValue = DMibPIsUnionType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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
			
#			ifdef DMibPIsClassType
				template <typename t_CType>
				class TCIsClassHelper
				{
				public:
					enum
					{
						EValue = DMibPIsClassType(t_CType)
					};
				};
#			else
#				error "Implement this"
#			endif
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

				template <typename t_CTraitsToCall, typename t_CTraitsCallWith, bint t_bEllipsis>
				struct TCEvaulateForType
				{ 
					enum
					{
						mc_Value = 
						constenum(t_CTraitsCallWith::mc_Arity) == constenum(t_CTraitsToCall::mc_Arity)
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
						constenum(t_CTraitsCallWith::mc_Arity) >= constenum(t_CTraitsToCall::mc_Arity)
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
				bint, 
				NPrivate::TCIsFunctionCallableWithHelper<t_CFunctionType, t_CFunctionCallType>::mc_Value
			>
		{ 
		public:
		};		

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Member traits																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		namespace NPrivate
		{
			using CHasMemberImplementationUnderlaying = int32;
			enum EHasMemberImplementation
			{
				EHasMemberImplementation_Class,
				EHasMemberImplementation_Union,
				EHasMemberImplementation_Other
			};
			
		}
		template <typename t_CType>
		class TCIsFunctionObject;

		// Flaw: HasMember/IsCallable does not work for overloaded functions on unions on GCC


#	define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameSingleMemeberImplNormal(_Type, _MemberName) \
		template <typename t_CClass>\
		static auto fs_Deduce(t_CClass *_pMember) -> decltype(&t_CClass::_MemberName);\
		static CDummy fs_Deduce(...);\
		enum {\
			mc_Value = !NMib::NTraits::TCIsSame<decltype(fs_Deduce((_Type*)0)), CDummy>::mc_Value\
			, ms_MultiValue = mc_Value\
		};

#	define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameSingleMemeberImplSafe(_Type, _MemberName) DMibPrivateTypeTraitsImplement_MemberTraitsWithNameSingleMemeberImplNormal(_Type, _MemberName)

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameTraits(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRet2, _OperatorRetVal, _FunctionType, _SafeImpl) \
		template <typename t_CType>\
		class TC##_BaseName##Traits_##_TraitName\
		{ \
			typedef typename NMib::NTraits::TCRemoveReference<t_CType>::CType CTypeToCheck;\
			template <typename t_CType2, bint t_bEnable>\
			struct TCImplementationSingleMember\
			{\
				enum\
				{\
					mc_Value = false\
				};\
			};\
			template <mint t_Value>\
			struct TCDummy\
			{\
			};\
			struct CDummy{};\
			template <typename t_CType2>\
			struct TCImplementationSingleMember<t_CType2, true>\
			{\
			DMibPrivateTypeTraitsImplement_MemberTraitsWithNameSingleMemeberImpl##_SafeImpl(t_CType2, _MemberName)\
			};\
			typedef TCImplementationSingleMember<CTypeToCheck, \
				NMib::NTraits::TCIsClass<CTypeToCheck>::mc_Value || NMib::NTraits::TCIsUnion<CTypeToCheck>::mc_Value> CImplementationSingleMember;\
			template <typename t_CType2, NMib::NTraits::NPrivate::CHasMemberImplementationUnderlaying t_Implementation>\
			struct TCImplementation\
			{\
				enum\
				{\
					mc_Value = false\
				};\
			};\
			template <typename t_CType2>\
			struct TCImplementation<t_CType2, NMib::NTraits::NPrivate::EHasMemberImplementation_Class>\
			{\
				struct CBaseMixin\
				{ \
					_OperatorRet _MemberName _OperatorParams\
					{\
						_OperatorRetVal;\
					}\
				};\
				struct CDerived : public t_CType2, public CBaseMixin \
				{\
				};\
				template <typename t_CType3, t_CType3 t_Value>\
				class TCHelper\
				{\
				};\
				template <typename t_CClass> \
				static NMib::NTraits::CFalseBySize fs_Deduce(t_CClass *, TCHelper<_OperatorRet2 (_FunctionType) _OperatorParams, &t_CClass::_MemberName>* = 0); \
				static NMib::NTraits::CTrueBySize fs_Deduce(...); \
				enum\
				{\
					mc_Value = sizeof(fs_Deduce((CDerived*)0)) == sizeof(NMib::NTraits::CTrueBySize) \
				};\
			};\
			template <typename t_CType2>\
			struct TCImplementation<t_CType2, NMib::NTraits::NPrivate::EHasMemberImplementation_Union>\
			{\
				enum\
				{\
					mc_Value = TCImplementationSingleMember<t_CType2, true>::ms_MultiValue\
				};\
			};\
			typedef TCImplementation<CTypeToCheck, \
				NMib::NTraits::TCIsClass<CTypeToCheck>::mc_Value ? NMib::NTraits::NPrivate::EHasMemberImplementation_Class \
				: NMib::NTraits::TCIsUnion<CTypeToCheck>::mc_Value ? NMib::NTraits::NPrivate::EHasMemberImplementation_Union \
				: NMib::NTraits::NPrivate::EHasMemberImplementation_Other> CImplementation;\
			template <typename t_CType2, bint t_bHasMember>\
			struct TCImplementationTypeOf\
			{\
				typedef void CType;\
			};\
			template <typename t_CType2>\
			struct TCImplementationTypeOf<t_CType2, true>\
			{\
				typedef decltype(&t_CType2::_MemberName) CType;\
			};\
			typedef typename TCImplementationTypeOf\
			<\
				CTypeToCheck, CImplementationSingleMember::mc_Value\
			>::CType CRawType;\
		public: \
			typedef typename NMib::NTraits::TCRemoveMemberObjectPointer\
				<\
					typename NMib::NTraits::TCRemoveMemberFunctionPointer\
					<\
						typename NMib::NTraits::TCRemovePointer\
						<\
							CRawType\
						>::CType\
					>::CType\
				>::CType CMemberType;\
			typedef typename NMib::NTraits::TCRemovePointer\
				<\
					CRawType\
				>::CType CFullMemberType;\
			enum\
			{\
				mc_HasMember = CImplementation::mc_Value \
				, mc_IsCallable = mc_HasMember && \
				(\
					NMib::NTraits::TCIsMemberFunctionPointer<CMemberType>::mc_Value\
					|| NMib::NTraits::TCIsFunction<CMemberType>::mc_Value\
					|| !CImplementationSingleMember::mc_Value\
					|| _FunctionObject\
				)\
			};\
		};

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameFullType(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl) \
		template <typename t_CType>\
		class TC##_BaseName##FullType_##_TraitName\
		{\
		public:\
			typedef typename TC##_BaseName##Traits_##_TraitName<t_CType>::CFullMemberType CType;\
		};

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameType(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl) \
		template <typename t_CType>\
		class TC##_BaseName##Type_##_TraitName\
		{\
		public:\
			typedef typename TC##_BaseName##Traits_##_TraitName<t_CType>::CMemberType CType;\
		};

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameHas(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl) \
		template <typename t_CType>\
		class TCHas##_BaseName##_##_TraitName \
			: public NMib::NTraits::TCCompileTimeConstant<bool, TC##_BaseName##Traits_##_TraitName<t_CType>::mc_HasMember>\
		{\
		};

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallable(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl) \
		template <typename t_CType>\
		class TCIs##_BaseName##Callable_##_TraitName : public NMib::NTraits::TCCompileTimeConstant<bool, TC##_BaseName##Traits_##_TraitName<t_CType>::mc_IsCallable>\
		{\
		};

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallableWith(_BaseName, _TraitName, _Mem, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl, _ExtraEvalExpression, _CallableParam0) \
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##CallableWith_##_TraitName\
		{\
		private:\
			class CDummy{};\
			template <typename t_CFunction>\
			struct TCEval2\
			{\
				typedef void CRet;\
				static CDummy fs_D(...);\
			};\
			template <typename tR, typename... t_PCParams>\
			struct TCEval2<tR (t_PCParams...)>\
			{\
				typedef tR CRet;\
				template <typename t_CC> static auto fs_D(t_CC *_pM) -> decltype(NMib::fg_GetReference<t_CC>()._Mem(NMib::fg_GetType<t_PCParams>()...));\
				static CDummy fs_D(...);\
			};\
			template <bint t_bValid, typename t_CFunction>\
			struct TCEval\
			{\
				enum\
				{\
					mc_Value = false\
				};\
				typedef void CReturnType;\
			};\
			template <typename t_CFunction>\
			struct TCEval<true, t_CFunction>\
			{\
				typedef decltype(TCEval2<t_CFunction>::fs_D(((t_CType *)nullptr))) CRet;\
				enum\
				{\
					mc_Value = NMib::NTraits::NPrivate::TCReturnConvertibleHelper<CRet, typename TCEval2<t_CFunction>::CRet>::mc_Value\
					&& !NMib::NTraits::TCIsSame<CRet, CDummy>::mc_Value\
				};\
				typedef typename NMib::TCChooseType<mc_Value, CRet, void>::CType CReturnType;\
			};\
			typedef TCEval\
					<\
						(NMib::NTraits::TCIsClass<t_CType>::mc_Value || NMib::NTraits::TCIsUnion<t_CType>::mc_Value)\
						&& _ExtraEvalExpression\
						, t_CFunctionCallType\
					> CEvalType;\
		public:\
			enum\
			{\
				mc_Value = CEvalType::mc_Value\
			};\
			typedef typename CEvalType::CReturnType CReturnType;\
		};\
		template <typename t_CType, typename t_CFunctionCallType, bool t_bIsCallableWith = TCIs##_BaseName##CallableWith_##_TraitName<t_CType, t_CFunctionCallType>::mc_Value>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp\
		{\
			enum\
			{\
				mc_Value = false\
			};\
		};\
		template <typename t_CType, typename t_CRet, typename... t_PCParams>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CRet (t_PCParams...), true>\
		{\
			template <typename t_CToGenerate>\
			static t_CToGenerate G();\
			enum\
			{\
				mc_Value = noexcept(NMib::fg_GetReference<t_CType>()._Mem(G<t_PCParams>()...))\
			};\
		};\
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName : public TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CFunctionCallType>\
		{\
		};

		namespace NPrivate
		{
			template <typename t_CType>
			struct TCTypeWithMember
			{
				t_CType m_Member;
			};
		}
		
#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallableWithBinaryOperator(_BaseName, _TraitName, _Mem, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl, _ExtraEvalExpression, _Operator) \
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##CallableWith_##_TraitName\
		{\
		private:\
			class CDummy{};\
			template <typename t_CFunction>\
			struct TCEval2\
			{\
				typedef void CRet;\
				static CDummy fs_D(...);\
			};\
			template <typename tR, typename t_CParam>\
			struct TCEval2<tR (t_CParam)>\
			{\
				typedef tR CRet;\
				template <typename t_CC> static auto fs_D(t_CC *_pM) -> decltype(_pM->m_Member _Operator NMib::fg_GetType<t_CParam>());\
				static CDummy fs_D(...);\
			};\
			template <bint t_bValid, typename t_CFunction>\
			struct TCEval\
			{\
				enum\
				{\
					mc_Value = false\
				};\
				typedef void CReturnType;\
			};\
			template <typename t_CFunction>\
			struct TCEval<true, t_CFunction>\
			{\
				typedef decltype(TCEval2<t_CFunction>::fs_D(((NMib::NTraits::NPrivate::TCTypeWithMember<t_CType> *)nullptr))) CRet;\
				enum\
				{\
					mc_Value = NMib::NTraits::NPrivate::TCReturnConvertibleHelper<CRet, typename TCEval2<t_CFunction>::CRet>::mc_Value\
					&& !NMib::NTraits::TCIsSame<CRet, CDummy>::mc_Value\
				};\
				typedef typename NMib::TCChooseType<mc_Value, CRet, void>::CType CReturnType;\
			};\
			typedef TCEval\
					<\
						true\
						, t_CFunctionCallType\
					> CEvalType;\
		public:\
			enum\
			{\
				mc_Value = CEvalType::mc_Value\
			};\
			typedef typename CEvalType::CReturnType CReturnType;\
		};\
		template <typename t_CType, typename t_CFunctionCallType, bool t_bIsCallableWith = TCIs##_BaseName##CallableWith_##_TraitName<t_CType, t_CFunctionCallType>::mc_Value>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp\
		{\
			enum\
			{\
				mc_Value = false\
			};\
		};\
		template <typename t_CType, typename t_CRet, typename t_CParam>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CRet (t_CParam), true>\
		{\
			enum\
			{\
				mc_Value = noexcept(NMib::fg_GetReference<t_CType>() _Operator NMib::fg_GetType<t_CParam>())\
			};\
		};\
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName : public TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CFunctionCallType>\
		{\
		};
		
#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallableWithPrefixOperator(_BaseName, _TraitName, _Mem, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl, _ExtraEvalExpression, _Operator) \
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##CallableWith_##_TraitName\
		{\
		private:\
			class CDummy{};\
			template <typename t_CFunction>\
			struct TCEval2\
			{\
				typedef void CRet;\
				static CDummy fs_D(...);\
			};\
			template <typename tR>\
			struct TCEval2<tR ()>\
			{\
				typedef tR CRet;\
				template <typename t_CC> static auto fs_D(t_CC *_pM) -> decltype(_Operator _pM->m_Member);\
				static CDummy fs_D(...);\
			};\
			template <bint t_bValid, typename t_CFunction>\
			struct TCEval\
			{\
				enum\
				{\
					mc_Value = false\
				};\
				typedef void CReturnType;\
			};\
			template <typename t_CFunction>\
			struct TCEval<true, t_CFunction>\
			{\
				typedef decltype(TCEval2<t_CFunction>::fs_D(((NMib::NTraits::NPrivate::TCTypeWithMember<t_CType> *)nullptr))) CRet;\
				enum\
				{\
					mc_Value = NMib::NTraits::NPrivate::TCReturnConvertibleHelper<CRet, typename TCEval2<t_CFunction>::CRet>::mc_Value\
					&& !NMib::NTraits::TCIsSame<CRet, CDummy>::mc_Value\
				};\
				typedef typename NMib::TCChooseType<mc_Value, CRet, void>::CType CReturnType;\
			};\
			typedef TCEval\
					<\
						true\
						, t_CFunctionCallType\
					> CEvalType;\
		public:\
			enum\
			{\
				mc_Value = CEvalType::mc_Value\
			};\
			typedef typename CEvalType::CReturnType CReturnType;\
		};\
		template <typename t_CType, typename t_CFunctionCallType, bool t_bIsCallableWith = TCIs##_BaseName##CallableWith_##_TraitName<t_CType, t_CFunctionCallType>::mc_Value>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp\
		{\
			enum\
			{\
				mc_Value = false\
			};\
		};\
		template <typename t_CType, typename t_CRet>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CRet (), true>\
		{\
			enum\
			{\
				mc_Value = noexcept(_Operator NMib::fg_GetReference<t_CType>())\
			};\
		};\
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName : public TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CFunctionCallType>\
		{\
		};		

#define DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallableWithPostfixOperator(_BaseName, _TraitName, _Mem, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl, _ExtraEvalExpression, _Operator) \
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##CallableWith_##_TraitName\
		{\
		private:\
			class CDummy{};\
			template <typename t_CFunction>\
			struct TCEval2\
			{\
				typedef void CRet;\
				static CDummy fs_D(...);\
			};\
			template <typename tR>\
			struct TCEval2<tR ()>\
			{\
				typedef tR CRet;\
				template <typename t_CC> static auto fs_D(t_CC *_pM) -> decltype(_pM->m_Member _Operator);\
				static CDummy fs_D(...);\
			};\
			template <bint t_bValid, typename t_CFunction>\
			struct TCEval\
			{\
				enum\
				{\
					mc_Value = false\
				};\
				typedef void CReturnType;\
			};\
			template <typename t_CFunction>\
			struct TCEval<true, t_CFunction>\
			{\
				typedef decltype(TCEval2<t_CFunction>::fs_D(((NMib::NTraits::NPrivate::TCTypeWithMember<t_CType> *)nullptr))) CRet;\
				enum\
				{\
					mc_Value = NMib::NTraits::NPrivate::TCReturnConvertibleHelper<CRet, typename TCEval2<t_CFunction>::CRet>::mc_Value\
					&& !NMib::NTraits::TCIsSame<CRet, CDummy>::mc_Value\
				};\
				typedef typename NMib::TCChooseType<mc_Value, CRet, void>::CType CReturnType;\
			};\
			typedef TCEval\
					<\
						true\
						, t_CFunctionCallType\
					> CEvalType;\
		public:\
			enum\
			{\
				mc_Value = CEvalType::mc_Value\
			};\
			typedef typename CEvalType::CReturnType CReturnType;\
		};\
		template <typename t_CType, typename t_CFunctionCallType, bool t_bIsCallableWith = TCIs##_BaseName##CallableWith_##_TraitName<t_CType, t_CFunctionCallType>::mc_Value>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp\
		{\
			enum\
			{\
				mc_Value = false\
			};\
		};\
		template <typename t_CType, typename t_CRet>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CRet (), true>\
		{\
			enum\
			{\
				mc_Value = noexcept(NMib::fg_GetReference<t_CType>() _Operator)\
			};\
		};\
		template <typename t_CType, typename t_CFunctionCallType>\
		struct TCIs##_BaseName##NothrowCallableWith_##_TraitName : public TCIs##_BaseName##NothrowCallableWith_##_TraitName##Imp<t_CType, t_CFunctionCallType>\
		{\
		};		
		


#define DMibPrivateTypeTraitsImplement_MemberTraitsWithName(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl, _ExtraFunctionEvalExpression, _CallableSuffix, _CallableParam0, _OperatorRet2) \
		DMibPrivateTypeTraitsImplement_MemberTraitsWithNameTraits(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRet2, _OperatorRetVal, _FunctionType, _SafeImpl); \
		DMibPrivateTypeTraitsImplement_MemberTraitsWithNameFullType(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl); \
		DMibPrivateTypeTraitsImplement_MemberTraitsWithNameType(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl); \
		DMibPrivateTypeTraitsImplement_MemberTraitsWithNameHas(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl); \
		DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallable(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl); \
		DMibConcatenate(DMibPrivateTypeTraitsImplement_MemberTraitsWithNameCallableWith, _CallableSuffix)(_BaseName, _TraitName, _MemberName, _FunctionObject, _OperatorParams, _OperatorRet, _OperatorRetVal, _FunctionType, _SafeImpl, _ExtraFunctionEvalExpression, _CallableParam0);

#define DMibTypeTraitsImplement_MemberTraitsWithName(_BaseName, _TraitName, _MemberName) DMibPrivateTypeTraitsImplement_MemberTraitsWithName(_BaseName, _TraitName, _MemberName, NMib::NTraits::TCIsFunctionObject<CMemberType>::mc_Value, (), void, ;, CBaseMixin::*, Normal, true,,,void)
#define DMibTypeTraitsImplement_MemberTraits(_MemberName) DMibTypeTraitsImplement_MemberTraitsWithName(Member, _MemberName, _MemberName)

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Is Function Object																				|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		namespace NPrivate
		{
			template <typename t_CType>
			class TCFunctionObjectTraits_Helper;
			template <typename t_CType>
			class TCFunctionObjectFullType_Helper;
			template <typename t_CType>
			class TCFunctionObjectType_Helper;
			template <typename t_CType>
			class TCHasFunctionObject_Helper;
			template <typename t_CType>
			class TCIsFunctionObjectCallable_Helper;
			template <typename t_CType, typename t_CFunctionCallType>
			struct TCIsFunctionObjectCallableWith_Helper;
			template <typename t_CType>
			class TCFunctionObjectTraits_Helper;
		}
		
		template <typename t_CType>
		class TCIsFunctionObject : public TCCompileTimeConstant<bool, NPrivate::TCHasFunctionObject_Helper<t_CType>::mc_Value>
		{ 
		public:
		};		

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Is Callable																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename t_CType>
		class TCIsCallable : public TCCompileTimeConstant
			<
				bool
				, TCIsFunctionObject<t_CType>::mc_Value 
				|| (TCIsFunction<typename TCRemovePointer<typename TCRemoveReference<t_CType>::CType>::CType>::mc_Value && !TCIsFunction<t_CType>::mc_Value) 
			>
		{ 
		public:
		};		

		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Is Callable With																					|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename t_CType, typename t_CFunctionCallType>
		class TCIsCallableWith 
			: public TCCompileTimeConstant
			<
				bool
				, TCIsFunctionObject<t_CType>::mc_Value 
				? NPrivate::TCIsFunctionObjectCallableWith_Helper<t_CType, t_CFunctionCallType>::mc_Value 
				: (TCIsFunction<typename TCRemovePointer<typename TCRemoveReference<t_CType>::CType>::CType>::mc_Value && !TCIsFunction<t_CType>::mc_Value) 
				? NPrivate::TCIsFunctionCallableWithHelper<typename TCRemovePointer<typename TCRemoveReference<t_CType>::CType>::CType, t_CFunctionCallType>::mc_Value
				: false
			>
		{ 
		public:
			typedef typename TCChooseType
			<
				TCIsFunctionObject<t_CType>::mc_Value
				, typename NPrivate::TCIsFunctionObjectCallableWith_Helper<t_CType, t_CFunctionCallType>::CReturnType
				, typename TCChooseType
				<
					(TCIsFunction<typename TCRemovePointer<typename TCRemoveReference<t_CType>::CType>::CType>::mc_Value && !TCIsFunction<t_CType>::mc_Value)
					, typename NMib::NTraits::TCFunctionTraits<t_CType>::CReturn
					, void
				>::CType
			>::CType CReturnType;
		};


		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Is Constructor Callable With																		|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsConstructorCallableWith
		{
		private:
			typedef typename TCRemoveQualifiers<t_CType>::CType CType;
			template <typename t_CToGenerate>
			static t_CToGenerate G();
			class CDummy{};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Class																								|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CFunction>
			struct TCEval2
			{
				typedef void CRet;
				static CDummy fs_D(...);
			};
			template <typename tR, typename... t_PCTypes>
			struct TCEval2<tR (t_PCTypes...)>
			{
				typedef tR CRet;
				template <typename t_CC> static auto fs_D(t_CC *_pM) -> decltype(new(G<void *>()) t_CC(G<t_PCTypes>()...));
				static CDummy fs_D(...);
			};
			template <bint t_bValid, typename t_CFunction>
			struct TCEval
			{
				enum
				{
					mc_Value = false
				};
			};
			template <typename t_CFunction>
			struct TCEval<true, t_CFunction>
			{
				typedef decltype(TCEval2<t_CFunction>::fs_D(((CType *)nullptr))) CRet;
				enum
				{
					mc_Value = !NMib::NTraits::TCIsSame<CRet, CDummy>::mc_Value
				};
			};
			typedef TCEval
				<
					(NMib::NTraits::TCIsClass<CType>::mc_Value || NMib::NTraits::TCIsUnion<CType>::mc_Value)
					, t_CFunctionCallType
				> CEvalClass
			;

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Other																								|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			struct CDummy2
			{
			};

			template <bint t_bValid, typename t_CFunction>
			struct TCEvalOther
			{
				enum
				{
					mc_Value = false
				};
			};
			template <typename t_CReturn, typename t_CArgument>
			struct TCEvalOther<true, t_CReturn (t_CArgument)>
			{
				//static CDummy2 fs_D(CType);
				//static CDummy fs_D(...);

				//typedef decltype(fs_D(G<t_CArgument>())) CRet;
				enum
				{
					mc_Value = NMib::NTraits::TCIsConvertible<t_CArgument, CType>::mc_Value
					|| 
					(
						(
							NMib::NTraits::TCIsRValueReference<t_CArgument>::mc_Value
							|| !NMib::NTraits::TCIsReference<t_CArgument>::mc_Value
						)
						&& NMib::NTraits::TCIsRValueReference<CType>::mc_Value 
						&& 
						(
							NMib::NTraits::TCIsSame<typename TCRemoveQualifiers<typename TCRemoveReference<t_CArgument>::CType>::CType, typename TCRemoveQualifiers<typename TCRemoveReference<CType>::CType>::CType>::mc_Value
							|| NMib::NTraits::TCIsBaseOf<typename TCRemoveQualifiers<typename TCRemoveReference<t_CArgument>::CType>::CType, typename TCRemoveQualifiers<typename TCRemoveReference<CType>::CType>::CType>::mc_Value
						)
					)
				};
			};
			template <typename t_CReturn>
			struct TCEvalOther<true, t_CReturn ()>
			{
				enum
				{
					mc_Value = !NTraits::TCIsReference<CType>::mc_Value
				};
			};
			typedef TCEvalOther
					<
						!NMib::NTraits::TCIsFunction<CType>::mc_Value 
						&& !NMib::NTraits::TCIsVoid<CType>::mc_Value 
						&& !(
								NMib::NTraits::TCIsClass<CType>::mc_Value 
								|| NMib::NTraits::TCIsUnion<CType>::mc_Value
							) 
						&& !NTraits::TCIsArray<CType>::mc_Value
						, t_CFunctionCallType
					> CEvalOther;

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Array																								|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <bint t_bValid, typename t_CFunction>
			struct TCEvalArray
			{
				enum
				{
					mc_Value = false
				};
			};
/*			template <typename t_CReturn, typename t_CArgument>
			struct TCEvalArray<true, t_CReturn (t_CArgument)>
			{
				static CDummy2 fs_D(CType);
				static CDummy fs_D(...);

				typedef decltype(fs_D(G<t_CArgument>())) CRet;
				enum
				{
					mc_Value = !NMib::NTraits::TCIsSame<CRet, CDummy>::mc_Value
				};
			};*/
			template <typename t_CReturn>
			struct TCEvalArray<true, t_CReturn ()>
			{
				enum
				{
					mc_Value = TCIsConstructorCallableWith<typename TCRemoveAllExtents<CType>::CType, t_CFunctionCallType>::mc_Value
				};
			};
			typedef TCEvalArray
					<
						NMib::NTraits::TCIsArray<CType>::mc_Value && !NMib::NTraits::TCIsArrayUnbounded<CType>::mc_Value 
						, t_CFunctionCallType
					> CEvalArray;



		public:
			enum
			{
				mc_Value = CEvalClass::mc_Value || CEvalOther::mc_Value || CEvalArray::mc_Value
			};
		};


		/***************************************************************************************************\
		|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
		| Has New Operator																					|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename t_CType>
		class TCOperatorTraits_New;
		template <typename t_CType>
		class TCOperatorFullType_New;
		template <typename t_CType>
		class TCOperatorType_New;
		template <typename t_CType>
		class TCHasOperator_New;
		template <typename t_CType>
		class TCIsOperatorCallable_New;
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsOperatorCallableWith_New;
		template <typename t_CType>
		class TCOperatorTraits_New;

		template <typename t_CType>
		class TCOperatorTraits_NewArray;
		template <typename t_CType>
		class TCOperatorFullType_NewArray;
		template <typename t_CType>
		class TCOperatorType_NewArray;
		template <typename t_CType>
		class TCHasOperator_NewArray;
		template <typename t_CType>
		class TCIsOperatorCallable_NewArray;
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsOperatorCallableWith_NewArray;
		template <typename t_CType>
		class TCOperatorTraits_NewArray;

		template <typename t_CType>
		class TCOperatorTraits_Delete;
		template <typename t_CType>
		class TCOperatorFullType_Delete;
		template <typename t_CType>
		class TCOperatorType_Delete;
		template <typename t_CType>
		class TCHasOperator_Delete;
		template <typename t_CType>
		class TCIsOperatorCallable_Delete;
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsOperatorCallableWith_Delete;
		template <typename t_CType>
		class TCOperatorTraits_Delete;

		template <typename t_CType>
		class TCOperatorTraits_DeleteArray;
		template <typename t_CType>
		class TCOperatorFullType_DeleteArray;
		template <typename t_CType>
		class TCOperatorType_DeleteArray;
		template <typename t_CType>
		class TCHasOperator_DeleteArray;
		template <typename t_CType>
		class TCIsOperatorCallable_DeleteArray;
		template <typename t_CType, typename t_CFunctionCallType>
		struct TCIsOperatorCallableWith_DeleteArray;
		template <typename t_CType>
		class TCOperatorTraits_DeleteArray;

		template <typename t_CType>
		class TCHasOperatorNew : public TCCompileTimeConstant<bool, (TCHasOperator_New<t_CType>::mc_Value
			|| TCHasOperator_NewArray<t_CType>::mc_Value)>
		{ 
		public:
		};

		template <typename t_CType>
		class TCHasOperatorDelete : public TCCompileTimeConstant<bool, (TCHasOperator_Delete<t_CType>::mc_Value
			|| TCHasOperator_DeleteArray<t_CType>::mc_Value)>
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
				bint
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
}

namespace NMib
{
	namespace NTraits
	{
		namespace NPrivate
		{
			DMibPrivateTypeTraitsImplement_MemberTraitsWithName(FunctionObject, Helper, operator(), 0, (), void, ;, CBaseMixin::*, Normal, true,,,void);
		}

		DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, New, operator new, 0, (mint) noexcept, void *, return nullptr;, *, Safe, true,,,void*);
		DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, NewArray, operator new [], 0, (mint) noexcept, void *, return nullptr;, *, Safe, true,,,void*);
		DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, Delete, operator delete, 0, (void *), void, ;, *, Safe, true,,,void);
		DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, DeleteArray, operator delete [], 0, (void *), void, ;, *, Safe, true,,,void);

#define DMibTypeTraitsImplement_MemberTraits_BinaryOperator(_OperatorName, _Operator) DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, _OperatorName, operator _Operator, 0, (CBaseMixin const &), bool, return false;, CBaseMixin::*, Safe, true,BinaryOperator,_Operator,bool);
#define DMibTypeTraitsImplement_MemberTraits_PrefixOperator(_OperatorName, _Operator) DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, _OperatorName, operator _Operator, 0, (CBaseMixin const &), bool, return false;, CBaseMixin::*, Safe, true,PrefixOperator,_Operator,bool);
#define DMibTypeTraitsImplement_MemberTraits_PostfixOperator(_OperatorName, _Operator) DMibPrivateTypeTraitsImplement_MemberTraitsWithName(Operator, _OperatorName, operator _Operator, 0, (CBaseMixin const &), bool, return false;, CBaseMixin::*, Safe, true,PostfixOperator,_Operator,bool);

		DMibTypeTraitsImplement_MemberTraits_BinaryOperator(LessThan, <);
		DMibTypeTraitsImplement_MemberTraits_BinaryOperator(Assign, =);
	}
}
