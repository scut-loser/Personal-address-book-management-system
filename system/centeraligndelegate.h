#ifndef CENTERALIGNDELEGATE_H
#define CENTERALIGNDELEGATE_H

#include <QStyledItemDelegate>

// 继承 QStyledItemDelegate 创建自定义代理
class CenterAlignDelegate : public QStyledItemDelegate
{
    Q_OBJECT  // 若需要使用信号槽，则保留；否则可省略

public:
    // 构造函数（传递父对象以便内存管理）
    explicit CenterAlignDelegate(QObject *parent = nullptr);

    // 重写 initStyleOption 方法，强制设置对齐方式
    void initStyleOption(QStyleOptionViewItem *option,
                         const QModelIndex &index) const override;
};

#endif // CENTERALIGNDELEGATE_H
