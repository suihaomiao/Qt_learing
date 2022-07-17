#include "qperson.h"

QPerson::QPerson(QObject *parent) : QObject(parent)
{

}

QPerson::QPerson(const QString &name, QObject *parent)
{
    Q_UNUSED(parent);
    m_name = name;
}

unsigned int QPerson::age()
{
    return m_age;
}

void QPerson::setage(unsigned int value)
{
    if (m_age != value) {
        emit ageChangeNotify(value);
        m_age = value;
    }
    return;
}

unsigned QPerson::score()
{
    return m_score;
}

QString QPerson::sex()
{
    return m_sex;
}

QString QPerson::name()
{
    return m_name;
}

void QPerson::ageChange(unsigned int value)
{

}
