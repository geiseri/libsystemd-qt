/*
 * Copyright (C) 2013  Andrea Scarpino <me@andreascarpino.it>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef SD_UNIT_H
#define SD_UNIT_H

#include <QStringList>
#include <QSharedPointer>

#include "QtSystemd-export.h"
#include "systemd_types.h"
#include "job.h"

namespace Systemd {

class UnitPrivate;

class SDQT_EXPORT Unit : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Unit)

public:
    typedef QSharedPointer<Unit> Ptr;

    explicit Unit(const QString &path, QObject *parent = 0);
    explicit Unit(UnitPrivate &unit, QObject *parent = 0);
    virtual ~Unit();

    qulonglong activeEnterTimestamp() const;
    qulonglong activeEnterTimestampMonotonic() const;
    qulonglong activeExitTimestamp() const;
    qulonglong activeExitTimestampMonotonic() const;
    QString activeState() const;
    QStringList after() const;
    bool allowIsolate() const;
    QStringList before() const;
    QStringList bindsTo() const;
    QStringList boundBy() const;
    bool canIsolate() const;
    bool canReload() const;
    bool canStart() const;
    bool canStop() const;
    bool conditionResult() const;
    qulonglong conditionTimestamp() const;
    qulonglong conditionTimestampMonotonic() const;
    QStringList conflictedBy() const;
    QStringList conflicts() const;
    QStringList consistsOf() const;
    bool defaultDependencies() const;
    QString description() const;
    QStringList documentation() const;
    QStringList dropInPaths() const;
    QString following() const;
    QString fragmentPath() const;
    QString id() const;
    bool ignoreOnIsolate() const;
    bool ignoreOnSnapshot() const;
    qulonglong inactiveEnterTimestamp() const;
    qulonglong inactiveEnterTimestampMonotonic() const;
    qulonglong inactiveExitTimestamp() const;
    qulonglong inactiveExitTimestampMonotonic() const;
    uint job() const;
    qulonglong jobTimeoutUSec() const;
    QStringList joinsNamespaceOf() const;
    QString loadState() const;
    QStringList names() const;
    bool needDaemonReload() const;
    QStringList onFailure() const;
    QString onFailureJobMode() const;
    QStringList partOf() const;
    QStringList propagatesReloadTo() const;
    bool refuseManualStart() const;
    bool refuseManualStop() const;
    QStringList reloadPropagatedFrom() const;
    QStringList requiredBy() const;
    QStringList requiredByOverridable() const;
    QStringList requires() const;
    QStringList requiresMountsFor() const;
    QStringList requiresOverridable() const;
    QStringList requisite() const;
    QStringList requisiteOverridable() const;
    QString sourcePath() const;
    bool stopWhenUnneeded() const;
    QString subState() const;
    bool transient() const;
    QStringList triggeredBy() const;
    QStringList triggers() const;
    QString unitFileState() const;
    QStringList wantedBy() const;
    QStringList wants() const;

    void kill(const UnitKillWho who, int killSignal);
    Job::Ptr reload(const UnitMode mode);
    Job::Ptr reloadOrRestart(const UnitMode mode);
    Job::Ptr reloadOrTryRestart(const UnitMode mode);
    void resetFailed();
    Job::Ptr restart(const UnitMode mode);
    Job::Ptr start(const UnitMode mode);
    Job::Ptr stop(const UnitMode mode);
    Job::Ptr tryRestart(const UnitMode mode);

protected:
    UnitPrivate *d_ptr;

private slots:
    void populateProperties();

};
}

#endif
