#ifndef SYSTEMD_TYPES_H
#define SYSTEMD_TYPES_H

enum UnitMode {
    Replace,
    Fail,
    Isolate,
    IgnoreDependencies,
    IgnoreRequirements
};

enum UnitResult {
    Done,
    Canceled,
    Timeout,
    Failed,
    Dependency,
    Skipped
};

enum UnitKillWho {
    Main,
    Control,
    All
};

#endif // SYSTEMD_TYPES_H
