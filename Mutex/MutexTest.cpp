#include "Mutex.h"
#include "Locker.h"

#include <iostream>

using namespace std;


void* foo(void* _mutex)
{
	Mutex *mut = (Mutex*)_mutex;

	cout << "1" << endl;
	mut->Lock();
	cout << "2" << endl;
	mut->Unlock();
	cout << "3" << endl;
	mut->Unlock();
	cout << "4" << endl;
	mut->Lock();
	cout << "5" << endl;
	mut->Lock();
	cout << "6" << endl;
	return 0;
}

void* foo2(void* _mutex)
{
	cout << "1" << endl;
	Locker lock((pthread_mutex_t*)_mutex);
	cout << "2" << endl;
	lock.~Locker();
	Locker lock2((pthread_mutex_t*)_mutex);
	cout << "3" << endl;
	return 0;
}



int main ()
{
//	Mutex mut;

	pthread_t tid[2];
	pthread_mutex_t mut;
	pthread_mutex_init(&mut, 0);
	
	pthread_create(&(tid[0]), 0, foo2, &mut);
	pthread_create(&(tid[1]), 0, foo2, &mut);

	pthread_join(tid[0], 0);
	pthread_join(tid[1], 0);
	
	return 0;
}



