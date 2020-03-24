#pragma once

#include<cstddef>
#include<cassert>
#include<iostream>
#include<string>
#include<cstring>
#include<exception> 

namespace jrxstl{

	typedef std::size_t size_type;

	unsigned char get_true(size_type index) // 1 - 8
	{
		assert(index >= 1 && index <= 8);
		return (unsigned char)1 << (index - 1);
		// �õ�����00010000��������
	}
	unsigned char get_false(size_type index)
	{
		assert(index >= 1 && index <= 8);
		return ~get_true(index);
		// �õ�����11101111��������
	}

	void set_false(unsigned char& val, size_type index) // index (1 - 8)
	{
		assert(index >= 1 && index <= 8);
		val &= get_false(index);
	}
	void set_true(unsigned char& val, size_type index) // index (1 - 8) 
	{
		assert(index >= 1 && index <= 8);
		val |= get_true(index);
	}

	void* set(void* ptr, size_type pos, bool val = true)
	{   //һ���Եĺ��������������е���ֵ�ĵ���bit���趨
		assert(ptr != 0);
		unsigned char *pointer = (unsigned char*)ptr;
		size_type subpos = (pos + 7) / 8 - 1;
		size_type index = (pos + 7) % 8 + 1;
		if (val)
			set_true(pointer[subpos], index);
		else
			set_false(pointer[subpos], index);
		return ptr;
	}

	bool read(void *ptr, size_type pos)
	{
		assert(ptr != 0);
		unsigned char *pointer = (unsigned char*)ptr;
		size_type subpos = (pos + 7) / 8 - 1;
		size_type index = (pos + 7) % 8 + 1;
		char tmp_val = (pointer[subpos] >> (index - 1)) & char(1);
		return tmp_val > 0;
	}

	class  invalid_argument_1 {};

	template<std::size_t N>
	
	class bitset 
	{
	public:
		typedef bitset self;
		typedef std::size_t size_type;
		typedef unsigned long ULONG;
		typedef unsigned long long ULLONG;
		typedef unsigned char UCHAR;
	public:
		class ref 
		{  //дһ�������࣬��Ϊc++�޷��Ե�����λ��������
		public:
			typedef std::size_t size_type;
			typedef ref self;
			UCHAR *head;
			size_type position;
		public:
			ref(UCHAR* tmp_ptr, size_type pos) :head(tmp_ptr), position(pos)
			{
			}
		public:
			self& operator = (const self& tmp)
			{//jrxstl::set��pos��1��ʼ����,��˼�1,���¶������
				jrxstl::set(head, position + 1, jrxstl::read(tmp.head, tmp.position + 1));
				return *this;
			}
			self& operator = (const bool& tmp)
			{
				assert(head != 0);
				jrxstl::set(head, position + 1, tmp);
				return *this;
			}
			bool operator == (const bool& tmp) const
			{
				assert(head != 0);
				return jrxstl::read(head, position + 1) == tmp;
			}
			bool operator != (const bool& tmp) const
			{
				assert(head != 0);
				return !(*this == tmp);
			}
			bool operator == (const self& tmp) const
			{
				assert(head != 0);
				return jrxstl::read(head, position + 1) ==
					jrxstl::read(tmp.head, tmp.position + 1);
			}
			bool operator != (const self& tmp) const
			{
				return !(*this == tmp);
			}

			friend std::ostream& operator << (std::ostream& os, const self& tmp)
			{
				return os << jrxstl::read(const_cast<UCHAR*>(tmp.head), tmp.position + 1);
			}
			friend std::istream& operator >> (std::istream& is, self& tmp)
			{ // ��׼���޴˹���,�о�Ӧ�ü��ϣ����˼��⣬�Ǻǣ�
				bool tmp_val = false;
				is >> tmp_val;
				jrxstl::set(tmp.head, tmp.position + 1, tmp_val);
				return is;
			}
		};

	private:
		typedef ref reference;
		typedef const ref const_reference;
		static const size_type SIZE = N;
		UCHAR *head;
	private:   //�ڲ�ʹ�õ�һЩ����
		bool read(void *ptr, size_type pos) const   // ��0��ʼ
		{ // jrxstl���read��1��ʼ������������ת����,����ͬ��ɵ�
			return jrxstl::read(ptr, pos + 1);
		}
		void* set(void* ptr, size_type pos, bool val = true) const  // ��0��ʼ
		{ //���߼��Ͻ�����Ӧ����const��Ϊ��ͨ���ԣ����˸�const
		  // Ҳ��������дһ����const�汾
			return jrxstl::set(ptr, pos + 1, val);
		}
		size_type get_pos(size_type pos) const   // ��0��ʼ
		{ // ����˵������λ����λ������10λ1000 0001 11 �����һλgetpos�Ľ��Ϊ1,
			// �ǵڶ����ֽڣ�getsub����1
			return pos / 8;
		}
		size_type get_sub(size_type pos) const   // ��0��ʼ
		{  // 
			return pos % 8;
		}
		// ������Чλ��,�ɵ�λ����λ����11010000��ЧλΪ4λ
		size_type get_num_count() const
		{
			size_type m_count = 0;
			for (size_type i = size(); i >= 1; )
				if (test(--i))
					break;
				else
					++m_count;
			return size() - m_count;
		}
		void zero_last() //�����ʣ��λ����
		{  //�磬��4λ1101,���Ƿ������һ���ֽڣ�����4λ���ã�����
			size_type cur_pos = get_pos(size());
			size_type cur_sub = get_sub(size());
			++cur_sub;
			for (size_type i = cur_sub; i < 8; ++i)
				set(&head[cur_pos], i, false);
		}
		void fill(size_type first, size_type last, bool val = false)
		{  // ������[first,last)�ڵ�λ�������
			assert(first >= 0 && last <= size());
			for (size_type i = first; i < last; ++i)
				set(i, val);  // ��Ա����
		}
		void copy_left(size_type des, size_type beg, size_type end)
		{  // ����[beg,end);
			assert(des >= 0 && des <= beg);
			if (des == beg)  // �ƶ�0λ�����
				return;
			while (beg != end)
				set(des++, test(beg++));
		}
		void copy_right(size_type des, size_type beg, size_type end)
		{  // �����,desΪĩ��λ�ü� 1
			assert(des >= end && des <= size());
			if (end == size())   // �ƶ�0λ�����
				return;
			while (end != beg)
				set(--des, test(--end));
		}
	public:
		bitset()
		try :head(0)
		{  //���������ֽ�������SIZE Ϊ10�����2���ֽھͿ����ˣ�ʣ��6λ����16-10��
			// ����ͬ��ɵ�
			head = new UCHAR[get_pos(size()) + 1];
			std::memset(head, 0, get_pos(size()) + 1); // 
		}
		catch (...)
		{
#ifdef _DEBUG
			std::cerr << "out of memory" << std::endl;
#endif
		}
		
		//googleԼ�����е������Ĺ��캯������������ʾ��
		//ֻ�м���������¿������캯�����Բ�������explicit
		explicit bitset(ULONG val)    // unsigned long �汾
		try :head(0)
		{
			head = new UCHAR[get_pos(size()) + 1];
			std::memset(head, 0, get_pos(size()) + 1); // 
			for (size_type i = 0; i < size() && i < sizeof(ULONG) * 8; ++i)
				set(i, read(&val, i));
		}
		catch (...)
		{
#ifdef _DEBUG
			std::cerr << "out of memory" << std::endl;
#endif
		}
		
		explicit bitset(const std::string& str, size_type pos = 0, size_type n = std::string::npos)
		try :head(0)
		{

			head = new UCHAR[get_pos(size()) + 1];
			std::memset(head, 0, get_pos(size()) + 1); // 
			assert(n == std::string::npos || pos + n < str.size());
			if (pos + n > str.size())
				n = str.size() - pos;
			for (size_type i = 0, j = pos + n; i < size() && j >= pos + 1; )
			{
				assert(str[j - 1] == '0' || str[j - 1] == '1');
#ifdef NDEBUG
				if (str[j - 1] != '0' && str[j - 1] != '1')
					throw jrxstl::invalid_argument_1();  //�Ƿ��������׳��쳣
#endif
				set(head, i++, str[--j] == '1');
			}
		}
		catch (...)
		{
#ifdef _DEBUG
			std::cerr << "out of memory" << std::endl;
#endif
		}
		
		//���ƹ��캯��
		bitset(const self& temp) :head(0)
		{
			head = new UCHAR[get_pos(size()) + 1];
			std::memcpy(head, temp.head, get_pos(size()) + 1);
		}
		
		self& operator = (const self& temp)  //���Ƹ�ֵ
		{    // ֱ�Ӹ��ǣ����ﲻ�����ͷ���Դ����Ϊ����һ�£�SIZEһ��
			if (this == &temp)
				return *this;
			std::memcpy(head, temp.head, get_pos(size()) + 1);
			return *this;
		}
		~bitset()
		{
			delete[] head;
		}


	public:
		const_reference operator [] (size_type pos) const
		{
			assert(pos < size());
			return reference(head, pos);
		}

		reference operator [] (size_type pos)
		{
			assert(pos < size());
			return reference(head, pos);
		}

		size_type size() const
		{
			return SIZE;
		}

		size_type count() const
		{
			size_type m_count = 0;
			for (size_type i = 0; i < size(); ++i)
			{
				size_type cur_pos = get_pos(i);
				size_type cur_sub = get_sub(i);
				if (read(&head[cur_pos], cur_sub))
					++m_count;
			}
			return m_count;
		}

		self& set()
		{
			std::memset(head, 0xFF, get_pos(size()) + 1);
			// ��ʣ���λ����
			zero_last();
			return *this;
		}
		self& set(size_type pos, bool val = true)
		{
			assert(pos < size());
			size_type cur_pos = get_pos(pos);
			size_type cur_sub = get_sub(pos);
			set(&head[cur_pos], cur_sub, val);
			return *this;
		}

		bool any() const
		{
			for (size_type i = 0; i <= get_pos(size()); ++i)
				if (head[i])
					return true;
			return false;
		}
		bool none() const
		{
			for (size_type i = 0; i <= get_pos(size()); ++i)
				if (head[i])
					return false;
			return true;
		}
		self& reset()
		{
			std::memset(head, 0, get_pos(SIZE) + 1);
			return *this;
		}
		self& reset(size_type pos)
		{
			assert(pos < size());
			size_type cur_pos = get_pos(pos);
			size_type cur_sub = get_sub(pos);
			set(&head[cur_pos], cur_sub, false);
			return *this;
		}
		bool test(size_t pos) const
		{
			assert(pos < size());
			size_type cur_pos = get_pos(pos);
			size_type cur_sub = get_sub(pos);
			return read(&head[cur_pos], cur_sub);
		}

		self& flip()
		{
			size_type pos = get_pos(size());
			for (size_type i = 0; i <= pos; ++i)
				head[i] = ~head[i];
			zero_last();
			return *this;
		}
		self& filp(size_type pos)
		{
			assert(pos < size());
			if (test(pos))
				set(pos, false);
			else
				set(pos, true);
			return *this;
		}
		std::string to_string() const
		{
			std::string str(size(), '0');   // �Զ�����Ч�ʵͣ�����ֱ�ӳ�ʼ��
			for (size_type i = size(), j = 0; i >= 1; )
				if (test(--i))
					str[j++] = '1';
				else
					++j; // �������ù���ֱ�����������ø�����
			return str;
		}
		ULONG to_ulong() const
		{
			size_type num_count = get_num_count();
			assert(num_count <= sizeof(ULONG) * 8);
#ifdef NDEBUG
			if (num_count > sizeof(ULONG) * 8)
				throw std::overflow_error("overflow error,please check it");
#endif
			if (size() == sizeof(ULONG) * 8 || num_count == sizeof(ULONG) * 8)
				return *(ULONG*)head;
			ULONG tmp_val = 0;
			for (size_type i = 0; i < num_count; ++i)
				set(&tmp_val, i, test(i));
			return tmp_val;
		}
		ULLONG to_ullong() const   // c++11 ����
		{
			size_type num_count = get_num_count();
			assert(num_count <= sizeof(ULLONG) * 8);
#ifdef NDEBUG
			if (num_count > sizeof(ULLONG) * 8)
				throw std::overflow_error("overflow error,please check it");
#endif
			if (size() == sizeof(ULLONG) * 8 || num_count == sizeof(ULLONG) * 8)
				return *(ULLONG*)head;
			if (num_count <= sizeof(ULONG) * 8)
				return to_ulong();
			ULLONG tmp_val = 0;
			for (size_type i = 0; i < num_count; ++i)
				set(&tmp_val, i, test(i));
			return tmp_val;
		}
		//������һЩλ������������
		self& operator &= (const self& obj)
		{
			size_type position = get_pos(size());
			for (size_type i = 0; i <= position; ++i)
				head[i] &= obj.head[i];
			return *this;
		}
		self& operator |= (const self& obj)
		{
			size_type position = get_pos(size());
			for (size_type i = 0; i <= position; ++i)
				head[i] |= obj.head[i];
			return *this;
		}
		self& operator ^= (const self& obj)
		{
			size_type position = get_pos(size());
			for (size_type i = 0; i <= position; ++i)
				head[i] ^= obj.head[i];
			return *this;
		}
		self operator | (const self& obj) const
		{
			self temp(*this);
			temp |= obj;
			return temp;
		}
		self operator & (const self& obj) const
		{
			self temp(*this);
			temp &= obj;
			return temp;
		}
		self operator ^ (const self& obj) const
		{
			self temp(*this);
			temp ^= obj;
			return temp;
		}
		self operator ~ () const
		{
			self temp(*this);
			temp.flip();
			return temp;
		}
		self& operator <<= (size_type n)
		{
			if (n == 0)
				return *this;
			if (n >= size())
				std::memset(head, 0, get_pos(size()) + 1);
			//������Ҹ��Ƹ���
			else
			{
				copy_right(size(), 0, size() - n);
				fill(0, n, false); // �ճ���λ�����0
			}
			return *this;
		}
		self& operator >>= (size_type n)
		{
			if (n == 0)
				return *this;
			if (n >= size())
				std::memset(head, 0, get_pos(size()) + 1);
			else
			{
				copy_left(0, n, size());
				fill(size() - n, size(), false);
			}
			return *this;
		}
		self operator << (size_type n) const
		{
			self temp(*this);
			temp <<= n;  // ת��operator <<= 
			return temp;
		}
		self operator >> (size_type n) const
		{
			self temp(*this);
			temp >>= n;
			return temp;
		}
		bool operator == (const self& obj) const
		{
			size_type pos = get_pos(size());
			for (size_type i = 0; i <= pos; ++i)
				if (head[i] != obj.head[i])
					return false;
			return true;
		}
		bool operator != (const self& obj) const
		{
			return !(*this == obj);
		}
		friend std::ostream& operator << (std::ostream& os, const self& obj)
		{
			for (size_type i = obj.size(); i > 0; )
				os << obj.test(--i);
			return os;
		}
	};

}