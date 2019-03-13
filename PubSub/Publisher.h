#ifndef __PUBLISHER_H__
#define __PUBLISHER_H__

class IRouter;

class Publisher
{
	public:
		Publisher(){}
		virtual ~Publisher() = 0;	

    protected:
        IRouter *m_router;

	private:
		
};


#endif /* __PUBLISHER_H__ */
