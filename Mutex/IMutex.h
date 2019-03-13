#ifndef __IMUTEX_H__
#define __IMUTEX_H__


class IMutex
{
	public:
		IMutex(){}
		virtual ~IMutex(){}

		virtual int Lock() = 0;
		virtual int Unlock() = 0;

	private:
};


#endif /* __IMUTEX_H__ */

