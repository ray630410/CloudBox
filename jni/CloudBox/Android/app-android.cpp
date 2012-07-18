/*
 *  app-android.cpp
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud Hsu on 2012/1/17.
 *  Copyright 2012 Cloud Hsu. All rights reserved.
 *
 */

#include "app-android.h"
#include <GLES/gl.h>
#include "def.h"
#include "utils.h"
#include <time.h>
#include "../CloudBox.h"
#include "../CBLogoScene.h"

zip* APKArchive;
jobject g_textmgr;
JNIEnv *g_env;

//int to fixed point
#define iX(x) (x<<16)
//float ti fixed point
#define fX(x) ((int)(x * (1  << 16)))

//int square[12] = {
//    fX(-0.5), fX(-0.5), 0,
//    fX(0.5), fX(-0.5), 0,
//    fX(-0.5), fX(0.5), 0,
//    fX(0.5), fX(0.5), 0
//};
//
//int texCoords[8] = {
//    0, fX(1),
//    fX(1), fX(1),
//    0,0,
//    fX(1),0
//};
//
//GLuint texture;

static double _getTime(void)
{
    struct timeval  now;

    gettimeofday(&now, NULL);
    double sec = now.tv_sec;
    double usec = (double)now.tv_usec/1000/1000;
    return (double)(sec + usec);
}

static void printGLString(const char *name, GLenum s)
{
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}

static void checkGlError(const char* op)
{
    for (GLint error = glGetError(); error; error = glGetError()) {
        LOGE("after %s() glError (0x%x)\n", op, error);
    }
}

static void loadAPK (const char* apkPath)
{
  LOGI("Loading APK %s", apkPath);
  APKArchive = zip_open(apkPath, 0, NULL);
  if (APKArchive == NULL) {
    LOGE("Error loading APK");
    return;
  }

  //Just for debug, print APK contents
  int numFiles = zip_get_num_files(APKArchive);
  for (int i=0; i<numFiles; i++) {
    const char* name = zip_get_name(APKArchive, i, 0);
    if (name == NULL) {
      LOGE("Error reading zip file name at index %i : %s", zip_strerror(APKArchive));
      return;
    }
    LOGI("File %i : %s\n", i, name);
  }
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInit
  (JNIEnv * env, jclass cls, jstring apkPath)
{
	//LOGI("nativeInit");
	const char* str;
    jboolean isCopy;
    str = env->GetStringUTFChars(apkPath, &isCopy);
    loadAPK(str);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeInitGL
  (JNIEnv * env, jclass cls)
{
	LOGI("nativeInitGL");
    SGameApp.initialTimer(_getTime());
    SGameApp.initialize();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeSetsize
  (JNIEnv *, jclass, jint w, jint h) {
    //LOGI("nativeSetsize (%i,%i)", w, h);
    if(h == 0)
      h = 1;
    SGameApp.setScreen(w, h);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeResume
  (JNIEnv *, jclass)
{
	//LOGE("Resume");
	SGameApp.reloadTexture();
	SGameApp.applicationWillEnterForeground();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeRender
  (JNIEnv *, jclass) {
	SGameApp.mainLoop(_getTime());
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_nativePause
  (JNIEnv *, jclass)
{
	//LOGE("Pause");
	SGameApp.applicationDidEnterBackground();
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchBegan
  (JNIEnv *, jclass, jfloat x, jfloat y)
{
	SGameApp.touchBegan(x,y);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchMoved
  (JNIEnv *, jclass, jfloat x, jfloat y)
{
	SGameApp.touchMoved(x,y);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudGLSurface_touchEnded
  (JNIEnv *, jclass, jfloat x, jfloat y)
{
	SGameApp.touchEnded(x,y);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CBMotion_onSensorChanged
  (JNIEnv *, jclass, jfloat x, jfloat y, jfloat z)
{
	LOGI("x:%f y:%f z:%f\n", x, y, z);
	SGameApp.onSersorChanged(x, y, z);
}

JNIEXPORT void JNICALL Java_com_clouddevelop_cloudbox_CloudRenderer_nativeTextInit
(JNIEnv* env, jclass cls, jobject textManager)
{
	g_env = env;
	g_textmgr = textManager;
	jclass business_class = env->GetObjectClass(g_textmgr);
	AndroidLog("initial textmanager success!");
}
