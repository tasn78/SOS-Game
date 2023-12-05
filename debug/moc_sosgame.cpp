/****************************************************************************
** Meta object code from reading C++ file 'sosgame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sosgame.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sosgame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_SOSGame_t {
    uint offsetsAndSizes[76];
    char stringdata0[8];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[23];
    char stringdata5[28];
    char stringdata6[29];
    char stringdata7[21];
    char stringdata8[21];
    char stringdata9[21];
    char stringdata10[21];
    char stringdata11[21];
    char stringdata12[22];
    char stringdata13[10];
    char stringdata14[24];
    char stringdata15[27];
    char stringdata16[24];
    char stringdata17[27];
    char stringdata18[17];
    char stringdata19[7];
    char stringdata20[21];
    char stringdata21[24];
    char stringdata22[16];
    char stringdata23[14];
    char stringdata24[11];
    char stringdata25[30];
    char stringdata26[5];
    char stringdata27[11];
    char stringdata28[9];
    char stringdata29[5];
    char stringdata30[15];
    char stringdata31[14];
    char stringdata32[28];
    char stringdata33[17];
    char stringdata34[10];
    char stringdata35[18];
    char stringdata36[25];
    char stringdata37[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SOSGame_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SOSGame_t qt_meta_stringdata_SOSGame = {
    {
        QT_MOC_LITERAL(0, 7),  // "SOSGame"
        QT_MOC_LITERAL(8, 31),  // "on_BoardSizeSlider_valueChanged"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 5),  // "value"
        QT_MOC_LITERAL(47, 22),  // "on_StartButton_clicked"
        QT_MOC_LITERAL(70, 27),  // "on_SimpleGameButton_clicked"
        QT_MOC_LITERAL(98, 28),  // "on_GeneralGameButton_clicked"
        QT_MOC_LITERAL(127, 20),  // "gameBoardButtonClick"
        QT_MOC_LITERAL(148, 20),  // "on_player1_S_clicked"
        QT_MOC_LITERAL(169, 20),  // "on_player1_O_clicked"
        QT_MOC_LITERAL(190, 20),  // "on_player2_S_clicked"
        QT_MOC_LITERAL(211, 20),  // "on_player2_O_clicked"
        QT_MOC_LITERAL(232, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(254, 9),  // "resetGame"
        QT_MOC_LITERAL(264, 23),  // "on_player1Human_clicked"
        QT_MOC_LITERAL(288, 26),  // "on_player1Computer_clicked"
        QT_MOC_LITERAL(315, 23),  // "on_player2Human_clicked"
        QT_MOC_LITERAL(339, 26),  // "on_player2Computer_clicked"
        QT_MOC_LITERAL(366, 16),  // "makeComputerMove"
        QT_MOC_LITERAL(383, 6),  // "player"
        QT_MOC_LITERAL(390, 20),  // "simulateComputerTurn"
        QT_MOC_LITERAL(411, 23),  // "startComputerVsComputer"
        QT_MOC_LITERAL(435, 15),  // "gameOverOptions"
        QT_MOC_LITERAL(451, 13),  // "handleRestart"
        QT_MOC_LITERAL(465, 10),  // "resumeGame"
        QT_MOC_LITERAL(476, 29),  // "on_RecordGameBox_stateChanged"
        QT_MOC_LITERAL(506, 4),  // "arg1"
        QT_MOC_LITERAL(511, 10),  // "recordMove"
        QT_MOC_LITERAL(522, 8),  // "GameMove"
        QT_MOC_LITERAL(531, 4),  // "move"
        QT_MOC_LITERAL(536, 14),  // "startRecording"
        QT_MOC_LITERAL(551, 13),  // "stopRecording"
        QT_MOC_LITERAL(565, 27),  // "on_ReplayGameButton_clicked"
        QT_MOC_LITERAL(593, 16),  // "loadRecordedGame"
        QT_MOC_LITERAL(610, 9),  // "applyMove"
        QT_MOC_LITERAL(620, 17),  // "performReplayStep"
        QT_MOC_LITERAL(638, 24),  // "initializeBoardForReplay"
        QT_MOC_LITERAL(663, 9)   // "boardSize"
    },
    "SOSGame",
    "on_BoardSizeSlider_valueChanged",
    "",
    "value",
    "on_StartButton_clicked",
    "on_SimpleGameButton_clicked",
    "on_GeneralGameButton_clicked",
    "gameBoardButtonClick",
    "on_player1_S_clicked",
    "on_player1_O_clicked",
    "on_player2_S_clicked",
    "on_player2_O_clicked",
    "on_pushButton_clicked",
    "resetGame",
    "on_player1Human_clicked",
    "on_player1Computer_clicked",
    "on_player2Human_clicked",
    "on_player2Computer_clicked",
    "makeComputerMove",
    "player",
    "simulateComputerTurn",
    "startComputerVsComputer",
    "gameOverOptions",
    "handleRestart",
    "resumeGame",
    "on_RecordGameBox_stateChanged",
    "arg1",
    "recordMove",
    "GameMove",
    "move",
    "startRecording",
    "stopRecording",
    "on_ReplayGameButton_clicked",
    "loadRecordedGame",
    "applyMove",
    "performReplayStep",
    "initializeBoardForReplay",
    "boardSize"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SOSGame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  194,    2, 0x08,    1 /* Private */,
       4,    0,  197,    2, 0x08,    3 /* Private */,
       5,    0,  198,    2, 0x08,    4 /* Private */,
       6,    0,  199,    2, 0x08,    5 /* Private */,
       7,    0,  200,    2, 0x08,    6 /* Private */,
       8,    0,  201,    2, 0x08,    7 /* Private */,
       9,    0,  202,    2, 0x08,    8 /* Private */,
      10,    0,  203,    2, 0x08,    9 /* Private */,
      11,    0,  204,    2, 0x08,   10 /* Private */,
      12,    0,  205,    2, 0x08,   11 /* Private */,
      13,    0,  206,    2, 0x08,   12 /* Private */,
      14,    0,  207,    2, 0x08,   13 /* Private */,
      15,    0,  208,    2, 0x08,   14 /* Private */,
      16,    0,  209,    2, 0x08,   15 /* Private */,
      17,    0,  210,    2, 0x08,   16 /* Private */,
      18,    1,  211,    2, 0x08,   17 /* Private */,
      20,    0,  214,    2, 0x08,   19 /* Private */,
      21,    0,  215,    2, 0x08,   20 /* Private */,
      22,    0,  216,    2, 0x08,   21 /* Private */,
      23,    0,  217,    2, 0x08,   22 /* Private */,
      24,    0,  218,    2, 0x08,   23 /* Private */,
      25,    1,  219,    2, 0x08,   24 /* Private */,
      27,    1,  222,    2, 0x08,   26 /* Private */,
      30,    0,  225,    2, 0x08,   28 /* Private */,
      31,    0,  226,    2, 0x08,   29 /* Private */,
      32,    0,  227,    2, 0x08,   30 /* Private */,
      33,    0,  228,    2, 0x08,   31 /* Private */,
      34,    1,  229,    2, 0x08,   32 /* Private */,
      35,    0,  232,    2, 0x08,   34 /* Private */,
      36,    1,  233,    2, 0x08,   35 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,

       0        // eod
};

Q_CONSTINIT const QMetaObject SOSGame::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SOSGame.offsetsAndSizes,
    qt_meta_data_SOSGame,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SOSGame_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SOSGame, std::true_type>,
        // method 'on_BoardSizeSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_StartButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SimpleGameButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_GeneralGameButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameBoardButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player1_S_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player1_O_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player2_S_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player2_O_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player1Human_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player1Computer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player2Human_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_player2Computer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'makeComputerMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'simulateComputerTurn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startComputerVsComputer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameOverOptions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleRestart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resumeGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RecordGameBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'recordMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const GameMove &, std::false_type>,
        // method 'startRecording'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopRecording'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ReplayGameButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadRecordedGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const GameMove &, std::false_type>,
        // method 'performReplayStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initializeBoardForReplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SOSGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SOSGame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_BoardSizeSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_StartButton_clicked(); break;
        case 2: _t->on_SimpleGameButton_clicked(); break;
        case 3: _t->on_GeneralGameButton_clicked(); break;
        case 4: _t->gameBoardButtonClick(); break;
        case 5: _t->on_player1_S_clicked(); break;
        case 6: _t->on_player1_O_clicked(); break;
        case 7: _t->on_player2_S_clicked(); break;
        case 8: _t->on_player2_O_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->resetGame(); break;
        case 11: _t->on_player1Human_clicked(); break;
        case 12: _t->on_player1Computer_clicked(); break;
        case 13: _t->on_player2Human_clicked(); break;
        case 14: _t->on_player2Computer_clicked(); break;
        case 15: _t->makeComputerMove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->simulateComputerTurn(); break;
        case 17: _t->startComputerVsComputer(); break;
        case 18: _t->gameOverOptions(); break;
        case 19: _t->handleRestart(); break;
        case 20: _t->resumeGame(); break;
        case 21: _t->on_RecordGameBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->recordMove((*reinterpret_cast< std::add_pointer_t<GameMove>>(_a[1]))); break;
        case 23: _t->startRecording(); break;
        case 24: _t->stopRecording(); break;
        case 25: _t->on_ReplayGameButton_clicked(); break;
        case 26: _t->loadRecordedGame(); break;
        case 27: _t->applyMove((*reinterpret_cast< std::add_pointer_t<GameMove>>(_a[1]))); break;
        case 28: _t->performReplayStep(); break;
        case 29: _t->initializeBoardForReplay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *SOSGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SOSGame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SOSGame.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SOSGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
