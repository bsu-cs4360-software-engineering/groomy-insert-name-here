QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appointment.cpp \
    appointmentsdialog.cpp \
    appointmentservice.cpp \
    customer.cpp \
    customers.cpp \
    customerservice.cpp \
    customerview.cpp \
    editappointmentdialog.cpp \
    editcustomerdialog.cpp \
    editnoteview.cpp \
    editserviceview.cpp \
    main.cpp \
    mainwindow.cpp \
    note.cpp \
    notesdialog.cpp \
    noteservice.cpp \
    service.cpp \
    services.cpp \
    servicesservice.cpp \
    servicesview.cpp \
    tablepopup.cpp \
    viewappointmentdialog.cpp

HEADERS += \
    appointment.h \
    appointmentsdialog.h \
    appointmentservice.h \
    customer.h \
    customers.h \
    customerservice.h \
    customerview.h \
    editappointmentdialog.h \
    editcustomerdialog.h \
    editnoteview.h \
    editserviceview.h \
    mainwindow.h \
    note.h \
    notesdialog.h \
    noteservice.h \
    service.h \
    services.h \
    servicesservice.h \
    servicesview.h \
    tablepopup.h \
    viewappointmentdialog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    appointment_notes.json \
    appointments.json \
    customer_notes.json \
    customers.json \
    notes.json \
    service_notes.json \
    services.json \
    users.json




