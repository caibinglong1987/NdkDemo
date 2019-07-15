//
// Created by caibinglong on 2019/7/12.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "com_hx_hexintegrated_HexNative.h"

JNIEXPORT jstring JNICALL Java_com_hx_hexintegrated_HexNative_encryption
  (JNIEnv *env, jobject cla, jstring s){

        char * str = (char *) (*env)->GetStringUTFChars(env, s, 0);

        //jstring rtn;
        // rtn = (*env)->NewStringUTF(env, st);
        //return rtn;
        // char *str3 = new char{};
        // char *str = "Nb12345789";
                char *change = (char *)malloc(0);
                int len = strlen(str);
                int sumlen = 0;

                for (int i = 0; i < len; i++)
                {
                    int n = sprintf(change + sumlen, "%d", str[i] + 30); //每个加30
                    sumlen += n;
                }
                printf("change=%s\n", change);

                int sublen = 20;
                char *dest = (char *)malloc(0);
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

                printf("dest=%s,len=%ld", dest, strlen(dest));

                jstring rtn = (*env)->NewStringUTF(env, dest);
                return rtn;

  }


  JNIEXPORT jstring JNICALL Java_com_hx_hexintegrated_HexNative_encryptionByCusLen
    (JNIEnv *env, jclass cla, jstring s, jint jnum){

               char * str = (char *) (*env)->GetStringUTFChars(env, s, 0);

               char *change = (char *)malloc(0);
               int len = strlen(str);
               int sumlen = 0;

               for (int i = 0; i < len; i++)
               {
                   int n = sprintf(change + sumlen, "%d", str[i] + 30); //每个加30
                   sumlen += n;
               }
               printf("change=%s\n", change);

               int sublen = jnum;
               char *dest = (char *)malloc(0);
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

               printf("dest=%s,len=%ld", dest, strlen(dest));

               jstring rtn = (*env)->NewStringUTF(env, dest);
               return rtn;

    }

