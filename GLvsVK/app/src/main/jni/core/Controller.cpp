//
// Created by FKS143 on 2016/8/27.
//

#include "tools/Log.h"
#include "core/Controller.h"

#define LOG_TAG "fks_Controller"

Controller::Controller()
{
	LOGD("Controller created");
}

Controller::~Controller()
{
	LOGD("Controller freed");
}
