#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <dlfcn.h>
#include <libgen.h>
#include <unwind.h>
#include <pthread.h>
#include <sstream>
#include <locale>
#include <fcntl.h>
#include <sys/mman.h> 
#include <stdio.h>
#include <stdlib.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Macros.h"
#include "Tools.h"
#define targetLibName OBFUSCATE("Mylib.so") //add the lib you want to hook
#include "Dobby/dobby.h"
using namespace std;
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define  _BYTE  uint8_t
#define _WORD  uint16_t
#define  _DWORD uint32_t    //format for game guardian
#define  _QWORD uint64_t
#define print
#define BYTE1
#define BYTE2
#define BYTE3
#define BYTE4
#define BYTE5
#define _ReadStatusReg
#define ARM64_SYSREG
#define LOG_TAG "hook_info"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define _BOOL8 uint64_t //declared 64bit
uintptr_t Mylib;
////
///declared variables 32bit 
/// edit lib base
DWORD libMylibBase = 0;
DWORD libMylibAlloc = 0;
////
char *Offset;
/////
//add your address and libSize
//don't use this address because only #exemple
unsigned int libMylibSize = 0x48B49;
////
pthread_t ptid;
#define SLEEP_TIME 1000LL / 60LL
// ADD HOOK HERE
///
//#exemple hook only
void* hook_memcpy(char* dest, const char* src, size_t size) {
    LOGI("memcpy hook called");
    uintptr_t ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
    Dl_info info;
    if (dladdr((void*)ret, &info) && info.dli_sname) {
        LOGI("Caller Function: %s", info.dli_sname);
        if (strcmp(info.dli_sname, "suspicious_function") == 0) {
            LOGI("Blocked memcpy call from suspicious_function");
            return 0;
        }
    }

    if (size == 0 || size > 0x100000) { // Maximum 1MB limit 
        LOGI("Blocked memcpy: Invalid size detected");
        return 0;
    }
    if (!dest || !src) {
        LOGI("Blocked memcpy: Null pointer detected");
        return 0;
    }
    return memcpy(dest, src, size);
}
///

///
///#exsample hook with value one way
__int64 __fastcall sub_588C344(__int64 a1)
{
  int v2; // w9
  __int64 result; // x0
  
  switch ( v2 )
  {
   result = 4LL;
   return result;
  }
  return result;
}
///#exsample hook with value two lane
int (*osub_B32DE)(int a1, unsigned char *a2, size_t a3);
int hsub_B32DE(int a1, unsigned char *a2, size_t a3) 
{
    if ( a3 == 0x16 || a3 == 0x32 ) 
    {
       return osub_B32DE(a1, a2, a3); 
    } 
    return 0;        
}
///
void * Qwan_thread(void *) {
    LOGI(OBFUSCATE("Qwan library loaded...."));
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));
    HOOK_LIB_NO_ORIG("libMylib.so", "0x588C344", sub_588C344);///hook one lane
    HOOK_LIB("libMylib.so", "0xB32DF", hsub_B32DE, osub_B32DE);///hook two lane
// add your hook Value 
    return NULL;
}


__attribute__((constructor)) void mainload() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, Qwan_thread, NULL);
    }
    
    /// don't forget to modify mylib and replace it with the lib you want to hook
