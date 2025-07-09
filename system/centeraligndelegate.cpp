#include "centeraligndelegate.h"


// 构造函数（调用基类构造函数）
CenterAlignDelegate::CenterAlignDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

// 核心实现：设置单元格对齐方式
void CenterAlignDelegate::initStyleOption(QStyleOptionViewItem *option,
                                          const QModelIndex &index) const
{
    // 1. 先调用基类方法确保默认样式正确
    QStyledItemDelegate::initStyleOption(option, index);

    // 2. 强制设置水平和垂直居中
    option->displayAlignment = Qt::AlignCenter;
}
