#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>
#include <QString>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("auth", "suihaomiao");
    Q_CLASSINFO("version", "1.0.0");
    Q_CLASSINFO("company", "123");
    Q_PROPERTY(unsigned int age READ age WRITE setage NOTIFY ageChangeNotify);
    Q_PROPERTY(unsigned int score MEMBER m_score);
    Q_PROPERTY(QString sex MEMBER m_sex);
    Q_PROPERTY(QString name MEMBER m_name);

public:
    explicit QPerson(QObject *parent = nullptr);
    QPerson(const QString &name, QObject *parent = nullptr);
    unsigned int age();
    void setage(unsigned int value);
    unsigned score();
    QString sex();
    QString name();
signals:
    void ageChangeNotify(unsigned int value);
public slots:
    void ageChange(unsigned int value);
private:
    unsigned int m_age;
    unsigned int m_score;
    QString m_sex;
    QString m_name;
};

#endif // QPERSON_H
