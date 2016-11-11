TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ./tree
INCLUDEPATH += ./graph
INCLUDEPATH += ./graph

SOURCES += main.c \
    graph/graph.c \
    graph/crt_graph.c \
    graph/adjlist_graph.c \
    tree/tree.c \
    stack/stack_array.c \
    stack/stack_list.c \
    queue/queue_array.c \
    queue/queue_link.c

HEADERS += \
    tree.h \
    graph/graph.h \
    graph/crt_graph.h \
    graph/adjlist_graph.h \
    tree/tree.h \
    stack/stack_array.h \
    stack/stack_list.h \
    queue/queue_array.h \
    queue/queue_link.h
