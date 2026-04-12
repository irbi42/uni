#include "chartbuilder.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>


ChartBuilder::ChartBuilder(QTableWidget *sourceTable, QGraphicsView *parent) {
    m_sourseTable = sourceTable;
}


void ChartBuilder::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    QMenu menu;
    QAction *actionExportPNG = menu.addAction(tr("Export to PNG"));
    QAction *actionCloseDiagram = menu.addAction(tr("Close Diagram"));
    QAction *selectedAction = menu.exec(event->screenPos());
    if (!selectedAction) return;
    if(selectedAction == actionExportPNG) {
        QString path = QFileDialog::getSaveFileName(nullptr, tr("Save Diagram as PNG"), QString(), tr("PNG Files (*.png)"));

        if (!path.isEmpty()) {
            exportToPng(path);
        }
    } else if (selectedAction == actionCloseDiagram) {
        closeDiagram();
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
    if (maxValue == 0.0) maxValue = 1.0;

    QGraphicsRectItem *bar;
    QGraphicsLineItem *baseLine = new QGraphicsLineItem(-chartWidth / 2, chartMaxHeight, chartWidth / 2, chartMaxHeight);
    addItem(baseLine);
    m_items.append(baseLine);
    QGraphicsTextItem *caption;
    double posX = -(chartWidth / 2) + spacer;

    for (auto i = m_data.cbegin(),end = m_data.cend(); i != end; ++i) {
        qDebug() << "cur X:" <<posX;
        double height = ((chartMaxHeight - 20 )/ maxValue) * i.value();
        bar = new QGraphicsRectItem(posX, chartMaxHeight - height, barWidth, height);
        bar->setBrush(QBrush(Qt::blue));
        caption = new QGraphicsTextItem(i.key() + QString("\n(%1)").arg(i.value()), bar);
        //qDebug() << "capt height: " << caption->boundingRect().height();
        caption->setPos(posX, chartMaxHeight + spacer);
        caption->setTextWidth(barWidth);
        //qDebug() << "capt new height: " << caption->boundingRect().height();
        // QGraphicsItemGroup *group = createItemGroup({bar, caption});
        // addItem(group);
        addItem(bar);
        m_items.append(bar);
        addItem(caption);
        m_items.append(caption);
        posX = posX + barWidth + spacer;
    }


}

void ChartBuilder::closeDiagram() {
    clear();
    m_items.clear();
    m_data.clear();

    qDebug() << "Diagram closed";
}

void ChartBuilder::exportToPng(const QString &path) {
    if (m_items.isEmpty()) {
        QMessageBox::warning(nullptr, tr("Export Error"), tr("No diagram to export"));
        return;
    }
    QRectF sceneRect = this->itemsBoundingRect();

    qreal margin = 50;
    sceneRect.adjust(-margin, -margin, margin, margin);

    QImage image(sceneRect.size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    this->render(&painter, QRectF(), sceneRect);
    painter.end();


    if (image.save(path, "PNG")) {
        QMessageBox::information(nullptr, tr("Export Success"),
                                 tr("Diagram exported successfully to:\n%1").arg(path));
        qDebug() << "Diagram exported to:" << path;
    } else {
        QMessageBox::warning(nullptr, tr("Export Error"),
                             tr("Failed to save diagram to:\n%1").arg(path));
        qDebug() << "Failed to export diagram to:" << path;
    }
}

