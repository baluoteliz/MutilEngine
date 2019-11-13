// agora_videosource_sdk.cpp : Defines the exported functions for the DLL application.
//
#include "agora_videosource_sdk.h"

namespace agora{
	namespace rtc{
		//CAgoraVideoSourceEventHandler
		void CAgoraVideoSourceEventHandler::onVideoSourceJoinedChannel(agora::rtc::uid_t uid)
		{}

		void CAgoraVideoSourceEventHandler::onVideoSourceRequestNewToken()
		{}

		void CAgoraVideoSourceEventHandler::onVideoSourceLeaveChannel()
		{}

		void CAgoraVideoSourceEventHandler::onVideoSourceExit()
		{}

		//AgoraVideoSourceEngine
		AgoraVideoSourceEngine::AgoraVideoSourceEngine()
		{
			m_videoSourceSink.reset(createVideoSource());
		}

		AgoraVideoSourceEngine::~AgoraVideoSourceEngine()
		{

		}

		bool AgoraVideoSourceEngine::initialize(const char* appid)
		{
			return m_videoSourceSink->initialize(&m_videoSourceEventHandler, appid);
		}

		int AgoraVideoSourceEngine::setChannelProfile(CHANNEL_PROFILE_TYPE profile)
		{
			return m_videoSourceSink->setVideoSourceChannelProfile(profile);
		}

		int AgoraVideoSourceEngine::setVideoProfile(VIDEO_PROFILE_TYPE profile, bool swapWidthAndHeight)
		{
			return m_videoSourceSink->setVideoSourceVideoProfile(profile, swapWidthAndHeight);
		}

		int AgoraVideoSourceEngine::enableWebSdkInteroperability(bool enable)
		{
			return m_videoSourceSink->enableWebSdkInteroperability(enable);
		}

		int AgoraVideoSourceEngine::startScreenCapture(HWND windowId, int capFreq, Rect rect, int bitrate)
		{
			return m_videoSourceSink->captureScreen(windowId, capFreq, &rect, bitrate);
		}

		int AgoraVideoSourceEngine::stopScreenCapture()
		{
			return m_videoSourceSink->stopCaptureScreen();
		}

		int AgoraVideoSourceEngine::setParameters(const char* parameters)
		{
			return m_videoSourceSink->setParameters(parameters);
		}

		int AgoraVideoSourceEngine::startPreview()
		{
			return m_videoSourceSink->startPreview();
		}

		int AgoraVideoSourceEngine::setupLocalVideo(VideoCanvas canvas)
		{
			return m_videoSourceSink->setupLocalVideo((HWND)canvas.view, (RENDER_MODE_TYPE)canvas.renderMode);
		}

		int AgoraVideoSourceEngine::stopPreview() 
		{
			return m_videoSourceSink->stopPreview();
		}

		bool AgoraVideoSourceEngine::enableDualStreamMode(bool enable)
		{
			return node_ok == m_videoSourceSink->enableDualStreamMode(enable);
		}

		int AgoraVideoSourceEngine::renewToken(const char* token)
		{
			return m_videoSourceSink->renewVideoSourceToken(token);
		}
		
		int AgoraVideoSourceEngine::joinChannel(const char* token, const char* channelId, const char* info, uid_t uid)
		{
			return m_videoSourceSink->join(token, channelId, info, uid);
		}

		int AgoraVideoSourceEngine::leaveChannel()
		{
			return m_videoSourceSink->leave();
		}

		void AgoraVideoSourceEngine::release()
		{
			m_videoSourceSink->release();
		}
	}
}

AGORA_API agora::rtc::IAgoraVideoSourceEngine* AGORA_CALL createAgoraVideoSourceEngine()
{
	return new agora::rtc::AgoraVideoSourceEngine();
}

