//
// Created by FKS143 on 2016/8/27.
//

#include "com_example_fks143_glvsvk_opengles_mGLLib.h"

#include "GameManager.h"

JNIEXPORT void JNICALL Java_com_example_fks143_glvsvk_opengles_mGLLib_resize
(JNIEnv * env, jclass cls, jint width, jint height)
{
	GameManager::getInstance()->resize(width, height);
}

JNIEXPORT void JNICALL Java_com_example_fks143_glvsvk_opengles_mGLLib_step
(JNIEnv * env, jclass cls)
{
	GameManager::getInstance()->step();
}

JNIEXPORT void JNICALL Java_com_example_fks143_glvsvk_opengles_mGLLib_init
(JNIEnv * env, jclass cls)
{
	GameManager::getInstance()->init();
}

