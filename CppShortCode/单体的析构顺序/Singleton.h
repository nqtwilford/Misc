#ifndef SINGLETON_H_
#define SINGLETON_H_
template <class T>
class Singleton
{
public:
//	static T &Instance()	
//	{
//		static T t;
//		return t;
//	}
/*Ϊʲô��ʹ������ķ�ʽ��
**���ں����еľ�̬����ֻ���ں�����һ�ε��õ�ʱ�򴴽���
**�޷���֤���캯���еĳ�ʼ��������һʱ��ִ��
**����Ա��̬���������main����֮ǰ����
*/
	inline static T &Instance()
	{
		return t;
	}
private:
	static T t;
};

template <class T>
T Singleton<T>::t;
#endif
