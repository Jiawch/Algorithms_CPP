/*! Author: qwchen
 *! Date: 2016-9-13
 * ���Ա��ADT
 */

#ifndef linearList_
#define linearList_

#include <iostream>

using namespace std;

template <class T>
class linearList {
public:
    virtual ~linearList() {};
    virtual bool empty() const = 0;                              // ���ص����Ա�Ϊ��ʱ������true
    virtual int size() const = 0;                                // �������Ա�Ԫ�صĸ���
    virtual int capacity() const = 0;                            // �������Ա������
    virtual T& get(int theIndex) const = 0;                      // ��������ΪtheIndex��Ԫ��
    virtual int indexOf(const T &theElement) const = 0;          // ����Ԫ��theElement��һ�γ���ʱ������
    virtual void erase(int theIndex) = 0;                        // ɾ������ΪtheIndex��Ԫ��
    virtual void insert(int theIndex, const T &theElement) = 0;  // ��theElement�������Ա�������ΪtheIndex��λ����
    virtual void output(ostream &out) const = 0;                 // �����Ա���뵽�����
};

#endif

