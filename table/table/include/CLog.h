#ifndef _CLOG_H_
#define _CLOG_H_
#include <stdio.h>




#if defined (DEBUG_TO_FILE)
extern FILE*LogToFile;
#define DBUG_LOG(...)  fprintf(LogToFile,"[DBEG_INFO] %60s\t\t%15s()\t%d\t\t",__FILE__,__func__,__LINE__);\
						fprintf(LogToFile,__VA_ARGS__);\
						fflush(LogToFile);
#elif defined (DEBUG_PRINTF)


#define DBUG_LOG(...)  printf(__VA__ARGS__)


#else

#define DBUG_LOG(...)

#endif









#endif //_CLOG_H_
