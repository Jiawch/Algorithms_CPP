/*! Author: qwchen
 *! Date: 2016-9-22
 * �ö���ʵ�ֵ��г�����������
 * ��������������һ������������г�"β[581742963]ͷ"�������к�k��������(������ֻ���Ƚ��ȳ�)��
 *           ������Щ�������Գ�����������У�ʹ���г���������ʱ����˳��Ϊ"β[987654321]ͷ"
 *           ���ƣ�1. ������Դ�������ǰ���ƶ���һ���������ĺ�˻������ĺ��
 *                 2. ������Դ�һ����������ǰ���Ƶ�������ĺ��
 * ˼·����ÿһ������������Ϊһ�����У�����һ����������С����ı��smallestCar�������ڹ���ı��itsTrack����¼��һ��Ҫ�뵽������ĳ����nextCarToOutput
 *       ����������ÿһ�ڳ��᣺
 *           ������պõ�����һ��Ҫ�뵽������ĳ���ţ�ֱ�ӽ���������ƶ����������
 *               ��ʱ�����ϼ�黺��������С�ĳ�����Ƿ������һ��Ҫ�뵽������ĳ���ţ����������뵽�����
 *           ���򣬽����ƶ�����������
 *               ��������ѡȡԭ���ǣ����Ϊu�ĳ���Ҫ��Ĺ��Ӧ���ǳ�����С��u�������
 */

#include <iostream>
#include <queue>

using namespace std;

// ȫ�ֱ���
queue<int> *track;    // ����������
int numberOfCars;     // ��������Ŀ
int numberOfTracks;   // ����������Ŀ
int smallestCar;      // �ڻ������б����С�ĳ���
int itsTrack;         // ͣ������С����Ļ�����

void outputFromHoldingTrack();
bool putInHoldingTrack(int inputCar);

/*
 * �г�����������
 * Parament��
 *     inputOrder: �����ĳ���
 *     theNumberOfCars: ��������
 *     theNumberOfTracks: ������������
 */
bool railroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks) {
    numberOfCars = theNumberOfCars;
    numberOfTracks = theNumberOfTracks;
    track = new queue<int>[numberOfTracks];
    int nextCar = 1;  // ��¼��һ��Ҫ�뵽������ĳ����
    smallestCar = numberOfCars + 1;
    itsTrack = numberOfTracks + 1;
    for (int i = 0; i < numberOfCars; i++) {
        if (inputOrder[i] == nextCar) { // 1. ֱ�Ӵ������Ƶ������
            cout << "Move car " << inputOrder[i] << " from input track to output stack" << endl;
            nextCar++;
            while (smallestCar == nextCar) { // 2. �ӻ������Ƶ������
                outputFromHoldingTrack();
                nextCar++;
            }
        }
        else {    // 3. �������ƶ�������
            if (!putInHoldingTrack(inputOrder[i])) {
                return false;
            }
        }
    }
    return true;
}

// 2. �ӻ������Ƶ������
void outputFromHoldingTrack() {
    // �ӻ������Ƶ������
    cout << "Move car " << smallestCar << " from holding track " << itsTrack << " to output stack" << endl;
    track[itsTrack].pop();
    // ����ѡ�ٶ�β��С�ĳ�����Ӻ�
    smallestCar = numberOfCars + 2;
    itsTrack = numberOfTracks + 1;
    for (int i = 0; i < numberOfTracks; i++) {
        if (!track[i].empty() && track[i].front() < smallestCar) {
            smallestCar = track[i].front();
            itsTrack = i;
        }
    }
}

// 3. �������ƶ�������
bool putInHoldingTrack(int inputCar) {
    int bestTrack = numberOfTracks;
    int bestTop = 0;
    for (int i = 0; i < numberOfTracks; i++) {
        if (!track[i].empty()) {
            int lastCar = track[i].back();
            if (lastCar > bestTop && lastCar < inputCar) {
                bestTop = lastCar;
                bestTrack = i;
            }
        }
        else {
            if (bestTop == 0)
                bestTrack = i;
        }
    }
    if (bestTrack == numberOfTracks)
        return false;
    track[bestTrack].push(inputCar);
    cout << "Move Car " << inputCar << " from input track to holding track " << bestTrack << endl;
    if (inputCar < smallestCar) {
        smallestCar = inputCar;
        itsTrack = bestTrack;
    }
    return true;
}


void testRailroad() {
    int inputOrder[9] = {3, 6, 9, 2, 4, 7, 1, 8, 5};
    if(railroad(inputOrder, 9, 2))
        cout << "[Successd] All cars have moved from input track to output stack" << endl;
    else
        cout << "[Failed] No enough track!!!" << endl;
}


int main(){
    testRailroad();
    return 0;
}