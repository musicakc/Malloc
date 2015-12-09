#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void malloc(size_t size)
{
	/*
	sbrk used to increment heap size and return pointer to start 		region on heap
	*/
	void *p = sbrk(0);
	void *request = sbrk(size);
	if (request == (void*) -1)
		return NULL; //sbrk failed
	else
	{
		assert(p==request); //This is not thread safe
		return p;
	}
}
