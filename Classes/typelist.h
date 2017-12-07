#pragma once
#ifndef __TYPE_LIST_H__ 
#define __TYPE_LIST_H__ 

//************************基础数据***********************************

struct NullType;

#define __null() NullType

template<int V>
struct IntType
{
	enum
	{
		Value = V,
	};
	using Result = IntType<V>;
};

template<bool V>  struct BoolType;

template<>
struct BoolType<true>
{
	enum
	{
		Value = true,
	};

	using Result = BoolType<true>;
};

template<>
struct BoolType<false>
{
	enum
	{
		Value = false,
	};
	using Result = BoolType<false>;
};

using TrueType = BoolType<true>::Result;
using FalseType = BoolType<false>::Result;

template<typename T, typename V>
struct IsEqual
{
	using Result = FalseType;
};

template<typename T>
struct IsEqual<T, T>
{
	using Result = TrueType;
};

template<typename T>
struct Print
{
	//const int Value = 1 / (sizeof(T) - sizeof(T)); 编译错误，打印失败
};

template<typename T>
struct Value
{
	enum
	{
		Result = T::Value,
	};
};

struct EmptyType
{

};

#define __empty() EmptyType

template<>
struct Value<EmptyType>
{
	enum
	{
		Result = 0,
	};
};

template<typename T1, typename T2> struct Add;
template<>
struct Add<NullType, NullType>
{
	using Result = NullType;
};
template<int V>
struct Add<NullType, IntType<V>>
{
	using Result = NullType;
};
template<int V>
struct Add<IntType<V>, NullType>
{
	using Result = NullType;
};
template<int V1, int V2>
struct Add<IntType<V1>, IntType<V2>>
{
	using Result = IntType<V1 + V2>;
};

template<typename T1, typename T2> struct Sub;
template<int V1, int V2>
struct Sub<IntType<V1>, IntType<V2>>
{
	using Result = IntType<V1 - V2>;
};

template<typename T1, typename T2> struct Mul;
template<int V1, int V2>
struct Mul<IntType<V1>, IntType<V2>>
{
	using Result = IntType<V1*V2>;
};

template<typename T1, typename T2> struct Div;
template<int V1, int V2>
struct Div<IntType<V1>, IntType<V2>>
{
	using Result = IntType<V1 / V2>;
};

template<typename T1, typename T2> struct Mod;
template<int V1, int V2>
struct Mod<IntType<V1>, IntType<V2>>
{
	using Result = IntType<V1%V2>;
};

template<typename T> struct Inc;
template<int V>
struct Inc<IntType<V>>
{
	using Result = IntType<V + 1>;
};

template<typename T> struct Dec;
template<int V>
struct Dec<IntType<V>>
{
	using Result = IntType<V - 1>;
};

template<typename T> struct Not;
template<bool b>
struct Not<BoolType<b>>
{
	using Result = BoolType<!b>;
};

template<typename T1, typename T2> struct And;
template<bool b1, bool b2>
struct And<BoolType<b1>, BoolType<b2>>
{
	using Result = BoolType<b1&&b2>;
};

template<typename T1, typename T2> struct Or;
template<bool b1, bool b2>
struct Or<BoolType<b1>, BoolType<b2>>
{
	using Result = BoolType<b1 || b2>;
};

template<typename Condition, typename Then, typename Else> struct IfThenElse;
template<typename Then, typename Else>
struct IfThenElse<TrueType, Then, Else>
{
	using Result = Then;
};

template<typename Then, typename Else>
struct IfThenElse <FalseType, Then, Else>
{
	using Result = Else;
};

#define __JOIN(symbol1,symbol2) symbol1##symbol2
#define UNIQUE_NAME(prefix) __JOIN(prefix,__LINE__)

//#define __print(token, ...) char UNIQUE_NAME(token) = Print<__VA_ARGS__>()

#define __print(...) Print<__VA_ARGS__> UNIQUE_NAME(tpm_print_)
#define __int(value) typename IntType<value>::Result
#define __bool(...) typename BoolType<__VA_ARGS__>::Result
#define __true() typename TrueType::Result
#define __false() typename FalseType::Result
#define __is_eq(...) typename IsEqual<__VA_ARGS__>::Result
#define __value(...) Value<__VA_ARGS__>::Result
#define __add(...) typename Add<__VA_ARGS__>::Result
#define __sub(...) typename Sub<__VA_ARGS__>::Result
#define __mul(...) typename Mul<__VA_ARGS__>::Result
#define __div(...) typename Div<__VA_ARGS__>::Result
#define __inc(...) typename Inc<__VA_ARGS__>::Result
#define __dec(...) typename Dec<__VA_ARGS__>::Result
#define __mod(...) typename Mod<__VA_ARGS__>::Result
#define __not(...) typename Not<__VA_ARGS__>::Result
#define __and(...) typename And<__VA_ARGS__>::Result
#define __or(...) typename Or<__VA_ARGS__>::Result
#define __if(...) typename IfThenElse<__VA_ARGS__>::Result

template<typename T, typename V>
using LargerType = __if(__bool(sizeof(T) >= sizeof(V)), T, V);

template<typename T, typename V>
struct IsConvertible
{
private:
	using YES = long;
	using NO = short;

	static YES test(V);
	static NO test(...);
	static T self();
public:
	using Result = __bool(sizeof(test(self())) == sizeof(YES));
};

#define __is_convertible(...) typename IsConvertible<__VA_ARGS__>::Result
#define __is_both_convertible(T,V) __and(__is_convertible(T,V),__is_convertible(V,T))
#define __is_base_of(T,V) __and(__is_convertible(const V*,const T*), __and(__not(__is_eq(const T*,const void*)),__not(__is_eq(const T,const V))))

template<typename ...Numbers> struct Sum;
template<typename  Number, typename ...LeftNumbers>
struct Sum<Number, LeftNumbers...>
{
	using Result = typename Add<Number, typename  Sum<LeftNumbers...>::Result>::Result;
};
template<>
struct Sum<>
{
	using Result = IntType<0>;
};

#define __sum(...) typename Sum<__VA_ARGS__>::Result

template<typename T>
struct CloneCreator
{
	static T* create(const T* instance)
	{
		return instance->clone();
	}
};

template<typename T>
struct UnCloneCreator
{
	static T* create(const T* instance)
	{
		return new T(*instance);
	}
};

template<typename T, bool isCloneable> using Creator = __if(__bool(isCloneable), CloneCreator<T>, UnCloneCreator<T>);

#define TPMASSERT_TRUE(T)         \
static_assert(__value(T),"assert failed:excepted  #T is true,but it is false")

#define TPMASSERT_FALSE(T)         \
static_assert(!__value(T,"assert failed:excepted #T is false,but it is true")

#define TPMASSERT_EQ(T,Expected)       \
static_assert(__value(__is_eq(T,Expected)),"assert failed:excepted #T is equal to #Expected,but it is not")

#define TPMASSERT_NEQ(T,Expected)     \
static_assert(!__value(__is_eq(T,Expected)),"assert failed:excepted #T is not equal #Expected,but it is not")

template<typename T>
struct Valid
{
	using Result = __true();
};
template<>
struct Valid<NullType>
{
	using Result = __false();
};

#define __valid(...) typename Valid<__VA_ARGS__>::Result
#define TPMASSERT_VALID(T)         \
static_assert(__value(__valid(T)),"assert failed:Expected #T is valid,but it is not")
#define TMPASSERT_INVALID(T)     \
static_assert(!__value(__valid(T)),"assert failed:Expected #T is invalid,but it is not")

#define TEST(name) struct UNIQUE_NAME(tpm_test_)
#define FIXTURE(name) namespace tpm_test_##name

#define __func_forward(name,...)     \
using name=__VA_ARGS__

#define __func_forward_1(name,...)    \
template<typename _1> using name=__VA_ARGS__

#define __func_forward_2(name,...)    \
template<typename _1,typename _2> using name=__VA_ARGS__

#define __func_forward_3(name, ...)     \
template<typename _1, typename _2, typename _3> using name = __VA_ARGS__

#define __func_forward_4(name, ...)     \
template<typename _1, typename _2, typename _3, typename _4>  \
using name = __VA_ARGS__

__func_forward_1(TypeSize, __int(sizeof(_1)));

__func_forward_2(SupperOf, IfThenElse<__is_base_of(_1, _2), _1, _2>);  //选择父类返回

																	   //*********************************TypeList实现区************************

template<typename H, typename T>
struct TypeElem
{
	using Head = H;
	using Tail = T;
};

#define __type_elem(...) TypeElem<__VA_ARGS__>

template<typename Head, typename ...Tails>
struct TypeList
{
	using Result = TypeElem<Head, typename TypeList<Tails...>::Result>;
};
template<typename H>
struct TypeList<H>
{
	using Result = TypeElem<H, NullType>;
};
template<>
struct TypeList<NullType>
{
	using Result = __null();
};


#define __type_list(...) typename TypeList<__VA_ARGS__>::Result

template<int Head, int ...Tails>
struct ValueList
{
	using Result = TypeElem<IntType<Head>, typename ValueList<Tails...>::Result>;
};
template<int Head>
struct ValueList<Head>
{
	using Result = TypeElem < IntType<Head>, NullType >;
};

#define __value_list(...) typename ValueList<__VA_ARGS__>::Result

template<typename TL> struct Length;
template<>
struct Length<NullType>
{
	using Result = IntType<0>;
};
template<typename Head, typename Tail>
struct Length<TypeElem<Head, Tail>>
{
	using Result = typename Add<IntType<1>, typename Length<Tail>::Result>::Result;
};

#define __length(...) typename Length<__VA_ARGS__>::Result

template<typename TL, typename index> struct TypeAt;
template<int V>
struct TypeAt<NullType, IntType<V>>
{
	using Result = NullType;
};
template<typename H, typename T>
struct TypeAt<TypeElem<H, T>, IntType<1>>
{
	using Result = H;
};
template<typename H, typename T, int i>
struct TypeAt<TypeElem<H, T>, IntType<i>>
{
	using Result = typename TypeAt<T, IntType<i - 1>>::Result;
};

#define __at(...) typename TypeAt<__VA_ARGS__>::Result

template<typename TL, typename E> struct Index;
template<typename E>
struct Index<NullType, E>
{
	using Result = __null();
};
template<typename H, typename T>
struct Index<TypeElem<H, T>, H>
{
	using Result = IntType<1>;
};
template<typename H, typename T, typename E>
struct Index<TypeElem<H, T>, E>
{
	using Result = typename Add<IntType<1>, typename Index<T, E>::Result>::Result;
};

#define __index_of(...) typename Index<__VA_ARGS__>::Result
#define __is_include(...) __valid(__index_of(__VA_ARGS__))

template<typename TL, typename elem> struct Append;
template<>
struct Append < NullType, NullType >
{
	using Result = NullType;
};
template<typename T>
struct Append<NullType, T>
{
	using Result = typename TypeList<T>::Result;
};
template<typename H, typename T>
struct Append<NullType, TypeElem<H, T>>
{
	using Result = TypeElem<H, T>;
};
template<typename H, typename T, typename E>
struct Append<TypeElem<H, T>, E>
{
	using Result = TypeElem<H, typename Append<T, E>::Result>;
};

#define __append(...) typename Append<__VA_ARGS__>::Result

using EmptyList = NullType;
#define __empty_list() EmptyList

template<typename TL, typename E> struct Erase;
template<typename E>
struct Erase<NullType, E>
{
	using Result = NullType;
};
template<typename H, typename T>
struct Erase<TypeElem<H, T>, H>
{
	using Result = T;
};
template<typename H, typename T, typename E>
struct Erase<TypeElem<H, T>, E>
{
	using Result = __append(__type_list(H), typename Erase<T, E>::Result);
};

#define __erase(...) typename Erase<__VA_ARGS__>::Result

template<typename TL, typename E> struct EraseAll;
template<typename E>
struct EraseAll<NullType, E>
{
	using Result = __null();
};
template<typename H, typename T>
struct EraseAll<TypeElem<H, T>, H>
{
	using Result = typename EraseAll<T, H>::Result;
};
template<typename H, typename T, typename E>
struct EraseAll<TypeElem<H, T>, E>
{
	using Result = __append(__type_list(H), typename EraseAll<T, E>::Result);
};

#define __erase_all(...) typename EraseAll<__VA_ARGS__>::Result

template<typename TL> struct Unique;
template<>
struct Unique<NullType>
{
	using Result = __null();
};
template<typename H>
struct Unique<TypeElem<H, NullType>>
{
	using Result = __type_list(H);
};
template<typename H, typename T>
struct Unique<TypeElem<H, T>>
{
	using Result = __append(__type_list(H), \
		typename Unique<__erase_all(T, H)>::Result);
};

#define __unique(...) typename Unique<__VA_ARGS__>::Result

template<typename TL, typename O, typename N> struct Replace;
template<typename O, typename N>
struct Replace<NullType, O, N>
{
	using Result = __null();
};
template<typename H, typename T, typename N>
struct Replace<TypeElem<H, T>, H, N>
{
	using Result = __append(__type_list(N), T);
};
template<typename H, typename T, typename O, typename N>
struct Replace<TypeElem<H, T>, O, N>
{
	using Result = __append(__type_list(H), typename Replace<T, O, N>::Result);
};

#define __replace(...) typename Replace<__VA_ARGS__>::Result

template<typename TL, typename O, typename N> struct ReplaceAll;
template<typename O, typename N>
struct ReplaceAll<NullType, O, N>
{
	using Result = __null();
};
template<typename H, typename T, typename N>
struct ReplaceAll<TypeElem<H, T>, H, N>
{
	using Result = __append(__type_list(N), typename ReplaceAll<T, H, N>::Result);
};
template<typename H, typename T, typename O, typename N>
struct ReplaceAll<TypeElem<H, T>, O, N>
{
	using Result = __append(__type_list(H), typename ReplaceAll<T, O, N>::Result);
};

#define __replace_all(...) typename ReplaceAll<__VA_ARGS__>::Result

template<typename TL, typename TL1>
struct Subset
{
	using Result = __and(__is_eq(typename TL::Head, typename TL1::Head), \
		typename Subset<typename TL::Tail, typename TL1::Tail>::Result);
};
template<typename TL>
struct Subset<TL, NullType>
{
	using Result = __true();
};
template<typename TL1>
struct Subset<NullType, TL1>
{
	using Result = __false();
};

#define __subset(...) typename Subset<__VA_ARGS__>::Result

template<typename TL1, typename TL2> struct IsSubset;
template<>
struct IsSubset<NullType, NullType>
{
	using Result = __true();
};
template<typename H>
struct IsSubset<TypeElem<H, NullType>, TypeElem<H, NullType>>
{
	using Result = __true();
};
template<typename H, typename T>
struct IsSubset<NullType, TypeElem<H, T>>
{
	using Result = __false();
};
template<typename H, typename T>
struct IsSubset<TypeElem<H, T>, NullType>
{
	using Result = __true();
};
template<typename H, typename H1, typename T1>
struct IsSubset < TypeElem < H, NullType>, TypeElem < H1, T1>>
{
	using Result = __false();
};
template<typename H, typename T, typename T1>
struct IsSubset<TypeElem<H, T>, TypeElem<H, T1>>
{
	using Result = __subset(T, T1);
};
template<typename H, typename T, typename H1, typename T1>
struct IsSubset<TypeElem<H, T>, TypeElem<H1, T1>>
{
	using Result = typename IsSubset<T, typename IsSubset<T, \
		TypeElem<H1, T1>>>::Result;
};

#define __last_elem(...) __at(__VA_ARGS__,__length(__VA_ARGS__))
#define __top(...) typename __VA_ARGS__::Head

//******************************一些TypeList辅助算法***************************

template<typename TL, template<typename T> class Op> struct Any;
template<template<typename T> class Op>
struct Any<NullType, Op>
{
	using Result = __false();
};
template<typename H, typename T, template<typename T1>  class Op>
struct Any<TypeElem<H, T>, Op>
{
	using Result = __if(typename Op<H>::Result, __true(), \
		typename Any<T, Op>::Result);
};

#define __any(...) typename Any<__VA_ARGS__>::Result;

template<typename TL, template<typename T> class Op> struct All;
template<template<typename T> class Op>
struct All<NullType, Op>
{
	using Result = __true();
};
template<typename H, typename T, template<typename T1> class Op>
struct All<TypeElem<H, T>, Op>
{
	using Result = __if(typename Op<H>::Result, typename All<T, Op>, \
		__false());
};

#define __all(...) typename All<__VA_ARGS__>::Result

template<typename TL, template<typename T>  \
	class MapFunc>  struct Map;
template<template<typename T> class MapFunc>
struct Map<NullType, MapFunc>
{
	using Result = __null();
};
template<typename H, typename T, template<typename T1>  \
	class MapFunc>
	struct Map<TypeElem<H, T>, MapFunc>
{
	using Result = TypeElem<typename MapFunc<H>::Resutlt, \
		typename Map<T, MapFunc>::Result>;
};

#define __map(...) typename Map<__VA_ARGS__>::Result

template<typename TL1, typename TL2, template<typename T1, \
	typename T2> class Func> struct Transform;
template<template<typename T1, typename T2> class Func>
struct Transform <NullType, NullType, Func>
{
	using Result = __null();
};
template<typename H, typename T, template<typename T1, \
	typename T2> class Func>
	struct Transform<TypeElem<H, T>, NullType, Func>
{
	using Result = __null();
};
template<typename H, typename T, template<typename T1, \
	typename T2> class Func>
	struct Transform<NullType, TypeElem<H, T>, Func>
{
	using Result = __null();
};
template<typename H, typename T, typename H1, typename T1, \
	template<typename T2, typename T3> class Func>
struct Transform<TypeElem<H, T>, TypeElem<H1, T1>, Func>
{
	using Result = TypeElem<typename Func<H, H1>::Result, \
		typename Transform<T, T1, Func>::Result>;
};

#define __tranfrom(...) typename Transform<__VA_ARGS__>::Result

template<typename TL, template<typename T>  \
	class FilterFunc>  struct Filter;
template<template<typename T> class FilterFunc>
struct Filter <NullType, FilterFunc>
{
	using Result = __null();
};
template<typename H, typename T, template<typename T> class FilterFunc>
struct Filter<TypeElem<H, T>, FilterFunc>
{
	using Result = __if(typename FilterFunc<H>::Result, \
		typename Filter<T, FilterFunc>::Result, \
		__append(__type_list(H), Filter<T, FilterFunc>));
};

#define __filter(...) typename Filter<__VA_ARGS__>::Result

template<typename TL, template<typename T1, \
	typename T2> class Compare> struct SortUtility;
template<typename H, template<typename T1, \
	typename T2> class Compare>
	struct SortUtility<TypeElem<H, NullType>, Compare>
{
	using Result = H;
};
template<typename H, typename T, template<typename T1, typename T2> class Compare>
struct SortUtility<TypeElem<H, T>, Compare>
{
	using Result = __if(typename Compare<H, typename T::Head>::Result, \
		typename SortUtility<T, Compare>::Result, \
		typename SortUtility<TypeElem<H, typename T::Tail>, Compare>::Result);
};

template<typename Tl, template<typename T1, \
	typename T2> class Compare> struct Sort;
template<template<typename T1, typename T2> class Compare>
struct Sort<NullType, Compare>
{
	using Result = __null();
};
template<typename H, template<typename T1, typename T2> class Compare>
struct Sort <TypeElem<H, NullType>, Compare>
{
	using Result = TypeElem<H, NullType>;
};
template<typename H, typename T, template<typename T1, \
	typename T2> class Compare>
	struct Sort<TypeElem<H, T>, Compare>
{
private:
	using Tmp = typename SortUtility<TypeElem<H, T>, Compare>::Result;
public:
	using Result = TypeElem<Tmp, Sort<__erase(TypeElem<H, T>, Tmp), Compare>>;
};

template<typename T>
struct IsBuildIn
{
private:
	using lists = __type_list(char, wchar_t, char16_t, char32_t, \
		bool, short, int, long, long long, float, double, long double);
public:
	using Result = __is_include(lists, T);
};

#define __is_build_in(...) typename IsBuildIn<__VA_ARGS__>::Result

template<typename TL, template<typename> class Unit> struct ScatterInherits;
template<template<typename> class Unit>
struct ScatterInherits<NullType, Unit>
{
};
template<typename  Atom, template<typename> class Unit>
struct ScatterInherits :Unit<Atom>
{
};
template<typename H, typename T, template<typename> class Unit>
struct ScatterInherits<TypeElem<H, T>, Unit> :
	ScatterInherits<H, Unit>,
	ScatterInherits<T, Unit>
{
};

#define __scatter_inherits(...) ScatterInherits<__VA_ARGS__>

template<typename T>
struct LambaTraits :LambaTraits<decltype(&T::operator())>
{
};
template<typename C, typename R, typename ...Args>
struct LambaTraits<R(C::*)(Args...) const>
{
	using ReturnType = R;
	using ParaTypes = __type_list(Args...);
};

#define __lamba_return(...) typename LambaTraits<__VA_ARGS__>::ReturnType

#define __lamba_paras(...) typename  LambaTraits<__VA_ARGS__>::ParaTypes

#define __lamba_para(lamba,index) __at(__lamba_paras(lamba),__int(index))



#endif // !__TYPE_LIST_H__
