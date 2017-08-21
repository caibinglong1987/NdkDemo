//
// Created by HEC271 on 2017/8/21.
//
#include "com_hexing_ndk_Java.h"

JNIEXPORT jstring JNICALL Java_com_hexing_ndkDemo_Java2CJNI_printJni
        (JNIEnv *env, jobject instance){
    return (*env)->NewStringUTF(env,"hello test");
}