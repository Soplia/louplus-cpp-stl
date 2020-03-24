#pragma once

#include <cstring>
#include <utility>
#include "xallocator.h"
#include "xfunctional.h"
#include "xiterator.h"
#include "xtypetrait.h"
#include "xutility.h"

namespace jrxstl
{
	template<class InputIterator, class Distance>
	void _advance(InputIterator& it, Distance n, input_iterator_tag) {
		assert(n >= 0);
		while (n--) {//当n大于0，迭代器前移n位
			++it;
		}
	}

	template<class InputIterator, class Distance>
	void advance(InputIterator& it, Distance n) {
		typedef typename iterator_traits<InputIterator>::iterator_category iterator_category;
		_advance(it, n, iterator_category());
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
		_distance(InputIterator first, InputIterator last, input_iterator_tag) {
		typename iterator_traits<InputIterator>::difference_type dist = 0;//初始化距离
		while (first++ != last) {//当首地址不等于尾地址，距离增加
			++dist;
		}
		return dist;//返回迭代器间距离
	}

	template<class Iterator>
	typename iterator_traits<Iterator>::difference_type
		distance(Iterator first, Iterator last) {
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		//Does this place use 仿函数
		return _distance(first, last, iterator_category());
	}

	template <class InputIterator, class xt>
	InputIterator find(InputIterator first, InputIterator last, const xt & val)
	{
		for (; first != last; ++first)
			if (*first == val)
				break;
		return first;
	}

	template <class T>
	const T& max(const T& a, const T& b) {
		return (a < b) ? b : a;
	}
	template <class T, class Compare>
	const T& max(const T& a, const T& b, Compare comp) {
		return (copm(a, b)) ? b : a;
	}

	template <class T>
	const T& min(const T& a, const T& b) {
		return !(b < a) ? a : b;
	}
	template <class T, class Compare>
	const T& min(const T& a, const T& b, Compare comp) {
		return !comp(b, a) ? a : b;
	}

	template<class OutputIterator, class Size, class T>
	OutputIterator fill_n(OutputIterator first, Size n, const T& value)
	{
		for (; n > 0; --n, ++first)
			*first = value;
		return first;
	}
	template<class Size>
	char *fill_n(char *first, Size n, const char& value)
	{
		memset(first, static_cast<unsigned char>(value), n);
		return first + n;
	}
	template<class Size>
	wchar_t *fill_n(wchar_t *first, Size n, const wchar_t& value)
	{
		memset(first, static_cast<unsigned char>(value), n * sizeof(wchar_t));
		return first + n;
	}

	template<class RandomIterator, class BinaryPredicate>
	typename iterator_traits<RandomIterator>::value_type
		mid3(RandomIterator first, RandomIterator last, BinaryPredicate pred) {//[first, last]
		auto mid = first + (last + 1 - first) / 2;
		if (pred(*mid, *first)) {
			swap(*mid, *first);
		}
		if (pred(*last, *mid)) {
			swap(*last, *mid);
		}
		if (pred(*last, *first)) {
			swap(*last, *first);
		}
		auto ret = *mid;
		swap(*mid, *(last - 1));//将mid item换位作为哨兵
		return ret;
	}

	template<class RandomIterator>
	void sort(RandomIterator first, RandomIterator last) {
		return sort(first, last, less<typename iterator_traits<RandomIterator>::value_type>());
	}

	template<class RandomIterator, class BinaryPredicate>
	void bubble_sort(RandomIterator first, RandomIterator last, BinaryPredicate pred) {
		auto len = last - first;
		for (auto i = len; i != 0; --i) {
			bool swaped = false;
			for (auto p = first; p != (first + i - 1); ++p) {
				if (pred(*(p + 1), *p)) {
					swap(*(p + 1), *p);
					swaped = true;
				}
			}
			if (!swaped)
				break;
		}
	}

	template<class RandomIterator, class BinaryPredicate>
	void sort(RandomIterator first, RandomIterator last, BinaryPredicate pred) {
		if (first >= last || first + 1 == last)
			return;
		if (last - first <= 20)//区间长度小于等于20的采用冒泡排序更快
			return bubble_sort(first, last, pred);
		auto mid = mid3(first, last - 1, pred);
		auto p1 = first, p2 = last - 2;
		while (p1 < p2) {//快速排序
			while (pred(*p1, mid) && (p1 < p2)) ++p1;
			while (!pred(*p2, mid) && (p1 < p2)) --p2;
			if (p1 < p2) {
				swap(*p1, *p2);
			}
		}
		swap(*p1, *(last - 2));//将作为哨兵的mid item换回原来的位置
		sort(first, p1, pred);
		sort(p1 + 1, last, pred);
	}

	template <class RandomAccessIterator, class Compare>
	void pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
		jrxstl::swap(*first, *(last - 1));
		if (last - first >= 2)
			jrxstl::down(first, last - 2, first, comp);
	}

	template<class RandomAccessIterator, class Compare>
	//heap上溯算法
	static void up(RandomAccessIterator first, RandomAccessIterator last,
		RandomAccessIterator head, Compare comp) {
		if (first != last) {
			int index = last - head;
			auto parentIndex = (index - 1) / 2;
			for (auto cur = last; parentIndex >= 0 && cur != head; parentIndex = (index - 1) / 2) {
				auto parent = head + parentIndex;//get parent
				if (comp(*parent, *cur))
					jrxstl::swap(*parent, *cur);
				cur = parent;
				index = cur - head;
			}
		}
	}

	template<class RandomAccessIterator, class Compare>
	//heap下降算法
	static void down(RandomAccessIterator first, RandomAccessIterator last,
		RandomAccessIterator head, Compare comp) {
		if (first != last) {
			auto index = first - head;
			auto leftChildIndex = index * 2 + 1;
			for (auto cur = first; leftChildIndex < (last - head + 1) && cur < last; leftChildIndex = index * 2 + 1) {
				auto child = head + leftChildIndex;//get the left child
				if ((child + 1) <= last && *(child + 1) > *child)//cur has a right child
					child = child + 1;
				if (comp(*cur, *child))
					jrxstl::swap(*cur, *child);
				cur = child;
				index = cur - head;
			}
		}
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator __copy(InputIterator first, InputIterator last, OutputIterator result, _true_type) {
		auto dist = distance(first, last);
		memcpy(result, first, sizeof(*first) * dist);
		advance(result, dist);
		return result;
	}
	template<class InputIterator, class OutputIterator>
	OutputIterator __copy(InputIterator first, InputIterator last, OutputIterator result, _false_type) {
		while (first != last) {
			*result = *first;
			++result;
			++first;
		}
		return result;
	}
	template<class InputIterator, class OutputIterator, class T>
	OutputIterator _copy(InputIterator first, InputIterator last, OutputIterator result, T*) {
		typedef typename jrxstl::_type_traits<T>::is_POD_type is_pod;
		return __copy(first, last, result, is_pod());
	}

	template <class InputIterator, class OutputIterator>
	OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
		return _copy(first, last, result, value_type(first));
	}
	template<>
	inline char *copy(char *first, char *last, char *result) {
		auto dist = last - first;
		memcpy(result, first, sizeof(*first) * dist);
		return result + dist;
	}
	template<>
	inline wchar_t *copy(wchar_t *first, wchar_t *last, wchar_t *result) {
		auto dist = last - first;
		/*
		The memcpy() function takes three arguments : dest, src and count.
		This function when called, copies count bytes from the memory location 
		pointed to by src to the memory location pointed to by dest.
		*/
		memcpy(result, first, sizeof(*first) * dist);
		return result + dist;
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator set_intersection(InputIterator first1, InputIterator last1,
		InputIterator first2, InputIterator last2,
		OutputIterator d_first) {
		while (first1 != last1 && first2 != last2) {
			if (*first1 < *first2) {
				++first1;
			}
			else {
				if (!(*first2 < *first1)) {
					*d_first++ = *first1++;
				}
				++first2;
			}
		}
		return d_first;
	}


}
