/*! Author: qwchen
 *! Date: 2016-9-20
 * ���еĳ�����������
 */

#ifndef queue_
#define queue_

using namespace std;

template <class T>
class queue {
public:
    virtual ~queue() {}
    virtual bool empty() const = 0;           // ������Ϊ��ʱ������true
    virtual int size() const = 0;             // ���ض�����Ԫ�صĸ���
    virtual T& front() = 0;                   // ����ͷԪ�ص�����
    virtual T& back() = 0;                    // ����βԪ�ص�����
    virtual void pop() = 0;                   // ɾ����Ԫ��
    virtual void push(const T &theElem) = 0;  // ��Ԫ��theElem�����β
};

#endif // !queue_
