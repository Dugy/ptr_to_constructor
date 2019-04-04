#include <memory>

template<typename P, typename T = P, typename... Args>
inline std::unique_ptr<P> construct(Args... args) {
	return std::make_unique<T>(args...);
}

template<typename P, typename T = P, typename... Args>
inline std::shared_ptr<P> constructShared(Args... args) {
	return std::make_shared<T>(args...);
}

template<typename P, typename T = P, typename... Args>
inline P* constructRaw(Args... args) {
	return new T(args...);
}
