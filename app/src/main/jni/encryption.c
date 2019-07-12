//
// Created by caibinglong on 2019/7/12.
//

#include "com_hx_hexintegrated_HexNative.h"

JNIEXPORT jstring JNICALL Java_com_hx_hexintegrated_HexNative_encryption
  (JNIEnv *env, jobject cla, jstring s){
        // char * st = (char *) *env->GetStringUTFChars( s, 0);
                      //printf("\n c-string:  %s", st);
                     //char * str = "hello wang wu!";
                   // jstring rtn = *env->NewStringUTF(st);

                     //return rtn;


                      char * st = (char *) (*env)->GetStringUTFChars(env, s, 0);
                      printf("\n c-string:  %s", st);

                     // char * str = "hello wang wu!";
                      jstring rtn;
                      rtn = (*env)->NewStringUTF(env, st);
                      return rtn;
  }

