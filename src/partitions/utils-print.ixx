/* module partition interface unit declaration */
export module utils:print;


/* imports|exports */
import <format>;
export import <string_view>;
import <cstdio>;
// :print is exported -> people using printty::print() might need std::to_string() :thinking: */
export import <string>;


/* begin of the implementation details */
export namespace utty {

	template <typename... Args>
	void print(const std::string_view fmt_str, Args&& ... args) {
		auto fmt_args {std::make_format_args(args...)};
		std::string outstr {std::vformat(fmt_str, fmt_args)};
		fputs(outstr.c_str(), stdout);
	}
}
