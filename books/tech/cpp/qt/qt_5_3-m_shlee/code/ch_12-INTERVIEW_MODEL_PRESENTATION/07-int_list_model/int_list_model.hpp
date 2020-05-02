#pragma once

#include <QAbstractListModel>
class IntListModel : public QAbstractListModel {
    Q_OBJECT

    public:
        IntListModel(QList<int> const& list, QObject* pobj = 0)
            : QAbstractListModel{pobj},
              m_list{list} { }

        QVariant data(QModelIndex const& index, int nRole) const
        {
            if (not index.isValid())
                return QVariant{};

            return ((Qt::DisplayRole == nRole || Qt::EditRole == nRole)
                    ? m_list.at(index.row())
                    : QVariant{});
        }

        bool setData(QModelIndex const& index,
                     QVariant const& value,
                     int nRole)
        {
            if (index.isValid() and Qt::EditRole == nRole) {
                m_list.replace(index.row(), value.value<int>());
                emit dataChanged(index, index);
                return true;
            }
            return false;
        }

        int rowCount(QModelIndex const& parent = QModelIndex()) const {
            return m_list.size();
        }

        QVariant headerData(int nSection,
                            Qt::Orientation orientation,
                            int nRole = Qt::DisplayRole) const
        {
            if (nRole != Qt::DisplayRole)
                return QVariant();

            return (Qt::Horizontal == orientation 
                    ? QString("Number")
                    : QString::number(nSection));
        }

        Qt::ItemFlags flags(QModelIndex const& index) const {
            Qt::ItemFlags flags = QAbstractListModel::flags(index);
            return (index.isValid() 
                    ? (flags | Qt::ItemIsEditable)
                    : flags);
        }

    private:
        QList<int> m_list;
};
