#pragma once
template <class T>
class singleton {
private:
	static T* m_single;
public:
	// ������
	singleton(){/*empty*/ }
	// �Ҹ���
	virtual ~singleton(){ delete m_single; }
	// �ν��Ͻ� ����
	static T* getInstance(){ if (m_single == NULL) m_single = new T(); return m_single; }
};
template <class T> T* singleton<T>::m_single = 0;