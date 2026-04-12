#ifndef CHARTBUILDER_H
#define CHARTBUILDER_H

#include <QGraphicsScene>
#include <QTableWidget>

class ChartBuilder : public QGraphicsScene
{
public:
    explicit ChartBuilder(QTableWidget *sourceTable, QGraphicsView *parent = nullptr);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void buildBarChart(const QModelIndexList &selectedCells);
    void exportToPng(const QString &path);
    void closeDiagram();

private:
    QTableWidget *m_sourseTable;
    QMap<QString, double> m_data;
    QList<QGraphicsItem*> m_items;

};

#endif // CHARTBUILDER_H
