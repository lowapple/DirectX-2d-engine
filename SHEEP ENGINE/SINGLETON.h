#pragma once
template <class T>
class singleton {
private:
	static T* m_single;
public:
	// 생성자
	singleton(){/*empty*/ }
	// 소멸자
	virtual ~singleton(){ delete m_single; }
	// 인스턴스 관리
	static T* getInstance(){ if (m_single == NULL) m_single = new T(); return m_single; }
};
template <class T> T* singleton<T>::m_single = 0;