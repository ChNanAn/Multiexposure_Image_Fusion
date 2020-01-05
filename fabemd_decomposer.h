#ifndef FABEMD_DECOMPOSER_H
#define FABEMD_DECOMPOSER_H

#include <QImage>
#include "matrix_2d.h"

class fabemd_decomposer
{
public:
    fabemd_decomposer();

    void FuseImages();
    void SetInputImages(QVector<QImage *> *images);
    void SetResX(int value);
    void SetResY(int value);

    QImage *GetFusedImage();

private:
    QVector<QImage*> *inputImages;

    QVector<Matrix2D<float> *> y_channels;
    QVector<Matrix2D<float> *> cb_channels;
    QVector<Matrix2D<float> *> cr_channels;

    QVector<QVector<Matrix2D<float> *>> imfs;

    void RGBToYCbCr();
    void DecomposeY();
    int GetExtremaDistance(Matrix2D<float> *extrema, QVector<float> *extrema_distance);
    int ROWS, COLUMNS;

    void FuseIMFs(int win_size);
    QImage *fused_image;
};

#endif // FABEMD_DECOMPOSER_H
