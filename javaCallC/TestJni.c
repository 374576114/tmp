#include <stdio.h>
#include "jni_TestJni.h"

JNIEXPORT void JNICALL _Java_jni_TestJni_display(JNIEnv *env,
			jobject arg, jstring inString){
	const jbyte* str;
	str = (*env)->GetStringUTFChars(env, inString, JNI_FALSE);
	printf("hello %s\n", str);

	(* env)->ReleaseStringUTFChars(env, inString, (const char*)str);

	return ;
}

