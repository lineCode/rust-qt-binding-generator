/* generated by rust_qt_binding_generator */
#include "test_tree_rust.h"

namespace {

    struct option_quintptr {
    public:
        quintptr value;
        bool some;
        operator QVariant() const {
            if (some) {
                return QVariant::fromValue(value);
            }
            return QVariant();
        }
    };
    static_assert(std::is_pod<option_quintptr>::value, "option_quintptr must be a POD type.");

    typedef void (*qstring_set)(QString* val, const char* utf8, int nbytes);
    void set_qstring(QString* val, const char* utf8, int nbytes) {
        *val = QString::fromUtf8(utf8, nbytes);
    }

    struct qmodelindex_t {
        int row;
        quintptr id;
    };
    inline QVariant cleanNullQVariant(const QVariant& v) {
        return (v.isNull()) ?QVariant() :v;
    }
}
extern "C" {
    void persons_data_user_name(const Persons::Private*, quintptr, QString*, qstring_set);
    bool persons_set_data_user_name(Persons::Private*, quintptr, const ushort* s, int len);
    void persons_sort(Persons::Private*, unsigned char column, Qt::SortOrder order = Qt::AscendingOrder);

    int persons_row_count(const Persons::Private*, option_quintptr);
    bool persons_can_fetch_more(const Persons::Private*, option_quintptr);
    void persons_fetch_more(Persons::Private*, option_quintptr);
    quintptr persons_index(const Persons::Private*, option_quintptr, int);
    qmodelindex_t persons_parent(const Persons::Private*, quintptr);
    int persons_row(const Persons::Private*, quintptr);
}
int Persons::columnCount(const QModelIndex &) const
{
    return 1;
}

bool Persons::hasChildren(const QModelIndex &parent) const
{
    return rowCount(parent) > 0;
}

int Persons::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return 0;
    }
    const option_quintptr rust_parent = {
        parent.internalId(),
        parent.isValid()
    };
    return persons_row_count(m_d, rust_parent);
}

bool Persons::insertRows(int, int, const QModelIndex &)
{
    return false; // not supported yet
}

bool Persons::removeRows(int, int, const QModelIndex &)
{
    return false; // not supported yet
}

QModelIndex Persons::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || column >= 1) {
        return QModelIndex();
    }
    if (parent.isValid() && parent.column() != 0) {
        return QModelIndex();
    }
    if (row >= rowCount(parent)) {
        return QModelIndex();
    }
    const option_quintptr rust_parent = {
        parent.internalId(),
        parent.isValid()
    };
    const quintptr id = persons_index(m_d, rust_parent, row);
    return createIndex(row, column, id);
}

QModelIndex Persons::parent(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QModelIndex();
    }
    const qmodelindex_t parent = persons_parent(m_d, index.internalId());
    return parent.row >= 0 ?createIndex(parent.row, 0, parent.id) :QModelIndex();
}

bool Persons::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return false;
    }
    const option_quintptr rust_parent = {
        parent.internalId(),
        parent.isValid()
    };
    return persons_can_fetch_more(m_d, rust_parent);
}

void Persons::fetchMore(const QModelIndex &parent)
{
    const option_quintptr rust_parent = {
        parent.internalId(),
        parent.isValid()
    };
    persons_fetch_more(m_d, rust_parent);
}

void Persons::sort(int column, Qt::SortOrder order)
{
    persons_sort(m_d, column, order);
}
Qt::ItemFlags Persons::flags(const QModelIndex &i) const
{
    auto flags = QAbstractItemModel::flags(i);
    if (i.column() == 0) {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QString Persons::userName(const QModelIndex& index) const
{
    QString s;
    persons_data_user_name(m_d, index.internalId(), &s, set_qstring);
    return s;
}

bool Persons::setUserName(const QModelIndex& index, const QString& value)
{
    bool set = false;
    set = persons_set_data_user_name(m_d, index.internalId(), value.utf16(), value.length());
    if (set) {
        emit dataChanged(index, index);
    }
    return set;
}

QVariant Persons::data(const QModelIndex &index, int role) const
{
    Q_ASSERT(rowCount(index.parent()) > index.row());
    switch (index.column()) {
    case 0:
        switch (role) {
        case Qt::DisplayRole:
        case Qt::EditRole:
        case Qt::UserRole + 0:
            return QVariant::fromValue(userName(index));
        }
    }
    return QVariant();
}

int Persons::role(const char* name) const {
    auto names = roleNames();
    auto i = names.constBegin();
    while (i != names.constEnd()) {
        if (i.value() == name) {
            return i.key();
        }
        ++i;
    }
    return -1;
}
QHash<int, QByteArray> Persons::roleNames() const {
    QHash<int, QByteArray> names = QAbstractItemModel::roleNames();
    names.insert(Qt::UserRole + 0, "userName");
    return names;
}
QVariant Persons::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }
    return m_headerData.value(qMakePair(section, (Qt::ItemDataRole)role), role == Qt::DisplayRole ?QString::number(section + 1) :QVariant());
}

bool Persons::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (orientation != Qt::Horizontal) {
        return false;
    }
    m_headerData.insert(qMakePair(section, (Qt::ItemDataRole)role), value);
    return true;
}

bool Persons::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column() == 0) {
        if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::UserRole + 0) {
            if (value.canConvert(qMetaTypeId<QString>())) {
                return setUserName(index, value.value<QString>());
            }
        }
    }
    return false;
}

extern "C" {
    Persons::Private* persons_new(Persons*,
        void (*)(const Persons*, option_quintptr),
        void (*)(Persons*),
        void (*)(Persons*),
        void (*)(Persons*, quintptr, quintptr),
        void (*)(Persons*),
        void (*)(Persons*),
        void (*)(Persons*, option_quintptr, int, int),
        void (*)(Persons*),
        void (*)(Persons*, option_quintptr, int, int, option_quintptr, int),
        void (*)(Persons*),
        void (*)(Persons*, option_quintptr, int, int),
        void (*)(Persons*));
    void persons_free(Persons::Private*);
};

Persons::Persons(bool /*owned*/, QObject *parent):
    QAbstractItemModel(parent),
    m_d(0),
    m_ownsPrivate(false)
{
    initHeaderData();
}

Persons::Persons(QObject *parent):
    QAbstractItemModel(parent),
    m_d(persons_new(this,
        [](const Persons* o, option_quintptr id) {
            if (id.some) {
                int row = persons_row(o->m_d, id.value);
                emit o->newDataReady(o->createIndex(row, 0, id.value));
            } else {
                emit o->newDataReady(QModelIndex());
            }
        },
        [](Persons* o) {
            emit o->layoutAboutToBeChanged();
        },
        [](Persons* o) {
            emit o->layoutChanged();
        },
        [](Persons* o, quintptr first, quintptr last) {
            quintptr frow = persons_row(o->m_d, first);
            quintptr lrow = persons_row(o->m_d, first);
            o->dataChanged(o->createIndex(frow, 0, first),
                       o->createIndex(lrow, 0, last));
        },
        [](Persons* o) {
            o->beginResetModel();
        },
        [](Persons* o) {
            o->endResetModel();
        },
        [](Persons* o, option_quintptr id, int first, int last) {
            if (id.some) {
                int row = persons_row(o->m_d, id.value);
                o->beginInsertRows(o->createIndex(row, 0, id.value), first, last);
            } else {
                o->beginInsertRows(QModelIndex(), first, last);
            }
        },
        [](Persons* o) {
            o->endInsertRows();
        },
        [](Persons* o, option_quintptr sourceParent, int first, int last, option_quintptr destinationParent, int destination) {
            QModelIndex s;
            if (sourceParent.some) {
                int row = persons_row(o->m_d, sourceParent.value);
                s = o->createIndex(row, 0, sourceParent.value);
            }
            QModelIndex d;
            if (destinationParent.some) {
                int row = persons_row(o->m_d, destinationParent.value);
                d = o->createIndex(row, 0, destinationParent.value);
            }
            o->beginMoveRows(s, first, last, d, destination);
        },
        [](Persons* o) {
            o->endMoveRows();
        },
        [](Persons* o, option_quintptr id, int first, int last) {
            if (id.some) {
                int row = persons_row(o->m_d, id.value);
                o->beginRemoveRows(o->createIndex(row, 0, id.value), first, last);
            } else {
                o->beginRemoveRows(QModelIndex(), first, last);
            }
        },
        [](Persons* o) {
            o->endRemoveRows();
        }
)),
    m_ownsPrivate(true)
{
    connect(this, &Persons::newDataReady, this, [this](const QModelIndex& i) {
        this->fetchMore(i);
    }, Qt::QueuedConnection);
    initHeaderData();
}

Persons::~Persons() {
    if (m_ownsPrivate) {
        persons_free(m_d);
    }
}
void Persons::initHeaderData() {
    m_headerData.insert(qMakePair(0, Qt::DisplayRole), QVariant("userName"));
}
