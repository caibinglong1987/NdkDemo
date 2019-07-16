//
// Created by caibinglong on 2019/7/12.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <android/log.h>
#include "com_hx_hexintegrated_HexNative.h"

#define  LOG_TAG    "nativeprint"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

char* Encryption(char * str,int number);

JNIEXPORT jstring JNICALL Java_com_hx_hexintegrated_HexNative_encryption
  (JNIEnv *env, jobject cla, jstring s){

        char * str = (char *) (*env)->GetStringUTFChars(env, s, 0);

        char *dest = Encryption(str, 20);
        jstring rtn = (*env)->NewStringUTF(env, dest);

        return rtn;

  }


  JNIEXPORT jstring JNICALL Java_com_hx_hexintegrated_HexNative_encryptionByCusLen
    (JNIEnv *env, jclass cla, jstring s, jint jnum){

              char * str = (char *) (*env)->GetStringUTFChars(env, s, 0);
              int number = jnum;
              char *dest = Encryption(str, number);
              jstring rtn = (*env)->NewStringUTF(env, dest);
              return rtn;

    }

    char* Encryption(char * str,int number){

               char *change = (char *)malloc(0);
               int len = strlen(str);
               int sumlen = 0;

               for (int i = 0; i < len; i++)
               {

                   int n = sprintf(change + sumlen, "%d", str[i] - 30); //每个加30
                   sumlen += n;

               }
               LOGE("HexNative_encryption change=%s", change);

               int sublen = number;
               char *dest = (char *)calloc(sizeof(char), sublen);
               int index = 0;
               if (sumlen >= sublen)
               {
                    index = sumlen - sublen;
                    memcpy(dest, change + index, sumlen);
               }
               else
               {
                    index = sublen - sumlen;
                    memset(dest, '0', index);
                    memcpy(dest + index, change, sumlen);
               }

               LOGE("HexNative_encryption dest=%s,len=%ld", dest, strlen(dest));
               return dest;
    }

