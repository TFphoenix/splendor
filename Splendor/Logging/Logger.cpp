#include "Logger.h"
#include <chrono>

Logger::Logger(std::ostream& out, Level minLogLevel) : m_out(out), m_minLogLevel(minLogLevel) {}

void Logger::Log(const std::string& message, Level level) const
{
	if (level < m_minLogLevel) return;
	switch (level)
	{
	case Logger::Level::Debug:
		m_out << "[Debug]";
		break;
	case Logger::Level::Info:
		m_out << "[Info]";
		break;
	case Logger::Level::Warning:
		m_out << "[Warning]";
		break;
	case Logger::Level::Error:
		m_out << "[Error]";
		break;
	default:
		break;
	}
	const auto now = std::chrono::system_clock::now().time_since_epoch();
	const auto h = std::chrono::duration_cast<std::chrono::hours>(now);
	const auto m = std::chrono::duration_cast<std::chrono::minutes>(now);
	const auto s = std::chrono::duration_cast<std::chrono::seconds>(now);
	m_out << "[" << h.count() % 60 << ":" << m.count() % 60 << ":" << s.count() % 60 << "]";
	m_out << message << std::endl;
}
