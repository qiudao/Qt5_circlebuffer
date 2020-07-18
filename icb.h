#ifndef __ICB_H
#define __ICB_H

#include <QObject>
#include <QDebug>

template<typename T> void myswap(T& t1, T& t2)
{
	T tmpT;
	tmpT = t1;
	t1 = t2;
	t2 = tmpT;
}

template<typename T> 
class Stack {
	public:
		Stack(int size = 10)
		{
			m_eleSize 	= sizeof(T);
			m_cap		= size;
			m_head 		= 0;
			m_tail 		= 0;
			m_count 	= 0;

			m_buf = (T*)malloc((m_eleSize+1) * sizeof(T));
		};
		~Stack(){};

		/* push */
		bool push(T& v)
	   	{
			if (isFull())
			{
				m_head++;
				if (m_head > m_cap)
					m_head = 0;
			} else {
				m_count++;
			}
			//m_buf[m_tail] = v;
			memcpy(&m_buf[m_tail], &v, sizeof(T));
			m_tail++;
			if (m_tail > m_cap)
				m_tail = 0;

			return true;
		};

		/* pop */
		bool pop(T *t) 
		{
			if (isEmpty())
				return false;

			memcpy((void *)t, (void*)&m_buf[m_head], sizeof(T));
			m_head++;
			if (m_head > m_cap)
				m_head = 0;

			m_count--;
			if (m_head == m_tail)
				reset();
			return true;
		}

		T& at(int index) 
		{
			if (index + 1 > m_count)
				return m_buf[0];

			index += m_head;
			if (index > m_cap)
				index -= (m_cap + 1);
			return m_buf[index];
		}

		void reset()
		{
			m_head 	= 0;
			m_tail 	= 0;
			m_count	= 0;
		}

		int cap() {return m_cap;}
		int dataAvail() { return m_count;}
		int eleSize() {return m_eleSize;}
		int space() {return m_cap - m_count;}
		bool isFull() {return m_count == m_cap;}
		bool isEmpty() {return m_count == 0;}

	private:
		int m_eleSize;
		int m_head;
		int m_tail;
		int m_cap;
		int m_count;
		T   *m_buf;
};



#endif
