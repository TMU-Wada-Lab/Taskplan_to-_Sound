// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  TtoS.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "TtoS.h"
int c_state = -1;
// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const ttos_spec[] =
#else
static const char* ttos_spec[] =
#endif
  {
    "implementation_id", "TtoS",
    "type_name",         "TtoS",
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
TtoS::TtoS(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_finaltaskIn("task", m_finaltask),
    m_task_soundOut("sound", m_task_sound),
    m_sound_TFOut("sound_TF", m_sound_TF)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
TtoS::~TtoS()
{
}



RTC::ReturnCode_t TtoS::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("task", m_finaltaskIn);
  
  // Set OutPort buffer
  addOutPort("sound", m_task_soundOut);
  addOutPort("sound_TF", m_sound_TFOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TtoS::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t TtoS::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoS::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t TtoS::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t TtoS::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t TtoS::onExecute(RTC::UniqueId /*ec_id*/)
{
    if (m_finaltaskIn.isNew()) {
        m_finaltaskIn.read();
        c_state = m_finaltask.data;
        c_state += 10;
        m_task_sound.data.length(1);
        m_task_sound.data[0] = c_state;
        m_task_soundOut.write();
    }
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t TtoS::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoS::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoS::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoS::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t TtoS::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void TtoSInit(RTC::Manager* manager)
  {
    coil::Properties profile(ttos_spec);
    manager->registerFactory(profile,
                             RTC::Create<TtoS>,
                             RTC::Delete<TtoS>);
  }
  
}
