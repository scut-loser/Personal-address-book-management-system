#ifndef LISTITEMDELEGATE_H
#define LISTITEMDELEGATE_H

#include <QPainter>
#include <QStyledItemDelegate>

class ListItemDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate; // 使用基类构造函数

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // LISTITEMDELEGATE_H
