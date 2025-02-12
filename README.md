## Let's discuss each part of the code that I created:

## 1. Header Files and Basic Definitions:
#include <various_headers>

>Header files include standard C++ functions, thread handling, memory management, dll
## 2. Data Type Definition:
#define __int8 char
#define __int16 short 
#define __int32 int
#define __int64 long long

>Defines data types for compatibility with the Game Guardian format


## 3. Variabel Global:
uintptr_t Mylib;
DWORD libMylibBase = 0;
DWORD libMylibAlloc = 0;
unsigned int libMylibSize = 0x48B49;

>This defines the base address and size of the target library to be hooked.

## 4. Example Hook Function:
void* hook_memcpy(char* dest, const char* src, size_t size) {
   This function hooks standard memcpy with additions security check and
      Checks the calling function
   > - Validate the buffer size
  > - Null pointer check
}
## 5. Example of a Hook with Return Value:
__int64 __fastcall sub_588C344(__int64 a1) {
    Simple hook that always returns the value 4
    return 4LL;
}
## 6. Hook use Original Function:
int (*osub_B32DE)(int a1, unsigned char *a2, size_t a3);
int hsub_B32DE(int a1, unsigned char *a2, size_t a3) {
    > Hook that allows calling the original function
   > Only process if buffer size is 0x16 or 0x32
}
## 7. Main Thread:
void * Qwan_thread(void *) {
> Thread waiting for the target library to load> Then apply the defined hooks

## 8. Constructor:
__attribute__((constructor)) void mainload() {
> This function is called when the library is loaded
> Create a thread to run the hooking process
}

## example how to run hook lib using method static constructor:

    const-string v0, "Mylib"
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)
