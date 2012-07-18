/*
 *  app-android.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */
#include <jni.h>

#ifndef _Included_com_clouddevelop_cloudbox_CloudRenderer
#define _Included_com_clouddevelop_cloudbox_CloudRenderer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_clouddevelop_cloudbox_CloudRenderer_nativeInit
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInit
  (JNIEnv *, jclass, jstring);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInitGL
  (JNIEnv *, jclass);

/*
 * Class:     com_clouddevelop_cloudbox_CloudRenderer_nativeResize
 * Method:    nativeResize
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeSetsize
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_clouddevelop_cloudbox_CloudRenderer_nativeRender
 * Method:    nativeRender
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeRender
  (JNIEnv *, jclass);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeResume
  (JNIEnv *, jclass);

/*
 * Class:     com_clouddevelop_cloudbox_CloudGLSurface_nativePause
 * Method:    nativePause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_nativePause
  (JNIEnv *, jclass);

// Event for touch
JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchBegan
  (JNIEnv *, jclass, jfloat x, jfloat y);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchMoved
  (JNIEnv *, jclass, jfloat x, jfloat y);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchEnded
  (JNIEnv *, jclass, jfloat x, jfloat y);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBMotion_onSensorChanged
  (JNIEnv *, jclass, jfloat x, jfloat y, jfloat z);

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeTextInit
(JNIEnv* env, jclass cls, jobject textManager);

#ifdef __cplusplus
}
#endif
#endif
