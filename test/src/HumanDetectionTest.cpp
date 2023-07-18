// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  HumanDetectionTest.cpp
 * @brief Human Detection component (test code)
 *
 */
// </rtc-template>

#include "HumanDetectionTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const humandetection_spec[] =
#else
static const char* humandetection_spec[] =
#endif
  {
    "implementation_id", "HumanDetectionTest",
    "type_name",         "HumanDetectionTest",
    "description",       "Human Detection component",
    "version",           "1.0.0",
    "vendor",            "Hase",
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
HumanDetectionTest::HumanDetectionTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_ImageInputOut("ImageInput", m_ImageInput),
    m_ImageOutputIn("ImageOutput", m_ImageOutput)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
HumanDetectionTest::~HumanDetectionTest()
{
}



RTC::ReturnCode_t HumanDetectionTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("ImageOutput", m_ImageOutputIn);
  
  // Set OutPort buffer
  addOutPort("ImageInput", m_ImageInputOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HumanDetectionTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t HumanDetectionTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetectionTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t HumanDetectionTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t HumanDetectionTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t HumanDetectionTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t HumanDetectionTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetectionTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetectionTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetectionTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetectionTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool HumanDetectionTest::runTest()
{
    return true;
}


extern "C"
{
 
  void HumanDetectionTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(humandetection_spec);
    manager->registerFactory(profile,
                             RTC::Create<HumanDetectionTest>,
                             RTC::Delete<HumanDetectionTest>);
  }
  
}
