QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    Appointments.cpp \
    CustomerInfo.cpp \
    UserInfo.cpp \
    crypt_blowfish/crypt_blowfish.c \
    crypt_blowfish/crypt_gensalt.c \
    crypt_blowfish/wrapper.c \
    main.cpp \
    mainwindow.cpp \
    tablepopup.cpp

HEADERS += \
    Appointments.h \
    CommonIncludes.h \
    CustomerInfo.h \
    UserInfo.h \
    bcrypt.h \
    crypt_blowfish/crypt.h \
    crypt_blowfish/crypt_blowfish.h \
    crypt_blowfish/crypt_gensalt.h \
    crypt_blowfish/ow-crypt.h \
    crypt_blowfish/x86.S \
    mainwindow.h \
    nlohmann/adl_serializer.hpp \
    nlohmann/byte_container_with_subtype.hpp \
    nlohmann/detail/abi_macros.hpp \
    nlohmann/detail/conversions/from_json.hpp \
    nlohmann/detail/conversions/to_chars.hpp \
    nlohmann/detail/conversions/to_json.hpp \
    nlohmann/detail/exceptions.hpp \
    nlohmann/detail/hash.hpp \
    nlohmann/detail/input/binary_reader.hpp \
    nlohmann/detail/input/input_adapters.hpp \
    nlohmann/detail/input/json_sax.hpp \
    nlohmann/detail/input/lexer.hpp \
    nlohmann/detail/input/parser.hpp \
    nlohmann/detail/input/position_t.hpp \
    nlohmann/detail/iterators/internal_iterator.hpp \
    nlohmann/detail/iterators/iter_impl.hpp \
    nlohmann/detail/iterators/iteration_proxy.hpp \
    nlohmann/detail/iterators/iterator_traits.hpp \
    nlohmann/detail/iterators/json_reverse_iterator.hpp \
    nlohmann/detail/iterators/primitive_iterator.hpp \
    nlohmann/detail/json_custom_base_class.hpp \
    nlohmann/detail/json_pointer.hpp \
    nlohmann/detail/json_ref.hpp \
    nlohmann/detail/macro_scope.hpp \
    nlohmann/detail/macro_unscope.hpp \
    nlohmann/detail/meta/call_std/begin.hpp \
    nlohmann/detail/meta/call_std/end.hpp \
    nlohmann/detail/meta/cpp_future.hpp \
    nlohmann/detail/meta/detected.hpp \
    nlohmann/detail/meta/identity_tag.hpp \
    nlohmann/detail/meta/is_sax.hpp \
    nlohmann/detail/meta/std_fs.hpp \
    nlohmann/detail/meta/type_traits.hpp \
    nlohmann/detail/meta/void_t.hpp \
    nlohmann/detail/output/binary_writer.hpp \
    nlohmann/detail/output/output_adapters.hpp \
    nlohmann/detail/output/serializer.hpp \
    nlohmann/detail/string_concat.hpp \
    nlohmann/detail/string_escape.hpp \
    nlohmann/detail/value_t.hpp \
    nlohmann/json.hpp \
    nlohmann/json_fwd.hpp \
    nlohmann/ordered_map.hpp \
    nlohmann/thirdparty/hedley/hedley.hpp \
    nlohmann/thirdparty/hedley/hedley_undef.hpp \
    tablepopup.h
=======
    customer.cpp \
    customers.cpp \
    customerservice.cpp \
    editcustomerdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    tablepopup.cpp \
    viewcustomerdialog.cpp

HEADERS += \
    customer.h \
    customers.h \
    customerservice.h \
    editcustomerdialog.h \
    mainwindow.h \
    tablepopup.h \
    viewcustomerdialog.h
>>>>>>> workspace-Lucas

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

<<<<<<< HEAD
RESOURCES +=

DISTFILES += \
    crypt_blowfish/LINKS \
    crypt_blowfish/PERFORMANCE \
    crypt_blowfish/README \
    crypt_blowfish/crypt.3 \
    crypt_blowfish/glibc-2.1.3-crypt.diff \
    crypt_blowfish/glibc-2.14-crypt.diff \
    crypt_blowfish/glibc-2.3.6-crypt.diff
=======
RESOURCES += \
    resources.qrc

DISTFILES += \
    customers.json
>>>>>>> workspace-Lucas




