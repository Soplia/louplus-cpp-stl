#pragma once

namespace jrxstl
{
	template <class xt>
	struct unary_function
	{
		typedef xt argument_type;
		typedef xt result_type;
	};

	template <class xt>
	struct binary_function
	{
		typedef xt first_argument_type;
		typedef xt second_argument_type;
		typedef xt result_type;
	};

	template <class xt>
	struct less
	{
		typedef xt first_argument_type;
		typedef xt second_argument_type;
		typedef bool result_type;

		result_type operator() (const first_argument_type& a, const second_argument_type& b)
		{
			return a < b;
		}
	};

	template <class xt>
	struct equal_to
	{
		typedef xt first_argument_type;
		typedef xt second_argument_type;
		typedef bool result_type;

		result_type operator() (const first_argument_type& a, const second_argument_type& b)
		{
			return a == b;
		}
	};

	template <class xt>
	struct identity : public unary_function<xt>
	{
		const xt& operator() (const xt &x) const
		{
			return x;
		}
	};

	template <class xt>
	struct select1st : public unary_function<xt>
	{
		const typename xt::first_type& operator()(const xt& x) const
		{
			return x.first;
		}
	};

}