#include <QUrl>
#include <QSysInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "wpmsession.h"
#include "logger.h"

ASU_USE_NAMESPACE

WPMBuild& WPMBuild::operator=(const QJsonObject& o)
{
    if(!(o.contains("bid")
      && o.contains("aid")
      && o.contains("bversion")
      && o.contains("btags")
      && o.contains("burl")
      && o.contains("bdownload")
    )) throw QString("MyFunc argument too large.");
    this->bid = o["bid"].toInt();
    this->aid = o["aid"].toInt();
    this->bversion = o["bversion"].toString();
    this->btags = o["btags"].toString();
    this->burl = o["burl"].toString();
    this->bdownload = o["bdownload"].toString();
    return *this;
}

WPMBuild::operator QJsonObject()
{
    QJsonObject o;
//    o["bid"] = this->bid;
//    o["aid"] = this->aid;
//    o["bversion"] = this->bversion;
//    o["btags"] = this->btags;
//    o["burl"] = this->burl;
//    o["bdownload"] = this->bdownload;
    return o;
}

WPMSession::WPMSession(QObject *parent)
    : Session(parent), host("http://worker.asu/")
{

}

WPMSession::~WPMSession()
{

}

bool WPMSession::getLastBuild(int app)
{
    zInfo(tr("WPMSession::getLastBuild(%1)").arg(app));
    //
    QString url = QString("api/builds/?app=%1&tag[]=os_%2&tag[]=kernel_%3&tag[]=osname_%4&tag[]=arch_%5")
            .arg(app).arg(QSysInfo::productType()).arg(QSysInfo::kernelType()).arg(QSysInfo::productType()).arg(QSysInfo::currentCpuArchitecture());
    QByteArray responce;
    //
    if(this->get(host + url, responce) == QNetworkReply::NoError){
        zDebug(tr("Ответ %1")/*.arg(responce)*/);
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responce, &parseError);
        if(parseError.error == QJsonParseError::NoError){
            if(jsonDoc.isArray()){
                QJsonArray jsonArr = jsonDoc.array();
//                if(jsonArr.size() == 0) return false;
                //
                QJsonObject app = jsonArr.at(0).toObject();
                QString burl = app["burl"].toString();
                zDebug(tr("Получен burl %1").arg(burl));
            }else{
                zWarning(tr("Ответ сервера: ответ не массив"));
//                return false;
            }
        }else{
            zError(tr("Ошибка ответа: %1").arg(parseError.errorString()));
//            return false;
        }
    }
    //
/*    QXmlStreamReader xml(responce);
    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(xml.isStartElement()){
            QString tag = xml.name().toString();
            if(tag == "app"){
                QXmlStreamAttributes attrs = xml.QXmlStreamReader::attributes();
                tagApp _tag;
                zTrace(tr("tag %1").arg(attrs.count()));
                for (int i = 0; i < attrs.count(); i++){
                    QString _name = attrs[i].name().toString();
                    if(_name == "id"){
                        _tag.id = attrs[i].value().toInt();
                    }else if(_name == "name"){
                        _tag.name = attrs[i].value().toString();
                    }else if(_name == "version"){
                        _tag.version = attrs[i].value().toString();
                    }else if(_name == "path"){
                        _tag.path = attrs[i].value().toString();
                    }else if(_name == "start"){
                        _tag.start = attrs[i].value().toString();
                    }
                }
                _apps.insert(_tag.id, _tag);
                zInfo(tr("{ %1 , %2 , %3 , %4 }").arg(_tag.id).arg(_tag.name).arg(_tag.version).arg(_tag.path));
            }else{
                zWarning(tr("Неизвестный тег %1").arg(tag));
            }
        }
    }
    if (xml.hasError()) {
        zInfo(tr("Неверный XML файл %1").arg(xml.errorString()));
        return false;
    }*/
//    return true;
}



