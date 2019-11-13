
#pragma once
#include "IAgoraVideoSourceEngine.h"
#include "agora_video_source.h"
#include <memory>

namespace agora{
	namespace rtc{

		class CAgoraVideoSourceEventHandler : public IAgoraVideoSourceEventHandler
		{
			//advertise callback
			virtual void onVideoSourceJoinedChannel(agora::rtc::uid_t uid) override;
			virtual void onVideoSourceRequestNewToken() override;
			virtual void onVideoSourceLeaveChannel() override;
			virtual void onVideoSourceExit() override;
		};

		class AgoraVideoSourceEngine : public IAgoraVideoSourceEngine
		{
		public:
			AgoraVideoSourceEngine();
			~AgoraVideoSourceEngine();

			virtual void release() override;
			virtual bool initialize(const char* appid) override;
			virtual int setChannelProfile(CHANNEL_PROFILE_TYPE profile) override;
			virtual int setVideoProfile(VIDEO_PROFILE_TYPE profile, bool swapWidthAndHeight) override;
			virtual int enableWebSdkInteroperability(bool enable) override;
			virtual int startScreenCapture(HWND windowId, int capFreq, Rect rect, int bitrate) override;
			virtual int stopScreenCapture() override;
			virtual int setParameters(const char* parameters) override;
			virtual int setupLocalVideo(VideoCanvas canvas) override;
			virtual int startPreview() override;
			virtual int stopPreview() override;
			virtual bool enableDualStreamMode(bool enable) override;
			virtual int renewToken(const char* token) override;
			virtual int joinChannel(const char* token, const char* channelId, const char* info, uid_t uid) override;
			virtual int leaveChannel() override;
		private:
			std::unique_ptr<AgoraVideoSource> m_videoSourceSink;
			CAgoraVideoSourceEventHandler m_videoSourceEventHandler;

			bool m_initialized;
		};
	}
}
