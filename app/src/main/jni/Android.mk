LOCAL_PATH := $(call my-dir)
MAIN_LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libdobby
LOCAL_SRC_FILES := Dobby/libraries/$(TARGET_ARCH_ABI)/libdobby.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/Dobby/libraries/
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := Qwanwin

LOCAL_CFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w
LOCAL_CFLAGS += -fno-rtti -fno-exceptions -fpermissive
LOCAL_CPPFLAGS := -Wno-error=format-security -fvisibility=hidden -ffunction-sections -fdata-sections -w -Werror -s -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fms-extensions -fno-rtti -fno-exceptions -fpermissive
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all, -llog
LOCAL_ARM_MODE := arm

LOCAL_C_INCLUDES += $(MAIN_LOCAL_PATH)

LOCAL_SRC_FILES 		:=  main.cpp \
        tools.cpp \
        Substrate/hde64.c \
        Substrate/SubstrateDebug.cpp \
        Substrate/SubstrateHook.cpp \
        Substrate/SubstratePosixMemory.cpp \
        Substrate/And64InlineHook.cpp\
        KittyMemory/KittyMemory.cpp \
        KittyMemory/MemoryPatch.cpp \
        KittyMemory/MemoryBackup.cpp \
        KittyMemory/KittyUtils.cpp \
        
       
LOCAL_CPP_FEATURES                      := exceptions
LOCAL_LDLIBS                            := -llog -landroid -lEGL -lGLESv2 -lGLESv3 -lGLESv1_CM -lz
LOCAL_STATIC_LIBRARIES					:= libdobby
include $(BUILD_SHARED_LIBRARY)

