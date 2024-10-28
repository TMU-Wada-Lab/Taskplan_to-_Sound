// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  TtoSTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "TtoSTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const ttos_spec[] =
#else
static const char* ttos_spec[] =
#endif
  {
    "implementation_id", "TtoSTest",
    "type_name",         "TtoSTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
TtoSTest::TtoSTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_finaltaskOut("task", m_finaltask),
    m_task_soundIn("sound", m_task_sound),
    m_sound_TFIn("sound_TF", m_sound_TF)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
TtoSTest::~TtoSTest()
{
}



RTC::ReturnCode_t TtoSTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("sound", m_task_soundIn);
  addInPort("sound_TF", m_sound_TFIn);
  
  // Set OutPort buffer
  addOutPort("task", m_finaltaskOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TtoSTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t TtoSTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoSTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t TtoSTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t TtoSTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t TtoSTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t TtoSTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoSTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoSTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoSTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoSTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool TtoSTest::runTest()
{
    return true;
}


extern "C"
{
 
  void TtoSTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(ttos_spec);
    manager->registerFactory(profile,
                             RTC::Create<TtoSTest>,
                             RTC::Delete<TtoSTest>);
  }
  
}
