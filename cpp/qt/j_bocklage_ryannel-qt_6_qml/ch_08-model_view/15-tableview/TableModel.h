#pragma once

#include <QAbstractTableModel>


class TableModel : public QAbstractTableModel {
	Q_OBJECT
	
public:
	TableModel();
	
	int rowCount(const QModelIndex & index = QModelIndex()) const override;
	int columnCount(const QModelIndex & index = QModelIndex()) const override;
	QVariant data(const QModelIndex & index, int role) const override;
};
