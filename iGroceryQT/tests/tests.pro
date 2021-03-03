QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tests.cpp \
            ../iGrocery/entities/good.cpp \
            ../iGrocery/entities/user.cpp \
            ../iGrocery/db/usersdb.cpp \
            ../iGrocery/db/goodsdb.cpp

HEADERS +=  ../iGrocery/entities/good.h \
            ../iGrocery/entities/user.h \
            ../iGrocery/db/usersdb.h \
            ../iGrocery/db/goodsdb.h
