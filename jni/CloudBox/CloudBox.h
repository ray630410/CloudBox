/*
 *  CloudBox.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/25.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef CBVERSION
#define CBVERSION "0.99.39"
#endif

/*
 * Cloud Box is cross platform framework.
 * Copyright by Cloud Hsu
 * version 0.99.39
 * 2012/09/09 v0.99.39
 * 1. Fix bug for RingScroll Image.
 * 2. Disable Sleep for iOS and Android.
 * 3. SoundPool has some bug, record it.
 * 2012/09/09 v0.99.39
 * 1. Add mute function for audio engine.
 * 2012/08/21 v0.99.38
 * 1. Implement new CBSlideBar for 4 direction(up/down/left/right).
 * 2012/07/30 v0.99.37
 * 1. Implement and test android sound engine.
 * 2012/07/28 v0.99.36
 * 1. Fix warring.
 * 2. Implement CBEffectManager.java.
 * 2012/07/10 v0.99.35
 * 1. Add new class in java(not implement).
 * 2. Add audio engine funtion in android.
 * 3. Update CBLed.java to handler.
 * 2012/07/10 v0.99.35
 * 1. Add CBAudioEngine for sound and music engine.
 * 2. Implement sound and music engine on iOS.
 * 2012/06/14 v0.99.34
 * 1. Add new CBMotion.java, CBMotionAndroid.h/cpp for Accelerometer.
 * 2. Add pre-compile const CBMotionEnable in CBMotion.h
 * 2012/06/10 v0.99.33
 * 1. Fix bug in onSwitch event in CBSwitch.
 * 2. Trigger onClick on touchEnded.
 * 2012/05/26 v0.99.32
 * 1. Remove ActionLifeType in Action Function.
 * 2. Add new extends function CBMotion.
 * 3. Refactor CBRingScrollImage.
 * 2012/05/12 v0.99.31
 * 1. Fix bug in CBString text color function in setColor.
 * 2. Add new function checkCollision in CBView.
 * 2012/05/04 v0.99.30
 * 1. Fix bug in CBLayout for orientation.
 * 2. Refactor interface in CBAnimation.
 * 3. Fix compile warring in xcode4.2.
 * 2012/05/01 v0.99.29
 * 1. Fix bug in CBRingScrollImage.
 * 2. Test done in Android/iOS for CBRingScrollImage.
 * 3. The image max width/height in iOS is 1024.
 * 2012/04/19 v0.99.28
 * 1. Add new component CBRingScrollImage.
 * 2. Fix bug that is an error when change orientation(EAGLView.mm).
 * 2012/04/15 v0.99.27
 * 1. Implement CBSwitch Component.
 * 2. Add CBDefaultOption.
 * 3. Add event to CBSlideBar.
 * 2012/04/10 v0.99.26
 * 1. Add new component CBSwitch(not yet to test).
 * 2. Test CBSlideBar in Android device(Samsung Galaxy S2).
 * 3. Test CBSlideBar in iPhone4.
 * 2012/04/08 v0.99.25
 * 1. Add new action: CBPropertyAction
 * 2. Add CBSlideBar
 * 2012/04/07 v0.99.24
 * 1. Comfirm the action function.
 * 2. Add CBRotateAction.
 * 2012/04/05 v0.99.23
 * 1. Test done with new design in Android.
 * 2. Fix much bugs in Android.
 * 2012/03/31 v0.99.22
 * 1. Refactor all view object.
 * 2. Find new solution to solve the cross-thread issue.
 * version 0.99.21
 * 2012/02/19 v0.99.21
 * 1. Implement run once callback function.
 * 2012/02/18 v0.99.20
 * 1. Refactor CBString
 * 2012/01/27 v0.99.19
 * 1. Change access level to private for CBDirector.runWithScene
 * 2. Remove queueEvent in CloudGLSurface.java
 * 3. Add CloudADApp.java for Android template.
 * 4. Fix bug for onPause and onResume event in Android.
 * 5. Update eclipse project to use Android SDK 4.0.3.
 * 2012/01/26 v0.99.18
 * 1. Refactor CBRenderBox
 * 2. Add CloudBoxEx.h to handle extended function
 * 3. Fix bug for CBBuilderIOS.BuilderString
 * 2012/01/26 v0.99.17
 * 1. Refactor the texture pool to manage all texture.
 * 2. All CBImage just use texture from pool.
 * 3. The bug of android scene change in Lotto is the pool error.
 * 2012/01/25 v0.99.16
 * 1. Android must use Runable to implement touch.
 * 2012/01/24 v0.99.15
 * 1. Add default function for CBImage and remove builder function.
 * 2. Add default function for CBLabel and remove builder function.
 * 3. Add default function for CBButton and remove builder function.
 * 4. Fix position bug for CBLogoScene,CBLabel,CBButton.
 * 2012/01/24 v0.99.14
 * 1. Refactor CBLabel.
 * 2. Refactor CBButton.
 * 3. Refactor CBLotto.
 * 4. Refactor CBImage.
 * 2012/01/24 v0.99.13
 * 1. Add new logo and new icon to cloudbox.
 * 2. Fix bug for extend function as CBLotto.
 * 3. Add icon and description for Xcode template.
 * 2012/01/17 v0.99.12
 * 1. Add background and foreground event.
 * 2012/01/17 v0.99.11
 * 1. Add reload text texture for android
 * 2012/01/16 v0.99.10
 * 1. Fix bug in CBRenderBox.cpp
 * 2012/01/16 v0.99.9
 * 1. Because Android need to reload texture when onResume, so develop all function.
 * 2. Test done C++ call CloudLed.java
 * 2012/01/15 v0.99.8
 * 1. Add auto layout function
 * 2. Modify some initial code for android
 * 2012/01/14 v0.99.7
 * 1. Add new touch check for retina display(CBItem::isTrigger)
 * 2. Add isRetina to CBEnvironment
 * 2012/01/14 v0.99.6
 * 1. Add CBObject class
 * 2. Add CBEnvironment class
 * 2012/01/05 v0.99.5
 * 1. Add new const SKIP_LOGO in CBCore.h
 * 2011/10/30 v0.99.4
 * 1. Add auto release in scene.
 * 2. Improve item model and texture pool.
 * 2011/09/04 v0.99.3
 * 1. Add text for Android
 */

#include "CBLibrary.h"
#include "CBTexture.h"
#include "CBView.h"
#include "CBImage.h"
#include "CBString.h"
#include "CBScene.h"
#include "CBAnimation.h"
#include "CBSprite.h"
#include "CBLabel.h"
#include "CBButton.h"
#include "CBNumber.h"
#include "CBSwitch.h"
#include "CBDevice.h"
#include "CBEnvironment.h"
#include "CBDirector.h"
#include "CBTextureCallback.h"
#include "CBTextCallback.h"
#include "CBAction.h"
#include "CBRotateAction.h"
#include "CBGameApp.h"
#include "CBAudioEngine.h"

// CloudBox game component
#ifdef __CBIOS__
#include "CBSlideBar.h"
#include "CBRingScrollImage.h"
#else
#include "Component/CBSlideBar.h"
#include "Component/CBDefaultOption.h"
#include "Component/CBRingScrollImage.h"
#endif


#ifdef __CBIOS__
// not yet to implement cross platform sound engine
#endif