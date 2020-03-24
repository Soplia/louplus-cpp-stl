#pragma once

#include <type_traits>
#include "xalgorithm.h"
#include "xiterator.h"
#include "xallocator.h"
#include "xreverseiterator.h"
#include "xuninitializedfunctions.h"

namespace jrxstl {
	template<class T, class Alloc = allocator<T>>
	class deque;
	namespace Detail {
		//class of deque iterator
		template<class T>
		class dq_iter :public iterator<bidirectional_iterator_tag, T> {
		private:
			template<class ELEM, class alloc>
			friend class ::jrxstl::deque;
		private:
			//typedef jrxstl::deque<T>* cntrPtr;
			typedef const ::jrxstl::deque<T>* cntrPtr;
			size_t mapIndex_;
			T *cur_;
			cntrPtr container_;
		public:
			typedef T& reference;
			typedef T& pointer;
			dq_iter() :mapIndex_(-1), cur_(0), container_(0) {}
			dq_iter(size_t index, T *ptr, cntrPtr container)
				:mapIndex_(index), cur_(ptr), container_(container) {}
			dq_iter(const dq_iter& it)
				:mapIndex_(it.mapIndex_), cur_(it.cur_), container_(it.container_) {}
			dq_iter& operator = (const dq_iter& it);
			void swap(dq_iter& it);
			reference operator *() { return *cur_; }
			//const reference operator *()const{ return *cur_; }
			pointer operator ->() { return &(operator*()); }
			//const pointer operator ->()const{ return &(operator*()); }
			dq_iter& operator ++();
			dq_iter operator ++(int);
			dq_iter& operator --();
			dq_iter operator --(int);
			bool operator ==(const dq_iter& it)const;
			bool operator !=(const dq_iter& it)const;
		private:
			T *getBuckTail(size_t mapIndex)const;
			T *getBuckHead(size_t mapIndex)const;
			size_t getBuckSize()const;
		public:
			template<class ELEM>
			friend dq_iter<ELEM> operator + (const dq_iter<ELEM>& it, typename dq_iter<ELEM>::difference_type n);
			template<class ELEM>
			friend dq_iter<ELEM> operator + (typename dq_iter<ELEM>::difference_type n, const dq_iter<ELEM>& it);
			template<class ELEM>
			friend dq_iter<ELEM> operator - (const dq_iter<ELEM>& it, typename dq_iter<ELEM>::difference_type n);
			template<class ELEM>
			friend dq_iter<ELEM> operator - (typename dq_iter<ELEM>::difference_type n, const dq_iter<ELEM>& it);
			template<class ELEM>
			friend typename dq_iter<ELEM>::difference_type operator - (const dq_iter<ELEM>& it1, const dq_iter<ELEM>& it2);
			template<class ELEM>
			friend void swap(dq_iter<ELEM>& lhs, dq_iter<ELEM>& rhs);
		};
	}// end of Detail namespace

	//class of deque
	template<class T, class Alloc>
	class deque {
	private:
		template<class ELEM>
		friend class ::jrxstl::Detail::dq_iter;
	public:
		typedef T value_type;
		typedef Detail::dq_iter<T> iterator;
		typedef Detail::dq_iter<const T> const_iterator;
		typedef T& reference;
		typedef const reference const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;
	private:
		typedef Alloc dataAllocator;
		enum class EBucksSize { BUCKSIZE = 64 };
	private:
		iterator beg_, end_;
		size_t mapSize_;
		T **map_;
	public:
		deque();
		explicit deque(size_type n, const value_type& val = value_type());
		template <class InputIterator>
		deque(InputIterator first, InputIterator last);
		deque(const deque& x);

		~deque();

		deque& operator= (const deque& x);
		deque& operator= (deque&& x);

		iterator begin();
		iterator end();
		iterator begin()const;
		iterator end()const;
	public:
		size_type size() const { return end() - begin(); }
		bool empty() const { return begin() == end(); }

		reference operator[] (size_type n);
		reference front();
		reference back();
		const_reference operator[] (size_type n) const;
		const_reference front() const;
		const_reference back() const;

		void push_back(const value_type& val);
		void push_front(const value_type& val);
		void pop_back();
		void pop_front();
		void swap(deque& x);
		void clear();
	private:
		T *getANewBuck();
		T** getANewMap(const size_t size);
		size_t getNewMapSize(const size_t size);
		size_t getBuckSize()const;
		void init();
		bool back_full()const;
		bool front_full()const;
		void deque_aux(size_t n, const value_type& val, std::true_type);
		template<class Iterator>
		void deque_aux(Iterator first, Iterator last, std::false_type);
		void reallocateAndCopy();
	public:
		template <class ELEM, class alloc>
		friend bool operator== (const deque<ELEM, alloc>& lhs, const deque<ELEM, alloc>& rhs);
		template <class ELEM, class alloc>
		friend bool operator!= (const deque<ELEM, alloc>& lhs, const deque<ELEM, alloc>& rhs);
		template <class ELEM, class alloc>
		friend void swap(deque<ELEM, alloc>& x, deque<ELEM, alloc>& y);
	};//end of deque
}

#include "xdeque.impl.h"