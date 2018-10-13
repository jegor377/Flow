namespace flow {
	namespace log {
		void info(const std::string& msg) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void warn(const std::string& msg) {
			SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void error(const std::string& msg) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void debug(const std::string& msg) {
			SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		// special functions
		// logs warn when sdl reported error and flow fixed it somehow.
		void sdl_fix_warn(const std::string& error_source, const std::string& fix_way, const char* sdl_error_msg) {
			std::string msg = error_source+" reported error (\""+std::string(sdl_error_msg)+"\"). It has been fixed. Fix way: "+fix_way+".";
			warn(msg);
		}
	}
}