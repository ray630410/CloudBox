# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../libzip/ $(LOCAL_PATH)/../libpng/
LOCAL_STATIC_LIBRARIES := libzip libpng

#-Wno-psabi to remove warning about GCC 4.4 va_list warning
LOCAL_CFLAGS := -DANDROID_NDK -Wno-psabi -fno-exceptions -fno-rtti 

LOCAL_MODULE    := cloudbox-app
#LOCAL_MODULE    := libcloudbox
# main.cpp
# CloudBox Common Library
LOCAL_SRC_FILES := CBAction.cpp CBActionManager.cpp CBAnimation.cpp \
                   CBButton.cpp CBCmd.cpp CBDirector.cpp \
                   CBEventDispatcher.cpp CBGameApp.cpp CBImage.cpp \
                   CBView.cpp CBLabel.cpp CBLayout.cpp \
                   CBLibrary.cpp CBLogoScene.cpp CBNumber.cpp \
                   CBRenderBox.cpp CBScene.cpp CBSprite.cpp \
                   CBString.cpp CBTexture.cpp CBTexturePool.cpp \
                   CBTimerManager.cpp CBTouchManager.cpp \
                   _CBDefBuilder.cpp _CBBuilder.cpp CBGLImage.cpp \
                   CBTextCallback.cpp CBTextureCallback.cpp CBCallbackDispatcher.cpp \
                   CBOpenGL.cpp CBEnvironment.cpp CBRotateAction.cpp CBPropertyAction.cpp \
                   CBAudioEngine.cpp CBSwitch.cpp CBProperty.cpp \
                   ../CBAppEvent.cpp
# CloudBox extends function
# LOCAL_SRC_FILES += Extends/CBLotto.cpp Extends/CBLed.cpp Extends/CBMotion.cpp
LOCAL_SRC_FILES += Extends/CBMotion.cpp
# CloudBox Android Library
LOCAL_SRC_FILES += Android/CBBuilderAndroid.cpp Android/app-android.cpp Android/utils.cpp \
                   Android/CBJNI.cpp Android/CBTextManager.cpp Android/CBAndroidAudioManager.cpp \
                   Android/CBAndroidEffectManager.cpp 
# CloudBox Android Extends Library
# LOCAL_SRC_FILES += Android/CBMotionAndroid.cpp Android/CBLedAndroid.cpp
# CloudBox Game Component
LOCAL_SRC_FILES += Component/CBSlideBar.cpp Component/CBRingScrollImage.cpp \
# CloudBox Project
LOCAL_SRC_FILES += ../HelloScene.cpp
LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog -lz
#LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM -lz
#LOCAL_STATIC_LIBRARIES := android_native_app_glue libzip libpng

include $(BUILD_SHARED_LIBRARY)

#$(call import-module,android/native_app_glue)