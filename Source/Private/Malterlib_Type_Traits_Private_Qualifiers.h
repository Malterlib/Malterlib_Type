// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#ifndef DMibPreFileToIterate // Make parser work
#error "Should not be included by itself"
#endif

#if DMibPreIterate_i > 0

#define DMibTemp_GenerateParam2(z, n, text) [DMibConcatenate(text,n)]
#define DMibTemp_Params2 DMibPreRepeat(DMibPreIterate_i, DMibTemp_GenerateParam2, t_nArray) // expands to class, class, class, class
#define DMibTemp_TemplateParams2 DMibPreGenerateParams(DMibPreIterate_i, mint t_nArray)

template <typename t_CType, DMibTemp_TemplateParams2>
class TCConstQualifier<t_CType const [] DMibTemp_Params2>
{
public:
	enum
	{
		EValue = true,
	};
	typedef t_CType CUnqualified [] DMibTemp_Params2;
	typedef t_CType const CQualified [] DMibTemp_Params2;
};

template <typename t_CType, DMibTemp_TemplateParams2>
class TCConstQualifier<t_CType const DMibTemp_Params2>
{
public:
	enum
	{
		EValue = true,
	};
	typedef t_CType CUnqualified DMibTemp_Params2;
	typedef t_CType const CQualified DMibTemp_Params2;
};


template <typename t_CType, DMibTemp_TemplateParams2>
class TCVolatileQualifier<t_CType volatile []DMibTemp_Params2>
{
public:
	enum
	{
		EValue = true,
	};
	typedef t_CType CUnqualified []DMibTemp_Params2;
	typedef t_CType volatile CQualified []DMibTemp_Params2;
};

template <typename t_CType, DMibTemp_TemplateParams2>
class TCVolatileQualifier<t_CType volatile DMibTemp_Params2>
{
public:
	enum
	{
		EValue = true,
	};
	typedef t_CType CUnqualified DMibTemp_Params2;
	typedef t_CType volatile CQualified DMibTemp_Params2;
};

#undef DMibTemp_TemplateParams2
#undef DMibTemp_Params2
#undef DMibTemp_GenerateParam2

#endif

