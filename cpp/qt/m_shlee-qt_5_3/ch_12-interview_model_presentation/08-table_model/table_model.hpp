#pragma once

#include <QtWidgets>

class TableModel : public QAbstractTableModel {
    Q_OBJECT

    private:
        int m_nRows;
        int m_nColumns;
        QHash<QModelIndex, QVariant> m_hash;

    public:
        TableModel(int nRows, int nColumns, QObject* pobj = 0)
            : QAbstractTableModel{ pobj },
              m_nRows{ nRows },
              m_nColumns{ nColumns } {}

        QVariant data(QModelIndex const& index, int nRole) const
        {
            if (not index.isValid())
                return QVariant{};

            QString str = QString("%1,%2").arg(index.row() + 1)
                                          .arg(index.column() + 1);
            return ((Qt::DisplayRole == nRole || Qt::EditRole == nRole)
                    ? m_hash.value(index, QVariant(str))
                    : QVariant{});
        }

        bool setData(QModelIndex const& index,
                     QVariant const& value,
                     int nRole)
        {
            if (index.isValid() and Qt::EditRole == nRole) {
                m_hash[index] = value;
                emit dataChanged(index, index);
                return true;
            }
            return false;
        }

        int rowCount(QModelIndex const&) const {
            return m_nRows;
        }

        int columnCount(QModelIndex const&) const {
            return m_nColumns;
        }

        Qt::ItemFlags flags(QModelIndex const& index) const {
            Qt::ItemFlags flags = QAbstractTableModel::flags(index);
            return (index.isValid() 
                    ? (flags | Qt::ItemIsEditable)
                    : flags);
        }
};
