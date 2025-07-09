#include "listitemdelegate.h"


void ListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const  {
    QStyledItemDelegate::paint(painter, option, index);

    if (index.row() != index.model()->rowCount() - 1) {
        painter->save();

        // 创建 QPen 并设置颜色、粗细、抗锯齿
        QPen pen;
        // pen.setColor(QColor("#cccccc")); // 颜色
        pen.setColor(QColor(204, 204, 204)); // 颜色
        pen.setWidth(1);                 // 线条粗细（单位：像素）
        painter->setPen(pen);
        painter->setRenderHint(QPainter::Antialiasing, true); // 抗锯齿

        // 计算线条位置（向下偏移 1px）
        int lineY = option.rect.bottom() + 18;
        QPoint left(option.rect.left(), lineY);
        QPoint right(option.rect.right(), lineY);
        painter->drawLine(left, right);

        painter->restore();
    }
}
