#pragma once

#include <memory>
class GLFWwindow;

namespace leap
{
	namespace audio
	{
		class IAudioSystem;
		class DefaultAudioSystem;
	}
	namespace graphics
	{
		class IRenderer;
		class DefaultRenderer;
	}

	class ServiceLocator final
	{
	public:
		static audio::IAudioSystem& GetAudio();
		static graphics::IRenderer& GetRenderer();
		template <typename T>
		static void RegisterAudioSystem();
		template <typename T>
		static void RegisterRenderer(GLFWwindow* pWindow);
	private:
		static std::unique_ptr<audio::IAudioSystem> m_pAudioSystem;
		static std::unique_ptr<audio::DefaultAudioSystem> m_pDefaultAudioSystem;
		static std::unique_ptr<graphics::IRenderer> m_pRenderer;
		static std::unique_ptr<graphics::DefaultRenderer> m_pDefaultRenderer;
	};

	template<typename T>
	inline void ServiceLocator::RegisterAudioSystem()
	{
		static_assert(std::is_base_of<audio::IAudioSystem, T>::value);
		m_pAudioSystem = std::make_unique<T>();
	}

	template<typename T>
	inline void ServiceLocator::RegisterRenderer(GLFWwindow* pWindow)
	{
		static_assert(std::is_base_of<graphics::IRenderer, T>::value);
		m_pRenderer = std::make_unique<T>(pWindow);
	}
}