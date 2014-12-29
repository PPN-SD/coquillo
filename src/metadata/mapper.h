#ifndef COQUILLO_METADATA_MAPPER_H
#define COQUILLO_METADATA_MAPPER_H

#include <QHash>
#include <QString>
#include <QVariant>

#include "tag.h"

namespace Coquillo {
    namespace MetaData {
        class Mapper {
            public:
                virtual ~Mapper() { }
                QString mapToSource(const QString & name) const;
                QString mapFromSource(const QString & name) const;

                virtual QVariant value(const Tag & tag, const QString & field) const;
                virtual QVariant take(Tag & tag, const QString & field) const;
                virtual void insert(Tag & tag, const QString & field, const QVariant & value);

            protected:
                QHash<QString, QString> _map;
        };

        class Id3v2Mapper : public Mapper {
            public:
                Id3v2Mapper();
                QVariant value(const Tag & tag, const QString & field) const ;
                void insert(Tag & tag, const QString & field, const QVariant & value);
        };

        class XiphMapper : public Mapper {
            public:
                XiphMapper();
                QVariant value(const Tag & tag, const QString & field) const ;
                void insert(Tag & tag, const QString & field, const QVariant & value);
        };
    }
}

#endif
