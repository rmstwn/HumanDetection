﻿// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  HumanDetection.cpp
 * @brief Human Detection component
 *
 */
 // </rtc-template>

#include "HumanDetection.h"

using namespace std;
using namespace cv;
using namespace cv::ml;

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const humandetection_spec[] =
#else
static const char* humandetection_spec[] =
#endif
{
  "implementation_id", "HumanDetection",
  "type_name",         "HumanDetection",
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
HumanDetection::HumanDetection(RTC::Manager* manager)
// <rtc-template block="initializer">
	: RTC::DataFlowComponentBase(manager),
	m_ImageInputIn("ImageInput", m_ImageInput),
	m_ImageOutputOut("ImageOutput", m_ImageOutput)
	// </rtc-template>
{
}

/*!
 * @brief destructor
 */
HumanDetection::~HumanDetection()
{
}



RTC::ReturnCode_t HumanDetection::onInitialize()
{
	// Registration: InPort/OutPort/Service
	// <rtc-template block="registration">
	// Set InPort buffers
	addInPort("ImageInput", m_ImageInputIn);

	// Set OutPort buffer
	addOutPort("ImageOutput", m_ImageOutputOut);


	// Set service provider to Ports

	// Set service consumers to Ports

	// Set CORBA Service Ports

	// </rtc-template>

	// <rtc-template block="bind_config">
	// </rtc-template>


	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t HumanDetection::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t HumanDetection::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetection::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t HumanDetection::onActivated(RTC::UniqueId /*ec_id*/)
{
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

	m_ImageOutput.width = 0;
	m_ImageOutput.height = 0;

	return RTC::RTC_OK;
}


RTC::ReturnCode_t HumanDetection::onDeactivated(RTC::UniqueId /*ec_id*/)
{
	if (!m_imageBuff.empty())
	{
		// free image memory
		m_imageBuff.release();
		m_imageDetectBuff.release();
	}

	return RTC::RTC_OK;
}


RTC::ReturnCode_t HumanDetection::onExecute(RTC::UniqueId /*ec_id*/)
{
	if (m_ImageInputIn.isNew()) {
		m_ImageInputIn.read();

		//img = current_frame.clone();
		//resize(img, img, Size(img.cols * 2, img.rows * 2));

		// InPort and OutPort screen size processing and image memory allocation
		if (m_ImageInput.width != m_ImageOutput.width || m_ImageInput.height != m_ImageOutput.height)
		{
			m_ImageOutput.width = m_ImageInput.width;
			m_ImageOutput.height = m_ImageInput.height;

			m_imageBuff.create(cv::Size(m_ImageInput.width, m_ImageInput.height), CV_8UC3);
			//m_imageDetectBuff.create(cv::Size(m_ImageInput.width, m_ImageInput.height), CV_8UC3);

		}

		memcpy(m_imageBuff.data, (void*)&(m_ImageInput.pixels[0]), m_ImageInput.pixels.length());
		//memcpy(m_imageDetectBuff.data, (void*)&(m_ImageInput.pixels[0]), m_ImageInput.pixels.length());

		vector<Rect> found;
		vector<double> weights;

		hog.detectMultiScale(m_imageBuff, found, weights);

		for (size_t i = 0; i < found.size(); i++)
		{
			Rect r = found[i];
			rectangle(m_imageBuff, found[i], cv::Scalar(0, 0, 255), 3);
			stringstream temp;
			temp << weights[i];
			putText(m_imageBuff, temp.str(), Point(found[i].x, found[i].y + 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
			track.push_back(Point(found[i].x + found[i].width / 2, found[i].y + found[i].height / 2));

			cout << "[X pos: " << found[i].x + found[i].width / 2 << "]" << "[Y pos: " << found[i].y + found[i].height / 2 << "]" << endl;
		}

		//for (size_t i = 1; i < track.size(); i++) {
		//	line(m_imageBuff, track[i - 1], track[i], Scalar(255, 255, 0), 2);
		//}

		int len = m_imageBuff.channels() * m_imageBuff.cols * m_imageBuff.rows;
		m_ImageOutput.pixels.length(len);

		memcpy((void*)&(m_ImageOutput.pixels[0]), m_imageBuff.data, len);

		m_ImageOutputOut.write();

	}

	return RTC::RTC_OK;
}


//RTC::ReturnCode_t HumanDetection::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetection::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetection::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetection::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t HumanDetection::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{

	void HumanDetectionInit(RTC::Manager* manager)
	{
		coil::Properties profile(humandetection_spec);
		manager->registerFactory(profile,
			RTC::Create<HumanDetection>,
			RTC::Delete<HumanDetection>);
	}

}
