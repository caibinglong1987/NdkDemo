LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := HexLibrary

#1 编译多个.c文件 空格 \ 隔开
LOCAL_SRC_FILES := cbl.c \ test.c \ encryption.c

include $(BUILD_SHARED_LIBRARY)