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

#ifndef SD_UNIT_P_H
#define SD_UNIT_P_H

#include "unitinterface.h"

#include "unit.h"

namespace Systemd {

class UnitPrivate
{

public:
    explicit UnitPrivate(const QString &path);
    virtual ~UnitPrivate();

    OrgFreedesktopSystemd1UnitInterface unitIface;

    qulonglong activeEnterTimestamp;
    qulonglong activeEnterTimestampMonotonic;
    qulonglong activeExitTimestamp;
    qulonglong activeExitTimestampMonotonic;
    QString activeState;
    QStringList after;
    bool allowIsolate;
    QStringList before;
    QStringList bindsTo;
    QStringList boundBy;
    bool canIsolate;
    bool canReload;
    bool canStart;
    bool canStop;
    bool conditionResult;
    qulonglong conditionTimestamp;
    qulonglong conditionTimestampMonotonic;
    QStringList conflictedBy;
    QStringList conflicts;
    QStringList consistsOf;
    bool defaultDependencies;
    QString description;
    QStringList documentation;
    QStringList dropInPaths;
    QString following;
    QString fragmentPath;
    QString id;
    bool ignoreOnIsolate;
    bool ignoreOnSnapshot;
    qulonglong inactiveEnterTimestamp;
    qulonglong inactiveEnterTimestampMonotonic;
    qulonglong inactiveExitTimestamp;
    qulonglong inactiveExitTimestampMonotonic;
    uint job;
    qulonglong jobTimeoutUSec;
    QStringList joinsNamespaceOf;
    QString loadState;
    QStringList names;
    bool needDaemonReload;
    QStringList onFailure;
    QString onFailureJobMode;
    QStringList partOf;
    QStringList propagatesReloadTo;
    bool refuseManualStart;
    bool refuseManualStop;
    QStringList reloadPropagatedFrom;
    QStringList requiredBy;
    QStringList requiredByOverridable;
    QStringList requires;
    QStringList requiresMountsFor;
    QStringList requiresOverridable;
    QStringList requisite;
    QStringList requisiteOverridable;
    QString sourcePath;
    bool stopWhenUnneeded;
    QString subState;
    bool transient;
    QStringList triggeredBy;
    QStringList triggers;
    QString unitFileState;
    QStringList wantedBy;
    QStringList wants;

    void populateProperties();
};
}

#endif
