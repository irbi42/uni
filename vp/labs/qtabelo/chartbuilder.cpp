#include "chartbuilder.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>

ChartBuilder::ChartBuilder(QTableWidget *sourceTable, QGraphicsView *parent) {
    m_sourseTable = sourceTable;
}


void ChartBuilder::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    QMenu menu;
    QAction *actionExportPNG = menu.addAction(tr("Export to PNG"));
    QAction *actionCloseDiagram = menu.addAction(tr("Close Diagram"));
    QAction *selectedAction = menu.exec(event->pos());
    if (!selectedAction) return;
    if(selectedAction == actionExportPNG) {

    } else if (selectedAction == actionCloseDiagram) {

    }
}

void ChartBuilder::buildBarChart(const QModelIndexList &selectedCells) {
    clear();
    m_data.clear();
    for (int i = 0; i < selectedCells.size(); i = i + 2) {
        QString key = m_sourseTable->item(selectedCells[i].row(),selectedCells[i].column())->text();
        double value = m_sourseTable->item(selectedCells[i + 1].row(),selectedCells[i + 1].column())->text().toDouble();
        m_data.insert(key, value);
    }
    int chartMaxHeight = 400;
    int barWidth = 100;
    int spacer = 10;
    double chartWidth = barWidth * m_data.size() + spacer * (m_data.size() + 1);
    double maxValue = 0.0;

    for (auto i = m_data.cbegin(),end = m_data.cend(); i != end; ++i) {
        qDebug() << qPrintable(i.key()) << ": " << i.value() << "\n";
        if (i.value() > maxValue) {
            maxValue = i.value();
        }
    }

    qDebug() << "max: " << maxValue;

    QGraphicsRectItem *bar;
    QGraphicsLineItem *baseLine = new QGraphicsLineItem(-chartWidth / 2, chartMaxHeight, chartWidth / 2, chartMaxHeight);
    addItem(baseLine);
    QGraphicsTextItem *caption;
    double posX = -(chartWidth / 2) + spacer;

    for (auto i = m_data.cbegin(),end = m_data.cend(); i != end; ++i) {
        qDebug() << "cur X:" <<posX;
        double height = ((chartMaxHeight - 20 )/ maxValue) * i.value();
        bar = new QGraphicsRectItem(posX, chartMaxHeight - height, barWidth, height);
        caption = new QGraphicsTextItem(i.key() + QString("\n(%1)").arg(i.value()), bar);
        //qDebug() << "capt height: " << caption->boundingRect().height();
        caption->setPos(posX, chartMaxHeight + spacer);
        caption->setTextWidth(barWidth);
        //qDebug() << "capt new height: " << caption->boundingRect().height();
        // QGraphicsItemGroup *group = createItemGroup({bar, caption});
        // addItem(group);
        addItem(bar);
        addItem(caption);
        posX = posX + barWidth + spacer;
    }


}

void ChartBuilder::exportToPng(const QString &path) {

}
