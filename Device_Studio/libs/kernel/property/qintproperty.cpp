#include "qintproperty.h"

QIntProperty::QIntProperty(QAbstractProperty * parent):
    QAbstractProperty(parent)
{
    m_value = 0;
}

QString QIntProperty::getValueText()
{
    return getValue().toString();
}

QIcon QIntProperty::getValueIcon()
{
    return QIcon();
}
