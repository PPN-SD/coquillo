#ifndef COQUILLO_TAGS_TAGSTORE_H
#define COQUILLO_TAGS_TAGSTORE_H

#include <QObject>
#include "tagcontainer.hpp"

namespace Coquillo {
    namespace Tags {
        class Store {
            public:
                Store();
                void add(const QVariantHash & file);
                void add(const QList<QVariantHash> & files);

                const Container & at(int pos) const;

                bool isModified(int pos) const;
                bool isFieldModified(int pos, const QString & field) const;

                void remove(int pos);

                inline int size() const { return _items.size(); }

                bool rename(int pos, const QString & new_path);
                bool setValue(int pos, const QString & field, const QVariant & value);

                QList<Container> changedItems() const;

            private:
                Container & at(int pos);
                void backup(int pos);
                void backup(const Container & item);

                Tag::Mapping _fallback;
                QHash< QString, Tag::Mapping> _mappings;
                QList<Container> _items;
                QHash<uint, Container> _backup;
        };
    }
}

#endif
