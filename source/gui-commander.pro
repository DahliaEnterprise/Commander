#-------------------------------------------------
#
# Project created by QtCreator 2019-02-17T17:16:29
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui-commander
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 wall_off

SOURCES += \
        main.cpp \
    mainmenu.cpp \
    find.cpp \
    find/find_filterby_filename.cpp \
    find/thread_find_filterby_filename.cpp \
    cardgame/cardgame.cpp \
    cardgame/window_playagainstai.cpp \
    cardgame/opengl/opengl_widget.cpp \
    cardgame/opengl/opengl_canvas.cpp \
    cardgame/game_to_opengl/game_to_opengl_image.cpp \
    cardgame/game_to_opengl/game_to_opengl.cpp \
    cardgame/playerInput/playerinput_usingkeyboard.cpp \
    cardgame/gamelogic/gamelogic.cpp \
    cardgame/gamelogic/mainmenu/gamelogic_mainmenu.cpp \
    cardgame/gamelogic/mainmenu/mainmenu_indicator_of_selectedwindow.cpp \
    cardgame/gamelogic/mainmenu/mainmenu_mouse.cpp \
    cardgame/gamelogic/mainmenu/mainmenu_selectablecards.cpp \
    cardgame/database/database.cpp \
    cardgame/database/database_card.cpp \
    cardgame/gamelogic/mainmenu/mainmenu_loadinggizmo.cpp

HEADERS += \
    mainmenu.h \
    find.h \
    find/find_filterby_filename.h \
    find/thread_find_filterby_filename.h \
    cardgame/cardgame.h \
    cardgame/window_playagainstai.h \
    cardgame/opengl/opengl_widget.h \
    cardgame/opengl/opengl_canvas.h \
    cardgame/opengl/canvas/canvas_draw_command_image.h \
    cardgame/game_to_opengl/game_to_opengl_image.h \
    cardgame/game_to_opengl/game_to_opengl.h \
    cardgame/playerInput/playerinput_usingkeyboard.h \
    cardgame/gamelogic/gamelogic.h \
    cardgame/gamelogic/mainmenu/gamelogic_mainmenu.h \
    cardgame/gamelogic/mainmenu/mainmenu_indicator_of_selectedwindow.h \
    cardgame/gamelogic/mainmenu/mainmenu_mouse.h \
    cardgame/gamelogic/mainmenu/mainmenu_selectablecards.h \
    cardgame/database/database.h \
    cardgame/database/database_card.h \
    cardgame/gamelogic/mainmenu/mainmenu_loadinggizmo.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
