/*! Author: qwchen
 *! Date: 2016-9-28
 * �ѵĳ�����������
 */

#ifndef heap_
#define heap_

using namespace std;

template <class T>
class heap {
public:
    virtual ~heap() {}
    virtual bool empty() const = 0;              // ����true���ҽ�����Ϊ��
    virtual int size() const = 0;                // ���ضѵ�Ԫ�ظ���
    virtual const T& top() = 0;                  // ���ضѶ�Ԫ�ص�����
    virtual void pop() = 0;                      // ɾ���Ѷ�Ԫ��
    virtual void push(const T& theElement) = 0;  // ����в���Ԫ��
};

#endif // !heap_

