/**
 * Carma Cloud Webservice
 * Carma cloud  Webservice accepts requests from vehicles and response message from carma cloud
 *
 * The version of the OpenAPI document: 0.1.9
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

#include "OAIHelpers.h"
#include "OAIDefaultApiRequest.h"

namespace OpenAPI {

OAIDefaultApiRequest::OAIDefaultApiRequest(QHttpEngine::Socket *s, QSharedPointer<OAIDefaultApiHandler> hdl) : QObject(s), socket(s), handler(hdl) {
    auto headers = s->headers();
    for(auto itr = headers.begin(); itr != headers.end(); itr++) {
        requestHeaders.insert(QString(itr.key()), QString(itr.value()));
    }
}

OAIDefaultApiRequest::~OAIDefaultApiRequest(){
    disconnect(this, nullptr, nullptr, nullptr);
    qDebug() << "OAIDefaultApiRequest::~OAIDefaultApiRequest()";
}

QMap<QString, QString>
OAIDefaultApiRequest::getRequestHeaders() const {
    return requestHeaders;
}

void OAIDefaultApiRequest::setResponseHeaders(const QMultiMap<QString, QString>& headers){
    for(auto itr = headers.begin(); itr != headers.end(); ++itr) {
        responseHeaders.insert(itr.key(), itr.value());
    }
}


QHttpEngine::Socket* OAIDefaultApiRequest::getRawSocket(){
    return socket;
}


void OAIDefaultApiRequest::tcmreplyPostRequest(){
    qDebug() << "/carmacloud/tcmreply";
    connect(this, &OAIDefaultApiRequest::tcmreplyPost, handler.data(), &OAIDefaultApiHandler::tcmreplyPost);

    
 
    
    QString body;
    ::OpenAPI::fromStringValue(QString(socket->readAll()), body);
    
    

    emit tcmreplyPost(body);
}


void OAIDefaultApiRequest::tcmreqPostRequest(){
    qDebug() << "/carmacloud/tcmreq";
    connect(this, &OAIDefaultApiRequest::tcmreqPost, handler.data(), &OAIDefaultApiHandler::tcmreqPost);

    
 
    
    QString body;
    ::OpenAPI::fromStringValue(QString(socket->readAll()), body);
    
    

    emit tcmreqPost(body);
}


void OAIDefaultApiRequest::v2xhubPostRequest(){
    qDebug() << "/carmacloud/v2xhub";
    connect(this, &OAIDefaultApiRequest::v2xhubPost, handler.data(), &OAIDefaultApiHandler::v2xhubPost);

    
 
    
    QString body;
    ::OpenAPI::fromStringValue(QString(socket->readAll()), body);
    
    

    emit v2xhubPost(body);
}



void OAIDefaultApiRequest::tcmreplyPostResponse(){
    writeResponseHeaders();
    socket->setStatusCode(QHttpEngine::Socket::OK);
    if(socket->isOpen()){
        socket->close();
    }
}

void OAIDefaultApiRequest::tcmreqPostResponse(){
    writeResponseHeaders();
    socket->setStatusCode(QHttpEngine::Socket::OK);
    if(socket->isOpen()){
        socket->close();
    }
}

void OAIDefaultApiRequest::v2xhubPostResponse(){
    writeResponseHeaders();
    socket->setStatusCode(QHttpEngine::Socket::OK);
    if(socket->isOpen()){
        socket->close();
    }
}


void OAIDefaultApiRequest::tcmreplyPostError(QNetworkReply::NetworkError error_type, QString& error_str){
    Q_UNUSED(error_type); // TODO: Remap error_type to QHttpEngine::Socket errors
    writeResponseHeaders();
    socket->setStatusCode(QHttpEngine::Socket::NotFound);
    socket->write(error_str.toUtf8());
    if(socket->isOpen()){
        socket->close();
    }
}

void OAIDefaultApiRequest::tcmreqPostError(QNetworkReply::NetworkError error_type, QString& error_str){
    Q_UNUSED(error_type); // TODO: Remap error_type to QHttpEngine::Socket errors
    writeResponseHeaders();
    socket->setStatusCode(QHttpEngine::Socket::NotFound);
    socket->write(error_str.toUtf8());
    if(socket->isOpen()){
        socket->close();
    }
}

void OAIDefaultApiRequest::v2xhubPostError(QNetworkReply::NetworkError error_type, QString& error_str){
    Q_UNUSED(error_type); // TODO: Remap error_type to QHttpEngine::Socket errors
    writeResponseHeaders();
    socket->setStatusCode(QHttpEngine::Socket::NotFound);
    socket->write(error_str.toUtf8());
    if(socket->isOpen()){
        socket->close();
    }
}


void OAIDefaultApiRequest::sendCustomResponse(QByteArray & res, QNetworkReply::NetworkError error_type){
    Q_UNUSED(error_type); // TODO
    socket->write(res);
    if(socket->isOpen()){
        socket->close();
    }    
}

void OAIDefaultApiRequest::sendCustomResponse(QIODevice *res, QNetworkReply::NetworkError error_type){
    Q_UNUSED(error_type);  // TODO
    socket->write(res->readAll());
    if(socket->isOpen()){
        socket->close();
    }
}

}