#pragma once
template <typename T>
class Observer
{
public:
	virtual ~Observer() = default;
	virtual void OnNotify(unsigned int, T*) = 0;
	virtual void OnDestroy() {}
};