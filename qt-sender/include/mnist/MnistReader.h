#ifndef MNIST_READER_H
#define MNIST_READER_H

#include <iostream>

#include <QByteArray>
#include <QQuickImageProvider>

using namespace std;

class MnistReader : public QQuickImageProvider {

public:
    static const int MAGIC;

    MnistReader(string filePath);
    ~MnistReader();

    int imgSize();
    const char* imgBytes(int imgNum);
    QByteArray imgByteArray(int imgNum);
    void saveImg(int numImg);

    QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize);

private:
    int magic = 0;
    int imgCnt = 0;
    int rowCnt = 0;
    int colCnt = 0;
    char* data;

};


#endif // MNIST_READER_H
