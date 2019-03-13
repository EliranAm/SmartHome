#ifndef __ISEMAPHORE_H__
#define __ISEMAPHORE_H__



class ISemaphore
{
	public:
		ISemaphore(){}
		virtual ~ISemaphore(){}

		virtual int Post() = 0;
		virtual int Wait() = 0;

	private:
		
};



#endif /* __ISEMAPHORE_H__ */
