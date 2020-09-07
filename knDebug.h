#ifndef __KNDEBUG_H__
#define __KNDEBUG_H__

#define KN_DEBUG 
#ifdef KN_DEBUG
#define DEBUG(format, ...) printf(__FILE__"|"__FUNCTION__"|%05d|"format"\n",__LINE__,##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

#endif